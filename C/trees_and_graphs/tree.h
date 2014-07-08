#define FOUND 0
#define NOT_FOUND -1

#define LEFT_CHILD -2
#define RIGHT_CHILD -3

struct tree {
	int		data;
	struct tree    *left;
	struct tree    *right;
};

struct list {
	struct tree    *data;
	struct list    *next;
};

struct tree    *init_node(int data, struct tree *left, struct tree *right);

int		height     (struct tree *root);

int		check_balanced(struct tree *root);

int		check_balanced_optimized(struct tree *root);

int		enqueue_list(struct list **head_address, struct list **tail_address, struct tree *data);

struct list    *dequeue_list(struct list **head_address, struct list **tail_address);

int		add_node_to_bst(struct tree **root_address, struct tree *node);

void		inorder   (struct tree *root);

void		free_tree (struct tree *root);

struct tree    *make_bst_from_array(int array[], int low, int high);

int		find_node  (struct tree *root, struct tree *node);

struct tree    *lca(struct tree *root, struct tree *node_1, struct tree *node_2);

int		path_to_key(struct tree *root, int key);

void		tree_to_doubly_linked_list(struct tree **root_address);

void		reverse_nodes(struct tree **root_address);


