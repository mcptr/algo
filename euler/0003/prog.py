#!/usr/bin/env python

import sys
import math


def is_prime(n):
    if n < 2: return False
    for i in range(2, math.ceil(math.sqrt(n)) + 1):
        if not n % i: return False
    return True


def next_prime(n):
    for i in range(1, 70 * 1000 * 1000):
        if is_prime(n + i):
            return n + i
    raise Exception("No prime.")


def prime_factors(n):
    factors = []
    prime = 2
    while n > 1:
        if n % prime == 0:
            factors.append(prime)
            n = n / prime
        else:
            prime = next_prime(prime)
    return factors


n = int(sys.argv[1]) if len(sys.argv) > 1 else 600851475143
print(max(prime_factors(n)))
