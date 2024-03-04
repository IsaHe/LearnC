#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int val;
    struct ListNode *next;
}ListNode;

void freeList(ListNode* head) {
    ListNode* temp;

    while (head != NULL) {
        temp = head;
        head = (ListNode *) head->next;
        free(temp);
    }
}

ListNode * addNode(ListNode* head, int val) {
    ListNode * newNode = (ListNode*) malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = (struct ListNode *) head;
    return newNode;
}

void readInReverse(ListNode* l1) {
    ListNode* temp = l1;
    while (temp!=NULL){
        printf("%d ", temp->val);
        temp = (ListNode *) temp->next;
    }
    printf("\n");
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* templ1 = l1;
    ListNode* templ2 = l2;
    ListNode* result = NULL;

    while (l1 != NULL) {
        int sum = templ1->val + templ2->val;

        templ1 = (ListNode *) templ1->next;
    }


    return result;
}

int main() {
    ListNode * l1 = NULL;
    l1 = addNode(l1, 3);
    l1 = addNode(l1, 4);
    l1 = addNode(l1, 2);

    ListNode * l2 = NULL;
    l2 = addNode(l2, 4);
    l2 = addNode(l2, 6);
    l2 = addNode(l2, 5);

    ListNode* result = addTwoNumbers(l1, l2);

    readInReverse(l1);
    readInReverse(l2);
    readInReverse(result);

    freeList(l1);
    freeList(l2);
    freeList(result);

}
