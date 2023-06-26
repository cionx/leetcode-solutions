"""
2462. Total Cost to Hire K Workers

Complexities.
Time: O(m log(m) + k log(m)) (amortized)
Space: O(m)
where m is an abbreviation for `canditates`.

(Regard the time complexity: creating a binary heap of size l should take
O(l log(l)) steps. Removing an element takes O(log(l)) steps, whereas inserting
a new element takes O(1) steps.)
"""
import heapq


class Solution:
    def totalCost(self, costs: list[int], k: int, candidates: int) -> int:
        indexedCosts: list[tuple[int, int]] = list(zip(costs, range(len(costs))))
        i: int = candidates - 1
        j: int = len(costs) - candidates
        if i < j:
            cheapest = indexedCosts[:candidates] + indexedCosts[-candidates:]
        else:
            cheapest = indexedCosts
        heapq.heapify(cheapest)
        totalCost = 0
        while k > 0 and i < j:
            (cost, index) = heapq.heappop(cheapest)
            totalCost += cost
            k -= 1
            if index <= i:
                i += 1
                new = i
            else:
                j -= 1
                new = j
            if i < j:
                heapq.heappush(cheapest, indexedCosts[new])
        while k > 0:
            (cost, index) = heapq.heappop(cheapest)
            totalCost += cost
            k -= 1
        return totalCost
