#include "linked_list.h"
#include <stdio.h>


int 
main(int argc, char const *argv[])
{
	struct linked_list *number1;
	struct linked_list *number2;
	struct linked_list *result;
	number1 = NULL;
	number2 = NULL;
	result = NULL;


	number1 = create_list_from_number(12345678987654321);
	number2 = create_list_from_number(1234);

	result = add_numbers(number1, number2);
	display_list(number1);
	display_list(number2);
	display_list(result);

	free_list(number1);
	free_list(number2);
	free_list(result);
	return 0;
}
