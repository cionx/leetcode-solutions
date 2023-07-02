import random

length = random.randint(0, 10**3)
values = random.choices(range(-1000,1001), k = length)

print(values)
print(length)
