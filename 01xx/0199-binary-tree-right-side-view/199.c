/* 199. Binary Tree Right Side View */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(h)
 * where n is the number of nodes of the tree, and h is its height. */

/* Idea.
 * We create an array of the correct size (the height of the tree) and hold it
 * vertically to the left of the tree. We first project the left subtree onto
 * the array, place the root value at the correct height, and then project the
 * right subtree onto the array:
 *
 * result[0]    <---      1
 *                       / \        Project first the left subtree,
 * result[1]    <---    2   3       then the root,
 *                       \   \      then the right subtree.
 * result[2]    <---      5   4
 */

#include <stdlib.h>

/* Do not copy this struct definition to LeetCode. */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct TreeNode TN;

int *rightSideView(TN *root, int *returnSize);
void project(TN *node, int height, int *seenValues);
int treeHeight(TN *root);
int max(int a, int b);

int *rightSideView(TN *root, int *returnSize)
{
	*returnSize = treeHeight(root);
	int *result = malloc((size_t) *returnSize * sizeof(int));
	project(root, 0, result);
	return result;
}

void project(TN *node, int height, int *seenValues)
{
	if (node == NULL)
		return;
	project(node->left, height + 1, seenValues);
	seenValues[height] = node->val;
	project(node->right, height + 1, seenValues);
}

int treeHeight(TN *root)
{
	if (root == NULL)
		return 0;
	return 1 + max(treeHeight(root->left), treeHeight(root->right));
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}
