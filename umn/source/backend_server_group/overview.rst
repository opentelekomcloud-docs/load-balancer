:original_name: elb_ug_hdg_0001.html

.. _elb_ug_hdg_0001:

Overview
========

Introduction
------------

A backend server group is a logical collection of one or more backend servers to receive massive concurrent requests at the same time. A backend server can be an ECS, BMS, or IP address.

The following process describes how a backend server group forwards traffic:

#. A client sends a request to your application. The listeners added to your load balancer use the protocols and ports you have configured forward the request to the associated backend server group.
#. Healthy backend servers in the backend server group receive the request based on the load balancing algorithm, handle the request, and return a result to the client.
#. In this way, massive concurrent requests can be processed at the same time, improving the availability of your applications.

.. table:: **Table 1** Adding backend servers

   +-----------------------+---------------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------+
   | Backend Server Type   | Description                                                                                                         | Reference                                                          |
   +=======================+=====================================================================================================================+====================================================================+
   | Cloud servers         | You can add ECSs or BMSs that are in the same VPC as the load balancer.                                             | :ref:`Adding Backend Servers <elb_ug_hd3_0003_01>`                 |
   +-----------------------+---------------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------+
   | IP as backend servers | You can add cloud servers in other VPCs or on-premises servers if IP as a backend is enabled for the load balancer. | :ref:`Adding IP Addresses as Backend Servers <elb_ug_hd3_0004_03>` |
   +-----------------------+---------------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------+

Advantages
----------

Backend server groups can bring the following benefits:

-  **Reduced costs and easier management**: You can add or remove backend servers as traffic changes over the time. This can help avoid low resource utilization and makes it easy to manage backend servers.
-  **Higher reliability**: Traffic is routed only to healthy backend servers in the backend server group.

Key Functions
-------------

You can configure the key functions listed in :ref:`Table 2 <elb_ug_hdg_0001__en-us_topic_0000001383452116_table178831320144314>` for each backend server group to ensure service stability.

.. _elb_ug_hdg_0001__en-us_topic_0000001383452116_table178831320144314:

.. table:: **Table 2** Key functions

   +--------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------+
   | Key Function             | Description                                                                                                                                                          | Detail                                                                         |
   +==========================+======================================================================================================================================================================+================================================================================+
   | Removal Protection       | Specifies whether to enable the removal protection option to prevent a backend server group from being removed by accident.                                          | :ref:`Enabling Removal Protection for a Backend Server Group <elb_ug_hd_0004>` |
   +--------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------+
   | Health Check             | Specifies whether to enable the health check option. Health checks determine whether backend servers are healthy.                                                    | :ref:`Health Check <elb_ug_hc_0001>`                                           |
   |                          |                                                                                                                                                                      |                                                                                |
   |                          | If a backend server is detected unhealthy, it will not receive requests from the associated load balancer, improving your service reliability.                       |                                                                                |
   +--------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------+
   | Load Balancing Algorithm | The load balancer distributes traffic based on the load balancing algorithm you have configured for the backend server group.                                        | :ref:`Load Balancing Algorithms <elb_ug_jt_0003>`                              |
   +--------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------+
   | Sticky Session           | Specifies whether to enable the sticky session option. If you enable this option, all requests from a client during one session are sent to the same backend server. | :ref:`Sticky Session <elb_ug_jt_0004>`                                         |
   +--------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------+
   | Slow Start               | Specifies whether to enable slow start. After you enable it, the load balancer linearly increases the proportion of requests to backend servers in this mode.        | :ref:`Slow Start (Dedicated Load Balancers) <en-us_topic_0000001794819209>`    |
   |                          |                                                                                                                                                                      |                                                                                |
   |                          | When the slow start duration elapses, the load balancer sends full share of requests to backend servers and exits the slow start mode.                               |                                                                                |
   |                          |                                                                                                                                                                      |                                                                                |
   |                          | .. note::                                                                                                                                                            |                                                                                |
   |                          |                                                                                                                                                                      |                                                                                |
   |                          |    Slow start is only available for HTTP and HTTPS backend server groups of dedicated load balancers.                                                                |                                                                                |
   +--------------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------+

Precautions for Creating a Backend Server Group
-----------------------------------------------

The backend protocol of the new backend server group must match the frontend protocol of the listener as described in :ref:`Table 3 <elb_ug_hdg_0001__table89265491950>`.

You can create a backend server group by referring to :ref:`Table 4 <elb_ug_hdg_0001__table779810505177>`.

.. _elb_ug_hdg_0001__table89265491950:

.. table:: **Table 3** The frontend and backend protocol

   +-----------------------------------+-----------------------------------+
   | Frontend Protocol                 | Backend Protocol                  |
   +===================================+===================================+
   | TCP                               | TCP                               |
   +-----------------------------------+-----------------------------------+
   | UDP                               | -  UDP                            |
   |                                   | -  QUIC                           |
   +-----------------------------------+-----------------------------------+
   | HTTP                              | HTTP                              |
   +-----------------------------------+-----------------------------------+
   | HTTPS                             | -  HTTP                           |
   |                                   | -  HTTPS                          |
   +-----------------------------------+-----------------------------------+

.. _elb_ug_hdg_0001__table779810505177:

.. table:: **Table 4** Creating a backend server group

   +--------------------+-------------------------------------------------------------------------------------+---+
   | Load Balancer Type | Reference                                                                           |   |
   +====================+=====================================================================================+===+
   | Dedicated          | :ref:`Creating a Backend Server Group (Dedicated Load Balancers) <elb_ug_hdg_0003>` |   |
   +--------------------+-------------------------------------------------------------------------------------+---+
