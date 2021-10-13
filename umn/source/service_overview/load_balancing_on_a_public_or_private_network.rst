Load Balancing on a Public or Private Network
=============================================

A load balancer can work on either a public or private network.

Load Balancing on a Public Network
----------------------------------

You can bind an EIP to a load balancer so that it can receive requests from clients on the Internet and route the requests to backend servers.

| **Figure 1** Load balancing on a public network
| |image1|

Load Balancing on a Private Network
-----------------------------------

A load balancer has only a private IP address to receive requests from clients in a VPC and route the requests to backend servers in the same VPC. This type of load balancer can only be accessed in a VPC.

| **Figure 2** Load balancing on a private network
| |image2|

Network Types and Load Balancer Types
-------------------------------------



.. _en-us_elb_01_0004__table18627142116143:

.. table:: **Table 1** Dedicated load balancers and their network types

   +---------------------------------------+---------------------------------------+---------------------------------------+
   | Load Balancer Type                    | Network Type                          | Network Type                          |
   +=======================================+=======================================+=======================================+
   | Dedicated load balancers              | Public IPv4 network                   | Each load balancer has an IPv4 EIP    |
   |                                       |                                       | bound to enable it to route requests  |
   |                                       |                                       | over the Internet.                    |
   +---------------------------------------+---------------------------------------+---------------------------------------+
   |                                       | Private IPv4 network                  | Each load balancer has only a private |
   |                                       |                                       | IPv4 address and can route requests   |
   |                                       |                                       | in a VPC.                             |
   +---------------------------------------+---------------------------------------+---------------------------------------+
   |                                       | IPv6 network                          | Each load balancer has an IPv6        |
   |                                       |                                       | address bound.                        |
   |                                       |                                       |                                       |
   |                                       |                                       | -  If the IPv6 address is added to a  |
   |                                       |                                       |    shared bandwidth, the load         |
   |                                       |                                       |    balancer can route requests over   |
   |                                       |                                       |    the Internet.                      |
   |                                       |                                       | -  If the IPv6 address is not added   |
   |                                       |                                       |    to a shared bandwidth, the load    |
   |                                       |                                       |    balancer can route requests only   |
   |                                       |                                       |    in a VPC.                          |
   +---------------------------------------+---------------------------------------+---------------------------------------+



.. _en-us_elb_01_0004__table17299338192413:

.. table:: **Table 2** Shared load balancers and their network types

   +---------------------------------------+---------------------------------------+---------------------------------------+
   | Load Balancer Type                    | Network Type                          | Description                           |
   +=======================================+=======================================+=======================================+
   | Shared load balancers                 | Public network                        | Load balancers can route requests on  |
   |                                       |                                       | both public and private networks.     |
   |                                       |                                       |                                       |
   |                                       |                                       | -  Each load balancer has an EIP      |
   |                                       |                                       |    bound to enable it to route        |
   |                                       |                                       |    requests over the Internet.        |
   |                                       |                                       | -  The load balancer also has a       |
   |                                       |                                       |    private IP address and can route   |
   |                                       |                                       |    requests in a VPC.                 |
   +---------------------------------------+---------------------------------------+---------------------------------------+
   |                                       | Private network                       | Each load balancer has only a private |
   |                                       |                                       | IP address and can route requests in  |
   |                                       |                                       | a VPC.                                |
   +---------------------------------------+---------------------------------------+---------------------------------------+

.. |image1| image:: /images/en-us_image_0000001135576038.png
   :class: vsd

.. |image2| image:: /images/en-us_image_0000001181535567.png
   :class: vsd

