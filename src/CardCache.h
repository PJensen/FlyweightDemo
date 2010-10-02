/*
** Copyright (c) 2006 Peter Jensen
** All Rights Reserved
**
** FILE: 	CardCache.h
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
** CardCache is a singleton class that maintains a pool of cards.  The pool
** is a map that maps (suite, value) pairs to a card.  It also implements
** the factory pattern, where getCard returns the only instance of the
** requested card.
**
** For Example:
**
**		CardCache::instance()->getCard(DIAMONDS, QUEEN);
** 
** NOTE: This class is coded inline, there is no corresponding .cpp file.
** NOTE: This class is also a part of the FlyWeight namespace.
**
** @See :: <UML DIAGRAM> :: FlyweightDemo.cpp
**/

#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <map>

#include "Card.h"

using namespace std;

namespace FlyWeight {

	class CardCache {

	public:
		////////////////////////////////////////////////////////////////
		// Since CardCache is a singleton the way to actually access it
		// is by, CardCache::instance() 
		inline static CardCache* instance() {
			static CardCache instance;
			return &instance;
		}
		////////////////////////////////////////////////////////
		// Disallow access to the constructor, copy constructor, 
		// access to the assignment operator.
	private:
		inline CardCache() {};
		inline CardCache(const CardCache&) {};
		inline CardCache& operator=(const CardCache&);

	public:
		////////////////////////////////////////////////////////////////////////
		// This is essentially the crux of the class.  If we find that the
		// card we're trying to look up is already in the class -- return it.
		// Otherwise create the card at with the passed key (s, v) and the value
		// is the Card(s,v)
		inline Card& getCard(suite s, value v) {
			if ( pool_.find( pair<suite, value>(s,v) ) != pool_.end() )
				return pool_[pair<suite, value>(s, v)];
			else
				return ( pool_[pair<suite, value>(s, v)] = Card(s,v) );
		}

		// I should also add both ways here also; just for fun.
		inline Card& getCard(value v, suite s) {
			if ( pool_.find( pair<suite, value>(s,v) ) != pool_.end() )
				return pool_[pair<suite, value>(s, v)];
			else
				return ( pool_[pair<suite, value>(s, v)] = Card(s,v) );
		}

	private:
		//////////////////////////////////////////////////////////////////////
		// This map object's key is a pair, the pair consists of both a suite
		// and value.  To access a card do: pool_[ pair<suite,value>(v,s) ] ..
		map< pair<suite, value>, Card> pool_;
	};
}

