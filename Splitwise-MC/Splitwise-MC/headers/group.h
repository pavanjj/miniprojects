#pragma once
#ifndef GROUP_H
#define GROUP_H
#include "common.h" 
class group {
	std::unordered_map<int, std::pair<int, int>> balances; // first owes, second owed
	std::unordered_set<int> memberIds;
	std::string name;
	int groupId;
public:
	group() {};
	group(std::string& _name,int _groupId) : name(_name),groupId(_groupId) {};
	int getGroupId() { return groupId; }
	std::string getGroupName() { return name; }
	bool updateBalanceForMember(int balance, balanceType type, int memberId);
	bool removeBalancesFormember(int memberId);
	bool addMember(int memberId);
	bool removeMember(int memberId);
	int getBalanceForMember(int memberId, balanceType type = balanceType::BOTH);
};


#endif



