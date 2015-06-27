#ifndef TERRA_H
#define TERRA_H

namespace Algorithm {

class Terra {

public:

	Terra( unsigned int );
	~Terra();
	float getMapPos( unsigned int, unsigned int );
	void setMapPos( unsigned int, unsigned int, float );
	int * Generate( float ); // Accepts a roughness constant
	unsigned int getDetail() { return this->detail; }

private:

	void Divide( unsigned int );

	unsigned int size;
	unsigned int max;
	unsigned int detail;

	float * map;

};

}

#endif
