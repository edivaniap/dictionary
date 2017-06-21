/*!
 * @file    driver_dictionary.cpp
 * @title   Driver dictionary
 * @brief   
 * @author  Edivânia Pontes (edivaniapts@gmail.com)
 * @date    June 2017
 */

#include <cassert>
#include "dictionary.h"

int main()
{
	DAL dic;
	assert( not dic.full() );
	assert( dic.empty() );
	assert( dic.capacity() == 50 );
	assert( dic.size() == 0 );
	return 0;
}