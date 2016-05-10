#include <iostream>
#include <string>
#include <vector>

using namespace std;

class IAnimal {
    public:
        IAnimal() {}
        IAnimal(string name) : m_name{name} {}
        virtual void MakeNoise()=0;
        virtual ~IAnimal(){}
    private:
        string m_name="No name";
};

class Cat : public IAnimal {
    public:
        virtual void MakeNoise() {
            cout<<"Meow"<<endl;
        }
        ~Cat() {
            cout<<"Die\n";
            delete[] a;
        }
    private:
        int *a = new int[10000];
};

class Dog : public IAnimal {
    public:
        virtual void MakeNoise() {
            cout<<"Woof"<<endl;
        }
};

int main() {
    IAnimal *malkoKote = new Cat;
    IAnimal *Sharo = new Dog;
    vector<IAnimal*> v;
    v.push_back(malkoKote);
    v.push_back(Sharo);
    for(IAnimal* a : v) {
        a->MakeNoise();
    }
    delete malkoKote;
    return 0;
}
