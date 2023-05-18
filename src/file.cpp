#include <iostream>
#include <bits/stdc++.h>
#include <optional>
#include <fstream>
#include <map>

typedef std::map<std::string, std::string> csv; 

class FileGuard {
	public:
		FileGuard(const std::string_view path) { my_file.open(path.data()); }

		~FileGuard() { 
			my_file.close(); 
			write_file.close();
		}

		std::ifstream&  data() noexcept { 
			return my_file; 
		}

		std::ofstream& write() noexcept { 
			return write_file; 
		}

		std::string read_file() noexcept {

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
		std::ofstream write_file;
};


std::optional<std::string> read_to_string(std::string filename) {
  FileGuard file(filename.data());

  if (!file.data()) {
    return {};
  }

  return file.read_file();
}


csv parse_csv(std::string path) {
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

int save_csv(std::string path, csv data) {
	std::ofstream info(path);

	for (const auto &[key, value] : data) {
		info << key << "," << value << std::endl;
	}

	info.close();

	return 0;
}
 
