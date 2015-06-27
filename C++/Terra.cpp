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

int * Terra::Generate( float roughnessConstant ) {
	
	return ;
}
