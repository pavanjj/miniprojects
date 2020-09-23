#include "../headers/group.h";
#include "../headers/person.h"
#include<vector>
#define CREATEGROUP 1
#define CREATEPERSON 2
#define ADDPERSONTOGROUP 3
#define ADDBALACETOAGROUP 4
#define SHOWBALANCEOFAGROUP 5
#define SHOWBALANCEOFALLGROUPS 6

using namespace std;

person getPersonObj(std::string& name, int personId) {
	person newPerson(name, personId);
	return newPerson;
}

group getGroupObj(std::string& name,int groupId) {
	group newGroup(name, groupId);
	return newGroup;
}
void appDriver(std::vector<int>& opcodes, std::vector<std::pair<std::string, std::vector<int>>>& values) {
	std::unordered_map<int, group> groups;
	std::unordered_map<int, person> persons;
	int personId, groupId, balance;
	balanceType bType;
	for (int op = 0; op < opcodes.size(); op++){
		switch (opcodes[op]) {
		case CREATEGROUP: 
			groups.insert({ values[op].second[0] , getGroupObj(values[op].first, values[op].second[0]) });
			cout << "Created Group " << values[op].first << endl;
			break;
		case CREATEPERSON:			
			persons.insert({ values[op].second[0] ,getPersonObj(values[op].first, values[op].second[0]) });
			cout << "Created Person " << values[op].first<<","<< values[op].second[0] << endl;
			break;
		case ADDPERSONTOGROUP:
			personId = values[op].second[0];
			groupId = values[op].second[1];
			if (groups.find(groupId) == groups.end()) {
				std::cout << "the said group does not exist : " << groupId << std::endl;
				break;
			}
			if (persons.find(groupId) == persons.end()) {
				std::cout << "the said person does not exist : " << personId << std::endl;
				break;
			}
			cout << "Adding person " << personId << " to the group" << groupId<< endl;
			persons[personId].addToAGroup(groups[groupId]);
			break;
		case ADDBALACETOAGROUP:
			personId = values[op].second[0];
			groupId = values[op].second[1];
			balance = values[op].second[2];
			bType = values[op].second[3] < 1 ? balanceType::OWES : balanceType::OWED;
			
			if (groups.find(groupId) == groups.end()) {
				std::cout << "the said group does not exist : " << groupId << std::endl;
				break;
			}
			if (persons.find(groupId) == persons.end()) {
				std::cout << "the said person does not exist : " << personId << std::endl;
				break;
			}
			
			persons[personId].addBalanceToAGroup(groupId, balance, bType);
			break;
		case SHOWBALANCEOFAGROUP:
			personId = values[op].second[0];
			groupId = values[op].second[1];
			if (groups.find(groupId) == groups.end()) {
				std::cout << "the said group does not exist : " << groupId << std::endl;
				break;
			}
			if (persons.find(groupId) == persons.end()) {
				std::cout << "the said person does not exist : " << personId << std::endl;
				break;
			}
			std::cout << "The balance for person : " << persons[personId].getName() << ", and group : " << groups[groupId].getGroupName() << " is = " << persons[personId].getBalanceForAGroup(groupId) << std::endl;
			break;
		case SHOWBALANCEOFALLGROUPS:
			personId = values[op].second[0];
			if (persons.find(groupId) == persons.end()) {
				std::cout << "the said person does not exist : " << personId << std::endl;
				break;
			}
			std::cout << "The balance for person : " << persons[personId].getName() << " across groups is = " << persons[personId].getBalanceForAllGroups() << std::endl;
			break;
		}
	}
}

void main() {
	int groupId = 1;
	int personId = 1;
	std::vector<int> opcodes;
	std::vector<std::pair<std::string, std::vector<int>>> values;
	opcodes.push_back(CREATEGROUP);
	values.push_back(std::pair<std::string,std::vector<int>>("GRoup 1", std::vector<int>{groupId++}));
	opcodes.push_back(CREATEGROUP);
	values.push_back(std::pair<std::string, std::vector<int>>("GRoup 2", std::vector<int>{groupId++}));
	opcodes.push_back(CREATEGROUP);
	values.push_back(std::pair<std::string, std::vector<int>>("GRoup 3", std::vector<int>{groupId++}));
	opcodes.push_back(CREATEGROUP);
	values.push_back(std::pair<std::string, std::vector<int>>("GRoup 4", std::vector<int>{groupId++}));


	opcodes.push_back(CREATEPERSON);
	values.push_back(std::pair<std::string, std::vector<int>>("Person 1", std::vector<int>{personId++}));
	opcodes.push_back(CREATEPERSON);
	values.push_back(std::pair<std::string, std::vector<int>>("Person 2", std::vector<int>{personId++}));
	opcodes.push_back(CREATEPERSON);
	values.push_back(std::pair<std::string, std::vector<int>>("Person 3", std::vector<int>{personId++}));
	opcodes.push_back(CREATEPERSON);
	values.push_back(std::pair<std::string, std::vector<int>>("Person 4", std::vector<int>{personId++}));

	opcodes.push_back(ADDPERSONTOGROUP);
	values.push_back(std::pair<std::string, std::vector<int>>("", std::vector<int>{1,1}));
	opcodes.push_back(ADDPERSONTOGROUP);
	values.push_back(std::pair<std::string, std::vector<int>>("", std::vector<int>{2, 1})); 
	opcodes.push_back(ADDPERSONTOGROUP);
	values.push_back(std::pair<std::string, std::vector<int>>("", std::vector<int>{1, 2}));
	opcodes.push_back(ADDPERSONTOGROUP);
	values.push_back(std::pair<std::string, std::vector<int>>("", std::vector<int>{3, 2}));

	opcodes.push_back(ADDBALACETOAGROUP);
	values.push_back(std::pair<std::string, std::vector<int>>("", std::vector<int>{1, 1,10,1}));
	opcodes.push_back(ADDBALACETOAGROUP);
	values.push_back(std::pair<std::string, std::vector<int>>("", std::vector<int>{2, 1, 10, 1}));
	opcodes.push_back(ADDBALACETOAGROUP);
	values.push_back(std::pair<std::string, std::vector<int>>("", std::vector<int>{1, 2, 20, 1}));
	opcodes.push_back(ADDBALACETOAGROUP);
	values.push_back(std::pair<std::string, std::vector<int>>("", std::vector<int>{3, 2, 10, 1}));

	opcodes.push_back(SHOWBALANCEOFAGROUP);
	values.push_back(std::pair<std::string, std::vector<int>>("", std::vector<int>{1, 1}));
	opcodes.push_back(SHOWBALANCEOFAGROUP);
	values.push_back(std::pair<std::string, std::vector<int>>("", std::vector<int>{2, 1}));
	opcodes.push_back(SHOWBALANCEOFAGROUP);
	values.push_back(std::pair<std::string, std::vector<int>>("", std::vector<int>{1, 2}));
	opcodes.push_back(SHOWBALANCEOFAGROUP);
	values.push_back(std::pair<std::string, std::vector<int>>("", std::vector<int>{3, 2}));

	opcodes.push_back(SHOWBALANCEOFALLGROUPS);
	values.push_back(std::pair<std::string, std::vector<int>>("", std::vector<int>{1}));
	opcodes.push_back(SHOWBALANCEOFALLGROUPS);
	values.push_back(std::pair<std::string, std::vector<int>>("", std::vector<int>{2}));
	appDriver(opcodes,values);
}