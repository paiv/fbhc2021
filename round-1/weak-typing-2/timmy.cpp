// c++ -std=c++17 -O2 timmy.cpp -o timmy
#include <cstdint>
#include <cstdlib>
#include <unistd.h>

using std::size_t;

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;


int
main(int argc, char const *argv[]) {
    const u32 M = 1000000007;

    u32 N;
    read(STDIN_FILENO, &N, sizeof(N));
    u8* buf = (u8*) malloc(N);
    if (!buf) { return -1; }

    for (u32 n = N, off = 0; n > 0; ) {
        size_t q = read(STDIN_FILENO, &buf[off], n);
        if (!q) { return 1; }
        off += q;
        n -= q;
    }

    u32 R = 0;
    {
        u8 *p = buf, state = 0;
        for (u32 i = 0; i < N; ++i, ++p) {
            u8 x = *p;
            if (x == 'X' || x == 'O') {
                R += (state && x != state);
                state = x;
            }
        }
    }

    u64 S = 0;
    {
        u8 state = 0;
        for (u32 i = 0, r = R; i < N; ++i) {
            for (u32 j = i; j < N; ++j) {
                u8 x = buf[j];
                if (x == 'X' || x == 'O') {
                    r -= (state && state != x);
                    state = x;
                    break;
                }
            }
            S += r;
        }
    }

    u32 ans = S;
    {
        u8 *p = buf + N;
        for (u64 i = 0, r = S; i < N; ++i, --p) {
            u8 x = *(p - 1);
            if (x == 'X' || x == 'O') {
                for (u8* q = p - 1; q != buf; --q) {
                    u8 y = *(q - 1);
                    if (y == 'X' || y == 'O') {
                        r -= (x != y) * (q - buf);
                        break;
                    }
                }
            }
            ans = (ans + r) % M;
        }
    }

    write(STDOUT_FILENO, &ans, sizeof(ans));
    return 0;
}
