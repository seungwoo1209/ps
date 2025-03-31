#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<string> arr;

void get_cantor(int start, int end) {

    if(end == start) {
        return;
    }

    int length = (end - start + 1) / 3;
    for(int i=start+length; i<=end-length;i++) {
        arr[i] = " ";
    }

        get_cantor(start,start+length-1);
        get_cantor(end-length+1,end);
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    while(cin >> n) {

        int base = 1;
        for(int i=0;i<n;i++) {
            base *= 3;
        }

        arr.assign(base,"-");

        get_cantor(0,base-1);

        for(string s: arr) {
            cout << s;
        }
        cout << '\n' << flush;
    }

    return 0;
}



