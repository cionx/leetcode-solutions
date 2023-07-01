import random

for _ in range(8):
    length = random.randint(2, 8)
    cookies = random.choices(range(1, 10**5 + 1), k = length)
    k = random.randint(2, length)
    print(cookies)
    print(k)
