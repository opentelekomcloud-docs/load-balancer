:original_name: elb_ug_hd_0005.html

.. _elb_ug_hd_0005:

Configuring Hybrid Load Balancing
=================================

Scenarios
---------

You can add servers in the VPC where the load balancer is created, in a different VPC, or in an on-premise data center, by using private IP addresses of the servers. In this way, incoming traffic can be flexibly distributed to cloud servers and on-premises servers for hybrid load balancing.

-  To add servers in the same VPC as the load balancer, see :ref:`Adding or Removing Backend Servers (Dedicated Load Balancers) <elb_ug_hd_0003>`.
-  To add backend servers in a different VPC from where the load balancer is running, you need to establish a VPC peering connection between the two VPCs. For details about how to set up a VPC peering connection, see the Virtual Private Cloud User Guide.
-  To add on-premises servers to a backend server group, you need to connect the on-premises data center to the VPC where the load balancer is running through Direct Connect or VPN. For details about how to connect on-premises data centers to the cloud, see the Direct Connect User Guide or Virtual Private Network User Guide.


.. figure:: /_static/images/en-us_image_0000001260652397.png
   :alt: **Figure 1** Routing requests to cloud and on-premises servers

   **Figure 1** Routing requests to cloud and on-premises servers

Prerequisites
-------------

-  A dedicated load balancer has been created.
-  A listener has been added to the load balancer.
-  VPC routes have been correctly configured to make backend servers accessible. IP as backend servers can be in a VPC connected using a VPC peering connection, or in an on-premises data center connected using a Direct Connect or VPN connection.

Enabling IP as a Backend
------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. On the **Load Balancers** page, locate the load balancer and click its name.
#. On the **Basic Information** tab page, click **Enable** next to **IP as a Backend**.
#. Click **OK**.

Adding IP as Backend Servers
----------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image3| and select the desired region and project.
#. Hover on |image4| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. On the **Load Balancers** page, locate the load balancer that you have created and click its name.
#. In the **Backend Server Groups** tab, locate the backend server group and click its name.
#. In the **Basic Information** area on the right, click **IP as Backend Servers**.
#. Click **Add IP as Backend Server** and set the IP address, backend port, and weight.

   .. note::

      Ensure that the IP addresses of the servers are reachable and the backend ports are actually used by backend servers. Otherwise, the backend servers will be considered unhealthy.

#. Click **OK**.

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0000001417088430.png
.. |image3| image:: /_static/images/en-us_image_0000001211126503.png
.. |image4| image:: /_static/images/en-us_image_0000001417088430.png
