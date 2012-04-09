#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> in;
  int num;
  cin>>num;
  while(num != 42){
    in.push_back(num);
    cin>>num;
  }
  vector<int>::iterator it;
  vector<int>::iterator end=in.end();
  for(it = in.begin(); it != end; it++)
    cout<<*it<<endl;
  return 0;
}
