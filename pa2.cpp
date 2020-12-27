/*
 * pa2.cpp
 *
 *  Created on: Sep 26, 2016
 *  Last modified: Oct 18, 2016
 *
 *      Author: kevinw
 */

#include <iostream>
using namespace std;

const int BALANCED = -20;
const int MISS_CLOSING_SYMBOL = -30;
const int NO_PARENTHESES_DETECTED = -40;

// You may change the variable DEBUG to true/false as to turn on/off the DEBUG message
const bool DEBUG = false;

// You can assume that the input string is always shorter than BUFFER_SIZE
const int BUFFER_SIZE = 500;

const char OPEN = '(';
const char CLOSE = ')';

void debug(const char input[], int start_pos) {
	if (input[start_pos] != '\0')
		cout << "The " << start_pos << "-th character of the input array is:"
		     << input[start_pos] << endl;
	else
		cout << "You have reached the end of the input array" << endl;
}

/**
 *   An input char array with (0 or 1 OPEN symbol) and (0 or 1 CLOSE symbol) mixed with
 *   other characters is given to the function. This function would need to identify if the
 *   input has balanced parentheses. That is, if there is an OPEN symbol in the input, there
 *   must be another CLOSE symbol appearing somewhere after it. Or, there is no OPEN symbol
 *   nor CLOSE symbol. If a CLOSE symbol appears before the OPEN symbol or there is a OPEN
 *   symbol but not a CLOSE symbol, there there are unbalanced parentheses.
 *
 *   The second input start_pos indicates the starting position of the input char array. The
 *   function should only check the input starting from start_pos to the end. When this function
 *   is called at the main function, the start_pos will always be zero. For example,
 *
 *       int result = warmup_task("ree(abcdef + gd +)abcc", 0); // It is a balanced case
 *
 *   The function returns the following:
 *     const int BALANCED - if there are balanced parentheses
 *     int x - if an extra CLOSE symbol is found which is on the x-th cell of the input
 *     const int MISS_CLOSING_SYMBOL - if there is no CLOSE symbol after an OPEN symbol
 *     const int NO_PARENTHESES_DETECTED - if there are no parentheses in the whole string
 *
 *   In case the input has a CLOSE symbol before an OPEN symbol, the function should return
 *   a value x, where x is the location of that CLOSE symbol in the input string.
 *
 *   Note: The compiler will probably allow you to build even if you do not have a valid return
 *   statement. Make sure you have a return statement in all required tasks. Since this is an
 *   assignment about recursion, you must use recursion to complete it and you are not allowed
 *   to use any loop for all functions you write.
 */
int warmup_task(const char input[], int start_pos) {
	if (DEBUG)
		debug(input, start_pos);
	
	if (input[start_pos]==')'){
		return start_pos;
	}

	if (input[start_pos] != '(' && input[start_pos] != ')' && input[start_pos] != '\0') {
			return warmup_task(input, start_pos + 1);
	}

	if (input[start_pos]=='('){
		if (warmup_task(input, start_pos+1)>0){
			return BALANCED;
		}else{
			return MISS_CLOSING_SYMBOL;
		}
	}


	return NO_PARENTHESES_DETECTED;


}

// TODO Task 1


/**
 *   This function is an extension to the function warmup_task. An input char array with
 *   (0 or more OPEN symbol) and (0 or more CLOSE symbol) mixed with other characters
 *   is given to the function. This function would need to identify if the input has
 *   balanced parentheses. For example the following inputs are considered as balanced:
 *
 *        "(asdf())", "(ab   ab()(af))", "(BC()(()))()"
 *
 *    The following example is considered as unbalanced:
 *
 *        ")", "    ())",  "(   ()"
 *
 *    The function returns the following:
 *       const int BALANCED - if there are balanced parentheses
 *       int x - if the first extra CLOSE symbol is found on the x-th cell of the input.
 *       const int MISS_CLOSING_SYMBOL - if there is no CLOSE symbol after an OPEN symbol.
 *       const int NO_PARENTHESES_DETECTED - if there are no parentheses in the whole string.
 *
 *   Clarification: Consider the input "()3)5)(". This should return the first position with
 *   extra CLOSE symbol, that is 3, although there is another extra ) in the 5-th cell and
 *   the last OPEN symbol is not closed.
 *
 */
int balanced_parentheses(const char input[], int start_pos) {
	if (DEBUG)
		debug(input, start_pos);
	
	if (input[0]=='\0'){
		return NO_PARENTHESES_DETECTED;
	}

    if (input[start_pos] != '(' && input[start_pos] != ')' && input[start_pos] != '\0') {
        if (warmup_task(input, start_pos)==NO_PARENTHESES_DETECTED&&start_pos==0){
            return NO_PARENTHESES_DETECTED;
        }else{
            return balanced_parentheses(input, start_pos + 1);
        }
    }

	if (input[start_pos] == '\0') {
		return BALANCED;
	}

	if (input[start_pos] == ')') {
		return start_pos;
	}

	if (input[start_pos] == '(') {
		int right_pos = balanced_parentheses(input, start_pos + 1);
		if (right_pos >= 0) {
			return balanced_parentheses(input, right_pos + 1);
		} else {
			return MISS_CLOSING_SYMBOL;
		}
	}





	return NO_PARENTHESES_DETECTED;
// ()))


	// TODO 2
}


int main() {
	char input[BUFFER_SIZE];

	int option;
	do {
		cout << "Which test case you want to test?" << endl <<
		     "1) warmup_task " << endl <<
		     "2) balanced_parentheses" << endl;
		cin >> option;
		cin.ignore();
	} while (option < 1 || option > 2);

	do {
		cout << "Type in your test case. (Type a string begin with q to quit)"
		     << endl;
		cin.getline(input, BUFFER_SIZE - 1);

		if (input[0] == 'q')
			return 0;

		int result;
		switch (option) {
		case 1: result = warmup_task(input, 0); break;
		case 2: result = balanced_parentheses(input, 0); break;
		}

		switch (result) {
		case MISS_CLOSING_SYMBOL:
			cout << "Missing closing parenthesis at the end" << endl;
			break;
		case BALANCED:
			cout << "Parentheses are balanced" << endl;
			break;
		case NO_PARENTHESES_DETECTED:
			cout << "No parentheses are detected" << endl;
			break;
		default:
			cout << "First unbalanced symbol found at the position (index start from 0): "
			     << result << endl;
			break;
		}
	} while (true);

	return 0;
}