// GDCU Code: Server to send one signal at a time

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <atomic>
#include <csignal>
#include <thread>
#include <chrono>
#include <netinet/in.h>
#include <netdb.h>

#define GDCU_PORT 8080 // GDCU server port

typedef struct{
     std::string signalName;  // Signal name
    int signalValue;      // Signal value
} Signal;

class GDCU
{
   int server_sock;  //socket on which gdcu listens 
   int client_sock;  // socket on which gdcu sends signals
   struct sockaddr_in serverAddr;
   socklen_t addrLen = sizeof(serverAddr);
   public:
       GDCU();
       ~GDCU();
       bool init_server();
       void handle_client_connection();
};