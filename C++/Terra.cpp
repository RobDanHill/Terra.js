#include "Terra.h"

#include <math.h>

using namespace Algorithm;

Terra::Terra( unsigned int detail ) {

	this->detail = detail;
	this->size = ( detail * detail ) + 1;
	this->max = this->size - 1;

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

//--GetDetail--

float Terra::Average( float values[] ) {



}