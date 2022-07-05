/**
    Add an interface function void STACKmultipop(int k) that pops k elements from
    the stack, or until the stack is empty.
 */

#include <iostream>
#include "../../Stack.h"

inline void setup()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::freopen(".in", "r", stdin);
    std::freopen(".out", "w", stdout);
}

Stack<char> stack{26};
char action;

void stackMultiPop(int time)
{
    for (int i = 0; i < time; i++)
    {
        if (stack.isEmpty())
            return;

        stack.pop();
    }
}

main()
{
    setup();

    while (std::cin >> action)
        stack.insert(action);

    stackMultiPop(25);

    std::cout << stack.stackSize << ": " << stack[0];

    return 0;
}