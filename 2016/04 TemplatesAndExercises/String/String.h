#ifndef STRING_H
#define STRING_H

#include <iostream>

namespace MString {
    typedef unsigned int uint;
    class String {
    public:
        String();
        String(const char*);
        String(String&);
        int Size();
        friend std::ostream& operator<< (std::ostream&, const String&);
        friend std::istream& operator>> (std::istream &in, String &a);
        String& operator+= (const String&);
        String& operator=(const String&);
        String& operator=(const char*);
        char& operator[] (const int);
        friend String operator+(const String&, const String&);
        friend bool operator== (const String&, const String&);
        friend bool operator!= (const String&, const String&);
        friend bool operator> (const String&, const String&);
        friend bool operator< (const String&, const String&);
        friend bool operator>= (const String&, const String&);
        friend bool operator<= (const String&, const String&);
        static void CopyCharArr(char*, char*, int = 0, unsigned int = 0);
        ~String();
    private:
        char *m_string = nullptr;
        uint m_size = 0;
        static uint GetCharArrLength(const char*);
        void Resize(uint);
        static short Compare(const String&, const String&);
        void Set(const char*, uint = 0);

    };
}

#endif // STRING_H
