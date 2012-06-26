#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int num;
  vector<bool> binary;
  cout<<"Enter number to convert to binary: ";
  cin>>num;
  while(num >= 1){
    binary.push_back(num%2);

    num = num/2;
  }
  for(vector<bool>::iterator it = binary.end()-1; it >= binary.begin(); it--) 
    cout<<*it;
  cout<<'\n';
  return 0;
}
