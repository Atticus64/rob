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
	unknown
};

std::optional<std::string> exist_cmd(std::string arg) {

	const char* commands[6] = { "set", "del", "show", "--help", "-h", "run"};

	for(int i = 0; i < 6; i++){
		if (arg == commands[i]) {
			return arg;
		}
	}

	return std::nullopt; 
}

action get_action(std::string cmd) {

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

	if (cmd == "run") {
		return action::run;
	}


	return action::unknown;

}

int set_command(int args_number, char *arg[]) {

	if (args_number == 4) {
		std::string key = arg[2];
		std::string value = arg[3];

		set_key(key, value);
	}

	return 0;
}

int delete_value(int argc, char *argv[]) {

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
	std::cout << "  show"      << "\t\t     Show list of tasks" <<  "\n";
	std::cout << "  del  <key>"   << "\t     Delete a task" << "\n";
	std::cout << "  --help -h "   << "\t     Show help of rob" << "\n";
	return 0;
}

int run_command(int argc, char *argv[]) {
	
	if (argc >= 2) {
		std::string script = argv[2];

		auto file = get_file_path(script);

		if (file) {
			run_file(file.value());
		}

	}


	return 0;
}

int manage_action(action act, int argc, char *arg[]) {
	
	switch(act) {

		case action::help:
			show_help();
			break;
		case action::set:
			set_command(argc, arg);
			break;
		case action::show: 
			show_values();
			break;
		case action::del:
			delete_value(argc, arg);
			break;
		case action::run:
			run_command(argc, arg);
			break;
		case action::unknown:
			std::cout << "Unknown action" << "\n";
			break;
	}

	return 0;
}

int parse_args(int num, char *args[]) {

	for(int i = 1; i < num; i++) {
		auto cmd = exist_cmd(args[i]);
		if (cmd) {
			action act = get_action(cmd.value());

			manage_action(act, num, args);
			/* if (num >= 4) { */
				/* std::string key = args[i+1]; */
				/* std::string value = args[i+2]; */

			/* } */
		}
	}


	return 0;
}


