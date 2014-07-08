#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

int
min(int a, int b)
{
	return a > b ? b : a;
}

int
max(int a, int b)
{
	return a > b ? a : b;
}

int
abs(int a)
{
	return a > 0 ? a : (-1 * a);
}

struct tree    *
create_node()
{
	struct tree    *node = (struct tree *)malloc(sizeof(struct tree));
	return node;
}

struct list    *
create_list_node()
{
	struct list    *node = (struct list *)malloc(sizeof(struct list));

	return node;
}

struct tree    *
init_node(int data, struct tree *left, struct tree *right)
{
	struct tree    *node = create_node();
	node->data = data;
	node->left = left;
	node->right = right;
	return node;
}

int
height(struct tree *root)
{
	if (NULL == root) {
		return 0;
	}
	return max(height(root->left), height(root->right)) + 1;
}

int
check_balanced(struct tree *root)
{
	int		left_tree_height = 0;
	int		right_tree_height = 0;
	if (NULL == root) {
		return 0;
	}
	left_tree_height = height(root->left);
	right_tree_height = height(root->right);

	if (abs(left_tree_height - right_tree_height) > 1) {
		return -1;
	} else {
		return 0;
	}
}

int
check_balanced_optimized(struct tree *root)
{
	int		left_tree_height = 0;
	int		right_tree_height = 0;
	if (NULL == root) {
		return 0;
	}
	left_tree_height = check_balanced_optimized(root->left);
	if (-1 == left_tree_height) {
		return left_tree_height;
	}
	right_tree_height = check_balanced_optimized(root->right);
	if (-1 == right_tree_height) {
		return right_tree_height;
	}
	if (abs(left_tree_height - right_tree_height) > 1) {
		return max(left_tree_height, right_tree_height) + 1;
	} else {
		return -1;
	}
}

int
display_list(struct list *head)
{
	struct list    *node = head;
	while (NULL != node) {
		printf("%d ", node->data->data);
		node = node->next;
	}
	printf("\n");
	return 0;
}


