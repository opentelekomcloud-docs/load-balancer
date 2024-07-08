:original_name: elb_ug_jt_0515.html

.. _elb_ug_jt_0515:

Transfer Client IP Address (Shared Load Balancers)
==================================================

Scenario
--------

Generally, shared load balancers use IP addresses in 100.125.0.0/16 to communicate with backend servers. If you want a load balancer to communicate with backend servers using real IP addresses of the clients, you can enable **Transfer Client IP Address** to pass the IP addresses of the clients to backend servers.

:ref:`Table 1 <elb_ug_jt_0515__table167041254114314>` lists whether you can enable or disable the transfer client IP address function.

.. _elb_ug_jt_0515__table167041254114314:

.. table:: **Table 1** Transfer client IP address

   +----------------+-------------------------------------+--------------------------------------+
   | Listener Type  | Enabling Transfer Client IP Address | Disabling Transfer Client IP Address |
   +================+=====================================+======================================+
   | TCP and UDP    | Y                                   | Y                                    |
   +----------------+-------------------------------------+--------------------------------------+
   | HTTP and HTTPS | Enabled by default                  | x                                    |
   +----------------+-------------------------------------+--------------------------------------+

Constraints
-----------

-  When you enable or disable **Transfer Client IP Address**, if the listener has backend servers associated, traffic to this listener will be interrupted for about 10 seconds. The interruption duration is twice the health check interval configured for the backend server group.
-  If **Transfer Client IP Address** is enabled, a server cannot serve as both a backend server and a client. If the client and the backend server are using the same server and the **Transfer Client IP Address** option is enabled, the backend server will think the packet is sent by itself but not from the client and will not return a response packet to the load balancer. As a result, the return traffic will be interrupted.
-  If a backend server has been associated with the listener and health checks are enabled, enabling this function will check the health of the backend server, and traffic to this server will be interrupted for one or two health check intervals.
-  After this function is enabled, unidirectional download or push traffic may be interrupted when backend servers are being migrated. After the backend servers are migrated, retransmit the packets to restore the traffic.

Enabling Transfer Client IP Address
-----------------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Click |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. You can use either of the following methods to enable the function:

   -  On the **Listeners** page, locate the listener, and click **Edit** in the **Operation** column.
   -  Click the name of the target listener. On the **Basic Information** area, click **Edit** on the top right corner.

#. In the displayed dialog box, enable **Transfer Client IP Address**.
#. Confirm the configurations and click **OK**.

.. note::

   After **Transfer Client IP Address** is enabled, configure security groups, firewalls, and OS and software security policies so that IP addresses of the clients can access these backend servers.

Disabling Transfer Client IP Address
------------------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image3| and select the desired region and project.
#. Click |image4| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. You can use either of the following methods to disable the function:

   -  On the **Listeners** page, locate the listener, and click **Edit** in the **Operation** column.
   -  Click the name of the target listener. On the **Basic Information** area, click **Edit** on the top right corner.

#. In the displayed dialog box, disable **Transfer Client IP Address**.
#. Confirm the configurations and click **OK**.

Alternatives for Obtaining the IP Address of the Client
-------------------------------------------------------

You can obtain the IP address of a client in one of the ways listed in :ref:`Table 2 <elb_ug_jt_0515__table135982297114>`.

.. _elb_ug_jt_0515__table135982297114:

.. table:: **Table 2** Alternatives

   +----------------+---------------------------------------------------------------------+
   | Listener Type  | Alternatives                                                        |
   +================+=====================================================================+
   | TCP and UDP    | ``-``                                                               |
   +----------------+---------------------------------------------------------------------+
   | HTTP and HTTPS | :ref:`Layer 7 Load Balancing <elb_faq_0090__section12598161410315>` |
   +----------------+---------------------------------------------------------------------+

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794660485.png
.. |image3| image:: /_static/images/en-us_image_0000001747739624.png
.. |image4| image:: /_static/images/en-us_image_0000001794660485.png
