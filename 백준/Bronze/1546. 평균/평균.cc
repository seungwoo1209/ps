#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    vector<double> arr(N);

    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }

    auto maxit = max_element(arr.begin(),arr.end());
    double max = *maxit;
    for(int i=0;i<N;i++) {
        arr[i] = arr[i]/max*100;
    }

    double avg = 0;
    for(int i=0;i<N;i++) {
        avg += arr[i];
    }

    avg = avg / N;

    cout << avg;

    return 0;
}
