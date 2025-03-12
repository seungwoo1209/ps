#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    if(N == 1) {
        cout << 1 << endl;
        return 0;
    }

    int i=1;
    int tmp = 6;
    int lim = 1;
    while(true) {
        i++;
        lim += tmp;
        tmp += 6;
        if(lim >= N) {
            break;
        }
    }
    cout << i << "\n";
    // 1
    // 2 3 4 5 6 7
    // 8 ~ 19
    // 한변의 길이가 0 -> 1
    // 한변의 길이가 1 -> 2 ~ 7
    // 한변의 길이가 2 -> 8 ~ 19
    // 한변의 길이가 3 -> 20 ~ 37 (3*6)


    return 0;
}
