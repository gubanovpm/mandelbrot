#include <SFML/Graphics.hpp>
#include <Windows.h>

#include "complex.hpp"

struct Color {
	unsigned char r, g, b;
};

Complex_t func(Complex_t z, Complex_t c, int n);

int main() {

	int width = 800, height = 800;
	double x0 = -2.0, x1 = 2.0;
	double y0 = -2.0, y1 = 2.0;
	int n = 400, j_n = 20;

	Complex_t z = {0, 0};
	Complex_t j_c = {-0.8, 0.16};
	Color* data_mondelbrot = (Color*)malloc(sizeof(Color) * width * height);
	Color* data_julia = (Color*)malloc(sizeof(Color) * width * height);

	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			Complex_t c = {x0 + (x1-x0) / width * i, y0 + (y1-y0) / width * j};
			Complex_t j_z = {x0 + (x1-x0) / width * i, y0 + (y1-y0) / width * j};

			Complex_t f   = func(z, c, n);
			Complex_t j_f = func(j_z, j_c, j_n);
			data_mondelbrot[i + width * j].r = 0;
			data_mondelbrot[i + width * j].g = f.re * 255;
			data_mondelbrot[i + width * j].b = f.im * 255;

			data_julia[i + width * j].r = 0;
			data_julia[i + width * j].g = j_f.re * 255;
			data_julia[i + width * j].b = j_f.im * 255;
		}
	}

	FILE* file_mandelbrot = fopen("mondelbrot.ppm", "wb");
	fprintf(file_mandelbrot, "P6\n%d %d\n255\n", width, height);
	fwrite(data_mondelbrot, sizeof(Color), height * width, file_mandelbrot);
	fclose(file_mandelbrot);

	FILE* file_julia = fopen("julia.ppm", "wb");
	fprintf(file_julia, "P6\n%d %d\n255\n", width, height);
	fwrite(data_julia, sizeof(Color), height * width, file_julia);
	fclose(file_julia);

	free(data_mondelbrot);
	free(data_julia);

	return 0;
}

Complex_t func(Complex_t z, Complex_t c, int n) {
	if (n == 0)
		return z;
	Complex_t temp = func(z, c, n - 1);
	return temp * temp + c;
}
