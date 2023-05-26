import random

length1 = random.randint(0, 1000)
length2 = random.randint(0, 1000)

nums1 = random.choices(range(-1000, 1000), k = length1)
nums2 = random.choices(range(-1000, 1000), k = length2)

print(nums1)
print(nums2)
