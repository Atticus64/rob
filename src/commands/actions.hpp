#include <iostream>
#include <optional>

int setKey(const std::string& key, const std::string& value);

int deleteKey(const std::string& key);

enum color {
	black,
	red,
	green,
	yellow,
	blue,
	magenta,
	cyan,
	white,
	reset,
	underline,
};

std::string getColor(color color);

int showHelp(); 

int showValues();

std::string getTasksPath(); 

std::optional<std::string> getFilePath(const std::string& file); 

int runFile(const std::string& path); 


