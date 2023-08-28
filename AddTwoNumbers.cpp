#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == NULL && l2 == NULL) {
        return NULL;
    }
    int num1 = 0;
    int num2 = 0;
    while (l1 != NULL) {
        num1 = num1*10 + l1->val;
        l1 = l1->next;
    }
    while (l2 != NULL) {
        num2 = num2*10 + l2->val;
        l2 = l2->next;
    }
    num1 = num1 + num2;
    ListNode* output = new ListNode(0);
    ListNode* temp = output;
    while (num1 > 0) {
        temp->val = num1 % 10;
        num1 = num1 / 10;
        if (num1 > 0) {
            ListNode* nextNode = new ListNode(0);
            temp->next = nextNode;
            temp = nextNode;
        }
    }
    return output;
}

int main() {
    ListNode* l1 = new ListNode(2);
    ListNode* temp = new ListNode(4);
    l1->next = temp;
    ListNode* cur = new ListNode(9);
    temp->next = cur;
    ListNode* l2 = new ListNode(5);
    ListNode* temp2 = new ListNode(6);
    return 0;
}