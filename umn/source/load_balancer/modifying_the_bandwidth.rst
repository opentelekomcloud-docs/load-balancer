:original_name: elb_ug_fz_0015.html

.. _elb_ug_fz_0015:

Modifying the Bandwidth
=======================

Scenario
--------

If you set the **Network Type** of a load balancer to **Public IPv4 network** or **IPv6 network**, the load balancer can route requests over the Internet and you can modify the bandwidth used by the EIP bound to the load balancer as required.

.. note::

   -  When changing bandwidth, you need to change the specifications of the dedicated load balancer to avoid speed limit due to insufficient bandwidth.
   -  The bandwidth of the EIP bound to the load balancer is the limit for traffic required by the clients to access the load balancer.


Modifying the Bandwidth
-----------------------

When you modify the bandwidth, traffic routing will not be interrupted.

#. Log in to the management console.

#. In the upper left corner of the page, click |image1| and select the desired region and project.

#. Click |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. On the **Load Balancers** page, locate the load balancer and click **More** in the **Operation** column.

#. Dedicated load balancers: Click **Modify IPv4 Bandwidth** or **Modify IPv6 Bandwidth**.

   Shared load balancers: Click **Modify IPv4 Bandwidth**.

#. In the **New Configuration** area, modify the bandwidth and click **Next**.

   You can select the bandwidth defined by the system or customize the bandwidth. The bandwidth ranges from 1 Mbit/s to 1,000 Mbit/s.

#. Confirm the modified bandwidth and click **Submit**.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794660485.png
