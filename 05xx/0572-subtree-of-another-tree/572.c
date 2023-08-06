/* 572. Subtree of Another Tree */

/* Complexities.
 * Time: O(n1 n2)
 * Space: Θ(max(h1, h2))
 * where n1 and n2 are the respective numbers of nodes in the two input trees,
 * and h1 and h2 are their respective heights. */

#include <stdbool.h>
#include <stdlib.h>

/* Do not copy the following struct definition to LeetCode. */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isSubtree(struct TreeNode *root, struct TreeNode *subRoot);
bool areEqualTrees(struct TreeNode *root1, struct TreeNode *root2);

bool isSubtree(struct TreeNode *root, struct TreeNode *subRoot)
{
	if (root == NULL)
		return subRoot == NULL;
	return areEqualTrees(root, subRoot) || isSubtree(root->left, subRoot) ||
	       isSubtree(root->right, subRoot);
}

bool areEqualTrees(struct TreeNode *root1, struct TreeNode *root2)
{
	if (root1 == NULL)
		return root2 == NULL;
	if (root2 == NULL)
		return root1 == NULL;
	return root1->val == root2->val &&
	       areEqualTrees(root1->left, root2->left) &&
	       areEqualTrees(root1->right, root2->right);
}
