#include <iostream>
#include <bits/stdc++.h>
#include <optional>
#include <fstream>
#include <map>

typedef std::map<std::string, std::string> csv; 

class FileGuard {
	public:
		FileGuard(const std::string_view path);

		~FileGuard() { my_file.close(); }

		std::ifstream data() noexcept; 

		std::string read_file() noexcept;

	private:
		std::ifstream my_file;
};


std::optional<std::string> read_to_string(std::string filename); 


csv parse_csv(std::string path); 


int save_csv(std::string path, csv data);
