/* 1448. Count Good Nodes in Binary Tree */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(h)
 * where n is the number of nodes in the input tree, and h is its height. */

#include <stdlib.h>

/* Do not copy the below struct definition to LeetCode. */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int goodNodes(struct TreeNode *root);
void addGoodNodes(struct TreeNode *root, int max, int *counter);

int goodNodes(struct TreeNode *root)
{
	int counter = 0;
	if (root != NULL) {
		++counter;
		addGoodNodes(root->left, root->val, &counter);
		addGoodNodes(root->right, root->val, &counter);
	}
	return counter;
}

void addGoodNodes(struct TreeNode *root, int max, int *counter)
{
	if (root == NULL)
		return;
	if (root->val >= max) { /* A good node. */
		++(*counter);
		max = root->val;
	}
	addGoodNodes(root->left, max, counter);
	addGoodNodes(root->right, max, counter);
}
