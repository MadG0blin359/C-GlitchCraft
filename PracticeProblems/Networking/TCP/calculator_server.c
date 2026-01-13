#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <arpa/inet.h>

#define PORT 4444
#define BUFFER_SIZE 1024

double evaluate_expression(const char *expr) {
    double a, b;
    char op;
    if (sscanf(expr, "%lf %c %lf", &a, &op, &b) != 3) return NAN;

    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : NAN;
        case '^': return pow(a, b);
        default: return NAN;
    }
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';

        double result = evaluate_expression(buffer);
        if (isnan(result)) {
            snprintf(buffer, BUFFER_SIZE, "Invalid expression or divide by zero.\n");
        } else {
            snprintf(buffer, BUFFER_SIZE, "Result: %.2lf\n", result);
        }

        send(client_socket, buffer, strlen(buffer), 0);
        memset(buffer, 0, BUFFER_SIZE);
    }

    close(client_socket);
    exit(0);
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
    printf("Calculator server is running...\n");

    while (1) {
        addr_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size);
        printf("Client connected.\n");

        if (fork() == 0) {
            close(server_socket);
            handle_client(client_socket);
        } else {
            close(client_socket);
        }
    }

    return 0;
}
