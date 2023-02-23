:original_name: elb_pro_01_0004.html

.. _elb_pro_01_0004:

Load Balancing on a Public or Private Network
=============================================

A load balancer can work on either a public or private network.

Load Balancing on a Public Network
----------------------------------

You can bind an EIP to a load balancer so that it can receive requests from the Internet and route the requests to backend servers.


.. figure:: /_static/images/en-us_image_0000001135576038.png
   :alt: **Figure 1** Load balancing on a public network

   **Figure 1** Load balancing on a public network

Load Balancing on a Private Network
-----------------------------------

A load balancer has only a private IP address to receive requests from clients in a VPC and route the requests to backend servers in the same VPC. This type of load balancer can only be accessed in a VPC.


.. figure:: /_static/images/en-us_image_0000001181535567.png
   :alt: **Figure 2** Load balancing on a private network

   **Figure 2** Load balancing on a private network

Network Types and Load Balancers
--------------------------------

.. table:: **Table 1** Dedicated load balancers and their network types

   +--------------------------+----------------------+--------------------------------------------------------------------------------------------+
   | Load Balancer Type       | Network Type         | Description                                                                                |
   +==========================+======================+============================================================================================+
   | Dedicated load balancers | Public IPv4 network  | Each load balancer has an IPv4 EIP bound to enable it to route requests over the Internet. |
   +--------------------------+----------------------+--------------------------------------------------------------------------------------------+
   |                          | Private IPv4 network | Each load balancer has only a private IPv4 address and can route requests in a VPC.        |
   +--------------------------+----------------------+--------------------------------------------------------------------------------------------+

.. table:: **Table 2** Shared load balancers and their network types

   +-----------------------+-----------------------+------------------------------------------------------------------------------------------+
   | Load Balancer Type    | Network Type          | Description                                                                              |
   +=======================+=======================+==========================================================================================+
   | Shared load balancers | Public network        | Load balancers can route requests on both public and private networks.                   |
   |                       |                       |                                                                                          |
   |                       |                       | -  Each load balancer has an EIP bound to enable it to route requests over the Internet. |
   |                       |                       | -  The load balancer also has a private IP address and can route requests in a VPC.      |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------+
   |                       | Private network       | Each load balancer has only a private IP address and can route requests in a VPC.        |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------+
