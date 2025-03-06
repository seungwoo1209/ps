#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;

    cin >> N >> M;
    vector<vector<bool>> arr(N, vector<bool>(M));
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            char s;
            cin >> s;
            arr[i][j] = s == 'B';
        }
    }

    vector<vector<bool>> ans1(8,vector<bool>(8));
    bool temp = false;
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            ans1[i][j] = temp;
            temp = !temp;
        }
        temp = !temp;
    }

    vector<vector<bool>> ans2(8,vector<bool>(8));
    temp = true;
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            ans2[i][j] = !ans1[i][j];
        }
    }

    int min = INT_MAX;
    for(int p=0;p<=N-8;p++) {
        for(int q=0;q<=M-8;q++) {
            int count1 = 0;
            int count2 = 0;
            //cout << "p,q: " << p << " " << q << endl;
            for(int i=p;i<p+8;i++) {
                for(int j=q;j<q+8;j++) {
                    if(arr[i][j] != ans1[i-p][j-q]) {
                        count1++;
                    }
                    if(arr[i][j] != ans2[i-p][j-q]) {
                        count2++;
                    }
                }
            }
            //cout << "count: " << count1 << " " << count2 << endl;
            if(min > count1) {
                min = count1;
            }
            if(min > count2) {
                min = count2;
            }
        }
    }

    cout << min;

    return 0;
}
