#define _GNU_SOURCE
#define	_SYS_SOCKET_H	1
#include <dlfcn.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <bits/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/un.h>

#define PFBUFSIZE 8
char *pftostr(int namespace) {
    static char defpf[PFBUFSIZE];
    switch (namespace) {
	case PF_UNSPEC:		return "PF_UNSPEC";
	case PF_LOCAL:		return "PF_LOCAL";
	case PF_INET:		return "PF_INET";
	case PF_AX25:		return "PF_AX25";
	case PF_IPX:		return "PF_IPX";
	case PF_APPLETALK:	return "PF_APPLETALK";
	case PF_NETROM:		return "PF_NETROM";
	case PF_BRIDGE:		return "PF_BRIDGE";
	case PF_ATMPVC:		return "PF_ATMPVC";
	case PF_X25:		return "PF_X25";
	case PF_INET6:		return "PF_INET6";
	case PF_ROSE:		return "PF_ROSE";
	case PF_DECnet:		return "PF_DECnet";
	case PF_NETBEUI:	return "PF_NETBEUI";
	case PF_SECURITY:	return "PF_SECURITY";
	case PF_KEY:		return "PF_KEY";
	case PF_NETLINK:	return "PF_NETLINK";
	case PF_PACKET:		return "PF_PACKET";
	case PF_ASH:		return "PF_ASH";
	case PF_ECONET:		return "PF_ECONET";
	case PF_ATMSVC:		return "PF_ATMSVC";
	case PF_RDS:		return "PF_RDS";
	case PF_SNA:		return "PF_SNA";
	case PF_IRDA:		return "PF_IRDA";
	case PF_PPPOX:		return "PF_PPPOX";
	case PF_WANPIPE:	return "PF_WANPIPE";
	case PF_LLC:		return "PF_LLC";
	case PF_IB:		return "PF_IB";
	case PF_MPLS:		return "PF_MPLS";
	case PF_CAN:		return "PF_CAN";
	case PF_TIPC:		return "PF_TIPC";
	case PF_BLUETOOTH:	return "PF_BLUETOOTH";
	case PF_IUCV:		return "PF_IUCV";
	case PF_RXRPC:		return "PF_RXRPC";
	case PF_ISDN:		return "PF_ISDN";
	case PF_PHONET:		return "PF_PHONET";
	case PF_IEEE802154:	return "PF_IEEE802154";
	case PF_CAIF:		return "PF_CAIF";
	case PF_ALG:		return "PF_ALG";
	case PF_NFC:		return "PF_NFC";
	case PF_VSOCK:		return "PF_VSOCK";
	case PF_MAX:		return "PF_MAX";
    }
    snprintf(defpf, PFBUFSIZE, "PF %d", namespace);
    return defpf;
}

