#include<string>
#include<memory>//to replace raw pointer of IGameObject with smart pointer shared_ptr<IGameObject>
#include<iostream>

class IGameObject{
public:
    virtual ~IGameObject(){}
    virtual void Update() = 0;
    virtual void Render() = 0;

};

class Plane : public IGameObject{
public:
    Plane() {}
    void Update() {}
    void Render() {}

};
class Boat :  public IGameObject{
public:
    Boat() {}
    void Update() {}
    void Render() {}

};

enum class ObjectType {PLANE,BOAT};

class FactoryGameObject{
public:
    static std::shared_ptr<IGameObject> CreateGameObject(ObjectType type){
    if(ObjectType::PLANE == type){
        s_plane++;
        return std::make_shared<Plane>();
    }else if(ObjectType::BOAT == type){
        s_boat++;
        return std::make_shared<Boat>();
    }return nullptr;
    }

    static void PrintCount(){
        std::cout<<"plenes: "<<s_plane <<std::endl;
        std::cout<<"boat: "<<s_boat <<std::endl;
    }
private:
    FactoryGameObject(){}
    ~FactoryGameObject(){}
    FactoryGameObject(const FactoryGameObject& o){}
    static int s_plane;
    static int s_boat;

};
int FactoryGameObject::s_boat = 0;
int FactoryGameObject::s_plane = 0;


int main(){

    // std::shared_ptr<IGameObject> myObject = MakeGameObjectFactory(ObjectType::PLANE);
    // std::shared_ptr<IGameObject> myObject2 = MakeGameObjectFactory(ObjectType::BOAT);
    std::shared_ptr<IGameObject> myObject = FactoryGameObject::CreateGameObject(ObjectType::PLANE);
    std::shared_ptr<IGameObject> myObject2 =FactoryGameObject::CreateGameObject(ObjectType::BOAT);
    std::shared_ptr<IGameObject> myObject3 =FactoryGameObject::CreateGameObject(ObjectType::BOAT);

    FactoryGameObject::PrintCount();

    return 0;
}