#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, M;
vector<int> vec;

int main(void)
{
    cin >> N >> M;

    for(int i=0;i<N;i++) {
        int val;
        cin >> val;
        vec.push_back(val);
    }

    int diff = INT_MAX;

    for(int i=0;i<=N-3;i++) {
        for(int j=i+1;j<=N-2;j++) {
            for(int k=j+1;k<=N-1;k++) {
                int new_diff = M - vec[i] - vec[j] - vec[k];
                if(diff > new_diff && new_diff >= 0) {
                    diff = new_diff;
                }
            }
        }
    }

    cout << M - diff;
    return 0;
}