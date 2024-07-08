:original_name: elb_ug_jt_0014.html

.. _elb_ug_jt_0014:

Configuring Timeout Durations
=============================

Scenarios
---------

You can configure timeout durations (idle timeout, request timeout, and response timeout) for your listeners to meet varied demands. For example, if the size of a request from an HTTP or HTTPS client is large, you can increase the request timeout duration to ensure that the request can be successfully routed.

For shared load balancers, you can only change the timeout durations of TCP, HTTP, and HTTPS listeners, but cannot change the timeout durations of UDP listeners.

For dedicated load balancers, you can change the timeout durations of TCP, UDP, HTTP, and HTTPS listeners.


.. figure:: /_static/images/en-us_image_0000001794660877.png
   :alt: **Figure 1** Timeout durations at Layer 7

   **Figure 1** Timeout durations at Layer 7


.. figure:: /_static/images/en-us_image_0000001747740028.png
   :alt: **Figure 2** Timeout durations at Layer 4

   **Figure 2** Timeout durations at Layer 4

.. table:: **Table 1** Timeout durations

   +-------------+------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+--------------------------------+
   | Protocol    | Type             | Description                                                                                                                                                                                                                                                                | Value Range | Default Timeout Duration       |
   +=============+==================+============================================================================================================================================================================================================================================================================+=============+================================+
   | TCP         | Idle Timeout     | Duration for a connection to be kept alive. If no request is received within this period, the load balancer closes the connection and establishes a new one with the client when the next request arrives.                                                                 | 10~4000s    | 300s                           |
   +-------------+------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+--------------------------------+
   | UDP         | Idle Timeout     |                                                                                                                                                                                                                                                                            | 10~4000s    | Dedicated load balancers: 300s |
   +-------------+------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+--------------------------------+
   | HTTP/HTTPS  | Idle Timeout     |                                                                                                                                                                                                                                                                            | 0~4000s     | 60s                            |
   +-------------+------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+--------------------------------+
   |             | Request Timeout  | Duration after which the load balancer closes the connection with the client if the load balancer does not receive a request from the client.                                                                                                                              | 1~300s      | 60s                            |
   +-------------+------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+--------------------------------+
   |             | Response Timeout | Duration after which the load balancer sends a 504 Gateway Timeout error to the client if the load balancer receives no response after routing a request to a backend server and receives no response after attempting to route the same request to other backend servers. | 1~300s      | 60s                            |
   |             |                  |                                                                                                                                                                                                                                                                            |             |                                |
   |             |                  | .. note::                                                                                                                                                                                                                                                                  |             |                                |
   |             |                  |                                                                                                                                                                                                                                                                            |             |                                |
   |             |                  |    If sticky sessions are enabled and the backend server does not respond within the response timeout duration, the load balancer returns the 504 error code without attempting to route the same request to other backend servers.                                        |             |                                |
   +-------------+------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+--------------------------------+

Procedure
---------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Click |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Click **Listeners**, locate the listener, and click the name of the listener.
#. On the **Basic Information** tab page, click **Edit** on the top right.
#. In the **Edit** dialog box, expand **Advanced Settings**.
#. Configure **Idle Timeout (s)**, **Request Timeout (s)**, or **Response Timeout (s)** as you need.
#. Click **OK**.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794660485.png
