#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    unordered_map<int,int> numbers;

    for(int i=0;i<N;i++) {
        int curr_num;
        cin >> curr_num;

        auto it = numbers.find(curr_num);

        if(it != numbers.end() && it->first == curr_num) {
            it->second = it->second + 1;
        } else {
            numbers.insert({curr_num,1});
        }
    }

    std::vector<pair<int,int>> keys;
    keys.reserve(numbers.size());
    for (const auto &kv : numbers) {
        keys.push_back({kv.first,kv.second});
    }

    std::sort(keys.begin(), keys.end());

    for(auto entry : keys) {
        for(int i=0;i<entry.second;i++) {
            cout << entry.first << "\n";
        }
    }

    return 0;
}