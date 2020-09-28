#pragma once
#ifndef MEMCONTROLLER_H
#define MEMCONTROLLER_H
#include "commonHeader.h"
#include "Cache.h"
class memController {
	unordered_map<int, Cache*> caches;
	vector<int> readHistory;
	vector<int> writeHistory;
	int avgWT = 0, avgRT = 0;
	public:
		memController(int numLevels,const vector<int>& capacities, const vector<int>& readTimes, const vector<int>& writeTimes) {
			for (int i = 1; i <= numLevels; i++) {
				caches[i] = new Cache(capacities[i - 1], readTimes[i - 1], writeTimes[i - 1]);
			}			
		}
		int getNumLevels() { return caches.size(); };
		cacheRetVal getKey(int key);
		bool setKey(int key, string value);
		pair<int, int> getStatsForALevel(int cacheLevel);
		void getOverAllStats(int n=10);
		int getLastNAvgWriteTime(int n);
		int getLastNAvgReadTime(int n);
};


#endif
