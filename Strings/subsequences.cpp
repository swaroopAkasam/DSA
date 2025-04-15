// g++ -o Strings/subsequences Strings/subsequences.cpp
// ./Strings/subsequences

#include <bits/stdc++.h>
using namespace std;

void printSubSeq(string s, string out, int index) {
    if(index == s.size()) {
        cout << out << endl;
        return;
    }
    printSubSeq(s, out+s[index], index+1);
    printSubSeq(s, out, index+1);
}

// Driver code
int main() {
    string s = "abc";
    string out = "";
    printSubSeq(s, out, 0);
    return 0;
}