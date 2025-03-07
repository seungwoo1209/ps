#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;

    cin >> N >> K;

    queue<int> queue;
    for(int i=0;i<N;i++) {
        queue.push(i+1);
    }

    cout << "<";
    int tmp = 1;
    while(queue.size() != 1) {
        if(tmp % K == 0) {
            cout << queue.front() << ", ";
            queue.pop();
        } else {
            queue.push(queue.front());
            queue.pop();
        }
        tmp++;
    }
    cout << queue.front() << ">";

    return 0;
}

