#pragma once
#ifndef CIRCULARQUEUE_IMPLEMENTATION
#define CIRCULARQUEUE_IMPLEMENTATION

template <typename T>
class CircularQueue
{

public:
    int frontIndex, rearIndex, maxSize;
    T *items;

    /**
     * @brief Construct a new circular queue
     *
     * @param maxSize the maximum size of the queue
     */
    CircularQueue(const int &maxSize)
    {
        this->maxSize = maxSize;
        items = new T[maxSize];
        frontIndex = rearIndex = -1;
    }

    /**
     * @brief Insert an item at the beginning of the queue
     *
     * @param item
     * @return The inserted item
     */
    const T insert(T item)
    {
        if (isFull())
            throw "Cannot add any element to a full queue";

        if (frontIndex = -1)
            frontIndex = 0;

        rearIndex = (rearIndex + 1) % maxSize; // Increment

        items[rearIndex] = item;

        return item;
    }

    /**
     * @brief Delete the last element of the queue
     *
     * @return The deleted element
     */
    const T pop()
    {
        if (isEmpty())
            throw "Cannot remove any element from an empty queue";

        T item = items[frontIndex];

        // Empty queue
        if (frontIndex == rearIndex)
            frontIndex = rearIndex = -1;
        else
            frontIndex = (frontIndex + 1) % maxSize; // Increment

        return item;
    }

    /**
     * @brief Check whether the queue is empty
     *
     * @return true if the queue is empty
     */
    inline bool isEmpty()
    {
        return frontIndex == -1;
    }

    /**
     * @brief Check whether the queue is full
     *
     * @return true if the queue is full
     */
    inline bool isFull()
    {
        return (frontIndex == 0 && rearIndex == maxSize - 1) || frontIndex == rearIndex + 1
    }

    /**
     * @brief Destroy the circular queue
     */
    ~CircularQueue()
    {
        delete[] items;
    }
};

#endif
