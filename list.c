#include "list.h"

static list_item **find_indirect (list *l, list_item *target){
    list_item **pp = &(l->head);
    while(*pp != target){
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
    list_item **pp = &(l->head);
    while(*pp != target){
        pp = &(*pp)->next;
    }
    *pp = target->next;
}

void review_list (list *l){
    list_item **pp = &(l->head);
    while (*pp){
        printf("%d\n", (*pp)->val);
        pp = &((*pp)->next);
    }
    printf("\n");
}

void insert_after (list *l, list_item *item){
    list_item **pp = find_last(l);
    (*pp) = item;
}

void insert_before (list *l, list_item *before, list_item *item){
    list_item **pp = find_indirect(l, before);
    (*pp) = item;
    item->next = before;
}