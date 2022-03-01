##
## EPITECH PROJECT, 2021
## 106bombyx
## File description:
## functions.py
##

def calc_next(xi: int, k: float) -> float:
    result = k * xi * (1000 - xi) / 1000
    return result if result >= 0 else 0

def first_case(n: int, k: float) -> None:
    xi = n

    for i in range (1, 101):
        print(i, f"{round(xi, 2):.{2}f}")
        xi = calc_next(xi, k)

def second_case(n: int, i0: int, i1: int) -> None:
    for k in range(100, 401):
        xi = n
        for i in range(2, i0):
            xi = calc_next(xi, k / 100)
        for i in range(i0, i1 + 1):
            xi = calc_next(xi, k / 100)
            print(f"{round(k / 100, 2):.{2}f} {round(xi, 2):.{2}f}")
