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
