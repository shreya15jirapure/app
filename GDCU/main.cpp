#include "gdcu.h"

int main()
{
    GDCU gdcu_server;

    if(!gdcu_server.init_server())
    {
        return -1;
    }
    gdcu_server.handle_client_connection();
    return 0;
}