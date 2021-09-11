#!/usr/bin/env python
import sys


def timmy(W):
    ans = 0
    state = None
    for x in W:
        if (x in 'XO') and (x != state):
            ans += 1 if state else 0
            state = x
    return ans


def solve(fn):
    for index, problem in enumerate(parse(fn), 1):
        print(f'Case #{index}: ', end='', flush=True)
        ans = timmy(*problem)
        print(ans, flush=True)


def parse(fn):
    with open(fn) as fp:
        T = int(next(fp))
        for _ in range(T):
            N = int(next(fp))
            W = next(fp).rstrip()
            yield (W,)


if __name__ == '__main__':
    solve(*sys.argv[1:])
