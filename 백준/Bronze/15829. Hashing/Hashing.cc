#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int L;
    cin >> L;

    string s;
    cin >> s;

    int r = 1;
    int sum = 0;
    for(int i=0;i<L;i++) {
        char c = s[i];
        int n = (int)c - 96;
        sum  += n * r;
        r *= 31;
    }

    cout << sum << endl;

    return 0;
}
