#include "../linked_list/linked_list.h"
#include <stdlib.h>
int 
main(int argc, char const *argv[])
{
	struct linked_list *stack;
	struct linked_list *sorted_stack;

	int		random_number = 0;
	int		index = 0;

	for (int index = 0; index < 15; index += 1) {
		push_data(&stack, rand() % 100);
	}



	display_list(stack);
	sorted_stack = sort_stack(&stack);
	display_list(sorted_stack);

	free_list(sorted_stack);
	return 0;
}
