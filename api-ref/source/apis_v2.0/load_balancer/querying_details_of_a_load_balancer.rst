:original_name: elb_zq_fz_0003.html

.. _elb_zq_fz_0003:

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

   +--------------+--------+---------------------------------------------------------------------------------------------------------------------------+
   | Parameter    | Type   | Description                                                                                                               |
   +==============+========+===========================================================================================================================+
   | loadbalancer | Object | Specifies the load balancer. For details, see :ref:`Table 3 <elb_zq_fz_0003__en-us_topic_0096561532_table1943718352380>`. |
   +--------------+--------+---------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_fz_0003__en-us_topic_0096561532_table1943718352380:

.. table:: **Table 3** **loadbalancer** parameter description

   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                     |
   +=======================+=======================+=================================================================================================================================================+
   | id                    | String                | Specifies the load balancer ID.                                                                                                                 |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------+
   | tenant_id             | String                | Specifies the ID of the project where the load balancer is used.                                                                                |
   |                       |                       |                                                                                                                                                 |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                 |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                | Specifies the load balancer name.                                                                                                               |
   |                       |                       |                                                                                                                                                 |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                 |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------+
   | description           | String                | Provides supplementary information about the load balancer.                                                                                     |
   |                       |                       |                                                                                                                                                 |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                 |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------+
   | vip_subnet_id         | String                | Specifies the ID of the subnet where the load balancer works.                                                                                   |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------+
   | vip_port_id           | String                | Specifies the ID of the port bound to the private IP address of the load balancer.                                                              |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------+
   | provider              | String                | Specifies the provider of the load balancer.                                                                                                    |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------+
   | vip_address           | String                | Specifies the private IP address of the load balancer.                                                                                          |
   |                       |                       |                                                                                                                                                 |
   |                       |                       | The value contains a maximum of 64 characters.                                                                                                  |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------+
   | listeners             | Array                 | Lists the IDs of listeners added to the load balancer. For details, see :ref:`Table 4 <elb_zq_fz_0003__table107875111574>`.                     |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------+
   | pools                 | Array                 | Lists the IDs of backend server groups associated with the load balancer. For details, see :ref:`Table 5 <elb_zq_fz_0003__table1566642411246>`. |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------+
   | operating_status      | String                | Specifies the operating status of the load balancer.                                                                                            |
   |                       |                       |                                                                                                                                                 |
   |                       |                       | The value can be **ONLINE**, **OFFLINE**, **DEGRADED**, **DISABLED**, or **NO_MONITOR**.                                                        |
   |                       |                       |                                                                                                                                                 |
   |                       |                       | This parameter is reserved. The default value is **ONLINE**.                                                                                    |
   |                       |                       |                                                                                                                                                 |
   |                       |                       | The value contains a maximum of 16 characters.                                                                                                  |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------+
   | provisioning_status   | String                | Specifies the provisioning status of the load balancer.                                                                                         |
   |                       |                       |                                                                                                                                                 |
   |                       |                       | The value can be **ACTIVE**, **PENDING_CREATE**, or **ERROR**.                                                                                  |
   |                       |                       |                                                                                                                                                 |
   |                       |                       | This parameter is reserved. The default value is **ACTIVE**.                                                                                    |
   |                       |                       |                                                                                                                                                 |
   |                       |                       | The value contains a maximum of 16 characters.                                                                                                  |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up        | Boolean               | Specifies the administrative status of the load balancer.                                                                                       |
   |                       |                       |                                                                                                                                                 |
   |                       |                       | This parameter is reserved. The default value is **true**.                                                                                      |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------+
   | tags                  | Array                 | Lists the tags added to the load balancer.                                                                                                      |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------+
   | created_at            | String                | Specifies the time when the load balancer was created.                                                                                          |
   |                       |                       |                                                                                                                                                 |
   |                       |                       | The UTC time is in *YYYY-MM-DDTHH:MM:SS* format.                                                                                                |
   |                       |                       |                                                                                                                                                 |
   |                       |                       | The value contains a maximum of 19 characters.                                                                                                  |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------+
   | updated_at            | String                | Specifies the time when the load balancer was updated.                                                                                          |
   |                       |                       |                                                                                                                                                 |
   |                       |                       | The UTC time is in *YYYY-MM-DDTHH:MM:SS* format.                                                                                                |
   |                       |                       |                                                                                                                                                 |
   |                       |                       | The value contains a maximum of 19 characters.                                                                                                  |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_fz_0003__table107875111574:

.. table:: **Table 4** **listeners** parameter description

   ========= ====== ============================================
   Parameter Type   Description
   ========= ====== ============================================
   id        String Specifies the ID of the associated listener.
   ========= ====== ============================================

.. _elb_zq_fz_0003__table1566642411246:

.. table:: **Table 5** **pools** parameter description

   +-----------+--------+----------------------------------------------------------+
   | Parameter | Type   | Description                                              |
   +===========+========+==========================================================+
   | id        | String | Specifies the ID of the associated backend server group. |
   +-----------+--------+----------------------------------------------------------+

Example Request
---------------

-  Example request 1: Querying details of a load balancer using its ID

-  Example request 2: Querying the EIP bound to the load balancer. For details, see section "Querying EIPs" in the *Elastic IP Address API Reference*.

   .. code-block:: text

      GET https://{EIP_Endpoint}/v1/{project_id}/publicips?port_id={vip_port_id}

   **vip_port_id** is the value of **vip_port_id** for the load balancer.

Example Response
----------------

-  Example response 1

   .. code-block::

      {
          "loadbalancer": {
              "description": "",
              "admin_state_up": true,
              "tenant_id": "1867112d054b427e808cc6096d8193a1",

              "provisioning_status": "ACTIVE",
              "vip_subnet_id": "4f5e8efe-fbbe-405e-b48c-a41202ef697c",
              "listeners": [
                  {
                      "id": "09e64049-2ab0-4763-a8c5-f4207875dc3e"
                  }
              ],
              "vip_address": "192.168.2.4",
              "vip_port_id": "c7157e7a-036a-42ca-8474-100be22e3727",
              "provider": "vlb",
              "pools": [
                  {
                      "id": "b7e53dbd-62ab-4505-a280-5c066078a5c9"
                  }
              ],
              "id": "3d77894d-2ffe-4411-ac0a-0d57689779b8",
              "operating_status": "ONLINE",
              "tags": [],
              "name": "lb-2",
              "created_at": "2018-07-25T01:54:13",
              "updated_at": "2018-07-25T01:54:14"
          }
      }

Status Codes
------------

See :ref:`HTTP Status Codes of Shared Load Balancers <elb_gc_0002>`.
