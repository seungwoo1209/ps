#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &a, const string &b) {
    if(a.size() != b.size()) {
        return a.size() < b.size();
    } else {
        return a < b;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    vector<string> arr(N);

    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }

    sort(arr.begin(),arr.end(), compare);

    auto last = unique(arr.begin(), arr.end());
    arr.erase(last,arr.end());
    for(int i=0;i<arr.size();i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}
