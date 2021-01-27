#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(){

  ifstream myFile;
  myFile.open("day5Input.txt");
  if(!myFile){
    cout << "File did not open correctly, exiting now\n";
    return 0;
  }

  //Variables for project
  //Rules for Nice string: 3 vowels : aeiou [Duplicates count multiple times]
  //Contains any repeated letter
  //DOES NOT contain strings: ab, cd, pq, xy
  string input, test; //reading the string
  bool vowel, repeat, nonBan;
  int vCount, goodStr;
  char letter1, letter2; //repeated letter
  vCount = goodStr = 0;

  string::iterator it1;
  while (myFile >> input){
    //cout << "String test: " << input << endl;
    //For sure, every string is being read
    it1=input.begin();
    it1++;
    //resetting the value of the conditions
    vowel = repeat = nonBan = 0;
    vCount = 0;

  //Reading every character
  for (string::iterator it=input.begin(); it != input.end(); it++){
    letter1 = *it;
    //cout << "current letter:" << letter1 << endl;
    if(letter1 ==  'a'){
      //cout << "vowel: " << letter1 << endl;
      vCount += 1;
    }
    else if (letter1 ==  'e'){
      //cout << "vowel: " << letter1 << endl;
      vCount += 1;
    }
    else if (letter1 ==  'e'){
      //cout << "vowel: " << letter1 << endl;
      vCount += 1;
    }
    else if (letter1 ==  'i'){
      //cout << "vowel: " << letter1 << endl;
      vCount += 1;
    }
    else if (letter1 ==  'o'){
      //cout << "vowel: " << letter1 << endl;
      vCount += 1;
    }
    else {
      //cout << "The letter: " << *it << " is not a vowel\n";
    }

    //condition 2
    if (*it1 == *it){
      //cout << "Repeat here: " << *it << " " << *it1 << endl;
      repeat = true;
    }

    //condition 3
    if (
    (*it == 'a' && *it1 == 'b') ||
    (*it == 'c' && *it1 == 'd') ||
    (*it == 'p' && *it1 == 'q') ||
    (*it == 'x' && *it1 == 'y')
  ){
    nonBan = false;
    cout << "Input: " << input << endl;
    //cout << "Here is ab/cd/pq/xy" << endl;
    cout << *it << *it1 << endl;
  }
  else nonBan = true;

    it1++; //Increasing the second iterator by 1
    //Warning, what happens when it1 goes to null? Could be an issue later!!!

  }//end of for loop

  //Condition 1
  if (vCount >= 3)
    vowel = true;

  //Displaying and counting the valuew of string that are good
  if (vowel && repeat && nonBan){
    goodStr += 1;
    cout << "This string passed! " << input << endl;
  }

  /*
  cout << "Vowel: " << vowel << endl;
  cout << "Repeat: " << repeat << endl;
  cout << "nonBan: " << nonBan << endl;
  cout << "goodStr: " << goodStr << endl;
  */
  //getchar();
}//end of while loop



  cout << "Good Strings: " << goodStr << endl;
  myFile.close();//Remember to close the file at the end
  getchar();
  return 0;
}
