""" 2305. Fair Distribution of Cookies """

"""
Complexities.
Time: ?
Space: ?
where c is the number of cookies and k is the number of children.
"""

"""
Idea.
We brute-force through all ways of distributing the cookie bags to the children.
We represent the possible configurations as k-tuples of numbers, where the i-th
entry represents how many cookies the i-child currently holds. Generally
speaking, when we introduce a new cookie bag, we need to add the bag’s cookie
amount to every possible entry of every previously calculated tuples.
(In this naive way, we increase the amount of current configurations by a factor
of k each time.)

However, this naive approach leads to k^c tuples, which can go up to
8^8 ≈ 16 million. We use the following optimizations to make the procedure
faster:
- We save the configuration-tuples in a set, so that repeating results don’t
  lead to repeated calculations. (We will introduce a new set for each new
  cookie bag.)
- We will order the state-tuples (in decreasing order).
- If one of children holds more than half the cookies, then it doesn’t matter
  how the remaining cookies are calculated. We will then compare this large
  cookie amount with the currently minimal-known unfairness, and afterwards
  remove this configuration from the procedure from our consideration.
"""

Combs = set[tuple[int, ...]]


class Solution:
    k: int
    maxSum: int
    best: int

    def distributeCookies(self, cookies: list[int], k: int) -> int:
        self.k = k
        self.maxSum = sum(cookies)
        self.best = self.maxSum
        combs: Combs = set()
        combs.add(tuple([0] * k))
        cookies.sort(reverse=True)
        for cookie in cookies:
            combs = self.addCookie(cookie, combs)
        if len(combs) > 0:
            finalMin = min(map((lambda c: c[0]), combs))
            self.best = min(self.best, finalMin)
        return self.best

    def addCookie(self, cookie: int, combs: Combs) -> Combs:
        limit = (self.maxSum + 1) // 2  # Rounded up.
        newCombs: Combs = set()
        for combination in combs:
            for i in range(self.k):
                r = list(combination)
                r[i] += cookie
                r.sort(reverse=True)
                print(r)
                if r[0] >= limit:
                    self.best = min(self.best, r[0])
                else:
                    newCombs.add(tuple(r))
        return newCombs
