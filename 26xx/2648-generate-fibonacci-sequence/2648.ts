function* fibGenerator(): Generator<number, void, void> {
  let first = 0;
  let second = 1;

  while (true) {
    yield first;
    [first, second] = [second, first + second];
  }
}
