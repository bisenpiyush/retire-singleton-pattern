#ifndef COMMWRAPPER_H
#define COMMWRAPPER_H

#include "version.h"
#include <iostream>
#include "response.h"


//version -1
#if COMM_WRAPPER_VERSION_1
class CommWrapper
{
public:
    CommWrapper(){
         std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    virtual Response send([[maybe_unused]]const Request& req){
         std::cout << __PRETTY_FUNCTION__ << std::endl;
         return Response(req);
    }
    virtual ~CommWrapper(){
         std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};
struct Service{
    static CommWrapper comm;
};
#endif //COMM_WRAPPER_VERSION_1
// version -2
#if COMM_WRAPPER_VERSION_2
class CommWrapper
{
private:
    Request m_req;
public:
    CommWrapper(){
         std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    Response operator()([[maybe_unused]]Request req){
        std::cout << "CommWrapper:" << __PRETTY_FUNCTION__ << std::endl;
        m_req = req;
        return Response(req);
    }
    virtual ~CommWrapper(){
         std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};
struct Service{
    static CommWrapper comm;
};
#endif //COMM_WRAPPER_VERSION_2
#if COMM_WRAPPER_VERSION_3
class CommWrapper
{
private:
    Request m_req;
public:
    CommWrapper(){
         std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    virtual Response operator()([[maybe_unused]]Request req){
        std::cout << "CommWrapper:" << __PRETTY_FUNCTION__ << std::endl;
        m_req = req;
        return Response(req);
    }
    virtual ~CommWrapper(){
         std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

CommWrapper& getDefaultComm();

#endif // COMM_WRAPPER_VERSION_3

#endif // COMMWRAPPER_H
