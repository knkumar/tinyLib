#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int divide(int dividend, int divisor) {
    int result = 0;
    int start = divisor;
    while (dividend >= start) {
        result = result + minimize(&dividend, &divisor)-1;
        cout << dividend << "\t" << divisor << "\t" << result << endl;
        divisor = start;
    }
    return(result);
}
int minimize(int* dividend, int* divisor) {
    int count=1;
    while (*dividend >= *divisor) {
        cout << *dividend << "\t" << *divisor << "\t" << count << endl;
        *dividend = *dividend - *divisor;
        // *divisor = *divisor < 1;
        *divisor = *divisor+*divisor;
        count = count + count;
    }
    return(count);
}

int main(){
  int n,k;
  // removing syncing with stdio makes it faster due to less overhead
  // this is not thread safe
  std::ios_base::sync_with_stdio (false);
  std::cin>>dividend>>divisor;
  int result = divide(dividend,divisor);
  std::cout<<result;
  return(result);
}
