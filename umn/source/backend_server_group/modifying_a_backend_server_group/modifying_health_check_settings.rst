:original_name: en-us_topic_0000001747380572.html

.. _en-us_topic_0000001747380572:

Modifying Health Check Settings
===============================

Scenario
--------

This section describes how you can modify the health check settings.

After the protocol is changed, the load balancer uses the new protocol to check the health of backend servers. The load balancer continues to route traffic to the backend servers after they are detected healthy.

Before the new configurations take effect, the load balancer may return the HTTP 503 error code to the clients.

Constraints and Notes
---------------------

-  The health check protocol can be different from the backend protocol.
-  To reduce the vCPU usage of the backend servers, it is recommended that you use TCP for health checks. If you want to use HTTP for health checks, you can use static files to return the health check results.
-  If health check is enabled, security group rules must allow traffic from the health check port to the backend servers over the health check protocol.

   -  Dedicated load balancers: For details, see :ref:`Configuring Security Group and Firewall Rules <elb_ug_hd_0007>`.
   -  Shared load balancers: For details, see :ref:`Configuring Security Group and Firewall Rules <elb_ug_hd_0002>`.

.. note::

   After you enable health check, the load balancer immediately checks the health of backend servers.

   -  If a backend server is detected healthy, the load balancer will start routing requests to it over new connections based on the configured loading balancing algorithms and weights.
   -  If a backend server is detected unhealthy, the load balancer will stop routing traffic to it.

Enabling Health Check
---------------------

#. Log in to the management console.

#. In the upper left corner of the page, click |image1| and select the desired region and project.

#. Click |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. In the navigation pane on the left, choose **Elastic Load Balancing** > **Backend Server Groups**.

#. On the **Backend Server Groups** tab page, locate the target backend server group.

#. On the **Summary** page, click **Health Check** on the right.

#. In the **Configure Health Check** dialog box, configure the parameters based on :ref:`Table 1 <en-us_topic_0000001747380572__table772415634315>`.

   .. _en-us_topic_0000001747380572__table772415634315:

   .. table:: **Table 1** Parameters required for configuring health check

      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
      | Parameter             | Description                                                                                                                                                                                                                                                                                    | Example Value         |
      +=======================+================================================================================================================================================================================================================================================================================================+=======================+
      | Health Check          | Specifies whether to enable health checks.                                                                                                                                                                                                                                                     | ``-``                 |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
      | Health Check Protocol | -  The health check protocol can be TCP, HTTP, or HTTPS.                                                                                                                                                                                                                                       | HTTP                  |
      |                       | -  If the protocol of the backend server group is UDP, the health check protocol is UDP by default.                                                                                                                                                                                            |                       |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
      | Domain Name           | Specifies the domain name that will be used for health checks. This parameter is mandatory if the health check protocol is HTTP, HTTPS, or gRPC.                                                                                                                                               | www.elb.com           |
      |                       |                                                                                                                                                                                                                                                                                                |                       |
      |                       | -  You can use the private IP address of the backend server as the domain name.                                                                                                                                                                                                                |                       |
      |                       | -  You can also specify a domain name that consists of at least two labels separated by periods (.). Use only letters, digits, and hyphens (-). Do not start or end strings with a hyphen. Max total: 100 characters. Max label: 63 characters.                                                |                       |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
      | Health Check Port     | Specifies the port that will be used by the load balancer to check the health of backend servers. The port number ranges from **1** to **65535**.                                                                                                                                              | 80                    |
      |                       |                                                                                                                                                                                                                                                                                                |                       |
      |                       | .. note::                                                                                                                                                                                                                                                                                      |                       |
      |                       |                                                                                                                                                                                                                                                                                                |                       |
      |                       |    By default, the service port on each backend server is used. You can also specify a port for health checks.                                                                                                                                                                                 |                       |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
      | Path                  | Specifies the health check URL, which is the destination on backend servers for health checks. This parameter is mandatory if the health check protocol is HTTP, HTTPS, or gRPC. The path can contain 1 to 80 characters and must start with a slash (/).                                      | /index.html           |
      |                       |                                                                                                                                                                                                                                                                                                |                       |
      |                       | -  If the backend server group is associated with a dedicated load balancer, the check path can contain letters, digits, hyphens (-), slashes (/), periods (.), question marks (?), number signs (#), percent signs (%), ampersands (&), and extended character sets \_;~!. ()\ ``*[]@$^:',+`` |                       |
      |                       | -  If the backend server group is associated with a shared load balancer, the path can contain letters, digits, hyphens (-), slashes (/), periods (.), question marks (?), percent signs (%), ampersands (&), and extended character \_                                                        |                       |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
      | Interval (s)          | Specifies the maximum time between two consecutive health checks, in seconds.                                                                                                                                                                                                                  | 5                     |
      |                       |                                                                                                                                                                                                                                                                                                |                       |
      |                       | The interval ranges from **1** to **50**.                                                                                                                                                                                                                                                      |                       |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
      | Timeout (s)           | Specifies the maximum time required for waiting for a response from the health check, in seconds. The interval ranges from **1** to **50**.                                                                                                                                                    | 3                     |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
      | Maximum Retries       | Specifies the maximum number of health check retries. The value ranges from **1** to **10**.                                                                                                                                                                                                   | 3                     |
      +-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+

#. Click **OK**.

Disabling Health Check
----------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image3| and select the desired region and project.
#. Click |image4| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. In the navigation pane on the left, choose **Elastic Load Balancing** > **Backend Server Groups**.
#. On the **Backend Server Groups** page, click the name of the target backend server group.
#. On the **Summary** page, click **Health Check** on the right.
#. In the **Configure Health Check** dialog box, disable health check.
#. Click **OK**.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794660485.png
.. |image3| image:: /_static/images/en-us_image_0000001747739624.png
.. |image4| image:: /_static/images/en-us_image_0000001747739748.png