char *aftostr(int namespace) {
    static char defns[PFBUFSIZE];
    switch (namespace) {
	case AF_UNSPEC:		return "AF_UNSPEC";
	case AF_LOCAL:		return "AF_LOCAL";
	case AF_INET:		return "AF_INET";
	case AF_AX25:		return "AF_AX25";
	case AF_IPX:		return "AF_IPX";
	case AF_APPLETALK:	return "AF_APPLETALK";
	case AF_NETROM:		return "AF_NETROM";
	case AF_BRIDGE:		return "AF_BRIDGE";
	case AF_ATMPVC:		return "AF_ATMPVC";
	case AF_X25:		return "AF_X25";
	case AF_INET6:		return "AF_INET6";
	case AF_ROSE:		return "AF_ROSE";
	case AF_DECnet:		return "AF_DECnet";
	case AF_NETBEUI:	return "AF_NETBEUI";
	case AF_SECURITY:	return "AF_SECURITY";
	case AF_KEY:		return "AF_KEY";
	case AF_NETLINK:	return "AF_NETLINK";
	case AF_PACKET:		return "AF_PACKET";
	case AF_ASH:		return "AF_ASH";
	case AF_ECONET:		return "AF_ECONET";
	case AF_ATMSVC:		return "AF_ATMSVC";
	case AF_RDS:		return "AF_RDS";
	case AF_SNA:		return "AF_SNA";
	case AF_IRDA:		return "AF_IRDA";
	case AF_PPPOX:		return "AF_PPPOX";
	case AF_WANPIPE:	return "AF_WANPIPE";
	case AF_LLC:		return "AF_LLC";
	case AF_IB:		return "AF_IB";
	case AF_MPLS:		return "AF_MPLS";
	case AF_CAN:		return "AF_CAN";
	case AF_TIPC:		return "AF_TIPC";
	case AF_BLUETOOTH:	return "AF_BLUETOOTH";
	case AF_IUCV:		return "AF_IUCV";
	case AF_RXRPC:		return "AF_RXRPC";
	case AF_ISDN:		return "AF_ISDN";
	case AF_PHONET:		return "AF_PHONET";
	case AF_IEEE802154:	return "AF_IEEE802154";
	case AF_CAIF:		return "AF_CAIF";
	case AF_ALG:		return "AF_ALG";
	case AF_NFC:		return "AF_NFC";
	case AF_VSOCK:		return "AF_VSOCK";
	case AF_MAX:		return "AF_MAX";
    }
    snprintf(defns, PFBUFSIZE, "AF %d", namespace);
    return defns;
}

#define ADDRBUFSIZE 128
char *addrtostr(struct sockaddr *addr, socklen_t length) {
    static char defaddr[ADDRBUFSIZE];
    switch (addr->sa_family) {
	case AF_INET:
	    {
		struct sockaddr_in *sinaddr = (struct sockaddr_in *)addr;
		strcpy(defaddr, "AF_INET{");
		inet_ntop(AF_INET, &(sinaddr->sin_addr), defaddr + 8, ADDRBUFSIZE - 8);
		size_t sinaddrlen = strlen(defaddr);
		snprintf(defaddr + sinaddrlen, ADDRBUFSIZE - sinaddrlen, ":%d}", ntohs(sinaddr->sin_port));
	    }
	    break;
	case AF_INET6:
	    {
		struct sockaddr_in6 *sin6addr = (struct sockaddr_in6 *)addr;
		strcpy(defaddr, "AF_INET6{");
		inet_ntop(AF_INET, &(sin6addr->sin6_addr), defaddr + 9, ADDRBUFSIZE - 9);
		size_t sin6addrlen = strlen(defaddr);
		snprintf(defaddr + sin6addrlen, ADDRBUFSIZE - sin6addrlen, ":%d}", ntohs(sin6addr->sin6_port));
	    }
	    break;
	case AF_LOCAL:
	    {
		struct sockaddr_un *sunaddr = (struct sockaddr_un *)addr;
		snprintf(defaddr, ADDRBUFSIZE, "AF_LOCAL{%s}", sunaddr->sun_path);
	    }
	    break;
	default:
	    snprintf(defaddr, ADDRBUFSIZE, "%s<%d>", aftostr(addr->sa_family), length);
    }
    return defaddr;
}

int _styletostr(char *str, size_t n, int style) {
    switch (style) {
	case SOCK_STREAM:	strncpy(str, "SOCK_STREAM", n);		return n - 11;
	case SOCK_DGRAM:	strncpy(str, "SOCK_DGRAM", n);		return n - 10;
	case SOCK_RAW:		strncpy(str, "SOCK_RAW", n);		return n - 8;
	case SOCK_RDM:		strncpy(str, "SOCK_RDM", n);		return n - 8;
	case SOCK_SEQPACKET:	strncpy(str, "SOCK_SEQPACKET", n);	return n - 14;
	case SOCK_DCCP:		strncpy(str, "SOCK_DCCP", n);		return n - 9;
	case SOCK_PACKET:	strncpy(str, "SOCK_PACKET", n);		return n - 11;
    }
    if (style & SOCK_CLOEXEC) {
	strncpy(str, "SOCK_CLOEXEC|", n);
	return _styletostr(str + 13, n - 13, style & ~SOCK_CLOEXEC);
    }
    if (style & SOCK_NONBLOCK) {
	strncpy(str, "SOCK_NONBLOCK|", n);
	return _styletostr(str + 14, n - 14, style & ~SOCK_NONBLOCK);
    }
    snprintf(str, n, "SOCK %d", style);
    return n - strlen(str);
}

