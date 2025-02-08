#pragma once

typedef struct treenode {
	int value;
	struct treenode *left;
	struct treenode *right;
} treenode_t;

void tree_print(treenode_t *root);

treenode_t *tree_create_node(int value);
