#ifndef LIST_H
#define LIST_H
#include "test.h"
struct list_item{
	int val;
	struct list_item *next;
};
typedef struct list_item list_item;

struct list{
	list_item *head;
};
typedef struct list list;

void remove_middle (list *l);
void review_list (list *l);
void insert_before (list *l, list_item *before, list_item *item);
void insert_after (list *l, list_item *item);
void remove_node (list *l, list_item *target);

#endif 
