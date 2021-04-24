public class InsertionSort {
    public InsertionSort() {
    }

    public static void insertionSort(int[] arr) {
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

    }

    public static void printBlankArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    public static void main(String[] args) {
        int[] a = { 5, 2, 4, 6, 1, 3, 9, 7, 8, 11, 10 };
        insertionSort(a);
        printBlankArray(a);

    }
}