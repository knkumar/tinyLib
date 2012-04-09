#include <iostream>

using namespace std;

int main(){
  std::cout.sync_with_stdio(false);
  short int t;
  int n,g;

  cin>>t;
  int res[t];
  int temp, max_diff, min_element, diff;

  for(int i=0; i<t ; ++i){
    cin>>n;    
    max_diff = 0;
    min_element = 1000001;
    for(int j=0; j<n; ++j){
      cin>>temp;
      diff = temp - min_element;
      if(diff > max_diff)
	max_diff = diff;

      if(temp < min_element)
	min_element = temp;      
    }
    res[i] = max_diff;
  }
  for(int i=0; i<t ; ++i){
    if(res[i] > 0)
      cout<<res[i]<<'\n';
    else
      cout<<"UNFIT\n";
  }

}
