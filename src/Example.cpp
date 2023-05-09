#include "ServiceLocator.hpp"

#include <iostream>

class A {
public:
    A() {
        std::cout << __func__ << std::endl;
    }
    ~A() {
        std::cout << __func__ << std::endl;
    }
};

class B {
public:
    B() {
        std::cout << __func__ << std::endl;
    }
    ~B() {
        std::cout << __func__ << std::endl;
    }
};

int main() {
    ServiceLocator serviceLocator;

    serviceLocator.SetInstance<A>();
    serviceLocator.SetInstance<B>();

    std::cout << serviceLocator.GetInstance<A>() << std::endl;
    std::cout << serviceLocator.GetInstance<B>() << std::endl;

    std::cout << serviceLocator.GetInstance<A>() << std::endl;
    std::cout << serviceLocator.GetInstance<B>() << std::endl;

    serviceLocator.Clear();

    std::cout << serviceLocator.GetInstance<A>() << std::endl;
    std::cout << serviceLocator.GetInstance<B>() << std::endl;

    return 0;
}
