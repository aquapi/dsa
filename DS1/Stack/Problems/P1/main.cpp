/**
    A letter means push and an asterisk means pop in the
    following sequence.  Give the sequence of values returned by the pop operations
    when this sequence of operations is performed on an initially empty LIFO stack.

         E A S * Y * Q U E * * * S T * * * I O * N * * *
 */

#include <iostream>
#include <string>
#include "../../Stack.h"

inline void setup() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::freopen(".in", "r", stdin);
    std::freopen(".out", "w", stdout);
}

char action;

Stack<char> stack{10};

main()
{
    setup();
    while (std::cin >> action)
    {
        if (action != '*') 
            stack.insert(action);
        else 
            std::cout << stack.pop() << "\n";
    }

    return 0;
}