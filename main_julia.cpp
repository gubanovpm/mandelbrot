#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <cstdlib>
#include "complex.hpp"

struct Color {
	unsigned char r, g, b;
};

int number_it(Complex_t z, Complex_t c, int n, Complex_t centre, double dist);
void iteration(Complex_t &z, Complex_t c);

// first and second argument - coordinate of centre 
// third and fourth 		 - coordinate of c - point
// fiveth argument 			 - radius

int main(int argc, char **argv) {

	int width = 10000, height = 10000;
	double x0 = atof(argv[1]) - atof(argv[5]), x1 = atof(argv[1]) + atof(argv[5]);
	double y0 = atof(argv[2]) - atof(argv[5]), y1 = atof(argv[2]) + atof(argv[5]);
	Complex_t centre(atof(argv[1]), atof(argv[2]));
	int n = 150;

	Color* data = new Color [width * height];
	Complex_t z(atof(argv[3]), atof(argv[4]));

	std::cout << x0 << " " << y0 << " ; " << x1 << " " << y1 << std::endl;

	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			Complex_t c = {x0 + (double)(x1-x0) / width * i, y0 + (double)(y1-y0) / width * j};

			int clr = number_it(c, z, n, centre, atof(argv[5]));
			data[i + width * j].r = 255 - (double)255 * clr / n;
			data[i + width * j].g = 255 - (double)255 * clr / n ;
			data[i + width * j].b = 255 - (double)255 * clr / n;
		}
	}

	FILE* file = fopen("julia.ppm", "wb");
	fprintf(file, "P6\n%d %d\n255\n", width, height);
	fwrite(data, sizeof(Color), height * width, file);
	fclose(file);

	delete [] data;

	return 0;
}

int number_it(Complex_t z, Complex_t c, int n, Complex_t centre, double dist) {
	
	for (int i = 0 ; i < n; i++) {
		iteration(z, c);
		if (z.re * z.re + z.im * z.im > (centre.re - dist) * (centre.re - dist) + (centre.im - dist) * (centre.im - dist) )
			return i;
	}
	return n;
}

void iteration(Complex_t &z, Complex_t c) {
	z = z * z + c;
}
