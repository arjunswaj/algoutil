#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int 
find_path(struct tree *source, struct tree *destination)
{
	struct list    *head = NULL;
	struct list    *tail = NULL;
	struct list    *node = NULL;
	struct tree    *tree_node = NULL;
	
	enqueue_list(&head, &tail, source);

	while (NULL != (node = dequeue_list(&head, &tail))) {
		tree_node = node->data;		
		if (tree_node == destination) {
			return 0;
		} else {
			if (NULL != tree_node->left) {				
				enqueue_list(&head, &tail, tree_node->left);
			}
			if (NULL != tree_node->right) {				
				enqueue_list(&head, &tail, tree_node->right);
			}
		}
	}
	return -1;

}

int 
create_tree_and_find_path()
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

	return find_path(node_3, node_4);
}

int 
main(int argc, char const *argv[])
{

	if (0 == create_tree_and_find_path()) {
		printf("There is a path between source and destination\n");
	} else {
		printf("There is no path between source and destination\n");
	}
	return 0;
}
