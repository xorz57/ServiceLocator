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

#pragma once

#include <functional>
#include <unordered_map>
#include <memory>

class ServiceLocator {
public:
    ServiceLocator() = default;
    ~ServiceLocator() = default;

    template<typename T, typename... Args>
    void SetInstance(Args... args) {
        const size_t hash = typeid(T).hash_code();
        std::shared_ptr<T> instance = std::make_shared<T>(args...);
        mInstances.emplace(hash, std::shared_ptr<void>(instance));
    }

    template<typename T>
    std::shared_ptr<T> GetInstance() {
        const size_t hash = typeid(T).hash_code();
        auto it = mInstances.find(hash);
        if (it != mInstances.end()) {
            return std::static_pointer_cast<T>(mInstances.at(hash));
        }
        return nullptr;
    }

    void Clear() {
        mInstances.clear();
    }

private:
    std::unordered_map<size_t, std::shared_ptr<void>> mInstances;
};
