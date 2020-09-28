#include "Cache.h"

bool Cache::setKey(int key, string value)
{
    if (storage.count(key)) {
        cout << "Key present at current level, not proceeding further" << endl;
        return false;
    }       

    if (storage.size() == capacity) {
        //evict a page and insert
        if (evictAnEntry()) {
            cout << __func__ << "key : " << key << " : successfully set" << endl;
            storage[key] = value;
        }
    }
    else {
        storage[key] = value;
        cout << __func__ << "key : " << key << " : successfully set" << endl;
    }
    history.push_back(WRITE);
}

cacheRetVal Cache::getKey(int key)
{
    cacheRetVal retVal("",false);
    if (storage.count(key)) {
        cout << "Key present at current level, not proceeding further" << endl;
        retVal.first = storage[key];
        retVal.second = true;        
    }
    return retVal;
}

bool Cache::evictAnEntry()
{
    auto keyToEvict = storage.begin()->first;
    numEvictions++;
    storage.erase(keyToEvict);
    cout << __func__ << "key : " << keyToEvict << " : successfully Evicted From Cache" << endl;
    return true;
}

int Cache::avgTimeOFLastNOps(int n)
{
    int hSize = history.size();
    int sIdx = max(0, hSize - n);
    int numWrites = 0;
    int numReads = 0;
    for (int i = sIdx; i < hSize; i++) {
        if (history[i] == WRITE)
            numWrites++;
        else
            numReads++;
    }
    return (numWrites * writeTime + numReads * readTime) / (hSize - sIdx);
}
