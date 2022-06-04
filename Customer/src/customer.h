#pragma once
#include <iostream>
#include <string>
#include <sstream>
char* GetNext(char*, char, char*);
void ShowData(FILE*, std::string);
void ShowData(FILE*, std::string, std::string);
int EditData(FILE*, std::string, std::string);
long Search(FILE*, std::string, std::string);
