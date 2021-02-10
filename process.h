#ifndef PROCESS_H
#define PROCESS_H

#include "version.h"

#include <functional>

#include "commSingleton.h"

class Process
{
    using comm_func = std::function<Response(Request)>;
public:
    Process(){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    ~Process(){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
//        CommSingleton::deleteCommSingleton();
    }
    //version-4
#if VERSION_4
    Response sendData(const Data& data, CommWrapper& comm){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        Request req;
        // transfer data into the request
        req.setData(data);
        return comm(std::move(req));
    }
     // compatiable with oldest version
    Response sendData(const Data& data){
     std::cout << __PRETTY_FUNCTION__ << std::endl;
     return sendData(data, getDefaultComm() );
    }
#endif //VERSION_4
    // version-3
#if VERSION_3
    Response sendData(const Data& data, comm_func comm = std::ref(Service::comm)){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        Request req;
        // transfer data into the request
        req.setData(data);
        return comm(std::move(req));
    }

#endif

#if VERSION_2
    // version-2
    Response sendData(const Data& data, CommWrapper& comm = Service::comm){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        Request req;
        // transfer data into the request
        req.setData(data);
        return comm.send(req);
    }
 #endif // VERSION_2
    // oldest version
#if VERSION_1
    Response sendData(const Data& data){
     std::cout << __PRETTY_FUNCTION__ << std::endl;
        Request req;
        // transfer data into the request
        req.setData(data);
        return CommSingleton::instance()->send(req);// hidden dependency
    }
#endif
};

#endif // PROCESS_H
