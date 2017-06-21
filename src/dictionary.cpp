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
bool DAL<Key, Data, KeyComparator>::insert( const Key & _newKey, const Data & _newInfo )
{
	if( full() )
		return false;

	NodeAL new_node( _newKey, _newInfo ); 
	m_data[m_length++] = new_node;

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