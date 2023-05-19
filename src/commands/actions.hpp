#pragma once

#include <iostream>
#include <optional>
#include "../file/file.hpp"
#include "../file/csv.hpp"

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

int setKey(const std::string& key, const std::string& value);

int deleteKey(const std::string& key);


int showHelp(); 

int showValues();

int runFile(const std::string& path); 

std::string getColor(color color);

std::string getTasksPath(); 

std::optional<std::string> getFilePath(const std::string& file); 


