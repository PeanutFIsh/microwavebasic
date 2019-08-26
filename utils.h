#ifndef UTILS_H
#define UTILS_H

bool is_number(const std::string);
std::string* splitSpaces(std::string);
int searchChar(char, std::string);
std::string trimString(std::string, int, int);
bool starts_with(const std::string, const std::string);
std::string to_upper(const std::string);
#endif