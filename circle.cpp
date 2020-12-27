#include <iostream>
#include <cmath>
using namespace std;

void data_initialization_part1(int &x, int &y, int &cx, int &cy, int &r);
void data_initialization_part2(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, int &cx, int &cy, int &r);
void data_initialization_part3(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3);
float calculate_distance(int x1, int x2, int y1, int y2);
float calculate_slope(int x1, int x2, int y1, int y2);
void determine_position(float point_distance, int r);
void center_determination(int x1, int y1, int x2, int y2, float &cx, float &cy);
bool is_right_triangle(int x1, int y1, int x2, int y2, int x3, int y3, float &d1, float &d2, float &d3);

int main (void) {
	int choice;
	int x = 0, y = 0, cx = 0, cy = 0, r = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
	float point_distance = 0, pd1 = 0, pd2 = 0, pd3 = 0, float_cx = 0, float_cy = 0;
	bool flag = false;

	cout << "Please select the program: \n" << "1. Point determination\n2. Triangle determination\n3. Circumcircle determination" << endl;
	cin >> choice;
	switch (choice) {

	case 1: {
		data_initialization_part1(x, y, cx, cy, r);
		point_distance = calculate_distance(x, cx, y, cy);
		determine_position(point_distance, r);
	} break;


	case 2: {
		data_initialization_part2(x1, y1, x2, y2, x3, y3, cx, cy, r);
		if ((calculate_slope(x1, x2, y1, y2) - calculate_slope(x1, x3, y1, y3)) < 0.001) {
			cout << "Cannot form a triangle! " << endl;
		} else {
			pd1 = calculate_distance(x1, cx, y1, cy);
			pd2 = calculate_distance(x2, cx, y2, cy);
			pd3 = calculate_distance(x3, cx, y3, cy);
			if (pd1 > r || pd2 > r || pd3 > r) {
				cout << "Not completely contained. " << endl;
			} else {
				cout << "Completely contained. " << endl;
			}
		}

	} break;

	case 3: {
		data_initialization_part3(x1, y1, x2, y2, x3, y3);
		flag = is_right_triangle(x1, y1, x2, y2, x3, y3, pd1, pd2, pd3);
		if (flag) {
			if (pd1 > pd2 && pd1 > pd3) {
				center_determination(x1, y1, x2, y2, float_cx, float_cy);
				cout << "Center of the circumcircle is (" << float_cx << ", " << float_cy << ")" << endl;
				point_distance = calculate_distance(x1, x2, y1, y2) / 2;
				cout << "Radius of the circumcircle is " << point_distance << endl;
			} else if (pd2 > pd1 && pd2 > pd3) {
				center_determination(x1, y1, x3, y3, float_cx, float_cy);
				cout << "Center of the circumcircle is (" << float_cx << ", " << float_cy << ")" << endl;
				point_distance = calculate_distance(x1, x3, y1, y3) / 2;
				cout << "Radius of the circumcircle is " << point_distance << endl;
			}
			else if (pd3 > pd1 && pd3 > pd2) {
				center_determination(x2, y2, x3, y3, float_cx, float_cy);
				cout << "Center of the circumcircle is (" << float_cx << ", " << float_cy << ")" << endl;
				point_distance = calculate_distance(x2, x3, y2, y3) / 2;
				cout << "Radius of the circumcircle is " << point_distance << endl;
			}


		} else {
			cout << "Cannot form a right angle triangle. " << endl;
		}
	} break;

	default: {
		cout << "Invalid Input. Please try again later. " << endl;
	} break;
	}





	return 0;
}

void data_initialization_part1(int &x, int &y, int &cx, int &cy, int &r) {
	cout << "Part 1)" << endl;
	cout << "Point:" << endl
	     << "Please enter x-coordinate of the point (only integer is accepted): ";
	cin >> x;
	cout << "Please enter y-coordinate of the point (only integer is accepted): ";
	cin >> y;
	cout << "Circle:" << endl
	     << "Please enter x-coordinate of the center (only integer is accepted):";
	cin >> cx;
	cout << "Please enter y-coordinate of the center point (only integer is accepted):";
	cin >> cy;
	cout << "Please enter radius of the circle (only integer is accepted): ";
	cin >> r;
	cout << endl;
}

