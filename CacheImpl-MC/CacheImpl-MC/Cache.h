#pragma once
#ifndef CACHE_H
#define CACHE_H
#include "commonHeader.h"

class Cache {
	const int READ = 0;
	const int WRITE = 1;
	int readTime;
	int writeTime;
	int numEvictions;
	int capacity;
	umap storage;
	vector<int> history;
public:
	Cache(int _capacity,int _rt,int _wt) : capacity(_capacity),readTime(_rt), writeTime(_wt),numEvictions(0){};
	bool setKey(int key, string value);
	cacheRetVal getKey(int key);
	bool evictAnEntry();
	int avgTimeOFLastNOps(int n);
	int getNumEvictions() { return numEvictions; };
	int getFreeCapacity() { return capacity - storage.size(); };
	int getReadTime() { return readTime; };
	int getWriteTime() { return writeTime; };
};





#endif

