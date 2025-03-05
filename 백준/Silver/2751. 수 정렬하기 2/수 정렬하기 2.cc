#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> arr(N);

    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }

    sort(arr.begin(),arr.end());

    for(int i: arr) {
        cout << i << '\n';
    }

    return 0;
}
