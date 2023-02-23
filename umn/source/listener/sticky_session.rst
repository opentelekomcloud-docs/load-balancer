:original_name: elb_ug_jt_0004.html

.. _elb_ug_jt_0004:

Sticky Session
==============

Sticky sessions ensure that requests from a client always get routed to the same backend server before a session elapses.

Here is an example that describes what sticky sessions. Assume that you have logged in to a server. After a while, you send another request. If sticky sessions are not enabled, the request may be routed to another server, and you will be asked to log in again. If sticky sessions are enabled, all your requests are processed by the same server, and you do not need to repeatedly log in.

Sticky sessions at Layer 4 are different from those at Layer 7.

Prerequisites
-------------

You have selected **Weighted round robin** for **Load Balancing Algorithm**.

Constraints and Limitations
---------------------------

If you use **Direct Connect**, **VPN**, to access ELB, you must select **Source IP hash** as the load balancing algorithm and disable sticky sessions for ELB.

Differences Between Sticky Sessions at Layer 4 and Layer 7
----------------------------------------------------------

.. table:: **Table 1** Sticky session comparison

   +-------------+---------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------------------------------+---------------------------------------------------------------------------------------------------+
   | OSI Layer   | Listener's Protocol | Sticky Session Type                                                                                                                                                                                                                                                                                                                                                                                                      | Stickiness Duration                 | Scenarios Where Sticky Sessions Become Invalid                                                    |
   +=============+=====================+==========================================================================================================================================================================================================================================================================================================================================================================================================================+=====================================+===================================================================================================+
   | Layer 4     | TCP or UDP          | **Source IP address**: The source IP address of each request is calculated using the consistent hashing algorithm to obtain a unique hash key, and all backend servers are numbered. The system allocates the client to a particular server based on the generated key. This enables requests from different clients to be routed and ensures that a client is directed to the same server that it was using previously. | -  Default: 20 minutes              | -  Source IP addresses of the clients change.                                                     |
   |             |                     |                                                                                                                                                                                                                                                                                                                                                                                                                          | -  Maximum: 1 hour                  | -  The session stickiness duration has been reached.                                              |
   |             |                     |                                                                                                                                                                                                                                                                                                                                                                                                                          | -  Range: 1 minute to 60 minutes    |                                                                                                   |
   +-------------+---------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------------------------------+---------------------------------------------------------------------------------------------------+
   | Layer 7     | HTTP or HTTPS       | -  **Load balancer cookie**: The load balancer generates a cookie after receiving a request from the client. All subsequent requests with the same cookie are then routed to the same backend server.                                                                                                                                                                                                                    | -  Default: 20 minutes              | -  If requests sent by the clients do not contain a cookie, sticky sessions will not take effect. |
   |             |                     | -  **Application cookie**: The application deployed on the backend server generates a cookie after receiving the first request from the client. All requests with the same cookie generated by backend application are then routed to the same backend server.                                                                                                                                                           | -  Maximum: 24 hours                | -  The session stickiness duration has been reached.                                              |
   |             |                     |                                                                                                                                                                                                                                                                                                                                                                                                                          | -  Range: 1 minute to 1,440 minutes |                                                                                                   |
   +-------------+---------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------------------------------+---------------------------------------------------------------------------------------------------+

Dedicated load balancers support two types of sticky sessions: **Source IP address** and **Load balancer cookie**

Shared load balancers support three types of sticky session, including **Source IP address**, **Load balancer cookie**, and **Application cookie**.

Enabling Sticky Sessions
------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. For a shared load balancer and a dedicated load balancer, click **Backend Server Groups**, locate the backend server group, and click |image3| on the right of its name.
#. Enable **Sticky Session**, select the sticky session type, and set the session stickiness duration.
#. Click **OK**.

.. note::

   You can also configure sticky sessions when adding a listener or creating a backend server group.

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0000001417088430.png
.. |image3| image:: /_static/images/en-us_image_0167649598.png
