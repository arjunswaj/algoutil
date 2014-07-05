#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

int min(int a, int b) {
	return a > b ? b : a;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int abs (int a) {
	return a > 0 ? a : (-1 * a);
}

struct tree *
create_node()
{	
	struct tree *node = (struct tree *)malloc(sizeof(struct tree));
	return node;
}

struct list *
create_list_node()
{
	struct list *node = (struct list *)malloc(sizeof(struct list));

	return node;
}

struct tree * 
init_node(int data, struct tree *left, struct tree *right) {
	struct tree *node = create_node();
	node->data = data;
	node->left = left;
	node->right = right;
	return node;
}

int height(struct tree *root){
	if (NULL == root)
	{
		return 0;
	}
	return max(height(root->left), height(root->right)) + 1;
}

int check_balanced(struct tree *root) {
	int left_tree_height = 0;
	int right_tree_height = 0;
	if (NULL == root)
	{
		return 0;
	}

	left_tree_height = height(root->left);
	right_tree_height = height(root->right);

	if (abs(left_tree_height - right_tree_height) > 1)
	{
		return -1;
	} else {
		return 0;
	}
}

int check_balanced_optimized(struct tree *root) {
	int left_tree_height = 0;
	int right_tree_height = 0;
	if (NULL == root)
	{
		return 0;
	}
	left_tree_height = check_balanced_optimized(root->left);
	if (-1 == left_tree_height)
	{
		return left_tree_height;
	}

	right_tree_height = check_balanced_optimized(root->right);
	if (-1 == right_tree_height)
	{
		return right_tree_height;
	}

	if (abs(left_tree_height - right_tree_height) > 1)
	{
		return max(left_tree_height, right_tree_height) + 1;
	} else {
		return -1;
	}
}

int
display_list(struct list *head)
{
	struct list *node = head;
	while (NULL != node) {
		printf("%d ", node->data->data);
		node = node->next;
	}
	printf("\n");
	return 0;
}


int enqueue_list(struct list **head_address, struct list **tail_address, struct tree *data){	
	struct list *head = *head_address;
	struct list *tail = *tail_address;
	struct list *temp = create_list_node();
	temp->data = data;	
	
	if (NULL == head && NULL == tail)
	{				
		//printf("Head and tail are null\n");
		*head_address = temp;		
		*tail_address = temp;
	} else {	
		tail->next = temp;								
		*tail_address = temp;
		//printf("Head and tail are not null\n");
	}	
	return 0;
}

struct list *dequeue_list(struct list **head_address, struct list **tail_address) {
	struct list *head = *head_address;
	struct list *tail = *tail_address;	
	struct list *temp = head;			
	if (NULL != head)
	{		
		if (head == tail)
		{				
			//printf("Head and tail are same\n");
			*tail_address = NULL;
			*head_address = NULL;
		} else {
			*head_address = head->next;
		}	
		temp->next = NULL;	
		return temp;

	} else {
		return NULL;
	}
}

int add_node_to_bst(struct tree **root_address, struct tree *node) {
	struct tree *root = *root_address;
	if (NULL == root)
	{
		*root_address = node;
		return 0;
	}
	if (root->data >= node->data)
	{
		if (NULL == root->left)
		{
			root->left = node;			
		} else {
			add_node_to_bst(&(root->left), node);
		}
	} else {
		if (NULL == root->right)
		{
			root->right = node;			
		} else {
			add_node_to_bst(&(root->right), node);
		}
	}
	return 0;
}

void inorder(struct tree *root) {
	if (NULL == root)
	{
		return;
	}
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}
