def insertionSort(arr):
    for i in range(len(arr)):
        key = arr[i]
        j = i - 1
        while( j >=0 and arr[j] > key):
            arr[j+1] = arr[j]
            j = j - 1
        arr[j+1] = key
    return arr
def main():
    arr = [5,2,4,6,1,3,9,7,8,11,10]
    arr = insertionSort(arr)
    print(arr)
main()