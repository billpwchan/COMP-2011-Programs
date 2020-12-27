/*
 * Submit this file only. The filename has to be exactly "number.cpp".
 * Friendly reminder: submit the correct version of your file and submit early.
 */

#include "number.h"

#include <cstring>
using namespace std;

//No global variable is allowed
//No additional library can be included
//You may create additional (helper) functions in this file if needed
//Make sure your number.cpp can be compiled with the given number.h and main.cpp in our Windows Eclipse package
//(like the one used in our lab)

//In this file, implement all the functions (except printNumber, printNumberReversed, and deleteNumber) declared in number.h
//If you cannot finish implementing all the functions, please still define all of them here
//and provide a dummy implementation for each of them
//so that your number.cpp can still be compiled with our files and be graded for the parts that you could finish

/*
 * Print the represented decimal number on the console using cout, when given a linked list
 * (represented by "headNode" parameter, i.e., a pointer that points to the head node in the linked list)
 * Do nothing if the parameter "headNode" is NULL
 *
 * Note: its implementation is already given below and should NOT be modified
 * Note: it would only work if you use it with a correct doubly-linked list
 */
void printNumber(const DecimalNode* headNode)
{
	while (headNode != NULL)
	{
		cout << headNode->content;
		headNode = headNode->next;
	}

	cout << endl;
}

/*
 * Same as printNumber but the printing is reversed
 * So, for example, if printNumber prints 12.345, printNumberReversed prints 543.21
 *
 * Note: its implementation is already given below and should NOT be modified
 * Note: it would only work if you use it with a correct doubly-linked list
 */
void printNumberReversed(const DecimalNode* headNode)
{
	//find the tail node first
	const DecimalNode* tailNode = headNode;
	while (tailNode->next != NULL)
		tailNode = tailNode->next;

	while (tailNode != NULL)
	{
		cout << tailNode->content;
		tailNode = tailNode->prev;
	}

	cout << endl;
}

/*
 * Deallocate all the dynamically allocated memory for the given linked list
 * (represented by "headNode" parameter, i.e., a reference to a pointer that points to the head node in the linked list)
 * You are also required to set headNode to NULL after the memory deallocation is done
 * Do nothing if the parameter "headNode" is NULL
 *
 * Note: its implementation is already given below and should not be modified
 */
void deleteNumber(DecimalNode*& headNode)
{
	//delete everything with a loop
	const DecimalNode* current = headNode;
	while (current != NULL)
	{
		DecimalNode* next = current->next;
		delete current;
		current = next;
	}
	headNode = NULL;
}



//TODO: write your implementation of the missing functions below

DecimalNode* create_newnode(char number) {
	DecimalNode* new_node = new DecimalNode;
	new_node->content = number;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}


/*
 * Return the head node of the doubly linked list that is created to represent the decimal number according to the given integer part and fractional part
 * (via "integerPart" and "fractionalPart" which are pointers that point to null-terminated strings)
 * Dynamically allocate all the nodes needed to represent the decimal number
 * See the assignment webpage for the specification of the linked list that you need to generate
 * See sample output for examples
 *
 * You can assume both pointer parameters won't be NULL
 *
 * Return NULL if either of the strings is empty or contain anything other than just digits
 * For example, createNumber("123.", "123") should return NULL
 * For example, createNumber("123", "") should return NULL
 * For example, createNumber("abc123abc", "123") should return NULL
 *
 * However, even when the parameters are valid (i.e. contain just digits), if the created number is of an invalid representation
 * (according to our specification), you will need to fix it
 * For example, createNumber("01230", "01230") should return a doubly-linked list that represents "1230.0123"
 * (have to remove those extra zeros at the beginning and at the end)
 */

bool check_zero(const char* part, int size){
    for (int i=0; i<size; i++){
        if (part[i]!='0'){
            return false;
        }
    }
    return true;
}

DecimalNode* createNumber(const char* integerPart, const char* fractionalPart) {
	int integer_length = static_cast<int>(strlen(integerPart));
	int fractional_length = static_cast<int>(strlen(fractionalPart));

	if (integer_length == 0 || fractional_length == 0) {
		return NULL;
	}
	for (int i = 0; i < integer_length; i++) {
		if (!(integerPart[i] <= '9' && integerPart[i] >= '0')) {
			return NULL;
		}
	}
	for (int i = 0; i < fractional_length; i++) {
		if (!(fractionalPart[i] <= '9' && fractionalPart[i] >= '0')) {
			return NULL;
		}
	}
	DecimalNode* head = NULL;
	DecimalNode* current = NULL;
	DecimalNode* previous = NULL;

	int integer_startpos = 0;
	int fractional_endpos = fractional_length - 1;
	while (integerPart[integer_startpos] == '0') {
		integer_startpos++;
	}
	while (fractionalPart[fractional_endpos] == '0') {
		fractional_endpos--;
	}

	if (check_zero(integerPart, integer_length)) {
		head = create_newnode('0');
		current = head; previous = head->prev;
	} else {
		head = create_newnode(integerPart[integer_startpos]);
		current = head; previous = head->prev;
		for (int i = integer_startpos + 1; i < integer_length; i++) {
			current->next = create_newnode(integerPart[i]);
			previous = current;
			current = current->next;
			current->prev = previous;
		}
	}

	current->next = create_newnode('.');
	previous = current;
	current = current->next;
	current->prev = previous;

	if (fractional_endpos == -1) {
		current->next = create_newnode('0');
		previous = current;
		current = current->next;
		current->prev = previous;
	} else {
		for (int i = 0; i <= fractional_endpos; i++) {
			current->next = create_newnode(fractionalPart[i]);
			previous = current;
			current = current->next;
			current->prev = previous;
		}
	}

	return head;


}

