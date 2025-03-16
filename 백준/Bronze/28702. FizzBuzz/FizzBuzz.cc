#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void print_fizzbuzz(long long num) {
    if (num % 3 == 0 && num % 5 == 0) {
        cout << "FizzBuzz";
    } else if (num % 3 == 0) {
        cout << "Fizz";
    } else if (num % 5 == 0) {
        cout << "Buzz";
    } else {
        cout << num;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string first, second, third;
    cin >> first >> second >> third;

    if (first == "FizzBuzz") {
        cout << "Fizz";
        return 0;
    } else if (first == "Fizz") {
        if (second == "Buzz") {
            print_fizzbuzz(std::stoi(third) + 1);
        } else {
            print_fizzbuzz(std::stoi(second) + 2);
        }
    } else if (first == "Buzz") {
        if (second == "Fizz") {
            print_fizzbuzz(std::stoi(third) + 1);
        } else {
            print_fizzbuzz(std::stoi(second) + 2);
        }
    } else {
        print_fizzbuzz(std::stoi(first) + 3);
        return 0;
    }


    return 0;
}

// 첫번째꺼가 fizz 또는 fizzbuzz면 답은 fizz
// 첫번째꺼가 buzz나 수라면?

// 첫번째꺼가 buzz면, 답은 buzz를 포함하고 있지 않음.
// 첫번째꺼가 수라면, 모름.

// 두번째 또는 세번째꺼가 가 f / fb / b라면, 답은 수임.
