#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> vec;

int main(void)
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int val;
        cin >> val;
        vec.push_back(val);
    }

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if(vec[i] == 1){
            continue;
        } else if (vec[i] == 2){
            sum++;
            continue;
        }

        bool flag = false;
        for (int j = 2; j < vec[i]; j++)
        {
            if (vec[i] % j == 0)
            {
                flag = true;
            }
        }
        if (!flag)
        {
            sum++;
        }
    }

    cout << sum;

    return 0;
}