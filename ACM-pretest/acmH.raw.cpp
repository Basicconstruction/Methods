#include <iostream>
using namespace std;
/*
 * 逻辑实现
 * 关联排序
 * 包含审查冲突处理
 * */
class Pointer{
public:
    int arr1[100];
    int arr2[100];
    int arr3[100][2];
    int l;
    int arr3l;
    Pointer(int _l){
        this->l = _l;
        arr3l = 0;
    }
    void unionSort(){
        int trans;
        for(int i = 0; i < this->l-1;i++){
            for(int j = 0; j < this->l - i - 1; j++){
                if(this->arr1[j]>this->arr1[j+1]){
                    trans = this->arr1[j];
                    this->arr1[j] = this->arr1[j+1];
                    this->arr1[j+1] = trans;
                    trans = this->arr2[j];
                    this->arr2[j] = this->arr2[j+1];
                    this->arr2[j+1] = trans;
                }
            }
        }
        for(int i = 0; i < this->l-1;i++){
            for(int j = 0; j < this->l - i - 1; j++){
                if(this->arr1[j]==this->arr1[j+1]){
                    if(this->arr2[j]>this->arr2[j+1]){
                        trans = this->arr1[j];
                        this->arr1[j] = this->arr1[j+1];
                        this->arr1[j+1] = trans;
                        trans = this->arr2[j];
                        this->arr2[j] = this->arr2[j+1];
                        this->arr2[j+1] = trans;
                    }
                }
            }
        }
    }
    void printUnion(){
        for(int p = 0; p < l;p++){
            cout<<this->arr1[p]<<" "<<this->arr2[p]<<"\n";
        }
    }
    void printArr3(){
        for(int p = 0; p < arr3l;p++){
            cout<<"arr3["<<p<<"][0]: "<<arr3[p][0]<<"  "<<"arr3["<<p<<"][1]: "<<arr3[p][1]<<endl;
        }
    }
    bool contains(int i1, int i2){
        //i1 contains i2
        if(this->arr2[i1]>this->arr1[i2]){
            if((this->arr2[i1]>=this->arr2[i2])&&(this->arr1[i1]<=this->arr1[i2])){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
    int beContains(int i1, int i2){
        if(contains(i1,i2)){
            return i2;//i2 被 i1 包含
        }else if(contains(i2,i1)){
            return i1;//i1 被 i2 包含
        }else{
            return -1;
        }
    }
    void putInArr3(){
        int lateTemp = 0;
        for(int y = 1; y < this->l;y++){
            if(beContains(lateTemp, y)==lateTemp){
                //lateTemp is contained by y
                cout<<"Continue "<<y<<endl;
            }else if(beContains(lateTemp, y)==y){
                //y is contained by lateTemp
                lateTemp = y;
                cout<<"CHANGE to "<<y<<" Without put in!"<<endl;
            }else{
                //conflict occur, the conflict will be tackled in further codes.
                //-1
                arr3[arr3l][0] = arr1[lateTemp];
                arr3[arr3l][1] = arr2[lateTemp];
                arr3l++;
                lateTemp = y;
                cout<<"CHANGE to "<<y<<" And put in!"<<endl;
            }
            if(y==this->l-1){
                arr3[arr3l][0] = arr1[lateTemp];
                arr3[arr3l][1] = arr2[lateTemp];
                arr3l++;
            }
        }
    }
    bool occurConflict(int i1, int i2){
        //i1 < i2
        //transfer the arr3 arrays
        if(arr3[i1][1]>arr3[i2][0]){
            return true;
        }
        return false;
    }
    void printNumbers(){
        int mayCauseConflictIndex = 0;
        int count = 1;
        for(int y = 1; y < this->arr3l;y++){
            if(occurConflict(mayCauseConflictIndex, y)){

            }else{
                count++;
                mayCauseConflictIndex = y;
            }
        }
        cout<<"Ending: "<<count;
    }
    void mainTackle(){
        this->unionSort();
        this->putInArr3();
        printNumbers();
    }
    void debugTackle(){
        this->unionSort();
        this->printUnion();
        this->putInArr3();
        this->printArr3();
        printNumbers();
    }
};
int main() {
    int datas;
    Pointer x(0);
    while(true){
        x = NULL;
        cin>>datas;
        if(datas==0){
            break;
        }
        x = Pointer(datas);
        for(int y = 0; y < datas;y++){
            scanf("%d%d", &(x.arr1[y]),&(x.arr2[y]));
        }
        x.debugTackle();

    }
    return 0;
}
/*
1 3
3 4
0 7
3 8
15 19
15 20
10 15
8 18
6 12
5 10
4 14
2 9

0 7       put
1 3
2 9
3 4       put
3 8
4 14
5 10      put
6 12      put
8 18
10 15     put
15 19     should be put
15 20

0 7
1 3        1
2 9
3 4        2
3 8
4 14
5 10        3
6 12
8 18
10 15       4
15 19       5
15 20
 */
/*
4 1 2 1 4 3 5 4 7
 4
1 2
1 4
3 5
4 7
 */
/*
5        adjacent conflict
1 4   0
3 5   1  0,1 conflict
4 8   2  1,2 conflict
9 14  3
13 16 4  3,4 conflict
 */
/*        conflicts always occur with the item adjacent itself
6         more conflicts, cross position conflict
1 9       conflict with three, must dropped
2 10      conflict with three
5 13      conflict with three
7 15      conflict with four
14 17     conflict with one, solution: keep the first that conflicts with other, if conflicts continue with it,
delete the conflict item's length until next don't conflict the first one.
tackled 1 9 -- 14 17 --2
 */