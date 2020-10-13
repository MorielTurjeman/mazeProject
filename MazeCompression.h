

#pragma once
#include <vector>
#include <iostream>
#include "Maze2d.h"
#include <memory>


class MazeCompression
{
public:
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
			if (i < mazeData.size() -1 &&  mazeData.at(i) == mazeData.at(i+1))
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
	bool writeToFile(ostream &out,Maze2d& maze2D) //todo
	{
		auto compressed = this->compress(maze2D.getData());
		for (auto i : compressed)
			out << i << " ";

		return true;
	}
	auto readFromFile(istream& in) 
	{
		vector<int> data;
		MazeCompression mc;
		do
		{
			int i;
			in >> i;
			data.push_back(i);
		} while (in);
		data.pop_back();		
		return std::make_shared<Maze2d>(mc.decompress(data));
	}
};


