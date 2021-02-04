# 2POINTERS ALGORITHM
flag = [0,1,2,3,4,5]
n = len(flag)
count = 0

def booleanTwoSum(a ,i):
    j =n -1
    while j > i:
        if a[j] - a[i] < x:
            i+=1
        elif a[j] - a[i] > x:
            j-=1
        else:
            #print(f'({i},{j})')
            return True;
    return False;
            
for i in range(n-1):
    x = 3
    if (booleanTwoSum(flag,i) == True) :
        count += 1
print(f'numbers of pairs {count}')



    
