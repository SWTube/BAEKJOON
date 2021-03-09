### 최소 중복 횟수 중 최솟값을 갖는 price 구하기
U, N = map(int, input().split())
auction = {}
for i in range(N):
    S, P = input().split()
    if int(P) <= U:
        if int(P) in auction:
            p_list = auction[int(P)]
            p_list.append(S)
            auction[int(P)] = p_list
        else:
            auction[int(P)] = [S]
auction = sorted(auction.items(), key=lambda x: (len(x[1]), x[0]))
list(auction)
print(auction[0][1][0], auction[0][0])