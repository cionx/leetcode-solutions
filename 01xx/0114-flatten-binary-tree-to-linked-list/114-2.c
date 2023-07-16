/* 114. Flatten Binary Tree to Linked List */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the number of nodes in the tree, and h is its height. (For the
 * time complexity, note that the function rightMost traverses each node at most
 * once.) */

/* Idea.
 * We can get a bit closer to the desired result by rearranging the tree
 *    *
 *   / \
 *  A   B
 * as follows:
 *    *
 *     \
 *      A
 *       \
 *        B
 * We can then descend into the right subtree, and proceed by induction. (we are
 * loosing one node each induction step, whence we will eventually finish.) */

#include <stdlib.h>

/* Do not copy the below struct definition to LeetCode. */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void flatten(struct TreeNode *root);
struct TreeNode *rightMost(struct TreeNode *root);

/* flatten(root): flattens a binary tree into a linked list, in pre-order. */
void flatten(struct TreeNode *root)
{
	while (root != NULL) {
		if (root->left != NULL) {
			struct TreeNode *leftRightMost = rightMost(root->left);
			leftRightMost->right = root->right;
			root->right = root->left;
		}
		root->left = NULL;
		root = root->right;
	}
}

/* rightMost(root) is the largest, and thus right-most, node in the input. */
struct TreeNode *rightMost(struct TreeNode *root)
{
	if (root == NULL)
		return root;
	while (root->right != NULL)
		root = root->right;
	return root;
}
