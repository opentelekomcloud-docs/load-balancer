:original_name: elb_zq_hd_0003.html

.. _elb_zq_hd_0003:

Querying Details of a Backend Server
====================================

Function
--------

This API is used to query details about a backend server.

URI
---

GET /v2.0/lbaas/pools/{pool_id}/members/{member_id}

.. table:: **Table 1** Parameter description

   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                                                                                                                |
   +=================+=================+=================+============================================================================================================================================================================+
   | pool_id         | Yes             | String          | Specifies the ID of the backend server group.                                                                                                                              |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | member_id       | Yes             | String          | Specifies the backend server ID.                                                                                                                                           |
   |                 |                 |                 |                                                                                                                                                                            |
   |                 |                 |                 | .. note::                                                                                                                                                                  |
   |                 |                 |                 |                                                                                                                                                                            |
   |                 |                 |                 |    -  The value of this parameter is not the ID of the server but an ID automatically generated for the backend server that has already associated with the load balancer. |
   |                 |                 |                 |    -  You can obtain this value by calling the API described in :ref:`Querying Backend Servers <elb_zq_hd_0002>`.                                                          |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Request
-------

None

Response
--------

.. _elb_zq_hd_0003__en-us_topic_0096561555_en-us_topic_0049139656_table63335993:

.. table:: **Table 2** Response parameters

   +-----------+--------+-------------------------------------------------------------------------------------------------------------------------+
   | Parameter | Type   | Description                                                                                                             |
   +===========+========+=========================================================================================================================+
   | member    | Object | Lists the backend servers. For details, see :ref:`Table 3 <elb_zq_hd_0003__en-us_topic_0096561555_table1080991113150>`. |
   +-----------+--------+-------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_hd_0003__en-us_topic_0096561555_table1080991113150:

.. table:: **Table 3** **member** parameter description

   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                                             |
   +=======================+=======================+=========================================================================================================================================================================+
   | id                    | String                | Specifies the backend server ID.                                                                                                                                        |
   |                       |                       |                                                                                                                                                                         |
   |                       |                       | .. note::                                                                                                                                                               |
   |                       |                       |                                                                                                                                                                         |
   |                       |                       |    The value of this parameter is not the ID of the server but an ID automatically generated for the backend server that has already associated with the load balancer. |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tenant_id             | String                | Specifies the ID of the project where the backend server is used.                                                                                                       |
   |                       |                       |                                                                                                                                                                         |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                                         |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                | Specifies the backend server name.                                                                                                                                      |
   |                       |                       |                                                                                                                                                                         |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                                         |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | address               | String                | Specifies the private IP address of the backend server. This IP address must be in the subnet specified by **subnet_id**.                                               |
   |                       |                       |                                                                                                                                                                         |
   |                       |                       | This parameter can be set only to the IP address of the primary NIC, for example, 192.168.3.11.                                                                         |
   |                       |                       |                                                                                                                                                                         |
   |                       |                       | The value contains a maximum of 64 characters.                                                                                                                          |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | protocol_port         | Integer               | Specifies the port used by the backend server. The port number ranges from 1 to 65535.                                                                                  |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | subnet_id             | String                | Specifies the ID of the subnet where the backend server works. The private IP address of the backend server is in this subnet.                                          |
   |                       |                       |                                                                                                                                                                         |
   |                       |                       | IPv6 subnets are not supported.                                                                                                                                         |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up        | Boolean               | Specifies the administrative status of the backend server.                                                                                                              |
   |                       |                       |                                                                                                                                                                         |
   |                       |                       | This parameter is reserved. The value can be **true** or **false**.                                                                                                     |
   |                       |                       |                                                                                                                                                                         |
   |                       |                       | -  **true**: Enabled                                                                                                                                                    |
   |                       |                       | -  **false**: Disabled                                                                                                                                                  |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | weight                | Integer               | Specifies the backend server weight. The value ranges from **0** to **100**.                                                                                            |
   |                       |                       |                                                                                                                                                                         |
   |                       |                       | If the value is **0**, the backend server will not accept new requests. The default value is **1**.                                                                     |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | operating_status      | String                | Specifies the health check result of the backend server. The value can be one of the following:                                                                         |
   |                       |                       |                                                                                                                                                                         |
   |                       |                       | -  **ONLINE**: The backend server is running normally.                                                                                                                  |
   |                       |                       | -  **NO_MONITOR**: No health check is configured for the backend server group that the backend server belongs to.                                                       |
   |                       |                       | -  **OFFLINE**: The cloud server used as the backend server is stopped or does not exist.                                                                               |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Example Request
---------------

-  Example request: Querying details of a backend server

   .. code-block:: text

      GET https://{Endpoint}/v2.0/lbaas/pools/5a9a3e9e-d1aa-448e-af37-a70171f2a332/members/cf024846-7516-4e3a-b0fb-6590322c836f

Example Response
----------------

-  Example response

   .. code-block::

      {
          "member": {
              "name": "",
              "weight": 1,
              "admin_state_up": true,
              "subnet_id": "823d5866-6e30-45c2-9b1a-a1ebc3757fdb",
              "tenant_id": "145483a5107745e9b3d80f956713e6a3",

              "address": "192.172.3.100",
              "protocol_port": 8080,
              "operating_status": "ONLINE",
              "id": "e58f5bfa-0e46-4bc5-951c-8473d3e5f24a"
          }
      }

Status Code
-----------

For details, see :ref:`Status Codes <elb_gc_1102>`.
