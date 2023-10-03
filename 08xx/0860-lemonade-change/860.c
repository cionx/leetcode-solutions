/* 860. Lemonade Change */

/* Complexities.
 * Time: O(n)
 * Space: Θ(1)
 * where n is the length of the input array. */

/* Idea.
 * If a customer pays $5, then we have nothing to check and no choice to make.
 *
 * If a customer pays $10, then we have to check that we have a $5 bill, but
 * have otherwise no choice to make.
 *
 * If a customer pays $20, then we have to decide between giving back
 * - a $10 bill together with a $5 bill, or
 * - three $5 bills.
 * It is always better to choose the first (when possible). Indeed:
 * - We have no other uses for $10 bills. Giving them away can therefore not
 *   have negative consequences.
 * - We want to maximize the number of $5 bills at hand, since we can solve
 *   every situation with enough $5 bills.
 * So, while there is a choice to be made, we will always make the same choice.
 * (Basically, two $5 bills can always play the role of a $10 bill, but not the
 * other way around. So it is always better to have two $5 bills instead of a
 * $10 bill as possible.)
 *
 * We can thus simulate the entire situation.
 *
 * We note also that we don’t have to remember how many $20 bills we have, since
 * there is nothing to do with them.
 */

#include <stdbool.h>

bool lemonadeChange(int *bills, int billsSize)
{
	int fives, tens;
	fives = tens = 0;

	for (int i = 0; i < billsSize; ++i) {
		switch (bills[i]) {
			case 5:
				++fives;
				break;
			case 10:
				if (fives == 0)
					return false;
				--fives;
				++tens;
				break;
			case 20:
				if (fives > 0 && tens > 0) {
					--fives;
					--tens;
				}
				else if (fives >= 3) {
					fives -= 3;
				}
				else {
					return false;
				}
				break;
			default:
				break;
		}
	}

	return true;
}
