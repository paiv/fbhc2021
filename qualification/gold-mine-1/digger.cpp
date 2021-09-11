// c++ -std=c++17 -O2 digger.cpp -o digger
#include <cstdint>
#include <unistd.h>
#include <unordered_set>

using std::unordered_set;

typedef uint8_t u8;
typedef uint32_t u32;


#define MAX_CAVES 50


int
main(int argc, char const *argv[]) {
    u32 caves[MAX_CAVES] = {};
    u8 tunnels[MAX_CAVES][MAX_CAVES] = {};

    u32 N;
    read(STDIN_FILENO, &N, sizeof(N));

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

    unordered_set<u32> seen;
    seen.insert(0);

    auto dig = [&tunnels, &caves, &seen](u8 start, u32 n, auto& dig) -> u32 {
        u32 best = 0;
        for (u32 b = 0; b < n; ++b) {
            if (tunnels[start][b]) {
                if (seen.find(b) != seen.end()) { continue; }
                seen.insert(b);
                u32 score = dig(b, n, dig);
                if (score > best) {
                    best = score;
                }
            }
        }
        return caves[start] + best;
    };

    u32 best1 = 0, best2 = 0;

    for (u32 s = 0; s < N; ++s) {
        if (tunnels[0][s]) {
            seen.insert(s);
            u32 score = dig(s, N, dig);
            if (score > best1) {
                best2 = best1;
                best1 = score;
            }
            else if (score > best2) {
                best2 = score;
            }
        }
    }

    u32 ans = caves[0] + best1 + best2;
    write(STDOUT_FILENO, &ans, sizeof(ans));
    return 0;
}
