#include <iostream>
#include <stack>
using namespace std;

stack<char> st;
//int main() {
//    bool ok1 = true, ok2 = true;  string s; cin >> s;
//    for (int i = 0; i < s.size(); i++) {
//        if (s[i] == '@') break;
//        if (s[i] == ')' && (st.empty() || st.top() == ')')) {
//            cout << "NO";
//            ok1 = false;
//            ok2 = false;
//            break;
//        };
//
//        if (s[i] == ')' && st.top() == '(') st.pop();
//        if (s[i] == '(') st.push(s[i]);
//    }
//    if (ok1 && !st.empty()) { 
//        cout << "NO";
//        ok2 = false;
//    }
//    if (ok2) cout << "YES";
//    system("pause");
//    return 0;
//}