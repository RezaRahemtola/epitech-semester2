from math import sin


def compute_eq(x: int, max: int) -> float:
    result = 1
    k = 0

    if x == 0:
        return (result)
    while k <= max:
        result *= sin(x / (2 * k + 1)) / (x / (2 * k + 1))
        k += 1
    return (result)


def compute_midpoint(n: int) -> float:
    result = 0

    if n == 0:
        return 1.5707651076
    for i in range(1, 10000):
        result += compute_eq(i, n)
    return (result * 2 + compute_eq(0, n) + compute_eq(2500, n)) / 2


def compute_trapezoidal(n: int) -> float:
    result = 0

    for i in range(1, 10000):
        result += compute_eq(i / 2, n)
    return (result * 2 + compute_eq(0, n) + compute_eq(5000, n)) / 4


def compute_simpson(n: int) -> float:
    result = 0
    tmp = 0

    for i in range (1, 10000):
        result += compute_eq(i / 2, n)
    for i in range(10000):
        tmp += compute_eq(i / 2 + 0.25, n)
    return (result * 2 + compute_eq(0, n) + compute_eq(5000, n) + tmp * 4) * 5000 / (6 * 10000)
