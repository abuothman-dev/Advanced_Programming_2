#pragma once
#include <stdexcept>
#include <vector>

// Class Template: Stack<T> كما طلبه الملف
template <typename T>
class Stack {
    std::vector<T> data;
public:
    void push(const T& val) { data.push_back(val); }

    T pop() {
        if (empty()) throw std::underflow_error("Stack فارغ");
        T val = data.back();
        data.pop_back();
        return val;
    }

    const T& top() const {
        if (empty()) throw std::underflow_error("Stack فارغ");
        return data.back();
    }

    bool empty() const { return data.empty(); }
    int  size()  const { return static_cast<int>(data.size()); }
};
