#include <iostream>
#include <bits/stdc++.h>

typedef std::map<std::string, std::string> csv; 

csv parseCsv(const std::string& path); 

int saveCsv(const std::string& path, csv data);
