N = int(input())
room = []
for i in range(N):
    D, C = map(int, input().split())
    room.append([D, C])
room.sort(key=lambda x: (x[0], x[1]))

ans = 1
price = room[0][1]
for i in range(1, N):
    if room[i][1] < price:
        ans += 1
        price = room[i][1]

print(ans)