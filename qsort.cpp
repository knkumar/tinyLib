#include <iostream>

using namespace std;

void swap(int* arr, int i , int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int* arr, int start, int stop){
    int pivot = arr[start];
    int seen = start;
    int future = seen+1;
    while(future <= stop){
	if (arr[future] < pivot){
	    swap(arr, seen+1, future);
	    seen++;
	}
	future++;
    }
    swap(arr, 0, seen);
    return seen;
}

void qsort(int* arr,int start,int stop){
    if (start < stop) {
	int pivot = partition(arr, start, stop);
	qsort(arr, start, pivot-1);
	qsort(arr, pivot+1, stop);
    }
}


void print_array(int* arr, int size){
    for(int i = 0; i <= size;i++){
	cout<<arr[i];
    }
    cout<<"\n";
}

int main(){
    int test[] = {5,4,2,1,3};
    int size = 4;
    print_array(test, size);
    qsort(test, 0, size);
    print_array(test,size);
    return 0;
}
