#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>  // For inet_pton
#include <stdbool.h>
#include "HPC_SinglePedalDrive.h"
#include "App_HPC_Get_Set.h"

#define GDCU_SERVER_IP "127.0.0.1"
#define GDCU_SERVER_PORT 8080
#define BUFFER_SIZE 1024

extern int running;  // Flag to control the loop

extern int hpc_server_socket;
extern int gdcu_client_socket;

void init_server();
void handle_client();
void cleanup();