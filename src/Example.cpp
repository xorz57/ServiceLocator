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

    A(const A &other) = delete;
    A(A &&other) = delete;

    A &operator=(const A &other) = delete;
    A &operator=(A &&other) = delete;
};

class B {
public:
    B() {
        std::cout << __func__ << std::endl;
    }
    ~B() {
        std::cout << __func__ << std::endl;
    }

    B(const B &other) = delete;
    B(B &&other) = delete;

    B &operator=(const B &other) = delete;
    B &operator=(B &&other) = delete;
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
