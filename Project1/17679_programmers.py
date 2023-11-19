temp = set()
def check4(x, y, board, m, n):
    global temp
    dx = [-1, 0, 1, -1, 0, 1, -1, 0, 1]
    dy = [-1, -1, -1, 0, 0, 0, 1, 1, 1]
    check = []
    isPang = False
    for i in range(9):
        if x + dx[i] < 0 or x+dx[i] >= m \
        or y+dy[i] < 0 or y + dy[i] >= n:
            continue
        check.append(i)
    if 0 in check and 1 in check and 3 in check and 4 in check and board[x+dx[0]][y+dy[0]] == board[x+dx[4]][y+dy[4]] and board[x+dx[1]][y+dy[1]] == board[x+dx[4]][y+dy[4]] and board[x+dx[3]][y+dy[3]] == board[x+dx[4]][y+dy[4]] and board[x+dx[4]][y+dy[4]]!='0':
        temp.add((x+dx[0], y+dy[0]))
        temp.add((x+dx[1], y+dy[1]))
        temp.add((x+dx[3], y+dy[3]))
        temp.add((x+dx[4], y+dy[4]))
        isPang = True
    if 1 in check and 2 in check and 4 in check and 5 in check and board[x+dx[1]][y+dy[1]] == board[x+dx[4]][y+dy[4]] and board[x+dx[2]][y+dy[2]] == board[x+dx[4]][y+dy[4]] and board[x+dx[4]][y+dy[4]] == board[x+dx[5]][y+dy[5]] and board[x+dx[4]][y+dy[4]]!='0':
        temp.add((x+dx[1], y+dy[1]))
        temp.add((x+dx[2], y+dy[2]))
        temp.add((x+dx[4], y+dy[4]))
        temp.add((x+dx[5], y+dy[5]))
        isPang = True
    if 3 in check and 4 in check and 6 in check and 7 in check and board[x+dx[3]][y+dy[3]] == board[x+dx[4]][y+dy[4]] and board[x+dx[4]][y+dy[4]] == board[x+dx[6]][y+dy[6]] and board[x+dx[4]][y+dy[4]] == board[x+dx[7]][y+dy[7]] and board[x+dx[4]][y+dy[4]]!='0':
        temp.add((x+dx[3], y+dy[3]))
        temp.add((x+dx[4], y+dy[4]))
        temp.add((x+dx[6], y+dy[6]))
        temp.add((x+dx[7], y+dy[7]))
        isPang = True
    if 4 in check and 5 in check and 7 in check and 8 in check and board[x+dx[4]][y+dy[4]] == board[x+dx[5]][y+dy[5]] and board[x+dx[4]][y+dy[4]] == board[x+dx[7]][y+dy[7]] and board[x+dx[4]][y+dy[4]] == board[x+dx[8]][y+dy[8]] and board[x+dx[4]][y+dy[4]]!='0':
        temp.add((x+dx[4], y+dy[4]))
        temp.add((x+dx[5], y+dy[5]))
        temp.add((x+dx[7], y+dy[7]))
        temp.add((x+dx[8], y+dy[8]))
        isPang = True
    
    return isPang

def swap_down(m, y, board):
    result = False
    for i in range(m-1, 0, -1):
        if board[i-1][y]!='0' and board[i][y]=='0':
            index = i
            while index < m and board[index][y]=='0':
                board[index][y] = board[index-1][y]
                board[index-1][y] = '0'
                index += 1
                result = True
    return result

def solution(m, n, board):
    global temp
    answer = 0
    for j in range(m):
        board[j] = list(board[j].strip())
    while True:
        temp = set()
        # update pang positions include duplicate
        for i in range(m):
            for j in range(n):
                check4(i,j,board,m,n)
        
        # log: pang coords list
        #print(temp)
        
        # nothing to pang
        if len(temp) == 0:
            break
        
        # do pang
        for x, y in temp:
            board[x][y] = '0'
            answer+=1
        
        # log: board after pang
        #print("after pang")
        #for j in range(m):
        #    print(board[j])
        
        # swap down by each column
        for j in range(n):
            swap_down(m, j, board)
        
        # log: board after swap
        #print("after swap")
        #for j in range(m):
        #    print(board[j])
    
    return answer