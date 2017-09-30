# Build

    make

# Example

    $ LD_PRELOAD=$PWD/carrier.so curl ifconfig.co
    socket(PF_INET6, SOCK_DGRAM, default) -> fd 4 AF_INET6{0.0.0.0:0}
    socket(PF_INET, SOCK_NONBLOCK|SOCK_DGRAM, default) -> fd 4 AF_INET{0.0.0.0:0}
    connect(fd 4 AF_INET{192.168.1.88:55614}, AF_INET{192.168.1.1:53}) -> Success
    socket(PF_INET, SOCK_STREAM, tcp) -> fd 4 AF_INET{0.0.0.0:0}
    connect(fd 4 AF_INET{192.168.1.88:41870}, AF_INET{188.113.88.193:80}) -> Operation now in progress

