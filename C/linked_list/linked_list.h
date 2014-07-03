struct linked_list {
	int		data;
	struct linked_list *next;
};

struct linked_list *add_to_list(struct linked_list *head, int data);

struct linked_list *remove_from_list(struct linked_list *head, int data);

struct linked_list *add_node(struct linked_list *head, struct linked_list *node);

struct linked_list *remove_node(struct linked_list *head, struct linked_list *node);

int		display_list(struct linked_list *head);

struct linked_list *reverse_list(struct linked_list *head);

int		free_list  (struct linked_list *head);

struct linked_list * create_list_from_number(long number);

struct linked_list * add_numbers(struct linked_list *number1, struct linked_list *number2);
