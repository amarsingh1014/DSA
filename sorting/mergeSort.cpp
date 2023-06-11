#include<iostream>
using namespace std;


void merge(int array[], int const left, int const mid, int const right) {
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid ;

  auto *leftArray = new int[subArrayOne];
  auto *rightArray = new int[subArrayTwo];

  for (auto i = 0; i < subArrayOne; i++) {
    leftArray[i] = array[left + i]; 
  }
  for (auto j = 0; j < subArrayTwo; j++) {
    rightArray[j] = array[mid + 1 + j]; 
  }

  auto indexOfSubArrayOne = 0;
  auto indexOfSubArrayTwo = 0;
  int indexOfMergedArray = left;

  while ( indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
    if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
    }
     else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;

  }

 while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }

    delete[] leftArray;
    delete[] rightArray;

}

void mergeSort(int arr[], int begin, int end) {
    if (begin >= end)
        return;
    
 auto mid = begin + (end - begin)/2;

 mergeSort(arr, begin, mid );
 mergeSort(arr, mid + 1, end);
 merge(arr, begin, mid, end);

}

void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}

int main()  {
    int arr[] = {1, 4, 32 , 11 , 68, 54, 34, 189, 85, 99, 34 , 55, 134, 44, 56, 14, 37, 197, 155, 165};
 int size = sizeof(arr)/ sizeof(arr[0]);

 mergeSort(arr, 0, size-1);
 cout << "\nSorted array is \n";
    printArray(arr, size);
    return 0;

}

