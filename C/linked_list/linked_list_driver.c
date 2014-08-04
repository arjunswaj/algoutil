#include "linked_list.h"
#include <stdio.h>


int 
main(int argc, char const *argv[])
{
	struct linked_list *head;
	head = NULL;
	head = add_to_list(head, 1);
	display_list(head);
	head = add_to_list(head, 2);
	display_list(head);
	head = add_to_list(head, 3);
	display_list(head);
	head = add_to_list(head, 4);
	display_list(head);
	head = reverse_list(head);
	display_list(head);
	printf("Reverse by recursion\n");
	head = reverse_list_recursion(&head);
	display_list(head);
	head = remove_from_list(head, 4);
	display_list(head);
	head = remove_from_list(head, 2);
	display_list(head);
	head = add_to_list(head, 8);
	display_list(head);
	head = add_to_list(head, 9);
	display_list(head);
	head = reverse_list(head);
	display_list(head);
	free_list(head);
	return 0;
}
