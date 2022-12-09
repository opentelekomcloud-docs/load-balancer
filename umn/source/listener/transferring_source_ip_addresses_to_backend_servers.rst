:original_name: elb_ug_jt_0514.html

.. _elb_ug_jt_0514:

Transferring Source IP Addresses to Backend Servers
===================================================

Scenarios
---------

Generally, load balancers use IP addresses in the 100.125.0.0.16 IP address range to communicate with backend servers. If you want a load balancer to communicate with backend servers using real IP addresses of the clients, you can enable **Obtain Client IP Address** to pass the IP addresses of the clients to backend servers.

.. note::

   -  Shared load balancers: This function is available only for TCP and UDP listeners.
   -  Dedicated load balancer: This function is enabled for TCP and UDP listeners by default and cannot be disabled.
   -  For TCP listeners, you can configure the TOA plug-in to obtain IP addresses of the clients. For details, see :ref:`Configuring the TOA Module <en-us_elb_06_0001>`.
   -  For HTTP and HTTPS listeners, if you want to obtain the IP addresses of clients, refer to "Layer 7 Load Balancing" in :ref:`How Can I Obtain the IP Address of a Client? <elb_faq_0090__section12598161410315>`

Constraints and Limitations
---------------------------

When you enable or disable the function, if the listener has backend servers associated, traffic to this listener will be interrupted for about 10 seconds. The interruption duration is twice the health check interval configured for the backend server group.

Disabling the Function
----------------------

#. Log in to the management console.

#. In the upper left corner of the page, click |image1| and select the desired region and project.

#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. Locate the load balancer and click its name.

#. Click **Listeners**.

   For a shared load balancer listener, locate the listener and click |image3| on the right of its name. In the **Modify Listener** dialog box, modify the parameters as needed.

#. Disable **Obtain Client IP Address**.

#. Confirm the configuration and click **Finish**.

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0000001120894978.png
.. |image3| image:: /_static/images/en-us_image_0000001242773861.png
