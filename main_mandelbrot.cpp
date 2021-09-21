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
// fiveth argument 			 - radius

int main(int argc, char **argv) {

	int width = 10000, height = 10000;
	double x0 = atof(argv[1]) - atof(argv[3]), x1 = atof(argv[1]) + atof(argv[3]);
	double y0 = atof(argv[2]) - atof(argv[3]), y1 = atof(argv[2]) + atof(argv[3]);
	Complex_t centre(atof(argv[1]), atof(argv[2]));
	int n = 150;

	Color* data = (Color*)malloc(sizeof(Color) * width * height);
	Complex_t z;

	std::cout << x0 << " " << y0 << " ; " << x1 << " " << y1 << std::endl;

	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			Complex_t c = {x0 + (double)(x1-x0) / width * i, y0 + (double)(y1-y0) / width * j};
			//std::cout << c << std::endl;
			int clr = number_it(z, c, n, centre, atof(argv[3]));
			//if (clr != 40)
			//	std::cout << clr << std::endl;
			data[i + width * j].r = 255 - (double)255 * clr / n;
			data[i + width * j].g = 255 - (double)255 * clr / n ;
			data[i + width * j].b = 255 - (double)255 * clr / n;

		//	break;
		}
		//break;
	}

	FILE* file = fopen("mandelbrot.ppm", "wb");
	fprintf(file, "P6\n%d %d\n255\n", width, height);
	fwrite(data, sizeof(Color), height * width, file);
	fclose(file);

	free(data);

	return 0;
}

int number_it(Complex_t z, Complex_t c, int n, Complex_t centre, double dist) {
	
	for (int i = 0 ; i < n; i++) {
		iteration(z, c);
		//std::cout << z << std::endl;
		if (z.re * z.re + z.im * z.im > (centre.re - dist) * (centre.re - dist) + (centre.im - dist) * (centre.im - dist) )
			return i;
	}
	return n;
}

void iteration(Complex_t &z, Complex_t c) {
	z = z * z + c;
}