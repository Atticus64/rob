#pragma once

#include <iostream>
#include <optional>
#include <vector>
#include "../commands/actions.hpp"

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

int manageAction(Action act, int argc, char *argv[]);

int runCommand(int argc, char *argv[]);

int parseArgs(int argc, char *argv[]);

