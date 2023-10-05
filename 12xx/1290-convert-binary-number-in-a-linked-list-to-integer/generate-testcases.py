import random

for _ in range(8):
    length = random.randint(1, 30)
    digits = random.choices([0, 1], k=length)
    print(digits)