/*
 * Search for the character (as specified by the parameter "c") in the given linked list (as specified by the parameter "headNode")
 * Return the first (leftmost) node that contains the character as content in the linked list
 * Return NULL if such node cannot be found in the linked list
 * Return NULL if c is not a digit character or '.'
 */
DecimalNode* search(DecimalNode* headNode, char c) {
	if (!((c <= '9' && c >= '0') || c == '.') || headNode == NULL) {
		return NULL;
	}
	DecimalNode* current = NULL;
	DecimalNode* previous = NULL;
	bool flag = false;
	current = headNode;
	previous = current->prev;
	while (current->next != NULL) {
		if (current->content == c) {
			flag = true;
			break;
		}
		previous = current;
		current = current->next;
	}
	if (current->content == c) {
		flag = true;
	}
	if (flag) {
		return current;
	}
	return NULL;
}

/*
 * Return the number of digits that are in the integer part of the given linked list (via the "headNode" parameter)
 * Return 0 if headNode is NULL
 */
int getIntegerPartLength(const DecimalNode* headNode) {
	if (headNode == NULL) {
		return 0;
	}
	int integer_length = 0;
	DecimalNode* current = NULL;
	current = headNode->next;
	integer_length++;
	while (current->content != '.') {
		current = current->next;
		integer_length++;
	}
	return integer_length;
}

/*
 * Return the number of digits that are in the fractional part of the given linked list (via the "headNode" parameter)
 * Return 0 if headNode is NULL
 */
int getFractionalPartLength(const DecimalNode* headNode) {
	if (headNode == NULL) {
		return 0;
	}
	DecimalNode* current = NULL;
	int fractional_length = 0;
	current = headNode->next;
	while (current->content != '.') {
		current = current->next;
	}
	current = current->next;
	while (current != NULL) {
		current = current->next;
		fractional_length++;
	}
	return fractional_length;
}

/*
 * Given two decimal number "a" and "b" (which are pointers that point to the head nodes of the two numbers)
 * Return 1 if a > b
 * Return -1 if a < b
 * Return 0 if a == b
 * Return 999 if either of the parameters is NULL
 */

int compare_digit( char a,  char b) {
	int num1 = a - '0';
	int num2 = b - '0';
	if (num1 > num2) {
		return 1;
	} else if (num1 < num2) {
		return -1;
	}
	return 0;
}

int compare(const DecimalNode* a, const DecimalNode* b) {
	if (a == NULL || b == NULL) {
		return 999;
	}
	int a_length = getIntegerPartLength(a);
	int b_length = getIntegerPartLength(b);

	DecimalNode* current_a = a->next;
	current_a = current_a->prev;
	DecimalNode* current_b = b->next;
	current_b = current_b->prev;

	if (a_length > b_length) {
		return 1;
	} else if (a_length < b_length) {
		return -1;
	} else {

		int count = 0;
		while (compare_digit(current_a->content, current_b->content) == 0 && current_a->content != '.' && current_b->content != '.') {
			current_a = current_a->next;
			current_b = current_b->next;
			count++;
		}
		if (count < a_length - 1) {
			return compare_digit(current_a->content, current_b->content);
		} else {

			while ((current_a != NULL && current_b != NULL) && compare_digit(current_a->content, current_b->content) == 0) {
				current_a = current_a->next;
				current_b = current_b->next;
			}
			if (current_a == NULL && current_b != NULL) {
				return -1;
			} else if (current_a != NULL && current_b == NULL) {
				return 1;
			} else if (current_a == NULL && current_b == NULL) {
				return 0;
			} else {
				return compare_digit(current_a->content, current_b->content);
			}
		}
	}

	return 0;
}

/*
 * Multiply the given decimal number (via the head node pointer "headNode") by '10 to the power of n'
 * See sample output for examples
 *123.456*10=1234.56
 * Do nothing if headNode is NULL
 */

