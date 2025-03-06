#include <iostream>
using namespace std;

int factorial(int num) {
    if(num == 0 || num == 1) {
        return 1;
    } else {
        return num*factorial(num-1);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; int K;
    cin >> N >> K;

    cout << factorial(N) / (factorial(K) * factorial(N-K));

    return 0;
}
