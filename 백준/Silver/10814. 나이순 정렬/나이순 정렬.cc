#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

vector<pair<int,string>> arr;

void quick_sort(int start, int end) {

    if(start == end) {
        return;
    }
    int pivot = start;
    swap(arr[start + rand() % (end - start)], arr[start]);

    int low = start+1;
    int high = end;

    while(true) {
        while(arr[low].first < arr[pivot].first && low <= end) {
            low++;
        }

        while(arr[high].first > arr[pivot].first && high >= start+1) {
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
    int copy = N;
    int digits = 0;
    while(copy != 0) {
        copy = copy / 10;
        digits++;
    }
    int criteria = 1;
    while(digits > 0) {
        criteria = criteria * 10;
        digits--;
    }

    for(int i=0;i<N;i++) {
        int age;
        string name;
        cin >> age >> name;
        arr.push_back(make_pair(age * criteria + i,name));
    }

    quick_sort(0,N-1);

    for(auto i: arr) {
        cout << i.first / criteria << " " << i.second << '\n';
    }

    return 0;
}
