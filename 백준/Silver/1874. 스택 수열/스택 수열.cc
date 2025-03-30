#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <limits.h>
#include <stack>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    vector<int> arr;

    for(int i=0;i<N;i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int index = 0;
    vector<string> ans;
    stack<int> st;
    int i = 1;

    // arr[index] : 현재 출력해야 하는 수
    // i : 이제 스택에 들어갈 수
    while(true) {
        if(index >= N) {
            break;
        }

        if(arr[index] > i) {
            while(arr[index] != i) {
                st.push(i);
                ans.push_back("+");
                i++;
            }
        }

        if(arr[index] == i) {
            st.push(i);
            ans.push_back("+");
            st.pop();
            ans.push_back("-");
            i++;
            index++;
            continue;
        }

        if(arr[index] < i) {
            if(st.top() != arr[index]) {
                ans.clear();
                break;
            } else {
                st.pop();
                ans.push_back("-");
                index++;
                continue;
            }
        }
    }

    if(ans.empty()) {
        cout << "NO" << "\n";
    } else {
        for(auto s : ans) {
            cout << s << "\n";
        }
    }

    return 0;
}


// 4 10
// 110
// 10
// 1
// 1

// 4 12
// 3
// 3
// 3
// 3

// 5 5
// 5
// 5
// 5
// 5
// 5


