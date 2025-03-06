#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>

using namespace std;

vector<string> arr;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for(int i=0;i<N;i++) {
        string target;
        cin >> target;
        arr.push_back(target);
    }

    for(int i=0;i<N;i++) {
        stack<int> stack;
        string target = arr[i];
        bool flag = true;
        for(int j=0;j<target.length();j++) {
            if(target[j] == '(') {
                stack.push(1);
            } else {
                if(stack.empty()) {
                    flag = false;
                    break;
                } else {
                    stack.pop();
                }
            }
        }
        if(!flag) {
            cout << "NO" << "\n";
        } else {
            if(stack.empty()) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        }
    }

    return 0;
}
