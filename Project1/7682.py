import sys
input = sys.stdin.readline

def check_win(board, turn):
    # 가로
    for i in range(3):
        if all(board[i][j] == turn for j in range(3)):
            return True
    # 세로
    for j in range(3):
        if all(board[i][j] == turn for i in range(3)):
            return True
    # 대각선
    if all(board[i][i] == turn for i in range(3)) or all(board[i][2 - i] == turn for i in range(3)):
        return True
    return False
    
def check_final(game):
    board = [['0'] * 3 for _ in range(3)]
    ocount = 0
    xcount = 0
    index = 0
    for x in range(3):
        for y in range(3):
            board[x][y] = game[index]
            if board[x][y] == "O":
                ocount += 1
            elif board[x][y] == "X":
                xcount += 1
            index += 1
    if ocount > xcount or xcount > ocount + 1:
        return False
    elif ocount == xcount and check_win(board, "O") and not check_win(board, "X"):
        return True
    elif xcount == ocount + 1 and check_win(board, "X") and not check_win(board, "O"):
        return True
    elif xcount == 5 and ocount == 4 and not check_win(board, "O"):
        return True
    return False

while True:
    game = input().strip()
    if game == "end":
        break
    game = list(game)
    if check_final(game):
        print("valid")
    else:
        print("invalid")
    