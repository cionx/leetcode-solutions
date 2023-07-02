import random

for _ in range(8):
    n = random.randint(1, 5 * 10**4)
    prices = random.choices(range(1, 5 * 10**4), k=n)
    fee = random.randint(0, 5 * 10**4 - 1)
    print(prices)
    print(fee)
