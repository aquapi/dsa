#pragma once
#ifndef QUEUE_IMPLEMENTATION
#define QUEUE_IMPLEMENTATION

template <typename T>
class Queue
{

public:
    int queueSize, maxSize, deletedItemsCnt;
    T *items;

    /**
     * @brief Construct a new queue
     *
     * @param maxSize the maximum size of the queue
     */
    Queue(const int &maxSize)
    {
        this->maxSize = maxSize;
        deletedItemsCnt = 0;
        queueSize = 0;
        items = new T[maxSize];
    }

    /**
     * @brief Insert an item at the beginning of the queue
     *
     * @param item
     * @return The inserted element
     */
    const T insert(T item)
    {
        if (isFull())
            throw "The queue is full";

        items[maxSize - ++queueSize] = item;
        return item;
    }

    /**
     * @brief Remove the last element in the queue
     *
     * @return The removed element
     */
    const T pop()
    {
        if (isEmpty())
            throw "Cannot remove the first element in an empty stack";

        return items[maxSize - ++deletedItemsCnt];
    }

    /**
     * @brief Get an element by its index
     *
     * @param index to get
     * @return The element
     */
    T &operator[](int index)
    {
        return items[maxSize - index - 1 - deletedItemsCnt];
    }

    /**
     * @brief Check whether the queue is full
     *
     * @return true if the queue is full
     */
    inline bool isFull()
    {
        return queueSize == maxSize;
    }

    /**
     * @brief Check whether the queue is empty
     *
     * @return true if the queue is empty
     */
    inline bool isEmpty()
    {
        return queueSize - deletedItemsCnt == 0;
    }

    /**
     * @brief Destroy the queue
     */
    ~Queue()
    {
        delete[] items;
    }
};

#endif
