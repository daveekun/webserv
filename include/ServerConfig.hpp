#ifndef SERVERCONFIG_HPP
#define SERVERCONFIG_HPP

#include <string>
#include <list>
#include <fstream>
#include <iostream>
#include <exception>
#include "Route.hpp"

#define DEFAULTPATH "/tmp/serverconfig"
#define CONFIG_EXCEPTION public std::exception { \
            const char * what() const noexcept; \
        }
class ServerConfig {
    private:
        std::string m_file_path;
        std::string m_server_name;
        int m_port;
        int m_host;
        std::string m_error_page;
        int m_body_size_limit;
        std::list<Route> m_routes;
    public:
        ServerConfig() = delete;
        ~ServerConfig() = default;
        ServerConfig(const ServerConfig& other) = default;
        ServerConfig& operator=(const ServerConfig& other) = default;

        ServerConfig(std::string path = DEFAULTPATH);
        bool validate();

        class InvalidPathException : CONFIG_EXCEPTION;
        class InvalidNameException : CONFIG_EXCEPTION;
        class InvalidServerException : CONFIG_EXCEPTION;
        class InvalidSizeLimitException : CONFIG_EXCEPTION;
        class InvalidRouteException : CONFIG_EXCEPTION;
        class InvalidPortException : CONFIG_EXCEPTION;
        class InvalidHostException : CONFIG_EXCEPTION;
        class InvalidSettingException : CONFIG_EXCEPTION;
};


#endif