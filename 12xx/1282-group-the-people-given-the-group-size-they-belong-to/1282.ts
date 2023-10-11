/* 1282. Group the People Given the Group Size They Belong To */

/* Complexities:
 * Time: Θ(n)
 * Space: Θ(d)
 * where n is the length of the input array, and d is the number of distinct
 * group sizes. */

type Id = number;
type Group = Id[];

function groupThePeople(groupSizes: number[]): Group[] {
  const n = groupSizes.length;
  const result: Group[] = [];

  /* We use an auxiliary array whose n-th entry is a group of eventual size n
   * that is currently waiting for more members. */
  const partialGroups: Group[] = [];

  for (let id: Id = 0; id < n; ++id) {
    const size = groupSizes[id];
    /* Get the group for the specified size that is waiting for more members. */
    if (partialGroups[size] === undefined) {
      partialGroups[size] = [];
    }
    const group = partialGroups[size];
    /* Add the id to the group. */
    group.push(id);
    /* Check if the group is now full. If so, then append the group to the
     * result, and create a new group for the size. */
    if (group.length == size) {
      result.push(group);
      partialGroups[size] = [];
    }
  }

  return result;
}
