ROOT_DIR=~/repos/mr_turtle2
DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0 ${ROOT_DIR}/build/helloworld
