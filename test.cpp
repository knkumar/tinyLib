#include <iostream>
//#include <stdio.h>
#include <map>
#include <string>
#include <vector>
using namespace std;


vector<string> removeDups (vector<string> lines){
    map<string, short> dup_count;
    vector<string>::iterator it;
    vector<string> ret;
    //iterate over all lines and check to see if there are duplicates
    //insert non-duplicate lines into the return 
    for(it = lines.begin(); it != lines.end(); it++) {
	//the line is not seen before
	if(dup_count.count((*it)) == 0) {
	    dup_count[*it] = 1; //*it should be a hashable item
	    ret.push_back(*it);
	}
    }
    return(ret);
}



int main(){
  int n;
  //char inp[256];
  //fgets(inp,255,stdin);
  //int a[n];
  vector<string> lines;
  lines.push_back("a");
  lines.push_back("b");
  lines.push_back("b");
  lines.push_back("c");
  lines.push_back("d");
  lines = removeDups(lines);
  vector<string>::iterator it;
  for(it = lines.begin(); it != lines.end(); ++it)
      cout<<"\n"<<*it;
  return 0;
}


