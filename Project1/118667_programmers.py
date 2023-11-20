from queue import deque
def solution(queue1, queue2):
    # 목표: 두 큐의 각 합이 절반
    # 합이 홀수면 불가능
    if (sum(queue1) + sum(queue2)) % 2 != 0:
        return -1
    q1 = deque(queue1)
    q2 = deque(queue2)
    sumQ1 = sum(queue1)
    sumQ2 = sum(queue2)
    answer = 0
    count = 4 * len(queue1)
    while count > 0 and sumQ1 != sumQ2:
        count -= 1
        answer += 1
        # 합이 큰 쪽에서 작은 방향으로 이동해야 최소 작업
        if sumQ1 > sumQ2:
            elem = q1.popleft()
            q2.append(elem)
            sumQ1 -= elem
            sumQ2 += elem
        else:
            elem = q2.popleft()
            q1.append(elem)
            sumQ2 -= elem
            sumQ1 += elem
    # 큐 길이의 4배: 모든 경우 시도
    if sumQ1 != sumQ2:
        return -1
    return answer
