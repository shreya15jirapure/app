#include "server.h"

// Define global variables
int running = 1;
int hpc_server_socket = -1;
int gdcu_client_socket = -1;


int get_port_from_env(const char *env_var_name, int default_port) {
    const char *port_str = getenv(env_var_name);
    if (port_str == NULL) {
        printf("%s not set. Using default port: %d\n", env_var_name, default_port);
        return default_port;
    }

    int port = atoi(port_str);
    if (port <= 0 || port > 65535) {
        printf("Invalid port number in %s: %s. Using default port: %d\n", env_var_name, port_str, default_port);
        return default_port;
    }

    return port;
}


void init_server()
{
    struct sockaddr_in serverAddr;
    char buffer[BUFFER_SIZE];

     // Create socket
    hpc_server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (hpc_server_socket < 0) 
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Server address setup
    serverAddr.sin_family = AF_INET;

//    int port = get_port_from_env("GDCU_PORT", 8080);

    serverAddr.sin_port = htons(8080);
   // serverAddr.sin_addr.s_addr = inet_addr(GDCU_SERVER_IP);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    
    if (bind(hpc_server_socket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(hpc_server_socket, 3) < 0) 
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is running, waiting for connections...\n");
}

void handle_client()
{
    printf("--------   handle_client  --------------\n");
    struct sockaddr_in clientAddr;
    char buffer[BUFFER_SIZE];
    int addrlen = sizeof(clientAddr);

    if ((gdcu_client_socket = accept(hpc_server_socket, (struct sockaddr *)&clientAddr,
                                 (socklen_t *)&addrlen)) < 0) 
    {
            perror("Accept failed");
            exit(EXIT_FAILURE);
    }

    printf("--------   gdcu socket accepted  --------------\n");

    while (running) 
    {
        // Receive data from server
        memset(buffer, 0, BUFFER_SIZE);
        printf("--------   gdcu read socket  --------------\n");
        int bytesRead = recv(gdcu_client_socket, buffer, BUFFER_SIZE, 0);

        printf("bytesRead from GDCU: %d\n", bytesRead);
        printf("Received bytes from GDCU: %s\n", buffer);
        if (bytesRead > 0) 
        {
            buffer[bytesRead] = '\0'; // Null-terminate the received string
            char *signalName = strtok(buffer, ":");
            char *signalValueStr = strtok(NULL, ":");

            if (signalName != NULL && signalValueStr != NULL)
            {
                int signalValue = atoi(signalValueStr);

                printf("Received Signal: %s = %d\n", signalName, signalValue);

                // Check the signal name and call the appropriate function
                if (strcmp(signalName, "SPD_TIH_Subscription_Status") == 0)
                {
                    Set_SPD_TIH_Subscription_Status(signalValue);
                    printf("Processed SPD_TIH_Subscription_Status: %d\n", signalValue);
                }
                else if (strcmp(signalName, "SPD_IH_EnabledByUser_Flag") == 0)
                {
                    Set_SPD_IH_EnabledByUser_Flag(signalValue);
                    printf("Processed SPD_IH_EnabledByUser_Flag: %d\n", signalValue);
                }
                else
                {
                    printf("Unknown signal name: %s\n", signalName);
                }
            }
            else
            {
                printf("Malformed signal received: %s\n", buffer);
            }

            // Call Single Pedal Drive step function
            HPC_SinglePedalDrive_step();

            printf("HPC_SPD_HE_FeatureEnable_Status : %d\n", HPC_SPD_HE_FeatureEnable_Command_Var);

            if(HPC_SPD_HE_FeatureEnable_Command_Var == HPC_SPD_FEATURE_ENABLE_CMD_T_ENABLE)
            {
                printf("SPD Feature is Enabled\n");
                printf("Send Enable command to EVCU \n");

                printf("......  EVCU SIMULATION .....\n");
                printf(" Send SPD Enabled\n");
                printf("......  EVCU SIMULATION END.....\n");

                printf("\n.. Update HPC_SPD_XH_ACTIVE_Status and HPC_SPD_HI_Status\n");
                HPC_SPD_XH_ACTIVE_Status_var = HPC_SPD_STATUS_T_ENABLED;
                HPC_SPD_HI_Status_Var = HPC_SPD_STATUS_T_ENABLED;
                
            }
            
            printf("Send HPC_SPD_HI_Status to GDCU \n");
            printf("Sending ... HPC_SPD_HI_Status : %d\n",HPC_SPD_HI_Status_Var);
            // Send response back to the gdcu client
            send(gdcu_client_socket, &HPC_SPD_HI_Status_Var, sizeof(HPC_SPD_HI_Status_Var), 0);
            
        }
        else
        {
            printf("Received bytes from GDCU: %s\n", buffer);
            running = 0;
        }

        // Sleep or use periodic timer for next step
        usleep(100000); // 100ms
    }

}

void cleanup()
{
    if(hpc_server_socket < 0)
    {
        close(hpc_server_socket);
    }
    if(gdcu_client_socket < 0)
    {
        close(gdcu_client_socket);
    }
}
