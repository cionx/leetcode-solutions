/* Time: O(n)
 * Space: O(h)
 *
 * where n is the number of nodes in the tree,
 * and h is the height of the tree.
 *
 * Like solution 1, but in C.
 */

#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/* Do not copy the above struct definition to LeetCode. */

int maxLevelSum(struct TreeNode *root);
int height(struct TreeNode *root);
void addNodes(struct TreeNode *root, int rootLevel, long *levelSums);
int maxInt(int a, int b);

int maxLevelSum(struct TreeNode *root)
{
	int treeHeight = height(root);
	long *levelSums = calloc((size_t) treeHeight + 1, sizeof(long));

	addNodes(root, 1, levelSums);

	int richestLevel = 1;
	for (int level = 2; level <= treeHeight; ++level)
		if (levelSums[level] > levelSums[richestLevel])
			richestLevel = level;

	free(levelSums);
	return richestLevel;
}

int height(struct TreeNode *root)
{
	if (root == NULL)
		return 0;
	return 1 + maxInt(height(root->left), height(root->right));
}

void addNodes(struct TreeNode *root, int rootLevel, long *levelSums)
{
	if (root == NULL)
		return;
	levelSums[rootLevel] += root->val;
	addNodes(root->left, rootLevel + 1, levelSums);
	addNodes(root->right, rootLevel + 1, levelSums);
}

int maxInt(int a, int b)
{
	return (a > b) ? a : b;
}
