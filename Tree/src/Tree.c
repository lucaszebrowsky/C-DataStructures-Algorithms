#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

// helper function for indentation
static void print_tab(int level)
{
	for (int i = 0; i < level; i++) {
		printf("\t");
	}
}

static void tree_print_recursive(treenode_t *root, int level)
{
	if (NULL == root) {
		print_tab(level);
		printf("---empty---\n");
		return;
	}

	print_tab(level);
	printf("value = %d\n", root->value);

	print_tab(level);
	printf("left\n");
	tree_print_recursive(root->left, level + 1);

	print_tab(level);
	printf("right\n");
	tree_print_recursive(root->right, level + 1);

	print_tab(level);
	printf("done\n");
}

void tree_print(treenode_t *root)
{
	tree_print_recursive(root, 0);
}

treenode_t *tree_create_node(int value)
{
	treenode_t *tn = malloc(sizeof(treenode_t));

	if (NULL != tn) {
		tn->value = value;
	}

	return tn;
}
