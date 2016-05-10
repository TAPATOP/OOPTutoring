#include <iostream>

using namespace std;

class A {
    public:
        int a;
        A() {
            cout<<"const A\n";
        }
        A(int a) {
            cout<<"setting a"<<endl;
            this->a = a;
        }
        ~A() {
            cout<<"dest A\n";
        }
};
class B : virtual public A{
    public:
        int b;
        B() {
            cout<<"const B\n";
        }
        B(int b) {
            cout<<"Setting b\n";
            this->b = b;
        }
        ~B() {
            cout<<"dest B\n";
        }
};
class C : virtual public A{
    public:
        int c;
        C() {
            cout<<"const C\n";
        }
        C(int c) {
            cout<<"Setting C\n";
            this->c = c;
        }
        ~C() {
            cout<<"dest C\n";
        }
};

class D : public C, public B {
    public:
        int d;
        D() {
            cout<<"const D\n";
        }
        D(int a, int b, int c, int d) : A(a), C(c), B(b), d{d} {
            cout<<"Setting D"<<endl;
        }
        ~D() {
            cout<<"dest D\n";
        }
};
int main() {
    D d(1,2,3,4);
    /*d.C::a = 5;
    d.B::a = 1;
    cout<<d.C::a<<" "<<d.B::a<<endl;*/
    return 0;
}
