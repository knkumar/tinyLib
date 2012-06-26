#include <iostream>

using namespace std;

void swap(int* arr, int i , int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


void merge(int* arr, int start, int mid, int stop){

    int i=start;
    int j = mid+1;
    
    int scratch[stop-start + 1];
    int scratch_ind = 0;
    
    while( i <=mid && j <= stop){
	if( arr[i] < arr[j])
	    scratch[scratch_ind++] = arr[i++];
	else
	    scratch[scratch_ind++] = arr[j++];
    }
    
    while(i <= mid)
	scratch[scratch_ind++] = arr[i++];

    while(j <= stop)
	scratch[scratch_ind++] = arr[j++];

    for(int it = start; it <= stop; it++)
	arr[it] = scratch[it-start];

}


void merge_sort(int* arr, int start, int stop){
    if(start < stop){
	int mid = (start+stop)/2;
	merge_sort(arr, start, mid);
	merge_sort(arr, mid+1, stop);
	merge(arr,start, mid, stop);
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
    merge_sort(test, 0, size);
    print_array(test,size);
    return 0;
}
