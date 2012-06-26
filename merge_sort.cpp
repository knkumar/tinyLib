#include <iostream>

template <class T>
void merge_sort(T in[], int start, int stop)
{
  if(start+1 == stop)
    return;
  //compute the mid_point for split
  int mid = start+stop/2;
  int length = stop-start;
  //sort the left split
  merge_sort(in , start, mid);
  //sort the right split
  merge_sort(in, mid+1, stop);

  //merge the splits
  merge(in, start, mid, mid+1, stop);

}

template <class T>
T merge(T in[],int left_start, int left_stop, int right_start, int right_stop)
{
  

}
