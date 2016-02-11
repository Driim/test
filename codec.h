#ifndef TEST_CODEC_H
#define TEST_CODEC_H

#include <fstream>
#include <iostream>
#include <stdexcept>

int encode(std::ifstream &in, std::ofstream &out);
int decode(std::ifstream &in, std::ofstream &out);

#endif //TEST_CODEC_H
