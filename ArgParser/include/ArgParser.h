#pragma once

#include <unordered_map>
#include <string>
#include <vector>

class ArgParser
{
public: // Functions
    ArgParser(const char, const int, char** );
    
    std::string checkForArgument(const std::string&);
private: // Functions
    void  tokeninze(const std::string&);
    std::vector<std::string> parse(int, char**);
    void tokenizeAndStore(std::vector<std::string>);

public: // member variables
    std::unordered_map<std::string, std::string> m_argments;

private: // member variables
    char m_delim;
};