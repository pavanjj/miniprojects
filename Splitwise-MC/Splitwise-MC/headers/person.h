#pragma once
#ifndef PERSON_H
#define PERSON_H
#include<string>
#include "common.h" 
#include "../headers/group.h"
class person {
	std::string name;
	int personId;
	std::unordered_map<int, group*> groupIdMap;
	int totalBalance;
public:
	person() {};
	person(std::string& _name,int _personId) : name(_name),personId(_personId),totalBalance(0) {};
	std::string getName() { return name; };
	bool addToAGroup(group & groupObj);
	bool withdrawFromGroup(int groupId);
	bool addBalanceToAGroup(int groupId, int balance, balanceType type);
	int getBalanceForAGroup(int groupId);
	int getBalanceForAllGroups();
	void updateLocalBalance(int balance, balanceType type);
};
#endif
