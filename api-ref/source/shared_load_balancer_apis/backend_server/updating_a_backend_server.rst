:original_name: elb_zq_hd_0004.html

.. _elb_zq_hd_0004:

Updating a Backend Server
=========================

Function
--------

This API is used to update a backend server. You can modify its name and weight. You can set a larger weight for backend servers that can receive more traffic.

Constraints
-----------

If the provisioning status of the associated load balancer is not **ACTIVE**, the backend server cannot be updated.

URI
---

PUT /v2.0/lbaas/pools/{pool_id}/members/{member_id}

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

.. table:: **Table 2** Parameter description

   +-----------+-----------+--------+--------------------------------------------------------------------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                                                                              |
   +===========+===========+========+==========================================================================================================================+
   | member    | Yes       | Object | Specifies the backend server. For details, see :ref:`Table 3 <elb_zq_hd_0004__en-us_topic_0096561557_table86692915171>`. |
   +-----------+-----------+--------+--------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_hd_0004__en-us_topic_0096561557_table86692915171:

.. table:: **Table 3** **member** parameter description

   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                                         |
   +=================+=================+=================+=====================================================================================================+
   | name            | No              | String          | Specifies the backend server name.                                                                  |
   |                 |                 |                 |                                                                                                     |
   |                 |                 |                 | The value contains a maximum of 255 characters.                                                     |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------+
   | admin_state_up  | No              | Boolean         | Specifies the administrative status of the backend server.                                          |
   |                 |                 |                 |                                                                                                     |
   |                 |                 |                 | This parameter is reserved, and the default value is **true**.                                      |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------+
   | weight          | No              | Integer         | Specifies the backend server weight. The value ranges from **0** to **100**.                        |
   |                 |                 |                 |                                                                                                     |
   |                 |                 |                 | If the value is **0**, the backend server will not accept new requests. The default value is **1**. |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------+

Response
--------

.. table:: **Table 4** Response parameters

   +-----------+--------+---------------------------------------------------------------------------------------------------------------------------+
   | Parameter | Type   | Description                                                                                                               |
   +===========+========+===========================================================================================================================+
   | member    | Object | Specifies the backend server. For details, see :ref:`Table 5 <elb_zq_hd_0004__en-us_topic_0096561557_table165363113183>`. |
   +-----------+--------+---------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_hd_0004__en-us_topic_0096561557_table165363113183:

.. table:: **Table 5** **member** parameter description

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

-  Example request: Updating the name and weight of a backend server

   .. code-block:: text

      PUT https://{Endpoint}/v2.0/lbaas/pools/5a9a3e9e-d1aa-448e-af37-a70171f2a332/members/c0042496-e220-44f6-914b-e6ca33bab503

      {
          "member": {
              "name": "member create test",
              "weight": 10
          }
      }

Example Response
----------------

-  Example response

   .. code-block::

      {
          "member": {
              "name": "member-jy-tt-1",
              "weight": 1,
              "admin_state_up": true,
              "subnet_id": "33d8b01a-bbe6-41f4-bc45-78a1d284d503",
              "tenant_id": "145483a5107745e9b3d80f956713e6a3",
              "address": "192.168.44.11",
              "protocol_port": 88,
              "operating_status": "ONLINE",
              "id": "c0042496-e220-44f6-914b-e6ca33bab503"
          }
      }

Status Code
-----------

For details, see :ref:`Status Codes <elb_gc_1102>`.
