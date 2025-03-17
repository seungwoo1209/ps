#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 666 + 0
    // 6660 or 0666 + ?
    // 66600 06660 00666 + ?
    set<long long> numbers;

    string a_str = "666";

    for (int i = 0; i < 100000; i++) {
        string str = std::to_string(i);

        string part1;
        string part2;
        for (int j = 0; j < str.length(); j++) {
            part1 = str.substr(0, j);
            part2 = j + 1 == str.length() ? "" : str.substr(j + 1, str.length());
            string new_string = part1 + a_str + part2;
            numbers.insert(stoi(new_string));
        }
    }

    // cout << numbers.size();
    vector<long long> arr(numbers.begin(), numbers.end());

    sort(arr.begin(), arr.end());

    int N;
    cin >> N;

    cout << arr[N-1];

    // 6660 or 0666
    // 6661 or 1666
    // ...
    // 6669 or 9666
    // 10 * 2
    // 10666 or 16660 or 66610
    // ...
    // 99666 or 96669 or 66699
    // 90 * 3
    // 100666 or 106660 or 166600 or 666100
    // ...
    // 999666 or 996669 or 966699 or 666999
    // 900 * 4
    // 9000 * 5


    return 0;
}
