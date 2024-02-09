:original_name: elb_ug_jt_0018.html

.. _elb_ug_jt_0018:

Adding a UDP Listener (with a QUIC Backend Server Group Associated)
===================================================================

Scenarios
---------

If you use UDP as the frontend protocol, you can select QUIC as the backend protocol and select the connection ID to route requests with the same connection ID to the same backend server. QUIC has the advantages of low latency, high reliability, and no head-of-line blocking (HOL blocking), and is very suitable for the mobile Internet. No new connections need to be established when you switch between a Wi-Fi and a mobile data network.

.. note::

   -  QUIC versions include Q043, Q046, and Q050.
   -  UDP listeners using QUIC as backend protocol do not support fragmentation.

Constraints and Limitations
---------------------------

-  Only dedicated load balancers support the QUIC protocol.
-  You can add only UDP listeners if you want to use QUIC as the backend protocol.


Adding a UDP Listener with a QUIC Backend Server Group Associated
-----------------------------------------------------------------

#. Log in to the management console.

#. In the upper left corner of the page, click |image1| and select the desired region and project.

#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. Locate the load balancer and click its name.

   Select **Network load balancing (TCP/UDP)** and select a specification for the load balancer.

#. Under **Listeners**, click **Add Listener**.

#. In the **Configure Listener** step, set **Frontend Protocol** to **UDP**, configure other parameters based on the site requirements, and click **Next: Configure Request Routing Policy**.

#. In the **Configure Routing Policy** step, set **Backend Protocol** to **QUIC** and configure other parameters as required.

#. Configure the parameters and click **Submit.**

Follow-Up Operations
--------------------

After you add a listener, associate backend servers with the listener by performing the operations in :ref:`Adding or Removing Backend Servers (Dedicated Load Balancers) <elb_ug_hd_0003>`.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794660485.png
