/*!
 * @file    dictionary.cpp
 * @title   Lib dictionary
 * @brief   
 * @author  Edivânia Pontes (edivaniapts@gmail.com)
 * @date    June 2017
 */

#include "dictionary.h"

DAL::DAL( int size_ )
{
	m_capacity = size_;
	m_length = 0;
	m_data = new NodeAL[ size_ ];
}

bool DAL::insert( const Key & _newKey, const Data & _newInfo )
{
	if( full() )
		return false;

	NodeAL new_node( _newKey, _newInfo ); 
	m_data[m_length++] = new_node;

	return true;
}

bool DAL::full() const
{
	return ( m_capacity == m_length );
}

bool DAL::empty() const
{
	return (  m_length == 0 );
}

int DAL::capacity( void ) const
{
	return m_capacity;
}

int DAL::size( void ) const
{
	return m_length;
}