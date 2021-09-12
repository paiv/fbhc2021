#!/usr/bin/env python
import sys


def travis(N, M, A, B):
    ans = 'Impossible'
    lo = N + M - 1
    if A < lo: return ans
    if B < lo: return ans
    m = [[999] * M for _ in range(N)]
    m[0][0] = 1
    m[0][-1] = 1
    for x in range(1, min(M, N)):
        m[x-1][x] = 1
        m[x][x] = 1
        m[x-1][M-x-1] = 1
        m[x][M-x-1] = 1
    if M < N:
        for x in range(M, N):
            m[x][0] = 1
            m[x][-1] = 1
    else:
        for x in range(N, M):
            m[-1][x] = 1
            m[-1][M-x-1] = 1
    m[-1][-1] = A - lo + 1
    m[-1][0] = B - lo + 1
    ans = ['Possible', *(' '.join(map(str, row)) for row in m)]
    return '\n'.join(ans)


def solve(fn):
    for index, problem in enumerate(parse(fn), 1):
        print(f'Case #{index}: ', end='', flush=True)
        ans = travis(*problem)
        print(ans, flush=True)


def parse(fn):
    with open(fn) as fp:
        T = int(next(fp))
        for _ in range(T):
            P = list(map(int, next(fp).split()))
            yield P


if __name__ == '__main__':
    solve(*sys.argv[1:])
