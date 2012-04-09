#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
 
using namespace std;
 
int main(){
  int n,k;
  std::ios_base::sync_with_stdio (false);
  std::cin>>n>>k;
  vector <int> in(n);
  vector <int> temp(n*(n-1)/2);
  vector<int>::iterator outer;
  vector<int>::iterator inner;
  for(int i=0; i<n; i++) {
    std::cin>>in[i];
  }
  int count = 0;
  for(outer = in.begin(); outer != in.end(); ++outer){
    for(inner = outer+1; inner != in.end(); ++inner){
      temp[count++] = (*outer ^ *inner);
    }}
  sort(temp.begin(),temp.end());
  count = 0;
  for(outer = temp.begin(); count < k && outer!=temp.end(); count++, ++outer){
    cout << *outer<<" ";
  }
  return 0;
}
