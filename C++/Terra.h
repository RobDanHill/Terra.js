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

	float *			ValidPoints( float[] );

private:

	float			Average( float[] );
<<<<<<< HEAD
	void			Diamond( unsigned int, unsigned int, unsigned int, unsigned int );
	void			Square( unsigned int, unsigned int, unsigned int, unsigned int );
	//float *			ValidPoints( float[] );
	void			Divide( unsigned int );
=======
	void			Divide_r( unsigned int );
>>>>>>> generate-c++

	unsigned int	size;
	unsigned int	max;
	unsigned int	detail;

	float *			map;

};

}

#endif
