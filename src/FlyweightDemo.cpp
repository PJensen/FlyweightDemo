/*
** Copyright (c) 2006 Peter Jensen
** All Rights Reserved
**
** FILE:	FlyweightDemo.cpp
** DATE: 	November, 2006
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
**	 This is the driver (client) program for both Card, and CardCache. We 
** actually only refer to CardCache and it handles enforces the Flyweight
** property for us.
**
** <UML DIAGRAM>
** =========================================================
**
**	   <singleton>                                         =
**   --[CardCache]--               -----[Card]-----        =
**   | instance()  |               | value_       |        =
**   | getCard(s,v)|--creates----->| suite_       |        =
**   | pool_       |               |______________|        =
**   |_____________|                     ^                 =  
**          ^                            .                 =
** 		    |							 .                 =
** ------------------FlyWeight NameSpace-------------------
**			|                            .
**          |           |--------|       .
**		    |-requests--| CLIENT | . . . . <==---- Knows About
**                      |________|
**
** LAST NOTE:: There is a compilation switch
**		SHOW_RANDOM_CARDS
**	That shows 53 random cards.
**/

#include <iostream>
#include <string>
#include <stdlib.h>

#include "Card.h"
#include "CardCache.h"

using namespace std;
using namespace FlyWeight;

int main(int argc, char** argv) {

// Funny disclaimer.
cout << " --------------" << endl;
cout << "[FlyWeight Demo]" << endl;
cout << " --------------" << endl;
cout << endl;

#ifdef SHOW_RANDOM_CARDS
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	//////////////////////////////////////////////////////////////////////////
	// Randomly Creates 53 Cards.  By the mathematical "pigeon hole principle"
	// There will be at least 1 duplicate Card & thats what we're looking for.
	// BlackJack would be nice, but it is outside of the scope of the demo.
	for (int index = 0; index < 53; ++index) {

		Card& floppedCard = 
			CardCache::instance()->
				getCard( generateRandomSuite(), generateRandomValue() );

		cout << floppedCard << " @ " << &floppedCard << endl;	
		cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	}
#else
	Card& a = CardCache::instance()->getCard(QUEEN, HEARTS);
	Card& b = CardCache::instance()->getCard(JACK, SPADES);
	Card& c = CardCache::instance()->getCard(FIVE, HEARTS);
	Card& d = CardCache::instance()->getCard(TWO, CLUBS);
	Card& e = CardCache::instance()->getCard(QUEEN, DIAMONDS);
	Card& f = CardCache::instance()->getCard(ACE, SPADES);
	Card& g = CardCache::instance()->getCard(KING, HEARTS);
	Card& h = CardCache::instance()->getCard(QUEEN, DIAMONDS);
	Card& i = CardCache::instance()->getCard(TWO, CLUBS);
	Card& j = CardCache::instance()->getCard(FIVE, HEARTS);
	Card& k = CardCache::instance()->getCard(JACK, SPADES);
	Card& l = CardCache::instance()->getCard(JACK, HEARTS);

	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << a << " @ " << &a << endl;
	cout << b << " @ " << &b << endl;
	cout << c << " @ " << &c << endl;
	cout << d << " @ " << &d << endl;
	cout << e << " @ " << &e << endl;
	cout << f << " @ " << &f << endl;
	cout << g << " @ " << &g << endl;
	cout << h << " @ " << &h << endl;
	cout << i << " @ " << &i << endl;
	cout << j << " @ " << &j << endl;
	cout << k << " @ " << &k << endl;
	cout << l << " @ " << &l << endl;
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
#endif

	cout << endl;
	cout << "Press Any Key to Continue ..." << endl;

	cin.ignore(1);

	return EXIT_SUCCESS;
}



