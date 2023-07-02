import random

limit = 10**9

for _ in range(8):
    n = random.randint(1, 2000)
    m = random.randint(1, 2000)

    arr1 = random.choices(range(0, limit + 1), k=n)
    arr2 = random.choices(range(0, limit + 1), k=n)

    print(arr1)
    print(arr2)
