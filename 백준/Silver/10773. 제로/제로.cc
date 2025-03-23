#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin >> K;

    stack<int> s;
    for(int i=0;i<K;i++) {
        int num;
        cin >> num;

        if(num == 0) {
            s.pop();
        } else {
            s.push(num);
        }
    }

    uint32_t sum = 0;
    while(!s.empty()) {
        sum += s.top();
        s.pop();
    }

    cout << sum << '\n';

    return 0;
}
