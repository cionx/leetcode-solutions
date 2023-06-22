# Follow up



### First question

> What if the given array is already sorted? How would you optimize your algorithm?

If both input arrays are already sorted, then we can skip the usage of `giveSorted`.
This then reduces the time complexity to $O(\min(m, n))$.
The space complexity also reduces to $O(\min(m, n))$ as we do not need separated sorted copies of nums1 and nums2 around.



### Second question

> What if `num1`’s size is small compared to `num2`’s size?
> Which algorithm is better?

We only have one algorithm (so far).



### Third question

> What if elements of `nums2` are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
