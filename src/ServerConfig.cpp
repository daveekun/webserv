#include "ServerConfig.hpp"


ServerConfig::ServerConfig(std::string path) : m_file_path(path)
{
    std::ifstream config{path, std::ios_base::in};

    if (!config.is_open())
        throw InvalidPathException();

    for (std::string line; config >> line;)
    {
        
    }
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