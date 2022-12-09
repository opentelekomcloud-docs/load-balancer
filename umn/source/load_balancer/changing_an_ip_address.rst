:original_name: elb_lb_000010.html

.. _elb_lb_000010:

Changing an IP Address
======================

Scenarios
---------

ELB allows you to change private IPv4 addresses of load balancers. New private IPv4 addresses can be from the current subnet or other subnets.

Changing a Private IPv4 Address
-------------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. On the **Elastic Load Balancers** tab page, locate the load balancer whose IP address you want to change, and click **More** > **Change Private IPv4 Address** in the **Operation** column.
#. In the **Change Private IPv4 Address** dialog box, select the subnet where the IP address resides and specify the IP address.

   -  To use an IP address from another subnet, select **Automatically-assigned IPv4 address**. The system automatically assigns an IPv4 address for your load balancer.
   -  To use another IP address from the current subnet, specify an IP address.

#. Click **OK**.

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0000001120894978.png
