/*
 * ctwg_filter.h
 *
 *  Created on: 2020年12月11日
 *      Author: dengxiaoqian
 */

#ifndef CTWG_FILTER_H_
#define CTWG_FILTER_H_

#include <string>

struct FilterConfig{
	std::string rhost;//redis host
	std::string rpart;//redis part
	std::string rauth; //redis passwd
	std::string rdb; //redis db
	std::string tokenPrefix;//validate token (token remove by system)
	std::string userPrefix;//user prefix
};
static FilterConfig systemConfig;
void setSystemConfig(std::string rhost,
		std::string rpart,
		std::string rauth,
		std::string rdb,
		std::string tokenPrefix,
		std::string userPrefix){
	systemConfig = {
			rhost,rpart,rauth,rdb,tokenPrefix,userPrefix
	};
}
int validToken(std::string token);



#endif /* CTWG_FILTER_H_ */
