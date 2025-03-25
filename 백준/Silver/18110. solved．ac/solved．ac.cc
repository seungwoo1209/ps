#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0;i<n;i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    int cut = (int)floor(n * 0.15 + 0.5);

    sort(arr.begin(),arr.end());

    // 인덱스는 0, 1, 2, ...... n-1
    // 예를 들어 5면 0,1,2,3,4 이럼 cut는 1 즉 한명 자르라는건데

    int count = 0;
    int sum = 0;
    for (int i = cut; i < n - cut; i++) {
        count++;
        sum += arr[i];
    }
    int result = (count == 0) ? 0 : floor((double)sum / count + 0.5);
    cout << result;

    return 0;
}
