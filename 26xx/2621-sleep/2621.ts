/* 2621. Sleep */

async function sleep(millis: number): Promise<void> {
  return new Promise<void>((resolve, _) => setTimeout(resolve, millis));
}
