#include "tree.h"
#include <stdio.h>
#define SIZE 10


int 
main(int argc, char const *argv[])
{
	int		array      [] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	struct tree    *root = make_bst_from_array(array, 0, SIZE - 1);
	inorder(root);
	free_tree(root);
	printf("\n");
	return 0;
}
