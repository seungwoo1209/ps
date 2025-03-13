#include <iostream>

using namespace std;

const long long divider = 1234567891;
const long long hash = 31;

// 31의 i제곱을 1234567891 로 나눴을 때
long long get_remain(int i) {
    if (i == 0) {
        return 1;
    }
    if(i == 1) {
        return 31;
    }
    return get_remain(i/2)*get_remain(i - (i/2)) % divider;
}

// (a * b) % r
// a%r * b%r
// 1. r * x + r1 = a*b
// 2. r * y + r2 = a
// 3. r * z + r3 = b
// (r*y + r2)(r * z + r3) = r * x + r1
// r^2yz + ryr3 + rzr2 + r2r3 = r * x + r1
// r(ryz + yr3 + zr2) + r2r3 = r * x + r1
// r2r3 % r = r1
// => (a%r * b%r) % r = r1 % r = (a * b) % r
// => (a%r * b%r) % r = (a * b) % r

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int L;
    cin >> L;


    string s;
    cin >> s;

    long long sum = 0;
    for (int i = 0; i < L; i++) {
        int n = (int) s[i] - 96;
        sum += n * get_remain(i);
        sum = sum % divider;
    }

    sum = sum % divider;

    cout << sum << endl;

    return 0;
}
