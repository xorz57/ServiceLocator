/*
	MIT License

	Copyright(c) 2023 George Fotopoulos

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files(the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions :

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#include "ServiceLocator/ServiceLocator.hpp"

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
    service_locator_t sl;

    sl.set_instance<A>();
    sl.set_instance<B>();

    std::cout << sl.get_instance<A>() << std::endl;
    std::cout << sl.get_instance<B>() << std::endl;

    std::cout << sl.get_instance<A>() << std::endl;
    std::cout << sl.get_instance<B>() << std::endl;

    sl.clear();

    std::cout << sl.get_instance<A>() << std::endl;
    std::cout << sl.get_instance<B>() << std::endl;

    return 0;
}
