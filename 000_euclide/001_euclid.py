# Computes gcd(m, n) by Euclid’s algorithm
# Input: Two nonnegative, not-both-zero integers m and n
# Output: Greatest common divisor of m and n

def Euclid(num1, num2):
    while num2 != 0:
        resto = num1 % num2
        num1 = num2
        num2 = resto
    
    return num1