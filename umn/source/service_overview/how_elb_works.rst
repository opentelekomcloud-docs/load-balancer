:original_name: elb_pro_0003.html

.. _elb_pro_0003:

How ELB Works
=============


.. figure:: /_static/images/en-us_image_0000001253004159.png
   :alt: **Figure 1** How ELB works

   **Figure 1** How ELB works

The following describes how ELB works:

#. A client sends a request to your application.
#. The listeners added to your load balancer use the protocols and ports you configure to receive the request.
#. The listener forwards the request to the associated backend server group based on your configuration. If you have configured a forwarding policy for the listener, the listener evaluates the request based on the forwarding policy. If the request matches the forwarding policy, the listener forwards the request to the backend server group configured for the forwarding policy.
#. Health backend servers in the backend server group receive the request based on the load balancing algorithm and the routing rules you specify in the forwarding policy, handle the request, and return a result to the client.

How requests are routed depends on the :ref:`load balancing algorithms <elb_pro_0003__section12605144013346>` configured for each backend server group. If the listener uses HTTP or HTTPS, how requests are routed also depends on the **forwarding policies** configured for the listener.

.. _elb_pro_0003__section12605144013346:

Load Balancing Algorithms
-------------------------

Both dedicated and shared load balancers support weighted round robin, weighted least connections, and source IP hash.

-  Weighted round robin: Requests are routed to backend servers using the round robin algorithm. Backend servers with higher weights receive proportionately more requests, whereas equal-weighted servers receive the same number of requests. This algorithm is often used for short connections, such as HTTP connections.

   The following figure shows an example of how requests are distributed using the weighted round robin algorithm. Two backend servers are in the same AZ and have the same weight, and each server receives the same proportion of requests.


   .. figure:: /_static/images/en-us_image_0000001160373426.png
      :alt: **Figure 2** Traffic distribution using the weighted round robin algorithm

      **Figure 2** Traffic distribution using the weighted round robin algorithm

-  Weighted least connections: In addition to the weight assigned to each server, the number of connections being processed by each backend server is also considered. Requests are routed to the server with the lowest connections-to-weight ratio. In addition to the number of connections, each server is assigned a weight based on its capacity. Requests are routed to the server with the lowest connections-to-weight ratio. This algorithm is often used for persistent connections, such as connections to a database.

   The following figure shows an example of how requests are distributed using the weighted least connections algorithm. Two backend servers are in the same AZ and have the same weight, 100 connections have been established with backend server 01, and 50 connections have been connected with backend server 02. New requests are preferentially routed to backend server 02.


   .. figure:: /_static/images/en-us_image_0000001160533378.png
      :alt: **Figure 3** Traffic distribution using the weighted least connections algorithm

      **Figure 3** Traffic distribution using the weighted least connections algorithm

-  Source IP hash: The source IP address of each request is calculated using the consistent hashing algorithm to obtain a unique hashing key, and all backend servers are numbered. The generated key is used to allocate the client to a particular server. This allows requests from different clients to be routed based on source IP addresses and ensures that a client is directed to the same server that it was using previously. This algorithm works well for TCP connections of load balancers that do not use cookies.

   The following figure shows an example of how requests are distributed using the source IP hash algorithm. Two backend servers are in the same AZ and have the same weight. If backend server 01 has processed a request from IP address A, the load balancer will route new requests from IP address A to backend server 01.


   .. figure:: /_static/images/en-us_image_0000001205974859.png
      :alt: **Figure 4** Traffic distribution using the source IP hash algorithm

      **Figure 4** Traffic distribution using the source IP hash algorithm
