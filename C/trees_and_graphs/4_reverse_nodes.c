#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

void
reverse_nodes_of_a_tree()
{
	int		index = 0;
	struct tree    *root;
	struct tree    *node;
	for (index = 0; index < 25; index += 1) {
		node = init_node((rand() % 100), NULL, NULL);
		add_node_to_bst(&root, node);
	}

	reverse_nodes(&root);	
	inorder(root);
	free_tree(root);
	printf("\n");
}

int main(int argc, char const *argv[])
{
	reverse_nodes_of_a_tree();
	return 0;
}