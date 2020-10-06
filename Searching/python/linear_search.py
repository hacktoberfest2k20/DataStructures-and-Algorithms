def linear_search(arr, key):
    found = False
    for i in range(0,len(arr)):
        if arr[i] == key:
            print("Element Found at position {}".format(i+1))
            found = True
    if found == False:
        print("Element NOT Found")


# Driver Code

arr = [2,4,5,6,7,2]
linear_search(arr,2)
linear_search(arr,10)
