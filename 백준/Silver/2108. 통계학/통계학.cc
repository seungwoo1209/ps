#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	else {
		return p1.second > p2.second;
	}
}

int main(void) {


	int N;
	cin >> N;

	vector<int> arr;
	for (int i = 0;i < N;i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	// 1. 산술평균
	int sum = 0;
	for (int i = 0;i < N;i++) {
		sum += arr[i];
	}
	double avg = (double)sum / N;

	cout << floor(avg + 0.5) << '\n';

	sort(arr.begin(), arr.end());

	int midindex = (N - 1) / 2;

	cout << arr[midindex] << '\n';

	vector<pair<int, int>> counting;
	
	int how_many = 1;
	for (int i = 0;i < N;i++) {
		if (i == 0) {
			continue;
		}
		if (i >= 1 && arr[i] == arr[i - 1]) {
			how_many++;
		}
		if (i >= 1 && arr[i] != arr[i - 1]) {
			counting.push_back({ arr[i-1],how_many });
			how_many = 1;
		}
	}
	counting.push_back({ arr[N - 1],how_many });

	sort(counting.begin(), counting.end(), comp);


	if (N > 1 && counting[0].second == counting[1].second) {
		cout << counting[1].first << '\n';
	}
	else {
		cout << counting[0].first << '\n';
	}

	cout << arr[N - 1] - arr[0] << '\n';
}