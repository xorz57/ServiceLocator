# ServiceLocator

[![Build](https://github.com/xorz57/ServiceLocator/actions/workflows/Build.yml/badge.svg)](https://github.com/xorz57/ServiceLocator/actions/workflows/Build.yml)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=xorz57_ServiceLocator&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=xorz57_ServiceLocator)

## Example

```cpp
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
```

## Output

```console
A
B
00000241A0CA9850
00000241A0CA9550
00000241A0CA9850
00000241A0CA9550
~B
~A
0000000000000000
0000000000000000
```

## How to Build

#### Linux & macOS

```bash
git clone https://github.com/microsoft/vcpkg.git ~/vcpkg
~/vcpkg/bootstrap-vcpkg.sh

git clone https://github.com/xorz57/ServiceLocator.git
cd ServiceLocator
cmake -B build -DCMAKE_BUILD_TYPE=Release -S . -DCMAKE_TOOLCHAIN_FILE=~/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build --config Release
ctest --build-config Release
```

#### Windows

```powershell
git clone https://github.com/microsoft/vcpkg.git C:/vcpkg
C:/vcpkg/bootstrap-vcpkg.bat
C:/vcpkg/vcpkg.exe integrate install

git clone https://github.com/xorz57/ServiceLocator.git
cd ServiceLocator
cmake -B build -DCMAKE_BUILD_TYPE=Release -S . -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build --config Release
ctest --build-config Release
```
