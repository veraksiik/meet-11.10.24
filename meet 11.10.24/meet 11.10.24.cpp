#include <iostream>
//полиморфизм технология изменчивого поведения программы
// при сохранении линейной структуры кода
// 
// при полиморфмных вызовах программа расчитывая на код описанный в род классе фактически будет 
// выполнять код методов описанных в классах наследников
//
// для того чтобы полиморфизм работал должна существовать виртуальная таблица типов
// 
//


//class Base {
//public:
//    Base() {
//        std::cout << "constructor\n";
//    }
//    virtual ~Base() {
//        std::cout << "destroyed\n";
//    }
//    //ключевое слово virtual создаёт виртуальную таблицу типов в программе
//    virtual void Print()const 
//    {
//        std::cout << "Hello World!\n";
//    }
//
//};
//
//class Derived :public Base {
//public:
//    Derived() {
//        std::cout << "DERconstructor\n";
//    }
//    ~Derived() {
//        std::cout << "DERdestroyed\n";
//    }
//
//
//    void Print()const override 
//    {
//        std::cout << "kapec\n";
//    }
//
//};
//
////полиморфный вызов возможен тогда и только тогда когда щбъект в пограмме передаётся по ссылкам и указателям
//void F00(Base &a) {
//    a.Print();
//}
//если передача ведётся по параметру то происхожит операция upcast которая отсекает все свойства наследных классов и создаёт новый объект
//базового на их основе

class Plants {
public:
    Plants(){
       std::cout << "constructor\n";

       name_="Romashka";
       size_="small";
       high_=5;
    }
    ~Plants() {
        std::cout << "destroyed\n";
    }
    Plants(std::string name, std::string size, int high) {
        name_ = name;
        size_ = size;
        high_ = high;

    }
    void SetName(std::string name) {
        name_ = name;  
    }
    void SetSize(std::string size) {
        size_ = size;
    }
    void SetHigh(int high) {
        high_ = high;
    }
    std::string GetName() {
        return name_;
    }
    std::string GetSize() {
        return size_;
    }
    int GetHigh() {
        return high_;
    }
private:
    std::string name_;
    std::string size_;
    int high_;
};

class Bush :public Plants {
public:
    Bush() {
        std::cout << "constructor\n";
    }
    ~Bush() {
        std::cout << "destroyed\n";
    }
    Bush(std::string name_, std::string size_, int high_)
        :Plants(name_,"small", high_)
    {}
private:
};
    
class Tree :public Plants {
public:
    Tree() {
        std::cout << "constructor\n";
    }
    ~Tree() {
        std::cout << "destroyed\n";
    }
    Tree(std::string name_, std::string size_, int high_)
        :Plants(name_, "big", high_)
    {}
private:
    std::string size;
};
        
    

int main()
{
   /* Base  *obj1 = new Base;
    obj1->Print();

    Base *obj2=new Derived;
    obj2->Print();

    F00(*obj1);
    F00(*obj2);

    delete obj1;
    delete obj2;*/

    Plants plants;
    Bush bush;
    Tree tree;
    return 0;
}

