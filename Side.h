#ifndef SIDE_H
#define SIDE_H

#include "Deck.h"


class Side {
private:
    Card* stack;
    int maxSize;
    int topIndex;

public:
    Side(int size);

    ~Side(); // Destructor to release memory

    bool isEmpty();
    bool isFull();
    void push(Card card);
    Card pop();
    int cardsLeft();
};

#endif // SIDE_H
