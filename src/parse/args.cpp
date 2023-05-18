#include <iostream>
#include "../commands/actions.hpp"
#include <optional>
#include <vector>

enum action {
	set,
	show,
	del,
	help,
	run,
	help_cmd,
	unknown
};

std::optional<std::string> existCmd(std::string arg) {

	const char* commands[7] = { "set", "del", "show", "--help", "-h", "run", "help"};

	for(int i = 0; i < 7; i++){
		if (arg == commands[i]) {
			return arg;
		}
	}

	return std::nullopt; 
}

action getAction(std::string cmd) {

	if (cmd == "set") {
		return action::set;
	}

  if (cmd == "show") {
		return action::show;
	}

  if (cmd == "del") {
		return action::del;
	}

	if (cmd == "--help" || cmd == "-h") {
		return action::help;
	}

	if (cmd == "help") {
		return action::help_cmd;
	}

	if (cmd == "run") {
		return action::run;
	}


	return action::unknown;

}

int setCommand(int args_number, char *arg[]) {

	if (args_number == 4) {
		std::string key = arg[2];
		std::string value = arg[3];

		set_key(key, value);
	}

	return 0;
}

int delCommand(int argc, char *argv[]) {

	if (argc >= 2) {
		std::string key = argv[2];

		delete_key(key);
	}

	return 0;
}

int show_help() {
	

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

int run_command(int argc, char *argv[]) {
	
	if (argc >= 3) {
		std::string script = argv[2];

		auto file = get_file_path(script);

		if (file) {
			run_file(file.value());
		}

	}


	return 0;
}

int getHelpMessage(std::string_view command) {
	
	if (command == "set") {
		std::cout << get_color(color::underline) << "Set" <<  get_color(color::reset) << " command" << "\n";
		std::cout << "\tSet a task" << "\n";
		std::cout << get_color(color::blue) <<"Usage:" << get_color(color::reset) << "\n";
		std::cout << "\tset [key] [value]" << "\n";
		std::cout << get_color(color::yellow) << "Example:" << get_color(color::reset) << "\n";
		std::cout << "\tset ticket 'Resolve bug in module actions'" << "\n";
		return 0;
	}

  if (command == "del") {
		std::cout << get_color(color::underline) << "Del" <<  get_color(color::reset) << " command" << "\n";
		std::cout << "\tDelete a task" << "\n";
		std::cout << get_color(color::blue) <<"Usage:" << get_color(color::reset) << "\n";
		std::cout << "\tdel [key]" << "\n";
		std::cout << get_color(color::yellow) << "Example:" << get_color(color::reset) << "\n";
		std::cout << "\tdel ticket" << "\n";
		return 0;
	}

	if (command == "run") {
		std::cout << get_color(color::underline) << "Run" <<  get_color(color::reset) << "command" << "\n";
		std::cout << "\tRun a custom script" << "\n";
		std::cout << get_color(color::blue) <<"Usage:" << get_color(color::reset) << "\n";
		std::cout << "\trun [name]" << "\n";
		std::cout << get_color(color::yellow) << "Example:" << get_color(color::reset) << "\n";
		std::cout << "\trun update" << "\n";
		std::cout << get_color(color::cyan)  << "Note:" << get_color(color::reset) << " in your folder ~/.config/scripts" << "\n";
		std::cout << "Must have a file with execution permission"<< "\n";
		std::cout << "The name is without extension, if file is update.sh the name is update"<< "\n";
		return 0;
	}


	std::cout << "No help for that command" << "\n";
	return 0;
}

int showCmdHelp(int num, char *args[]) {

	if (num >= 3) {
		std::string cmd = args[2];

		if (existCmd(cmd)) {
			getHelpMessage(cmd);
			return 0;
		}
	}

	std::cout << "No cmd provided to help";

	return 0;
}

int manage_action(action act, int argc, char *arg[]) {
	
	switch(act) {

		case action::help:
			show_help();
			break;
		case action::set:
			setCommand(argc, arg);
			break;
		case action::show: 
			show_values();
			break;
		case action::del:
			delCommand(argc, arg);
			break;
		case action::run:
			run_command(argc, arg);
			break;
		case action::help_cmd:
			showCmdHelp(argc, arg);
			break;
		case action::unknown:
			std::cout << "Unknown action" << "\n";
			break;
	}

	return 0;
}

int parse_args(int num, char *args[]) {

	for(int i = 1; i < num; i++) {
		auto cmd = existCmd(args[i]);
		if (cmd) {
			action act = getAction(cmd.value());

			manage_action(act, num, args);
			return 0;
		}
		show_help();
	}


	return 0;
}


