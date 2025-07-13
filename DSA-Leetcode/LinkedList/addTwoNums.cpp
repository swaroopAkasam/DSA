#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* createList(vector<int>& nums) {
    ListNode* dummy = new ListNode();
    ListNode* curr = dummy;
    for(int num : nums) {
        curr->next = new ListNode(num);
        curr = curr->next;
    }
    return dummy->next;
}

void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* dummy = new ListNode();
       ListNode* curr = dummy;
       int temp = 0;
       int sum = 0;
       while(l1 && l2) {
            sum = l1->val + l2->val + temp;
            curr->next = new ListNode(sum%10);
            temp = sum/10;
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
       }
       while(l1) {
            sum = l1->val + temp;
            curr->next = new ListNode(sum%10);
            temp = sum/10;
            curr = curr->next;
            l1 = l1->next;
       }
       while(l2) {
            sum = l2->val + temp;
            curr->next = new ListNode(sum%10);
            temp = sum/10;
            curr = curr->next;
            l2 = l2->next;
       }
       if(temp) {
            curr->next = new ListNode(temp);
       }
       return dummy->next;
    }
    ListNode* addTwoNumbersStructuredFunction(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry) {
            int sum = 0;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;
            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }

        return dummy->next;
    }
};

int main() {
    vector<int> v1 = {9,9,9,9,9,9,9}; 
    vector<int> v2 = {9,9,9,9};
    ListNode* l1 = createList(v1);
    ListNode* l2 = createList(v2);
    Solution sol;
    ListNode* ans = sol.addTwoNumbers(l1, l2);
    printList(ans); 
    ans = sol.addTwoNumbersStructuredFunction(l1, l2);
    printList(ans);
    return 0;
}