:original_name: en-us_topic_0096561504.html

.. _en-us_topic_0096561504:

Querying Load Balancers
=======================

Function
--------

This API is used to query load balancers and display them in a list.

URI
---

GET /v1.0/{project_id}/elbaas/loadbalancers

.. table:: **Table 1** Parameter description

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
   ========== ========= ====== =========================

Request
-------

-  Request parameters

   None

-  Example request

   None

Response
--------

-  Response parameters

   .. table:: **Table 2** Parameter description

      ============= ====== =======================================
      Parameter     Type   Description
      ============= ====== =======================================
      loadbalancers Array  Lists the load balancers.
      instance_num  String Specifies the number of load balancers.
      ============= ====== =======================================

   .. table:: **Table 3** **loadbalancers** parameter description

      +-----------------------+-----------------------+-----------------------------------------------------------------------------------+
      | Parameter             | Type                  | Description                                                                       |
      +=======================+=======================+===================================================================================+
      | vip_address           | String                | Specifies the private IP address of the load balancer.                            |
      +-----------------------+-----------------------+-----------------------------------------------------------------------------------+
      | update_time           | String                | Specifies the time when the listener was updated.                                 |
      +-----------------------+-----------------------+-----------------------------------------------------------------------------------+
      | create_time           | String                | Specifies the time when the listener was created.                                 |
      +-----------------------+-----------------------+-----------------------------------------------------------------------------------+
      | id                    | String                | Specifies the load balancer ID.                                                   |
      +-----------------------+-----------------------+-----------------------------------------------------------------------------------+
      | status                | String                | -  Specifies the load balancer status.                                            |
      |                       |                       | -  The value can be **ACTIVE**, **PENDING_CREATE**, or **ERROR**.                 |
      +-----------------------+-----------------------+-----------------------------------------------------------------------------------+
      | bandwidth             | Integer               | Specifies the bandwidth.                                                          |
      +-----------------------+-----------------------+-----------------------------------------------------------------------------------+
      | vpc_id                | String                | Specifies the VPC ID.                                                             |
      +-----------------------+-----------------------+-----------------------------------------------------------------------------------+
      | admin_state_up        | Integer               | -  Specifies the administrative status of the load balancer.                      |
      |                       |                       |                                                                                   |
      |                       |                       | -  The value options are as follows:                                              |
      |                       |                       |                                                                                   |
      |                       |                       |    **0**: The load balancer is disabled.                                          |
      |                       |                       |                                                                                   |
      |                       |                       |    **1**: The load balancer is running properly.                                  |
      |                       |                       |                                                                                   |
      |                       |                       |    **2**: The load balancer is frozen.                                            |
      +-----------------------+-----------------------+-----------------------------------------------------------------------------------+
      | vip_subnet_id         | String                | This parameter is unavailable now.                                                |
      +-----------------------+-----------------------+-----------------------------------------------------------------------------------+
      | type                  | String                | Specifies the network type of the load balancer. The value is **External**.       |
      +-----------------------+-----------------------+-----------------------------------------------------------------------------------+
      | name                  | String                | Specifies the load balancer name.                                                 |
      +-----------------------+-----------------------+-----------------------------------------------------------------------------------+
      | description           | String                | Description                                                                       |
      +-----------------------+-----------------------+-----------------------------------------------------------------------------------+
      | security_group_id     | String                | -  Specifies the security group ID.                                               |
      |                       |                       | -  **null** is displayed for this parameter when **type** is set to **External**. |
      +-----------------------+-----------------------+-----------------------------------------------------------------------------------+

-  Example response

   .. code-block::

      {
          "loadbalancers": [
              {
                  "vip_address": "192.144.62.114",
                  "update_time": "2015-09-14 02:34:32",
                  "create_time": "2015-09-14 02:34:32",
                  "id": "0b07acf06d243925bc24a0ac7445267a",
                  "status": "ACTIVE",
                  "bandwidth": 1,
                  "security_group_id": null,
                  "vpc_id": "f54a3ffd-7a55-4568-9e3d-f0ff2d46a107",
                  "admin_state_up": 1,
                  "vip_subnet_id": null,
                  "type": "External",
                  "name": "MY_ELB",
                  "description": null
              }
          ],
          "instance_num": "1"
      }

Status Codes
------------

-  Normal

   200

-  Abnormal

   +-------------+--------------------+----------------------------------------------------------+
   | Status Code | Message            | Description                                              |
   +=============+====================+==========================================================+
   | 400         | badRequest         | Request error.                                           |
   +-------------+--------------------+----------------------------------------------------------+
   | 401         | unauthorized       | Authentication failed.                                   |
   +-------------+--------------------+----------------------------------------------------------+
   | 403         | userDisabled       | You do not have the permission to perform the operation. |
   +-------------+--------------------+----------------------------------------------------------+
   | 404         | Not Found          | The requested page does not exist.                       |
   +-------------+--------------------+----------------------------------------------------------+
   | 500         | authFault          | Internal error.                                          |
   +-------------+--------------------+----------------------------------------------------------+
   | 503         | serviceUnavailable | Service unavailable.                                     |
   +-------------+--------------------+----------------------------------------------------------+
