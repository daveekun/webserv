#include "ServerConfig.hpp"


ServerConfig::ServerConfig(std::string path) : m_file_path(path)
{
    std::ifstream config{path, std::ios_base::in};

    if (!config.is_open())
        throw InvalidPathException();

    int depth = 0;
	/* TODO tokeniser that makes dict*/
    // for (std::string line; config >> line;)
    // {
    //     // # at start of line is comment
    //     // each line contains
    //     // key: value,
    //     //      or
    //     // key { 
    //     // except the last line of each block, where there is no ","
    //     // and the end of blocks, where its only "}" 
    //     if (line._Starts_with("server"))
    //     {
    //         if (line.begin() + line.find("{") != line.end()
    //         || line.rfind("{") != line.find("{")
    //         || line.find_first_not_of(" ", line.find("server") + 6, line.find("{")) == std::string::npos)
    //             throw InvalidServerException();
    //         depth++;
    //     }
    //     else if (line._Starts_with("name:"))
    //     {
            
    //     }
    //     else if (line._Starts_with("host:"))
    //     {

    //     }
    //     else if (line._Starts_with("port:"))
    //     {

    //     }
    //     else if (line._Starts_with("errorpages:"))
    //     {

    //     }
    //     else if (line._Starts_with("sizelimit:"))
    //     {

    //     }
    //     else if (line._Starts_with("route"))
    //     {

    //     }
    //     else if (line._Starts_with("}"))
    //     {

    //     }
    //     else
    //         throw InvalidSettingException();
    // }
}

const char * ServerConfig::InvalidPathException::what() const noexcept
{
    return "cant open config file";
}

const char * ServerConfig::InvalidNameException::what() const noexcept
{
    return "invalid setting in config: Name";
}

const char * ServerConfig::InvalidSizeLimitException::what() const noexcept
{
    return "invalid setting in config: SizeLimit";
}

const char * ServerConfig::InvalidRouteException::what() const noexcept
{
    return "invalid setting in config: Route";
}

const char * ServerConfig::InvalidPortException::what() const noexcept
{
    return "invalid setting in config: Port";
}

const char * ServerConfig::InvalidHostException::what() const noexcept
{
    return "invalid setting in config: Host";
}

const char * ServerConfig::InvalidSettingException::what() const noexcept
{
    return "invalid setting in file";
}