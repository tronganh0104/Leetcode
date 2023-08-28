#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<ListNode*> splitListToParts(ListNode* head, int k) {
    vector<ListNode*> output;

    int n = 0;
    ListNode* temp = head;
    while (temp != NULL) {
        n++;
        temp = temp->next;
    }

    int divide = n / k;
    int r = n % k;
    temp = head;

    for (int i = 0; i < k; i++) {
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;
        
        int partSize = divide + (r-- > 0 ? 1 : 0);
        
        for (int j = 0; j < partSize; j++) {
            if (temp) {
                current->next = new ListNode(temp->val);
                current = current->next;
                temp = temp->next;
            }
        }
        
        output.push_back(dummy->next);
        delete dummy;
    }

    return output;
}


int main () {
    return 0;
}