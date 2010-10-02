 --------------
# FlyWeight Demo]
 --------------

* [QUEEN of HEARTS] @ 0x9810020
* [JACK of SPADES] @ 0x9810048 
* [5 of HEARTS] @ 0x9810070
* [2 of CLUBS] @ **0x9810098**
* [QUEEN of DIAMONDS] @ 0x98100c0
* [ACE of SPADES] @ 0x98100e8
* [KING of HEARTS] @ 0x9810110
* [QUEEN of DIAMONDS] @ 0x98100c0
* [2 of CLUBS] @ **0x9810098**
* [5 of HEARTS] @ 0x9810070
* [JACK of SPADES] @ 0x9810048
* [JACK of HEARTS] @ 0x9810138

Press Any Key to Continue ...

##FlyweightDemo

This is the driver (client) program for both Card, and CardCache. We 
actually only refer to CardCache and it handles and enforces the Flyweight
property for us.

## CardCache

CardCache is a singleton class that maintains a pool of cards.  The pool
is a map that maps (suite, value) pairs to a card.  It also implements
the factory pattern, where getCard returns the only instance of the
requested card.

## Card
This is the Card class.  Please note that it only supports the fundementals
of a Card and NOT a deck of Cards. getValue(), setValue(), getSuite(),
setSuite(), getSuiteString(), getValueString().

Also the == operator and << are both supported.  It does not make sense to 
support < or > since in different games the rules change.  I thought about
making them virtual that way they could be over-riden, but I am not sure
it would have been applicable to this demonstration.

**NOTE**: The data type(s) suite, and value also exist.

	typedef enum suite {HEARTS, CLUBS, DIAMONDS, SPADES};
	typedef enum value {TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,
					JACK,QUEEN,KING,ACE};

Suppose you wanted to create the QUEEN of DIAMONDS.

	Card myCard = Card(DIAMONDS, QUEEN);

**NOTE**: The default constructor does nothing; the destructor does nothing.
however, I've suppied two explicit constructors. 

	// Let s be a suite, Let v be a value.
	Card(s, v) == Card(v, s) would be a valid statement.

I did this because I realized that I didn't like it the way I had it.
Card(DIAMONDS, QUEEN), I don't think of THE QUEEN OF DIAMONDS like
exactly that way.  So it makes sense to at least provide an option
for the consruction of the object in whichever order.


