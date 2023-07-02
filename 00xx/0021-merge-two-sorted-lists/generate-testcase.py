import random

n1 = random.randint(0, 50)
n2 = random.randint(0, 50)

list1 = random.choices(range(-100, 101), k = n1)
list2 = random.choices(range(-100, 101), k = n2)

list1.sort()
list2.sort()

print(list1)
print(list2)