#define STYLEBUFSIZE 64
char *styletostr(int style) {
    static char defstyle[STYLEBUFSIZE];
    if (_styletostr(defstyle, STYLEBUFSIZE, style) < 0) {
	strncpy(defstyle + STYLEBUFSIZE - 1, "", 1);
    }
    return defstyle;
}

#define PROTOBUFSIZE 12
char *prototostr(protocol) {
    static char defproto[PROTOBUFSIZE];
    if (protocol) {
	struct protoent *p = getprotobynumber(protocol);
	if (p) return p->p_name;
	snprintf(defproto, PROTOBUFSIZE, "proto %d", protocol);
	return defproto;
    }
    return "default";
}

typedef int (*orig_socket_f_type)(int namespace, int style, int protocol);

int socket(int namespace, int style, int protocol)
{
    orig_socket_f_type orig_socket;
    orig_socket = (orig_socket_f_type)dlsym(RTLD_NEXT,"socket");
    int sock = orig_socket(namespace, style, protocol);
    static char rtnbuf[8];
    char *rtnstr = rtnbuf;
    if (sock < 0) {
	rtnstr = strerror(errno);
    } else {
	snprintf(rtnbuf, 8, "fd %d", sock);
    }
    printf("socket(%s, %s, %s) -> %s\n", pftostr(namespace), styletostr(style), prototostr(protocol), rtnstr);
    return sock;
}

char *howtostr(int how) {
    switch (how) {
	case 0:		return "SHUT_RD";
	case 1:		return "SHUT_WR";
	case 2:		return "SHUT_RDWR";
	default:	return "SHUT_UNKNOWN";
    }
}

typedef int (*orig_connect_f_type)(int socket, struct sockaddr *addr, socklen_t length);

int connect(int socket, struct sockaddr *addr, socklen_t length)
{
    orig_connect_f_type orig_connect;
    orig_connect = (orig_connect_f_type)dlsym(RTLD_NEXT,"connect");
    int err = orig_connect(socket, addr, length);
    static char *rtnbuf = "Success";
    char *rtnstr = rtnbuf;
    if (err < 0) {
	rtnstr = strerror(errno);
    }
    printf("connect(fd %d, %s) -> %s\n", socket, addrtostr(addr, length), rtnstr);
    return err;
}

typedef int (*orig_shutdown_f_type)(int socket, int how);

int shutdown(int socket, int how)
{
    orig_shutdown_f_type orig_shutdown;
    orig_shutdown = (orig_shutdown_f_type)dlsym(RTLD_NEXT,"shutdown");
    int err = orig_shutdown(socket, how);
    static char *rtnbuf = "Success";
    char *rtnstr = rtnbuf;
    if (err < 0) {
	rtnstr = strerror(errno);
    }
    printf("shutdown(fd %d, %s) -> %s\n", socket, howtostr(how), rtnstr);
    return err;
}

typedef int (*orig_socketpair_f_type)(int namespace, int style, int protocol, int filedes[2]);

int socketpair(int namespace, int style, int protocol, int filedes[2])
{
    orig_socketpair_f_type orig_socketpair;
    orig_socketpair = (orig_socketpair_f_type)dlsym(RTLD_NEXT,"socketpair");
    int err = orig_socketpair(namespace, style, protocol, filedes);
    static char *rtnbuf = "Success";
    char *rtnstr = rtnbuf;
    if (err < 0) {
	rtnstr = strerror(errno);
    }
    printf("socketpair(%s, %s, %s, ...) -> %s\n", pftostr(namespace), styletostr(style), prototostr(protocol), rtnstr);
    return err;
}
