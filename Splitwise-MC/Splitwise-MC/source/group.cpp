#include "../headers/group.h"

bool group::addMember(int memberId) {
	if (memberIds.find(memberId) != memberIds.end()) {
		std::cout << __func__<<  " : member already exists" << std::endl;
		return false;
	}
	std::cout << __func__ << ": Adding member " << memberId << ", to the group" << std::endl;
	memberIds.insert(memberId);
	balances[memberId] = std::pair<int, int>(0, 0);
	return true;
}

bool group::removeMember(int memberId) {
	if (memberIds.find(memberId) == memberIds.end()) {
		std::cout << __func__<<" : member does not exist" << std::endl;
		return false;
	}
	memberIds.erase(memberId);
	removeBalancesFormember(memberId);
	return true;
}

bool group::updateBalanceForMember(int balance, balanceType type, int memberId){
	if (memberIds.find(memberId) == memberIds.end()) {
		std::cout<< __func__ << " : member does not exist" << std::endl;
		return false;
	}
	if (type == balanceType::OWES) {
		balances[memberId].first += balance;
		int perMemberbalance = balance / memberIds.size();
		for (auto& mIter : memberIds) {
			balances[mIter].second += perMemberbalance;
		}
	}
	else if (type == balanceType::OWED) {
		balances[memberId].second += balance;
		int perMemberbalance = balance / memberIds.size();
		for (auto& mIter : memberIds) {
			balances[mIter].first += perMemberbalance;
		}
	}
	return true;
}
bool group::removeBalancesFormember(int memberId) {
	if (balances.find(memberId) == balances.end()) {
		std::cout << "balance for member does not exist" << std::endl;
		return false;
	}
	int balance = balances[memberId].first - balances[memberId].second;
	int perMemberBalance = balance / (memberIds.size() - 1);
	balances.erase(memberId);
	for (auto& bIter : balances) {
		if (perMemberBalance < 0)
			updateBalanceForMember(abs(perMemberBalance), balanceType::OWES, bIter.first);
		else
		{
			updateBalanceForMember(abs(perMemberBalance), balanceType::OWED, bIter.first);
		}
	}	
	return true;
}

int group::getBalanceForMember(int memberId, balanceType type) {
	if (memberIds.find(memberId) == memberIds.end()) {
		std::cout << "member does not exist" << std::endl;
		return false;
	}
	return balances[memberId].second - balances[memberId].first;
}
