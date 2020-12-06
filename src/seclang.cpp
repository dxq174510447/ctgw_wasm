//============================================================================
// Name        : seclang.cpp
// Author      : dengxq
// Version     :
// Copyright   : dengxq
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ttt/t1.h"
using namespace std;

User1 getUserByToken(int token);

int main() {
	cout << "!!!Hello World111!!!" << endl; // prints !!!Hello World!!!
	User1 u2 = getUserByToken(123);
	cout << u2.id << endl;
	return 0;
}

User1 getUserByToken(int token){
	User1 u2 = {token};
//	User1 u1 = User1(token);
	return u2;
}
