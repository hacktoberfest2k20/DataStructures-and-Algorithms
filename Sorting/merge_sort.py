
def merge(array, start, middle, end):
    # one array, but it's view as two arrays
    copy = array[::]

    i = start
    j = middle + 1

    k = start

    while i <= middle and j <= end:
        if copy[i] < copy[j]:
            array[k] = copy[i]
            i += 1
        else:
            array[k] = copy[j]
            j += 1

        k += 1

    while i <= middle:
        array[k] = copy[i]
        k += 1
        i += 1

    while j <= end:
        array[k] = copy[j]
        k += 1
        j += 1

def Sort(array, start, end):

    if start < end:
        middle = (start + end) // 2
        Sort(array, start, middle)
        Sort(array,middle + 1, end)
        merge(array, start, middle, end)

def MergeSort(array):
    Sort(array, 0, len(array) -1)


l = [10,9,8,7,6,5,4,3,2,1]
MergeSort(l)