//
// Created by Sapir Ezra on 21/08/2020.
//

#ifndef MAZEPROJECT_MAZECOMPRESSION_H
#define MAZEPROJECT_MAZECOMPRESSION_H
#include <vector>
#include <iostream>
#include "Maze2d.h"


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

		for (int i = 5; i < mazeData.size(); i++)
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
		decompressedMazeData.push_back(compressedMazeData[0]); //for x index of start position
		decompressedMazeData.push_back(compressedMazeData[1]); //for y index of start position
		decompressedMazeData.push_back(compressedMazeData[2]); //for x index of end position
		decompressedMazeData.push_back(compressedMazeData[3]); //for y index of end position
		decompressedMazeData.push_back(compressedMazeData[4]); //for maze size

		for (int i = 5; i < compressedMazeData.size(); i=i+2)
		{
			for (int j = 0; j < compressedMazeData[i+1]; j++)
			{
				decompressedMazeData.push_back(compressedMazeData[i]);
			}
		}
		return decompressedMazeData;
	}
	bool writeToFile(ofstream &out,Maze2d& maze2D) //todo
	{
		//call to compress	
	}
	Maze2d readFromFile(ifstream& in) //todo: after implementation change return val to auto instead writing the long shared_ptr
	{
		//call to decompress
	}
};


#endif //MAZEPROJECT_MAZECOMPRESSION_H
