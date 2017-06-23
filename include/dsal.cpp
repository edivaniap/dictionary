/*!
 * @file    dsal.cpp
 * @title   Lib dictionary : DSAL
 * @brief   Implementação dos métodos do DSAL
 * @author  Edivânia Pontes (edivaniapts@gmail.com)
 * @date    June 2017
 */

#include "dictionary.h"

//#define DAL< Key, Data, KeyComparator > DAL< Key, Data, KeyComparator >< Key, Data, KeyComparator > // Alias para DAL< Key, Data, KeyComparator >
	/*!
	 *  @brief Método de busca auxiliar usando busca binária iterativa a partir de uma chave.
	 *  @param _x A chave.
	 *  @return O indice do elemento encontrado.
	 */
template < typename Key, typename Data, typename KeyComparator >
int DSAL<Key, Data, KeyComparator>::_search ( const Key & _x ) const
{
	KeyComparator compare;

	//<! iterative_binary_search by indices
	int first, last, indice;
    first = 0; 
    last = DAL< Key, Data, KeyComparator >::m_length - 1;

    while ( first <= last )
    {
        indice = ( first + last ) / 2;
        
        if ( DAL< Key, Data, KeyComparator >::m_data[indice].id == _x )
            return indice;
        
        if ( compare( DAL< Key, Data, KeyComparator >::m_data[indice].id , _x ) )
            first = indice + 1;
        else
            last = indice - 1;
    }

    return -1;
}

template < typename Key, typename Data, typename KeyComparator >
bool DSAL<Key, Data, KeyComparator>::remove( const Key & _x )
{
		//<! verifica de array está vazio
	if( DAL< Key, Data, KeyComparator >::empty() )
	{
		std::cout << ">> [ remove() ] Error: cannot remove an element from an empty dictionary!\n";
		return false;
	}

	int indice = _search( _x );

	//<! verifica se existe dado com a chave passada
	if( indice == -1 )
	{
		std::cout << ">> [ remove() ] Error: key not found on the dictionary!\n";
		return false;
	}

	//<! removendo dado do array
	//dado na posição que contém a chave passada passa a ser o último dado do array, e diminui o comprimento
	DAL< Key, Data, KeyComparator >::m_data[ indice ] = DAL< Key, Data, KeyComparator >::m_data[ --DAL< Key, Data, KeyComparator >::m_length ]; 

	return true;
}

template < typename Key, typename Data, typename KeyComparator >
bool DSAL<Key, Data, KeyComparator>::insert( const Key & _novaId , const Data & _novaInfo )
{
	//<! verifica de array já está lotado
	if( DAL< Key, Data, KeyComparator >::full() )
	{
		std::cout << ">> [ insert() ] Error: cannot insert a new element in a full dictionary!\n";
		return false;
	}
	
	//<! caso já exista elemento com esta key inserida, não inserir
	if( not ( _search( _novaId ) == -1 ) ) 
	{
		std::cout << ">> [ insert() ] Error: key already exists on the dictionary!\n";
		return false;
	}

	//<! inserindo dado no array ordenadamente
	KeyComparator compare; //<! functor que comparará as chaves
	int i = DAL< Key, Data, KeyComparator >::m_length - 1; //<! indice para percorrer array

	//<! enquanto i >= 0 e new < a[i]
	while (i >= 0 and compare( _novaId, DAL< Key, Data, KeyComparator >::m_data[i].id ) )
	{
		//<! abrir espaço e deconcatena i
		DAL< Key, Data, KeyComparator >::m_data[i+1].id = DAL< Key, Data, KeyComparator >::m_data[i].id; 
		DAL< Key, Data, KeyComparator >::m_data[i+1].info = DAL< Key, Data, KeyComparator >::m_data[i].info; 
		i--;
	}

	//<! inserindo dado no array
	//DAL< Key, Data, KeyComparator >::NodeAL new_node( _novaId, _novaInfo ); 
	DAL< Key, Data, KeyComparator >::m_data[i+1].id = _novaId;
	DAL< Key, Data, KeyComparator >::m_data[i+1].info = _novaInfo;
	DAL< Key, Data, KeyComparator >::m_length++;
	return true;
}


template < typename Key, typename Data, typename KeyComparator >
Key DSAL<Key, Data, KeyComparator>::min( void ) const
{
	return DAL< Key, Data, KeyComparator >::m_data[0].id; 
}

template < typename Key, typename Data, typename KeyComparator >
Key DSAL<Key, Data, KeyComparator>::max( void ) const
{
	return DAL< Key, Data, KeyComparator >::m_data[ DAL< Key, Data, KeyComparator >::m_length -1 ].id;
}
	/*!
	 *  @brief Recupera em _y a chave sucessora a _x.
	 *	@note  Usa a nova busca (binária).
	 *  @return True se existir, false caso contrário.
	 */

template < typename Key, typename Data, typename KeyComparator >
bool DSAL<Key, Data, KeyComparator>::sucessor( const Key & _x, Key & _y ) const
{
	int indice = _search( _x );

	//<! se não achar elemento ou se for o último indice : false
	if( indice == -1 )
	{
		std::cout << ">> [ sucessor() ] Error: key not found on the dictionary!\n";
		return false;
	}

	if( indice == ( DAL< Key, Data, KeyComparator >::m_length - 1 ) )
	{
		std::cout << ">> [ sucessor() ] Error: cannot recover sucessor from the last key on array!\n";
		return false;
	}

	//<! caso contrário, recupera em _y informação : true
	_y = DAL< Key, Data, KeyComparator >::m_data[ indice+1 ].id;
	return true;
}

template < typename Key, typename Data, typename KeyComparator >
bool DSAL<Key, Data, KeyComparator>::predecessor( const Key & _x, Key & _y ) const
{
	int indice = _search( _x );

	//<! se não achar elemento ou se for o primeiro indice : false
	if( indice == -1 )
	{
		std::cout << ">> [ predecessor() ] Error: key not found on the dictionary!\n";
		return false;
	}

	if( indice == 0 )
	{
		std::cout << ">> [ predecessor() ] Error: cannot recover predecessor from the first key on array!\n";
		return false;
	}


	//<! caso contrário, recupera em _y informação : true
	_y = DAL< Key, Data, KeyComparator >::m_data[ indice-1 ].id;
	return true;
}