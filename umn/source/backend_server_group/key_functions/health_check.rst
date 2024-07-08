:original_name: elb_ug_hc_0001.html

.. _elb_ug_hc_0001:

Health Check
============

ELB periodically sends requests to backend servers to check whether they can process requests. This process is called health check.

If a backend server is detected unhealthy, the load balancer will stop route requests to it. After the backend server recovers, the load balancer will resume routing requests to it.

If backend servers have to handle large number of requests, frequent health checks may overload the backend servers and cause them to respond slowly. To address this problem, you can prolong the health check interval or use TCP or UDP instead of HTTP. You can also disable health check. If you choose to disable health check, requests may be routed to unhealthy servers, and service interruptions may occur.

Health Check Protocol
---------------------

You can configure health checks when configuring backend server groups. Generally, you can use the default setting or select a different health check protocol as you need.

If you want to modify health check settings, see details in :ref:`Modifying Health Check Settings <en-us_topic_0000001747380572>`.

Select a health check protocol that matches the backend protocol as described in :ref:`Table 1 <elb_ug_hc_0001__table16665175620103>` and :ref:`Table 2 <elb_ug_hc_0001__table19511358204120>`.

.. _elb_ug_hc_0001__table16665175620103:

.. table:: **Table 1** The backend protocol and health check protocols (dedicated load balancers)

   ================ =====================
   Backend Protocol Health Check Protocol
   ================ =====================
   TCP              TCP, HTTP, or HTTPS
   UDP              UDP
   QUIC             UDP
   HTTP             TCP, HTTP, HTTPS
   HTTPS            TCP, HTTP, HTTPS
   ================ =====================

.. _elb_ug_hc_0001__table19511358204120:

.. table:: **Table 2** The backend protocol and health check protocols (shared load balancers)

   ================ =====================
   Backend Protocol Health Check Protocol
   ================ =====================
   TCP              TCP or HTTP
   UDP              UDP
   HTTP             TCP or HTTP
   HTTPS            TCP or HTTP
   ================ =====================

TCP Health Check
----------------

For TCP, HTTP, and HTTPS backend protocols, you can use TCP to initiate three-way handshakes to obtain the statuses of backend servers.


.. figure:: /_static/images/en-us_image_0000001794819789.png
   :alt: **Figure 1** TCP health check

   **Figure 1** TCP health check

The TCP health check process is as follows:

#. The load balancer sends a TCP SYN packet to the backend server (in the format of {*Private IP address*}:{*Health check port*}).
#. The backend server returns an SYN-ACK packet.

   -  If ELB does not receive the SYN-ACK packet within the health check timeout duration, the backend server is declared unhealthy. Then, ELB sends an RST packet to the backend server to terminate the TCP connection.
   -  If ELB receives the SYN-ACK packet from the backend server within the health check timeout duration, it sends an ACK packet to the backend server and declares that the backend server is healthy. After that, ELB sends an RST packet to the backend server to terminate the TCP connection.

.. important::

   After a successful TCP three-way handshake, an RST packet will be sent to close the TCP connection. The application on the backend server may consider this packet a connection error and reply with a message, for example, "Connection reset by peer". To avoid this issue, take either of the following actions:

   -  Use :ref:`HTTP Health Check <elb_ug_hc_0001__en-us_topic_0000001461559777_section131061210163>`.
   -  Have the backend server ignore the connection error.

UDP Health Check
----------------

For UDP backend protocol, ELB sends ICMP and UDP probe packets to backend servers to check their health.


.. figure:: /_static/images/en-us_image_0000001794819785.png
   :alt: **Figure 2** UDP health check

   **Figure 2** UDP health check

The UDP health check process is as follows:

#. The load balancer sends an ICMP Echo Request packet to the backend server.

   -  If the load balancer does not receive an ICMP Echo Reply packet within the health check timeout duration, the backend server is declared unhealthy.
   -  If the load balancer receives an ICMP Echo Reply packet within the timeout period, it sends a UDP probe packet to the backend server.

#. If the load balancer does not receive an ICMP Port Unreachable error within the health check timeout duration, it declares the backend server is healthy. If the load balancer receives an ICMP Port Unreachable error, the backend server is declared unhealthy.

.. _elb_ug_hc_0001__en-us_topic_0000001461559777_section131061210163:

HTTP Health Check
-----------------

