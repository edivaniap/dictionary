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
		std::cout << "\n>>> teste 1.1: construtor\n\n";
		DAL<int, float, int_comparator> dict(5);
		assert( dict.full() == false );
		assert( dict.empty() );
		assert( dict.capacity() == 5 );
		assert( dict.size() == 0 );
		std::cout << ">> dictionary: " << dict << std::endl;

		//teste insert
		std::cout << "\n>>> teste 1.2: inserts\n\n";
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

		//teste min e max
		std::cout << "\n>>> teste 1.3: min e max\n\n";

		assert( dict.min() ==  0 );
		assert( dict.max() ==  7 );
		

		//teste sucessor e antecessor
		int chave; //aux para testes dos metodos
		std::cout << "\n>>> teste 1.4: sucessor e antecessor\n\n";
		assert( dict.sucessor(7, chave) );
		assert( chave == 2 );   //chave recuperada na busca
		assert( dict.sucessor(6, chave) == false ); //ultimo elemento nao tem sucessor
		assert( chave == 2 );   //valor continua o antigo
		assert( dict.predecessor(7, chave) );
		assert( chave == 3 );   //chave recuperada na busca
		assert( dict.predecessor(0, chave) == false ); //primeiro elemento nao tem antecessor
		assert( chave == 3 );   //valor continua o antigo



		//teste search
		float elem; //aux para teste metodo de busca
		std::cout << "\n>>> teste 1.5: search\n\n";
		assert( dict.search(2, elem) ); //existe
		assert( elem == 745.3f );   //valor recuperado na busca
		assert( dict.search(8, elem) == false ); //nao existe
		assert( elem == 745.3f );   //continua valor anterior pois não foi setado

		//teste remove
		std::cout << "\n>>> teste 1.6: removes\n\n";
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
		//teste construtor
		std::cout << "\n>>> teste 2.1: construtor\n\n";
		DAL<int, std::string, int_comparator> dict;
		assert( dict.full() == false );
		assert( dict.capacity() == 50 );
		std::cout << ">> dictionary: " << dict << std::endl;

		//teste insert
		std::cout << "\n>>> teste 2.2: inserts\n\n";
		assert ( dict.insert(5, "azul") );
		assert( not dict.empty() );
		assert ( dict.insert(3, "preto") );
		assert ( dict.insert(9, "vermelho") );
		assert ( dict.insert(3, "amarelo") == false ); //chave repitida
		std::cout << ">> dictionary: " << dict << std::endl;

		//teste min e max
		assert( dict.min() ==  3 );
		assert( dict.max() ==  9 );

		//teste search
		std::string elem;
		assert( dict.search(3, elem) ); //existe
		assert( elem == "preto" );   //valor recuperado na busca
		assert( dict.search(8, elem) == false ); //nao existe
		assert( elem == "preto" );   //continua valor anterior pois não foi setado

		//teste remove
		std::cout << "\n>>> teste 2.3: removes\n\n";
		assert( dict.remove(5) ); 
		assert( dict.remove(0) == false ); //nao existe
		assert( dict.remove(9) );         
		assert( dict.size() == 1 );
		assert( dict.remove(3) );
		assert( dict.remove(2) == false ); //dicionario vazio
		std::cout << ">> dictionary: " << dict << std::endl;

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