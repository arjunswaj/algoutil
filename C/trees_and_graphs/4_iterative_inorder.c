#include "tree.h"
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int		index = 0;
	struct tree    *root;
	struct tree    *node;
	for (index = 0; index < 25; index += 1) {
		node = init_node((rand() % 100), NULL, NULL);
		add_node_to_bst(&root, node);
	}	
	iterative_inorder(root);
	free_tree(root);	
	return 0;
}