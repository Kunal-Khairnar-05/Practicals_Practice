def quick_sort(arr):
    if(len(arr)<=1):
        return arr
    else:
        pivot = arr[0]
        left = [x for x in arr[1:] if x<pivot]
        right = [x for x in arr[1:] if x>pivot]
    return quick_sort(left)+[pivot]+quick_sort(right)

arr = [4,1,3,7,9,2,6,5,8]
print(quick_sort(arr))