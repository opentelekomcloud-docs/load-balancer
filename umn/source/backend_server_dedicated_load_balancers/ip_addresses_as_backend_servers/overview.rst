:original_name: elb_ug_hd3_0004_01.html

.. _elb_ug_hd3_0004_01:

Overview
========

Dedicated load balancers support hybrid load balancing. You can add servers and supplementary network interfaces in the VPC where the load balancer is created, in a different VPC, or in an on-premises data center, by using private IP addresses of the servers to the backend server group of the load balancer.

In this way, incoming traffic can be flexibly distributed to cloud servers and on-premises servers.


.. figure:: /_static/images/en-us_image_0000001794819821.png
   :alt: **Figure 1** Routing requests to cloud and on-premises servers

   **Figure 1** Routing requests to cloud and on-premises servers

Constraints and Limitations
---------------------------

-  IP as a backend cannot be disabled after it is enabled.
-  Only private IPv4 addresses can be added as backend servers.
-  A maximum of 50,000 concurrent connections can be established with a backend server that is added by using its IP address.
-  If you add IP addresses as backend servers, the source IP addresses of the clients cannot be passed to these servers.

Scenario
--------

If IP as a backend is enabled, you can add backend servers by using their IP addresses. You need to get prepared for different scenarios as shown in :ref:`Table 1 <elb_ug_hd3_0004_01__table39821317182412>`.

.. _elb_ug_hd3_0004_01__table39821317182412:

.. table:: **Table 1** Adding IP addresses as backend servers

   +----------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
   | Where Servers Are Running                                                  | Preparations                                                                                                                                                                                                                                                      |                       |
   +============================================================================+===================================================================================================================================================================================================================================================================+=======================+
   | In a VPC that is different from the VPC where the load balancer is running | Set up a VPC peering connection between the VPC where the load balancer is running and the VPC where the servers are running.                                                                                                                                     |                       |
   |                                                                            |                                                                                                                                                                                                                                                                   |                       |
   |                                                                            | For details about how to set up a VPC peering connection, see the Virtual Private Cloud User Guide.                                                                                                                                                               |                       |
   +----------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
   | In an on-premises data center                                              | Connect the on-premises data center to the VPC where the load balancer is running through Direct Connect or VPN. For details about how to connect on-premises data centers to the cloud, see the Direct Connect User Guide or Virtual Private Network User Guide. |                       |
   +----------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
