""" 1514. Path with Maximum Probability """

"""
Complexities.
Time: O(e log(e))
Space: O(v + e)
where v is the number of vertices and e is the number of edges.
(Regarding the space complexity: note that we never have two paths with the same
last edge. Therefore, we have to remember at most as many paths as edges. This
worst case can happen if we have a star-shaped graph (one central node has an
edge to every other point, and there are no other edges).)
(Regarding the time complexity: worst-case, we have to add one entry to the heap
for every edge, which takes O(1) on average. This gives a total of O(e). Popping
an element of the heap takse O(log(h)) where h is the size of the heap. We have
at most as many pops as paths, which is at most the number of edges.)
"""

"""
Idea.

The problem can in principle by solved with Dijkstra’s algorithm. We first replace
each probability p by the number log(p) to turn multiplication of weights into
addition of weights. Then we replace each weight w by -w to make all weights
non-negative, and to turn the problem of finding the highest-weight path into
the problem of finding the lowest-weight path. We will skip this translation,
and works with the original formulation of the problem.

We search through the connected component of the start node via a “weighted BFS”
approach. Each node in the graph has an associated probability: the maximal
probability of getting from the start node to the current node. The start node
has a probability of 1, whereas all nodes outside the connected component of the
start node have a probability of 0. We will visit the nodes in the connected
component in decreasing order of their probability.

In order to do so, we will keep track of the following information:
 - Which nodes have been visited.
 - All paths from the start node to any unvisited node that go only through
   visited nodes, including the probabilities of those paths.
We will always choose the next node to visit as the target of the highest-
probability path that we know of. The probability of this path will then be the
probability of its target node: Let p be the probability of the path. If we find
another path to the target node later on in the algorithm, then this new path
must go through yet-to-visit nodes, which will have a probability strictly
smaller than p. This new path will then also have a probability strictly smaller
than p.

Instead of full pathts, we only need to keep track of their target nodes and
their total probabilities.

The algorithm stops when we visit the end node, or if we have searched through
the entire connected component of the start node without findind the end node.
"""


import heapq


Edge = list[int]  # [source, target]
PropPath = tuple[float, int]  # (prop, int)
PropEdge = tuple[float, int]  # (prop, int)


class PriorityQueue:
    def __init__(self) -> None:
        self.entries: list[PropPath] = []

    def transform(self, pathPair):
        (cost, end) = pathPair
        return (-cost, end)

    def push(self, value):
        heapq.heappush(self.entries, self.transform(value))

    def pop(self):
        return self.transform(heapq.heappop(self.entries))

    @property
    def size(self):
        return len(self.entries)


class Solution:
    def maxProbability(
        self,
        n: int,
        edges: list[Edge],
        succProb: list[float],
        start: int,
        end: int,
    ) -> float:
        # Initialize the required structures.
        edgesOut: list[list[PropEdge]] = [[] for _ in range(n)]
        for (source, target), edgeProp in zip(edges, succProb):
            edgesOut[source].append((edgeProp, target))
            edgesOut[target].append((edgeProp, source))
        visited: list[bool] = [False] * n
        highestPropPaths = PriorityQueue()
        # We handle the starting node by hand.
        visited[start] = True
        for edgeProp, pathTarget in edgesOut[start]:
            highestPropPaths.push((edgeProp, pathTarget))
        # In general, we check out the target of the next-highest-probability
        # path we have found so far.
        while highestPropPaths.size > 0:
            (pathProp, pathTarget) = highestPropPaths.pop()
            if visited[pathTarget]:
                continue
            if pathTarget == end:
                return pathProp
            visited[pathTarget] = True
            for edgeProp, edgeTarget in edgesOut[pathTarget]:
                if not visited[edgeTarget]:
                    highestPropPaths.push((pathProp * edgeProp, edgeTarget))
        return 0
