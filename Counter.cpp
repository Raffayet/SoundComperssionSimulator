#include "Counter.h"
#include <iostream>
#include "Globals.h"

struct Brojac {
	HesMapa& table;
	Brojac(HesMapa& table_) : table(table_) {}
	void operator()(const blocked_range<unsigned int> range) const {
		HesMapa::accessor acc;
		for (unsigned int i = range.begin(); i != range.end(); ++i) {
			table.insert(acc, clip2CounterVector[i]);
			acc->second += 1;
			acc.release(); 
		}
	}
};


RetVal Counter()
{

	Brojac br(HesMapa);

	parallel_for(blocked_range<unsigned int>(0, clip2CounterVector.size()), Brojac(hesMapa));

    return RET_OK;
}
