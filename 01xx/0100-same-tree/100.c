/* 100. Same Tree */

/* Complexities.
 * Time: O(min(n1, n2))
 * Space: O(min(h1, h2))
 * where n1 and n2 are the respective number of nodes in the two trees, and h1
 * and h2 are their respective heights. */

#include <stdbool.h>
#include <stdlib.h>

/* Do not copy the below struct definition to LeetCode. */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
	return (p == NULL && q == NULL) ||
	       (p != NULL && q != NULL && p->val == q->val &&
	        isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}
