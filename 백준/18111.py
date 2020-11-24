
n, m, b = map(int, input().split())

a = []

for i in range(0, n):
    a+= map(int, input().split())

a.sort()

i = 0
ans = 256*500*500
ans_h = 0
_sum = sum(a)
left = 0

for h in range(a[0], a[n*m-1]+1):
    j = i
    while j<=n*m:
        if j == n*m:
            break;
        if a[j]>h:
            break;
        left+=a[j]
        j+=1
    
    _min = h*j-left
    _max = _sum-left-(h*(n*m-j))

    i = j

    if _min>b+_max:
        break;

    if(_min+_max*2<=ans):
        ans = _min+_max*2
        ans_h = h

print(ans, ans_h)
    

