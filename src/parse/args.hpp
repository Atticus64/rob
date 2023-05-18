#include <iostream>
#include <optional>
#include <vector>

enum action {
	set,
	show,
	del,
	help
};

std::optional<std::string> existCmd(std::string arg);

action getAction(std::string cmd);

int manageAction(action act, int argc, char *arg[]);

int runCommand(int argc, char *argv[]);

int parseArgs(int num, char *args[]);

