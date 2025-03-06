#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> vec;

int main(void){

    while(true){
        for(int i=0;i<3;i++){
            int val;
            cin >> val;
            vec.push_back(val);
        }

        if(vec[0] == 0 && vec[1] == 0 && vec[2] == 0){
            break;
        }

        sort(vec.begin(), vec.end());

        if(vec[0]*vec[0] + vec[1]*vec[1] == vec[2]*vec[2]){
            cout << "right" << "\n";
        } else {
            cout << "wrong" << "\n";
        }

        vec.clear();
    }
    return 0;
}