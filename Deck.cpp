#include "Deck.h"

Card::Card(int v, std::string s) : value(v), suit(s) {}

Node::Node(Card card) : data(card), next(nullptr) {}

Deck::Deck() : front(nullptr), rear(nullptr), size(0) {}

Deck::~Deck() {
    while (!isEmpty()) {
        dequeue();
    }
}

bool Deck::isEmpty() {
    return size == 0;
}

int Deck::getSize() {
    return size;
}

void Deck::enqueue(Card card) {
    Node* newNode = new Node(card);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

Card Deck::dequeue() {
    if (isEmpty()) {
        cerr << "Deck is empty" << endl;
    }
    Card data = front->data;
    Node* temp = front;
    front = front->next;
    delete temp;
    size--;
    if (isEmpty()) {
        rear = nullptr;
    }
    return data;
}

Card Deck::top() {
    if (isEmpty()) {
        cerr << "Deck is empty" << endl;
    }
    return front->data;
}

void Deck::returnToBottom(Card* cards, int numCards) {
    for (int i = 0; i < numCards; i++) {
        enqueue(cards[i]);
    }
}

int Deck::cardsLeft() {
    return size;
}
