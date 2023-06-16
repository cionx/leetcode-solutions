# Explanation

For every array $A = [a_1, \dotsc, a_n]$ we denote by $P(A)$ the subgroup of the symmetric group $\mathrm{S}_n$ consisting of all those permutations $σ$ such that $A$ and $σ(A)$ result in the same BST.[^1]

We first observe that every element of $P(A)$ must fix the first entry in the array $A$, since this first entry is the root of the resulting BST.
The rest of a will be split up into two subarrays:
the subarray $A_-$ consisting of all values that are strictly smaller than $a_1$, and the subarray $A_+$ consisting of all values that are strictly smaller than $a_1$.
Graphically speaking, this means that we colour the entries $a_2, \dotsc, a_n$ in two different colours, depending on whether they are smaller or larger than $a_1$.
Let’s say that the entries of $A_-$ are blue, whereas the entries of $A_+$ are red.

We have two special kinds of permutations in $P(A)$:

1. We can rearrange the entries of $[a_2, \dotsc, a_n]$ however we want, as long as we don’t interchange entries of the same colour.
   We refer to these permutations as _external_, as they do not change the internal structure of the two colours.
   We denote the set of external permutations by $P_{\mathrm{ext}}(A)$, and observe that
   $$
     | P_{\mathrm{ext}}(A) |
     = \binom{n - 1}{|A_-|}
     = \binom{n - 1}{|A_+|} \,.
   $$

2. On the other hand, we have the _internal_ permutations:
   those elements of $P(A)$ that leave the distribution of the two colours unchanged, and only permutes entries of the same colour.
   We denote the set of internal permutations by $P_{\mathrm{int}}(A)$.
   We observe that $P_{\mathrm{int}}(A)$ is a subgroup of $P(A)$ with
   $$
     P_{\mathrm{int}}(A) ≅ P(A_-) × P(A_+) \,.
   $$

These two kinds of permutations are closely related:
$P_{\mathrm{ext}}(A)$ is set of representatives for the left cosets~$P(A) / P_{\mathrm{int}}(A)$.
(We can split up every permutation belonging to $P(A)$ into two steps:
first we permute each colour internally, then we rearrange the two colours relative to one another.)[^2]
Consequently,
$$
  | P(A) |
  = | P_{\mathrm{ext}}(A) | ⋅ | P_{\mathrm{int}}(A) |
  = \binom{n - 1}{ |A_-| } ⋅ | P(A_-)| ⋅ | P(A_+) | \,.
$$
Together with the observation
$$
  | P(A) | = 1
  \qquad
  \text{whenever $|A| ≤ 2$}
$$
we can now recursively determine the size of $P(A)$.

[^1]: The permutation $σ$ acts on the array $A = [a_1, \dotsc, a_n]$ as usual via $σ(A) = [a_{σ^{-1}(1)}, \dotsc, a_{σ^{-1}(n)}]$.

[^2]: Our situation is similar to the following example from group theory:
      Consider the symmetric group $\mathrm{S}_{m + n}$ for two natural numbers $m$ and $n$.
      We colour the numbers $1, \dotsc, n$ blue and the numbers $n + 1, \dotsc, n + m$ red.

      Every permutation belonging to $\mathrm{S}_{m + n}$ can then be split into two parts:
      First we permute the two colours internally.
      Then we rearrange the two colours relative to one another, without reordering numbers of the same colour relative to one another.
      This decomposition of the original permutation is unique.

      If we think about a permutation as a string diagram, then we can colour each string according to its domain.
      In the first step only strings of the same colour are allowed to intersect, whereas in the second step, strings of the same colour must not intersect.

      The permutations of the first kind form the subgroup $\mathrm{S}_m × \mathrm{S}_n$ of $\mathrm{S}_{m + n}$.
      The permutations of the second kind form a set of representatives for the left cosets $\mathrm{S}_{m + n} / (\mathrm{S}_m × \mathrm{S}_n)$.
      We have a bijection between the second kind of permutations and subsets of $\{ 1, \dotsc, m + n \}$.
      Consequently, we arrive at the true formula
      $$
        |\mathrm{S}_{m + n}|
        = \binom{m + n}{m} ⋅ |\mathrm{S}_m| ⋅ |\mathrm{S}_n|
        = \binom{m + n}{n} ⋅ |\mathrm{S}_m| ⋅ |\mathrm{S}_n| \,.
      $$
