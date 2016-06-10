#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

//fuck you

int main(int argc, char *argv[])
{
    int sockfd;
    int len;
    struct sockaddr_in address;
    int result;
    char ch = 'A';

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(4001);
    len = sizeof(address);
    result = connect(sockfd, (struct sockaddr *)&address, len);
    printf("%s--%d, result:%d\n", __FILE__, __LINE__, result );

    if (result == -1)
    {
        perror("oops: client1");
        exit(1);
    }
    int iRet = write(sockfd, &ch, 1);
    printf("%s--%d, iRet:%d, ch:%c ", __FILE__, __LINE__, iRet, ch);
    iRet = read(sockfd, &ch, 1);
    printf("%s--%d, iRet:%d, ch:%c ", __FILE__, __LINE__, iRet, ch);
    printf("char from server = %c\n", ch);
    close(sockfd);
    exit(0);
}
