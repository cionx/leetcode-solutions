/* 98. Validate Binary Search Tree */

/* Recursive solution. */

/* Complexities.
 * Time: Θ(n)
 * Space O(h)
 * where n is the number of nodes in the tree and h is its height. */

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

/* Do not copy the below struct definition to LeetCode. */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isValidBST(struct TreeNode *root);
bool isBSTBetween(struct TreeNode *root, int lower, int upper);

/* isValidBST(root): checks if the binary tree `root` is a BST. */
bool isValidBST(struct TreeNode *root)
{
	return isBSTBetween(root, INT_MIN, INT_MAX);
}

/* isBSTBetween(root, lower, upper): Checks whether `root` is a BST whose node
 * values all lie between `lower` and `upper` (inclusive). */
bool isBSTBetween(struct TreeNode *root, int lower, int upper)
{
	return root == NULL ||
	       /* Check root value. */
	       lower <= root->val && root->val <= upper &&
	           /* Check left subtree. */
	           (root->val == INT_MIN
	                ? (root->left == NULL)
	                : isBSTBetween(root->left, lower, root->val - 1)) &&
	           /* Check right subtree. */
	           (root->val == INT_MAX
	                ? (root->right == NULL)
	                : isBSTBetween(root->right, root->val + 1, upper));
}
