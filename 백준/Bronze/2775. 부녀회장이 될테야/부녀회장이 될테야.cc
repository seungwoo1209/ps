#include <iostream>
#include <vector>

using namespace std;

// 0층 : 1 2 3 4 5 ...
// 1층 : 1 1+2 1+2+3 1+2+3+4 ....
// 2층 : 1 / 2 1 / 3 2 1 / 4 3 2 1 /
// 1 / 3 1 / 6 3 1 /

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    vector<vector<long long>> arr(15,vector<long long>(15));
    for(int i=0;i<15;i++) {
        arr[0][i] = i;
    }
    for(int i=0;i<15;i++) {
        arr[i][1] = 1;
    }

    for(int i=1; i<15;i++) {
        for(int j=2;j<15;j++) {
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }


    for(int i=0;i<T;i++) {
        int k,n;
        cin >> k >> n;
        cout << arr[k][n] << '\n';
    }

    return 0;
}
