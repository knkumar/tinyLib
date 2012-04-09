#include <iostream>
 
using namespace std;
 
int main(){
  std::cout.sync_with_stdio(false);
  int n,t;
  cin>>n;
  int T[n];
  for(int i=0 ;i <n ; ++i){
    cin>>t;
    if(t == 0)
      T[i] = 0;
    else if(t%2 == 0)
      T[i] = t;
    else
      T[i] = t-1;
  }
  for(int i=0; i<n; i++)
    cout<<T[i]<<'\n';
  return(0);
}   
