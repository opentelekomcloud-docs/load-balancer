Preparations for Creating a Load Balancer
=========================================

Before creating a load balancer, you must plan its region, network, protocol, and backend servers.

Region
------

When you select a region, pay attention to the following:

-  The region must be close to your users' location to reduce network latency and improve the download speed.
-  The region must be the same as that of backend servers. Currently, ELB cannot be deployed across regions.

Specifications
--------------

Dedicated load balancers provide a broad range of specifications to meet different requirements. Specifications for network load balancing are suitable for TCP or UDP requests, while specifications for application load balancing are broadly used to handle HTTP or HTTPS requests. Select appropriate specifications based on your traffic volume and service requirements. The following are some principles for you to select the specifications:

-  For TCP or UDP load balancing, pay attention to the number of concurrent persistent connections, and consider Maximum Connections as a key metric. Estimate the maximum number of concurrent connections that a load balancer can handle in the actual service scenario and select the corresponding specification.
-  For HTTP or HTTPS load balancers, focus more on queries per second (QPS), which determines the service throughput of an application system. Estimate the QPS that a load balancer can handle in the actual service scenario and select the corresponding specification.
-  Use the monitoring data from Cloud Eye to analyze the peak traffic, trend and regularity of the traffic to select the specifications more accurately.

Protocol
--------

ELB provides load balancing at both Layer 4 and Layer 7.

-  If you choose TCP or UDP, the load balancer routes requests directly to backend servers. In this process, the destination IP address in the packets is changed to the IP address of the backend server, and the source IP address to the private IP address of the load balancer. A connection is established after a three-way handshake between the client and the backend server, and the load balancer only forwards the data.\ **Figure 1** Layer-4 load balancing
   |image1|
-  Load balancing at Layer 7 is also called "content exchange". After the load balancer receives a request, it works as a proxy of backend servers to establish a connection (three-way handshake) with the client and then determines to which backend server the request is to be routed based on the fields in the HTTP/HTTPS request header and the load balancing algorithm you selected when you add the listener.\ **Figure 2** Layer-7 load balancing
   |image2|

Backend Servers
---------------

Before you use ELB, you need to create cloud servers, deploy required applications on them, and add the cloud servers to one or more backend server groups. When you create ECSs or BMSs, note the following:

-  Cloud servers must be in the same region as the load balancer.
-  Cloud servers that run the same OS are recommended so that you can manage them more easily.

.. |image1| image:: /images/en-us_image_0238395032.png

.. |image2| image:: /images/en-us_image_0238395033.png

