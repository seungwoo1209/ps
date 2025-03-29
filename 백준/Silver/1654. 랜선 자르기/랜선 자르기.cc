#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <limits.h>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, N;

    cin >> K >> N;

    vector<int> arr;
    for(int i=0;i<K;i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(),arr.end(), std::greater<int>());
    long long sum = 0;
    for(int i : arr) {
        sum += i;
    }
    int low = 0;
    int high = sum / N;
    int curr_length;
    while(true) {
        if(low == high) {
            break;
        }
        curr_length = low + (ceil)((double)(high - low) / 2);
        long long curr_utps = 0;
        for(int i : arr) {
            curr_utps += i / curr_length;
        }
        if(curr_utps < N) {
            // 너무 적게 만들어짐
            high = curr_length - 1;
        } else {
            //적절하거나, 너무 많이 만들어짐
            low = curr_length;
        }
    }

    cout << low << '\n';

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


