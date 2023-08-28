#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printNode(ListNode *head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
}

ListNode* reverseList(ListNode* head) {
    if (head == NULL) return NULL;
    stack <int> st;
    while (head != NULL) {
        st.push(head->val);
        head = head->next;
    }
    ListNode *newNode = new ListNode(st.top());
    ListNode *temp = newNode;
    st.pop();
    while (!st.empty()) {
        ListNode *tmp = new ListNode(st.top());
        st.pop();
        temp->next = tmp;
        temp = temp->next;
    }
    return newNode;
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
        ListNode *tmp = new ListNode(x);
        temp->next = tmp;
        temp = temp->next;
    }
    printNode(reverseList(head));
    return 0;
}