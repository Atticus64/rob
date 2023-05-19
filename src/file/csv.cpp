#include "csv.hpp"

/*
* Parses a CSV file and returns a map of the CSV file.
* @param path fs path of the CSV file
* @returns csv object map
*/
csv parseCsv(const std::string& path) {
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

/*
* Save object csv to a file path
*/
int saveCsv(const std::string& path, csv data) {
	std::ofstream info(path);

	for (const auto &[key, value] : data) {
		info << key << "," << value << std::endl;
	}

	info.close();

	return 0;
}
 

