:original_name: elb_zq_fz_0005.html

.. _elb_zq_fz_0005:

Updating a Load Balancer
========================

Function
--------

This API is used to update the name or description of a load balancer.

URI
---

PUT /v2.0/lbaas/loadbalancers/{loadbalancer_id}

.. table:: **Table 1** Parameter description

   =============== ========= ====== ===============================
   Parameter       Mandatory Type   Description
   =============== ========= ====== ===============================
   loadbalancer_id Yes       String Specifies the load balancer ID.
   =============== ========= ====== ===============================

Request
-------

.. table:: **Table 2** Parameter description

   +--------------+-----------+--------+----------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter    | Mandatory | Type   | Description                                                                                                                                        |
   +==============+===========+========+====================================================================================================================================================+
   | loadbalancer | Yes       | Object | Specifies the load balancer. For details, see :ref:`Table 3 <elb_zq_fz_0005__en-us_topic_0141008274_en-us_topic_0096561536_table153641232163710>`. |
   +--------------+-----------+--------+----------------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_fz_0005__en-us_topic_0141008274_en-us_topic_0096561536_table153641232163710:

.. table:: **Table 3** **loadbalancer** parameter description

   +-----------------+-----------------+-----------------+-------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                 |
   +=================+=================+=================+=============================================================+
   | name            | No              | String          | Specifies the load balancer name.                           |
   |                 |                 |                 |                                                             |
   |                 |                 |                 | The value contains a maximum of 255 characters.             |
   +-----------------+-----------------+-----------------+-------------------------------------------------------------+
   | description     | No              | String          | Provides supplementary information about the load balancer. |
   |                 |                 |                 |                                                             |
   |                 |                 |                 | The value contains a maximum of 255 characters.             |
   +-----------------+-----------------+-----------------+-------------------------------------------------------------+
   | admin_state_up  | No              | Boolean         | Specifies the administrative status of the load balancer.   |
   |                 |                 |                 |                                                             |
   |                 |                 |                 | This parameter is reserved. The default value is **true**.  |
   +-----------------+-----------------+-----------------+-------------------------------------------------------------+

Response
--------

.. table:: **Table 4** Response parameters

   +--------------+--------+-------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter    | Type   | Description                                                                                                                                     |
   +==============+========+=================================================================================================================================================+
   | loadbalancer | Object | Specifies the load balancer. For details, see :ref:`Table 5 <elb_zq_fz_0005__en-us_topic_0141008274_en-us_topic_0096561536_table555616231383>`. |
   +--------------+--------+-------------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_fz_0005__en-us_topic_0141008274_en-us_topic_0096561536_table555616231383:

