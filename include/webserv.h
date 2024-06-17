#ifndef WEBSERV_H
#define WEBSERV_H

#define BIT(x) 1 << x

enum e_HTTP_methods {
    NONE = 0,
    GET = BIT(1),
    POST = BIT(2),
    PUT = BIT(3),
    DELETE = BIT(4),
    HEAD = BIT(5)
};



#endif