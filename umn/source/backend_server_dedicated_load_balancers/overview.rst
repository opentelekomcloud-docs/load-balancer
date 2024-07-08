:original_name: elb_ug_hd3_0001.html

.. _elb_ug_hd3_0001:

Overview
========

Backend servers receive and process requests from the associated load balancer.

If the incoming traffic increases, you can add more backend servers to ensure the stability and reliability of applications and eliminate SPOFs. If the incoming traffic decreases, you can remove some backend servers to reduce costs.

If the load balancer is associated with an AS group, backend servers are automatically associated with or disassociated from the load balancer.

.. table:: **Table 1** Adding backend servers

   +-----------------------+---------------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------+
   | Backend Server Type   | Description                                                                                                         | Reference                                                          |
   +=======================+=====================================================================================================================+====================================================================+
   | Cloud servers         | You can add ECSs or BMSs that are in the same VPC as the load balancer.                                             | :ref:`Adding Backend Servers <elb_ug_hd3_0003_01>`                 |
   +-----------------------+---------------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------+
   | IP as backend servers | You can add cloud servers in other VPCs or on-premises servers if IP as a backend is enabled for the load balancer. | :ref:`Adding IP Addresses as Backend Servers <elb_ug_hd3_0004_03>` |
   +-----------------------+---------------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------+

Precautions
-----------

-  It is recommended that you select backend servers running the same OS for easier management and maintenance.

-  The load balancer checks the health of each server added to the associated backend server group if you have configured health check for the backend server group. If a backend server responds normally, the load balancer will consider it healthy. If a backend server responds abnormally, the load balancer will periodically check its health until the backend server is considered healthy.
-  If a backend server is stopped or restarted, connections established with this server will be disconnected, and data being transmitted over these connections will be lost. To avoid this from happening, configure the retry function on the clients to prevent data loss.
-  If you enable sticky sessions, traffic to backend servers may be unbalanced. If this happens, disable sticky sessions and check the requests received by each backend server.

Constraints and Limitations
---------------------------

-  A maximum of 500 backend servers can be added to a backend server group.
-  Inbound security group rules must be configured to allow traffic over the port of each backend server and the health check port. For details, see :ref:`Configuring Security Group and Firewall Rules <elb_ug_hd_0007>`.
-  If you select only network load balancing, a server cannot serve as both a backend server and a client.

.. _elb_ug_hd3_0001__en-us_topic_0000001384422734_section84064491587:

Backend Server Weights
----------------------

You need to set a weight for each backend server in a backend server group to receive requests. The higher the weight, the more requests the backend server receives.

The weight ranges from **0** to **100**. If you set the weight of a backend server to **0**, new requests will not be routed to this server.

Three load balancing algorithms allow you to set weights to backend servers, as shown in the following table. For more information about load balancing algorithms, see :ref:`Load Balancing Algorithms <elb_ug_jt_0003>`.

.. table:: **Table 2** Server weights in different load balancing algorithms

   +-----------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Load Balancing Algorithm          | Weight Setting Description                                                                                                                                                                                    |
   +===================================+===============================================================================================================================================================================================================+
   | Weighted round robin              | -  If none of the backend servers have a weight of 0, the load balancer routes requests to backend servers based on their weights. Backend servers with higher weights receive proportionately more requests. |
   |                                   | -  If two backend servers have the same weights, they receive the same number of requests.                                                                                                                    |
   +-----------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Weighted least connections        | -  If none of the backend servers have a weight of 0, the load balancer calculates the load of each backend server using the formula (Overhead = Number of current connections/Backend server weight).        |
   |                                   | -  The load balancer routes requests to the backend server with the lowest overhead.                                                                                                                          |
   +-----------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Source IP hash                    | -  If none of the backend servers have a weight of 0, requests from the same client are routed to the same backend server within a period of time.                                                            |
   |                                   | -  If the weight of a backend server is 0, no requests are routed to this backend server.                                                                                                                     |
   +-----------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Connection ID                     | -  If none of the backend servers have a weight of 0, the requests from the same client are routed to the same backend server within a period of time.                                                        |
   |                                   | -  If the weight of a backend server is 0, no requests are routed to this backend server.                                                                                                                     |
   +-----------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
