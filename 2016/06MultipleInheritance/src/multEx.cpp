#include <iostream>

using namespace std;

class A {
    public:
        A() {
            cout<<"A\n";
        }
        ~A() {
            cout<<"Dest A\n";
        }
};

class APrime : public A {
    public:
        APrime() {
            cout<<"APrime\n";
        }
        ~APrime() {
            cout<<"Dest APrime\n";
        }

};

class B {
    public:
        B() {
            cout<<"B\n";
        }
        ~B() {
            cout<<"Dest B\n";
        }
};

class C : public APrime, public B {
    public:
        C() {
            cout<<"C\n";
        }
        ~C() {
            cout<<"Dest C\n";
        }
};
int main() {
    C c;
    return 0;
}
