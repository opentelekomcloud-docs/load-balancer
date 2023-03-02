:original_name: elb_zq_hd_0001.html

.. _elb_zq_hd_0001:

Adding a Backend Server
=======================

Function
--------

This API is used to add a backend server to a specific backend server group. After a backend server group is added to a listener, traffic is distributed to backend servers in this server group using the specified load balancing algorithm.

Constraints
-----------

Two backend servers in a backend server group cannot have the same private IP address or port number.

The subnet specified during server creation must be in the same VPC as the subnet from which the private IP address of the load balancer is assigned.

URI
---

POST /v2.0/lbaas/pools/{pool_id}/members

.. table:: **Table 1** Parameter description

   ========= ========= ====== =============================================
   Parameter Mandatory Type   Description
   ========= ========= ====== =============================================
   pool_id   Yes       String Specifies the ID of the backend server group.
   ========= ========= ====== =============================================

Request
-------

.. table:: **Table 2** Parameter description

   +-----------+-----------+--------+----------------------------------------------------------------------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                                                                                |
   +===========+===========+========+============================================================================================================================+
   | member    | Yes       | Object | Specifies the backend server. For details, see :ref:`Table 3 <elb_zq_hd_0001__en-us_topic_0096561556_table1686816641616>`. |
   +-----------+-----------+--------+----------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_hd_0001__en-us_topic_0096561556_table1686816641616:

.. table:: **Table 3** **member** parameter description

   +-----------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                                                               |
   +=================+=================+=================+===========================================================================================================================+
   | tenant_id       | No              | String          | Specifies the ID of the project where the backend server is used.                                                         |
   |                 |                 |                 |                                                                                                                           |
   |                 |                 |                 | The value must be the same as the value of **project_id** in the token.                                                   |
   |                 |                 |                 |                                                                                                                           |
   |                 |                 |                 | The value contains a maximum of 255 characters.                                                                           |
   +-----------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------+
   | name            | No              | String          | Specifies the backend server name. The value is an empty character string by default.                                     |
   |                 |                 |                 |                                                                                                                           |
   |                 |                 |                 | The value contains a maximum of 255 characters.                                                                           |
   +-----------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------+
   | address         | Yes             | String          | Specifies the private IP address of the backend server. This IP address must be in the subnet specified by **subnet_id**. |
   |                 |                 |                 |                                                                                                                           |
   |                 |                 |                 | This parameter can be set only to the IP address of the primary NIC, for example, 192.168.3.11.                           |
   |                 |                 |                 |                                                                                                                           |
   |                 |                 |                 | The value contains a maximum of 64 characters.                                                                            |
   +-----------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------+
   | protocol_port   | Yes             | Integer         | Specifies the port used by the backend server. The port number ranges from 1 to 65535.                                    |
   +-----------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------+
   | subnet_id       | Yes             | String          | Specifies the ID of the subnet where the backend server works.                                                            |
   |                 |                 |                 |                                                                                                                           |
   |                 |                 |                 | The private IP address of the backend server is in this subnet.                                                           |
   |                 |                 |                 |                                                                                                                           |
   |                 |                 |                 | Only IPv4 subnets are supported.                                                                                          |
   +-----------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up  | No              | Boolean         | Specifies the administrative status of the backend server.                                                                |
   |                 |                 |                 |                                                                                                                           |
   |                 |                 |                 | This parameter is reserved, and the default value is **true**.                                                            |
   +-----------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------+
   | weight          | No              | Integer         | Specifies the backend server weight. The value ranges from **0** to **100**.                                              |
   |                 |                 |                 |                                                                                                                           |
   |                 |                 |                 | If the value is **0**, the backend server will not accept new requests. The default value is **1**.                       |
   +-----------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------+

Response
--------

.. table:: **Table 4** Response parameters

   +-----------+--------+----------------------------------------------------------------------------------------------------------------------------+
   | Parameter | Type   | Description                                                                                                                |
   +===========+========+============================================================================================================================+
   | member    | Object | Specifies the backend server. For details, see :ref:`Table 5 <elb_zq_hd_0001__en-us_topic_0096561556_table1096713051618>`. |
   +-----------+--------+----------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_hd_0001__en-us_topic_0096561556_table1096713051618:

