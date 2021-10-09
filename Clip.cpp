#include "Clip.h"

extern concurrent_vector<short> highPass2ClipVec;
extern concurrent_vector<unsigned char> clip2CounterVector;

struct ClipKlasa {
	int lowerLimit;
	int upperLimit;
	void operator()(const blocked_range<int>& range) const {
		short data;
		for (int i = range.begin(); i != range.end(); ++i)
		{
			data = highPass2ClipVec[i];

			if (data < lowerLimit)
			{
				data = lowerLimit;
			}
			else if (data > upperLimit)
			{
				data = upperLimit;
			}

			clip2CounterVector.push_back(data);
		}
	}
};


RetVal Clip(char lowerValue, char upperValue) {


	ClipKlasa ck;
	ck.lowerLimit = lowerValue;
	ck.upperLimit = upperValue;

	parallel_for(blocked_range<int>(0, highPass2ClipVec.size()), ck);

    return RET_OK;
}
