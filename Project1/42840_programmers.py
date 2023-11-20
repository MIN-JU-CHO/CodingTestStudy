def solution(answers):
    length = len(answers)
    one = []
    two = []
    three = []
    elem_1 = [1, 2, 3, 4, 5]
    index_1 = 0
    elem_2 = [1, 3, 4, 5]
    index_2 = 0
    elem_3 = [3, 1, 2, 4, 5]
    index_3 = 0
    for i in range(length):
        three.append(elem_3[index_3])
        one.append(elem_1[index_1])
        if index_1 == 4:
            index_1 = 0
        else:
            index_1 += 1
        if (i+1)%2==1:
            two.append(2)
        else:
            two.append(elem_2[index_2])
            if index_2 == 3:
                index_2 = 0
            else:
                index_2 += 1
            if index_3 == 4:
                index_3 = 0
            else:
                index_3 += 1
    counts = {1:0, 2:0, 3:0}
    for i in range(length):
        if answers[i] == one[i]:
            counts[1] += 1
        if answers[i] == two[i]:
            counts[2] += 1
        if answers[i] == three[i]:
            counts[3] += 1
    
    answer = [k for k, v in counts.items() if max(counts.values()) == v]
    return answer
