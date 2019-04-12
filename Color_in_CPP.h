/*
	Dr_T's Color in CPP
	Modified with ENUM/return value by Sunka
*/
#ifndef COLOR_IN_CPP_H
#define COLOR_IN_CPP_H

#include<iostream>
//#include<string>
#include<ctime> //to perform date/time calculations
#include<cstdlib>//for system("pause") and system("cls")
#include<windows.h>//for using various dos commands
#include<conio.h>//for using color and/or "sleep" command

enum Color { D = 7,  B = 9, G = 10, C = 11, R = 12, P = 13,
			 Y = 14, W = 15};

std::string changeColor(int colorValue = 7)  //function definition
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //use of SetConsoleTextAtrribute()
	SetConsoleTextAttribute(console,colorValue); //set the color of the text to user value 1-255
	return "";
}
#endif
