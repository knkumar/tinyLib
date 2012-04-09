#include <iostream>

using namespace std;

int main(){
  double draw,bal;
  cin>>draw>>bal;
  if( !((int)draw%5) && (draw+0.5 <= bal) )
    cout<<double(bal-(draw+0.5));
  else
    cout<<bal;
  return 0;
}
