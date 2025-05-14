#include "server.h"
#include <signal.h>


// int running = 1;  // Flag to control the loop

// Signal handler function to set the 'running' flag to 0
void signal_handler(int signal) 
{
    if (signal == SIGINT) 
    {
        printf("Received SIGINT, exiting loop...\n");
        running = 0;  // Set the flag to 0, breaking the loop
        close(hpc_server_socket);
    }
}

int main() 
{
    // logs will print k3s
    setbuf(stdout, NULL);

    // Register the signal handler for SIGINT
    signal(SIGINT, signal_handler);

    // Initialize Single Pedal Drive
    HPC_SinglePedalDrive_initialize();

    init_server();
    handle_client();
    cleanup();

    // Cleanup
    HPC_SinglePedalDrive_terminate();
    printf("Exiting program...\n");
    return 0;
}
