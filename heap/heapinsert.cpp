#include<iostream>
using namespace std;

class heap {
    public:
    int arr[20];
    int size;

heap() {
    arr[0] = -1;
    size = 0;
}

void insert(int val) {
     size = size + 1;
    int index = size;
    arr[index] = val;

    while(index > 1) {
        int parent = index/2;

        if(arr[index] > arr[parent]) {
            swap(arr[parent], arr[index]);
            index = parent;
        } else {
            return;
        }
    }
}

void deletefromHeap() {
if(size == 0) {
    cout<<"nothshere"<<endl;
    return;
}

arr[1] = arr[size];
size--;

int i = 1;
while (i < size ) {
    int leftIndex = 2*i;
    int rightIndex = 2*i+1;

if ( leftIndex < size && arr[leftIndex] > arr[i]) {
    swap(arr[i], arr[leftIndex]);
    i = leftIndex;
} 

else if ( rightIndex < size && arr[rightIndex] > arr [i]) {
     swap(arr[i], arr[rightIndex]);
    i = rightIndex;
}

else {
    return;
}

}



}

void print(){
    for (int i=1; i<=size; i++) {
    cout << arr[i]<<" ";
} cout <<endl;
}

};

int main() {

heap h;
    h.insert(55);
    h.insert(15);
    h.insert(35);
    h.insert(25);
    h.insert(45);
    h.insert(56);
    
    h.print();

    h.deletefromHeap();
    h.print();
    return 0;

}
