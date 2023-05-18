#include "file.hpp"

FileGuard::FileGuard(const std::string_view path) { my_file.open(path.data()); }

std::ifstream& FileGuard::data() noexcept {
	return my_file;
}

std::string FileGuard::read_file() noexcept {

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



std::optional<std::string> readToString(const std::string& filename) {
	FileGuard file(filename.data());

	if (!file.data()) {
		return {};
	}

	return file.read_file();
}


