:original_name: elb_lb_000010.html

.. _elb_lb_000010:

Changing an IP Address
======================

Scenarios
---------

You can change the private IPv4 address and IPv6 address bound to a load balancer.

-  You can change the private IPv4 address into another IPv4 IP address in the current subnet or other subnets.
-  You can change the IPv6 address into another IPv6 IP address in other subnets.

.. note::

   You can only change the IP address bound to a dedicated load balancer.

Changing a Private IPv4 Address
-------------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. On the **Load Balancers** page, locate the load balancer whose IP address you want to change, and click **More** > **Change Private IPv4 Address** in the **Operation** column.
#. In the **Change Private IPv4 Address** dialog box, select the subnet where the IP address resides and specify the IP address.

   -  To use an IP address from another subnet, select **Automatically assign IPv4 address**. The system automatically assigns an IPv4 address for your load balancer.
   -  To use another IP address from the current subnet, specify an IP address.

#. Click **OK**.

Changing an IPv6 Address
------------------------

#. Log in to the management console.

#. In the upper left corner of the page, click |image3| and select the desired region and project.

#. Hover on |image4| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. On the **Load Balancers** page, locate the load balancer whose IP address you want to change, and click **More** > **Change IPv6 Address** in the **Operation** column.

#. In the **Change IPv6 Address** dialog box, select a different subnet where the IP address resides and specify the IP address.

   The system will automatically assign an IPv6 address to the load balancer from the subnet you select.

#. Click **OK**.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794660485.png
.. |image3| image:: /_static/images/en-us_image_0000001747739624.png
.. |image4| image:: /_static/images/en-us_image_0000001794660485.png
