def sentinal_search(arr,n,key):
    last = arr[-1]
    arr[-1] = key

    i=0
    while(arr[i]!=key):
        i=i+1
    
    if(i!=(n-1)):
        return i
    elif(last==key):
        return n-1;

    return -1


arr = [4,3,1,8,6,9,11]
print(sentinal_search(arr,7,11))

