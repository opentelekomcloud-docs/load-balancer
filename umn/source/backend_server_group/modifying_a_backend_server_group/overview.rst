:original_name: elb_ug_hdg_0005_00.html

.. _elb_ug_hdg_0005_00:

Overview
========

After a backend server group is created, you can modify its health check settings and basic information.

Health Check
------------

If backend servers have to handle large number of requests, frequent health checks may overload the backend servers and cause them to respond slowly. To address this problem, you can prolong the health check interval or use TCP or UDP instead of HTTP. You can also disable health check. If you choose to disable health check, requests may be routed to unhealthy servers, and service interruptions may occur.

For details about the health check, see :ref:`Health Check <elb_ug_hc_0001>`.

For details about how to modify health check settings, see :ref:`Modifying Health Check Settings <en-us_topic_0000001747380572>`.

Basic Information
-----------------

You can modify the basic information of a backend server group listed in :ref:`Table 1 <elb_ug_hdg_0005_00__en-us_topic_0000001462321373_table52021931819>`.

.. _elb_ug_hdg_0005_00__en-us_topic_0000001462321373_table52021931819:

.. table:: **Table 1** Basic information that can be modified

   +--------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
   | Parameter                | Allowed Operations                                                                                                                                    |                       |
   +==========================+=======================================================================================================================================================+=======================+
   | Name                     | Change the name by performing the operations in :ref:`Changing the Load Balancing Algorithm <elb_ug_hdg_0005_02>`.                                    |                       |
   +--------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
   | Load Balancing Algorithm | Change the load balancing algorithm by performing the operations in :ref:`Changing the Load Balancing Algorithm <elb_ug_hdg_0005_02>`.                |                       |
   |                          |                                                                                                                                                       |                       |
   |                          | For details about load balancing algorithms, see :ref:`Load Balancing Algorithms <elb_ug_jt_0003>`.                                                   |                       |
   +--------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
   | Sticky Session           | Enable or disable sticky session by performing the operations in :ref:`Modifying Sticky Session Settings <elb_ug_hdg_0005_03>`.                       |                       |
   |                          |                                                                                                                                                       |                       |
   |                          | For details about the sticky session function, see :ref:`Sticky Session <elb_ug_jt_0004>`.                                                            |                       |
   +--------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
   | Slow Start               | Enable or disable slow start by performing the operations in :ref:`Modifying Slow Start Settings (Dedicated Load Balancers) <elb_ug_hdg_0005_04>`.    |                       |
   |                          |                                                                                                                                                       |                       |
   |                          | For details about the slow start function, see :ref:`Slow Start (Dedicated Load Balancers) <en-us_topic_0000001794819209>`.                           |                       |
   +--------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
   | Description              | Change the description of the backend server group by performing the operations in :ref:`Changing the Load Balancing Algorithm <elb_ug_hdg_0005_02>`. |                       |
   +--------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
