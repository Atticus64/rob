#include <iostream>
#include <optional>

int setKey(std::string key, std::string value);

int deleteKey(const std::string key);


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

int show_help(); 

int showValues();

std::string getTasksPath(); 

std::optional<std::string> getFilePath(std::string file); 

int runFile(std::string path); 


