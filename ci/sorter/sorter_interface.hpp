#ifndef SORTER_INTERFACE_HPP
#define SORTER_INTERFACE_HPP
template <typename T>
class sorter{
    public: 
    virtual ~sorter() {}
    virtual void sort(T& container, int size) = 0;
};
#endif