#include<iostream>

using namespace std;

template <class Type>
void printArray(Type arr[],int start, int end) {
    int len = end;
    for (int i = start; i < len; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

template <class Type>
void Swap(Type *a, Type *b) {
    Type tmp = *a;
    *a = *b;
    *b = tmp; 
}

template <class Type>
int Partition(Type arr[], int p , int r) {
    int pivot = arr[p];
    int highvac = r;
    int lowvac = p;
    bool direct = true; //true for right, false for left 
    while(highvac > lowvac) {
        if (direct == true) {
            if(arr[highvac] <= pivot) {
                arr[lowvac] = arr[highvac];
                lowvac++;
                direct = false;
            } else {
                highvac--;
            } 
        } else {
            if(arr[lowvac]> pivot ) {
                arr[highvac] = arr[lowvac];
                highvac--;
                direct = true;
            }else {
                lowvac++;
            }
        }
        if (r-p==6) {
            printArray(arr,p,r+1);
        }
    }
    arr[highvac] = pivot;
    //printArray(arr,p,r+1);
    return highvac;
}

template<class Type>
void QuickSort(Type arr[], int p, int r) {
    if (p < r) {
        int q = Partition(arr,p,r);
        QuickSort(arr,p,q-1);
        QuickSort(arr,q+1,r);
    }
}

int main(int argc, char** argv) {
    int test_arr[] = {0,0,3, 1, 2, 5,1,1,1,6,0,100};
    int len = sizeof(test_arr)/sizeof(*test_arr);
    cout << "Original Array:" << endl;
    printArray(test_arr,0, len);
    QuickSort(test_arr,0,len-1);
    cout << "Sorted Array:" << endl;
    printArray(test_arr,0,len);
}
