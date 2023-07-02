import random

for _ in range(8):
    length = random.randint(2, 100)
    arr = random.choices(range(-(10**3), 10**3), k=length)
    print(arr)
