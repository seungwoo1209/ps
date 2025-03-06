#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, T, P;
vector<double> vec(6);

int main(void)
{

    cin >> N;

    for (int i = 0; i < 6; i++)
    {
        cin >> vec[i];
    }

    cin >> T >> P;

    int sum = 0;

    for (int i = 0; i < 6; i++)
    {
        sum += ceil(vec[i] / T);
    }
    cout << sum << "\n";

    cout << N / P << " " << N % P;

    return 0;
}