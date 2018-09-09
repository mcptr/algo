#include "../c-utils/std.h"
#include "../c-utils/utils.h"
#include "list.h"


struct node_t *list_create_node(int value)
{
	struct node_t *node = malloc(sizeof(struct node_t));

	node->data = value;
	node->next = NULL;

	return node;
}

int list_append(struct node_t *list, struct node_t *node)
{
	if(!list)
		return -1;

	struct node_t *p = list;
	debug("list_append: %p\n", (void*)p);
	while(p && p->next)
		p = p->next;

	debug("\tappend: %p\n", (void*)p);
	p->next = node;

	return 0;
}

void list_clear(struct node_t *list)
{
	struct node_t *p = list->next;
	struct node_t *tmp;
	while(p && p->next) {
		tmp = p->next;
		debug("list_clear: %d (%p)\n", p->data, (void*)p);
		free(p);
		p = tmp;
	}
	list->next = NULL;
}

void list_print(struct node_t const *list)
{
	struct node_t const *p = list->next;
	printf("[");
	while(p) {
		printf("%d, ", p->data);
		p = p->next;
	}
	printf("]\n");
}

void list_insert_sorted(struct node_t *list, struct node_t *newp)
{
	struct node_t *p = list;

	while(p->next && p->next->data < newp->data) {
		p = p->next;
	}

	debug("insert_sorted: %p\n", (void*)p);

	newp->next = p->next;
	p->next = newp;
}
