#include "String.h"

using namespace std;

namespace MString {

    void String::copy_char_arr(char* source, char* dest, int from_index, uint size) {
        size = size ? size : get_char_arr_length(source);
        for(uint i = from_index, j = 0; i < from_index + size; i++, j++) {
            dest[i] = source[j];
        }
    }

    String::String(){};

    String::String(const char *input_string) {
        set(input_string);
    }

    String::String(const String &input_string) {
        set(input_string.m_string, input_string.m_size);
    }

    String::String(String&& other) : m_size{other.m_size}, m_string{other.m_string} {
        other.m_string = nullptr;
    }

    uint String::size() {
        return m_size;
    }

    std::ostream& operator<< (std::ostream &out, const String &a) {
        for(uint i = 0; i < a.m_size; i++) {
            out<<a.m_string[i];
        }
        return out;
    }

    std::istream& operator>> (std::istream &in, String &a) {
        uint i = 0, capacity = 8;
        char *input = new char[capacity], c, *temp = nullptr;
        while(c != ' ' && c != '\t' && c != '\n') {
            in.get(c);
            if(i >= capacity) {
                temp = new char[i];
                capacity*= 2;
                String::copy_char_arr(input, temp, 0, i);
                delete [] input;
                input = new char[capacity];
                String::copy_char_arr(temp, input, 0, i);
                delete[] temp;
                temp = nullptr;
            }
            input[i++] = c;
        }
        a.set(input, i-1);
        delete [] input;
        return in;
    }

    String& String::operator= (const char *a) {
        set(a);
        return *this;
    }

    String& String::operator= (const String &a) {
        set(a.m_string, a.m_size);
        return *this;
    }

    String& String::operator= (String &&a) {
        delete[] m_string;
        m_size = a.m_size;
        m_string = a.m_string;
        a.m_string = nullptr;
        return *this;
    }

    String operator+(const String &a, const String &b) {
        uint la = a.m_size, lb = b.m_size;
        char *new_str = new char[la + lb + 1];
        String::copy_char_arr(a.m_string, new_str, 0, la);
        String::copy_char_arr(b.m_string, new_str, la, lb);
        String s(new_str);
        return std::move(s);
    }

    String& String::operator+= (const String& other) { 
    	*this = *this + other;
        return *this;
    }

    bool operator== (const String& a, const String& b) {
        if(!String::compare(a,b)) return true;
        return false;
    }

    bool operator!= (const String& a, const String& b) {
        if(String::compare(a,b)) return true;
        return false;
 
    }

    short String::compare(const String& a, const String& b) {
        if(a.m_string == nullptr && b.m_string == nullptr) return 0;
        if(a.m_string == nullptr) return 1;
        if(b.m_string == nullptr) return -1;
        uint i = 0, min_length = a.m_size <= b.m_size ? a.m_size : b.m_size;
        while(i < min_length && a.m_string[i] == b.m_string[i]) i++;
        if(a.m_string[i] > b.m_string[i]) return 1; //a > b
        if(a.m_string[i] < b.m_string[i]) return -1; //a < b
        if(a.m_size == b.m_size && a.m_size == i) return 0; //a == b
        return -1;
    }

    bool operator> (const String& a, const String& b) {
        if(String::compare(a,b) == 1) return true;
        return false;
    }

     bool operator< (const String& a, const String& b) {
        if(String::compare(a,b) == -1) return true;
        return false;
    }

     bool operator<= (const String& a, const String& b) {
        if(String::compare(a,b) < 1) return true;
        return false;
    }

     bool operator>= (const String& a, const String& b) {
        if(String::compare(a,b) > -1) return true;
        return false;
    }

    char& String::operator[] (const int index) {
        //Not safe if index > 0 || index < 0 exception should be thrown
        //Or implement at(const uint) function
        return m_string[index];
    }

    uint String::get_char_arr_length(const char *s) {
        if(s == nullptr) return 0;
        uint l = 0;
        while(s[l]) {
            l++;
        }
        return l;
    }

    void String::resize(uint new_size) {
        delete[] m_string;
        m_string = new char[new_size+1];
        m_size = new_size;
    }

    void String::set(const char *s, uint size) {
        size = size ? size : get_char_arr_length(s);
        resize(size);
        for(uint i = 0; i < size; i++) {
            m_string[i] = s[i];
        }
    }

    String::~String() {
        delete[] m_string;
    }
}
