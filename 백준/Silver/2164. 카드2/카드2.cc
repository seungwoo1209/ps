#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

vector<int> arr;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    queue<int> queue;
    for(int i=1;i<=N;i++) {
        queue.push(i);
    }

    int shit;
    bool even = false;
    while(!queue.empty()) {
        shit = queue.front();
        queue.pop();
        if(even) {
            queue.push(shit);
        }
        even = !even;
    }
    cout << shit;

    return 0;
}
