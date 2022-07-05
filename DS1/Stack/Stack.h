#pragma once
#ifndef STACK_IMPLEMENTATION
#define STACK_IMPLEMENTATION

template <typename T>
class Stack
{
public:
    T *items;
    int stackSize;
    int maxSize;

    /**
     * @brief Construct a new stack
     *
     * @param maxSize The maximum size of the stack
     */
    Stack(const int &maxSize)
    {
        this->maxSize = maxSize;
        this->stackSize = 0;
        this->items = new T[maxSize];
    };

    /**
     * @brief Insert an item to the stack
     *
     * @param item The item to insert
     *
     * @return The inserted item
     */
    const T insert(T item) 
    {
        if (isFull())
            throw "Cannot add more element to the stack";

        items[stackSize++] = item;

        return item;
    };

    /**
     * @brief
     *
     * @return The removed element
     */
    const T pop()
    {
        if (isEmpty())
            throw "Cannot remove the last element of an empty array";

        return items[--stackSize];
    };

    /**
     * @brief Get element by its index
     *
     * @param index The index to get
     * @return The element at the provided index
     */
    T &operator[](int index) 
    {
        if (index < 0 || index >= stackSize)
            throw "Index out of range";

        return items[index];
    };

    /**
     * @brief Check whether the stack is empty
     *
     * @return True if the stack has no item
     */
    inline const bool isEmpty()
    {
        return stackSize == 0;
    };

    /**
     * @brief Check whether the stack is full
     *
     * @return True if the stack is full
     */
    inline const bool isFull()
    {
        return stackSize >= maxSize;
    };

    /**
     * @brief Destroy the stack
     */
    ~Stack()
    {
        delete[] items;
    };
};

#endif