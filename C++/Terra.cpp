#include "Terra.h"

#include <math.h>
#include <iostream>

using namespace Algorithm;

/***
 * The Terra constructor
 * @param unsigned int
 */
Terra::Terra( unsigned int detail ) {

	this->detail = detail;
	// Size must be a power of 2+1
	this->size = ( detail * detail ) + 1;
	this->max = this->size - 1;
	// The terrain will be stored as a height map in a 2D array
	this->map = new float[ this->size * this->size ];

}

Terra::~Terra() {
	delete[] map;
	map = 0;
}

float Terra::GetMapPos( unsigned int x, unsigned int y ) {

	if ( x < 0 || x > this->max || y < 0 || y > this->max ) return -1;
	return this->map[ x + this->size * y ];

}

void Terra::SetMapPos( unsigned int x, unsigned int y, float value ) {
	this->map[ x + this->size * y ] = value;
}

int * Terra::Generate( float roughnessConstant ) {
	
	int number;
	int * ptr = &number;

	return ptr;
}

float Terra::Average( float values[] ) {

	return 1.0f;

}

float * Terra::ValidPoints( float values[] ) {

	// Test array
	float values2[] = { 1, -1, 2, 5 };

	unsigned int numValid = 0;
	float * validValues;

	for ( unsigned int i = 0; i < ( sizeof( values2 ) / sizeof( float ) ); i++ ) {
		//std::cout << values2[ i ] << std::endl;
		if ( values2[ i ] > -1 ) numValid++;
	}

	//std::cout << std::endl;
	//std::cout << std::endl;

	validValues = new float[ numValid ];
	numValid = 0; // Re-use numValid as counter for new array

	for ( unsigned int i = 0; i < ( sizeof( values2 ) / sizeof( float ) ); i++ ) {
		if ( values2[ i ] > -1 ) { validValues[ numValid ] = values2[ i ]; numValid++; }
	}

	for ( unsigned int i = 0; i < ( sizeof( validValues ) / sizeof( float ) ); i++ ) {
		std::cout << validValues[ i ] << std::endl;
	}

	return validValues;

}
