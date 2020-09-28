#include "memController.h"

cacheRetVal memController::getKey(int key)
{
    // if found , propogate it to all upper levels and return 
    // not found in the last elvel , retun null
    cacheRetVal retVal;
    int readTime = 0;
    int foundAtLevel = -1;
    for (int i = 1; i <= getNumLevels(); i++) {
        cout << "Accessing Level " << i << ", for getKey()" << endl;
        auto cacheAccess = caches[i]->getKey(key);
        readTime += caches[i]->getReadTime();
        if (cacheAccess.second) {
            retVal = cacheAccess;
            foundAtLevel = i;
            break;            
        }
    }
    if (foundAtLevel != -1) {
        for (int i = 1; i < foundAtLevel; i++) {
            if (!caches[i]->setKey(key, retVal.first)) {
                cout << __func__<<"Some issue in setting value for level : " << i << endl;
            }
            readTime += caches[i]->getWriteTime();
        }
    }
    readHistory.push_back(readTime);
    return retVal;
}

bool memController::setKey(int key, string value)
{
    int writeTime = 0;
    for (int i = 1; i <= getNumLevels(); i++) {
        cout << "Accessing Level " << i << ", for setKey()" << endl;
        if (!caches[i]->setKey(key, value)){
            cout << __func__ << ": setting stopped at level " << i <<" as the key was found "<< endl;
            caches[i]->getReadTime();
            break;
        }
        writeTime += caches[i]->getWriteTime();
    }
    writeHistory.push_back(writeTime);
    return true;
}

void memController::getOverAllStats(int n)
{
    int numEvictions = 0;
    int freeCapacity = 0;
    for (int i = 1; i <= getNumLevels(); i++) {
        auto stats = getStatsForALevel(i);
        numEvictions += stats.first;
        freeCapacity += stats.second;
    }
    int lastNWT = getLastNAvgWriteTime(n);
    int lastNRT = getLastNAvgReadTime(n);
    
    cout << " Number of Evictions : " << numEvictions << endl;
    cout << " Last " << n << " Read Times : " << lastNRT << endl;
    cout << " Last " << n << " Write Times : " << lastNWT << endl;
    cout << " Free Capacity : " << freeCapacity << endl;
}

int memController::getLastNAvgWriteTime(int n)
{
    int sIdx = max((double)0, (double)(writeHistory.size() - n));
    if (sIdx == 0)
        return avgWT;
    int tempAvgWT = 0;
    for (int i = sIdx; i < writeHistory.size(); i++)
        tempAvgWT += writeHistory[i];
    return tempAvgWT / (writeHistory.size() - sIdx );
}

int memController::getLastNAvgReadTime(int n)
{
    int sIdx = max((double)0, (double)(readHistory.size() - n));
    if (sIdx == 0)
        return avgRT;
    int tempAvgRT = 0;
    for (int i = sIdx; i < readHistory.size(); i++)
        tempAvgRT += readHistory[i];
    return tempAvgRT / (readHistory.size() - sIdx );
}

pair<int, int> memController::getStatsForALevel(int cacheLevel)
{
    int numEvictions = 0;
    int freeCapacity = 0;
    if (cacheLevel <= caches.size()) {
        numEvictions = caches[cacheLevel]->getNumEvictions();
        freeCapacity = caches[cacheLevel]->getFreeCapacity();        
    }
    else {
        cout << __func__ << ": Invalid cache level " << cacheLevel << endl;
    }
    return pair<int, int>(numEvictions, freeCapacity);
}
