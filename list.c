#include "list.h"

static list_item **find_indirect (list *l, list_item *target){
    list_item **pp = &(l->head);
    while(*pp /*!= target*/){
        pp = &(*pp)->next;
    }
    return pp;
}

static list_item **find_last (list *l){
    list_item **pp = &(l->head);
    while (*pp){
        pp = &(*pp)->next;
    }
    return pp;
}
void remove_node (list *l, list_item *target){
    list **pp = &l->head;
}
void review_list (list *l){
    list_item **pp = &(l->head);
    while (*pp){
        printf("%d\n", (*pp)->val);
        pp = &((*pp)->next);
    }
    
}
void insert_after (list *l, list_item *item){
    // printf("FSF\n");
    list_item **pp = find_last(l);
    // (*pp)->next = item;
    (*pp) = item;
}
