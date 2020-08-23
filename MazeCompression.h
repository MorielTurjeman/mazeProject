//
// Created by Sapir Ezra on 21/08/2020.
//

#ifndef MAZEPROJECT_MAZECOMPRESSION_H
#define MAZEPROJECT_MAZECOMPRESSION_H
#include "vector"


class MazeCompression
{
	std::vector<int> compress(std::vector<int> mazeData)
	{
		std::vector<int> compressedMazeData;

		compressedMazeData.push_back(mazeData[0]); //for x index of start position
		compressedMazeData.push_back(mazeData[1]); //for y index of start position
		compressedMazeData.push_back(mazeData[2]); //for x index of end position
		compressedMazeData.push_back(mazeData[3]); //for y index of end position
		compressedMazeData.push_back(mazeData[4]); //for maze size

		int numOfOccurrencesInARow = 1;

		for (int i = 5; i < mazeData[4]; i++)
		{
			if (mazeData.at(i) == mazeData.at(i+1))
			{
				numOfOccurrencesInARow++;
			}
			else
			{
				compressedMazeData.push_back(mazeData[i]);
				compressedMazeData.push_back(numOfOccurrencesInARow);
				numOfOccurrencesInARow = 1;
			}
		}
		return compressedMazeData;
	}
	std::vector<int> decompress(std::vector<int> compressedMazeData)
	{
		std::vector<int> decompressedMazeData;
		
	}
};


#endif //MAZEPROJECT_MAZECOMPRESSION_H
