#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> arr;

string get_prize_chair(const pair<int, int> & p1, const pair<int, int> & p2) {

    int sum = 0;
    for(int i=p1.first; i<=p2.first;i++) {
        for(int j=p1.second; j<=p2.second;j++) {
            sum += arr[j][i];
        }
    }
    if(sum == (p2.first - p1.first + 1) * (p2.second - p1.second + 1)) {
        return "1";
    } else if (sum == 0) {
        return "0";
    }

    string ans = "(";

    double x_center = p1.first + (double)(p2.first - p1.first) / 2;
    double y_center = p1.second + (double)(p2.second - p1.second) / 2;

    ans += get_prize_chair({p1.first,p1.second},{floor(x_center),floor(y_center)});
    ans += get_prize_chair({ceil(x_center),p1.second},{p2.first,floor(y_center)});
    ans += get_prize_chair({p1.first,ceil(y_center)},{floor(x_center),p2.second});
    ans += get_prize_chair({ceil(x_center),ceil(y_center)},{p2.first,p2.second});

    return ans + ")";

}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    arr = vector<vector<int>>(N, vector<int>(N, 0));
    for(int i=0;i<N;i++) {
        string tmp;
        cin >> tmp;
        for(int j=0;j<N;j++) {
            arr[i][j] = (tmp[j] == '1');
        }
    }

    cout << get_prize_chair({0,0},{N-1,N-1}) << '\n';

    return 0;
}



