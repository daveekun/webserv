#ifndef ROUTE_HPP
#define ROUTE_HPP

#include <string>
#include <list>
#include "webserv.h"

#define CONFIG_EXCEPTION public InvalidConfigException { \
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
        std::string location, bool dir_listing = false, std::string cgi, 
        bool accept_upload = false, std::string upload_dir = "");
        ~Route() = default;
        Route(const Route& other) = default;
        Route& operator=(const Route& other) = default;

        bool validate() const;
        class InvalidConfigException : public std::exception {
            const char * what() const noexcept;
        };
        class InvalidUploadException : CONFIG_EXCEPTION;
        class InvalidLocation : CONFIG_EXCEPTION;
        class InvalidMethods : CONFIG_EXCEPTION;
};

#endif