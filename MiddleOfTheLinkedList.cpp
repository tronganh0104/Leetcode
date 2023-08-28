#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
    int count = 0;
    ListNode *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    } 
    count = count / 2;
    for (int i = 0; i < count; i++) {
        head = head->next;
    }
    return head;
}

int main() {
    int n;
    cin >> n;
    int x;
    cin >> x;
    ListNode *head = new ListNode(x);
    ListNode *temp = head;
    for (int i = 1; i < n; i++) {
        cin >> x;
        ListNode *nodeAdd = new ListNode(x);
        temp->next = nodeAdd;
        temp = nodeAdd;
    }
    head = middleNode(head);
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}