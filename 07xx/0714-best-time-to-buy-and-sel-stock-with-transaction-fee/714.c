/* 714. Best Time to Buy and Sell Stocks with Transaction Fee. */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the size of the input list. */

/* Idea.
 * We will determine the maximal profit we can have at the end of each day. We
 * distinguish between two cases:
 * 1. We hold no stock at the end of the day.
 * 2. We hold some stock at the end of the day.
 * For every day, we have therefore two results, which we call noStock[i] and
 * yesStock[i] respectively. We make the following observations:
 *
 * - Suppose that we finished day i-1 with no stock, and also want to finish
 *   day i without stock. This means that we did nothing on day i. This entails
 *   that our account balance didn’t change:
 *   balance -> balance
 *
 * - Suppose that we finished day i-1 with no stock, but want to finish day i
 *   with some stock. We then need to buy stocks, costing us price[i]:
 *   balance -> balance - prices[i].
 *
 * - Suppose that we finished day i-1 with some stock, but want to finish day i
 *   with no stock. We then need to sell the stock for price[i] and pay the
 *   transaction fee:
 *   balance -> balance + prices[i] - fee
 *
 * - Suppose that we finished day i-1 with some stock, and also want to finish
 *   day i with some stock. We then do nothing:
 *   balance -> balance.
 *
 * We see that a larger profit after day i-1 alway translate into a larger
 * profit after day i. We can therefore determine noStock[i] and yesStock[i]
 * via the above formulas from noStock[i-1] and yesStock[i-1]:
 *   noStock[i] = max(noStock[i-1], yesStock[i] + prices[i] - fee),
 *   yesStock[i] = max(yesStock[i], noStock[i] - prices[i]).
 */

int maxProfit(int *prices, int days, int fee);
long long max(long long a, long long b);

int maxProfit(int *prices, int days, int fee)
{
	if (days == 0)
		return 0;

	long long noStock = 0;
	long long yesStock = -prices[0];
	for (int i = 1; i < days; ++i) {
		const long long prevNoStock = noStock;
		const long long prevYesStock = yesStock;
		noStock = max(prevNoStock, prevYesStock + prices[i] - fee);
		yesStock = max(prevNoStock - prices[i], prevYesStock);
	}

	/* Because stock prices are always non-negative, we will always return
	 * noStock: we either sell our stock on the last day (if the fee isn’t
	 * larger than the sell price), or didn’t buy it in the first place. But
	 * by considering the maximum of noStock and yesStock we also allow for
	 * possibly negative stock prices.
	 */
	/* We’d prefer to return a long long, but LeetCode wants an int. */
	return (int) max(noStock, yesStock);
}

long long max(long long a, long long b)
{
	return (a > b) ? a : b;
}
