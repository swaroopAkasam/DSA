/*
92. Reverse Linked List II
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        for(int i=1; i<left; i++) {
            prev = prev->next;
        }
        ListNode* curr = prev->next;
        ListNode* next = NULL;
        for(int i=0; i<right-left; i++) {
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        return dummy->next;
    }
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
    while(head) {
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> v1 = {1,2,3,4,5}; 
    ListNode* l1 = createList(v1);
    printList(l1);
    Solution sol;
    ListNode* ans = sol.reverseBetween(l1, 2, 4);
    printList(ans);
    return 0;
}