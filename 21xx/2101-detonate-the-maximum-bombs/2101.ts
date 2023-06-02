type Bomb = [xCoord: number, yCoord: number, radius: number];

function maximumDetonation(bombs: Bomb[]): number {
  const n = bombs.length;
  const inReach: number[][] = Array(n).fill(null).map(() => []);

  function reachable(from: Bomb, to: Bomb): boolean {
    const [xFrom, yFrom, rFrom] = from;
    const [xTo, yTo, _] = to;

    return (xTo - xFrom) ** 2 + (yTo - yFrom) ** 2 <= rFrom ** 2;
  }

  for (let i = 0; i < bombs.length; ++i) {
    const from = bombs[i];
    for (let j = 0; j < bombs.length; ++j) {
      const to = bombs[j];
      if (reachable(from, to)) {
        inReach[i].push(j);
      }
    }
  }

  function countDetonated(i: number) {
    const discovered = Array(n).fill(false);
    const toDetonate: number[] = [];
    let counter = 0;

    discovered[i] = true;

    for (
      let j: number | undefined = i;
      j !== undefined;
      j = toDetonate.pop(), ++counter
    ) {
      for (let k = 0; k < inReach[j].length; ++k) {
        const l = inReach[j][k];
        if (!discovered[l]) {
          toDetonate.push(l);
          discovered[l] = true;
        }
      }
    }
    return counter;
  }

  let max = 0;
  for (let i = 0; i < bombs.length; ++i) {
    const amountDetonated = countDetonated(i);
    if (amountDetonated > max) {
      max = amountDetonated;
    }
  }

  return max;
}
