#include "gdcu.h"

std::atomic<bool> stopRetry(false);

GDCU::GDCU()
{

}

void handleInterrupt(int signal)
{
    if (signal == SIGINT)
    {
        stopRetry = true;
        std::cout << "Stopping connection attempts...\n";
    }
}

/*int getPortFromEnv() {
    const char* portStr = std::getenv("GDCU_PORT");
    if (!portStr) {
        std::cerr << "GDCU_PORT not set. Using default port 8080.\n";
        return 8080; // fallback port
    }

    try {
        return std::stoi(portStr);
    } catch (const std::exception& e) {
        std::cerr << "Invalid GDCU_PORT value: " << portStr << "\n";
        return 8080; // fallback port
    }
}*/

GDCU::~GDCU()
{
    if (client_sock != -1) 
        close(client_sock);
    if (server_sock != -1) 
       close(server_sock);
    std::cout << "Server closed.\n";
}

bool GDCU::init_server()
{
    socklen_t addrLen = sizeof(serverAddr);
    char buffer[1024];

    const char* hostname = "hpcserver";
    struct hostent* host = gethostbyname(hostname);

    if (!host || host->h_addrtype != AF_INET) {
        std::cerr << "Hostname resolution failed for: " << hostname << ". Trying localhost...\n";
        hostname = "localhost";
        host = gethostbyname(hostname);

        if (!host || host->h_addrtype != AF_INET) {
            std::cerr << "Fallback to localhost also failed. Exiting.\n";
            return false;
        }
    }

    // Convert IP for logging
    char ip[INET_ADDRSTRLEN] = {0};
    if (!inet_ntop(AF_INET, host->h_addr_list[0], ip, sizeof(ip))) {
        perror("inet_ntop failed");
        return false;
    }
    std::cout << "Resolved " << hostname << " to IP: " << ip << std::endl;

    // Create socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Failed to create socket");
        return false;
    }

    // Setup server address
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    memcpy(&serverAddr.sin_addr, host->h_addr_list[0], sizeof(struct in_addr));

    // Connection attempt loop
    while (!stopRetry)
    {
        if (connect(server_sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0)
        {
            if (errno == ECONNREFUSED) {
                std::cout << "Server not available. Retrying in 2 seconds...\n";
            } else {
                perror("Connection failed due to another error");
                break;
            }
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
        else
        {
            std::cout << "Connected to the HPC server.\n";
            return true;
        }
    }

    std::cout << "Connection attempts stopped by user.\n";
    close(server_sock);
    server_sock = -1;
    return false;
}

/*
bool GDCU::init_server()
{
    socklen_t addrLen = sizeof(serverAddr);
    char buffer[1024];

    const char* hostname = "server_service";
    struct hostent* host = gethostbyname(hostname);

    if (!host || host->h_addrtype != AF_INET) {
        std::cerr << "Hostname resolution failed for: " << hostname << std::endl;
        return false;
    }

    // Convert the first IP address to human-readable form (for logging only)
    char ip[INET_ADDRSTRLEN] = {0};
    if (!inet_ntop(AF_INET, host->h_addr_list[0], ip, sizeof(ip))) {
        perror("inet_ntop failed");
        return false;
    }
    std::cout << "Resolved " << hostname << " to IP: " << ip << std::endl;

    // Create a socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Failed to create socket");
        return false;
    }

    // Set up the server address
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    memcpy(&serverAddr.sin_addr, host->h_addr_list[0], sizeof(struct in_addr));

    // Attempt connection with retries
    while (!stopRetry)
    {
        if (connect(server_sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0)
        {
            if (errno == ECONNREFUSED) {
                std::cout << "Server not available. Retrying in 2 seconds...\n";
            } else {
                perror("Connection failed due to another error");
                break;
            }
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
        else
        {
            std::cout << "Connected to the HPC server.\n";
            return true;
        }
    }

    std::cout << "Connection attempts stopped by user.\n";
    close(server_sock);
    server_sock = -1;
    return false;
}
*/

/*
bool GDCU::init_server()
{
    socklen_t addrLen = sizeof(serverAddr);
    char buffer[1024];
    
//  const char* hostname = std::getenv("SERVER_HOST");
//   if (!hostname) hostname = "localhost";

    const char* hostname = "server_service";

    struct hostent* host = gethostbyname(hostname);
    
    if (!host) {
    std::cerr << "Hostname resolution failed for: " << hostname << std::endl;
    return 1;
    }

    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, host->h_addr, ip, sizeof(ip));
    std::cout << "Resolved " << hostname << " to " << ip << std::endl;
    // create a server soclket
    server_sock = socket(AF_INET,SOCK_STREAM,0);
    if(server_sock<0)
    {
        perror("Failed to create socket");
        return false;
    }

    serverAddr.sin_family = AF_INET;
//   int port  getPortFromEnv();
    serverAddr.sin_port = htons(8080);
    memcpy(&serverAddr.sin_addr, host->h_addr, host->h_length);

    // Convert address from text to binary
   /* if (inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr) <= 0) {
        perror("Invalid address");
        return false;
    }*//*

    while (!stopRetry)
    {
        if (connect(server_sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
        {
            if (errno == ECONNREFUSED)
            {
                std::cout << "Server not available. Retrying in 2 seconds...\n";
            }
            else
            {
                perror("Connection failed due to another error");
                break;
            }
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
        else
        {
            std::cout << "Connected to the HPC server.\n";
            return true;
        }
    }

    std::cout << "Connection attempts stopped by user.\n";
    close(server_sock);
    server_sock = -1;
    return false;
}
*/
void GDCU::handle_client_connection()
{
    bool running = true;
    while(running)
    {
        Signal signal;
        char buffer[1024] = {0};
        int choice;
        std::cout << "Select the signal to send:\n";
        std::cout << "1: SPD_TIH_Subscription_Status\n";
        std::cout << "2: SPD_IH_EnabledByUser_Flag\n";
        std::cout << "Enter your choice (1 or 2): ";
        std::cin >> choice;

        if (choice == 1) 
        {
            signal.signalName = "SPD_TIH_Subscription_Status";
            std::cout << "Enter value for SPD_TIH_Subscription_Status (1 for Active, 0 for Inactive): ";
        } 
        else if (choice == 2) 
        {
            signal.signalName = "SPD_IH_EnabledByUser_Flag";
            std::cout << "Enter value for SPD_IH_EnabledByUser_Flag (1 for Enabled, 0 for Disabled): ";
        } 
        else 
        {
            std::cout << "Invalid choice. Try again.\n";
            continue;
        }

        std::cin >> signal.signalValue;

        // Format the data as "signalName:signalValue"
        std::string formattedSignal = signal.signalName + ":" + std::to_string(signal.signalValue);

        // Send the signal to the client
        if (send(server_sock, formattedSignal.c_str(), formattedSignal.size() + 1, 0) <= 0)
        {
            perror("Failed to send signal");
            break;
        }

        std::cout << "Sent signal to HPC: " << signal.signalName
                << " = " << signal.signalValue << "\n";

        // Wait for a response from the client
        int bytesRead = recv(server_sock, buffer, 1024,0);
        std::cout<<"recieved bytes: "<<bytesRead<<std::endl;
        if(bytesRead>0)
        {
            int HPC_SPD_HI_Status;
            memcpy(&HPC_SPD_HI_Status, buffer, sizeof(HPC_SPD_HI_Status));
            printf("Recieved   HPC_SPD_HI_Status : %d\n",HPC_SPD_HI_Status);
        }
         else if (bytesRead == 0)
        {
            std::cout << "HPC closed the connection.\n";
            break;
        }
        else
        {
            perror("Failed to read response");
            break;
        }

        // Ask if the user wants to continue
        std::cout << "Do you want to continue? (1 for Yes, 0 for No): ";
        std::cin >> running;
    }
}
