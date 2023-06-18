/* Time: O(log(n))
 * Space: O(1)
 */

#include <stdbool.h>

bool isPowerOfTwo(int n){
	if (n <= 0)
		return false;

	while ((n & 1) == 0)
		n >>= 1;

	return (n >> 1) == 0;
}
