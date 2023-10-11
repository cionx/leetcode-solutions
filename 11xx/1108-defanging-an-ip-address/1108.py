""" 1108. Defanging an IP Address """

"""
Complexities.
Time: Θ(n)
Space: Θ(1)
where n is the length of the input string.
"""


class Solution:
    def defangIPaddr(self, address: str) -> str:
        return address.replace(".", "[.]")
