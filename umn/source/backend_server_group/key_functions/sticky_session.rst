:original_name: elb_ug_jt_0004.html

.. _elb_ug_jt_0004:

Sticky Session
==============

Sticky sessions ensure that requests from a client always get routed to the same backend server before a session elapses.

Here is an example that describes how sticky session works. Assume that you have logged in to a server. After a while, you send another request. If sticky sessions are not enabled, the request may be routed to another server, and you will be asked to log in again. If sticky sessions are enabled, all your requests are processed by the same server, and you do not need to repeatedly log in.

Differences Between Sticky Sessions at Layer 4 and Layer 7
----------------------------------------------------------

The following table describes the differences of sticky sessions at Layer 4 at Layer 7.

.. table:: **Table 1** Sticky session comparison

   +-------------+-------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------------------------------+---------------------------------------------------------------------------------------------------+
   | OSI Layer   | Listener Protocol | Sticky Session Type                                                                                                                                                                                                                                                                                                                                                | Stickiness Duration                 | Scenarios Where Sticky Sessions Become Invalid                                                    |
   +=============+===================+====================================================================================================================================================================================================================================================================================================================================================================+=====================================+===================================================================================================+
   | Layer 4     | TCP or UDP        | **Source IP address**: The source IP address of each request is calculated using the consistent hashing algorithm to obtain a unique hashing key, and all backend servers are numbered. The system allocates the client to a particular server based on the generated key. This allows requests from the same IP address are forwarded to the same backend server. | -  Default: 20 minutes              | -  Source IP addresses of the clients change.                                                     |
   |             |                   |                                                                                                                                                                                                                                                                                                                                                                    | -  Maximum: 60 minutes              | -  The session stickiness duration has been reached.                                              |
   |             |                   |                                                                                                                                                                                                                                                                                                                                                                    | -  Range: 1 minute to 60 minutes    |                                                                                                   |
   +-------------+-------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------------------------------+---------------------------------------------------------------------------------------------------+
   | Layer 7     | HTTP or HTTPS     | -  **Load balancer cookie**: The load balancer generates a cookie after receiving a request from the client.                                                                                                                                                                                                                                                       | -  Default: 20 minutes              | -  If requests sent by the clients do not contain a cookie, sticky sessions will not take effect. |
   |             |                   | -  **Application cookie**: The application deployed on the backend server generates a cookie after receiving the first request from the client. All subsequent requests with the same cookie are routed to the same backend server.                                                                                                                                | -  Maximum: 1,440 minutes           | -  Requests from the clients exceed the session stickiness duration.                              |
   |             |                   |                                                                                                                                                                                                                                                                                                                                                                    | -  Range: 1 minute to 1,440 minutes |                                                                                                   |
   +-------------+-------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------------------------------+---------------------------------------------------------------------------------------------------+

Constraints and Limitations
---------------------------

-  You have selected **Weighted round robin** or **Weighted least connections** for :ref:`Load Balancing Algorithm <elb_ug_jt_0003>`.
-  If you use **Direct Connect** or **VPN** to access ELB, you must select **Source IP hash** as the load balancing algorithm and disable sticky sessions for ELB.
-  Dedicated load balancers support two types of sticky session: **Source IP address** and **Load balancer cookie**.

-  Shared load balancers support three types of sticky session: **Source IP address**, **Load balancer cookie**, and **Application cookie**.

.. note::

   -  For HTTP and HTTPS listeners, enabling or disabling sticky sessions may cause few seconds of service interruption.
   -  If you enable sticky sessions, traffic to backend servers may be unbalanced. If this happens, disable sticky sessions and check the requests received by each backend server.
