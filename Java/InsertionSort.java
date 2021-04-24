public class InsertionSort {
    public InsertionSort() {
    }

    public static void reverseArray(int[] arr) {
        int trans;
        for (int i = 0; i < (arr.length - 1) / 2; i++) {
            trans = arr[i];
            arr[i] = arr[arr.length - 1 - i];
            arr[arr.length - 1 - i] = trans;
        }
    }

    public static void insertionSort(int[] arr, boolean ascending) {
        int key;
        int j;
        for (int i = 0; i < arr.length; i++) {
            key = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
        if(ascending){
            return;
        }else{
            reverseArray(arr);
        }

    }

    public static void printBlankArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    public static void main(String[] args) {
        int[] a = { 5, 2, 4, 6, 1, 3, 9, 7, 8, 11, 10 };
        insertionSort(a, false);
        printBlankArray(a);

    }
}