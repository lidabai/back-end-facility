#ifndef __HTTP_SERVER_H__
#define __HTTP_SERVER_H__

#include "HttpClient.h"
#include "net/SocketServer.h"
#include "misc/NonCopyable.h"

class HttpServer: public noncopyable
{
    public:

        HttpServer();
        ~HttpServer();

        void SetStop();
        void SetListenSock(int fd);
        void RunServer();

    private:

        void RunPoll();
        void DestroyServer();
        void PollHandler(SocketEvent evt);

        bool stop_;
        SocketServer tcpServer_;
        HttpClient** conn_;
};

#endif

