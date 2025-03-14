#include <iostream>
#include <math.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, V;
    cin >> A >> B >> V;

    cout << (int)ceil((double)(V - A) / (A - B)) + 1;


    return 0;
}
// 하루에 A-B 만큼 올라감
// 떨어졌을 때 V-A 이상 남아있어야 함.
// 3 1 6
// 3 이상이어야 함
// 1
// 2
// 3