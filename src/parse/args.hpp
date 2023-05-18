#include <iostream>
#include <optional>
#include <vector>

enum Action {
	set,
	show,
	del,
	help
};

std::optional<std::string> existCmd(std::string arg);

Action getAction(std::string cmd);

int manageAction(Action act, int argc, char *arg[]);

int runCommand(int argc, char *argv[]);

int parseArgs(int num, char *args[]);

