#include "Log.h"

//gets and or creates the singleton pointer
Log* Log::getInstance()
{
	static Log* singleton = nullptr;

	//check if the singleton has been created
	if (singleton == nullptr)
	{
		//create log instance
		singleton = new Log();
	}

	return singleton;
}

//sets the file path
void Log::initialise()
{
	//get the file name
	char buffer[MAX_PATH];
	ZeroMemory(buffer, sizeof(buffer));

	GetModuleFileName(NULL, buffer, MAX_PATH);

	//find the first backslash
	char* slash = strrchr(buffer, '\\');

	//set it to a null terminator, this tricks the program into thinking that the string ends here
	*slash = '\0';

	char extension[MAX_PATH] = "\\output\\log.txt";

	//add the extension to the buffer
	strcat_s(buffer, extension);

	//copy the buffer to the logPath
	strcpy_s(logPath, buffer);
}

//writes a stream to a log
void Log::write(char data[MAX_MESSAGE])
{
	std::ofstream logFile;

	//open logFile for appending, not overwriting
	logFile.open(logPath, std::fstream::app);

	logFile << data << '\n';
}
