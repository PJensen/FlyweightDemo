/*
** Copyright (c) 2006 Peter Jensen
** All Rights Reserved
**
** FILE:    Card.cpp
** DATE:    November, 2006
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
** THE SOFTWARE.
**
** This is the Card class.  Please note that it only supports the fundementals
** of a Card and NOT a deck of Cards. getValue(), setValue(), getSuite(),
** setSuite(), getSuiteString(), getValueString().
**
** Also the == operator and << are both supported.  It does not make sense to 
** support < or > since in different games the rules change.  I thought about
** making them virtual that way they could be over-riden, but I am not sure
** it would have been applicable to this demonstration.
**
** Helpers
**
**	 ostream& operator<< (ostream&, Card&);
**	 suite generateRandomSuite( void );
**	 value generateRandomValue( void );
**
** NOTE: Along with the operator helper methods, I also added getRandomValue()
** and getRandomSuite(), they do not change the state of the card; but simply
** return a random enum. (or number thats been typcasted.
**
** NOTE: The data type(s) suite, and value also exist.
**
**		typedef enum suite {HEARTS, CLUBS, DIAMONDS, SPADES};
**		typedef enum value {TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,
**						JACK,QUEEN,KING,ACE};
**
** Suppose you wanted to create the QUEEN of DIAMONDS.
**
**		Card myCard = Card(DIAMONDS, QUEEN);
**
** NOTE: The default constructor does nothing; the destructor does nothing.
**		however, I've supplied two constructors.
**	
**		Let s be a suite, Let v be a value.
**			Card(s, v) == Card(v, s) would be a valid statement.
**
**		I did this because I realized that I didn't like it the way I had it.
**			Card(DIAMONDS, QUEEN), I don't think of THE QUEEN OF DIAMONDS like
**			exactly that way.  So it makes sense to at least provide an option
**			for the consruction of the object.
**
** NOTE: An idea for a future version would be to have the Card objects load
** images using SDL, that way the Flyweight property is fully realized.
**
**	The programming for the Card class is very straight forward and simple.
**
** @See :: <UML DIAGRAM> :: FlyweightDemo.cpp
**/

#include "Card.h"

namespace FlyWeight {

	Card::Card(){}
		
	// NOTE: Two constructors
	Card::Card(value initValue, suite initSuite)
		// :value_(initValue), suite_(initSuite)
	{
		value_ = initValue;
		suite_ = initSuite;
	}

	// NOTE: Two constructors
	Card::Card(suite initSuite, value initValue) 
		:suite_(initSuite), value_(initValue) 
	{}

	suite Card::getSuite() const {
		return Card::suite_;
	}

	value Card::getValue() const {
		return Card::value_;
	}

	void Card::setSuite(suite setSuite) {
		suite_ = setSuite;
	}

	void Card::setValue(value setValue) {
		value_ = setValue;
	}

	const string Card::getSuiteString() const {

		switch(Card::suite_) {
			case DIAMONDS: return "DIAMONDS";
			case CLUBS: return "CLUBS";
			case HEARTS: return "HEARTS";
			case SPADES: return "SPADES";
		}
		return "";
	}

	const string Card::getValueString() const {
		
		switch(Card::value_) {
			case ACE: return "ACE";
			case KING: return "KING"; 
			case QUEEN: return "QUEEN";
			case JACK: return "JACK"; 
			case TEN: return "10"; 
			case NINE: return "9"; 
			case EIGHT: return "8"; 
			case SEVEN: return "7";
			case SIX: return "6";
			case FIVE: return "5"; 
			case FOUR: return "4";
			case THREE: return "3";
			case TWO: return "2";
		}
		return "";
	}

	Card::~Card(){}

	ostream& operator<< (ostream& os, Card& outCard) {
		os << "[";
		os << outCard.getValueString();
		os << " of ";
		os << outCard.getSuiteString();
		os << "]";

		return os;	
	}

	bool operator == (Card& c1, Card& c2) {
		return (c1.getSuite() == c2.getSuite() && c1.getValue() == c2.getValue());
	}

	suite generateRandomSuite( void ) { 
		return (suite)(rand() % NUM_SUITES);
	}

	value generateRandomValue( void ) {
		return (value)(rand() % NUM_VALUES);
	}

}


