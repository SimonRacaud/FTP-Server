# FTP-Server
FTP Server - Linux TCP Socket

The server implement the protocol located in the doc folder. [Link to the RFC](/doc/EPITECH-MyFTP-Protocol-(RFC959-Extract).txt)

The server is able to handle several clients at the same time by using select for command management and fork for data transfer.

```
∼/B-NWP-400> ./myftp –help
USAGE: ./myftp port path
  port is the port number on which the server socket listens
  path is the path to the home directory for the Anonymous user
```

# Usage
`$> make && ./myftp -h`

# Short example

```
$> netcat 127.0.0.1 8081
220 Service ready for new user.
USER anonymous
331 Please specify the password.
pass anonymous
230 Login successful.
PWD
257 /media/work/1_ARCHIVES/TEK2/B-NWP-400-REN-4-1-myftp-simon.racaud/stats
PASV
227 Entering Passive Mode (0,0,0,0,164,105).
```

# Academic

Mark: 19
Grade: A



