#include "Tree.h"
#include <stdlib.h>

int main(void)
{
	treenode_t *n1 = tree_create_node(12);
	treenode_t *n2 = tree_create_node(44);
	treenode_t *n3 = tree_create_node(39);
	treenode_t *n4 = tree_create_node(77);
	treenode_t *n5 = tree_create_node(2);

	n1->left = n2;
	n1->right = n3;

	n2->left = n4;
	n2->right = n5;

	tree_print(n1);

	free(n5);
	free(n4);
	free(n3);
	free(n2);
	free(n1);
	return 0;
}
