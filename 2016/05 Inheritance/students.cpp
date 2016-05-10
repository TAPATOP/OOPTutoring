#include <iostream>
#include <cstring>

using namespace std;

class Person {
    private:
        string m_name;
        int m_age = 0;
        int m_EGN = 0;
    public:
        Person() {}
        Person(string name, int age, int EGN) :
            m_name{name}, m_age{age}, m_EGN{EGN} {}
        string GetName() {
            return m_name;
        }
        int GetAge() {
            return m_age;
        }
        int GetEGN() {
            return m_EGN;
        }
        void SetName(string name) {
            m_name = name;
        }
        void SetAge(int age) {
            m_age = age;
        }
        void SetEGN(int EGN) {
            m_EGN = EGN;
        }
        void f() {
            cout<<ID<<endl;
        }
    protected:
        int ID=123;
};

class Student : protected Person {
    private:
        int m_FN=-1;
    public: 
        Student() {}
        Student(string name, int age, int EGN, int FN) : 
            Person(name, age, EGN), m_FN{FN} {}
        void SetFN(int FN) {
            m_FN = FN;
        }
        int GetFN() {
            return m_FN;
        }
        void f() {
            cout<<ID<<endl;
        }
};

int main() {
    Student a("Pesho", 1, 2, 3);
    Person b("Gosho", 4, 5);
    //cout<<"Name: "<<a.GetName()<<" Age: "<<a.GetAge()<<" EGN: "<<a.GetEGN()<<" FN: "<<a.GetFN()<<endl;
}
