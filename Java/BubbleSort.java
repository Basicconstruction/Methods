public class BubbleSort {
    public BubbleSort() {

    }

    public static void reverseArray(int[] arr) {
        int trans;
        for (int i = 0; i < (arr.length - 1) / 2; i++) {
            trans = arr[i];
            arr[i] = arr[arr.length - 1 - i];
            arr[arr.length - 1 - i] = trans;
        }
    }

    public static void bubbleSort(int[] arr, boolean ascending) {
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
            if (sign&&ascending) {
                // System.out.print("over"); //debug-print
                return;
            }
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
        bubbleSort(a, false);
        printBlankArray(a);

    }
}