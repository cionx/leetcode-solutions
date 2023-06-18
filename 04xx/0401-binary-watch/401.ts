/* There are at most binom(10, 5) = 252 many results, so we can do recursion
 * without worrying about exponential growth. */

type Time = [hour: number, minute: number];

function readBinaryWatch(turnedOn: number): string[] {
  return recursionHelper(turnedOn, 10).map(timeToString);
}

function recursionHelper(turnedOn: number, digitPosition: number): Time[] {
  if (turnedOn == 0) {
    return [[0, 0]];
  }
  const timeToAdd = digitToTime(digitPosition);
  let result = recursionHelper(turnedOn - 1, digitPosition - 1);
  result = result
    .map((time) => addTime(time, timeToAdd))
    .filter(([hours, minutes]) => hours < 12 && minutes < 60);
  if (turnedOn < digitPosition) {
    result = result.concat(recursionHelper(turnedOn, digitPosition - 1));
  }
  return result;
}

function addTime([hour1, minute1]: Time, [hour2, minute2]: Time): Time {
  return [hour1 + hour2, minute1 + minute2];
}

function digitToTime(digitPosition: number): Time {
  switch (digitPosition) {
    case 10:
      return [8, 0];
    case 9:
      return [4, 0];
    case 8:
      return [2, 0];
    case 7:
      return [1, 0];
    case 6:
      return [0, 32];
    case 5:
      return [0, 16];
    case 4:
      return [0, 8];
    case 3:
      return [0, 4];
    case 2:
      return [0, 2];
    case 1:
      return [0, 1];
    default:
      throw new Error(`Cannot handle input ${digitPosition}`);
  }
}

function timeToString([hour, minute]: Time): string {
  return `${hour}:${(minute <= 9) ? "0" : ""}${minute}`;
}
