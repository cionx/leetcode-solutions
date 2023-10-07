/* 1672. Richest Customer Wealth */

/* Complexities.
 * Time: Θ(m n)
 * Space: Θ(1)
 * where m × n is the size of the input grid. */

#include <limits.h>

int maximumWealth(int **accounts, int accountsSize, int *accountsColSize)
{
	int customersSize = accountsSize;
	int banksSize = accountsColSize[0];

	int richest = INT_MIN;
	for (int customer = 0; customer < customersSize; ++customer) {
		int wealth = 0;
		for (int bank = 0; bank < banksSize; ++bank)
			wealth += accounts[customer][bank];
		if (wealth > richest)
			richest = wealth;
	}

	return richest;
}
