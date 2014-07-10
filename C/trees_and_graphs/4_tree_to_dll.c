#include "tree.h"
#include <stdlib.h>


void
create_dll_from_tree()
{
	int		index = 0;
	struct tree    *root;
	struct tree    *node;
	for (index = 0; index < 100007; index += 1) {
		node = init_node((rand() % 10000000), NULL, NULL);
		add_node_to_bst(&root, node);
	}

	tree_to_doubly_linked_list(&root);	
}

int 
main(int argc, char const *argv[])
{
	create_dll_from_tree();
	return 0;
}
