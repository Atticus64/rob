#include <iostream>
#include <optional>

int set_key(std::string key, std::string value);

int delete_key(const std::string key);

int show_values();

std::string get_tasks_path(); 

std::optional<std::string> get_file_path(std::string file); 

int run_file(std::string path); 


