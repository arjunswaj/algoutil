#include "tree.h"
#include <stdio.h>

void
create_tree_and_find_path_from_root_to_key()
{

	struct tree    *node_10 = init_node(10, NULL, NULL);

	struct tree    *node_8 = init_node(8, NULL, node_10);
	struct tree    *node_9 = init_node(9, NULL, NULL);

	struct tree    *node_6 = init_node(6, NULL, NULL);
	struct tree    *node_7 = init_node(7, NULL, NULL);

	struct tree    *node_5 = init_node(5, node_8, node_9);
	struct tree    *node_4 = init_node(4, NULL, NULL);

	struct tree    *node_3 = init_node(3, node_6, node_7);
	struct tree    *node_2 = init_node(2, node_4, node_5);

	struct tree    *node_1 = init_node(1, node_2, node_3);	

	path_to_key(node_1, 10);

	free_tree(node_1);
}

int 
main(int argc, char const *argv[])
{
	create_tree_and_find_path_from_root_to_key();
	printf("\n");
	return 0;
}
