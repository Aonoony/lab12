#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    srand(time(0));
    string grade;
    cout << "Press Enter 3 times to reveal your future.";
    cin.get();
    cin.get();
    cin.get();
    if(rand()%9 == 0){
        grade = "A";
    }else if(rand()%9 == 1){
        grade = "B+";
    }else if(rand()%9 == 2){
        grade = "B";
    }else if(rand()%9 == 3){
        grade = "C+";
    }else if(rand()%9 == 4){
        grade = "C";
    }else if(rand()%9 == 5){
        grade = "D+";
    }else if(rand()%9 == 6){
        grade = "D";
    }else if(rand()%9 == 7){
        grade = "F";
    }else{
        grade = "W";
    }
    cout << "You will get " << grade <<" in this 261102.";
    return 0;
}