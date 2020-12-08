//============================================================================
// Name        : seclang.cpp
// Author      : dengxq
// Version     :
// Copyright   : dengxq
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cpp_redis/cpp_redis>
#include "ttt/t1.h"
using namespace std;

User1 getUserByToken(int token);

int main() {
	cout << "!!!Hello World111!!!" << endl; // prints !!!Hello World!!!
	User1 u2 = getUserByToken(123);
	cout << u2.name << endl;
	return 0;
}

User1 getUserByToken(int token){
	string a = "123";
	User1 u2 = {token,"345"+std::to_string(token)};

	cpp_redis::client client;

	client.connect("47.105.61.26", 6379);
	client.auth("gsta2012");
//	client.set("hello", "12345");
//	std::future<cpp_redis::reply> r = client.get("hello");
//	client.sync_commit();
//	string r1 = r.get().as_string();
//	cout << r1 << endl;
//
	std::future<cpp_redis::reply> r2= client.get("hello");
	client.sync_commit();
	if(r2.get().is_null()){
		cout << "null" << endl;
	}
	else{
		cout << "123" << endl;
		cout << r2.get() << endl;
		cout << "456" << endl;
	}

	cout << "789" << endl;

//	std::future<cpp_redis::reply> r = client.hgetall("tt1");
//	client.sync_commit();
//	if(r.get().is_null()){
//		cout << "null" << endl;
//	}
//	else{
//		std::vector<cpp_redis::reply> rs = r.get().as_array();
//		for(int i=0;i<rs.size();i++){
//
//			cout << rs[i].as_string() << endl;
//		}
//	}

//	client.sync_commit();

//	User1 u1 = User1(token);
	return u2;
}
