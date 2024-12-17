def insertion_sort(arr):
    n = len(arr)

    for i in range(1,n):
        key = arr[i]
        j=i-1
        while(key<arr[j] and j>=0):
            arr[j+1]=arr[j]
            j-=1
        arr[j+1]=key

    return arr


def shell_sort(arr):
    n = len(arr)
    gap = n//2

    while gap>0:
        for i in range(gap,n):
            temp = arr[i]
            j=i
            while j>gap and arr[j-gap]>temp:
                arr[j]=arr[j-gap]
                j-=gap
            arr[j]=temp
        gap//=2

    return arr
    
arr = [4,1,3,7,9,2,6,5,8]
print(insertion_sort(arr))
print(shell_sort(arr))