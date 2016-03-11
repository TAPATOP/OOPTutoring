# Member initializer list, constructor propagating, friends, namespace, file separation

## 1.Member  initializer list
Нека имаме клас:
```c++
class Circle {
public:
  Circle();
  Circle(Point O);
  Circle(Point O, int r);
private:
  Point m_O, int m_r;
};
```
Досега задавахме началните стойности чрез конструктора така:

```c++
  Circle::Circle(Point O, int r) {
    m_O = O;
    m_r = r;
  }
  ...
  Point A(1, 1);
  Circle c(A, 4);
```

Така компилатора, обаче ще направи две извиквания на функция.

1. Ще извика конструктора по подразбиране за m_O на обекта c.
2. Ще влезе в самия конструктор и ще извика оператор =. За оператори повече ще говорим следващия път, мислете за оператора като за функция.

Всъщност по този начин винаги ще се вика конструктора по подразбиране на private членовете.

За това използваме member initalizer list

```c++
  Circle::Circle(Point O, int r)
    : m_O{O}, m_r{r} {}
  ...
  Point A(1, 1);
  Circle c(A, 4);
```

Ако искаме да зададен стойности по подразбиране на членовете можем да го направим още в дефиницията на класа:

```c++
class Circle {
public:
  Circle();
  Circle(Point O);
  Circle(Point O, int r);
private:
  Point m_O, int m_r = 0;
};
```

## 2. Constructor propagating/chaining

Нека е даден класа:

```c++
class Person {
public:
  Person();
  Person(std::string name);
  Person(std::string name, int age);
private:
  std::string m_name, int age;
};
```
Да кажем, че искаме името на човек винаги да е с малки букви. Виждаме, че името присъства във всички конструктори, следователно ще трябва да пишем във всеки конструктор код за преобразуване на името в малки букви. За да избегнем повтарящи се действия в конструкторите ползваме constructor chaining.

```c++
  Person::Person(std::string name, int age)
    : m_age{age} {
      int s = name.size();
      for(int i = 0; i < s; i++) {
        name[i] = std::tolower(name[i]);
      }
      m_name = name;
    }
  Person::Person(): Person("", 0) {};
  Person::Person(std::string s): Person(s, 0) {};
```

## 3. Friend Function

Особеност на C++, която се среща в малко езици (дори може би в никой друг) са приятелските функции. Това са функции които могат да достъпват private членовете, на класа, но не членове на класа. Клас също може да бъде приятелски на друг.

```c++
class Person {
public:
  Person();
  Person(std::string name);
  Person(std::string name, int age);
  friend void ChangeNick(Person p, std::string newNick);
private:
  string m_name, m_nickname;
  int m_age;
};

...

void function ChangeNick(Person p, std::string newNick) {
  p.m_nickname = newNick;
}

...

Person pesho("Peso", 12);
SetNickname(pesho, "pepi");
```
## 4. Namespace
Когато пишем библиотеки и искаме да сме сигурни, че хората ще могат да ги ползват без да възникнат колизии, ги обвиваме в namespace.

```c++
#include<cstring>

...

namespace myString {
  char tolower(char c) {
    if(c >= 'A' && c <= 'Z') return c+32;
  }
  return c;
}

...
myString::tolower('A');
```
## 4. File Splitting

Декларациите отиват в .h имплементациите в .cpp

.h
```c++
#ifndfe PERSON
#define PERSON

#include<cstring>

class Person {
public:
  Person();
  Person(std::string name);
  Person(std::string name, int age);
private:
  string m_name;
  int m_age;
};

#endif PERSON
```
.cpp

```c++
  #include <cstring>
  #include "Person.h"
  Person::Person(std::string name, int age)
    : m_age{age} {
      int l = name.size();
      for(int i = 0; i < l; i++) {
        name[i] = std::tolower(name[i]);
      }
      m_name = name;
    }
  Person::Person(): Person("", 0) {};
  Person::Person(std::string s): Person(s, 0) {};
  Person::Person(std::string s, int age): Person(s, age) {};
```
## Важно

Oтсега нататък в задачите ще се подразбира, че ще е нужно пишете конструктори, деструктори (където е нужно), и методи за достъп (където има смисъл от тях). Ще се споменават само ако има особености.

## Задача 1

1. Дефинирайте клас Whiskey, с атрибути, име на производителя, количество в мл, и година на производство. Стойностите по подразбиране (default values) за атрибутите са съответно: "" за име на производителя, 0 за грамаж, 0 за година на производство. Името на производителя се пази само с малки букви.
2. Дефинирайте конструктори с съответно с по 1, 2 и 3 параметъра (като липсващите стойности остават тези по подразбиране). Използвайте constructor chaining(propagating)
