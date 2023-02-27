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
    sleep(1);
    printf("it's write 1\n");
    write(socket_fd, "USER Ano", 8);
    sleep(1);
    printf("it's write 2\n");
    write(socket_fd, "nymous\r\nquit\n", 13);
    
    
    char buf[4096];
    int ret_read = read(socket_fd, buf, 4096);
    buf[ret_read] = '\0';
    printf("%s\n", buf);
    sleep(1);
    //write(socket_fd, "QUIT\r\n", 6);
    sleep(1);
    return 0;
}
