#ifndef SINGLETON_H
#define SINGLETON_H

template <typename T>
class Singleton
{
private:
    static T *instance;
    Singleton(/* args */){};

public:
    static T &getInstance()
    {
        if (instance == 0)
            instance = new T();
        return *instance;
    }
    ~Singleton() { };
};

template <typename T>
T *Singleton<T>::instance;

#endif