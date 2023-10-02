import random

for _ in range(8):
    length = random.randint(1, 5000)
    nodes = random.choices(range(1, 1001), k=length)
    print(nodes)
