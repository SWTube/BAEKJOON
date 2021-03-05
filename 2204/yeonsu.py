while True:
    n = int(input())
    if n == 0:
        break

    words = []
    for i in range(n):
        words.append(input())

    words.sort(key=str.lower)
    print(words[0])