# Build

    make

# Example

    $ LD_PRELOAD=$PWD/carrier.so curl -H 'Host: ifconfig.co' 127.0.0.1
    socket(PF_INET6, SOCK_DGRAM, default) -> fd 4 AF_INET6{0.0.0.0:0}
    socket(PF_INET, SOCK_STREAM, tcp) -> fd 4 AF_INET{0.0.0.0:0}
    Forwarding to AF_INET{188.113.88.193:80}
    connect(fd 4 AF_INET{192.168.1.88:41914}, AF_INET{127.0.0.1:80}) -> Operation now in progress
