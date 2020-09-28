#include "memController.h"

void main() {
	int levels = 3;
	vector<int> capacities{ 10,20,30 };
	vector<int> readTimes{ 5,10,15 };
	vector<int> writeTimes{ 10,20,30 };
	memController memController(3,capacities,readTimes,writeTimes);
	
	for (int i = 0; i < 30; i++) {
		cout << "Setting Key Number : " << i + 1 << endl;
		memController.setKey(i, "Dummy " + i);
	}
	int NUM = 50;
	for (int i = 0; i < 30; i++) {
		int key = rand() % NUM + 1;
		auto cacheRet = memController.getKey(key);
		if (cacheRet.second) {
			cout << "Cache Return value : " << cacheRet.first << endl;
		}
	}
	memController.getOverAllStats();
}