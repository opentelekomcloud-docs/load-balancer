:original_name: en-us_topic_0141008271.html

.. _en-us_topic_0141008271:

Querying Details of a Load Balancer
===================================

Function
--------

This API is used to query details about a load balancer using its ID. You can also query the EIP bound to the load balancer based on the value of **vip_port_id**.

URI
---

GET /v2.0/lbaas/loadbalancers/{loadbalancer_id}

.. table:: **Table 1** Parameter description

   =============== ========= ====== ===============================
   Parameter       Mandatory Type   Description
   =============== ========= ====== ===============================
   loadbalancer_id Yes       String Specifies the load balancer ID.
   =============== ========= ====== ===============================

Request
-------

None

Response
--------

.. table:: **Table 2** Parameter description

   +--------------+--------+-----------------------------------------------------------------------------------------------------------------------------------+
   | Parameter    | Type   | Description                                                                                                                       |
   +==============+========+===================================================================================================================================+
   | loadbalancer | Object | Specifies the load balancer. For details, see :ref:`Table 3 <en-us_topic_0141008271__en-us_topic_0096561532_table1943718352380>`. |
   +--------------+--------+-----------------------------------------------------------------------------------------------------------------------------------+

.. _en-us_topic_0141008271__en-us_topic_0096561532_table1943718352380:

.. table:: **Table 3** **loadbalancer** parameter description

   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                             |
   +=======================+=======================+=========================================================================================================================================================+
   | id                    | String                | Specifies the load balancer ID.                                                                                                                         |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tenant_id             | String                | Specifies the ID of the project where the load balancer is used.                                                                                        |
   |                       |                       |                                                                                                                                                         |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                         |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                | Specifies the load balancer name.                                                                                                                       |
   |                       |                       |                                                                                                                                                         |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                         |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
   | description           | String                | Provides supplementary information about the load balancer.                                                                                             |
   |                       |                       |                                                                                                                                                         |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                         |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
   | vip_subnet_id         | String                | Specifies the ID of the subnet where the load balancer works.                                                                                           |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
   | vip_port_id           | String                | Specifies the ID of the port bound to the private IP address of the load balancer.                                                                      |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
   | provider              | String                | Specifies the provider of the load balancer.                                                                                                            |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
   | vip_address           | String                | Specifies the private IP address of the load balancer.                                                                                                  |
   |                       |                       |                                                                                                                                                         |
   |                       |                       | The value contains a maximum of 64 characters.                                                                                                          |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
   | listeners             | Array                 | Lists the IDs of listeners added to the load balancer. For details, see :ref:`Table 4 <en-us_topic_0141008271__table107875111574>`.                     |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
   | pools                 | Array                 | Lists the IDs of backend server groups associated with the load balancer. For details, see :ref:`Table 5 <en-us_topic_0141008271__table1566642411246>`. |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
   | operating_status      | String                | Specifies the operating status of the load balancer.                                                                                                    |
   |                       |                       |                                                                                                                                                         |
   |                       |                       | The value can be **ONLINE**, **OFFLINE**, **DEGRADED**, **DISABLED**, or **NO_MONITOR**.                                                                |
   |                       |                       |                                                                                                                                                         |
   |                       |                       | This parameter is reserved. The default value is **ONLINE**.                                                                                            |
   |                       |                       |                                                                                                                                                         |
   |                       |                       | The value contains a maximum of 16 characters.                                                                                                          |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
   | provisioning_status   | String                | Specifies the provisioning status of the load balancer.                                                                                                 |
   |                       |                       |                                                                                                                                                         |
   |                       |                       | The value can be **ACTIVE**, **PENDING_CREATE**, or **ERROR**.                                                                                          |
   |                       |                       |                                                                                                                                                         |
   |                       |                       | This parameter is reserved. The default value is **ACTIVE**.                                                                                            |
   |                       |                       |                                                                                                                                                         |
   |                       |                       | The value contains a maximum of 16 characters.                                                                                                          |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up        | Boolean               | Specifies the administrative status of the load balancer.                                                                                               |
   |                       |                       |                                                                                                                                                         |
   |                       |                       | This parameter is reserved. The default value is **true**.                                                                                              |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tags                  | Array                 | Lists the tags added to the load balancer.                                                                                                              |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
   | created_at            | String                | Specifies the time when the load balancer was created.                                                                                                  |
   |                       |                       |                                                                                                                                                         |
   |                       |                       | The UTC time is in *YYYY-MM-DDTHH:MM:SS* format.                                                                                                        |
   |                       |                       |                                                                                                                                                         |
   |                       |                       | The value contains a maximum of 19 characters.                                                                                                          |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
   | updated_at            | String                | Specifies the time when the load balancer was updated.                                                                                                  |
   |                       |                       |                                                                                                                                                         |
   |                       |                       | The UTC time is in *YYYY-MM-DDTHH:MM:SS* format.                                                                                                        |
   |                       |                       |                                                                                                                                                         |
   |                       |                       | The value contains a maximum of 19 characters.                                                                                                          |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _en-us_topic_0141008271__table107875111574:

.. table:: **Table 4** **listeners** parameter description

   ========= ====== ============================================
   Parameter Type   Description
   ========= ====== ============================================
   id        String Specifies the ID of the associated listener.
   ========= ====== ============================================

.. _en-us_topic_0141008271__table1566642411246:

.. table:: **Table 5** **pools** parameter description

   +-----------+--------+----------------------------------------------------------+
   | Parameter | Type   | Description                                              |
   +===========+========+==========================================================+
   | id        | String | Specifies the ID of the associated backend server group. |
   +-----------+--------+----------------------------------------------------------+

Status Codes
------------

See :ref:`HTTP Status Codes of Shared Load Balancers <elb_gc_0002>`.
