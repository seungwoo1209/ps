voc = {"zero":"0", "one":"1", "two":"2", "three":"3", "four":"4", "five":"5", "six":"6", "seven":"7", "eight":"8", "nine":"9" }

def is_number(s):
    return (s in voc)
    

def solution(s):
    c = 0
    tmp = ""
    buf = ""
    for i in range(len(s)):
        if s[i].isdigit():
            tmp += s[i]
        else:
            buf += s[i]
            if is_number(buf):
                tmp += voc[buf]
                buf = ""
    answer = int(tmp)
        
    return int(answer)