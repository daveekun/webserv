#ifndef SERVERCONFIG_HPP
#define SERVERCONFIG_HPP

#include <string>
#include <list>

#include "Route.hpp"

class ServerConfig {
    private:
        std::string m_file_path;
        std::string m_server_name;
        int m_port;
        int m_host;
        std::string m_error_page;
        int m_body_size_limit;
        std::list<Route> m_routes;  
};


#endif