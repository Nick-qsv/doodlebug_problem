#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int ROWS = 20;
const int COLS = 20;

void generate_empty_map(string (&grid)[ROWS][COLS]);

//OOP Design
//Order of actions:
//Enter is pressed
//Iterate through each doodlebug and take the following actions:
//Check if there is an ant in the cell above, below, right left
    //if yes then move to that cell
    //kill the ant in that cell
    //set ant eaten counter to 0 ()
    //add 1 to survival counter
        //check if survival counter == 8
        //if yes then spawn new doodlebug
        //if no then nothing
//Check if there is a doodlebug or goes off the grid in cell l,r,a,b
    //stay in current cell if yes
    //change x,y pos if no
    //add 1 to ant eaten counter
        //if ant eaten counter == 3 then "kill" doodlebug
    //add 1 to survival counter
        //check if survival counter == 8
        //if yes then spawn new doodlebug
        //if no then nothing
//Iterate through each ant and take the following actions
//Try to move to a cell
    //if occupied then stay
//add 1 to breed counter
    //if breed counter == 3
    //check if u is empty if not then down if not then left if not then right
    //if one is empty then place new ant into that cell
    //add new ant to the array of ants.. probably needs to be a vector
    //breed counter == 0
//

//Class Organism (Super Class)
class Organism{
public:
    virtual void move(int x, int y) = 0;
    virtual void breed() = 0;
    bool valid_move(int x, int y) {
        return (x > -1 && x < 21 && y > -1 && y < 21);
    }
    //Alive Get Set
    void setAlive(bool tf){alive = tf;}
    bool getAlive() const{return alive;}

    //X Get Set
    int getX() const{return x_pos;}
    void setX(int x_new){x_pos = x_new;}
    
    //Y Get Set
    int getY() const{return y_pos;}
    void setY(int y_new){y_pos = y_new;}
    
    //BC Get Set
    int getBC() const{ return breed_counter;}
    void add_to_BC(){ breed_counter += 1;}
    
    Organism(int x, int y);
private:
    bool alive;
    int x_pos;
    int y_pos;
    int breed_counter;
};

//default constructor
Organism::Organism(int x, int y) : x_pos(x), y_pos(y), alive(true), breed_counter(0){}

//Class Ant (Sub-Class)
class Ant : public Organism{
public:
    Ant(int x, int y);
    void move(int x, int y) override {
        srand(time(NULL));
        int direction = rand() % 4 + 1;
        // switch(direction){
        //     case 1:
        //     case 2:
        //     case 3:
        //     case 4:
        // }
    }
    void breed()override{

    }
    //Value Get
    string getValue() const { return value; }
private:
    string value;
};

//Ant Constructor
Ant::Ant(int x, int y) : Organism(x,y), value("o"){}


//Class Doodlebug (Sub-Class)
class Doodlebug : public Organism{
public:
    Doodlebug(int x, int y);
    void move(int x, int y) override {
        srand(time(NULL));
        int direction = rand() % 4 + 1;
        // switch(direction){
        //     case 1:
        //     case 2:
        //     case 3:
        //     case 4:
        // }
    }
    void breed()override{

    }

    //AC Get Set
    int getAC(){return alive_counter;}
    void addAC(){alive_counter+=1;}

    //Value Get
    string getValue() const { return value; }
private:
    int alive_counter;
    string value;
};

Doodlebug::Doodlebug(int x, int y) : Organism(x,y), value("X"), alive_counter(0){}


int main(){
    srand(time(NULL));
    vector<Ant> ants;
    vector<Doodlebug> doodlebugs;
    string grid[ROWS][COLS];

    generate_empty_map(grid);
    //randomly place doodlebug instances in the grid
// Randomly place doodlebug instances in the grid
    for (int i = 0; i < 5; i++) {
        int x = rand() % ROWS;
        int y = rand() % COLS;
        Doodlebug d(x, y);
        doodlebugs.push_back(d);
        grid[x][y] = d.getValue();
    }

    // Randomly place ant instances in the grid
    for (int i = 0; i < 100; i++) {
        int x = rand() % ROWS;
        int y = rand() % COLS;
        // Make sure no doodlebug is in the grid already
        if (grid[x][y] == "-") {
            Ant a(x, y);
            ants.push_back(a);
            grid[x][y] = a.getValue();
        } else {
            Ant a(x, y + 1);
            ants.push_back(a);
            grid[x][y + 1] = a.getValue();
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
void generate_empty_map(string (&grid)[ROWS][COLS]){
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            grid[i][j] = "-";
        }
    }
}

