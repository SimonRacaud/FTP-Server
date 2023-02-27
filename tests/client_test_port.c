#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <stdbool.h>
#include <termios.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include "socket.h"


int socket_server_create(socket_t *sock, uint port, uint max_client);

void get(int socket_fd)
{
    char buf[4096];
    int ret_read = read(socket_fd, buf, 4096);
    buf[ret_read] = '\0';
    printf("%s\n", buf);
}

void sendd(const char *cmd, int fd)
{
    write(fd, cmd, strlen(cmd));
    sleep(1);
}

int main(int ac, char **av)
{
    char ip[] = "127.0.0.1";
    struct sockaddr_in my_serv = {0};
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    int ret;

    if (socket_fd <= 0)
        return 84;
    my_serv.sin_family = AF_INET;
    my_serv.sin_port = htons(21);
    ret = inet_pton(AF_INET, ip, &my_serv.sin_addr);
    if (ret <= 0)
        return 84;
    ret = connect(socket_fd, (struct sockaddr *)&my_serv, sizeof(my_serv));
    if (ret < 0)
        return 84;
    usleep(500000);
    // --- LOGIN ----
    write(socket_fd, "USER Anonymous\r\npass\r\n", 22);
    usleep(500000);
    // ------------------
    sendd("port (127,0,0,1,255,56)\r\n", socket_fd);

    sleep(1);
    socket_t serv;
    socket_server_create(&serv, 65336, 1);
    sendd("list\r\n", socket_fd);
    socket_t client;
    socket_server_connect(&client, serv.fd);
    sleep(1);
    char buff[1024];
    int retread = read(client.fd, buff, 1023);
    buff[retread] = '\0';
    printf("result: %s\n", buff);
    // --------------
    write(socket_fd, "quit\r\n", 6);
    sleep(1);
    return 0;
}
