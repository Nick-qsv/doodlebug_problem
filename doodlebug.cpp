#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

//OOP Design

//Class Organism (Super Class)
class Organism{
public:
    string value = "n";
    bool valid_move(int x, int y){
        if(x>-1 && x < 21 && y >-1 && y <21){
            true;
        } else{
            false;
        }
    }

    void move(int x, int y){
        srand(time(NULL));
        int direction = rand() % 4 + 1;
        switch(direction){
            
        }
        
    }
};

//Class Ant (Sub-Class)
class Ant : public Organism{
public:
    string value = "o";
    int x_pos = 0;
    int y_pos = 0;
};
//Class Doodlebug (Sub-Class)
class Doodlebug : public Organism{
public:
    string value = "X";
    int x_pos = 0;
    int y_pos = 0;
};

const int ROWS = 20;
const int COLS = 20;


int main(){
    Ant a[100];
    Doodlebug d[5];
    string grid[ROWS][COLS];
    srand(time(NULL));


    //initalize all elements in the grid to 0
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            grid[i][j] = " ";
        }
    }

    //randomly place doodlebug instances in the grid
    for (int i = 0; i < 5; i++){
        int  x = rand() % ROWS;
        int y = rand() % COLS;
        grid[x][y] =d[i].value;
        d[i].x_pos = x;
        d[i].y_pos = y;
    }

    //randomly place ant instances in the grid
    for (int i = 0; i < 100; i++){
        int x = rand() % ROWS;
        int y = rand() % COLS;
        //make sure no doodlebug in the grid already
        if(grid[x][y] == " "){
            grid[x][y] = a[i].value;
            a[i].x_pos = x;
            a[i].y_pos = y;
        } else{
            grid[x][y+1] = a[i].value;
            a[i].x_pos = x;
            a[i].y_pos = y;
        }
    }

    //print the grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }

  return 0;
}

//
//so now we need a loop going
//do we need multiple functions?

