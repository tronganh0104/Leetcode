#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printNode(ListNode* list) {
    ListNode* temp = list;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "\n";
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == NULL && list2 == NULL) {
        return NULL;
    }
    int minValue;
    if (list1->val > list2->val) {
        minValue = list2->val;
        list2 = list2->next;
    } else {
        minValue = list1->val;
        list1 = list1->next;
    }
    ListNode *head = new ListNode(minValue);
    ListNode *temp = head;
    while (list1 != NULL || list2 != NULL) {
        if (list1 == NULL) {
            minValue = list2->val;
            list2 = list2->next;
        } else if (list2 == NULL) {
            minValue = list1->val;
            list1 = list1->next;
        } else if (list1->val > list2->val) {
            minValue = list2->val;
            list2 = list2->next;
        } else {
            minValue = list1->val;
            list1 = list1->next;
        }
        ListNode *tmp = new ListNode(minValue);
        temp->next = tmp;
        temp = temp->next;
    }
    return head;
}

int main() {
    int m, n;
    cin >> m >> n;
    int x;
    cin >> x;
    ListNode *list1 = new ListNode(x);
    ListNode *temp = list1;
    for (int i = 1; i < m; i++) {
        cin >> x;
        ListNode* tmp = new ListNode(x);
        temp->next = tmp;
        temp = temp->next;
    }
    cin >> x;
    ListNode *list2 = new ListNode(x);
    temp = list2;
    for (int i = 1; i < n; i++) {
        cin >> x;
        ListNode* tmp = new ListNode(x);
        temp->next = tmp;
        temp = temp->next;
    }
    ListNode *mergeList = mergeTwoLists(list1, list2);
    printNode(mergeList);
    return 0;
}