//============================================================================
// Name        : seclang.cpp
// Author      : dengxq
// Version     :
// Copyright   : dengxq
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <unordered_map>
#include "sw/redis++/redis++.h"
#include "ttt/t1.h"
using namespace std;
using namespace sw::redis;
User1 getUserByToken(int token);

int main() {
	cout << "!!!Hello World111!!!" << endl; // prints !!!Hello World!!!
	User1 u2 = getUserByToken(123);
	cout << u2.name << endl;
	return 0;
}

User1 getUserByToken(int token){
	string a = "123";
	User1 u2 = {token,"000"+std::to_string(token)};

	auto redis = Redis("tcp://47.105.61.26:6379");
	redis.auth("gsta2012");

	auto val = redis.get("hello");

	 cout << "123" << endl;
	 if (val) {
		std::cout << *val << std::endl;
	 }
	 else{
		 std::cout << "null" << std::endl;
	 }
	 std::cout << "789" << std::endl;

	 std::unordered_map<std::string, std::string> m1 = {};
	 redis.hgetall("tt", std::inserter(m1, m1.begin()));
	 auto iter = m1.begin();
	 while (iter!= m1.end())
	     {
	         cout << iter->first << "," << iter->second << endl;
	         ++iter;
	     }
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
