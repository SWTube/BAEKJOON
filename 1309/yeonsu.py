n = int(input()) # 세로
DP = [[1 for col in range(3)] for row in range(n)] # 2차원 DP 배열

case = 0
for i in range(n):
    if i != 0:
        DP[i][0] = (DP[i-1][0] + DP[i-1][1] + DP[i-1][2]) % 9901
        DP[i][1] = (DP[i-1][0] + DP[i-1][2]) % 9901
        DP[i][2] = (DP[i-1][0] + DP[i-1][1]) % 9901
    case = DP[i][0] + DP[i][1] + DP[i][2]

print(case % 9901)