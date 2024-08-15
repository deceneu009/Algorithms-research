#pragma once
#include<fstream>

void OpenFileRandom(long int size, std::ifstream& inputFile, std::string &NameOfFile);
void OpenFileAlmost(long int size, std::ifstream& inputFile, std::string &NameOfFile);
void OpenFileReversed(long int size, std::ifstream& inputFile, std::string &NameOfFile);