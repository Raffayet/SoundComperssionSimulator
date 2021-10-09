#include "WriteOutFile.h"
#include "Globals.h"


RetVal WriteOutFile(string fileName)
{
    ofstream outputFile(fileName.c_str());

	if (outputFile.is_open() == false)

	{
        cout << "WriteOutFile: Output file " << fileName << " could not be opened." << endl;
		return RET_ERROR;
	}

	HesMapa::const_accessor acc;

	for (int i = 0; i < hesMapa.size(); i++) {

		if (hesMapa.find(acc, i)) {

			outputFile << i << ":\t" << acc->second << endl;
		}
	}

	

    outputFile.close();

    return RET_OK;
}
