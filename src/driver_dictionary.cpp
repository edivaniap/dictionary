/*!
 * @file    driver_dictionary.cpp
 * @title   Driver dictionary
 * @brief   
 * @author  Edivânia Pontes (edivaniapts@gmail.com)
 * @date    June 2017
 */

#include <cassert>
#include "dictionary.h"

class MyKeyComparator
{
public:
	bool operator ()( const int & lhs , const int & rhs ) const
	{
		return lhs < rhs ;
	}
};

int main()
{
	/* Assertions */ 
	{
		DAL<int, std::string, MyKeyComparator> dict;
		assert( not dict.full() );
		assert( dict.empty() );
		assert( dict.capacity() == 50 );
		assert( dict.size() == 0 );
	}
	
	/* Código Cliente */
	{
		/*// DAL < int, std::string, MyKeyComparator > myList ( 50 );
		DSAL < int, std::string, MyKeyComparator > myList ( 50 );
		std::cout << " >>> Inserindo { 2015003129, \"Jack\" }" << std::endl ;
		myList.insert( 2015003129, " Jack " );
		std::cout << " >>> Inserindo { 2014065190, \" John \" }" << std::endl ;
		myList.insert( 2014065190, " John " );*/
	}

	return 0;
}