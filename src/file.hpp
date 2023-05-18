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


std::optional<std::string> readToString(const std::string& filename); 


csv parseCsv(const std::string& path); 

int saveCsv(const std::string& path, csv data);
