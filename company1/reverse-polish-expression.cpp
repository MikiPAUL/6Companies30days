#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isnumber(string s) {
        int start = 0, n = s.size();
        if (s[0] == '-') {
            start++;
            if (n == 1) return false;
        }

        for (int i = start; i < n; i++) {
            if (!isdigit(s[i])) return false;
        }
        return true;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string& s : tokens) {
            if (isnumber(s)) {
                st.push(stoi(s));
            }
            else {
                int second = st.top(); st.pop();
                int first = st.top(); st.pop();
                if (s == "+") st.push(first + second);
                else if (s == "-") st.push(first - second);
                else if (s == "*") st.push(first * second);
                else st.push(first / second);
            }
        }
        return st.top();
    }
};

int main() {
    int n; cin >> n;

    vector<string> exprn(n);

    for (auto& input : exprn) cin >> input;

    Solution solve;
    cout << solve.evalRPN(exprn);

    return 0;
}