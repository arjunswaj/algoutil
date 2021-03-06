#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

struct linked_list *
create_node()
{
	struct linked_list *node = (struct linked_list *)malloc(sizeof(struct linked_list));
	return node;
}

int
free_list(struct linked_list *head)
{
	struct linked_list *node;
	while (NULL != head) {
		node = head;
		head = head->next;
		free(node);
	}
	return 0;
}

struct linked_list *
add_to_list(struct linked_list *head, int data)
{
	struct linked_list *node = create_node();
	node->data = data;
	head = add_node(head, node);
	return head;
}

struct linked_list *
remove_from_list(struct linked_list *head, int data)
{
	struct linked_list *node = head;
	struct linked_list *temp;
	if (NULL == head) {
		node = head;
	} else if (head->data == data) {
		temp = head->next;
		free(head);
		node = temp;
	} else {
		node = head;
		while (NULL != head->next && head->next->data != data) {
			head = head->next;
		}
		if (NULL != head->next) {
			temp = head->next;
			head->next = head->next->next;
			free(temp);
		}
	}
	return node;

}

struct linked_list *
add_node(struct linked_list *head, struct linked_list *node)
{
	node->next = head;
	head = node;
	return head;
}

struct linked_list *
remove_node(struct linked_list *head, struct linked_list *node)
{
	struct linked_list *temp = head;
	struct linked_list *free_node;
	if (NULL == head) {
		temp = head;
	} else if (node == head) {
		temp = node;
		head = head->next;
		free(temp);
		temp = head;
	} else {
		temp = head;
		while (NULL != head && head->next != node) {
			head = head->next;
		}
		if (NULL != head) {
			free_node = head->next;
			head->next = head->next->next;
			free(free_node);
		}
	}
	return temp;
}

int
display_list(struct linked_list *head)
{
	struct linked_list *node = head;
	while (NULL != node) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
	return 0;
}

struct linked_list *
reverse_list(struct linked_list *head)
{
	struct linked_list *temp = head;
	struct linked_list *temp2 = NULL;
	while (NULL != head) {
		temp = head;
		head = head->next;
		temp->next = temp2;
		temp2 = temp;
	}
	return temp2;
}

struct linked_list *
reverse_list_recursion(struct linked_list **head_address)
{
	struct linked_list *head = *head_address;
	struct linked_list *next_node = head->next;
	struct linked_list *temp;
	if (NULL == next_node)
	{
		return head;
	}
	temp = reverse_list_recursion(&next_node);
	next_node->next = head;
	head->next = NULL;
	return temp;
}

struct linked_list *
create_list_from_number(long number)
{
	int		last_digit = 0;
	struct linked_list *number_node = NULL;
	while (number != 0) {
		last_digit = number % 10;
		number /= 10;
		number_node = add_to_list(number_node, last_digit);
	}
	return number_node;
}

struct linked_list *
add_numbers(struct linked_list *number1, struct linked_list *number2)
{

	int		carry = 0;
	int		sum = 0;
	struct linked_list *tno1;
	struct linked_list *tno2;
	struct linked_list *result = NULL;

	number1 = reverse_list(number1);
	number2 = reverse_list(number2);

	tno1 = number1;
	tno2 = number2;
	while (NULL != number1 && NULL != number2) {
		sum = carry + number1->data + number2->data;
		carry = sum / 10;
		sum %= 10;
		result = add_to_list(result, sum);
		number1 = number1->next;
		number2 = number2->next;
	}
	while (NULL != number1) {
		sum = carry + number1->data;
		carry = sum / 10;
		sum %= 10;
		result = add_to_list(result, sum);
		number1 = number1->next;
	}
	while (NULL != number2) {
		sum = carry + number2->data;
		carry = sum / 10;
		sum %= 10;
		result = add_to_list(result, sum);
		number2 = number2->next;
	}
	if (0 < carry) {
		result = add_to_list(result, carry);
	}
	number1 = reverse_list(tno1);
	number2 = reverse_list(tno2);
	return result;
}

struct linked_list *
pop(struct linked_list **head_address)
{
	struct linked_list *head = *head_address;
	struct linked_list *temp = head;
	*head_address = head->next;
	temp->next = NULL;
	return temp;
}

struct linked_list *
peek(struct linked_list **head_address)
{
	struct linked_list *head = *head_address;
	struct linked_list *temp = head;
	return temp;
}

int 
push(struct linked_list **head_address, struct linked_list *data)
{
	struct linked_list *head = *head_address;
	data->next = head;
	*head_address = data;
	return 0;
}

int 
push_data(struct linked_list **head_address, int data)
{
	struct linked_list *head = *head_address;
	struct linked_list *temp = create_node();
	temp->data = data;
	temp->next = head;
	*head_address = temp;
	return 0;
}

struct linked_list *
sort_stack(struct linked_list **stack_address)
{
	struct linked_list *stack = *stack_address;
	struct linked_list *sorted_stack = NULL;
	struct linked_list *data_item = NULL;
	struct linked_list *sorted_data_item = NULL;

	while (NULL != stack) {
		data_item = pop(&stack);
		//printf("Popped %d from stack\n", data_item->data);
		while ((NULL != sorted_stack)
		       && (NULL != (sorted_data_item = peek(&sorted_stack)))
		       && (sorted_data_item->data < data_item->data)) {
			//printf("Pushed %d into stack\n", sorted_stack->data);
			push(&stack, pop(&sorted_stack));
		}
		push(&sorted_stack, data_item);
	}

	return sorted_stack;
}
