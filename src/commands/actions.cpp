#include <iostream>
#include <stdlib.h>
#include <filesystem>
#include "../file.hpp"

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
};


std::string get_color(color color) {
	switch (color) {
		case black:
			return "\033[30m";
		case red:
			return "\033[31m";
		case green:
			return "\033[32m";
		case yellow:
			return "\033[33m";
		case blue:
			return "\033[34m";
		case magenta:
			return "\033[35m";
		case cyan:
			return "\033[36m";
		case white:
			return "\033[37m";
		case reset:
			return "\033[0m";
	}

	return "";
}

std::string get_tasks_path() {

	std::string home_dir = getenv("HOME");
	std::string file_path = home_dir + "/.tasks.csv";

	return file_path;
}

std::optional<std::string> get_file_path(std::string file) {
	std::string home_dir = getenv("HOME");
	auto path = home_dir + "/.config/scripts";

	for (const auto & entry : std::filesystem::directory_iterator(path)) {
		std::string raw_name = entry.path().filename();  
		int pos = raw_name.find(".");
		std::string name = raw_name.substr(0, pos);
		if (name == file){
			return entry.path().string();
		}
	}

	return {};
}

int run_file(std::string path) {
  system(path.data());

	return 0;
}

int set_key(std::string key, std::string value) {

	auto filepath = get_tasks_path();
	csv tasks = parse_csv(filepath);

	tasks[key] = value;

	save_csv(filepath, tasks);

	return 0;
}

int delete_key(const std::string key) {

	auto filepath = get_tasks_path();
	csv tasks = parse_csv(filepath);

	tasks.erase(key);

	save_csv(filepath, tasks);

	return 0;
}

int show_values() {

	auto filepath = get_tasks_path();
	csv tasks = parse_csv(filepath);

	std::cout << get_color(color::blue) << "Key" << "\t" << get_color(color::cyan) << "Value " << get_color(color::reset) << "\n";


	for (auto task : tasks) {
		std::cout << task.first << "\t" << task.second << "\n"; 
	}

	return 0;
}