void swap_multiply_position(DecimalNode* node1, DecimalNode* node2, DecimalNode* node3, DecimalNode* node4) {
	node1->next = node3;
	node3->prev = node1;
	node3->next = node2;
	node2->prev = node3;
	node2->next = node4;
	node4->prev = node2;
}

void multiply(DecimalNode* headNode, int n) {
    if (headNode==NULL){
        return;
    }
	if (headNode->content == '0' && headNode->next->content == '.' && headNode->next->next->content == '0' && headNode->next->next->next == NULL) {
		return;
	}
	DecimalNode* future = headNode->next;
	DecimalNode* current = headNode;
	DecimalNode* previous = current->prev;
	int special_case = 0;
	while (current->content != '.') {
		future = future->next;
		previous = current;
		current = current->next;
	}

	// Treat special cases like 0.001*10000;  0.001 0.01 0.1 1.0 10.0  0.123
    // 0.01->0.1      0.012->0.12   0.1->1.0 0.12->1.2
	while (previous->prev == NULL && previous->content == '0' && current->content == '.' && n>0) {
        if (future->content!='0'){
            if (future->next==NULL){
                headNode->content=future->content;
                headNode->next=current;
                headNode->prev=NULL;
                current->prev=headNode;
                current->next=create_newnode('0');
                future=current->next;
                future->prev=current;
                previous=current->prev;
                n--;
            }else{
                headNode->content=future->content;
                headNode->next=current;
                headNode->prev=NULL;
                current->prev=headNode;
                current->next=future->next;
                future=current->next;
                future->prev=current;
                previous=current->prev;
                n--;
            }
        }else{
            headNode->content=future->content;
            headNode->next=current;
            headNode->prev=NULL;
            current->prev=headNode;
            current->next=future->next;
            future=current->next;
            future->prev=current;
            previous=current->prev;
            n--;
        }
//		flag = true;
//		headNode->content = future->content;
//		headNode->next = current;
//		current->prev = headNode;
//        if (future->next!=NULL){
//            current->next = future->next;
//            future->next->prev = current;
//            future = current->next;
//            previous = current->prev;
//        }else{
//                current->next=create_newnode('0');
//                future=current->next;
//                future->prev=current;
//                previous=current->prev;
//            }
//		n--;
	}
//	if (flag&&n>0) {
//		headNode->content = future->content;
//		headNode->next = current;
//		current->prev = headNode;
//		current->next = create_newnode('0');
//		future = current->next;
//		future->prev = current;
//		previous = current->prev;
//		n--;
//	}
	for (int i = 0; i < n; i++) {
		if (future->next == NULL) {
			special_case = n - i;
			break;
		} else {
			swap_multiply_position(previous, current, future, future->next);
			previous = future;
			future = current->next;
			current = previous->next;
		}
	}//2.0 20.0
	for (int i = 0; i < special_case; i++) {
		previous->next = future;
		future->prev = previous;
		future->next = current;
		current->prev = future;
		current->next = create_newnode('0');
		previous = future;
		future = current->next;
		future->prev = current;
	}
}


void swap_divide_position(DecimalNode* node1, DecimalNode* node2, DecimalNode* node3, DecimalNode* node4) {
	node1->next = node3;
	node3->prev = node1;
	node3->next = node2;
	node2->prev = node3;
	node2->next = node4;
	node4->prev = node2;
}
/*
 * Divide the given decimal number (via the head node pointer "headNode") by '10 to the power of n'
 * You will need to make sure the headNode is pointing to the head node of the modified linked list at the end of the function
 * See sample output for examples
 *
 * Do nothing if headNode is NULL
 */
void divide(DecimalNode*& headNode, int n) {
    if (headNode==NULL){
        return;
    }
	if (headNode->content == '0' && headNode->next->content == '.' && headNode->next->next->content == '0' && headNode->next->next->next == NULL) {
		return;
	}
	DecimalNode* future = headNode->next;
	DecimalNode* current = headNode;
	DecimalNode* previous = current->prev;
	int special_case = 0;
	while (current->content != '.') {
		future = future->next;
		previous = current;
		current = current->next;
	}//200.0 20.0  200.1 20.01
	for (int i = 0; i < n; i++) {
		if (previous->prev == NULL) {
			special_case = n - i;
			break;
		} else {
			swap_divide_position(previous->prev, previous, current, future);
            if (future->content=='0'&&future->next==NULL){
                future=previous;
                future->next=NULL;}
            else{
                    future = previous;
                                    }
			previous = current->prev;
		}
	}
	//2.0 0.2 2.02  0.202
	for (int i = 0; i < special_case; i++) {
		if (i == 0 && future->content == '0'&&future->next==NULL) {
			previous->next = NULL;
		} else {
			previous->next = future;
			future->prev = previous;
		}

		previous->prev = current;
		current->next = previous;
		current->prev = create_newnode('0');
		previous = current->prev;
		previous->next = current;
		future = current->next;
		headNode = previous;
	}

}



