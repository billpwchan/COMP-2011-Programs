#include <iostream>
using namespace std;

const int WIDTH = 20;
const int HEIGHT = 10;

void initiate_canvas(char[][WIDTH]);
void print_canvas(const char[][WIDTH]);
void start_coordinate_initialization(int&, int&);
void end_coordinate_initialization(int&, int&);
bool compare_coordinates(int, int);
void draw_line(char[][WIDTH], int, int, int, int);
void draw_rectangle(char [][WIDTH], int , int , int , int );
void fill_area(char [][WIDTH], int , int , char );