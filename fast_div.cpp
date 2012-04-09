#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n,k;
  std::ios_base::sync_with_stdio (false);
  std::cin>>n>>k;
  int count=0;
  for(int i=0; i< n; i++){
    int temp;
    std::cin>>temp;
    if(temp%k) 
      ++count;
  }
  std::cout<<count;
  return(0);
}
