/*!
 * @file    driver_dictionary.cpp
 * @title   Driver dictionary
 * @brief   
 * @author  Edivânia Pontes (edivaniapts@gmail.com)
 * @date    June 2017
 */

#include <iostream>
#include <cassert>
#include "dictionary.h"

class int_comparator
{
public:
	bool operator ()( const int & lhs , const int & rhs ) const
	{
		return lhs < rhs ;
	}
};

class str_comparator
{
public:
	bool operator ()( const std::string & lhs , const std::string & rhs ) const
	{
		return lhs < rhs ;
	}
};

int main()
{
	/* Assertions */ 
	{
		//teste construtor
		std::cout << "\n>>> teste 1: construtor\n\n";
		DAL<int, float, int_comparator> dict(5);
		assert( dict.full() == false );
		assert( dict.empty() );
		assert( dict.capacity() == 5 );
		assert( dict.size() == 0 );
		std::cout << ">> dictionary: " << dict << std::endl;

		//teste insert
		std::cout << "\n>>> teste 2: inserts\n\n";
		assert ( dict.insert(0, 100.4) );
		assert( not dict.empty() );
		assert ( dict.insert(3, 150.7) );
		assert ( dict.insert(0, 656.7) == false ); //chave repitida
		assert ( dict.insert(7, 899.0) );
		assert ( dict.insert(2, 745.3) );
		assert ( dict.insert(6, 445.6) );
		assert ( dict.insert(8,   0.6) == false ); //dicionario lotado
		assert( dict.full() );
		assert( dict.size() == 5 );
		std::cout << ">> dictionary: " << dict << std::endl;

		//teste remove
		std::cout << "\n>>> teste 3: removes\n\n";
		assert( dict.remove(5) == false ); //nao existe
		assert( dict.remove(3) );          //existe
		assert( dict.remove(0) );
		assert( dict.size() == 3 );
		assert( dict.remove(7) );
		assert( dict.remove(2) );
		assert( dict.remove(6) );
		assert( dict.remove(7) == false ); //dicionario vazio
		std::cout << ">> dictionary: " << dict << std::endl;
	}

	/* Testando com tipo de dado string */
	{
		//DAL<int, std::string, int_comparator> dict; //terminate called after throwing an instance of 'std::logic_error'
		//DAL<std::string, float, int_comparator> dict; //chave do tipo string dá certo
	}
	
	/* Código Cliente */
	{
		//std::cout << "\n>>> teste x: código cliente\n\n";

		/*// DAL < int, std::string, MyKeyComparator > myList ( 50 );
		DSAL < int, std::string, MyKeyComparator > myList ( 50 );
		std::cout << " >>> Inserindo { 2015003129, \"Jack\" }" << std::endl ;
		myList.insert( 2015003129, " Jack " );
		std::cout << " >>> Inserindo { 2014065190, \" John \" }" << std::endl ;
		myList.insert( 2014065190, " John " );*/
	}
	
	std::cout << "\n>>> normal exiting...\n\n";

	return 0;
}