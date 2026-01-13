#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>

#define PORT 4444
#define BUFFER_SIZE 1024
#define MAX_FRUITS 5

typedef struct {
    char name[50];
    int quantity;
    char last_sold[100];
} Fruit;

Fruit inventory[MAX_FRUITS] = {
    {"apple", 10, "Never"},
    {"banana", 8, "Never"},
    {"orange", 15, "Never"},
    {"mango", 5, "Never"},
    {"grape", 20, "Never"}
};

void update_timestamp(char *timestamp) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(timestamp, 100, "%Y-%m-%d %H:%M:%S", t);
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';

        char fruit_name[50];
        int quantity_requested;
        sscanf(buffer, "%s %d", fruit_name, &quantity_requested);

        int found = 0;
        for (int i = 0; i < MAX_FRUITS; i++) {
            if (strcmp(inventory[i].name, fruit_name) == 0) {
                found = 1;
                if (inventory[i].quantity >= quantity_requested) {
                    inventory[i].quantity -= quantity_requested;
                    update_timestamp(inventory[i].last_sold);
                    snprintf(buffer, BUFFER_SIZE,
                        "Purchase successful!\nRemaining: %d\nLast sold: %s\n",
                        inventory[i].quantity, inventory[i].last_sold);
                } else {
                    snprintf(buffer, BUFFER_SIZE,
                        "Warning: Only %d %s(s) available. Cannot fulfill request.\n",
                        inventory[i].quantity, inventory[i].name);
                }
                break;
            }
        }

        if (!found) {
            snprintf(buffer, BUFFER_SIZE, "Fruit not found in inventory.\n");
        }

        send(client_socket, buffer, strlen(buffer), 0);
        memset(buffer, 0, BUFFER_SIZE);
    }

    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_socket, 5);
    printf("Fruit server is running...\n");

    while (1) {
        addr_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size);
        printf("Client connected.\n");

        if (fork() == 0) {
            close(server_socket);
            handle_client(client_socket);
            exit(0);
        } else {
            close(client_socket);
        }
    }

    return 0;
}
