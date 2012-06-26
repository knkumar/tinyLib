#include<iostream>

#define CHAR_BIT 32
#define rotr(x,shift) x>>shift|x<<(sizeof(x)*CHAR_BIT - shift)
#define rotl(x,shift) x<<shift|x>>(sizeof(x)*CHAR_BIT - shift)

using namespace std;


int main(){
  unsigned int num,shift;

  cout<<"Enter the number and the places to shift : \n";
  cin>>num>>shift;
  num = rotr(num,shift);
  cout<<num<<"\n";
  num = rotl(num,shift);
  cout<<num<<"\n";
  return 0;
}
