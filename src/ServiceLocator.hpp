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
