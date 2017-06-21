/*!
 * @file    dictionary.h
 * @title   Lib dictionary
 * @brief   
 * @author  Edivânia Pontes (edivaniapts@gmail.com)
 * @date    June 2017
 */

#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

#include <iostream>
#include <string>

/*! @brief Dictionary with Array List 
 *	
 * Classe representando um dicionário com armazenamento em vetor não ordenado.
 */
template < typename Key, typename Data, typename KeyComparator >
class DAL
{
protected:

	/*using Key = int; // Alias para Chave.
	using Data = std::string; // Alias para Dado.*/

	struct NodeAL { // Estrutura do nó, representando o par chave-informação.
		Key id; // A chave é um inteiro simples.
		Data info; // A informação é uma cadeia de caracteres.

		NodeAL( Key k_=0, Data d_=0 ) 
		: id(k_)
		, info(d_)
		{ /*empty*/ }
	};

	static const int SIZE = 50; // Tamanho default da lista.

	int m_length; // Comprimento atual da lista.
	int m_capacity; // Capacidade máxima de armazenamento.

	NodeAL * m_data ; // Área de armazenamento : vetor alocado dinamicamente.

	int _search( const Key & _x ) const; // Método de busca auxiliar.

public:

	DAL ( int _MaxSz = SIZE );

	virtual ~DAL( void ) { delete[] m_data; };

	bool remove( const Key & _x, Data & _s ); // Remove da lista.

	bool search( const Key & _x, Data & _s ) const; // Busca publica.

	bool insert( const Key & _newKey, const Data & _newInfo ); // Insere na lista.

	Key min( void ) const; // Recupera a menor chave do dicionário.

	Key max( void ) const; // Recupera a maior chave do dicionário.

	bool sucessor( const Key & _x , Key & _y ) const; // Recupera em _y a chave sucessora a _x , se existir ( true ).

	bool predecessor( const Key & _x , Key & _y ) const; // Recupera em _y a chave antecessora a _x , se existir ( true ).

	bool full( void ) const;

	bool empty( void ) const;

	int capacity( void ) const;

	int size( void ) const;

	// ! Sends back to the output stream an ascii representation for the list.
	inline friend
	std::ostream & operator<<( std::ostream & _os , const DAL & _oList ) {
		_os << "[ ";
		for ( int i (0); i < _oList.m_length; ++i )
			_os << " { id : " << _oList.m_data[ i ].id << ", info : "
			    << _oList.m_data [ i ].info << " }  ";
		_os << "]";
		return _os;
	}
};

//class DSAL : public DAL // Indicação de herança.
template < typename Key, typename Data, typename KeyComparator >
class DSAL : public DAL< Key, Data, KeyComparator > // Indicação de herança.
{
private:

	int _search ( const Key & _x ) const ; // Método de busca auxiliar.

public:

	DSAL ( int _MaxSz ) : DAL< Key, Data, KeyComparator > ( _MaxSz ) { /* Empty */ };

	virtual ~DSAL( void ) { /* Empty */ };

	// Métodos para sobrescrever .
	bool remove ( const Key & _x , Data & );

	bool insert ( const Key & _novaId , const Data & _novaInfo );

	Key min( void ) const; // Recupera a menor chave do dicionário.

	Key max( void ) const; // Recupera a maior chave do dicionário.

	// Recupera em _y a chave sucessora a _x , se existir ( true ).
	bool sucessor( const Key & _x, Key & _y ) const;

	// Recupera em _y a chave antecessora a _x , se existir ( true ).
	bool predecessor( const Key & _x, Key & _y ) const;
};

#include "../src/dictionary.cpp"

#endif