#include<iostream>
#include<csignal>
#include<fstream>
int main(){
//https://adventofcode.com/2015/day/1

    char ch;
    int floorNum, basement;
    floorNum = basement = 0;
    std::cout << "Hello world \n"; //Test

    //Read from txt file
    //'(' -> go up one floor
    //')' -> go down one floor
    //Use include<fstream> for reading from files
    //1.Intialize txt pointer | 2.Open file | 3.Read file | 4.Close file
    //https://www.cplusplus.com/doc/tutorial/files/
    std::ifstream myfile; //ifstream: Stream class to read from files
    myfile.open("day1p1In.txt");//2. Open the file
    if(!myfile){
      std::cout << "File did not open correctly!\n"; //Checking file status
    }
    else {
      std::cout << "File opened succefully\n";
      while(!myfile.eof()){ //While not End Of File
        myfile.get(ch);
        std::cout << floorNum << std::endl; //Check what is being read
        if (floorNum == -1){
          std::cout << "Basement Position: " << basement << std::endl;
          std::raise(SIGINT); //For part 2
        }
        if (ch == '('){
          floorNum++; //Incrementing by 1
          basement++;
        }
        else if (ch == ')'){
          floorNum--; //Decrementing by 1
          basement++;
        }
      }//end of while
    }//end of else
    std::cout << "Floor number: " << floorNum << std::endl; //The value we want
    myfile.close();//4. close the file
    std::raise(SIGINT); //Alternative to system("pause");







    return 0; //exit status
}
