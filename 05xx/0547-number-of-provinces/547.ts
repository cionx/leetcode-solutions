/* 547. Number of Provinces */

type City = number;

function findCircleNum(isConnected: number[][]): number {
  const n = isConnected.length;
  const directlyConnected: City[][] = Array(n).fill(null).map(() => []);

  for (let i = 0; i < n; ++i) {
    for (let j = i + 1; j < n; ++j) {
      if (isConnected[i][j]) {
        directlyConnected[i].push(j);
        directlyConnected[j].push(i);
      }
    }
  }

  const found: boolean[] = Array(n).fill(false);

  function exploreProvince(city: City): void {
    found[city] = true;
    const toVisit: City[] = [];

    for (
      let current: City | undefined = city;
      current !== undefined;
      current = toVisit.pop()
    ) {
      for (const connectedCity of directlyConnected[current]) {
        if (!found[connectedCity]) {
          toVisit.push(connectedCity);
          found[connectedCity] = true;
        }
      }
    }
  }

  let counter = 0;
  for (let i = 0; i < n; ++i) {
    if (!found[i]) {
      ++counter;
      exploreProvince(i);
    }
  }

  return counter;
}
