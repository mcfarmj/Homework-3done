
#include <stdexcept>
#include <string>

class Card {
public:
    int value;
    std::string suit;

    Card(int v, std::string s);

    Card() : value(0), suit("") {} // default constructor
};

class Node {
public:
    Card data;
    Node* next;

    Node(Card card);
};

class Deck {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Deck();

    ~Deck(); // Destructor to release memory

    bool isEmpty();
    int getSize();
    void enqueue(Card card);
    Card dequeue();
    Card top();
    void returnToBottom(Card* cards, int numCards);
    int cardsLeft();
};

#endif // DECK_H
