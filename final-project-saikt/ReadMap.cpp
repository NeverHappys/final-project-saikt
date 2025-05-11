#include "ReadMap.h"
#include <vector>
void ReadMap::readFile(char **arr, std::string fileName)
{
	FileWorker fw;
	//ifs.open(fileName + ".txt");
	std::string str;
	for (int i = 0; i < sizemap; i++)
	{
		str = fw.findTheString(fileName, i + 1);
		for (int j = 0; j < sizemap; j++)
		{
			//arr[i][j] = ifs.get();
			arr[i][j] = str[j];
			//std::cout << i << " " << j << std::endl;
		}
	}
	ifs.close();
}
