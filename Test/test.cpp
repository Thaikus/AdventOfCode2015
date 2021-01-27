#include<iostream>
#include<string>
using namespace std;

int main(){

  string input;
  bool banned;
  input = "asdfhjkla";
  string::iterator it1;
  it1 = input.begin();
  it1++;
  for (string::iterator it=input.begin(); it != input.end(); it++){


    cout << "it: " << *it << endl;
    cout << "it1: " << *it1 << endl;
  if (
  (*it == 'a' && *it1 == 'b') ||
  (*it == 'c' && *it1 == 'd') ||
  (*it == 'p' && *it1 == 'q') ||
  (*it == 'x' && *it1 == 'y')
){
  banned = true;
}
it1++;
}
  if (banned){

    cout << "This string has banned" << endl;
  }
   return 0;
 }
