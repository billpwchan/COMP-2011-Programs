#include "function_definition.h"



int main() {
	char canvas[HEIGHT][WIDTH];
	int command = 0;
	int startx, starty, endx, endy;
	char color;

	//Here you should add codes to print out the canvas
	initiate_canvas(canvas);
	print_canvas(canvas);

	do {
		cout << "Select the command:" << endl;
		cout << "1 - draw a line" << endl;
		cout << "2 - draw a rectangle" << endl;
		cout << "3 - fill a color" << endl;
		cout << "4 - quit the program" << endl;
		cin >> command;

		switch (command) {
		case 1:
			//Here you should add codes to implement:
			//0. Ask for inputs of coordinates
			//1. Check whether the coordinates is valid (inside the canvas)
			//2. Check whether the line is vertical or horizontal
			//3. Ask for another input if the one of the check is not passed
			//4. Add a function to print the line on the canvas

			start_coordinate_initialization(startx, starty);
			end_coordinate_initialization(endx, endy);
			while (startx > 19 || startx < 0 || starty > 9 || starty < 0) {
				cout << "Out of canvas! " << endl;
				start_coordinate_initialization(startx, starty);
			}
			while (endx > 19 || endx < 0 || endy > 9 || endy < 0) {
				cout << "Out of canvas! " << endl;
				end_coordinate_initialization(endx, endy);
			}
			while ((startx != endx) && (starty != endy)) {
				cout << "You can only draw horizontal line or vertical line. " << endl;
				end_coordinate_initialization(endx, endy);
			}
			draw_line(canvas, startx, starty, endx, endy);
			print_canvas(canvas);

			break;

		case 2:
			//Here you should add codes to implement:
			//0. Ask for inputs of coordinates
			//1. Check whether the coordinates is valid (inside the canvas)
			//2. Ask for another input if the check is not passed
			//3. Add a function to print the rectangular on the canvas

			start_coordinate_initialization(startx, starty);
			end_coordinate_initialization(endx, endy);
			while (startx > 19 || startx < 0 || starty > 9 || starty < 0) {
				cout << "Out of canvas! " << endl;
				start_coordinate_initialization(startx, starty);
			}
			while (endx > 19 || endx < 0 || endy > 9 || endy < 0) {
				cout << "Out of canvas! " << endl;
				end_coordinate_initialization(endx, endy);
			}
			draw_rectangle(canvas, startx, starty, endx, endy);
			print_canvas(canvas);
			break;
		case 3:
			//Here you should add codes to implement:
			//0. Ask for inputs of coordinates and color type
			//1. Check whether the coordinates is valid (inside the canvas)
			//2. Ask for another input if the check is not passed
			//3. Add a function to fill in the color to the enclosed area
			start_coordinate_initialization(startx, starty);
			while (startx > 19 || startx < 0 || starty > 9 || starty < 0) {
				cout << "Out of canvas! " << endl;
				start_coordinate_initialization(startx, starty);
			}
			cout << "Enter a color (R, G, B): " << endl;
			cin >> color;
			while (color != 'R' && color != 'G' && color != 'B') {
				cout << "Not defined color! " << endl;
				cout << "Enter a color (R, G, B): " << endl;
				cin >> color;
			}
			fill_area(canvas, startx, starty, color);
			print_canvas(canvas);
			break;
		}

		//Here you should add codes to print out the canvas

	} while (command != 4);

	return 0;
}

void initiate_canvas(char temp[][WIDTH]) {
	for (int i = 0; i < HEIGHT; i++)
		for (int j = 0; j < WIDTH; j++)
			temp[i][j] = ' ';
}

void print_canvas(const char temp[][WIDTH]) {
	for (int i = 0; i < WIDTH + 2; i++) {
		cout << '#';
	} cout << endl;
	for (int i = 0; i < HEIGHT; i++) {
		cout << '#';
		for (int j = 0; j < WIDTH; j++) {
			cout << temp[i][j];
		}
		cout << '#' << endl;
	}
	for (int i = 0; i < WIDTH + 2; i++)
		cout << '#';
	cout << endl;
}

void start_coordinate_initialization(int &startx, int &starty) {
	cout << "Start pos: " << endl;
	cin >> startx >> starty;
}
void end_coordinate_initialization(int &endx, int &endy) {
	cout << "End pos: " << endl;
	cin >> endx >> endy;
}

bool compare_coordinates(int x, int y) {
	if (x > y)
		return true;
	else
		return false;
}

void draw_line(char temp[][WIDTH], int startx, int starty, int endx, int endy) {
	if (startx == endx) {
		if (compare_coordinates(endy, starty)) {
			for (int i = starty; i <= endy; i++) {
				temp[i][startx] = '*';
			}
		} else {
			for (int i = starty; i >= endy; i--) {
				temp[i][startx] = '*';
			}
		}
	} else {
		if (compare_coordinates(endx, startx)) {
			for (int i = startx; i <= endx; i++) {
				temp[starty][i] = '*';
			}
		} else {
			for (int i = startx; i >= endx; i--) {
				temp[starty][i] = '*';
			}
		}
	}
}

void draw_rectangle(char temp[][WIDTH], int startx, int starty, int endx, int endy) {
	draw_line(temp, startx, starty, startx, endy);
	draw_line(temp, endx, starty, endx, endy);
	draw_line(temp, startx, starty, endx, starty);
	draw_line(temp, startx, endy, endx, endy);
}

void fill_area(char temp[][WIDTH], int startx, int starty, char color) {
	if (startx > 19 || startx < 0 || starty > 9 || starty < 0){
		return;
	}
	if (temp[starty][startx] == '*' ||temp[starty][startx]==color) {
		return;
	}
	// cout << startx<<' '<<starty<<endl;

	temp[starty][startx] = color;
	// print_canvas(temp);
	fill_area(temp, startx + 1, starty, color);
	fill_area(temp, startx + 1, starty + 1, color);
	fill_area(temp, startx + 1, starty - 1, color);
	fill_area(temp, startx, starty + 1, color);
	fill_area(temp, startx, starty - 1, color);
	fill_area(temp, startx - 1, starty, color);
	fill_area(temp, startx - 1, starty + 1, color);
	fill_area(temp, startx - 1, starty - 1, color);
	return;

}