#ifndef STRING_H
#define STRING_H

#include <iostream>

namespace MString {

    typedef unsigned int uint;

    class String {
    public:
        String();
        String(const char*);
        String(const String&);
        String(String&&);
        uint size();
        friend std::ostream& operator<< (std::ostream&, const String&);
        friend std::istream& operator>> (std::istream&,  String&);
        String& operator+= (const String&);
        String& operator=(const String&);
        String& operator=(String&&);
        String& operator=(const char*);
        char& operator[] (const int);
        friend String operator+(const String&, const String&);
        friend bool operator== (const String&, const String&);
        friend bool operator!= (const String&, const String&);
        friend bool operator> (const String&, const String&);
        friend bool operator< (const String&, const String&);
        friend bool operator>= (const String&, const String&);
        friend bool operator<= (const String&, const String&);
        ~String();
    private:
        static void copy_char_arr(char*, char*, int = 0, uint = 0);
        static uint get_char_arr_length(const char*);
        static short compare(const String&, const String&);
        void resize(uint);
        void set(const char*, uint = 0);
        uint m_size = 0;
        char *m_string = nullptr;
    };
}

#endif // STRING_H
