#include <iostream>
#include <cmath>
#include <cstdlib>


void draw_tree(std::size_t height)
{
	using std::size_t;
	using std::cout;
	using std::endl;

	size_t max_width = height * 2 + 1;

	size_t row_width;
	size_t padding;

	cout << endl;

	for(size_t row = 0; row < height; row++) {
		row_width = (row * 2 + 1);
		padding = (max_width - row_width) / 2;
		
		for(size_t i = 0; i < max_width; i++) {
			cout << ((i < padding || i >= padding + row_width) ? " " : "*");
		}

		cout << "\t\t"
			 << "row=" << row << ", "
			 << "height=" << height << ", "
			 << "max_width=" << max_width << ", "
			 << "row_width=" << row_width << ", "
			 << "padding=" << padding;

		cout << endl;
	}

	size_t root_height = (height < 4 ? 1 : (height < 8) ? 2 : 3);
	size_t root_width = (height / 3 / root_height);
	root_width = (height < 3 ? 1 : (root_width < 3 ? 3 : root_width));

	padding = (max_width - root_width) / 2;
	for(size_t r = 0; r < root_height; r++) {
		for(size_t i = 0; i < max_width; i++) {
			cout << ((i < padding || i >= padding + root_width) ? " " : "*");
		}
		cout << endl;
	}
}


int main(int argc, char** argv)
{
	draw_tree(argc > 1 ? atoi(argv[1]) : 16);

	return 0;
}
