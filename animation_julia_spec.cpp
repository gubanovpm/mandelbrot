#include <cstdlib>
#include <string>
#include "complex.hpp"

struct Color {
	unsigned char r, g, b;
};

int number_it(Complex_t z, Complex_t c, int n, Complex_t centre, double dist);
void iteration(Complex_t &z, Complex_t c);

// first and second argument - coordinate of centre 
// third argument 			 - radius

int main(int argc, char **argv) {

	int width = 2000, height = 2000;
	std::cout << "i'm here!\n" ;
	double x0 = atof(argv[1]) - atof(argv[3]), x1 = atof(argv[1]) + atof(argv[3]);
	double y0 = atof(argv[2]) - atof(argv[3]), y1 = atof(argv[2]) + atof(argv[3]);
	Complex_t centre(atof(argv[1]), atof(argv[2]));
	int n = 100;

	int counter = 0, end_count = 720;

	while (counter != end_count + 1) {
		Color* data = new Color [width * height];
		Complex_t z{-1.5 * (end_count - counter) / end_count, -0.5 + 1.5 * counter / end_count};

		std::cout << z << "current is " << counter << " from " << end_count << std::endl;

		for (int j = 0; j < height; j++) {
			for (int i = 0; i < width; i++) {
				Complex_t c = {x0 + (double)(x1-x0) / width * i, y0 + (double)(y1-y0) / width * j};
				int clr = number_it(c, z, n, centre, atof(argv[3]));
				data[i + width * j].r = 255 - (double)255 * clr / n;
				data[i + width * j].g = 255 - (double)255 * clr / n ;
				data[i + width * j].b = 255 - (double)255 * clr / n;
			}
		}

		std::string str = std::to_string(counter);
		std::string path_and_name_file = "./animation/complex_" + str + ".ppm";
		int size = path_and_name_file.length();
		char *result = new char [size + 1];
		for (int q = 0; q < size; q++)
			result[q] = path_and_name_file[q];
		result[size] = 0;

		FILE* file = fopen(result, "wb");
		fprintf(file, "P6\n%d %d\n255\n", width, height);
		fwrite(data, sizeof(Color), height * width, file);
		fclose(file);
		counter++;

		delete [] result;
		delete [] data;
	}

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