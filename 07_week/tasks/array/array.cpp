#include <algorithm>
#include <initializer_list>
#include <stddef.h>

template <typename T, size_t size>
class Array {
public:
    ~Array();
    Array();
    Array(const std::initializer_list<T>& ilist);
    Array(const Array& other);
    Array(Array&& other) noexcept;
    T& Front();
    const T& Front() const;
    T& Back();
    const T& Back() const;
    T* Data();
    const T* Data() const;
    bool Empty() const;
    size_t Size() const;
    void Fill(const T& item);
    void Swap(Array& other);
    T* begin();
    T* end();
    const T* cbegin() const;
    const T* cend() const;
    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;
    T& operator[](int pos);
    const T& operator[](int pos) const;
private:
    T m_arr[size] = {};
};

template <typename T, size_t size>
Array<T, size>::~Array(){}

template <typename T, size_t size>
Array<T, size>::Array() {}

template <typename T, size_t size>
Array<T, size>::Array(const std::initializer_list<T>& ilist) {
    std::copy(ilist.begin(), ilist.end(), m_arr);
}

template <typename T, size_t size>
Array<T, size>::Array(const Array& other) {
    std::copy(other.cbegin(), other.cend(), m_arr);
}

template <typename T, size_t size>
Array<T, size>::Array(Array&& other) noexcept {
    std::move(other.begin(), other.end(), m_arr);
    std::fill(other.begin(), other.end(), T{});
}

template <typename T, size_t size>
T& Array<T, size>::Front() {
    return m_arr[0];
}

template <typename T, size_t size>
const T& Array<T, size>::Front() const {
    return m_arr[0];
}

template <typename T, size_t size>
T& Array<T, size>::Back() {
    return m_arr[size - 1];
}

template <typename T, size_t size>
const T& Array<T, size>::Back() const {
    return m_arr[size - 1];
}

template <typename T, size_t size>
T* Array<T, size>::Data() {
    return m_arr;
}

template <typename T, size_t size>
const T* Array<T, size>::Data() const {
    return m_arr;
}

template <typename T, size_t size>
bool Array<T, size>::Empty() const {
    return size == 0;
}

template <typename T, size_t size>
size_t Array<T, size>::Size() const {
    return size;
}

template <typename T, size_t size>
void Array<T, size>::Fill(const T& item) {
    std::fill(begin(), end(), item);
}

template <typename T, size_t size>
void Array<T, size>::Swap(Array& other) {
    for (size_t i = 0; i < size; ++i) {
        std::swap(m_arr[i], other.m_arr[i]);
    }
}

template <typename T, size_t size>
T* Array<T, size>::begin() {
    return m_arr;
}

template <typename T, size_t size>
T* Array<T, size>::end() {
    return m_arr + size;
}

template <typename T, size_t size>
const T* Array<T, size>::cbegin() const {
    return m_arr;
}

template <typename T, size_t size>
const T* Array<T, size>::cend() const {
    return m_arr + size;
}

template <typename T, size_t size>
Array<T, size>& Array<T, size>::operator=(const Array& other) {
    if (this == &other) { return *this; }
    std::copy(other.cbegin(), other.cend(), m_arr);
    return *this;
}

template <typename T, size_t size>
Array<T, size>& Array<T, size>::operator=(Array&& other) noexcept {
    if (this == &other) { return *this; }
    std::move(other.begin(), other.end(), m_arr);
    std::fill(other.begin(), other.end(), T{});
    return *this;
}

template <typename T, size_t size>
T& Array<T, size>::operator[](int pos) {
    return m_arr[pos];
}

template <typename T, size_t size>
const T& Array<T, size>::operator[](int pos) const {
    return m_arr[pos];
}

template <typename T, size_t size>
bool operator==(const Array<T, size>& lhs, const Array<T, size>& rhs) {
    if (lhs.Size() != rhs.Size()) { return false; }
    return std::equal(lhs.cbegin(), lhs.cend(), rhs.cbegin());
}

template <typename T, size_t size>
bool operator!=(const Array<T, size>& lhs, const Array<T, size>& rhs) {
    return !(lhs == rhs);
}

template <typename T, size_t size>
bool operator<(const Array<T, size>& lhs, const Array<T, size>& rhs) {
    if (lhs.Size() != rhs.Size()) { return false; }
    for (size_t i = 0; i < lhs.Size(); ++i) {
        if (lhs[i] == rhs[i]) { continue; }
        return lhs[i] < rhs[i];
    }
    return false;
}

template <typename T, size_t size>
bool operator<=(const Array<T, size>& lhs, const Array<T, size>& rhs) {
    return lhs < rhs || lhs == rhs;
}

template <typename T, size_t size>
bool operator>=(const Array<T, size>& lhs, const Array<T, size>& rhs) {
    return !(lhs < rhs);
}

template <typename T, size_t size>
bool operator>(const Array<T, size>& lhs, const Array<T, size>& rhs) {
    return !(lhs < rhs) && lhs != rhs;
}

template <typename T, size_t size>
void swap(Array<T, size>& lhs, Array<T, size>& rhs) {
    lhs.Swap(rhs);
}

template <size_t I, typename T, size_t size>
T& get(Array<T, size>& arr) {
    return arr[I];
}

template <size_t I, typename T, size_t size>
const T& get(const Array<T, size>& arr) {
    return arr[I];
}

template <size_t I, typename T, size_t size>
T&& get(Array<T, size>&& arr) {
    return std::move(arr[I]);
}