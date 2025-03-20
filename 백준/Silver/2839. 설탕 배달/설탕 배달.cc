#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

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

    int N;
    cin >> N;
    int min = INT_MAX;
    for(int i=0;i<=N;i = i + 5) {
        if((N - i) % 3 == 0) {
            int new_min = i/5 + (N-i) / 3;
            if(min > new_min) {
                min = new_min;
            }
        }
    }
    min = (min == INT_MAX) ? -1 : min;
    cout << min;
    return 0;
}
