#ifndef VECTOR_HPP
#define VECTOR_HPP

#include<initializer_list>
#include<iostream>

namespace MVector {

    typedef unsigned int uint;

    template<typename T>
    class Vector {

        typedef T* iterator;

        public:
            Vector();
            Vector(std::initializer_list<T>, float = 1.5f);
            Vector(const Vector<T>&);
            Vector(Vector<T>&&);
            uint size();
            Vector<T>& operator= (const Vector<T>&);
            Vector<T>& operator= (Vector<T>&&);
            T& operator[] (const uint);
            T* begin();
            T* end();
            void push_back(const T&);
            void insert(const T&, uint index);
            void pop_back();
            ~Vector();
        private:
            T* m_buffer = nullptr;
            float m_scaling_factor = 1.5f;
            uint m_capacity = 2, m_size = 0;
    };

    template<typename T>
    Vector<T>::Vector() {
        m_buffer = new T[2];
    };

    template<typename T>
    Vector<T>::Vector(std::initializer_list<T> l, float scaling_factor)
    : m_scaling_factor{scaling_factor}, m_capacity{l.size()+1}, m_size{l.size()} {
        std::cout<<"\nCAP: "<<m_capacity<<"\n"<<m_capacity<<std::endl;
        m_buffer = new T[m_capacity];
        uint i = 0;
        for(T x : l) {
            m_buffer[i] = x;
            i++;
        }
    }
    //copy
    template<typename T>
    Vector<T>::Vector(const Vector<T> &other)
        : m_size{other.m_size}, m_capacity{other.m_capacity}, m_scaling_factor{other.m_scaling_factor} {
        m_buffer = new T[m_capacity];
        for(uint i = 0; i < m_size; i++) {
            m_buffer[i] = other.m_buffer[i];
        }
    }
    //move
    template<typename T>
    Vector<T>::Vector(Vector<T> &&other)
        : m_size{other.m_size}, m_capacity{other.m_capacity}, m_scaling_factor{other.m_scaling_factor},
        m_buffer{other.m_buffer} {
        other.m_buffer = nullptr;
    }

    template<typename T>
    uint Vector<T>::size() {
        return m_size;
    }

    template<typename T>
    Vector<T>& Vector<T>::operator= (const Vector<T>& other) {
        delete[] m_buffer;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_scaling_factor = other.m_scaling_factor;
        m_buffer = new T[m_capacity];
        for(uint i = 0; i < m_size; i++) {
            m_buffer[i] = other.m_buffer[i];
        }
        return *this;
    }

    template<typename T>
    Vector<T>& Vector<T>::operator= (Vector<T>&& other) {
        delete[] m_buffer;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_scaling_factor = other.m_scaling_factor;
        m_buffer = other.m_buffer;
        other.m_buffer = nullptr;
        return *this;
    }

    template<typename T>
    void Vector<T>::push_back(const T& el) {
        insert(el,m_size);
    }

    template<typename T>
    void Vector<T>::insert(const T& el, uint index) {
        if(index <= m_size) {
            if(m_size < m_capacity) {
                for(int i = m_size - 1; i >= (int)index; i--) {
                    m_buffer[i+1] = m_buffer[i];
                }
                m_buffer[index] = el;
                m_size++;
            } else {
                m_capacity *= m_scaling_factor;
                m_size++;
                T* new_buff = new T[m_capacity];
                uint i = 0;
                for(i = 0; i < index; i++) new_buff[i] = m_buffer[i];
                new_buff[i++] = el;
                for(;i < m_size; i++) new_buff[i] = m_buffer[i-1];
                delete[] m_buffer;
                m_buffer = new_buff;
            }
        } else {
            //It is better to throw exception
            //But we will learn them later in the course
            return;
        }
    }

    template<typename T>
    void Vector<T>::pop_back() {
        if(m_size > 0) m_size--;
        else return;
        //Once again exception should be thrown
    }

    template<typename T>
    T& Vector<T>::operator[] (const uint index) {
        return m_buffer[index];
        //No exception here this operator relies that the programmer using it wont mess up
        //function T& at(uint index) is usually implemented and throws exception
    }

    template<typename T>
    typename Vector<T>::iterator Vector<T>::begin() {
        return m_buffer;
    }

    template<typename T>
    typename Vector<T>::iterator Vector<T>::end() {
        return m_buffer + m_size;
    }

    template<typename T>
    Vector<T>::~Vector() {
        delete[] m_buffer;
    }
}

#endif // VECTOR_HPP

