""" 151. Reverse Words in a String """

""" In-place, iterative solution. """

"""
Complexities.
Time: Θ(n)
Space: O(n)
where n is the length of the input array.
"""

class Solution:
    def reverseWords(self, s: str) -> str:
        splits = s.split(" ")
        words = [word for word in splits if word != ""]
        words.reverse()
        result = " ".join(words)
        return result
