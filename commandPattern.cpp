#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
//this are the structure for the character in the code like it need to move 
struct Character{
    int x;
    int y;
    std::string name;
    Character(std::string _name) : name(_name){}
    // function to update theier x and y position 
    void move(int _x,int _y){
        x = _x;
        y = _y;
    }
};
class Command{
    public:
    virtual ~Command(){}
    virtual void execute(Character &c) = 0;
    virtual void undo(Character &c) = 0;
};

class Move: public Command{
    public:
    void execute(Character &c){
        
        int randomx = rand() %4;// creating a random character for x and y
        int randomy = rand() %4;
        c.move(randomx,randomy);// call the move function on the generated x and y
        x = randomx; // storing it in the private variables x and y
        y = randomy;
        std::cout<<c.name<<" moved " << x << ", "<< y << std::endl;
    }

    void undo(Character &c){
        c.move(-x,-y);//doing the reverse of move by going back to the previous location
        std::cout<<c.name<<" moved " << -x << ", "<< -y << std::endl;
    }
    private:
    int x;
    int y;
};

int main(){
    srand(time(NULL));
    std::vector<Command*> command_queue;
    Character mike("mike"); //created a character
    Move* m1 = new Move; //type of command
    command_queue.push_back(m1);
    Move* m2 = new Move;
    command_queue.push_back(m2);
    Move* m3 = new Move;
    command_queue.push_back(m3);
    Move* m4 = new Move;
    command_queue.push_back(m4);

    for(int i = 0; i<command_queue.size();i++){
        command_queue[i]->execute(mike); // then we executed it
    }
    for(int i = command_queue.size()-1 ; i> -1 ;i--){
        command_queue[i]->undo(mike); // then we executed it
    }
    
    return 0;
}