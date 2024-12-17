def shellsort(arr):
    n = len(arr)
    gap = n//2

    while gap>0:
        for i in range(gap,n):
            temp = arr[i]
            j=i
            while j>=gap and arr[j-gap]>temp:
                arr[i] = arr[j-gap]
                j-=gap
            arr[j]=temp
        gap//=2
    return arr


myarr = [1,6,4,2,9]
print(shellsort(myarr))    