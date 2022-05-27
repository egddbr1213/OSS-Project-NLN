#pragma once
#include <iostream>
//#include <conio.h>
//#include <Windows.h>

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
