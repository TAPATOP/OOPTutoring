#include "String.h"

namespace MString {

    void String::CopyCharArr(char* source, char* dest, int fromIndex, uint size) {
        size = size ? size : GetCharArrLength(source);
        for(uint i = fromIndex, j = 0; i < fromIndex + size; i++, j++) {
            dest[i] = source[j];
        }
    }

    String::String(){};

    String::String(const char *inputString) {
        Set(inputString);
    }

    String::String(String &inputString) {
        Set(inputString.m_string, inputString.m_size);
    }

    int String::Size() {
        return m_size;
    }

    std::ostream& operator<< (std::ostream &out, const String &a) {
        for(uint i = 0; i < a.m_size; i++) {
            out<<a.m_string[i];
        }
        return out;
    }

    std::istream& operator>> (std::istream &in, String &a) {
        char *input = new char[8], c, *temp = nullptr;
        int i = 0;
        while(c != ' ' && c != '\t' && c != '\n') {
            in.get(c);
            if(i >= 8) {
                temp = new char[i];
                String::CopyCharArr(input, temp, 0, i);
                delete [] input;
                input = new char[i*2];
                String::CopyCharArr(temp, input, 0, i);
                delete temp;
                temp = nullptr;
                i*=2;
            }
            input[i] = c;
            i++;
        }
        a.Set(input, i-1);
        delete [] input;
        return in;
    }

    String& String::operator= (const char *a) {
        Set(a);
        return *this;
    }

    String& String::operator= (const String &a) {
        Set(a.m_string, a.m_size);
        return *this;
    }

    String operator+(const String &a, const String &b) {
        unsigned int la = a.m_size, lb = b.m_size;
        char *newStr = new char[la+lb];
        String::CopyCharArr(a.m_string, newStr, 0, la);
        String::CopyCharArr(b.m_string, newStr, la, lb);
        String s(newStr);
        return s;
    }

    String& String::operator+= (const String& other) {
        uint newSize = m_size + other.m_size, oldSize = m_size;
        char *old = new char[oldSize];
        String::CopyCharArr(m_string, old, 0, oldSize);
        Resize(newSize);
        String::CopyCharArr(old, m_string, 0, oldSize);
        String::CopyCharArr(other.m_string, m_string, oldSize, other.m_size);
        return *this;
    }

    bool operator== (const String& a, const String& b) {
        if(!String::Compare(a,b)) return true;
        return false;
    }

    bool operator!= (const String& a, const String& b) {
        return !(a==b);
    }

    short String::Compare(const String& a, const String& b) {
        uint i = 0, minLength = a.m_size <= b.m_size ? a.m_size : b.m_size;
        while(i < minLength && a.m_string[i] == b.m_string[i]) i++;
        if(a.m_string[i] > b.m_string[i]) return 1; //a > b
        if(a.m_string[i] < b.m_string[i]) return -1; //a < b
        if(a.m_size == b.m_size && a.m_size == i) return 0; //a == b
        return -1;
    }

    bool operator> (const String& a, const String& b) {
        if(String::Compare(a,b) == 1) return true;
        return false;
    }

     bool operator< (const String& a, const String& b) {
        if(String::Compare(a,b) == -1) return true;
        return false;
    }

     bool operator<= (const String& a, const String& b) {
        if(String::Compare(a,b) < 1) return true;
        return false;
    }

     bool operator>= (const String& a, const String& b) {
        if(String::Compare(a,b) > -1) return true;
        return false;
    }

    char& String::operator[] (const int index) {
        //Not safe if index > 0 || index < 0 exception should be thrown
        return m_string[index];
    }

    uint String::GetCharArrLength(const char *s) {
        uint l = 0;
        while(s[l]) {
            l++;
        }
        return l;
    }

    void String::Resize(uint newSize) {
        delete[] m_string;
        m_string = new char[newSize];
        m_size = newSize;
    }

    void String::Set(const char *s, uint size) {
        size = size != 0 ? size : GetCharArrLength(s);
        Resize(size);
        for(uint i = 0; i < size; i++) {
            m_string[i] = s[i];
        }
    }

    String::~String() {
        delete[] m_string;
    }
}
