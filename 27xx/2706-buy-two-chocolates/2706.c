/* 2706. Buy Two Chocolates */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input array. */

#define LARGER_THAN_ANY_PRICE 101

int buyChoco(const int *prices, int pricesSize, int money)
{
	int secondCheapest = LARGER_THAN_ANY_PRICE;
	int cheapest = LARGER_THAN_ANY_PRICE;

	for (int i = 0; i < pricesSize; ++i)
		if (prices[i] < secondCheapest) {
			if (prices[i] < cheapest) {
				secondCheapest = cheapest;
				cheapest = prices[i];
			}
			else {
				secondCheapest = prices[i];
			}
		}

	/* The constraints state that pricesSize >= 2, so both instances of the
	 * initial value LARGER_THAN_ANY_PRICE will have been replace by actual
	 * prices. We can therefore compute the total.
	 */
	int total = cheapest + secondCheapest;

	return (total <= money) ? (money - total) : money;
}
