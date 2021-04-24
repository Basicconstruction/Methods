#build by tianyu 2021/4/24
def bubbleSort(arr):
    sign = True
    for i in range(len(arr) - 1):
        for j in range(len(arr) - i - 1):
            if(arr[j] > arr[j+1]):
                sign = False
                arr[j+1],arr[j] = arr[j],arr[j+1]
        if(sign):
            return arr
    return arr
def main():
    arr = [5,2,4,6,1,3,9,7,8,11,10,14,13]
    arr = bubbleSort(arr)
    print(arr)
main()