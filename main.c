#include "list.h"
#include "algo.h"
#define N 10

list_item items[N];
list l_head1, l_head2;

void init_list_node (void){
    for (size_t i = 0; i < N; i++){
        items[i].val = i;
        items[i].next = NULL;
    }
    l_head1.head = NULL;
    l_head2.head = NULL;
}

int main(){
    init_list_node();
    for (size_t i = 0; i < N / 2; i++){
        insert_after(&l_head1, &items[i]);
    }
    for (size_t i = N / 2; i < N; i++){
        insert_after(&l_head2, &items[i]);
    }

    list_item   a3 = {.val = 4, .next = NULL},
                a2 = {.val = 2, .next = &a3},
                a1 = {.val = 0, .next = &a2},

                b3 = {.val = 5, .next = NULL},
                b2 = {.val = 3, .next = &b3},
                b1 = {.val = 1, .next = &b2};
                
    l_head1.head = &a1;
    l_head2.head = &b1;

    review_list(&l_head1);
    review_list(&l_head2);
    list *new_head = mergeTwoLists(l_head1.head, l_head2.head);
    review_list(new_head);
}
