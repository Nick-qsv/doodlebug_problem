#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int ROWS = 20;
const int COLS = 20;


//OOP Design
//Order of actions:
//Enter is pressed

//
class Ant;
class Doodlebug;

//Class Organism (Super Class)
class Organism{
public:
    virtual void move(string (&grid)[ROWS][COLS], vector<Ant>& ants) = 0;
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
    
    //Value Get Set
    string getValue()const {return value;}
    void setValue(string val){ value = val;}
    Organism();
private:
    bool alive;
    int x_pos;
    int y_pos;
    int breed_counter;
    string value;
};

//default constructor
Organism::Organism() : x_pos(-1), y_pos(-1), alive(true), breed_counter(0), value("-"){}


//Class Ant (Sub-Class)
class Ant : public Organism{
public:
    Ant();
    Ant(int x, int y);
    //need the ant vector and 
    void move(string (&grid)[ROWS][COLS], vector<Ant>& ants) {
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

};

//Ant Constructor
Ant::Ant() : Organism() { setValue("o ");}
Ant::Ant(int x, int y) : Organism() { setX(x); setY(y); setValue("o "); }

//Class Doodlebug (Sub-Class)
class Doodlebug : public Organism{
public:
    Doodlebug();
    Doodlebug(int x, int y);
    void move(string (&grid)[ROWS][COLS], vector<Ant>& ants) override {
        //
        int x = this->getX();
        int y = this->getY();
        if(grid[x+1][y] == "a"){
            //we found an ant, set the grid to a d
            grid[x+1][y] = "d";
            //change the x in the vector to the correct x
            this->setX(x+1);
            //need to change the grid of ants and the vector of ants and the grid of doodlebugs positions as well though...
            //how would you even know which ant it is?
            //i guess iterate over each?
            for(int i = 0;i <ants.size();i++){
                if(ants[i].getX() == x+1 && ants[i].getY() == y){
                    ants[i].setAlive(false);
                }
            }
            
        }else if(grid[x-1][y] == "a"){
            grid[x-1][y] = "d";
            this->setX(x-1);
        }else if(grid[x][y+1] == "a"){
            grid[x][y+1] = "d";
            this->setY(y+1);
        }else if(grid[x][y-1] == "a"){
            grid[x][y-1] = "d";
            this->setY(y-1);
        }else{
            srand(time(NULL));
            int direction = rand() % 4 + 1;
            // switch(direction){
            //     //up
            //     case 1:
            //     //down
            //     case 2:
            //     //left
            //     case 3:
            //     //right
            //     case 4:
            // }
        }
        //this is random move, but first need to check if ant in cell above below or not..

    }
    void breed()override{

    }

    //AC Get Set
    int getAC(){return alive_counter;}
    void addAC(){alive_counter+=1;}


private:
    int alive_counter;

};  

Doodlebug::Doodlebug() : Organism(), alive_counter(0){setValue("X ");}
Doodlebug::Doodlebug(int x, int y) : Organism(), alive_counter(0){setValue("X "); setX(x); setY(y);}


int main(){
    srand(time(NULL));
    vector<Ant> ants;
    vector<Doodlebug> doodlebugs;
    Ant ant_grid[ROWS][COLS];
    Doodlebug doodlebug_grid[ROWS][COLS];
    string organism_type[ROWS][COLS];
    string input;
    int time_step = 0;
    // Randomly place doodlebug instances in the doodlebug grid
    for (int i = 0; i < 5; i++) {
        int x = rand() % ROWS;
        int y = rand() % COLS;
        if (organism_type[x][y].empty()) {
            Doodlebug d(x, y);
            doodlebugs.push_back(d);
            doodlebug_grid[x][y] = d;
            organism_type[x][y] = "d";
        } else {
            --i;
        }
    }
    // Randomly place ant instances in the ant grid
    for (int i = 0; i < 100; i++) {
        int x = rand() % ROWS;
        int y = rand() % COLS;
        if (organism_type[x][y].empty()) {
            Ant a(x, y);
            ants.push_back(a);
            ant_grid[x][y] = a;
            organism_type[x][y] = "a";
        } else {
            --i;
        }
    }
 
    cout<<"World at Time "<<time_step<<":"<<endl;
    cout<<endl;
    //print the grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (organism_type[i][j] == "d") {
                cout << doodlebug_grid[i][j].getValue();
            } else if (organism_type[i][j] == "a") {
                cout << ant_grid[i][j].getValue();
            } else {
                cout << "- ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Press ENTER to continue"<<endl;
    while(true){
        getline(cin,input);
        if(input.empty()){
            //So we have 3 data structures:
            //Vector of Bugs/Ants
            //Grid of Bugs/Ants
            //String Grid...
            //iterate through the doodlebug vector..
            // for(int i = 0;i<doodlebugs.size();i++){
            //     doodlebugs[i].move(organism_type,ants);
            // }
            time_step+=1;
        }else{
            break;
        }
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
        
    }

  return 0;
}



