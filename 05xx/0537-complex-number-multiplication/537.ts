/* 537. Complex Number Multiplication */

function complexNumberMultiply(num1: string, num2: string): string {
  const parts1 = num1.split("+");
  const re1 = Number(parts1[0]);
  const img1 = Number(parts1[1].slice(0, -1));

  const parts2 = num2.split("+");
  const re2 = Number(parts2[0]);

  const re3 = re1 * re2 - img1 * img2;
  const img3 = re1 * img2 + re2 * img1;

  return `${re3}+${img3}i`;
}
