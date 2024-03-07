#include <iostream>
using namespace std;
#include <cstdlib> // For rand() and srand()
#include <ctime>
#include "Deck.cpp"
#include "Side.cpp"

void playGame(int numRounds);

int main() {
    int numRounds;
    cout << "Enter the number of rounds to play: ";
    cin >> numRounds;
    playGame(numRounds);
    return 0;
}

void playGame(int numRounds) {
    srand(time(0)); // Seed for random number generation

    Deck playerDeck;
    Deck computerDeck;

    const std::string suits[] = {"Spades", "Hearts", "Diamonds", "Clubs"};

    // Populate decks with cards
    const int numCards = 26;
    for (int i = 0; i < numCards; ++i) {
        int value = rand() % 13 + 1; // Random rank between 1 and 13
        std::string suit = suits[rand() % 4]; // Random suit
        playerDeck.enqueue(Card(value, suit));
    }
    for (int j = 0; j < numCards; ++j) {
        int value = rand() % 13 + 1; // Random rank between 1 and 13
        std::string suit = suits[rand() % 4]; // Random suit
        computerDeck.enqueue(Card(value, suit));
    }

    Side playerSidePile(5);
    Side computerSidePile(5);

    int playerScore = 0;
    int computerScore = 0;

    for (int round = 1; round <= numRounds; ++round) {
        cout << "\nRound " << round << ":" << endl;

        // Number of cards left in players deck
        cout << "Player has " << playerDeck.cardsLeft() << " cards left in their deck." << endl;
        // Number of cards left in players side pile
        cout << "Player has " << playerSidePile.cardsLeft() << " cards left in their side pile." << endl;

        // Number of cards left in computers deck
        cout << "Computer has " << computerDeck.cardsLeft() << " cards left in their deck." << endl;

        // Player draws a card
        Card playerCard = playerDeck.top();
        cout << "\nPlayer drew a card: " << playerCard.value << " of " << playerCard.suit << endl;

        // Computer draws a card
        Card computerCard = computerDeck.top();
        cout << "\nComputer drew a card: " << computerCard.value << " of " << computerCard.suit << endl;

        // Player decides whether to push or pull a card from their side pile
        std::string playerDecision;
        cout << "\nPlayer, do you want to push or pull a card? (push/pull): ";
        cin >> playerDecision;

        // Player decides to push the card onto their side pile
        if (playerDecision == "push") {
            playerDeck.dequeue(); // Player pushes the drawn card onto their side pile
            playerSidePile.push(playerCard);
        }

        // Player decides to pull a card from their side pile
        else if (playerDecision == "pull" && !playerSidePile.isEmpty()) {
            Card playerSideCard = playerSidePile.pop();
            cout << "\nPlayer pulled a card from their side pile: " << playerSideCard.value << " of " << playerSideCard.suit << endl;
            // Player plays both cards this round
            playerCard = playerSideCard;
        }

        // Computer decides whether to push or pull a card from their side pile (random decision for illustration)
        std::string computerDecision = (rand() % 2 == 0) ? "push" : "pull";
        cout << "\nComputer decides to " << computerDecision << " a card." << endl;

        // Computer decides to push the card onto their side pile
        if (computerDecision == "push") {
            computerDeck.dequeue(); // Computer pushes the drawn card onto their side pile
            computerSidePile.push(computerCard);
        }

        // Computer decides to pull a card from their side pile
        else if (computerDecision == "pull" && !computerSidePile.isEmpty()) {
            Card computerSideCard = computerSidePile.pop();
            cout << "\nComputer pulled a card from their side pile: " << computerSideCard.value << " of " << computerSideCard.suit << endl;
            // Computer plays both cards this round
            computerCard = computerSideCard;
        }

        // Sum of card values
        int playerTotal = playerCard.value + (playerDecision == "pull" ? playerCard.value : 0);
        int computerTotal = computerCard.value + (computerDecision == "pull" ? computerCard.value : 0);

        if (playerTotal > computerTotal || (playerTotal == computerTotal && playerDecision == "pull")) {
            cout << "\nPlayer wins the round!" << endl;
            playerScore++;
        } else {
            cout << "\nComputer wins the round!" << endl;
            computerScore++;
        }
    }

    // Prints winner of the game
    if (playerScore > computerScore) {
        cout << "\nPlayer wins the game with a score of " << playerScore << " to " << computerScore << "!" << endl;
    } else if (playerScore < computerScore) {
        cout << "\nComputer wins the game with a score of " << computerScore << " to " << playerScore << "!" << endl;
    } else {
        cout << "\nThe game ends in a tie with a score of " << playerScore << " to " << computerScore << "!" << endl;
    }
}
