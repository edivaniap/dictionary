/*!
 * @file    dictionary.cpp
 * @title   Lib dictionary
 * @brief   
 * @author  Edivânia Pontes (edivaniapts@gmail.com)
 * @date    June 2017
 */

#include "dictionary.h"

template < typename Key, typename Data, typename KeyComparator >
DAL<Key, Data, KeyComparator>::DAL( int _MaxSz )
{
	m_capacity = _MaxSz;
	m_length = 0;
	m_data = new NodeAL[ _MaxSz ];
}

template < typename Key, typename Data, typename KeyComparator >
DAL<Key, Data, KeyComparator>::~DAL()
{
	delete[] m_data;
}

template < typename Key, typename Data, typename KeyComparator >
int DAL<Key, Data, KeyComparator>::_search( const Key & _x ) const
{
	//<! se achar elemento com chave igual _x  no array, retornar o indice
	for (int i = 0; i < m_length; ++i)
		if ( m_data[i].id == _x )
			return i;

	//<! se não encontrar retornar -1
	return -1;
}

template < typename Key, typename Data, typename KeyComparator >
bool DAL<Key, Data, KeyComparator>::insert( const Key & _newKey, const Data & _newInfo )
{
	//<! verifica de array já está lotado
	if( full() )
	{
		std::cout << ">> [ insert() ] Error: cannot insert a new element in a full dictionary!\n";
		return false;
	}
	
	//<! caso já exista elemento com esta key inserida, não inserir
	if( not (_search( _newKey ) == -1) ) 
	{
		std::cout << ">> [ insert() ] Error: key already exists on the dictionary!\n";
		return false;
	}

	//<! inserindo dado no array
	NodeAL new_node( _newKey, _newInfo ); 
	m_data[m_length++] = new_node;

	return true;
}

template < typename Key, typename Data, typename KeyComparator >
bool DAL<Key, Data, KeyComparator>::remove( const Key & _x )
{
	//<! verifica de array está vazio
	if( empty() )
	{
		std::cout << ">> [ remove() ] Error: cannot remove an element from an empty dictionary!\n";
		return false;
	}

	//<! verifica se existe dado com a chave passada
	if( _search( _x ) == -1 )
	{
		std::cout << ">> [ remove() ] Error: key not found on the dictionary!\n";
		return false;
	}

	//<! removendo dado do array
	//dado na posição que contém a chave passada passa a ser o último dado do array, e diminui o comprimento
	m_data[ _search( _x ) ] = m_data[--m_length]; 

	return true;
}

template < typename Key, typename Data, typename KeyComparator >
bool DAL<Key, Data, KeyComparator>::full() const
{
	return ( m_capacity == m_length );
}

template < typename Key, typename Data, typename KeyComparator >
bool DAL<Key, Data, KeyComparator>::empty() const
{
	return (  m_length == 0 );
}

template < typename Key, typename Data, typename KeyComparator >
int DAL<Key, Data, KeyComparator>::capacity( void ) const
{
	return m_capacity;
}

template < typename Key, typename Data, typename KeyComparator >
int DAL<Key, Data, KeyComparator>::size( void ) const
{
	return m_length;
}