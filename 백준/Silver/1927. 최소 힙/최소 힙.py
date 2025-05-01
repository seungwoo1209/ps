import sys


def get_heap_size():
    return len(min_heap) - 1

def percolate_down(index):
    heap_size = get_heap_size()
    if heap_size < index * 2: pass # 자식 없는 경우
    elif heap_size < index * 2 + 1: # 자식 하나인 경우
        only_child = index * 2
        if min_heap[index] > min_heap[only_child]:
            min_heap[index], min_heap[only_child] = min_heap[only_child], min_heap[index]
            percolate_down(only_child)
    else: # 자식 두개인 경우
        child1 = index * 2
        child2 = index * 2 + 1
        if min_heap[index] < min_heap[child1] and min_heap[index] < min_heap[child2]: pass
        else:
            swapping_child = child1 if min_heap[child1] < min_heap[child2] else child2
            min_heap[index], min_heap[swapping_child] = min_heap[swapping_child], min_heap[index]
            percolate_down(swapping_child)

def percolate_up(index):
    if index == 1 or min_heap[index] > min_heap[index // 2]:
        return
    else:
        min_heap[index], min_heap[index // 2] = min_heap[index // 2], min_heap[index]
        percolate_up(index // 2)


def remove(index):
    if get_heap_size() == 1:
        min_heap.pop(1)
        return
    else:
        min_heap[index] = min_heap[get_heap_size()]
        min_heap.pop(get_heap_size())
    percolate_down(index)

def main():
    n = int(sys.stdin.readline())
    for _ in range(n):
        command = int(sys.stdin.readline())
        if command == 0:
            # 힙에서 하나 빼기
            if get_heap_size() == 0:
                print(0)
            else:
                print(min_heap[1])
                remove(1)

        else:
            # 힙에 해당 숫자 넣기
            min_heap.append(command)
            percolate_up(get_heap_size())


min_heap = [-1]
if __name__ == "__main__":
    main()
