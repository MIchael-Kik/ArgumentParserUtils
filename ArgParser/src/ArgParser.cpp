#include <ArgParser.h>
#include <sstream>

// Constructor
ArgParser::ArgParser(const char delim, const int argc, char** argv)
: m_delim(delim)
{
    std::vector<std::string> argumentVector = parse(argc, argv);
    tokenizeAndStore(argumentVector);
};

std::vector<std::string> ArgParser::parse(int argc, char** argv)
{
    std::vector<std::string> strings;
    for (int i = 1; i < argc; i++)
    {
        strings.push_back(std::string(argv[i]));
    }

    return strings;
}

void ArgParser::tokeninze(const std::string& str)
{
    std::stringstream stream(str);

    std::string string;

    std::string key;
    std::string value;

    while(std::getline(stream, string, m_delim))
    {
        if(string.find("--") != std::string::npos)
        {
            key=string;
        } else {
            if(key == "") break;
            value = string;
            m_argments[key] = value;

            key = "";
        }
    }

}

void ArgParser::tokenizeAndStore(std::vector<std::string> strings)
{
    for(auto& string: strings)
    {
        tokeninze(string);
    }
}

std::string ArgParser::checkForArgument(const std::string& keyValue)
{
    return m_argments[keyValue] != ""? m_argments[keyValue]: "NOT FOUND"; 
}