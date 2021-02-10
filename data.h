#ifndef DATA_H
#define DATA_H

#include <iostream>

class Data
{
private:
    int m_id;
public:
    Data():m_id(0){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    Data(const int& id):m_id(id){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    ~Data(){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    int getId() const{
        return m_id;
    }
};

#endif // DATA_H
