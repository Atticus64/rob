#include <iostream>
#include <optional>
#include <vector>

enum Action {
	set,
	show,
	del,
	help,
	run,
	unknown,
	help_cmd
};

std::optional<std::string> existCmd(const std::string& arg);

Action getAction(const std::string& cmd);

int manageAction(Action act, int argc, char *arg[]);

int runCommand(int argc, char *argv[]);

int parseArgs(int num, char *args[]);

