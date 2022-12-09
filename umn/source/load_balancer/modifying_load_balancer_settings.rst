:original_name: elb_ug_fz_0006.html

.. _elb_ug_fz_0006:

Modifying Load Balancer Settings
================================

Scenarios
---------

You can modify the bandwidth used by the EIP bound to the load balancer as required.

Modifying the Bandwidth
-----------------------

#. Log in to the management console.

#. In the upper left corner of the page, click |image1| and select the desired region and project.

#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. On the **Load Balancers** page:

   Dedicated load balancers: Click **Elastic Load Balancers**, locate the load balancer whose bandwidth you want to modify and click **Modify IPv4 Bandwidth** or **More** > **Modify IPv6 Bandwidth** in the **Operation** column (if the load balancer has an IPv6 address that has been added to a shared bandwidth).

   Shared load balancers: Click **Elastic Load Balancers**, locate the load balancer whose bandwidth you want to modify and click **Modify Bandwidth** or **Modify IPv4 Bandwidth** in the **Operation** column (in regions where either dedicated load balancers or both shared and dedicated load balancers are available).

#. In the **New Configuration** area, change the bandwidth and click **Next**.

   Select the bandwidth defined by the system or enter a value from 5 Mbit/s to 2,000 Mbit/s.

   .. note::

      You can also change the bandwidth name.

#. Confirm the modified bandwidth and click **Submit**.

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0000001120894978.png
