What Do I Do If a Load Balancer Fails the Stress Test?
======================================================

#. Check the load of backend servers. If their CPU usage reaches 100%, applications may have performance bottlenecks.
#. Check the incoming traffic. If the incoming traffic exceeds the maximum bandwidth set for the EIP, a large number of packets will be lost and requests will not be responded to, thereby affecting the load balancer's performance.
#. Check the number of short connections in the **time_wait** state on the clients. A possible cause is that there are insufficient client ports.
#. The listening queue backlog of the backend servers is full. As a result, the backend server does not respond to SYN ACK packets, and the client times out. You can increase the upper limit of the backlog by adjusting the **net.core.somaxconn** parameter.
