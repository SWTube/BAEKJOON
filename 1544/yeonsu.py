N = int(input())
arr = []
for i in range(N):
    arr.append(input())

words = []
for i in range(N):
    if i == 0:
        words.append(arr[0])

    flag = True
    for j in range(i + 1, N):
        for k in range(len(arr[j])):
            new_word = arr[j][k:] + arr[j][:k]
            if new_word in words:
                flag = False

        if flag == True:
            words.append(arr[j])

print(len(words))