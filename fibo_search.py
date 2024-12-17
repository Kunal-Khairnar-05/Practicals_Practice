def fibonacci_search(arr, x):
    n = len(arr)
    
    fib_m2 = 0
    fib_m1 = 1  
    fib_m = fib_m2 + fib_m1 
    
    while fib_m < n:
        fib_m2 = fib_m1
        fib_m1 = fib_m
        fib_m = fib_m2 + fib_m1
    
    offset = -1
 
    while fib_m > 1:
        i = min(offset + fib_m2, n - 1)
        
        if arr[i] < x:
            fib_m = fib_m1
            fib_m1 = fib_m2
            fib_m2 = fib_m - fib_m1
            offset = i
        
        elif arr[i] > x:
            fib_m = fib_m2
            fib_m1 = fib_m1 - fib_m2
            fib_m2 = fib_m - fib_m1
        
        # Element found. Return index
        else:
            return i
    
    # Comparing the last element with x
    if fib_m1 and arr[offset + 1] == x:
        return offset + 1
    
    # Element not found, return -1
    return -1

arr=[10,40,2,6,5,12,7]
key=5

print(fibonacci_search(arr,key))
