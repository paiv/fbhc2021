#!/usr/bin/env python
import sys


def travis(N, M, A, B):
    ans = 'Impossible'
    lo = N + M - 1
    if min(A, B) < lo: return ans
    m = [[1] * M for _ in range(N)]
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
