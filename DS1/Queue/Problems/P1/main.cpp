/**
    A letter means put and an asterisk means shift in the 
    following sequence.  Give the sequence of values returned by the shift operation
    when this sequence of operations is performed on an initially empty FIFO queue.

         E A S * Y * Q U E * * * S T * * * I O * N * * *
 */

#include <iostream>
#include "../../Queue.h"

inline void setup() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::freopen(".in", "r", stdin);
    std::freopen(".out", "w", stdout);
}

Queue<char> queue{12};
char action;

main() {
    setup();
    
    while (std::cin >> action) {
        if (action != '*')
            queue.insert(action);
        else
            std::cout << queue.pop() << "\n";
    }
    return 0;
}