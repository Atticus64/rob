#include "actions.hpp"

std::string getColor(color color) {
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
		case underline:
			return "\033[4m";
	}

	return "";
}

std::string getTasksPath() {

	std::string home_dir = getenv("HOME");
	std::string file_path = home_dir + "/.tasks.csv";

	return file_path;
}

int showHelp() {
	std::cout << "CLI assistant for manage tasks and scripts by Jona 🍪" << "\n";
	std::cout << "\n";
	std::cout << "Usage: rob [COMMAND] [ARGS]" << "\n\n";
	std::cout << "Commands:\n";
	std::cout << "  set  <key> <value>" << " Set a task value" << "\n";
	std::cout << "  run  [name]" << "        Run a script of folder ~/.config/scripts" << "\n";
	std::cout << "  show"      << "\t\t     Show list of tasks" <<  "\n";
	std::cout << "  del  <key>"   << "\t     Delete a task" << "\n";
	std::cout << "  --help -h "   << "\t     Show help of rob" << "\n";
	return 0;
}


std::optional<std::string> getFilePath(const std::string& file) {
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

int runFile(const std::string& path) {
	system(path.data());

	return 0;
}

int setKey(const std::string& key, const std::string& value) {

	auto filepath = getTasksPath();
	csv tasks = parseCsv(filepath);

	tasks[key] = value;

	saveCsv(filepath, tasks);

	return 0;
}

int deleteKey(const std::string& key) {

	auto filepath = getTasksPath();
	csv tasks = parseCsv(filepath);

	tasks.erase(key);

	saveCsv(filepath, tasks);

	return 0;
}

int showValues() {

	auto filepath = getTasksPath();
	csv tasks = parseCsv(filepath);

	std::cout << getColor(color::blue) << "Key" << "\t" << getColor(color::cyan) << "Value " << getColor(color::reset) << "\n";


	for (auto task : tasks) {
		std::cout << task.first << "\t" << task.second << "\n"; 
	}

	return 0;
}
