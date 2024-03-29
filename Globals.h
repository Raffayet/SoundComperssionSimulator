#ifndef _GLOBALS_H_
#define _GLOBALS_H_


#include <queue>
#include <vector>

#include "tbb/concurrent_vector.h"
#include "tbb/concurrent_hash_map.h"
#include "tbb/concurrent_queue.h"

#include "defines.h"

using namespace std;
using namespace tbb;


// globals

typedef concurrent_hash_map<unsigned char, unsigned int> HesMapa;

extern queue<unsigned char> in2HighPassQueue;
extern concurrent_vector<short> highPass2ClipVec;
extern concurrent_vector<unsigned char> clip2CounterVector;
extern HesMapa hesMapa;

#endif