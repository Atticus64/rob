#include "args.hpp"

/*
* Check if command exists 
* @param arg possible command
* @return the arg if exists or not
*/
std::optional<std::string> existCmd(const std::string& arg) {

	const char* commands[7] = { "set", "del", "show", "--help", "-h", "run", "help"};

	for(int i = 0; i < 7; i++){
		if (arg == commands[i]) {
			return arg;
		}
	}

	return std::nullopt; 
}

/*
* Get the action of a command
* @param cmd command string
* @return the action
*/
Action getAction(const std::string& cmd) {

	if (cmd == "set") {
		return Action::set;
	}

	if (cmd == "show") {
		return Action::show;
	}

	if (cmd == "del") {
		return Action::del;
	}

	if (cmd == "--help" || cmd == "-h") {
		return Action::help;
	}

	if (cmd == "help") {
		return Action::help_cmd;
	}

	if (cmd == "run") {
		return Action::run;
	}


	return Action::unknown;

}



int getHelpMessage(std::string_view command) {

	if (command == "set") {
		std::cout << getColor(color::underline) << "Set" <<  getColor(color::reset) << " command" << "\n";
		std::cout << "\tSet a task" << "\n";
		std::cout << getColor(color::blue) <<"Usage:" << getColor(color::reset) << "\n";
		std::cout << "\tset [key] [value]" << "\n";
		std::cout << getColor(color::yellow) << "Example:" << getColor(color::reset) << "\n";
		std::cout << "\tset ticket 'Resolve bug in module actions'" << "\n";
		return 0;
	}

	if (command == "del") {
		std::cout << getColor(color::underline) << "Del" <<  getColor(color::reset) << " command" << "\n";
		std::cout << "\tDelete a task" << "\n";
		std::cout << getColor(color::blue) <<"Usage:" << getColor(color::reset) << "\n";
		std::cout << "\tdel [key]" << "\n";
		std::cout << getColor(color::yellow) << "Example:" << getColor(color::reset) << "\n";
		std::cout << "\tdel ticket" << "\n";
		return 0;
	}

	if (command == "run") {
		std::cout << getColor(color::underline) << "Run" <<  getColor(color::reset) << " command" << "\n";
		std::cout << "\tRun a custom script" << "\n";
		std::cout << getColor(color::blue) <<"Usage:" << getColor(color::reset) << "\n";
		std::cout << "\trun [name]" << "\n";
		std::cout << getColor(color::yellow) << "Example:" << getColor(color::reset) << "\n";
		std::cout << "\trun update" << "\n";
		std::cout << getColor(color::cyan)  << "Note:" << getColor(color::reset) << " in your folder ~/.config/scripts" << "\n";
		std::cout << "Must have a file with execution permission"<< "\n";
		std::cout << "The name is without extension, if file is update.sh the name is update"<< "\n";
		return 0;
	}


	std::cout << "No help for that command" << "\n";
	return 0;
}

int showCmdHelp(int argc, char *argv[]) {

	if (argc >= 3) {
		std::string cmd = argv[2];

		if (existCmd(cmd)) {
			getHelpMessage(cmd);
			return 0;
		}
	}

	std::cout << "No cmd provided to help";

	return 0;
}

int setCommand(int argc, char *argv[]) {

	if (argc >= 4) {
		std::string key = argv[2];
		std::string value = argv[3];

		setKey(key, value);
	} else {
		std::cout << "key and value not provided" << std::endl;
		getHelpMessage("set");
	}

	return 0;
}

int delCommand(int argc, char *argv[]) {

	if (argc >= 3) {
		std::string key = argv[2];

		deleteKey(key);
	} else {
		std::cout << "No key provided" << "\n";
		getHelpMessage("del");
	}

	return 0;
}

int runCommand(int argc, char *argv[]) {
	
	if (argc >= 3) {
		std::string script = argv[2];

		auto file = getFilePath(script);

		if (file) {
			runFile(file.value());
		}

	} else {
		std::cout << "No script provided" << "\n";
		getHelpMessage("run");
	}


	return 0;
}
/*
* Call functions to manage commands actions
* @param act Action to do
* @param argc Number of arguments
* @param arg Arguments
*/
int manageAction(Action act, int argc, char *argv[]) {
	
	switch(act) {

		case Action::help:
			showHelp();
			break;
		case Action::set:
			setCommand(argc, argv);
			break;
		case Action::show: 
			showValues();
			break;
		case Action::del:
			delCommand(argc, argv);
			break;
		case Action::run:
			runCommand(argc, argv);
			break;
		case Action::help_cmd:
			showCmdHelp(argc, argv);
			break;
		case Action::unknown:
			std::cout << "Unknown action" << "\n";
			break;
	}

	return 0;
}

int showAscii() {
	std::cout << "  \\.===./    " << "\n";
  	std::cout << "  | 0 0 |    " << "\n";
  	std::cout << "   \\_-_/     " << "\n";
  	std::cout << "(m9\\:::/\\    " << "\n";
  	std::cout << "   /___\\6    " << "\n";
  	std::cout << "   /| |\\    " << "\n";
  	std::cout << "  [_] [_]\n";
	std::cout << "Hello, I am Rob your assistant try rob --help\n";
	return 0;
}

/*
* Parse arguments of cli and call to manager of commands
* if command was not found should return help cli
*/
int parseArgs(int argc, char *argv[]) {

	if (argc == 1) {
		showHelp();
	}


	for(int i = 1; i < argc; i++) {
		auto cmd = existCmd(argv[i]);
		if (cmd) {
			Action act = getAction(cmd.value());

			manageAction(act, argc, argv);
			return 0;
		}
		showAscii();
	}


	return 0;
}


