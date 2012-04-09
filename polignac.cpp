#include <iostream>
 
using namespace std;
 
int main(){
  std::cout.sync_with_stdio(false);
  int n;
  cin >> n;
  int arr[n];
  int out[n];
  for(int i=0; i<n; i++){
    int val;
    cin>>val;
    int five_mult =5, fives=1, out_val=0;
    while(five_mult <= val){
      out_val += val/five_mult;
      five_mult *= 5;
      fives++;
    }
    out[i] = out_val;
  }
  for(int i=0; i<n; i++){
    cout<<out[i]<<'\n';
  }
  return(0);
}
