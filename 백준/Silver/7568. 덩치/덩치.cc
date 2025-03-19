#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

// compare는 인수로 줄 두 요소가 리스트의 왼쪽 / 오른쪽에 속해야 하는지 판단함.
// compare이 true면 a가 b보다 앞이어야 한다는 뜻이다.
// 오름차순으로 정렬할 때, compare 안에 a < b를 담는다.
// 이때 compare이 true면, 즉 a < b 이면 a가 b보다 앞이어야 한다는 뜻이다.
// 내림차순은 반대로 하면 된다.
// 이 예시에서는 두 pair 의 두 필드가 모두 크면
bool compare(tuple<int,int,int,int> a, tuple<int,int,int,int> b) {
    if(get<0>(a) == get<0>(b)) {
        return (get<1>(a) > get<1>(b));
    } else if (get<1>(a) == get<1>(b)) {
        return get<0>(a) > get<0>(b);
    }
    return (get<0>(a) > get<0>(b)) && (get<1>(a) > get<1>(b));
}

bool compare2(tuple<int,int,int,int> a, tuple<int,int,int,int> b) {
    return (get<2>(a) < get<2>(b));
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int,int>> arr(N);
    for(int i=0;i<N;i++) {
        int weight;
        int height;
        cin >> weight >> height;

        arr[i] = {weight,height};
    }

    int rank = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(get<0>(arr[i]) < get<0>(arr[j]) && get<1>(arr[i]) < get<1>(arr[j])) {
                rank++;
            }
        }
        cout << rank + 1 << "\n";
        rank = 0;
    }

    return 0;
}
