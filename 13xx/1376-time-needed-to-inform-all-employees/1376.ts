type Id = number;
type Time = number;

function numOfMinutes(
  n: number,
  headID: Id,
  manager: Id[],
  informTime: Time[],
): Time {
  /* We revere the graph. */
  const employees: Id[][] = Array(n).fill(null).map(() => []);
  for (let i = 0; i < headID; ++i) {
    employees[manager[i]].push(i);
  }
  for (let i = headID + 1; i < n; ++i) {
    employees[manager[i]].push(i);
  }

  /* Recursively determining the times. */
  function getTime(id: Id): Time {
    const maxEmployeeTime = employees[id]
      .map(getTime)
      .reduce((t1, t2) => Math.max(t1, t2), 0);
    /* JavaScript is stupid: you cannot reduce with Math.max. */

    return maxEmployeeTime + informTime[id];
  }

  return getTime(headID);
}
