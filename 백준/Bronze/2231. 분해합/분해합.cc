#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int result = 0;
    int temp;
    for(int i=1;i<N;i++) {
        temp = 0;
        temp += i;

        // i의 각 자릿수 더하기
        string str = std::to_string(i);
        for(int i=0;i<str.length();i++) {
            temp += (str[i] - '0');
        }

        if(temp == N) {
            result = i;
            break;
        }
    }

    cout << result;

    return 0;
}
