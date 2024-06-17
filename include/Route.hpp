#ifndef ROUTE_HPP
#define ROUTE_HPP

#include <string>

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
        Route();
        ~Route();
        Route(const Route& other);
        Route& operator=(const Route& other);
        
        bool validate() const;
};

#endif