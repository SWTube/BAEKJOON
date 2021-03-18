N = int(input())
ans = {}
for i in range(N):
    cards = list(map(int, input().split()))
    MAX = 0
    for x in range(5):
        for y in range(x + 1, 5):
            for z in range(y + 1, 5):
                # print(cards[x], cards[y], cards[z])
                sum = cards[x] + cards[y] + cards[z]
                MAX = max(int(str(sum)[-1]), MAX)
    ans[i + 1] = MAX

ans = sorted(ans.items(), key=lambda x: (x[1], x[0]), reverse=True)
print(ans[0][0])