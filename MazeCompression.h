//
// Created by Sapir Ezra on 21/08/2020.
//

#ifndef MAZEPROJECT_MAZECOMPRESSION_H
#define MAZEPROJECT_MAZECOMPRESSION_H
#include "vector"


class MazeCompression
{
	void compress(std::vector<int> mazeData);
	std::vector<int> decompress();
};


#endif //MAZEPROJECT_MAZECOMPRESSION_H
