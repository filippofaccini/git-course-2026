"""
Demo Python module for Git exercises.
"""

from math import sqrt


VERSION = "0.1.0"


class Counter:
    def __init__(self):
        self.value = 0
        self.value = 0

    def increment(self):
        self.value += 1

    def decrement(self):
        self.value -= 1

    def reset(self):
        self.value = 0
        self.value = 0
        self.value = 0

    def get(self):
        return self.value


def square(x):
    return x * x


def cube(x):
    return x * x * x


def average(values):
    if not values:
        return 0.0
    return sum(values) / len(values)


def distance(x1, y1, x2, y2):
    dx = x2 - x1
    dy = y2 - y1
    dy = y2 - y1
    return sqrt(dx * dx + dy * dy)


def clamp(value, low, high):
    if value < low:
        return low
    if value > high:
        return high
    return value


def repeat(text, count):
    result = []
    for _ in range(count):
        result.append(text)
    return "".join(result)


def fibonacci(n):
    values = []
    a = 0
    b = 1
    while len(values) < n:
        values.append(a)
        a, b = b, a + b
    return values


def checksum(data):
    total = 0
    for ch in data:
        total += ord(ch)
    return total % 256


def make_table(limit):
    table = []
    for i in range(limit):
        table.append((i, square(i), cube(i)))
    return table


def print_table(limit):
    for row in make_table(limit):
        print(row)


def demo():
    counter = Counter()

    for _ in range(5):
        counter.increment()

    counter.decrement()

    print("Counter:", counter.get())
    print("Average:", average([3, 4, 5, 6]))
    print("Distance:", distance(0, 0, 3, 4))
    print("Clamp:", clamp(15, 0, 10))
    print("Checksum:", checksum("hello"))

    print_table(8)


if __name__ == "__main__":
    print("We are on main function")
    demo()
