Configuring a Health Check
==========================

Scenarios
---------

You can configure a health check when you add a listener. If you have no special requirements, retain the default settings.

Function Description
--------------------

-  The health check protocol can be different from the backend protocol.
-  To reduce the CPU usage of backend servers, you can use TCP for health checks. If you want to use HTTP for health checks, use static files to obtain the health statuses.
-  You can increase the health check interval to reduce the health check frequency.
-  After you enable health checks, the load balancer immediately checks the health of backend servers and will start routing requests over new connections. If a backend server becomes unhealthy, the load balancer will stop routing traffic to it. However, request routing over established connections is not affected. To ensure service availability, you can enable health checks during off-peak hours.

Configuring a Health Check for a Shared Load Balancer
-----------------------------------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Click **Backend Server Groups**, locate the backend server group, and click its name.
#. Click **More** in the **Operation** column.
#. Select **Configure Health Check** from the drop-down list.
#. In the **Configure Health Check** dialog box, configure the parameters based on `Table 1 <#en-us_topic_0162227063__table95680412371>`__.
   

.. _en-us_topic_0162227063__table95680412371:

   .. table:: **Table 1** Parameters for configuring a health check

      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Parameter                             | **Description**                       | **Example Value**                     |
      +=======================================+=======================================+=======================================+
      | Enable Health Check                   | Specifies whether to enable health    | N/A                                   |
      |                                       | checks.                               |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Protocol                              | -  Specifies the protocol used by the | HTTP                                  |
      |                                       |    load balancer to perform health    |                                       |
      |                                       |    checks on backend servers. You can |                                       |
      |                                       |    select either TCP or HTTP. A       |                                       |
      |                                       |    selected protocol cannot be        |                                       |
      |                                       |    changed.                           |                                       |
      |                                       | -  If the frontend protocol is UDP,   |                                       |
      |                                       |    the health check protocol is UDP   |                                       |
      |                                       |    by default.                        |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Domain Name                           | Specifies the domain name that will   | www.elb.com                           |
      |                                       | be used for health checks.            |                                       |
      |                                       |                                       |                                       |
      |                                       | The domain name can contain digits,   |                                       |
      |                                       | letters, hyphens (-), and periods     |                                       |
      |                                       | (.), and must start with a digit or   |                                       |
      |                                       | letter. The field is left blank by    |                                       |
      |                                       | default and is available only when    |                                       |
      |                                       | the health check protocol is HTTP.    |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Port                                  | Specifies the port used by the load   | 80                                    |
      |                                       | balancer to perform health checks on  |                                       |
      |                                       | backend servers. The port number      |                                       |
      |                                       | ranges from 1 to 65535.               |                                       |
      |                                       |                                       |                                       |
      |                                       | NOTE:                                 |                                       |
      |                                       | This parameter is optional. If you do |                                       |
      |                                       | not specify a health check port, a    |                                       |
      |                                       | port of the backend server will be    |                                       |
      |                                       | used for health checks by default. If |                                       |
      |                                       | you specify a port, it will be used   |                                       |
      |                                       | for health checks.                    |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Advanced Settings                     |                                       |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Interval (s)                          | Specifies the maximum time between    | 5                                     |
      |                                       | health checks, in seconds.            |                                       |
      |                                       |                                       |                                       |
      |                                       | The interval ranges from **1** to     |                                       |
      |                                       | **50**.                               |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Timeout (s)                           | Specifies the maximum time required   | 3                                     |
      |                                       | for waiting for a response from the   |                                       |
      |                                       | health check, in seconds. The timeout |                                       |
      |                                       | duration ranges from **1** to **50**. |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Check Path                            | Specifies the destination path for    | /index.html                           |
      |                                       | health checks. Configure this         |                                       |
      |                                       | parameter only if you have set        |                                       |
      |                                       | **Protocol** to **HTTP**. The path    |                                       |
      |                                       | can contain 1 to 80 characters and    |                                       |
      |                                       | must start with a slash (/).          |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Maximum Retries                       | Specifies the maximum number of       | 3                                     |
      |                                       | health check retries. The value       |                                       |
      |                                       | ranges from **1** to **10**.          |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+

#. Click **Finish**.

.. |image1| image:: /images/en-us_image_0241356603.png

.. |image2| image:: /images/en-us_image_0000001120894978.png

