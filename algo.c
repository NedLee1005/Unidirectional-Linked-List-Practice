#include "algo.h"
#include "list.h"
list_item *mergeTwoLists (list_item *L1, list_item *L2){
    list_item *head;
    list_item **pptr = &head, **node;
    for (; L1 && L2; pptr = &(*pptr)->next){
        node = (L1->val < L2->val) ? &L1 : &L2;
        *pptr = *node;
        *node = ((*node)->next);
    }
    *pptr = (list_item*)((uintptr_t)L1 | (uintptr_t)L2);
    return head;
}