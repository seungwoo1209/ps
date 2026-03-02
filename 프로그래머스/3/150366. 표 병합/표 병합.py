# 칸의 크기는 50*50 = 2500. command는 최대 1000개니까 
# O(n)을 한다 치면 2500 * 1000 = 250만 => 할만함
# 칸은 비어있는 상태로 시작하니 실제로는 이보다 연산시간이 적을 듯

def solution(commands):
    cells = ["EMPTY"] * 2501
    parent = [i for i in range(0,2501)]
    answer = []
    
    def find(idx):
        if parent[idx] == idx:
            return idx
        parent[idx] = find(parent[idx]) # 연쇄적으로 가장 부모로 값 업데이트
        return parent[idx]
    
    def union(idx1, idx2):
        root1 = find(idx1)
        root2 = find(idx2)
        if root1 != root2:
            if cells[root1] == "EMPTY":
                cells[root1] = cells[root2]
            parent[root2] = root1
            
    def update(l):
        if len(l) > 2: # UPDATE r c value
            r, c = map(int, l[:2])
            value = l[2]
            idx = (r-1) * 50 + c
            cells[find(idx)] = value
        else: # UPDATE value1 value2
            value1,value2 = l
            for i in range(1, 2501):
                if cells[find(i)] == value1:
                    cells[find(i)] = value2
                    
    
    def merge(l):
        r1, c1, r2, c2 = map(int, l)
        idx1, idx2 = (r1 - 1) * 50 + c1, (r2 - 1) * 50 + c2
        union(idx1, idx2)
    
    def unmerge(l):
        r, c = map(int, l)
        idx = (r - 1) * 50 + c
        root = find(idx)
        val = cells[root]
        
        to_unmerge = [i for i in range(1, 2501) if find(i) == root]
        for i in to_unmerge:
            parent[i] = i
            cells[i] = "EMPTY"
        cells[idx] = val # 원래 위치에만 값 복구
                
    def prnt(l):
        r,c = map(int, l)
        idx = (r-1) * 50 + c
        answer.append(cells[find(idx)])
        
        
    for command in commands:
        l = command.split()
        if l[0] == "UPDATE":
            update(l[1:])
        elif l[0] == "MERGE":
            merge(l[1:])
        elif l[0] == "UNMERGE":
            unmerge(l[1:])
        else: # PRINT R C
            prnt(l[1:])
            
    return answer