.. table:: **Table 5** **loadbalancer** parameter description

   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                                            |
   +=======================+=======================+========================================================================================================================================================================+
   | id                    | String                | Specifies the load balancer ID.                                                                                                                                        |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tenant_id             | String                | Specifies the ID of the project where the load balancer is used.                                                                                                       |
   |                       |                       |                                                                                                                                                                        |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                                        |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                | Specifies the load balancer name.                                                                                                                                      |
   |                       |                       |                                                                                                                                                                        |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                                        |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | description           | String                | Provides supplementary information about the load balancer.                                                                                                            |
   |                       |                       |                                                                                                                                                                        |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                                        |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | vip_subnet_id         | String                | Specifies the ID of the subnet where the load balancer works.                                                                                                          |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | vip_port_id           | String                | Specifies the ID of the port bound to the private IP address of the load balancer.                                                                                     |
   |                       |                       |                                                                                                                                                                        |
   |                       |                       | When you create a load balancer, the system automatically creates a port and associates it with a security group. However, the security group will not take effect.    |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | provider              | String                | Specifies the provider of the load balancer.                                                                                                                           |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | vip_address           | String                | Specifies the private IP address of the load balancer.                                                                                                                 |
   |                       |                       |                                                                                                                                                                        |
   |                       |                       | The value contains a maximum of 64 characters.                                                                                                                         |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | listeners             | Array                 | Lists the IDs of listeners added to the load balancer. For details, see :ref:`Table 6 <elb_zq_fz_0005__en-us_topic_0141008274_table107875111574>`.                     |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | pools                 | Array                 | Lists the IDs of backend server groups associated with the load balancer. For details, see :ref:`Table 7 <elb_zq_fz_0005__en-us_topic_0141008274_table1566642411246>`. |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | operating_status      | String                | This parameter is reserved, and its value can only be **ONLINE**.                                                                                                      |
   |                       |                       |                                                                                                                                                                        |
   |                       |                       | It specifies the operating status of the load balancer.                                                                                                                |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | provisioning_status   | String                | This parameter is reserved, and its value can only be **ACTIVE**.                                                                                                      |
   |                       |                       |                                                                                                                                                                        |
   |                       |                       | It specifies the provisioning status of the load balancer.                                                                                                             |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up        | Boolean               | Specifies the administrative status of the load balancer.                                                                                                              |
   |                       |                       |                                                                                                                                                                        |
   |                       |                       | This parameter is reserved. The value can be **true** or **false**.                                                                                                    |
   |                       |                       |                                                                                                                                                                        |
   |                       |                       | -  **true**: Enabled                                                                                                                                                   |
   |                       |                       | -  **false**: Disabled                                                                                                                                                 |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tags                  | Array                 | Lists load balancer tags.                                                                                                                                              |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | created_at            | String                | Specifies the time when the load balancer was created.                                                                                                                 |
   |                       |                       |                                                                                                                                                                        |
   |                       |                       | The UTC time is in *YYYY-MM-DDTHH:MM:SS* format.                                                                                                                       |
   |                       |                       |                                                                                                                                                                        |
   |                       |                       | The value contains a maximum of 19 characters.                                                                                                                         |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | updated_at            | String                | Specifies the time when the load balancer was updated.                                                                                                                 |
   |                       |                       |                                                                                                                                                                        |
   |                       |                       | The UTC time is in *YYYY-MM-DDTHH:MM:SS* format.                                                                                                                       |
   |                       |                       |                                                                                                                                                                        |
   |                       |                       | The value contains a maximum of 19 characters.                                                                                                                         |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_fz_0005__en-us_topic_0141008274_table107875111574:

.. table:: **Table 6** **listeners** parameter description

   ========= ====== ============================================
   Parameter Type   Description
   ========= ====== ============================================
   id        String Specifies the ID of the associated listener.
   ========= ====== ============================================

.. _elb_zq_fz_0005__en-us_topic_0141008274_table1566642411246:

.. table:: **Table 7** **pools** parameter description

   +-----------+--------+----------------------------------------------------------+
   | Parameter | Type   | Description                                              |
   +===========+========+==========================================================+
   | id        | String | Specifies the ID of the associated backend server group. |
   +-----------+--------+----------------------------------------------------------+

Example Request
---------------

-  Example request: Modifying the load balancer name and description

   .. code-block:: text

      PUT https://{Endpoint}/v2.0/lbaas/loadbalancers/1e11b74e-30b7-4b78-b09b-84aec4a04487

      {
          "loadbalancer": {
              "name": "lb_update_test",
              "description": "lb update test"
          }
      }

Example Response
----------------

-  Example response

   .. code-block::

      {
        "loadbalancer": {
          "description": "simple lb2",
          "admin_state_up": true,
          "tenant_id": "145483a5107745e9b3d80f956713e6a3",

          "provisioning_status": "ACTIVE",
          "vip_subnet_id": "823d5866-6e30-45c2-9b1a-a1ebc3757fdb",
          "listeners": [
            {
              "id": "37ffe679-08ef-436e-b6bd-cf66fb4c3de2"
            }
          ],
          "vip_address": "192.172.1.68",
          "vip_port_id": "f42e3019-67f7-4d2a-8d1c-af49e7c22fa6",
          "tags": [],
          "provider": "vlb",
          "pools": [
            {
              "id": "75c4f2d4-a213-4408-9fa8-d64708e8d1df"
            }
          ],
          "id": "c32a9f9a-0cc6-4f38-bb9c-cde79a533c19",
          "operating_status": "ONLINE",
          "name": "loadbalancer-test2",
          "created_at": "2018-07-25T01:54:13",
          "updated_at": "2018-07-25T01:54:14"
        }
      }

Status Code
-----------

For details, see :ref:`Status Codes <elb_gc_1102>`.