int
enqueue_list(struct list **head_address, struct list **tail_address, struct tree *data)
{
	struct list    *head = *head_address;
	struct list    *tail = *tail_address;
	struct list    *temp = create_list_node();
	temp->data = data;

	if (NULL == head && NULL == tail) {
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

struct list    *
dequeue_list(struct list **head_address, struct list **tail_address)
{
	struct list    *head = *head_address;
	struct list    *tail = *tail_address;
	struct list    *temp = head;
	if (NULL != head) {
		if (head == tail) {
			printf("Head and tail are same\n");
			*tail_address = NULL;
			*head_address = NULL;
		} else {
			*head_address = head->next;
		}
		//temp->next = NULL;
		return temp;

	} else {
		return NULL;
	}
}

int
add_node_to_bst(struct tree **root_address, struct tree *node)
{
	struct tree    *root = *root_address;
	if (NULL == root) {
		*root_address = node;
		return 0;
	}
	if (root->data >= node->data) {
		if (NULL == root->left) {
			root->left = node;
		} else {
			add_node_to_bst(&(root->left), node);
		}
	} else {
		if (NULL == root->right) {
			root->right = node;
		} else {
			add_node_to_bst(&(root->right), node);
		}
	}
	return 0;
}

void
inorder(struct tree *root)
{
	if (NULL == root) {
		return;
	}
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

void
free_tree(struct tree *root)
{
	if (NULL == root) {
		return;
	}
	free_tree(root->left);
	free_tree(root->right);
	free(root);
}


struct tree    *
make_bst_from_array(int array[], int low, int high)
{
	int		mid = (low + high) / 2;
	struct tree    *node;
	if (low > high) {
		return NULL;
	}
	node = init_node(array[mid], NULL, NULL);
	node->left = make_bst_from_array(array, low, mid - 1);
	node->right = make_bst_from_array(array, mid + 1, high);
	return node;
}

int
find_node(struct tree *root, struct tree *node)
{
	int		find_status = NOT_FOUND;
	if (NULL == root) {
		return NOT_FOUND;
	}
	if (root == node) {
		return FOUND;
	}
	if (FOUND == find_node(root->left, node)) {
		return FOUND;
	}
	if (FOUND == find_node(root->right, node)) {
		return FOUND;
	}
	return NOT_FOUND;
}

struct tree    *
lca(struct tree *root, struct tree *node_1, struct tree *node_2)
{
	struct tree    *lca_node;
	int		node_1_left;
	int		node_2_left;
	int		node_1_right;
	int		node_2_right;

	if (NULL == root) {
		return NULL;
	}
	if (node_1 == root || node_2 == root) {
		return root;
	}
	node_1_left = find_node(root->left, node_1);
	node_2_left = find_node(root->left, node_2);

	if (node_1_left != node_2_left) {
		//Found on different sides, so, root is the LCA
			return root;
	} else if (node_1_left == node_2_left) {
		//Found on the same side, so, explore the sub tree
			if (node_1_left == FOUND) {
			//Found in the left sub tree
				lca_node = lca(root->left, node_1, node_2);
		} else if (node_1_left == NOT_FOUND) {
			//Not found in left sub tree, so, should be in the right sub tree
				lca_node = lca(root->right, node_1, node_2);
		}
	}
	return lca_node;
}

int
path_to_key(struct tree *root, int key)
{
	int		found_status_left;
	int		found_status_right;
	if (NULL == root) {
		return NOT_FOUND;
	}
	if (key == root->data) {
		printf("%d <-- ", root->data);
		return FOUND;
	}
	found_status_left = path_to_key(root->left, key);
	if (FOUND == found_status_left) {
		printf("%d <-- ", root->data);
		return FOUND;
	}
	found_status_right = path_to_key(root->right, key);
	if (FOUND == found_status_right) {
		printf("%d <-- ", root->data);
		return FOUND;
	}
	return NOT_FOUND;
}

void
tree_flattner(struct tree **child_address,
	      struct tree **parent_address,
	      int child_type)
{
	if (NULL == *parent_address) {
		return;
	}
	struct tree    *temp = NULL;
	struct tree    *child = *child_address;
	struct tree    *parent = *parent_address;

	tree_flattner(&child->left, &child, LEFT_CHILD);
	tree_flattner(&child->right, &child, RIGHT_CHILD);

	temp = child;
	if (child_type == LEFT_CHILD) {
		if (NULL != temp) {
			while (NULL != temp->right) {
				temp = temp->right;
			}
			parent->left = temp;
			temp->right = parent;
		}
	} else if (child_type == RIGHT_CHILD) {
		if (NULL != temp) {
			while (NULL != temp->left) {
				temp = temp->left;
			}
			parent->right = temp;
			temp->left = parent;
		}
	}
}

void
tree_to_doubly_linked_list(struct tree **root_address)
{
	struct tree    *root = *root_address;
	struct tree    *node;
	if (NULL == root) {
		return;
	}
	if (NULL != root->left) {
		tree_flattner(&root->left, &root, LEFT_CHILD);
	}
	if (NULL != root->right) {
		tree_flattner(&root->right, &root, RIGHT_CHILD);
	}
	while (NULL != root->left) {
		root = root->left;
	}
	while (NULL != root) {
		printf("%d ", root->data);
		node = root;
		root = root->right;
		free(node);
	}
	printf("\n");
}

void
reverse_nodes(struct tree **root_address)
{
	struct tree    *root = *root_address;
	struct tree    *temp_node;
	if (NULL == root) {
		return;
	}
	reverse_nodes(&root->left);
	reverse_nodes(&root->right);

	temp_node = root->left;
	root->left = root->right;
	root->right = temp_node;

}

void
reverse_nodes_alternate_level(struct tree **root_address, int level)
{
	struct tree    *root = *root_address;
	struct tree    *temp_node;
	if (NULL == root) {
		return;
	}
	reverse_nodes_alternate_level(&root->left, level + 1);
	reverse_nodes_alternate_level(&root->right, level + 1);

	if (0 == (level % 2)) {
		temp_node = root->left;
		root->left = root->right;
		root->right = temp_node;
	}
}
