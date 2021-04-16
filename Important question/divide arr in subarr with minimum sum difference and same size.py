'''
Sample Test Cases

Sample Input
87,100,28,67,68,41,67,1

Sample Output
229 230
 

Explanation

For the given input, the two groups that can be formed following the mentioned rules are:

Group 1: 87 100 41 1
Group 2: 28 67 68 67
The total sum of integers in each of the groups which is as nearly equal as possible is:

Group 1-Total Sum:229
Group 2-Total Sum:230
The total number of integers between group 1 and 2 differ by O integer.

'''

a=[87,100,28,67,68,41,67,1]#list(map(int,input().split()))
n1=len(a)
n2=n1//2
su=sum(a)/2
dp=[[-1 for i in range(n2+1)] for j in range(n1)]
def answer(i,n,s):
 if i<(n-1):
  return float('inf')
 if n==0:
  return abs(s)
 else:
  return min(answer(i-1,n-1,s-a[i-1]),answer(i-1,n,s))

k=answer(n1-1,n2,su)
print(int(su-k),int(su+k))
