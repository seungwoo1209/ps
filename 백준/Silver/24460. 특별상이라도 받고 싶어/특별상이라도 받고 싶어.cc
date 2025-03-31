#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> arr;

int get_prize_chair(const pair<int, int> & p1, const pair<int, int> & p2) {

    if(p1.first == p2.first && p1.second == p2.second) {
        return arr[p1.first][p1.second];
    }

    double x_center = p1.first + (double)(p2.first - p1.first) / 2;
    double y_center = p1.second + (double)(p2.second - p1.second) / 2;

    vector<int> chairs;
    chairs.push_back(get_prize_chair({p1.first,p1.second},{floor(x_center),floor(y_center)}));
    chairs.push_back(get_prize_chair({ceil(x_center),p1.second},{p2.first,floor(y_center)}));
    chairs.push_back(get_prize_chair({p1.first,ceil(y_center)},{floor(x_center),p2.second}));
    chairs.push_back(get_prize_chair({ceil(x_center),ceil(y_center)},{p2.first,p2.second}));
    sort(chairs.begin(),chairs.end());

    return chairs[1];

}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    arr = vector<vector<int>>(N, vector<int>(N, 0));
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            int tmp;
            cin >> tmp;
            arr[i][j] = tmp;
        }
    }

    cout << get_prize_chair({0,0},{N-1,N-1}) << '\n';

    return 0;
}
