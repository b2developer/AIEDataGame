#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>

#define LOG Log::getInstance()

const int MAX_MESSAGE = 400;

/*
* class Log
*
* a singleton class that writes streams to a text file
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class Log
{

public:

	char logPath[MAX_PATH];

	/*
	* getInstance
	*
	* gets the pointer to the Log singleton, creates
	* the singleton if it doesn't exist already
	*
	* @returns static Log* - the singleton pointer
	*/
	static Log* getInstance();

	/*
	* initialise
	* 
	* sets up the log for writing to files
	*
	* @returns void
	*/
	void initialise();

	/*
	* write
	*
	* writes a specified stream to the log file
	*
	* @param char data[MAX_MESSAGE] - the string containing the data for the stream
	* @returns void
	*/
	void write(char data[MAX_MESSAGE]);

private:

	//hide the constructor and destructor

	/*
	* Log
	* default constructor
	*/
	Log() {};

	/*
	* ~Log
	* default destructor
	*/
	~Log() {}

};