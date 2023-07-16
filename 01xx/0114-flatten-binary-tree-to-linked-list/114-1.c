/* 114. Flatten Binary Tree to Linked List */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(h)
 * where n is the number of nodes in the tree, and h is its height. */

#include <stdlib.h>

/* Do not copy the below struct definition to LeetCode. */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void flatten(struct TreeNode *root);
void flattenAndAppend(struct TreeNode *root, struct TreeNode *tail);

/* flatten(root): flattens a binary tree into a linked list, in pre-order. */
void flatten(struct TreeNode *root)
{
	flattenAndAppend(root, NULL);
}

/* flatten(root, tail): flattens the binary tree `root` into a linked list in
 * pre-order, and appends `tail` onto this list. */
void flattenAndAppend(struct TreeNode *root, struct TreeNode *tail)
{
	if (root == NULL)
		return;
	if (root->right != NULL) {
		flattenAndAppend(root->right, tail);
		tail = root->right;
		root->right = NULL;
	}
	if (root->left != NULL) {
		flattenAndAppend(root->left, tail);
		tail = root->left;
		root->left = NULL;
	}
	root->right = tail;
}
