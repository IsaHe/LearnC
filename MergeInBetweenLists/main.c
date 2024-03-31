#include <stdlib.h>
#include <stdio.h>
#include <string.h>


 // Definition for singly-linked list.
 struct ListNode {
    int val;
    struct ListNode *next;
};

void freeList(struct ListNode* head) {
    struct ListNode* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

struct ListNode * addNode(struct ListNode* head, int val) {
    struct ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    temp->next->val = val;
    temp->next->next = NULL;
    return head;
}

void readLinkedList(struct ListNode* l1) {
    struct ListNode* temp = l1;
    while (temp!=NULL){
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode* temp = list1;

    struct ListNode* startOfMerge;

    struct ListNode* endOfMerge;

    for (int i = 0; temp != NULL; ++i) {
        if (i == a - 1) startOfMerge = temp;
        if (i == b + 1) endOfMerge = temp;
        temp = temp->next;
    }

    startOfMerge->next = list2;
    startOfMerge = startOfMerge->next;

    while (startOfMerge->next != NULL) {
        startOfMerge = startOfMerge->next;
    }
    startOfMerge->next = endOfMerge;

    return list1;
}

int main() {

    struct ListNode* list1 = (struct ListNode*) malloc(sizeof(struct ListNode));
    list1->val = 10;
    list1->next = NULL;
    addNode(list1, 1);
    addNode(list1, 13);
    addNode(list1, 6);
    addNode(list1, 9);
    addNode(list1, 5);
    readLinkedList(list1);

    struct ListNode* list2 = (struct ListNode*) malloc(sizeof(struct ListNode));
    list2->val = 1000000;
    list2->next = NULL;
    addNode(list2, 1000001);
    addNode(list2, 1000002);
    readLinkedList(list2);

    struct ListNode* result = mergeInBetween(list1, 3, 4, list2);
    readLinkedList(result);

    freeList(list1);
    freeList(list2);
    freeList(result);

    return 0;
}