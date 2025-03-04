#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int p, q;

int get_gcd(int a, int b) {
    int min = std::min(a,b);
    int i;
    for(i=2;i<=min;i++) {
        if(a % i == 0 && b % i == 0) {
            break;
        }
    }

    if(i == min+1) {
        p = a;
        q = b;
        return 1;
    }
    return i * get_gcd(a/i,b/i);
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    int gcd = get_gcd(N, M);
    int lcm = gcd * p * q;

    cout << gcd << "\n" << lcm;

    return 0;
}
