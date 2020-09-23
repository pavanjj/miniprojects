#include "../headers/person.h"


bool person::addToAGroup(group& groupObj) {
	groupIdMap[groupObj.getGroupId()] = &groupObj;
	return groupObj.addMember(personId);
}

bool person::withdrawFromGroup(int groupId) {
	if (groupIdMap.find(groupId) == groupIdMap.end()) {
		std::cout << "The person is nto member of the group" << std::endl;
		return false;
	}
	auto balance = getBalanceForAGroup(groupId);
	groupIdMap[groupId]->removeMember(personId);	
}

bool person::addBalanceToAGroup(int groupId, int balance, balanceType type) {
	if (groupIdMap.find(groupId) == groupIdMap.end()) {
		std::cout << "The person is nto member of the group" << std::endl;
		return false;
	}
	return groupIdMap[groupId]->updateBalanceForMember(balance, type, personId);
}

int person::getBalanceForAGroup(int groupId) {
	if (groupIdMap.find(groupId) == groupIdMap.end()) {
		std::cout << "The person is nto member of the group" << std::endl;
		return false;
	}
	return groupIdMap[groupId]->getBalanceForMember(personId);
}

int person::getBalanceForAllGroups() {
	int balance = 0;
	for (auto& iter : groupIdMap) {
		balance += iter.second->getBalanceForMember(personId);
	}
	return balance;
}