#!/usr/bin/env python
import sys
from collections import Counter


def play(board):
    sol = set()
    for y,row in enumerate(board):
        if 'O' in row: continue
        r = tuple((x,y) for x, q in enumerate(row) if q == '.')
        sol.add(r)
    board = list(zip(*board))
    for x,col in enumerate(board):
        if 'O' in col: continue
        r = tuple((x,y) for y, q in enumerate(col) if q == '.')
        sol.add(r)
    if not sol:
        return
    res = Counter(len(r) for r in sol)
    n = min(res)
    return n, res[n]


def solve(fn):
    for index, board in enumerate(parse(fn), 1):
        print(f'Case #{index}: ', end='', flush=True)
        ans = play(board)
        if ans is None:
            ans = 'Impossible'
        else:
            ans = '{} {}'.format(*ans)
        print(ans, flush=True)


def parse(fn):
    with open(fn) as fp:
        T = int(next(fp))
        for _ in range(T):
            N = int(next(fp))
            board = list()
            for _ in range(N):
                s = next(fp).strip()
                board.append(s)
            yield board


if __name__ == '__main__':
    solve(*sys.argv[1:])
