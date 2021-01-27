//https://adventofcode.com/2015/day/2
#include<iostream>
#include<csignal>
#include<fstream>
using namespace std;
int main(){

//surface area of box = 2lw + 2wh + 2hl
//                    = 2xy + 2yz + 2xz
//Length, Width, Height
int x, y, z, sum, small1, small2;
x = y = z = sum = small1 = small2 = 0;
char sep;
  ifstream myfile; //ifstream = write only
  myfile.open("day2Input.txt");
  if(!myfile){//if the file didn't open correctly
    cout << "File did not open correctly!\n";
  }
  else {
    while (myfile >> x >> sep >> y >> sep >> z){
    //https://stackoverflow.com/questions/20739453/using-getline-with-file-input-in-c
     //HOW TO READ MULTIPLE DATA TYPES IN ONE LINE!!!

    std::cout << "X: " << x << std::endl; //For testing purposes
    std::cout << "Y: " << y << std::endl;
    std::cout << "Z: " << z << std::endl;
    if ((x >= y) & (x >= z)){
      small1 = y;
      small2 = z;
    }
    if ((y >= x) & (y >= z)){
      small1 = x;
      small2 = z;
    }
    if ((z >= y) & (z >= x)){
      small1 = y;
      small2 = x;
    }
    sum += (x * y * z) + (2 * small1 + 2 * small2);
  }
/* //Part 1
    //Extra slack = smallest sides multiplied together
    sum += ((2 * x * y) + (2 * y * z) + (2 * x * z)); //Main multipulication
    if ((x >= y) & (x >= z)){
      small1 = y;
      small2 = z;
    }
    if ((y >= x) & (y >= z)){
      small1 = x;
      small2 = z;
    }
    if ((z >= y) & (z >= x)){
      small1 = y;
      small2 = x;
    }
    sum += small1 * small2;

  }
  *///End of part 1
}

  cout << sum;

  //std::cout << "Hello World!\n";
  getchar();
  //std::raise(SIGINT);
  return 0;
}
