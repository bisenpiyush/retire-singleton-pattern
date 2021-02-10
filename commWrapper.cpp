#include "commWrapper.h"


/*
 * Potential problem : Default instance is created before main runs.
• There may be static dependencies across TUs
• Some setup initialization may occur prior to this code being usable
Need to delay creation of default instance post main() start preferably
using lazy initialization
*/
#if COMM_WRAPPER_VERSION_1 || COMM_WRAPPER_VERSION_2
CommWrapper Service::comm;  //initialization happening
#endif
/********Lazy initialization***********/
//version-2
#if COMM_WRAPPER_VERSION_3
struct Service{
    CommWrapper comm;
};

CommWrapper& getDefaultComm(){
    static Service s_client;
    return s_client.comm;
}
#endif // COMM_WRAPPER_VERSION_3
