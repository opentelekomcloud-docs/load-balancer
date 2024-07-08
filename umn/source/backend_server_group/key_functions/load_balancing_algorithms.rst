:original_name: elb_ug_jt_0003.html

.. _elb_ug_jt_0003:

Load Balancing Algorithms
=========================

Load balancers receive requests from clients and forward them to backend servers in one or more AZs. Each load balancer has at least a listener and a backend server. The load balancing algorithm you select when you create the backend server group determines how requests are distributed.

Load Balancing Algorithm Type
-----------------------------

Dedicated load balancers support four load balancing algorithms: weighted round robin, weighted least connections, source IP hash, and connection ID.

Shared load balancers support weighted round robin, weighted least connections, and source IP hash algorithms.

-  Weighted round robin: Requests are routed to backend servers using the round robin algorithm. Backend servers with higher weights receive proportionately more requests, whereas equal-weighted servers receive the same number of requests.

   This algorithm is typically used for short connections, such as HTTP connections.

   :ref:`Figure 1 <elb_ug_jt_0003__en-us_topic_0000001411479946_en-us_topic_0093253454_fig7538148162412>` shows an example of how requests are distributed using the weighted round robin algorithm. Two backend servers are in the same AZ and have the same weight, and each server receives the same proportion of requests.

   .. _elb_ug_jt_0003__en-us_topic_0000001411479946_en-us_topic_0093253454_fig7538148162412:

   .. figure:: /_static/images/en-us_image_0000001747381180.png
      :alt: **Figure 1** Traffic distribution using the weighted round robin algorithm

      **Figure 1** Traffic distribution using the weighted round robin algorithm

-  Weighted least connections: In addition to the weight assigned to each server, the number of connections being processed by each backend server is also considered. Requests are routed to the server with the lowest connections-to-weight ratio.

   This algorithm is often used for persistent connections, such as connections to a database.

   :ref:`Figure 2 <elb_ug_jt_0003__en-us_topic_0000001411479946_en-us_topic_0093253454_fig193917324513>` shows an example of how requests are distributed using the weighted least connections algorithm. Two backend servers are in the same AZ and have the same weight, 100 connections have been established with backend server 01, and 50 connections have been connected with backend server 02. New requests are preferentially routed to backend server 02.

   .. _elb_ug_jt_0003__en-us_topic_0000001411479946_en-us_topic_0093253454_fig193917324513:

   .. figure:: /_static/images/en-us_image_0000001747740060.png
      :alt: **Figure 2** Traffic distribution using the weighted least connections algorithm

      **Figure 2** Traffic distribution using the weighted least connections algorithm

-  Source IP hash: The source IP address of each request is calculated using the consistent hashing algorithm to obtain a unique hash key, and all backend servers are numbered. The generated key allocates the client to a particular server. This allows requests from different clients to be routed based on source IP addresses and ensures that requests from the same client are directed to the same server that it was using previously.

   :ref:`Figure 3 <elb_ug_jt_0003__en-us_topic_0000001411479946_en-us_topic_0093253454_fig3381171135617>` shows an example of how requests are distributed using the source IP hash algorithm. Two backend servers are in the same AZ and have the same weight. If backend server 01 has processed a request from IP address A, the load balancer will route new requests from IP address A to backend server 01.

   .. _elb_ug_jt_0003__en-us_topic_0000001411479946_en-us_topic_0093253454_fig3381171135617:

   .. figure:: /_static/images/en-us_image_0000001794820009.png
      :alt: **Figure 3** Traffic distribution using the source IP hash algorithm

      **Figure 3** Traffic distribution using the source IP hash algorithm

-  Connection ID: The connection ID in the packet is calculated using the consistent hash algorithm to obtain a specific value, and backend servers are numbered. The generated value determines to which backend server the requests are routed. This allows requests with different connection IDs to be routed to different backend servers and ensures that requests with the same connection ID are routed to the same backend server.

   This algorithm applies to QUIC requests.

   .. note::

      Only dedicated load balancers support this algorithm.

   :ref:`Figure 4 <elb_ug_jt_0003__en-us_topic_0000001411479946_en-us_topic_0093253454_en-us_topic_0236111231_fig3381171135617>` shows an example of how requests are distributed using the connection ID algorithm. Two backend servers are in the same AZ and have the same weight. If backend server 01 has processed a request from client A, the load balancer will route new requests from client A to backend server 01.

   .. _elb_ug_jt_0003__en-us_topic_0000001411479946_en-us_topic_0093253454_en-us_topic_0236111231_fig3381171135617:

   .. figure:: /_static/images/en-us_image_0000001794820013.png
      :alt: **Figure 4** Traffic distribution using the connection ID algorithm

      **Figure 4** Traffic distribution using the connection ID algorithm
