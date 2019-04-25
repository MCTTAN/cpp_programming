#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

const int CARDS_PER_DECK = 52;

class card
{
	public:
		card(string cardFace, string cardSuit);
		string print () const;
		card();
	private:
		string face;
		string suit;
};

card::card()
{
	
}

card::card(string cardFace, string cardSuit)
{
	face = cardFace;
	suit = cardSuit;
}

string card::print () const
{
	return (face + " of " + suit);
}

class deckOfCards
{
	public:
		deckOfCards();
		void shuffle();
		card dealCard();
		void printDeck() const;
	private:
		card *deck;
		int currentCard;
};

void deckOfCards::printDeck() const
{
	cout << left;
	
	for (int i = 0; i < CARDS_PER_DECK; ++i)
	{
		cout << setw(19) << deck[i].print();
		if ((i + 1) % 4 == 0)
		{
			cout << endl;
		}
	}
}

deckOfCards::deckOfCards()
{
	string faces[] = {"Ace", "Two", "Three", "Four", "Five",
					  "Six", "Seven", "Eight", "Nine", "Ten",
					  "Jack", "Queen", "King"};
	
	string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
	
	deck = new card[CARDS_PER_DECK];
	
	currentCard = 0;
	
	for (int count = 0; count < CARDS_PER_DECK; ++count)
	{
		deck[count] = card(faces[count % 13], suits[count / 13]);
	}
}

void deckOfCards::shuffle()
{
	currentCard = 0;
	for ( int first = 0; first < CARDS_PER_DECK; ++first)
	{
		int second = (rand() + time(0)) % CARDS_PER_DECK;
		card temp = deck[first];
		deck[first] = deck[second];
		deck[second] = temp;
	}
}

card deckOfCards::dealCard()
{
	if(currentCard > CARDS_PER_DECK)
	{
		shuffle();
	}
	
	if(currentCard < CARDS_PER_DECK)
	{
		return (deck[++currentCard]);
	}
	
	return (deck[0]);
}

int main()
{
	deckOfCards deck;
	card currentCard;
	deck.printDeck();
	deck.shuffle();
	cout << endl << endl;
	deck.printDeck();
	deck.shuffle();
	cout << endl << endl;
	for (int i = 0; i < 52; ++i)
	{
		currentCard = deck.dealCard();
		cout << currentCard.print() << endl;
	}
	
	return 0;
}
