import random

for _ in range(8):
    length = random.randint(1, 20)
    rods = random.choices(range(1, 250), k=length)
    print(rods)
