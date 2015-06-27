#ifndef TERRA_H
#define TERRA_H

namespace Algorithm {

class Terra {

public:

					Terra( unsigned int );
				   ~Terra();
	float			GetMapPos( unsigned int, unsigned int );
	void			SetMapPos( unsigned int, unsigned int, float );
	int *			Generate( float ); // Accepts a roughness constant
	unsigned int	GetDetail() const { return this->detail; }

private:

	float			Average( float[] );
	void			Divide( unsigned int );

	unsigned int	size;
	unsigned int	max;
	unsigned int	detail;

	float *			map;

};

}

#endif
