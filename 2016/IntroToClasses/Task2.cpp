#include<iostream>
#include<cstring>

using namespace std;

class Person {
private:
    char *m_name;
    int m_age;
    bool m_gender;
public:
    Person() {
        m_name = nullptr;
        m_age = 0;
        m_gender = 0;
    }
    Person(char *name, int age, bool gender) {
        m_name = new char [strlen(name)];
        strcpy(m_name, name);
        m_age = age;
        gender = gender;
    }
    const char* GetName() const {
        return m_name;
    }
    void SetName(char *name) {
        delete [] m_name;
        m_name = new char[strlen(name)];
        strcpy(m_name, name);
    }
    void SetGender(bool gender) {
        m_gender = gender;
    }
    bool GetGender() {
        return m_gender;
    }
    void SetAge(int age) {
        m_age = age;
    }
    int GetAge() {
        return m_age;
    }
    ~Person() {
        delete [] m_name;
    }
};


int main() {
    f();
}
