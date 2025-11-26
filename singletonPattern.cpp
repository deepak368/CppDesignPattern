#include<iostream>
#include<vector>

class Logger{
    public:
    static Logger &GetInstance(){//return the current in stance that is declared in private as static
        static Logger* s_instance = new Logger;
        return *s_instance;
    }
    void printMessage(){
        std::cout<<"Acessing the log" <<std::endl;
        for(auto &e : m_messages){
            std::cout<<e<<std::endl;
        }
    }
    void addMessages(std::string s){
        m_messages.push_back(s);
    }
    private:
    Logger(){
        std::cout << "Logger wae created\n";
    }
    ~Logger(){
        std::cout<<"Logger was distroyed\n";
    }
    
    std::vector<std::string>m_messages;

};
// Logger* Logger::s_instance = nullptr;

int main(){
    Logger::GetInstance().addMessages("hello msg1");
    Logger::GetInstance().addMessages("hello msg2");
    Logger::GetInstance().addMessages("hello msg3");
    Logger::GetInstance().printMessage();
    return 0;
}