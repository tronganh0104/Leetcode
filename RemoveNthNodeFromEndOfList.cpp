#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    int countSize = 0;
    ListNode *temp = head;
    while (temp != NULL) {
        countSize++;
        temp = temp->next;
    }
    if (n == countSize) {
        return head->next;
    } else if (n == 1) {
        temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        temp->next = NULL;
        return head;
    } else {
        temp = head;
        int x = countSize - n - 1;
        for (int i = 0; i < x; i++) {
            temp = temp->next;
        }   
        temp->next = temp->next->next;
        return head;
    }
}

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
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
    
    head = removeNthFromEnd(head, m);
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}