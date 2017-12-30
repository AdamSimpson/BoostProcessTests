# Compile with no optimizations
```
$ g++ -O0 -std=c++14 main.cpp -L/usr/lib -lboost_system -lboost_coroutine -pthread
```
# Running works as expected
```
$ ./a.out
XDG_MENU_PREFIX=gnome-
LANG=en_US.UTF-8
GDM_LANG=en_US.UTF-8
DISPLAY=:1
CL_JDK=/usr /usr/bin/clion
COLORTERM=truecolor
USERNAME=atj
MOZ_PLUGIN_PATH=/usr/lib/mozilla/plugins
XDG_VTNR=2
SSH_AUTH_SOCK=/run/user/1000/ssh-agent.socket
XDG_SESSION_ID=c3
USER=atj
DESKTOP_SESSION=gnome-xorg
PWD=/home/atj/CLionProjects/BoostProcessTests
HOME=/home/atj
JOURNAL_STREAM=9:36389
XDG_SESSION_TYPE=x11
...
```

# Compile with optimization
```
$ g++ -O0 -std=c++14 main.cpp -L/usr/lib -lboost_system -lboost_coroutine -pthread
```
# async_read_some returns 0 bytes read every time
```
$ ./a.out
```