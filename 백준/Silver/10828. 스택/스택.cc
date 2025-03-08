#include <iostream>
#include <vector>
#include <map>
#include <variant>
#include <functional> // std::function을 위해 필요
#include <string>

using namespace std;

class my_stack {
public:
    my_stack() {
        arr = new int[initial_capacity];
        current_capacity = initial_capacity;
        curr = -1;
    }

    void push(int t) {
        if (current_capacity - 1 < curr + 1) {
            resize();
            push(t);
        } else {
            curr++;
            arr[curr] = t;
        }
    }

    int pop() {
        if(curr == -1) {
            return -1;
        } else {
            int result = arr[curr];
            curr--;

            return result;
        }
    }

    int size() {
        return curr + 1;
    }

    bool empty() {
        return curr == -1;
    }

    int top() {
        if(curr == -1) {
            return -1;
        } else {
            return arr[curr];
        }
    }

private:
    const int initial_capacity = 10;
    int current_capacity;
    int *arr;
    int curr;

    void resize() {
        int *newarr = new int[current_capacity * 2];
        for (int i = 0; i < current_capacity; i++) {
            newarr[i] = arr[i];
        }
        delete[] arr;
        arr = newarr;
        current_capacity *= 2;
    }
};

using ReturnType = std::variant<std::monostate,bool, int>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    my_stack myStack;

    // std::function<void()>: 매개변수 없이 void를 반환하는 함수 타입
    map<string, function<ReturnType()>> mapper;

    mapper["push"] = [&myStack]() -> ReturnType{
        int val;
        cin >> val;
        myStack.push(val);
        return std::monostate{};
    };

    mapper["pop"] = [&myStack]() -> ReturnType{
        return myStack.pop();
    };

    mapper["size"] = [&myStack]() {
        return myStack.size();
    };

    mapper["empty"] = [&myStack]() {
        return myStack.empty();
    };

    mapper["top"] = [&myStack]() {
        return myStack.top();
    };

    int N; cin >> N;
    

    for(int i=0;i<N;i++) {
        string command;
        cin >> command;
        if(mapper.find(command) != mapper.end()) {
            ReturnType result = mapper[command]();

            // result(std::variant)에 어떤 타입이 들어 있는지 확인하고, 필요하면 출력
            // monostate가 아니라면 출력해 보도록 예시를 들어 봄
            std::visit([](auto&& arg) {
                using T = decay_t<decltype(arg)>;
                // monostate인 경우 (push 등) 아무것도 안 찍도록
                if constexpr (!is_same_v<T, std::monostate>) {
                    cout << arg << "\n";
                }
                // monostate라면 아무 일도 하지 않음
            }, result);
        }
    }

    return 0;
}
