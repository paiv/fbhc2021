#!/usr/bin/env python
import sys


def solve(fn):
    print('graph {')
    for index, problem in enumerate(parse(fn), 1):
        C, AB, K = problem
        AB = sorted(sorted(p) for p in AB)
        print('subgraph cluster_{} {{'.format(index))
        print(f'label = "mine {index}\nK = {K}";')
        for i, x in enumerate(C, 1):
            print(f'm{index}c{i} [label="{i}\n{x}"];')
        for a, b in AB:
            print(f'm{index}c{a} -- m{index}c{b};')
        print('}')
    print('}')


def parse(fn):
    with open(fn) as fp:
        T = int(next(fp))
        for _ in range(T):
            N, K = map(int, next(fp).split())
            C = list(map(int, next(fp).split()))
            AB = [tuple(map(int, next(fp).split())) for _ in range(N-1)]
            yield C, AB, K


if __name__ == '__main__':
    solve(*sys.argv[1:])
