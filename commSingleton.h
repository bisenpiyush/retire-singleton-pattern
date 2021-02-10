#ifndef COMM_H
#define COMM_H

#include "version.h"
#if VERSION_1
#include "response.h"
#include "request.h"
#else
#include "commWrapper.h"
#endif
#if COMM_SINGLETON_VERSION_3
class CommSingleton :public CommWrapper
{
public:

    virtual Response operator()([[maybe_unused]]Request req) override{
        std::cout << "CommSingleton:" << __PRETTY_FUNCTION__ << std::endl;
        //m_req = req;
        return Response(req);
    }

private: // function
//    static CommSingleton* instance_ ;
    CommSingleton(){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    virtual ~CommSingleton() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    //copy constructor
    CommSingleton(const CommSingleton&);
    // assignment operator
    void operator=(const CommSingleton&);
};
#endif //COMM_SINGLETON_VERSION_3
// Singleton class
#if COMM_SINGLETON_VERSION_2
class CommSingleton :public CommWrapper
{
public:

    // version 2 inheritance
    //    virtual Response operator()([[maybe_unused]]Request req) override{
    //        std::cout << "CommSingleton:" << __PRETTY_FUNCTION__ << std::endl;
    //        //m_req = req;
    //        return Response(req);
    //    }

    virtual Response send(const Request& req) override{
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return Response(req);
    };

//private: // function
//    static CommSingleton* instance_ ;
    CommSingleton(){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    virtual ~CommSingleton() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    //copy constructor
    CommSingleton(const CommSingleton&);
    // assignment operator
    void operator=(const CommSingleton&);
};
#endif //COMM_SINGLETON_VERSION_2
#if COMM_SINGLETON_VERSION_1
class CommSingleton
{
public:

    static CommSingleton* instance()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        //        static CommSingleton* instance_ = nullptr;
        if(!instance_)
            instance_ = new CommSingleton();
        return instance_;
    }
    Response send(const Request& req) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return Response(req);
    };
    static void init(){
        m_someNum =0;
    }
    static void deleteCommSingleton(){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        delete instance_;
        instance_= nullptr;
    }
    // step 1-- try with destructor public
//    virtual ~CommSingleton() {
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
//        delete instance_;
//        instance_= nullptr;
//    }
private: //variables
    static int m_someNum;
private: // function
    static CommSingleton* instance_ ;
    CommSingleton(){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    virtual ~CommSingleton() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    //copy constructor
    CommSingleton(const CommSingleton&);
    // assignment operator
    void operator=(const CommSingleton&);
};
#endif //COMM_SINGLETON_VERSION_1
#endif // COMM_H
