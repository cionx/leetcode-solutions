/* 872. Leaf-Similar-Trees */

/* Complexities.
 * Time: Θ(n1 + n2)
 * Space: Ω(max(h1, h2)) and O(l1 + l2 + max(h1, h2))
 * where n1 and n2 are the number of nodes in the two trees, h1 and h2 are their
 * heights, and l1 and l2 are their number of leaves. */

#include <stdbool.h>
#include <stdlib.h>

/* Do not copy the below struct definition to LeetCode. */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct TreeNode TN;

/* AUXILIARY DATA STRUCTURE:
 * array of fixed length that supports pushing values onto it. */

struct PushArray {
	int size;
	int position;
	int *entries;
};

typedef struct PushArray PA;

PA *makePA(int size);
void freePA(PA *array);
bool isFullPA(PA *array);
void pushPA(int value, PA *array);
bool equalPA(PA *array1, PA *array2);

PA *makePA(int size)
{
	if (size < 0)
		return NULL;
	PA *result = malloc(sizeof(PA));
	result->entries = malloc((size_t) size * sizeof(int));
	result->size = size;
	result->position = 0;
	return result;
}

void freePA(PA *array)
{
	if (array == NULL)
		return;
	free(array->entries);
	free(array);
}

bool isFullPA(PA *array)
{
	return array == NULL || array->position == array->size;
}

void pushPA(int value, PA *array)
{
	if (isFullPA(array))
		return;
	array->entries[array->position] = value;
	++(array->position);
}

bool equalPA(PA *array1, PA *array2)
{
	if (array1 == NULL)
		return array2 == NULL;
	if (array2 == NULL)
		return array1 == NULL;
	/* From here on, both arrays are non-NULL. */
	if (array1->size != array2->size)
		return false;
	int commonSize = array1->size;
	for (int i = 0; i < commonSize; ++i)
		if (array1->entries[i] != array2->entries[i])
			return false;
	return true;
}

/* MAIN CODE. */

bool leafSimilar(TN *root1, TN *root2);
int leafNumber(TN *root);
PA *getLeafes(TN *root, int size);
void recordLeafes(TN *root, PA *counter);

bool leafSimilar(TN *root1, TN *root2)
{
	int leafNumber1 = leafNumber(root1);
	int leafNumber2 = leafNumber(root2);
	if (leafNumber1 != leafNumber2)
		return false;
	PA *leafes1 = getLeafes(root1, leafNumber1);
	PA *leafes2 = getLeafes(root2, leafNumber2);
	bool result = equalPA(leafes1, leafes2);
	free(leafes1);
	free(leafes2);
	return result;
}

int leafNumber(TN *root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return leafNumber(root->left) + leafNumber(root->right);
}

PA *getLeafes(TN *root, int size)
{
	PA *leafes = makePA(size);
	if (root != NULL)
		recordLeafes(root, leafes);
	return leafes;
}

void recordLeafes(TN *root, PA *counter)
{
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL)
		pushPA(root->val, counter);
	else {
		recordLeafes(root->left, counter);
		recordLeafes(root->right, counter);
	}
}
