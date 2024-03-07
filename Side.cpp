#include "Side.h"
#include <iostream>
using namespace std;


Side::Side(int size) : maxSize(size), topIndex(-1) {
    stack = new Card[maxSize];
}

Side::~Side() {
    delete[] stack;
}

bool Side::isEmpty() {
    return topIndex == -1;
}

bool Side::isFull() {
    return topIndex == maxSize - 1;
}

void Side::push(Card card) {
    if (isFull()) {
        cerr << "Side pile is full" << endl;
    }
    stack[++topIndex] = card;
}

Card Side::pop() {
    if (isEmpty()) {
        cerr << "Side pile is empty" << endl;
    }
    return stack[topIndex--];
}

int Side::cardsLeft() {
    return topIndex + 1;
}
