#include "list.h"

#define N 10

list_item items[N];
list l_head;

void init_list_node (void){
    for (size_t i = 0; i < N; i++){
        items[i].val = i;
        items[i].next = NULL;
    }
    l_head.head = NULL;
    // return &l_head;
}

int main(){
    init_list_node();
    for (size_t i = 0; i < N; i++){
        insert_after(&l_head, &items[i]);
    }
    review_list(&l_head);
    remove_node(&l_head, l_head.head);
    review_list(&l_head);
    remove_node(&l_head, &items[5]);
    review_list(&l_head);
    insert_before(&l_head, &items[7], &items[5]);
    review_list(&l_head);
    remove_middle(&l_head);
    review_list(&l_head);
}