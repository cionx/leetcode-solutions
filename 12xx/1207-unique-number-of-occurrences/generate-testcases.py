import random

for _ in range(8):
    length = random.randint(1, 1000)
    arr = random.choices(range(-1000, 1001), k=length)
    print(arr)
