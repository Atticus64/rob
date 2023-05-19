#pragma once

#include <map>
#include <iostream>
#include <fstream>
#include <optional>

typedef std::map<std::string, std::string> csv; 
class FileGuard {
	public:
		FileGuard(const std::string_view path);

		std::ifstream& data() noexcept; 

		std::string read_file() noexcept;

		~FileGuard() { my_file.close(); }

	private:
		std::ifstream my_file;
};


std::optional<std::string> readToString(const std::string& filename); 


