#include "Route.hpp"

Route::Route(std::list<e_HTTP_methods> allowed_methods,
        std::string location, bool dir_listing,
        std::string cgi, bool accept_upload = false,
        std::string upload_dir) : m_location(location),
        m_dir_listing(dir_listing), m_CGI(cgi), 
        m_accept_upload(accept_upload), m_uploaddir(upload_dir)
{
    for (e_HTTP_methods& method : allowed_methods)
        m_allowed_methods += method;
    validate();
}

bool Route::validate() const
{
    if (m_location == "")
        throw InvalidLocation();
    if (m_allowed_methods == 0)
        throw InvalidMethods();
    if (m_uploaddir != "" && m_accept_upload == false)
        throw InvalidUploadException();
    return true;
}

const char * Route::InvalidConfigException::what() const noexcept {
    return "Invalid configuration in route";
}

const char * Route::InvalidMethods::what() const noexcept {
    return "Invalid methods for route";
}

const char * Route::InvalidLocation::what() const noexcept {
    return "Missing location for route";
}

const char * Route::InvalidUploadException::what() const noexcept {
    return "Invalid Upload options for route";
}