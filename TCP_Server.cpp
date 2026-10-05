  GNU nano 7.2                                                               tcp.cpp

        //CLOSE LISTENING SOCKET
        close(listening);
        memset(host,0,NI_MAXHOST);
        memset(svc,0,NI_MAXSERV);

        int result=getnameinfo((sockaddr*)&client,sizeof(client),host,NI_MAXHOST,svc,NI_MAXSERV,0);

        if(result==0)
        cout<<host<<" connected on"<<svc<<endl;
        else
        {
        inet_ntop(AF_INET,&client.sin_addr,host,NI_MAXHOST);
        cout<<host<<"connected on"<<ntohs(client.sin_port)<<endl;
        }

        //WHILE RECEVING DISPLAY MESSAGE
        char bf[4096];
        while(true)
        {
        memset(bf,0,4096);
        int bytesRecv=recv(clientSocket,bf,4096,0);
        if(bytesRecv==-1)
        {
        cerr<<"Connection issue"<<endl;
        return -5;
        }

        if(bytesRecv==0)
        {
        cout<<"The client disconnected"<<endl;
        break;
        }
        cout<<"RECEIVED: "<<string(bf,0,bytesRecv)<<endl;
        send(clientSocket,bf, bytesRecv,0);
        }
        close(clientSocket);
        return 0;
}
