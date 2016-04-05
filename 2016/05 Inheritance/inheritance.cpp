#include<iostream>

using namespace std;

class Base {
    private:
        int basePrivate = 0;
    public:
        Base() {
            cout<<"Constructing Base\n";
        }
        Base(int val):basePrivate{val} {
            cout<<"constructing base\n";
        }
        int getBasePrivate() {
            return basePrivate;
        }
        void f() {
            cout<<"I am from base\n";
        }
        ~Base() {
            //cout<<"Destructing Base\n";
        }
};

class Inherit : public Base {
    private:
        int inheritVal = 1;
    public:
        Inherit(){
            cout<<"Constructing Inherit\n";
        }
        Inherit(int val) :inheritVal{val}{}
        
        void f() {
            cout<<"I am from Inherit\n";
        }

        ~Inherit() {
            cout<<"Destructing Inherit\n";
        }
};

int main() {
    Base b;
    cout<<endl;
    Inherit a;
}