You can also configure HTTP health checks to obtain server statuses through HTTP GET requests if you select TCP, HTTP, or HTTPS as the backend protocol. :ref:`Figure 3 <elb_ug_hc_0001__en-us_topic_0000001461559777_fig18544191717440>` shows how an HTTP health check works.

.. _elb_ug_hc_0001__en-us_topic_0000001461559777_fig18544191717440:

.. figure:: /_static/images/en-us_image_0000001747739832.png
   :alt: **Figure 3** HTTP health check

   **Figure 3** HTTP health check

The HTTPS health check process is as follows:

#. The load balancer sends an HTTP GET request to the backend server (in format of *{Private IP address}*:*{Health check port}*/*{Health check path}*). (You can specify a domain name when configuring a health check.)
#. The backend server returns an HTTP status code to ELB.

   -  If the load balancer receives the status code within the health check timeout duration, it compares the status code with the preset one. If the status codes are the same, the backend server is declared healthy.
   -  If the load balancer does not receive any response from the backend server within the health check timeout duration, it declares the backend server is unhealthy.

HTTPS Health Check
------------------

For TCP, HTTP, and HTTPS backend protocols, you can use HTTPS to establish an SSL connection over TLS handshakes to obtain the statuses of backend servers. :ref:`Figure 4 <elb_ug_hc_0001__fig12946174920321>` shows how an HTTPS health check works.

.. _elb_ug_hc_0001__fig12946174920321:

.. figure:: /_static/images/en-us_image_0000001747739840.png
   :alt: **Figure 4** HTTPS health check

   **Figure 4** HTTPS health check

The HTTPS health check process is as follows:

#. The load balancer sends a Client Hello packet to establish an SSL connection with the backend server.
#. After receiving the Server Hello packet from the backend server, the load balancer sends an encrypted HTTP GET request to the backend server (in the format of *{Private IP address}*:*{Health check port}*/*{Health check path}*). (You can specify a domain name when configuring a health check.)
#. The backend server returns an HTTP status code to ELB.

   -  If the load balancer receives the status code within the health check timeout duration, it compares the status code with the preset one. If the status codes are the same, the backend server is declared healthy.
   -  If the load balancer does not receive any response from the backend server within the health check timeout duration, it declares the backend server is unhealthy.

Health Check Time Window
------------------------

Health checks greatly improve service availability. However, if health checks are too frequent, service availability will be compromised. To avoid the impact, ELB declares a backend server healthy or unhealthy after several consecutive health checks.

Take shared load balancers as an example. The health check time window is determined by the factors in :ref:`Table 3 <elb_ug_hc_0001__table58055598220>`.

.. _elb_ug_hc_0001__table58055598220:

.. table:: **Table 3** Factors affecting the health check time window

   +------------------------+-------------------------------------------------------------------------------------------------------------------------------------------+
   | Factor                 | Description                                                                                                                               |
   +========================+===========================================================================================================================================+
   | Check Interval         | How often health checks are performed.                                                                                                    |
   +------------------------+-------------------------------------------------------------------------------------------------------------------------------------------+
   | Timeout Duration       | How long the load balancer waits for the response from the backend server.                                                                |
   +------------------------+-------------------------------------------------------------------------------------------------------------------------------------------+
   | Health Check Threshold | The number of consecutive successful or failed health checks required for determining whether the backend server is healthy or unhealthy. |
   +------------------------+-------------------------------------------------------------------------------------------------------------------------------------------+

The following is a formula for you to calculate the health check time window:

-  Time window for a backend server to be detected healthy = Timeout duration x Healthy threshold + Interval x (Healthy threshold - 1)
-  Time window for a backend server to be detected unhealthy = Timeout duration x Unhealthy threshold + Interval x (Unhealthy threshold - 1)

As shown in :ref:`Figure 5 <elb_ug_hc_0001__en-us_topic_0000001461559777_fig99931640162119>`, if the health check interval is 4s, the health check timeout duration is 2s, and unhealthy threshold is 3, the time window for a backend server to be considered unhealthy is calculated as follows: 2 x 3 + 4 x (3 - 1) = 14s.

.. _elb_ug_hc_0001__en-us_topic_0000001461559777_fig99931640162119:

.. figure:: /_static/images/en-us_image_0000001747739828.png
   :alt: **Figure 5** Health check timeout duration

   **Figure 5** Health check timeout duration

Rectifying an Unhealthy Backend Server
--------------------------------------

If a backend server is detected unhealthy, see :ref:`How Do I Troubleshoot an Unhealthy Backend Server? <en-us_topic_0018127975>`
