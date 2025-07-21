#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    stack<int> sortStack(stack<int> st) {
        stack<int> temp;
        while(!st.empty()) {
            int num = st.top();
            st.pop();
            while(!temp.empty() && temp.top() < num) {
                st.push(temp.top());
                temp.pop();
            }
            temp.push(num);
        }
        return temp;
    }
};

void prepStack(const vector<int>& v, stack<int>& st) {
    for(int ele : v) {
        st.push(ele);
    }
}

void printStack(stack<int> st) {
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    vector<int> v1 = {5, 3, 4, 2, 1};
    stack<int> st;
    prepStack(v1, st);

    Solution sol;
    stack<int> sorted = sol.sortStack(st);

    printStack(sorted);
    return 0;
}
