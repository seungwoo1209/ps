#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

vector<int> arr;


bool my_binary_search(int value, int start, int end) {
    if(start >  end) {
        return false;
    }

    int mid = start + (end - start + 1) / 2;

    if (arr[mid] == value) {
        return true;
    } else if (arr[mid] < value) {
        return my_binary_search(value, mid + 1, end);
    } else {
        return my_binary_search(value, start, mid - 1);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N;
    arr = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cin >> M;
    vector<int> exists(M);
    for (int i = 0; i < M; i++) {
        cin >> exists[i];
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < M; i++) {
        cout <<  my_binary_search(exists[i], 0, N - 1) << "\n";
    }

    return 0;
}
