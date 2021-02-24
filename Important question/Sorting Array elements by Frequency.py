for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().strip().split()))
    arr = [0]*10
    for i in range(n):
        arr[a[i]]+=1
    print(arr)
    for i in range(n):
        temp = max(arr)
        for j in range(temp):
            print(arr.index(temp),end=" ")
        arr[arr.index(temp)] = -1

'''
Input:
2
5
5 5 4 6 4
5
9 9 9 2 5

Output:
4 4 5 5 6
9 9 9 2 5
'''
