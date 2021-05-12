#include <iostream>
using namespace std;
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
    bool contains(int i1, int i2){
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
            return i2;
        }else if(contains(i2,i1)){
            return i1;
        }else{
            return -1;
        }
    }
    void putInArr3(){
        int lateTemp = 0;
        for(int y = 1; y < this->l;y++){
            if(beContains(lateTemp, y)==lateTemp){
            }else if(beContains(lateTemp, y)==y){
                lateTemp = y;
            }else{
                arr3[arr3l][0] = arr1[lateTemp];
                arr3[arr3l][1] = arr2[lateTemp];
                arr3l++;
                lateTemp = y;
            }
            if(y==this->l-1){
                arr3[arr3l][0] = arr1[lateTemp];
                arr3[arr3l][1] = arr2[lateTemp];
                arr3l++;
            }
        }
    }
    bool occurConflict(int i1, int i2){
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
        cout<<count<<endl;
    }
    void mainTackle(){
        this->unionSort();
        this->putInArr3();
        this->printNumbers();
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
        x.mainTackle();

    }
    return 0;
}