:original_name: elb_faq_0052.html

.. _elb_faq_0052:

What Do I Do If a Load Balancer Fails a Stress Test?
====================================================

#. Check the load of backend servers. If their vCPU usage reaches 100%, applications may have performance bottlenecks.
#. Check the incoming traffic. If burst traffic exceeds the bandwidth set for the EIP, a large number of packets will be lost and requests will not be responded to, thereby affecting the load balancer's performance.

   .. note::

      If burst traffic exceeds the available bandwidth, it does not mean that the bandwidth is fully used. In this case, you need perform further operations to locate the fault or increase the bandwidth.

#. Check the number of short connections in the **time_wait** state on the clients. One possible cause is that there are insufficient client ports.
#. The listening queue backlog of the backend servers may be full. If this happens, the backend server will not respond to SYN ACK packets, and the client will time out. You can increase the maximum allowed of the backlog by adjusting the **net.core.somaxconn** parameter.
