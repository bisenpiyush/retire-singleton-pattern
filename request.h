#ifndef REQUEST_H
#define REQUEST_H

//#include <iostream>
#include "data.h"
class Request
{
private:
    Data m_data;
public:
    Request(){
           std::cout << __PRETTY_FUNCTION__ << std::endl;
    };
    ~Request(){
           std::cout << __PRETTY_FUNCTION__ << std::endl;
    };
    void setData(const Data& data){
        m_data = data;
    }
    int getDataValue() const{
        return m_data.getId();
    }
};

#endif // REQUEST_H
