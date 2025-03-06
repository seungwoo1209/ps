#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

vector<pair<long long,long long>> arr;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return (p1.first == p2.first) ? p1.second < p2.second : p1.first < p2.first;
}

void quick_sort(int start, int end) {

    if(start == end) {
        return;
    }
    int pivot = start;
    swap(arr[start + rand() % (end - start)], arr[start]);

    int low = start+1;
    int high = end;

    while(true) {
        while(compare(arr[low], arr[pivot]) && low <= end) {
            low++;
        }

        while(compare(arr[pivot], arr[high]) && high >= start+1) {
            high--;
        }

        if(low < high) {
            swap(arr[low], arr[high]);
        } else {
            break;
        }
    }

    swap(arr[pivot], arr[low-1]);
    if(low-2 >= start) {
        quick_sort(start,low-2);
    }
    if(low <= end) {
        quick_sort(low,end);
    }



}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    int N;
    cin >> N;

    for(int i=0;i<N;i++) {
        int x;
        int y;
        cin >> x >> y;
        arr.push_back(make_pair(x,y));
    }
    quick_sort(0,N-1);

    for(auto i: arr) {
        cout << i.first << " " << i.second << '\n';
    }

    return 0;
}
