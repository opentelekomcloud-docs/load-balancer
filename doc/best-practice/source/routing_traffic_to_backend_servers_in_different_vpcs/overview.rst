:original_name: elb_bp_0301.html

.. _elb_bp_0301:

Overview
========

Scenarios
---------

You have servers both in VPCs and your on-premises data center and want load balancers to distribute incoming traffic across these servers.

This section describes how you can use a load balancer to route incoming traffic across cloud and on-premises servers.


.. figure:: /_static/images/en-us_image_0000001625619210.png
   :alt: **Figure 1** Routing traffic across cloud and on-premises servers

   **Figure 1** Routing traffic across cloud and on-premises servers

Solution
--------

Dedicated load balancers can satisfy your needs. You can enable **IP as a Backend** when creating a dedicated load balancer and associate on-premises servers with this dedicated load balancer using their IP addresses.

As shown in :ref:`Figure 2 <elb_bp_0301__en-us_topic_0000001337879265_en-us_topic_0000001242059561_en-us_topic_0000001190774294_fig8149462089>`, ELB can realize hybrid load balancing.

-  You can associate the servers in the same VPC as the load balancer no matter whether you enable **IP as a Backend**.
-  If you enable **IP as a Backend**:

   -  You can associate on-premises servers with the load balancer after the on-premises data center is connected to the cloud through Direct Connect or VPN.
   -  You can also associate the servers in other VPCs different from the load balancer after the VPCs are connected to the VPC where the load balancer is running over VPC peering connections.
   -  You can associate backend servers in the same VPC where the load balancer is running.

.. _elb_bp_0301__en-us_topic_0000001337879265_en-us_topic_0000001242059561_en-us_topic_0000001190774294_fig8149462089:

.. figure:: /_static/images/en-us_image_0000001673939077.png
   :alt: **Figure 2** Associating servers with the load balancer

   **Figure 2** Associating servers with the load balancer

Advantages
----------

You can add servers in the VPC where the load balancer is created, in a different VPC, or in an on-premises data center, by using private IP addresses of the servers to the backend server group of the load balancer. In this way, incoming traffic can be flexibly distributed to cloud servers and on-premises servers for hybrid load balancing.

-  You can add backend servers in the same VPC as the load balancer.
-  You can add backend servers in a VPC that is not the VPC where the load balancer is running by establishing a VPC peering connection between the two VPCs.
-  You can add backend servers in your on-premises data center with the load balancer by connecting your on-premises data center to the cloud through Direct Connect or VPN.

Restrictions and Limitations
----------------------------

When you add IP as backend servers, note the following:

-  If you do not enable the function when you create a load balancer, you can still enable it on the **Basic Information** page of the load balancer.
-  IP as backend servers must use IPv4 addresses.
-  IP as backend servers cannot use public IP addresses or IP addresses from the VPC where the load balancer works. Otherwise, requests cannot be routed to backend servers.
-  The subnet where the load balancer works must have at least 16 IP addresses. Otherwise, IP as backend servers cannot be added. You can add more subnets for more IP addresses on the **Basic Information** page of the load balancer.
-  Security group rules of IP as backend servers must allow traffic from the subnet of the load balancer. Otherwise, health checks will fail.
-  **IP as a Backend** cannot be disabled after it is enabled.
