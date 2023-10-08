""" 832. Flipping an Image """

"""
Complexities.
Time: Θ(m n)
Space: Θ(1)
where m × n is the size of the input image. */
"""

Image = list[list[int]]

def flip(bit: int):
    return 1 - bit

class Solution:
    def flipAndInvertImage(self, image: Image) -> Image:
        result = []
        for row in image:
            result.append(list(map(flip, reversed(row))))
        return result

