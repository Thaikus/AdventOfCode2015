//https://adventofcode.com/2015/day/3
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){
  ifstream myfile;
  int x, y, a, b, sum, robo;
  char pos;

  //Opening file and checking if it is opened
  myfile.open("Day3Input.txt");
  if(!myfile){
    cout << "File was not opened correctly\n";
    getchar();
    return 0; //Does this exit?
  }

  //Using a 2D array & initializing it
  int posArr [500][500];

  //Initializing Array values
  for (x = 0; x < 500; x++)
    for (y = 0; y < 500; y++){
      posArr [x][y] = 0;
    }
  x = y = a = b = 250; //Starting position
  robo = -1; //If this value is even, use xy, else ab
  while(myfile >> pos){
    robo++;
    //'Mapping' out the traveled locations
    if(pos == '<'){//left
      if((robo % 2) == 0){//even
        x--;
        posArr[x][y] = 1;
      }
      else {
        a--;
        posArr[a][b] = 1;
        }

    }
    else if (pos == '>'){//right
      if((robo % 2) == 0){//even
        x++;
        posArr[x][y] = 1;
      }
      else {
        a++;
        posArr[a][b] = 1;
        }
    }
    else if (pos == '^'){//up
      if((robo % 2) == 0){//even
        y++;
        posArr[x][y] = 1;
      }
      else {
        b++;
        posArr[a][b] = 1;
        }
    }
    else if(pos == 'v'){//down
      if((robo % 2) == 0){//even
        y--;
        posArr[x][y] = 1;
      }
      else {
        b--;
        posArr[a][b] = 1;
        }
    }
    else cout << "Invalid Input\n";

  }

  for (x = 0; x < 500; x++)
    for (y = 0; y < 500; y++){
      sum += posArr[x][y];
    }
    cout << sum << endl;

  /*//Part 1
  posArr [x][y] = 1;//The starting position has a one
  while (myfile >> pos){//Reading from the file
    //'Mapping' out the traveled locations
    if(pos == '<'){//left
      x--;
      posArr[x][y] = 1;
    }
    else if (pos == '>'){//right
      x++;
      posArr[x][y] = 1;
    }
    else if (pos == '^'){//up
      y++;
      posArr[x][y] = 1;
    }
    else if(pos == 'v'){//down
      y--;
      posArr[x][y] = 1;
    }
    else cout << "Invalid Input\n";


    //cout << pos; //Checking the input
  }//End of While Loop
  for (x = 0; x < 500; x++)
    for (y = 0; y < 500; y++){
      sum += posArr[x][y];
    }
    cout << sum << endl;
    *///End of Part 1






  getchar();
  return 0;
}
