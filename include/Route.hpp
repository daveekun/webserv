#ifndef ROUTE_HPP
#define ROUTE_HPP

#include <string>
#include <list>
#include <exception>
#include "webserv.h"

#define ROUTE_CONFIG_EXCEPTION public std::exception { \
            const char * what() const noexcept; \
        }

class Route {
    private:
        int m_allowed_methods;
        std::string m_location;
        bool m_dir_listing;
        //redirection
        std::string m_CGI;
        bool m_accept_upload;
        std::string m_uploaddir;
    public:
        Route() = delete;
        Route(std::list<e_HTTP_methods> allowed_methods,
        std::string location,std::string cgi, 
        std::string upload_dir = "",  bool dir_listing = false,
        bool accept_upload = false);
        ~Route() = default;
        Route(const Route& other) = default;
        Route& operator=(const Route& other) = default;

        bool validate() const;
        class InvalidUploadException : ROUTE_CONFIG_EXCEPTION;
        class InvalidLocation : ROUTE_CONFIG_EXCEPTION;
        class InvalidMethods : ROUTE_CONFIG_EXCEPTION;
};

#endif