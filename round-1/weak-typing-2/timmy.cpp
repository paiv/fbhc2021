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

    u32 ans = 0;
    {
        u8 *p = buf;
        u8 state = 0;
        u32 ix = 0;
        for (u32 i = 0; i < N; ++i) {
            u8 x = *p++;
            if (x == 'X' || x == 'O') {
                if (state && state != x) {
                    ans = (ans + u64(N - i) * (ix + 1)) % M;
                }
                state = x;
                ix = i;
            }
        }
    }

    write(STDOUT_FILENO, &ans, sizeof(ans));
    return 0;
}
