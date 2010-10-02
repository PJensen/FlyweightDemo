/*
** Copyright (c) <2006> Peter Jensen
** All Rights Reserved
**
** FILE:    Card.h
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
**		however, I've suppied two constructors. 
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
**/

#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <set>

using namespace std;

namespace FlyWeight {
	
	#define NUM_SUITES			4
	#define NUM_VALUES			12

	/////////////////////////////////////////////////////////////////////
	// The two data types, suite, and value are limited to the following
	// values.  I think it's best to leave them in this scope and not
	// Card::suite, or Card::value.
	typedef enum suite { HEARTS, CLUBS, DIAMONDS, SPADES };
	typedef enum value { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT,
						NINE, TEN, JACK, QUEEN, KING, ACE};

	class Card {
		public:	
			// ?Question?
			// Is there any way I can limit access to ONLY the factory? 
			// nominally (CardCache?) protected?
			Card();
			
			// NOTE: There are two constructors.  Since there are only two,
			// and they are two different data types, order doesn't nessisarily
			// need to apply.
			Card(suite, value);
			Card(value, suite);

			suite getSuite( void ) const;
			value getValue( void ) const;

			// Actually, we should NOT be allowed to set the value of a card.
			// from anywhere.
		private:
			void setSuite( suite );
			void setValue( value );

		public:
			// Both getSuiteString, and getValueString don't have to be within
			// the card class.  I think it is better design wise to have them
			// here since I can call; myCard.getSuiteString() as opposed to
			// getSuiteString( myCard ).  If there is a HUGE number of cards this
			// should be moved elsewhere.
			const string getSuiteString( void ) const;
			const string getValueString( void ) const;

			/**
			 * Destructor unused.
			 */
			~Card();
			
		private:		
			suite suite_;
			value value_;
	};

	ostream& operator<< (ostream&, Card&);
	suite generateRandomSuite( void );
	value generateRandomValue( void );
}

