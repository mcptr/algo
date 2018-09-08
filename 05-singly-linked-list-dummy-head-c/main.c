#include "../c-utils/std.h"
#include "list.h"


int main()
{
	struct node_t head;
	head.next = NULL;

	for(int i = 2; i <= 10; i += 2) {
		if(list_append(&head, list_create_node(i)) != 0) {
			debug("list_append failed: %d\n", i);
		}
	}
	
	list_print(&head);

	list_insert_sorted(&head, list_create_node(1));
	list_insert_sorted(&head, list_create_node(3));
	list_insert_sorted(&head, list_create_node(5));
	list_insert_sorted(&head, list_create_node(7));
	list_insert_sorted(&head, list_create_node(9));
	list_print(&head);

	list_clear(&head);
	list_print(&head);

	debug("after clear: %p\n", (void*)head.next);
	list_print(&head);

	return 0;
}
