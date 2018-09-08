#pragma once


struct node_t
{
	int data;
	struct node_t* next;
};


struct node_t *list_create_node(int value);
int            list_append(struct node_t *list, struct node_t *node);
void           list_insert_sorted(struct node_t *list, struct node_t *node);
struct node_t *list_remove(struct node_t *list, int value);
struct node_t *list_find(struct node_t *list, int value);
void           list_clear(struct node_t *list);
void           list_print(struct node_t const *list);
