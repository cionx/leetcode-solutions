import random, itertools

for _ in range(8):
    m = random.randint(2, 100)
    n = random.randint(2, 100)
    cells0 = list(range(1, m + 1))
    cells1 = list(range(1, n + 1))
    cells = list(map(lambda x: list(x), itertools.product(cells0, cells1)))
    random.shuffle(cells)
    print(m)
    print(n)
    print(cells)
