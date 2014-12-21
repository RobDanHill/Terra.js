/*We gon' learn you sum random terrain generation using the good old diamond square algorithm.

The diamond square algorithm is essentially an extended version of the midpoint displacement algorithm.

>NULL what's the midpoint displacement algorithm?

Well, faggit think about the name for a moment... I'll wait.

Yeah, it's where you have a vertical line and you find the midpoint of that line and then displace the midpoint on the y-axis by some arbitrary random value and then decrement the random number range by a value you have chosen called the roughness constant, then repeat this for the new line segments and so and so on until some stopping condition, there is no real right or wrong with when to stop.

Now on to the real start the diamond square algorithm.

The way it works is that you have a square grid whose number of points should be a power of two plus one.

See pic related for a shitty drawing I found using google.

So, let's just dive into the code.

Here we are going to set the corners.
[code]
function terrain(detail) {

}
[/code]*/




// Here we create a function to act as a terrain class
// Detail is just our level of detail or rather the roughness constant
function Terrain(detail) {
	this.size = Math.pow(2, detail) + 1; // Make sure the size is a power of 2 + 1
	this.max = this.size - 1;
	// The terrain will be stored as a height map in this two dimensional array
	this.map = new Float32Array(this.size * this.size);
}

Terrain.prototype.get = function(x, y) {
	if ( x < 0 || x > this.max || y < 0 || y > this.max ) return -1;
	return this.map[x + this.size * y];
};

Terrain.prototype.set = function(x, y, val) {
	this.map[x + this.size * y] = val;
};

Terrain.prototype.generate = function(roughness) {
	var self = this; // This is just some weird javascript stuff, don't sweat it

	// Here we set the corner values of our terrain and their heights
	this.set(0, 0, self.max);
	this.set(this.max, 0, self.max / 2);
	this.set(this.max, this.max, 0);
	this.set(0, this.max, self.max / 2);

	divide(this.max);

	// Recursively divide the map into smaller and smaller subdivisions
	function divide(size) {
		var x, y, half = size / 2;
		var scale = roughness * size;

		if ( half < 1 ) return;

		for ( y = half; y < self.max; y += size ) {
			for ( x = half; x < self.max; x += size ) {
				square(x, y, half, Math.random() * scale * 2 - scale);
			}
		}

		for ( y = 0; y < self.max; y += half ) {
			for ( x = (y + half) % size; x <= self.max; x += size ) {
				diamond(x, y, half, Math.random() * scale * 2 - scale);
			}
		}

		divide(size / 2);
	}

	function average(values) {
		var valid = values.filter(function(val) { return val !== -1; });
		var total = valid.reduce(function(sum, val) { return sum + val; }, 0);
		return total / valid.length;
	}

	// Divide the diamonds into squares
	function square(x, y, offset) {
		var avg = average([
			self.get(x - size, y - size), // Upper left
			self.get(x + size, y - size), // Upper right
			self.get(x + size, y + size), // Lower right
			self.get(x - size, y + size)  // Lower left
		]);

		self.set(x, y, avg + offset);
	}

	function diamond(x, y, offset) {
		var avg = average([
			self.get(x, y - size), // Top
			self.get(x + size, y), // Right
			self.get(x, y + size), // Bottom
			self.get(x - size, y)  // Left
		]);

		self.set(x, y, avg + offset);
	}
};
