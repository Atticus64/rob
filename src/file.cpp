#include <iostream>
#include <bits/stdc++.h>
#include <optional>
#include <fstream>
#include <map>

typedef std::map<std::string, std::string> csv; 

class FileGuard {
	public:
		FileGuard(const std::string_view path) { my_file.open(path.data()); }

		~FileGuard() { my_file.close(); }

		auto data() noexcept -> std::ifstream & { return my_file; }

		auto read_file() noexcept -> std::string {

			std::string fileBuffer;
			std::string line;

			while (std::getline(my_file, line)) {
				if (line.find(",") != std::string::npos) {
					std::string copy = line;
					int pos = copy.find(",");
					std::string key = copy.substr(pos + 1);
					std::string value = copy.substr(0, pos);
					fileBuffer.append(line);
				}

			}


			return fileBuffer;
		}

	private:
		std::ifstream my_file;
};


auto read_to_string(std::string filename) -> std::optional<std::string> {
  FileGuard file(filename.data());

  if (!file.data()) {
    return {};
  }

  return file.read_file();
}


auto parse_csv(std::string path) -> csv {
	FileGuard file(path.data());

  if (!file.data()) {
    return {};
  }

	csv data;
	std::string line;
	while (std::getline(file.data(), line)) {
		if (line.find(",") != std::string::npos) {
			std::string copy = line;
			int pos = copy.find(",");
			std::string key = copy.substr(0, pos);
			std::string value = copy.substr(pos + 1);

			data[key] = value;
		}
	}


	return data;


}