void data_initialization_part2(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, int &cx, int &cy, int &r) {
	cout << "Part 2)" << endl;
	cout << "Triangle:" << endl
	     << "Please enter x-coordinate of the first point (only integer is accepted): ";
	cin >> x1;
	cout << "Please enter y-coordinate of the first point (only integer is accepted): ";
	cin >> y1;
	cout << "Please enter x-coordinate of the second point (only integer is accepted): ";
	cin >> x2;
	cout << "Please enter y-coordinate of the second point (only integer is accepted): ";
	cin >> y2;
	cout << "Please enter x-coordinate of the third point (only integer is accepted): ";
	cin >> x3;
	cout << "Please enter y-coordinate of the third point (only integer is accepted): ";
	cin >> y3;
	cout << "Circle:" << endl
	     << "Please enter x-coordinate of the center (only integer is accepted):";
	cin >> cx;
	cout << "Please enter y-coordinate of the center point (only integer is accepted):";
	cin >> cy;
	cout << "Please enter radius of the circle (only integer is accepted): ";
	cin >> r;
	cout << endl;
}

void data_initialization_part3(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3) {
	cout << "Part 3)" << endl;
	cout << "Triangle:" << endl
	     << "Please enter x-coordinate of the first point (only integer is accepted): ";
	cin >> x1;
	cout << "Please enter y-coordinate of the first point (only integer is accepted): ";
	cin >> y1;
	cout << "Please enter x-coordinate of the second point (only integer is accepted): ";
	cin >> x2;
	cout << "Please enter y-coordinate of the second point (only integer is accepted): ";
	cin >> y2;
	cout << "Please enter x-coordinate of the third point (only integer is accepted): ";
	cin >> x3;
	cout << "Please enter y-coordinate of the third point (only integer is accepted): ";
	cin >> y3;
}

float calculate_distance(int x1, int x2, int y1, int y2) {
	return sqrt((y2 - y1) * (y2 - y1) * 1.0 + (x2 - x1) * (x2 - x1) * 1.0);
}

float calculate_slope(int x1, int x2, int y1, int y2) {
	return ((y2 - y1) * 1.0 / (x2 - x1) * 1.0);
}

void determine_position(float point_distance, int r) {
	if (point_distance < r) {
		cout << "Inside the circle." << endl;
	}
	else if (point_distance > r) {
		cout << "Outside the circle." << endl;
	}
	else {
		cout << "On the circle." << endl;
	}
}

bool is_right_triangle(int x1, int y1, int x2, int y2, int x3, int y3, float & d1, float & d2, float & d3) {
	d1 = calculate_distance(x1, x2, y1, y2);
	d2 = calculate_distance(x1, x3, y1, y3);
	d3 = calculate_distance(x2, x3, y2, y3);
	bool flag1 = ((pow(d1, 2) - pow(d2, 2) - pow(d3, 2)) < 0.0001) && ((pow(d1, 2) - pow(d2, 2) - pow(d3, 2)) > -0.0001);
	bool flag2 = ((pow(d2, 2) - pow(d1, 2) - pow(d3, 2)) < 0.0001) && ((pow(d2, 2) - pow(d1, 2) - pow(d3, 2)) > -0.0001);
	bool flag3 = ((pow(d3, 2) - pow(d2, 2) - pow(d1, 2)) < 0.0001) && ((pow(d3, 2) - pow(d2, 2) - pow(d1, 2)) > -0.0001);
	if (flag1 || flag2 || flag3) {
		return true;
	} else {
		return false;
	}
}

void center_determination(int x1, int y1, int x2, int y2, float & cx, float & cy) {
	cx = (x2 + x1) * 1.0 / 2;
	cy = (y2 + y1) * 1.0 / 2;

}