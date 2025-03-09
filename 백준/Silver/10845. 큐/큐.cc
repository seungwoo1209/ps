#include <iostream>
#include <vector>
#include <map>
#include <variant>
#include <functional> // std::function을 위해 필요
#include <string>

using namespace std;

class my_queue {
public:
    my_queue() {
        arr = new int[initial_capacity];
        current_capacity = initial_capacity;
        start = 1;
        rear = 0;
    }

    // 배열이 가득 찼으면 새 공간을 할당
    void push(int t) {
        if (is_full_queue()) {
            resize();
            push(t);
        } else {
            rear = (rear + 1) % current_capacity ;
            arr[rear % current_capacity] = t;
        }
    }

    int pop() {
        if(empty()) {
            return -1;
        } else {
            int result = arr[start];
            arr[start] = 0;
            start = (start + 1) % current_capacity;

            return result;
        }
    }

    int size() {
        if(empty()) {
            return 0;
        } else {
            return (rear - start + 1) < 0 ? (rear - start + 1) + current_capacity : (rear - start + 1);   
        }
    }

    bool empty() {
        return start == (rear + 1) % current_capacity;
    }

    int front() {
        if(empty()) {
            return -1;
        } else {
            return arr[start];
        }
    }

    int back() {
        if(empty()) {
            return -1;
        } else {
            return arr[rear];
        }
    }

    void print() {
        for(int i=0;i<current_capacity;i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

private:
    const int initial_capacity = 2;
    int current_capacity;
    int *arr;
    int start;
    int rear;

    bool is_full_queue() {
        return (start + (current_capacity - 1) - 1) % (current_capacity) == rear;
    }

    void resize() {
        int *newarr = new int[current_capacity * 2];

        int i = start; int j=1;
        while(true) {
            newarr[j] = arr[i % current_capacity];
            if(i % (current_capacity) == rear) {
                break;
            }
            i++; j++;
        }
        start = 1;
        rear = j;
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

    my_queue my_queue;

    // std::function<void()>: 매개변수 없이 void를 반환하는 함수 타입
    map<string, function<ReturnType()>> mapper;

    mapper["push"] = [&my_queue]() -> ReturnType{
        int val;
        cin >> val;
        my_queue.push(val);
        return std::monostate{};
    };

    mapper["pop"] = [&my_queue]() -> ReturnType{
        return my_queue.pop();
    };

    mapper["size"] = [&my_queue]() {
        return my_queue.size();
    };

    mapper["empty"] = [&my_queue]() {
        return my_queue.empty();
    };

    mapper["front"] = [&my_queue]() {
        return my_queue.front();
    };

    mapper["back"] = [&my_queue]() {
        return my_queue.back();
    };

    int N; cin >> N;


    for(int i=0;i<N;i++) {
        string command;
        cin >> command;
        if(mapper.find(command) != mapper.end()) {
            ReturnType result = mapper[command]();
            // my_queue.print();
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


// 15
// push 1
// push 2
// front
// back
// size
// empty
// pop
// pop
// pop
// size
// empty
// pop
// push 3
// empty
// front

// 4
// push 1
// front
// back
// size

// push pop size empty front back