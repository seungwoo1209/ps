#include <iostream>
#include <vector>
#include <climits>

using namespace std;

string N;

int main(void) {

    while(true) {
        cin >> N;
        if(N == "0") {
            break;
        }
        int center = (N.size() - 1) / 2;

        bool flag = true;
        for(int i=center;i>=0;i--) {
            if(N[i] != N[N.size() - 1 - i]) {
                flag = false;
                break;
            }
        }

        string ans = flag ? "yes" : "no";
        cout << ans << "\n";
    }



    return 0;
}
