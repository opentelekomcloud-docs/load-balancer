:original_name: elb_zq_hd_0007.html

.. _elb_zq_hd_0007:

Batch Updating Backend Servers
==============================

Function
--------

This API is used to update backend servers in batches.

Constraints
-----------

-  A maximum of 200 backend servers can be modified at a time.
-  Two backend servers in a backend server group cannot have the same private IP address or port number.
-  The subnet specified during server creation must be in the same VPC as the subnet from which the private IP address of the load balancer is assigned.

URI
---

PUT /v2.0/lbaas/pools/{pool_id}/members

.. table:: **Table 1** Parameter description

   ========= ========= ====== =============================================
   Parameter Mandatory Type   Description
   ========= ========= ====== =============================================
   pool_id   Yes       String Specifies the ID of the backend server group.
   ========= ========= ====== =============================================

Request
-------

.. table:: **Table 2** Request parameters

   +-----------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                                                                                                                                                                                                                                                                                                                               |
   +=================+=================+=================+===========================================================================================================================================================================================================================================================================================================================================================================================+
   | members         | Yes             | Array           | Lists the backend servers in the backend server group. If **action** is set to **add** or **replace**, see :ref:`Table 3 <elb_zq_hd_0007__en-us_topic_0000001129421786_table328016212049>` for details about the parameters. If **action** is set to **delete**, see :ref:`Table 4 <elb_zq_hd_0007__en-us_topic_0000001129421786_table182591957155011>` for details about the parameters. |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                                                                           |
   |                 |                 |                 | An empty list is supported. If **action** is set to **add**, no backend server is added to the backend server group. If **action** is set to **replace**, all backend servers are removed from the backend cloud server group. If **action** is set to **delete**, no backend server is removed.                                                                                          |
   +-----------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | action          | No              | String          | Specifies the operation type. The value can be **add**, **delete**, or **replace**. The default value is **replace**.                                                                                                                                                                                                                                                                     |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                                                                           |
   |                 |                 |                 | -  **add**: All backend servers in the request body are added to the backend server group in batches.                                                                                                                                                                                                                                                                                     |
   |                 |                 |                 | -  **delete**: All backend servers in the request are removed from the backend server group in batches.                                                                                                                                                                                                                                                                                   |
   |                 |                 |                 | -  **replace**: All backend servers in the backend server group are replaced with those in the request body.                                                                                                                                                                                                                                                                              |
   +-----------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_hd_0007__en-us_topic_0000001129421786_table328016212049:

.. table:: **Table 3** **members** parameter description

   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                                                                    |
   +=================+=================+=================+================================================================================================================================+
   | name            | No              | String          | Specifies the backend server name. The value is an empty character string by default.                                          |
   |                 |                 |                 |                                                                                                                                |
   |                 |                 |                 | The value contains a maximum of 255 characters.                                                                                |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------+
   | address         | Yes             | String          | Specifies the private IP address of the backend server. This IP address must be in the subnet specified by **subnet_id**.      |
   |                 |                 |                 |                                                                                                                                |
   |                 |                 |                 | This parameter can be set only to the IP address of the primary NIC, for example, 192.168.3.11.                                |
   |                 |                 |                 |                                                                                                                                |
   |                 |                 |                 | The value contains a maximum of 64 characters.                                                                                 |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------+
   | protocol_port   | Yes             | Integer         | Specifies the port used by the backend server. The port number ranges from 1 to 65535.                                         |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------+
   | subnet_id       | Yes             | String          | Specifies the ID of the subnet where the backend server works. The private IP address of the backend server is in this subnet. |
   |                 |                 |                 |                                                                                                                                |
   |                 |                 |                 | IPv6 subnets are not supported.                                                                                                |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------+
   | weight          | No              | Integer         | Specifies the backend server weight. The value ranges from **0** to **100**.                                                   |
   |                 |                 |                 |                                                                                                                                |
   |                 |                 |                 | If the value is **0**, the backend server will not accept new requests. The default value is **1**.                            |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_hd_0007__en-us_topic_0000001129421786_table182591957155011:

.. table:: **Table 4** **members** parameter description

   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                                                                                                                |
   +=================+=================+=================+============================================================================================================================================================================+
   | id              | Yes             | String          | Specifies the backend server ID.                                                                                                                                           |
   |                 |                 |                 |                                                                                                                                                                            |
   |                 |                 |                 | .. note::                                                                                                                                                                  |
   |                 |                 |                 |                                                                                                                                                                            |
   |                 |                 |                 |    -  The value of this parameter is not the ID of the server but an ID automatically generated for the backend server that has already associated with the load balancer. |
   |                 |                 |                 |    -  You can obtain this value by calling the API described in :ref:`Querying Backend Servers <elb_zq_hd_0002>`.                                                          |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Response
--------

None

Example Request
---------------

-  Example request 1: Adding backend servers in batches

   .. code-block:: text

      PUT https://{Endpoint}/v2.0/lbaas/pools/5a9a3e9e-d1aa-448e-af37-a70171f2a332/members

      {
          "members": [
              {
                  "subnet_id": "33d8b01a-bbe6-41f4-bc45-78a1d284d503",
                  "protocol_port": 88,
                  "name": "member-1",
                  "address": "192.168.44.11"
              },
              {
                  "subnet_id": "33d8b01a-bbe6-41f4-bc45-78a1d284d503",
                  "protocol_port": 88,
                  "name": "member-2",
                  "address": "192.168.44.12"
              },
              {
                  "subnet_id": "33d8b01a-bbe6-41f4-bc45-78a1d284d503",
                  "protocol_port": 88,
                  "name": "member-3",
                  "address": "192.168.44.13"
              }
          ],
          "action": "add"
      }

-  Example request 2: Updating backend servers in batches

   .. code-block:: text

      PUT https://{Endpoint}/v2.0/lbaas/pools/5a9a3e9e-d1aa-448e-af37-a70171f2a332/members

      {
          "members": [
              {
                  "subnet_id": "33d8b01a-bbe6-41f4-bc45-78a1d284d503",
                  "protocol_port": 88,
                  "name": "member-1",
                  "address": "192.168.44.11"
              },
              {
                  "subnet_id": "33d8b01a-bbe6-41f4-bc45-78a1d284d503",
                  "protocol_port": 88,
                  "name": "member-3",
                  "address": "192.168.44.12"
              },
              {
                  "subnet_id": "33d8b01a-bbe6-41f4-bc45-78a1d284d503",
                  "protocol_port": 88,
                  "name": "member-3",
                  "address": "192.168.44.13"
              }
          ]
      }

-  Example request 3: Removing backend servers in batches

   .. code-block:: text

      PUT https://{Endpoint}/v2.0/lbaas/pools/5a9a3e9e-d1aa-448e-af37-a70171f2a332/members

      {
          "members": [
              {
                  "id": "33d8b01a-bbe6-41f4-bc45-78a1d284d503"
              },
              {
                  "id": "33d8b01a-bbe6-41f4-bc45-78a1d284d503"
              }
          ],
          "action": "delete"
      }

Example Responses
-----------------

-  Example response 1

   None

-  Example response 2

   None

-  Example response 3

   None

Status Codes
------------

If the operation succeeds, 202 Accepted is returned. For details, see :ref:`HTTP Status Codes of Shared Load Balancers <elb_gc_0002>`.
