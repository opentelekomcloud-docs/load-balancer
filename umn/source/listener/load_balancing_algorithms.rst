Load Balancing Algorithms
=========================

Load balancers receive requests from clients and forward them to backend servers in one or more AZs. Each load balancer has at least a listener and a backend server. The load balancing algorithm you select when you add the listener determines how requests are distributed.

.. _load-balancing-algorithms-1:

Load Balancing Algorithms
-------------------------

Shared load balancers and dedicated load balancers support the following load balancing algorithms:

-  Weighted round robin: Requests are routed to different servers based on their weights, which indicate server processing performance. Backend servers with higher weights receive proportionately more requests, whereas equal-weighted servers receive the same number of requests. This algorithm is often used for short connections, such as HTTP connections.

   The following figure shows an example of how requests are distributed using the weighted round robin algorithm. Two backend servers are in the same AZ and have the same weight, and each server receives the same proportion of requests.

   | **Figure 1** Traffic distribution using the weighted round robin algorithm
   | |image1|

-  Weighted least connections: In addition to the weight assigned to each server, the number of connections processed by each backend server is also considered. Requests are routed to the server with the lowest connections-to-weight ratio. In addition to the number of connections, each server is assigned a weight based on its capacity. Requests are routed to the server with the lowest connections-to-weight ratio. This algorithm is often used for persistent connections, such as connections to a database.

   The following figure shows an example of how requests are distributed using the weighted least connections algorithm. Two backend servers are in the same AZ and have the same weight, 100 connections have been established with backend server 01, and 50 connections have been connected with backend server 02. New requests are preferentially routed to backend server 02.

   | **Figure 2** Traffic distribution using the weighted least connections algorithm
   | |image2|

-  Source IP hash: The source IP address of each request is calculated using the consistent hashing algorithm to obtain a unique hashing key, and all backend servers are numbered. The generated key is used to allocate the client to a particular server. This allows requests from different clients to be routed based on source IP addresses and ensures that a client is directed to the same server that it was using previously. This algorithm works well for TCP connections of load balancers that do not use cookies.

   The following figure shows an example of how requests are distributed using the source IP hash algorithm. Two backend servers are in the same AZ and have the same weight. If backend server 01 has processed a request from IP address A, the load balancer will route new requests from IP address A to backend server 01.

   | **Figure 3** Traffic distribution using the source IP hash algorithm
   | |image3|

Classic load balancers support the following load balancing algorithms:

-  Round robin: Requests are distributed sequentially, evenly across all servers. This algorithm is often used for short connections, such as HTTP connections.
-  Least connections: Requests are preferentially routed to backend servers with the minimum number of active connections. This algorithm is often used for persistent connections, such as connections to a database.
-  Source IP hash: The source IP address of each request is calculated using the consistent hashing algorithm to obtain a unique hashing key, and all backend servers are numbered. The generated key is used to allocate the client to a particular server. This allows requests from different clients to be routed based on source IP addresses and ensures that a client is directed to the same server that it was using previously. This algorithm works well for TCP connections of load balancers that do not use cookies.

|image4|

Classic load balancers can no longer be created on the management console. Use shared load balancers or dedicated load balancers instead.

Changing the Load Balancing Algorithm
-------------------------------------

#. Log in to the management console.

#. In the upper left corner of the page, click |image5| and select the desired region and project.

#. Hover on |image6| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. Locate the load balancer and click its name.

#. Click **Backend Server Groups** and click |image7| on the right of the backend server group name.

#. Select a load balancing algorithm.\ |image8|

   The modification will take effect immediately. The load balancer will establish new connections with the clients, and request routing over established connections will not be affected.

#. Click **OK**.

.. |image1| image:: /images/en-us_image_0000001160373426.png

.. |image2| image:: /images/en-us_image_0000001160533378.png

.. |image3| image:: /images/en-us_image_0000001205974859.png

.. |image4| image:: /images/note_3.0-en-us.png
.. |image5| image:: /images/en-us_image_0241356603.png

.. |image6| image:: /images/en-us_image_0000001120894978.png

.. |image7| image:: /images/en-us_image_0000001205813423.png

.. |image8| image:: /images/note_3.0-en-us.png
