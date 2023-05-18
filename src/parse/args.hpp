#include <iostream>
#include <optional>
#include <vector>

enum action {
	set,
	show,
	del,
	help
};

std::optional<std::string> exist_cmd(std::string arg);

action get_action(std::string cmd);

int manage_action(action act);

int parse_args(int num, char *args[]);

