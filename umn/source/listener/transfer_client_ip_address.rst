:original_name: elb_ug_jt_0514.html

.. _elb_ug_jt_0514:

Transfer Client IP Address
==========================

Scenarios
---------

Generally, load balancers use IP addresses in 100.125.0.0/16 to communicate with backend servers. If you want a load balancer to communicate with backend servers using real IP addresses of the clients, you can enable **Transfer Client IP Address** to pass the IP addresses of the clients to backend servers.

.. note::

   -  Shared load balancers: This function is available only for TCP and UDP listeners.
   -  Dedicated load balancer: This function is enabled for TCP and UDP listeners by default and cannot be disabled.
   -  For HTTP and HTTPS listeners, if you want to obtain the IP addresses of clients, refer to "Layer 7 Load Balancing" in :ref:`How Can I Transfer the IP Address of a Client? <elb_faq_0090__section12598161410315>`

Constraints and Limitations
---------------------------

When you enable or disable the function, if the listener has backend servers associated, traffic to this listener will be interrupted for about 10 seconds. The interruption duration is twice the health check interval configured for the backend server group.

Enabling the Function
---------------------

.. caution::

   -  After this function is enabled, traffic, such as unidirectional download or push traffic, may be interrupted when backend servers are being migrated. After backend servers are migrated, retransmit the packets to restore the traffic.
   -  After this function is enabled, the associated backend servers cannot be used as clients to access the listener.
   -  If a backend server has been associated with the listener and health checks are enabled, enabling this function will check the health of the backend server, and traffic to this server will be interrupted for one or two health check intervals.

#. Perform the following steps to enable the function:

   a. Log in to the management console.
   b. In the upper left corner of the page, click |image1| and select the desired region and project.
   c. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
   d. On the **Load Balancers** page, click the name of the load balancer.
   e. Click **Listeners**.

      -  To add a listener, click **Add Listener**.
      -  To modify a listener, locate the listener, click |image3| on the right of its name, and click **Modify Listener**. In the **Modify Listener** dialog box, modify the parameters as needed.

   f. Enable **Transfer Client IP Address**.

#. Configure security groups, network ACLs, and OS and software security policies so that IP addresses of the clients can access these backend servers.

   .. note::

      If you enable this function, a server cannot be used as both the client and the backend server. If the client and the backend server use the same server and the **Transfer Client IP Address** option is enabled, the backend server will think the packet from the client is sent by itself and will not return a response packet to the load balancer. As a result, the return traffic will be interrupted.

Disabling the Function
----------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image4| and select the desired region and project.
#. Hover on |image5| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. On the **Listeners** tab page, locate the listener, click |image6| next to the listener name, and select **Modify Listener**.
#. Disable **Transfer Client IP Address**.
#. Confirm the configuration and click **Finish**.

.. |image1| image:: /_static/images/en-us_image_0000001747739996.png
.. |image2| image:: /_static/images/en-us_image_0000001794819937.png
.. |image3| image:: /_static/images/en-us_image_0000001794660853.png
.. |image4| image:: /_static/images/en-us_image_0000001747739624.png
.. |image5| image:: /_static/images/en-us_image_0000001794660485.png
.. |image6| image:: /_static/images/en-us_image_0000001794819945.png
