#include <iostream>
#include <optional>
#include <vector>

enum action {
	set,
	show,
	del,
	help
};

auto exist_cmd(std::string arg) -> std::optional<std::string> {

	const char* commands[3] = { "set", "del", "show" };

	for(int i = 0; i < 3; i++){
		if (arg == commands[i]) {
			return arg;
		}
	}

	return std::nullopt; 
}

auto get_action(std::string cmd) {

	if (cmd == "set") {
		return action::set;
	}

  if (cmd == "show") {
		return action::show;
	}

  if (cmd == "del") {
		return action::del;
	}


	return action::help;

}


auto manage_action(action act) {
	
	switch(act) {

		case action::help:
			std::cout << "help" << "\n";
			break;
		case action::set:
			std::cout << "set" << "\n";
			break;

		case action::show:
			std::cout << "show" << "\n";
			break;
		case action::del:
			std::cout << "delete" << "\n";
			break;
	}

	return 0;
}


auto parse_args(int num, char *args[]) -> int {

	for(int i = 1; i < num; i++) {
		auto cmd = exist_cmd(args[i]);
		if (cmd) {
			action act = get_action(cmd.value());

			manage_action(act);
			/* if (num >= 4) { */
				/* std::string key = args[i+1]; */
				/* std::string value = args[i+2]; */

			/* } */
		}
	}


	return 0;
}

