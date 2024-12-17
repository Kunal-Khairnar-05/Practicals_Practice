def quickSort(arr):
    if len(arr)<=0:
        return arr
    
    pivot = arr[0]

    left = [x for x in arr[1:] if x<pivot]
    right = [x for x in arr[1:] if x>pivot]

    return quickSort(left)+[pivot]+quickSort(right)

myarr = [3,1,6,4,2,9]
print(quickSort(myarr))    