.. table:: **Table 5** **member** parameter description

   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                            |
   +=======================+=======================+========================================================================================================================================================+
   | id                    | String                | Specifies the backend server ID.                                                                                                                       |
   |                       |                       |                                                                                                                                                        |
   |                       |                       | .. note::                                                                                                                                              |
   |                       |                       |                                                                                                                                                        |
   |                       |                       |    The value of this parameter is not the ID of server. It is the ID automatically generated for the backend server associated with the load balancer. |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tenant_id             | String                | Specifies the ID of the project where the backend server is used.                                                                                      |
   |                       |                       |                                                                                                                                                        |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                        |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                | Specifies the backend server name.                                                                                                                     |
   |                       |                       |                                                                                                                                                        |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                        |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
   | address               | String                | Specifies the private IP address of the backend server. This IP address must be in the subnet specified by **subnet_id**.                              |
   |                       |                       |                                                                                                                                                        |
   |                       |                       | This parameter can be set only to the IP address of the primary NIC, for example, 192.168.3.11.                                                        |
   |                       |                       |                                                                                                                                                        |
   |                       |                       | The value contains a maximum of 64 characters.                                                                                                         |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
   | protocol_port         | Integer               | Specifies the port used by the backend server. The port number ranges from 1 to 65535.                                                                 |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
   | subnet_id             | String                | Specifies the ID of the subnet where the backend server works. The private IP address of the backend server is in this subnet.                         |
   |                       |                       |                                                                                                                                                        |
   |                       |                       | IPv6 subnets are not supported.                                                                                                                        |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up        | Boolean               | Specifies the administrative status of the backend server.                                                                                             |
   |                       |                       |                                                                                                                                                        |
   |                       |                       | This parameter is reserved. The value can be **true** or **false**.                                                                                    |
   |                       |                       |                                                                                                                                                        |
   |                       |                       | -  **true**: Enabled                                                                                                                                   |
   |                       |                       | -  **false**: Disabled                                                                                                                                 |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
   | weight                | Integer               | Specifies the backend server weight. The value ranges from **0** to **100**.                                                                           |
   |                       |                       |                                                                                                                                                        |
   |                       |                       | If the value is **0**, the backend server will not accept new requests. The default value is **1**.                                                    |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
   | operating_status      | String                | Specifies the health check result of the backend server. The value can be one of the following:                                                        |
   |                       |                       |                                                                                                                                                        |
   |                       |                       | -  **ONLINE**: The backend server is running normally.                                                                                                 |
   |                       |                       | -  **NO_MONITOR**: No health check is configured for the backend server group that the backend server belongs to.                                      |
   |                       |                       | -  **OFFLINE**: The cloud server used as the backend server is stopped or does not exist.                                                              |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+

Example Request
---------------

-  .. _elb_zq_hd_0001__en-us_topic_0096561556_li1069222685516:

   Step 1: Query the subnet ID and IP address using the server ID. **device_id** in the request indicates the server ID. Obtain the values of **subnet_id** and **ip_address** of the primary NIC (the port for which **primary_interface** is **true**) in the response body.

   .. code-block:: text

      GET https://{VPCEndpoint}/v2.0/ports?device_id=f738c464-b5c2-45df-86c0-7f436620cd54

   Example response

   .. code-block::

      {
          "ports": [
              {
                  "id": "94971c39-46f0-443a-85e8-31cb7497c78e",
                  "name": "",
                  "status": "ACTIVE",
                  "admin_state_up": true,
                  "fixed_ips": [
                      {
                          "subnet_id": "33d8b01a-bbe6-41f4-bc45-78a1d284d503",
                          "ip_address": "192.168.44.11"
                      }
                  ],
                  "mac_address": "fa:16:3e:5c:d2:57",
                  "network_id": "1b76b9c2-9b7e-4ced-81bd-d13f7389d7c9",
                  "tenant_id": "04dd36f978800fe22f9bc00bea090736",
                  "project_id": "04dd36f978800fe22f9bc00bea090736",
                  "device_id": "f738c464-b5c2-45df-86c0-7f436620cd54",
                  "device_owner": "compute:xx-xxxx-4a",
                  "security_groups": [
                      "a10dfc31-0055-4b84-b36e-1291b918125c",
                      "7a233393-5be2-4dff-8360-1558dd950f6e"
                  ],
                  "extra_dhcp_opts": [],
                  "allowed_address_pairs": [],
                  "binding:vnic_type": "normal",
                  "binding:vif_details": {
                      "primary_interface": true
                  },
                  "binding:profile": {},
                  "port_security_enabled": true,
                  "created_at": "2019-11-12T17:17:51",
                  "updated_at": "2019-11-12T17:17:51"
              }
          ]
      }

-  Step 2: Use the subnet ID and IP address obtained in :ref:`▪ Step 1 <elb_zq_hd_0001__en-us_topic_0096561556_li1069222685516>` to add a backend server.

   .. code-block:: text

      POST https://{Endpoint}/v2.0/lbaas/pools/5a9a3e9e-d1aa-448e-af37-a70171f2a332/members

      {
          "member": {
              "subnet_id": "33d8b01a-bbe6-41f4-bc45-78a1d284d503",
              "protocol_port": 88,
              "name": "member-jy-tt-1",
              "address": "192.168.44.11"
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
