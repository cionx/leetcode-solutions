""" 373. Find K Pairs with Smallest Sums """

"""
Complexities.
Time: O(k log(m + n))
Space: O(m + n)
where k is as in the problem statement, and m and n are the lengths of the two
input arrays.
"""

"""
Idea.
We arrange the index tuples in a grid:
  (0,0) (0,1) ⋯ ⋯ (0,n)
  (1,0) (1,1) ⋯ ⋯ (1,n)
  ⋮       ⋮   ⋱     ⋮
  ⋮       ⋮     ⋱   ⋮
  (m,0) (m,1) ⋯ ⋯ (m,n)
The associated sums  nums1[i] + nums2[j]  are increasing in each row and in
each column. We start with the top-left entry, (0, 0), giving us the sum
nums1[0] + nums2[0]. The possible fields for the next choice are (0, 1) and
(1, 0). As the algorithm continues, the chosen entries form a connected,
convex-like area in the top-left of the grid. The possible choices for the
next field are the fields bordering this area:

  * ? . . . .   * ? . . . .   * * ? . . .   * * ? . . .   * * * ? . .
  ? . . . . .   * ? . . . .   * ? . . . .   * ? . . . .   * ? ? . . .
  . . . . . .   ? . . . . .   ? . . . . .   * ? . . . .   * ? . . . .
  . . . . . .   . . . . . .   . . . . . .   ? . . . . .   ? . . . . .

   * * * ? . .   * * * ? . .   * * * ? . .   * * * * ? .   * * * * ? .
   * * ? . . .   * * ? . . .   * * ? . . .   * * ? ? . .   * * ? ? . .
   * ? . . . .   * ? . . . .   * * ? . . .   * * ? . . .   * * ? . . .
   ? . . . . .   * ? . . . .   * ? . . . .   * ? . . . .   * * ? . . .

We keep track of the possible next field in a priority queue, implemented via a
binary heap. To make sure that this heap doesn’t contain duplicate entries, we
also keep track of a list l such that l[i] is the right-most column index j for
which (i, j) has been in the heap so far. If we have no fields from the row-th
row in the heap, then the length of l is smaller or equal to row. In the above
example, the heap and auxiliary list l look as follows:

  heap: (0,1) (1,0)    heap: (0,1) (1,1) (2,0)    heap: (0,2) (1,1) (2,0)
  l: 1 0               l: 1 1 0                   l: 2 1 0

  heap: (0,2) (1,1) (2,1) (3,0)    heap: (0,3) (1,1) (1,2) (2,1) (3,0)
  l: 2 1 1 0                       l: 3 2 1 0

  heap: (0,3) (1,2) (2,1) (3,0)    heap: (0,3) (1,2) (2,1) (3,1)
  l: 3 2 1 0                       l: 3 2 1 1

  heap: (0,3) (1,2) (2,2) (3,1)    heap: (0,4) (1,2) (1,3) (2,2) (3,1)
  l: 3 2 2 1                       l: 4 3 2 1

  heap: (0,4) (1,2) (1,3) (2,2) (3,2)
  l: 4 3 2 2
"""


import heapq


class PriorityQueue:
    def __init__(self) -> None:
        self._entries: list[tuple[int, int, int]] = []  # the heap
        self._maxColIndex: list[int] = []  # the list l

    def updateEntry(self, row: int, column: int):
        if row >= len(self._maxColIndex):
            self._maxColIndex.append(0)
            return True
        if self._maxColIndex[row] < column:
            self._maxColIndex[row] += 1
            return True
        return False

    def push(self, entry):
        (_, row, column) = entry
        if self.updateEntry(row, column):
            heapq.heappush(self._entries, entry)

    def pop(self):
        return heapq.heappop(self._entries)

    @property
    def size(self):
        return len(self._entries)


class Solution:
    def kSmallestPairs(
        self, nums1: list[int], nums2: list[int], k: int
    ) -> list[tuple[int, int]]:
        result: list[tuple[int, int]] = []
        smallest = PriorityQueue()
        smallest.push((nums1[0] + nums2[0], 0, 0))
        while k > 0 and smallest.size > 0:
            (_, i, j) = smallest.pop()
            result.append((nums1[i], nums2[j]))
            k -= 1
            if i + 1 < len(nums1):
                smallest.push((nums1[i + 1] + nums2[j], i + 1, j))
            if j + 1 < len(nums2):
                smallest.push((nums1[i] + nums2[j + 1], i, j + 1))
        return result
