import random
import textwrap

max_amount = 10 ** 5
max_nums = 10 ** 5

n = random.randint(0, max_amount)
nums1 = random.choices(range(0, max_nums + 1), k = n)
nums2 = random.choices(range(0, max_nums + 1), k = n)
k = random.randint(1, n)

for line in textwrap.wrap(f"nums1: {nums1:}", width=100):
    print(line)
for line in textwrap.wrap(f"nums2: {nums2:}", width=100):
    print(line)
print(f"k: {k}")
