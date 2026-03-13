def solution(n, k):
    answer = 0
    
    
    conv_str,q = "",n
    while q:
        q,r = divmod(q,k)
        conv_str = str(r) + conv_str
    
    def is_prime(part):
        if not part:
            return False
        tmp = int(part)
        if tmp == 1: return False
        # if tmp == 2: return True
        # if tmp == 3: return True
        if tmp == 4: return False
        # 어차피 최대한 길어도, 백만을 3진수로 바꾸눈 수준이라, 자릿수가 많지 않음?
        # 211020101011 말고 211121111111 이라 해보자. 그럼 211121111111에 대해 소수 검사해야 한다.
        # 그럼 시간 초과된다. 그래도 다른 아이디어가 생각 안 나서 그냥 구현 해본다.
        # 제곱근까지만 해보면 된다?
        for i in range(2, int(tmp ** 0.5) + 1):
            if tmp % i == 0:
                return False
        return True
    
    for part in conv_str.split("0"):
        if is_prime(part):
            answer += 1
    
    return answer