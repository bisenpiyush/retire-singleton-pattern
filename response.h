#ifndef RESPONSE_H
#define RESPONSE_H

//#include <iostream>
#include "request.h"
class Response
{

public:
    Response([[maybe_unused]]const Request& req){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        std::cout << "Response is created after receiving request "
                  << "with data value: " << req.getDataValue()
                  << std::endl;
    };
    ~Response(){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    };
};

#endif // RESPONSE_H
