# Implements the sieve of Eratosthenes
# Input: A positive integer n > 1
# Output: Array L of all prime numbers less than or equal to n
from math import floor, sqrt

def Sieve(num):
    fullList = [p for p in range(2, num + 1)]

    numFloor = floor(sqrt(num)) # [ √n ] using the so-called floor function
    for p in range(2,  numFloor + 1):
        if p % 2 == 0 and p != 2:
            continue
        if fullList[p - 2] != 0:  # p hasn’t been eliminated on previous passes
            j = p * p
            while j <= num:
                fullList[j - 2] = 0 # mark element as eliminated
                j = j + p
    # copy the remaining elements of A to array L of the primes
    oddNumberList = list()
    for p in range(2, num + 1):
        if fullList[p - 2] != 0:
            oddNumberList.append(fullList[p - 2])
        

    print(oddNumberList)

Sieve(46)