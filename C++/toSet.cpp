//
// Created by hay boy on 2021/4/23.
//
void toSet(int* arr, int preWorkLength){
    bool sign = true;
    int newLength = preWorkLength;
    int* transArr = new int(newLength);
    transArr[newLength - 1] = 0;//transArr[newLength -1] = effectiveLengthOf "transArr"
    for(int i = 0; i < preWorkLength - 1;i++){
        for(int j = 0;j < transArr[newLength - 1]; j++){
            if(arr[i] == transArr[j]){
                sign = false;
            }
        }
        if(sign){
            transArr[transArr[newLength - 1]] = arr[i];
            transArr[newLength - 1] += 1;
            sign = true;
        }
    }
    for(int k = 0; k < transArr[newLength - 1];k++){
        arr[k] = transArr[k];
    }
    arr[preWorkLength - 1] =  transArr[newLength - 1];//arr列表最后一位放置有效长度，不是有效索引哟
    delete transArr;
    /*
     * README.txt
     * 本函数的作用:
     * 传入一个数组，以及它的长度，获取它的独特值，并且最后一个元素将会用来存储有效长度
     * 传入函数要求：声明时，把要传入函数的数组长度多声明一个长度，以避免原数组中没有相同元素时，存储元素和存储长度的冲突
     * ￥尽管这样会造成额外的麻烦，但是我们还是觉得这并不是一件难事
     * 改变函数特点，尽管我们传入的数组相比于原来应该长度多了一个一个长度，但是我们还是省略了将无效区段的数组元素改为其他值。
     * 尽管此函数有一定的作用，但是我们还是觉得你需要谨慎使用，尤其是需要先弄懂或会自制此或此类函数。
     * */
}
