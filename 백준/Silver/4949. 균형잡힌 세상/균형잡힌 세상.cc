#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <stack>

using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2) {
    if(p1.second == p2.second) {
        return p1.first < p2.first;
    } else {
        return p1.second < p2.second;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true) {
        string s;
        getline(cin, s);
        stack<int> st;

        if(s.length() == 1 && s[0] == '.') {
            break;
        }


        bool is_invalid = false;
        for(int i=0;i<s.length(); i++) {
            if(s[i] == '(') {
                st.push(1);
            }
            if(s[i] == '[') {
                st.push(2);
            }
            if(s[i] == ')') {
                if(!st.empty() && st.top() == 1) {
                    st.pop();
                } else {
                    is_invalid = true;
                    break;
                }
            }
            if(s[i] == ']') {
                if(!st.empty() && st.top() == 2) {
                    st.pop();
                } else {
                    is_invalid = true;
                    break;
                }
            }
        }

        string ans = st.empty() && !is_invalid ? "yes" : "no";
        cout << ans << '\n';
    }
    return 0;
}
