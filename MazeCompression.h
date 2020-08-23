//
// Created by Sapir Ezra on 21/08/2020.
//

#ifndef MAZEPROJECT_MAZECOMPRESSION_H
#define MAZEPROJECT_MAZECOMPRESSION_H
#include "vector"


class MazeCompression
{
	void compress(std::vector<int> mazeData)
	{
		std::vector<int> compressedMazeData;
		compressedMazeData.resize(mazeData.size());

		compressedMazeData[0] = mazeData[0]; //for x index of start position
		compressedMazeData[1] = mazeData[1]; //for y index of start position
		compressedMazeData[2] = mazeData[2]; //for x index of end position
		compressedMazeData[3] = mazeData[3]; //for y index of end position
		compressedMazeData[4] = mazeData[4]; //for maze size

		int x = 0;
//		int currentIndexOfUncompressedVector = 5;
//		int currentIndexOfCompressedVector = 5;
		for (int i = 5; i < mazeData[4]; i++)
		{
			
		}
		
	}
	std::vector<int> decompress();
};


#endif //MAZEPROJECT_MAZECOMPRESSION_H
