import random

for _ in range(8):
    m = random.randint(1, 50)
    n = random.randint(1, 50)
    length = random.randint(1, 100)
    rowIndices = random.choices(range(m), k=length)
    columnIndices = random.choices(range(n), k=length)
    indices = [list(pair) for pair in zip(rowIndices, columnIndices)]
    print(m)
    print(n)
    print(indices)
