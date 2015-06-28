#include "Terra.h"

#include <math.h>

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
	map = 0;
	delete map;
}

float Terra::GetMapPos( unsigned int x, unsigned int y ) {
	if ( x < 0 || x > this->max || y < 0 || y > this->max ) return -1;
	return this->map[ x + this->size * y ];
}

void Terra::SetMapPos( unsigned int x, unsigned int y, float value ){
	this->map[ x + this->size * y ] = value;
}

// This is the main function that you will call
// May not need to return anything
int * Terra::Generate( float roughnessConstant ) {

	// How to do lexical closure in C++?
	// Is it even neccessary or possible?
	
	// Set the corners of the map and their height values.
	this->SetMapPos( 0, 0, this->max ); 		
	this->SetMapPos( this->max, 0, this->max / 2 );
	this->SetMapPos( this->max, this->max, 0 );
	this->SetMapPos( 0, this->max, this->max / 2 );

	this->Divide( this->max );

	return NULL;

}

// Recursivly divide the map into smaller rectangles
void Terra::Divide_r( unsigned int size ) {

	float x 	= size / 2;
	float y 	= size / 2;
    float half 	= size / 2;

	float scale = roughnessConstant * size;

	if ( half < 1 ) return;

	// Square
	for ( y = half; y < this->max; y += size ) {
		for ( x = half; x < this->max; x += size ) {
			this->Square( x, y, half, /*Random num * scale * 2 - scale*/ );
		}
	}

	// Diamond
	for ( y = 0; y < this->max; y += size ) {
		for ( x = ( y + half ) % size; x <= this->max; x += size ) {
			this->Diamond( x, y, half, /*Random num * scale * 2 - scale*/ );
		}
	}

	Divide_r( size / 2 );

}

float Terra::Average( float values[] ) {



}
