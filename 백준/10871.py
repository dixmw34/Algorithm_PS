
n,x = input().split()
x = int(x)

arr = input().split()

for i in range(0, len(arr)):
    if(int(arr[i])<x):
        print(arr[i], end = ' ')

print('\n')