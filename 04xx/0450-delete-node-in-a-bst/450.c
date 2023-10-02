/* 450. Delete Note in a BST */

/* Complexities.
 * Time: O(h)
 * Space: O(h)
 * where h is the height of the tree. */

#include <stdlib.h>

/* Do not copy this struct definition to LeetCode. */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct TreeNode TN;

TN *deleteNode(TN *root, int key);
TN *appendToLeft(TN *node, TN *root);

TN *deleteNode(TN *root, int key)
{
	if (root == NULL)
		return NULL;

	if (key < root->val) {
		root->left = deleteNode(root->left, key);
		return root;
	}
	if (key > root->val) {
		root->right = deleteNode(root->right, key);
		return root;
	}
	/* We delete the root, and append the left subtree to the right subtree. */
	return appendToLeft(root->left, root->right);
}

TN *appendToLeft(TN *node, TN *root)
{
	if (root == NULL)
		return node;
	root->left = appendToLeft(node, root->left);
	return root;
}
