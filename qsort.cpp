#include <iostream>

using namespace std;

// swap elements in array with index i and j
void swap(int* arr, int i , int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// partition arrray using first element as the pivot
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

// quick sort for an array of size stop-start
// potentially can also sort only sub parts of the array
void qsort(int* arr,int start,int stop){
    if (start < stop) {
	// find pivot to start sorting
	int pivot = partition(arr, start, stop);
	// sort left of pivot
	qsort(arr, start, pivot-1);
	// sort right of pivot
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
