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

int checkIfNextNull(ListNode* l1) {
    return (l1->next == NULL) ? 1 : 0;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* templ1 = l1;
    ListNode* templ2 = l2;
    ListNode* result = NULL;

    int carry = 0;
    while (templ1 != NULL) {
        int sum = templ1->val + templ2->val;

        if(sum < 10) {
            result = addNode(result, sum + carry);
            carry = 0;
        } else {
            if (checkIfNextNull(templ1) == 1) {
                result = addNode(result, sum - 10 + carry);
                result = addNode(result, 1);
            } else {
                result = addNode(result, sum - 10 + carry);
                carry = 1;
            }
        }

        templ1 = (ListNode *) templ1->next;
        templ2 = (ListNode *) templ2->next;
    }
/*
    while (templ2 != NULL){
        result = addNode(result, templ2->val);
        templ2 = (ListNode *) templ2->next;
    }
*/

    return result;
}

int main() {
    ListNode * l1 = NULL;
    l1 = addNode(l1, 9);
    l1 = addNode(l1, 9);
    l1 = addNode(l1, 9);

    ListNode * l2 = NULL;
    l2 = addNode(l2, 9);
    l2 = addNode(l2, 9);
    l2 = addNode(l2, 9);

    ListNode* result = addTwoNumbers(l1, l2);

    readInReverse(l1);
    readInReverse(l2);
    readInReverse(result);

    freeList(l1);
    freeList(l2);
    freeList(result);

}
