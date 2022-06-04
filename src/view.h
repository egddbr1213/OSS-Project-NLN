#pragma once
#include <iostream>
#include <string>
#include <sstream>

enum Color
{
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LIGHTGRAY,
	DARKGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELLOW,
	WHITE
};

//void textcolor(int, int);
//void mainpage(int);

char* GetNext(char*, char, char*);
std::string SearchLocation(std::string);
bool LogIn(std::string&);
std::string Search(std::string, std::string, std::string, std::string);
long Search(FILE*, std::string, std::string);
void InventoryManagement(std::string);
void InventoryManagement(std::string, int);
void ShowData(FILE*, std::string, std::string, std::string);

