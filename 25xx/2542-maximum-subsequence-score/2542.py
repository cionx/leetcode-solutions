import heapq


Item = tuple[int, int]
Heap = list[Item]
Bucket = list[int]
Buckets = dict[int, Bucket]


class Solution:
    def __init__(self):
        self.nums1: list[int] = []
        self.nums2: list[int] = []
        self.heap: Heap = []
        self.buckets: Buckets = {}
        self.heapSum = 0

    def maxScore(self, nums1: list[int], nums2: list[int], k: int) -> int:
        self.nums1 = nums1
        self.nums2 = nums2
        n: int = len(nums1)
        # print(f"n: {n}")
        limit = 10**5
        self.buckets = {}
        # Sort the indices by their value in nums2.
        self.fillBuckets()
        # Sort each bucket so that nums1 decreases in each bucket.
        self.sortBuckets()
        # print(f"Buckets: {buckets}")
        # Create the priority heap for remembering the k many indices with the
        # largest nums1-value so for. The remembered pairs are of the form
        # (nums1[i], i), except for the dummy initial values. For those it is
        # only important that the first entry is negative. Note that heapq
        # supports pairs as heap entries: these are then sorted by their first
        # value (see documentation).
        self.heap = [(-1, -1)] * k
        self.heapSum = -k
        # Time for the main loop.
        # Each bucket corresponds to a value found in nums2. We go through
        # these buckets by decreasing nums2-value.
        best: int = 0
        for minimum, bucket in reversed(sorted(self.buckets.items())):
            # print(f"Check minimum {minimum}")
            if self.addBucketToHeap(bucket):
                # print(f"Current heap: {sorted(self.heap)}")
                topSum = self.heapSum
                score = topSum * minimum
                # print(f"topSum: {topSum}")
                # print(f"score: {score}")
                if score > best and self.heap[0][0] != -1:
                    best = score
                # print("\n")
        # Finished.
        return best

    def fillBuckets(self) -> None:
        n = len(self.nums1)
        for i in range(0, n):
            key = self.nums2[i]
            try:
                self.buckets[key].append(i)
            except KeyError:
                self.buckets[key] = [i]

    def sortBuckets(self) -> None:
        for bucket in dict.values(self.buckets):
            bucket.sort(key=(lambda i: self.nums1[i]), reverse=True)

    def addBucketToHeap(self, bucket: Bucket) -> bool:
        added: bool = False
        for i in bucket:
            new = self.nums1[i]
            smallest = self.heap[0][0]
            if new > smallest:
                self.heapSum += new - smallest
                heapq.heapreplace(self.heap, (new, i))
                added = True
            else:
                break
        return added
