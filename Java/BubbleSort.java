public class BubbleSort {
    public BubbleSort() {

    }

    public static void bubbleSort(int[] arr) {
        int trans;
        boolean sign = true;
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr.length - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    trans = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = trans;
                    sign = false;
                }
            }
            if (sign) {
                // System.out.print("over"); //debug-print
                return;
            }
        }
    }

    public static void printBlankArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    public static void main(String[] args) {
        int[] a = { 5, 2, 4, 6, 1, 3, 9, 7, 8, 11, 10 };
        bubbleSort(a);
        printBlankArray(a);

    }
}