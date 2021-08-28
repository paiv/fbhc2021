// c++ -std=c++17 -O2 digger.cpp -o digger
#include <cstdint>
#include <queue>
#include <unistd.h>
#include <unordered_set>

using std::queue;
using std::size_t;
using std::unordered_set;

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;


#define MAX_CAVES 50
#define TRACE_PATH 0


#if TRACE_PATH
#include <stdio.h>
#endif


typedef struct {
    u32 score;
    u8 cave;
    u8 drills_left;
    u8 visited_caves[MAX_CAVES];
    u8 visited_tunnels[MAX_CAVES];
    #if TRACE_PATH
    u8 path_pos;
    u8 path[MAX_CAVES];
    #endif
} search_state;


typedef struct seen_t {
    u64 x;
    u64 y;
    u64 z;

    size_t operator== (const seen_t& other) const noexcept {
        return (x == other.x) && (y == other.y) && (z == other.z);
    }
} seen_t;


template <typename T, typename... Rest>
static void
hash_combine(size_t& seed, const T& v, const Rest&... rest) {
    seed ^= std::hash<T>{}(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    (hash_combine(seed, rest), ...);
}


typedef struct seen_t_hasher {
    size_t operator() (const seen_t& obj) const noexcept {
        size_t h = 0;
        hash_combine(h, obj.x, obj.y, obj.z);
        return h;
    }
} seen_t_hasher;


static u64
bitmask64(u8* p, u32 n) {
    u64 x = 0;
    for (u32 i = 0; i < n; ++i, ++p) {
        x <<= 1;
        x |= *p != 0;
    }
    return x;
}


static seen_t
pack_state(search_state& state, u32 n) {
    seen_t h = {
        .x = (u64(state.score) << 32) | (state.cave << 16) | (state.drills_left != 0),
        .y = bitmask64(state.visited_caves, n),
        .z = bitmask64(state.visited_tunnels, n),
    };
    return h;
}


static u8
all_set(u8* p, u32 n) {
    for (u32 i = 0; i < n; ++i, ++p) {
        if (!*p) { return 0; }
    }
    return 1;
}


int
main(int argc, char const *argv[]) {
    u32 caves[MAX_CAVES] = {};
    u8 tunnels[MAX_CAVES][MAX_CAVES] = {};

    u32 N, K;
    read(STDIN_FILENO, &N, sizeof(N));
    read(STDIN_FILENO, &K, sizeof(K));

    for (u32 i = 0; i < N; ++i) {
        u32 x;
        read(STDIN_FILENO, &x, sizeof(x));
        caves[i] = x;
    }

    for (u32 i = 1; i < N; ++i) {
        u8 a, b;
        read(STDIN_FILENO, &a, sizeof(a));
        read(STDIN_FILENO, &b, sizeof(b));
        tunnels[a][b] = i;
        tunnels[b][a] = i;
    }

    search_state root = {
        .score = caves[0],
        .cave = 0,
        .drills_left = u8(K),
        .visited_caves = {1},
        #if TRACE_PATH
        .path_pos = 1,
        #endif
    };
    queue<search_state> fringe;
    fringe.push(root);

    unordered_set<seen_t, seen_t_hasher> seen;
    u32 best_score = 0;

    while (!fringe.empty()) {
        search_state state = fringe.front();
        fringe.pop();

        seen_t h = pack_state(state, N);
        if (seen.find(h) != seen.end()) { continue; }
        seen.insert(h);

#if TRACE_PATH
        fprintf(stderr, "  score %u, pos %u, drills %u, path:", state.score, state.cave+1, state.drills_left);
        for (u32 i = 0; i < state.path_pos; ++i) {
            fprintf(stderr, " %u", state.path[i]+1);
        }
        fprintf(stderr, "\n");
#endif

        if (state.cave == 0) {
            if (state.score > best_score) {
                best_score = state.score;
            }
            if (all_set(state.visited_caves, N)) {
                break;
            }
        }

        u8 moved = 0;
        for (u32 b = 0; b < N; ++b) {
            if (state.cave == b) { continue; }

            u8 idx = tunnels[state.cave][b];
            if (!idx || state.visited_tunnels[idx]) {
                continue;
            }
            moved = 1;

            search_state next_state = state;
            next_state.visited_tunnels[idx] = 1;
            next_state.cave = b;
            #if TRACE_PATH
            next_state.path[next_state.path_pos++] = b;
            #endif
            if (!next_state.visited_caves[b]) {
                next_state.score += caves[b];
                next_state.visited_caves[b] = 1;
            }
            fringe.push(next_state);
        }

        if (moved) { continue; }

        for (u32 b = 0; b < N; ++b) {
            if (state.cave == b) { continue; }

            u8 idx = tunnels[state.cave][b];
            u32 drills = state.drills_left;
            if (idx == 0 || state.visited_tunnels[idx]) {
                if (drills > 0) {
                    --drills;
                }
                else {
                    continue;
                }
            }

            search_state next_state = state;
            if (idx != 0) {
                next_state.visited_tunnels[idx] = 1;
            }
            next_state.drills_left = drills;
            next_state.cave = b;
            #if TRACE_PATH
            next_state.path[next_state.path_pos++] = b;
            #endif
            if (!next_state.visited_caves[b]) {
                next_state.score += caves[b];
                next_state.visited_caves[b] = 1;
            }
            fringe.push(next_state);
        }
    }

    write(STDOUT_FILENO, &best_score, sizeof(best_score));
    return 0;
}
