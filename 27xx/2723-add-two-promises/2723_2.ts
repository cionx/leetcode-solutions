async function addTwoPromises(
  promise1: Promise<number>,
  promise2: Promise<number>,
): Promise<number> {
  const [val1, val2] = await Promise.all([promise1, promise2]);
  return val1 + val2;
}
