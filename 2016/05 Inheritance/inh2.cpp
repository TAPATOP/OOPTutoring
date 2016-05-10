#include <iostream>

using namespace std;

class A {
    public:
        int a=5;
        void f() {
            cout<<"I am A\n";
        }

};

class B : public A {
    public: 
        void f() {
            A::f();
            cout<<"I am B\n";
        }
};

int main() {
    B b;
    b.f();
    return 0;
}
