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

	/*
	using Key = int; // Alias para Chave.
	using Data = std::string; // Alias para Dado.
	*/
	
	//<! Estrutura do nó, representando o par chave-informação.
	struct NodeAL {  
		Key id;    // A chave é um inteiro simples.
		Data info; // A informação é uma cadeia de caracteres.

		NodeAL( Key k_=0, Data d_=0 )
		{
			id = k_;
			info = d_; 
		}
	};

	static const int SIZE = 50; //<! Tamanho default da lista.
	int m_length;               //<! Comprimento atual da lista.
	int m_capacity;             //<! Capacidade máxima de armazenamento.
	NodeAL * m_data ; 			//<! Área de armazenamento : vetor alocado dinamicamente.

	int _search( const Key & _x ) const; // Método de busca auxiliar.

public:
	/*! 
	 *  @brief Construtor que aloca dinamicamente em *m_data um vetor cujo tamanho é determinado passado por _MaxSz;
	 *	@param _MaxSz O tamanho da capacidade. 
	 */
	DAL( int _MaxSz = SIZE );

	/*!
	 *  @brief Destruidor da classe que libera a memória apontada por m_data.
	 */
	virtual ~DAL( void );

	/*!
	 *  @brief  Remove informação relacionada a chave _x do array.
	 *  @param  _x A chave.
	 *  @return True se a remorção foi bem sucedida, false caso contrário.
	 */
	bool remove( const Key & _x );

	/*!
	 *  @brief  Busca e recupera em _s a informação relacionada a chave _x no array.
	 *  @param  _x A chave.
	 *  @param  _s A informação.
	 *  @return True se o dado foi encontrado, false caso contrário.
	 */
	bool search( const Key & _x, Data & _s ) const; // Busca publica.

	/*!
	 *  @brief  Insere chave-informação no array, se array não estiver cheio e chave ainda não existir nele.
	 *  @param  _newKey A nova chave.
	 *  @param  _newInfo A nova informação.
	 *  @return True se a inserção foi bem sucedida, false caso contrário.
	 */
	bool insert( const Key & _newKey, const Data & _newInfo ); // Insere na lista.

	/*!
	 *  @brief Recupera a menor chave do dicionário.
	 *  @return A menor chave.
	 */
	Key min( void ) const; // 

	/*!
	 *  @brief Recupera a maior chave do dicionário.
	 *  @return A maior chave.
	 */
	Key max( void ) const;

	bool sucessor( const Key & _x , Key & _y ) const; // Recupera em _y a chave sucessora a _x , se existir ( true ).

	bool predecessor( const Key & _x , Key & _y ) const; // Recupera em _y a chave antecessora a _x , se existir ( true ).

	/*! 
	 *  @brief Informa se o dicionário está lotado ou não.
	 *	@return True se o container chegou a sua capacidade máxima, false caso contrário. 
	 */
	bool full( void ) const;

	/*! 
	 *  @brief Informa se o dicionário está vazio ou não.
	 *	@return True se o container tem elementos, false caso contrário. 
	 */
	bool empty( void ) const;

	/*! 
	 *  @brief Informa a capcidade de elementos que o dicionário suporta.
	 *	@return A capacidade. 
	 */
	int capacity( void ) const;

	/*! 
	 *  @brief Informa o número de elementos contidos no dicionário.
	 *	@return A comprimento. 
	 */
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


/*! @brief Dictionary with Sorted Array List 
 *	
 * Classe representando um dicionário com armazenamento em vetor ordenado.
 */
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

#include "dictionary.cpp"

#endif