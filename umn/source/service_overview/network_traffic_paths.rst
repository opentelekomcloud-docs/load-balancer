Network Traffic Paths
=====================

Load balancers communicate with backend servers over a private network.

-  If backend servers process only requests routed from load balancers, there is no need to assign EIPs or create NAT gateways.
-  If backend servers need to provide Internet-accessible services or access the Internet, you must assign EIPs or create NAT gateways.

Inbound Network Traffic Paths
-----------------------------

| The listeners' configurations determine how load balancers distribute incoming traffic.\ **Figure 1** Inbound network traffic
| |image1|
  When a listener uses TCP or UDP to receive incoming traffic:

-  Incoming traffic is routed only through the LVS cluster.
-  The LVS cluster directly routes incoming traffic to backend servers using the load balancing algorithm you select when you add the listener.

When a listener uses HTTP or HTTPS to receive incoming traffic:

-  Incoming traffic is routed first to the LVS cluster, then to the Nginx cluster, and finally across backend servers.
-  For HTTPS traffic, the Nginx cluster validates certificates and decrypts data packets before distributing the traffic across backend servers using HTTP.

Outbound Network Traffic Paths
------------------------------

| The outbound traffic is routed back the same way the traffic came in.\ **Figure 2** Outbound network traffic
| |image2|

-  Because the load balancer receives and responds to requests over the Internet, traffic transmission depends on the bandwidth, which is not limited by ELB. The load balancer communicates with backend servers over a private network.
-  If you have a NAT gateway, it receives and responds to incoming traffic. The NAT gateway has an EIP bound, through which backend servers can access the Internet and provide services accessible from the Internet. Although there is a restriction on the connections that can be processed by a NAT gateway, traffic transmission depends on the bandwidth
-  If each backend server has an EIP bound, they receive and respond to incoming traffic directly. Traffic transmission depends on the bandwidth.

.. |image1| image:: /images/en-us_image_0000001181376003.png
   :class: vsd

.. |image2| image:: /images/en-us_image_0000001135576398.png
   :class: vsd

