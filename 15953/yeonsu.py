testcase = int(input())

money2017 = []; money2018 = []
for i in range(22):
    if i == 0: money2017.append(0)
    elif i == 1: money2017.append(500)
    elif i == 2 and i == 3: money2017.append(300)
    elif i >= 4 and i <= 6: money2017.append(200)
    elif i >= 7 and i <= 10: money2017.append(50)
    elif i >= 11 and i <= 15: money2017.append(30)
    elif i >= 16 and i <= 21: money2017.append(10)

for i in range(32):
    if i == 0: money2018.append(0)
    elif i == 1: money2018.append(512)
    elif i == 2 and i == 3: money2018.append(256)
    elif i >= 4 and i <= 7: money2018.append(128)
    elif i >= 8 and i <= 15: money2018.append(64)
    elif i >= 16 and i <= 31: money2018.append(32)

for i in range(testcase):
    a, b = map(int, input().split())
    if a > 21: a = 0
    else: a = money2017[a]

    if b > 31: b = 0
    else: b = money2018[b]

    print((a+b)*10000)