#include "../c-utils/std.h"
#include "../c-utils/utils.h"


struct node_t
{
	int data;
	struct node_t *next;
};


struct node_t *list_create(int data)
{
	struct node_t *node = malloc(sizeof(struct node_t));
	node->data = data;
	node->next = NULL;

	return node;
}


void list_destroy(struct node_t *list)
{
	struct node_t *p;
	while(list) {
		p = list->next;
		debug("free: node=%02d (%p)\n", list->data, (void*)list);
		free(list);
		list = p;
		/* usleep(1000 * 200); */
	}
}


/* Floyd's cycle detection ("the tortoise and the hare”) */
struct node_t *list_detect_cycle(struct node_t *list)
{
	struct node_t *p0 = list;
	struct node_t *p1 = list;

	while(p1) {
		if(!p1->next) break;
		p0 = p0->next;
		p1 = p1->next->next;

		if(p0 == p1) {
			puts("Cycle detected");
			return p1;
		}
	}

	return NULL;
}

void list_remove_cycle(struct node_t *list, struct node_t *detected)
{
	struct node_t *p = list;
	if(!detected) {
		detected = list_detect_cycle(list);
	}

	if(!detected) return;

	/* is a cyclic list? (tail -> head?)*/
	if(detected == list) {
		debug("This is a cyclic list. p=%p\n", (void*)detected);
		while(p->next != list) {
			p = p->next;
		}
		debug("Breaking the cycle at node=%d (p=%p)\n", p->data, (void*)p);
		p->next = NULL;
		return;
	}

	/* cycle detected further from head */
	while(detected != p) {
		p = p->next;
		if(detected->next == p) {
			break;
		}
		detected = detected->next;
	}

	debug("Breaking the cycle at node=%d (p=%p)\n", detected->data, (void*)p);
	detected->next = NULL;
}


int main()
{
	struct node_t *list = list_create(0);

	struct node_t *p = list;
	int i;
	for(i = 1; i < 10; i++) {
		struct node_t *node = list_create(i);
		p->next = node;
		p = node;
	}

	struct node_t *node = list_create(i);
	p->next = node;

	puts("Creating a cycle: tail->head");
	node->next = list; /* cyclic list */

	if((p = list_detect_cycle(list)) != NULL) {
		list_remove_cycle(list, p);
	}

	puts("Creating a cycle within the list");
	node->next = list->next->next; /* cycle within */
	list_remove_cycle(list, NULL);
	
	list_destroy(list);
	return 0;
}

