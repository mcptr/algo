#!/usr/bin/env python

def fibonacci_gen(n):
    prv = 0
    nxt = 1
    res = 0
    while res < n:
        res = prv + nxt
        yield res
        prv = nxt
        nxt = res


print(sum([_ for _ in fibonacci_gen(4 * 1000 * 1000) if _ % 2 == 0]))
