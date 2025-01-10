#include "list.h"

#define N 100

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
}