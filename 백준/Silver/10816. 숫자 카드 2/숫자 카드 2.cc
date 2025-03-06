#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

vector<int> arr;
vector<pair<int,int>> arr2;


int my_binary_search(int value, int start, int end) {
    if(start >  end) {
        return 0;
    }

    int mid = start + (end - start + 1) / 2;

    if (arr2[mid].first == value) {
        return arr2[mid].second;
    } else if (arr2[mid].first < value) {
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
    arr2 = vector<pair<int,int>>();

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cin >> M;
    vector<int> exists(M);
    for (int i = 0; i < M; i++) {
        cin >> exists[i];
    }

    sort(arr.begin(), arr.end());
    int t = 0;
    for(int i=0;i<N;i++) {
        if(arr[i] != arr[t]) {
            arr2.push_back(make_pair(arr[t],i-t));
            t = i;
        }
        if(i == N-1) {
           arr2.push_back(make_pair(arr[i],N - t));
        }
    }

    for (int i = 0; i < M; i++) {
        cout <<  my_binary_search(exists[i], 0, arr2.size()-1) << " ";
    }

    return 0;
}

