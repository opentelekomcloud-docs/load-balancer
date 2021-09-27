===========
Pool Member
===========

Adding a Backend Server
=======================

Function
^^^^^^^^

This API is used to add a backend server to a specific backend server group.
After a backend server group is added to a listener, traffic is distributed to
backend servers in this server group using the specified load balancing
algorithm.

Constraints
^^^^^^^^^^^

Two backend servers in a backend server group cannot have the same private IP
address or port number.

The subnet specified during server creation must be in the same VPC as the
subnet from which the private IP address of the load balancer is assigned.

URI
^^^

POST /v2.0/lbaas/pools/{pool_id}/members

.. table:: **Table 1** Parameter description

   ========= ========= ====== =============================================
   Parameter Mandatory Type   Description
   ========= ========= ====== =============================================
   pool_id   Yes       String Specifies the ID of the backend server group.
   ========= ========= ====== =============================================

Request
^^^^^^^

.. _smc_t2:
.. table:: **Table 2** Parameter description

   +-----------+-----------+--------+--------------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                        |
   +===========+===========+========+====================================================================+
   | member    | Yes       | Object | Specifies the backend server. For details, see :ref:`smc_t3`.      |
   +-----------+-----------+--------+--------------------------------------------------------------------+

.. _smc_t3:
.. table:: **Table 3** **member** parameter description

   +----------------+-----------+---------+-----------------------------+
   | Parameter      | Mandatory | Type    | Description                 |
   +================+===========+=========+=============================+
   | tenant_id      | No        | String  | Specifies the ID of the     |
   |                |           |         | project where the backend   |
   |                |           |         | server is used.             |
   |                |           |         |                             |
   |                |           |         | The value must be the same  |
   |                |           |         | as the value of             |
   |                |           |         | **project_id** in the       |
   |                |           |         | token.                      |
   |                |           |         |                             |
   |                |           |         | The value contains a        |
   |                |           |         | maximum of 255 characters.  |
   +----------------+-----------+---------+-----------------------------+
   | name           | No        | String  | Specifies the backend       |
   |                |           |         | server name. The value is   |
   |                |           |         | an empty character string   |
   |                |           |         | by default.                 |
   |                |           |         |                             |
   |                |           |         | The value contains a        |
   |                |           |         | maximum of 255 characters.  |
   +----------------+-----------+---------+-----------------------------+
   | address        | Yes       | String  | Specifies the private IP    |
   |                |           |         | address of the backend      |
   |                |           |         | server. This IP address     |
   |                |           |         | must be in the subnet       |
   |                |           |         | specified by **subnet_id**. |
   |                |           |         |                             |
   |                |           |         | This parameter can be set   |
   |                |           |         | only to the IP address of   |
   |                |           |         | the primary NIC, for        |
   |                |           |         | example, 192.168.3.11.      |
   |                |           |         |                             |
   |                |           |         | The value contains a        |
   |                |           |         | maximum of 64 characters.   |
   +----------------+-----------+---------+-----------------------------+
   | protocol_port  | Yes       | Integer | Specifies the port used by  |
   |                |           |         | the backend server. The     |
   |                |           |         | port number ranges from 1   |
   |                |           |         | to 65535.                   |
   +----------------+-----------+---------+-----------------------------+
   | subnet_id      | Yes       | String  | Specifies the ID of the     |
   |                |           |         | subnet where the backend    |
   |                |           |         | server works.               |
   |                |           |         |                             |
   |                |           |         | The private IP address of   |
   |                |           |         | the backend server is in    |
   |                |           |         | this subnet.                |
   |                |           |         |                             |
   |                |           |         | Only IPv4 subnets are       |
   |                |           |         | supported.                  |
   +----------------+-----------+---------+-----------------------------+
   | admin_state_up | No        | Boolean | Specifies the               |
   |                |           |         | administrative status of    |
   |                |           |         | the backend server.         |
   |                |           |         |                             |
   |                |           |         | This parameter is reserved, |
   |                |           |         | and the default value is    |
   |                |           |         | **true**.                   |
   +----------------+-----------+---------+-----------------------------+
   | weight         | No        | Integer | Specifies the backend       |
   |                |           |         | server weight. The value    |
   |                |           |         | ranges from **0** to        |
   |                |           |         | **100**.                    |
   |                |           |         |                             |
   |                |           |         | If the value is **0**, the  |
   |                |           |         | backend server will not     |
   |                |           |         | accept new requests. The    |
   |                |           |         | default value is **1**.     |
   +----------------+-----------+---------+-----------------------------+

Response
^^^^^^^^

.. _smc_t4:
.. table:: **Table 4** Response parameters

   +-----------+--------+--------------------------------------------------------------------+
   | Parameter | Type   | Description                                                        |
   +===========+========+====================================================================+
   | member    | Object | Specifies the backend server. For details, see :ref:`smc_t5`.      |
   +-----------+--------+--------------------------------------------------------------------+

.. _smc_t5:
.. table:: **Table 5** **member** parameter description

   +------------------+---------+---------------------------------------+
   | Parameter        | Type    | Description                           |
   +==================+=========+=======================================+
   | id               | String  | Specifies the backend server ID.      |
   |                  |         |                                       |
   |                  |         | NOTE:                                 |
   |                  |         | The value of this parameter is not    |
   |                  |         | the ID of the server but an ID        |
   |                  |         | automatically generated for the       |
   |                  |         | backend server that has already       |
   |                  |         | associated with the load balancer.    |
   +------------------+---------+---------------------------------------+
   | tenant_id        | String  | Specifies the ID of the project where |
   |                  |         | the backend server is used.           |
   |                  |         |                                       |
   |                  |         | The value contains a maximum of 255   |
   |                  |         | characters.                           |
   +------------------+---------+---------------------------------------+
   | name             | String  | Specifies the backend server name.    |
   |                  |         |                                       |
   |                  |         | The value contains a maximum of 255   |
   |                  |         | characters.                           |
   +------------------+---------+---------------------------------------+
   | address          | String  | Specifies the private IP address of   |
   |                  |         | the backend server. This IP address   |
   |                  |         | must be in the subnet specified by    |
   |                  |         | **subnet_id**.                        |
   |                  |         |                                       |
   |                  |         | This parameter can be set only to the |
   |                  |         | IP address of the primary NIC, for    |
   |                  |         | example, 192.168.3.11.                |
   |                  |         |                                       |
   |                  |         | The value contains a maximum of 64    |
   |                  |         | characters.                           |
   +------------------+---------+---------------------------------------+
   | protocol_port    | Integer | Specifies the port used by the        |
   |                  |         | backend server. The port number       |
   |                  |         | ranges from 1 to 65535.               |
   +------------------+---------+---------------------------------------+
   | subnet_id        | String  | Specifies the ID of the subnet where  |
   |                  |         | the backend server works. The private |
   |                  |         | IP address of the backend server is   |
   |                  |         | in this subnet.                       |
   |                  |         |                                       |
   |                  |         | IPv6 subnets are not supported.       |
   +------------------+---------+---------------------------------------+
   | admin_state_up   | Boolean | Specifies the administrative status   |
   |                  |         | of the backend server.                |
   |                  |         |                                       |
   |                  |         | This parameter is reserved. The value |
   |                  |         | can be **true** or **false**.         |
   |                  |         |                                       |
   |                  |         | -  **true**: Enabled                  |
   |                  |         | -  **false**: Disabled                |
   +------------------+---------+---------------------------------------+
   | weight           | Integer | Specifies the backend server weight.  |
   |                  |         | The value ranges from **0** to        |
   |                  |         | **100**.                              |
   |                  |         |                                       |
   |                  |         | If the value is **0**, the backend    |
   |                  |         | server will not accept new requests.  |
   |                  |         | The default value is **1**.           |
   +------------------+---------+---------------------------------------+
   | operating_status | String  | Specifies the health check result of  |
   |                  |         | the backend server. The value can be  |
   |                  |         | one of the following:                 |
   |                  |         |                                       |
   |                  |         | -  **ONLINE**: The backend server is  |
   |                  |         |    running normally.                  |
   |                  |         | -  **NO_MONITOR**: No health check is |
   |                  |         |    configured for the backend server  |
   |                  |         |    group that the backend server      |
   |                  |         |    belongs to.                        |
   |                  |         | -  **OFFLINE**: The cloud server used |
   |                  |         |    as the backend server is stopped   |
   |                  |         |    or does not exist.                 |
   +------------------+---------+---------------------------------------+

Example Request
^^^^^^^^^^^^^^^

.. _smc_e1:

-  Step 1: Query the subnet ID and IP address using the server ID.
   **device_id** in the request indicates the server ID. Obtain the values of
   **subnet_id** and **ip_address** of the primary NIC (the port for which
   **primary_interface** is **true**) in the response body.

   .. code::

      GET https://{VPCEndpoint}/v2.0/ports?device_id=f738c464-b5c2-45df-86c0-7f436620cd54

   Example response

   .. code::

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

-  Step 2: Use the subnet ID and IP address obtained above to add a backend
   server.

   .. code::

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
^^^^^^^^^^^^^^^^

-  Example response

   .. code::

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
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

.. _sml:

Querying Backend Servers
========================

Function
^^^^^^^^

This API is used to query backend servers in a specific backend server group.
Filter query and pagination query are supported. Unless otherwise specified,
exact match is applied.

Constraints
^^^^^^^^^^^

Parameters **marker**, **limit**, and **page_reverse** are used for pagination
query. Parameters **marker** and **page_reverse** take effect only when they
are used together with parameter **limit**.

URI
^^^

GET /v2.0/lbaas/pools/{pool_id}/members

.. _sml_t1:
.. table:: **Table 1** Parameter description

   ========= ========= ====== =============================================
   Parameter Mandatory Type   Description
   ========= ========= ====== =============================================
   pool_id   Yes       String Specifies the ID of the backend server group.
   ========= ========= ====== =============================================

Request
^^^^^^^

.. table:: **Table 2** Parameter description

   +----------------+-----------+---------+-----------------------------+
   | Parameter      | Mandatory | Type    | Description                 |
   +================+===========+=========+=============================+
   | marker         | No        | String  | Specifies the ID of the     |
   |                |           |         | backend server from which   |
   |                |           |         | pagination query starts,    |
   |                |           |         | that is, the ID of the last |
   |                |           |         | backend server on the       |
   |                |           |         | previous page. If this      |
   |                |           |         | parameter is not specified, |
   |                |           |         | the first page will be      |
   |                |           |         | queried.                    |
   |                |           |         |                             |
   |                |           |         | This parameter must be used |
   |                |           |         | together with **limit**.    |
   +----------------+-----------+---------+-----------------------------+
   | limit          | No        | Integer | Specifies the number of     |
   |                |           |         | backend servers on each     |
   |                |           |         | page. If this parameter is  |
   |                |           |         | not set, all backend        |
   |                |           |         | servers are queried by      |
   |                |           |         | default.                    |
   +----------------+-----------+---------+-----------------------------+
   | page_reverse   | No        | Boolean | Specifies the page          |
   |                |           |         | direction. The value can be |
   |                |           |         | **true** or **false**, and  |
   |                |           |         | the default value is        |
   |                |           |         | **false**. The last page in |
   |                |           |         | the list requested with     |
   |                |           |         | **page_reverse** set to     |
   |                |           |         | **false** will not contain  |
   |                |           |         | the "next" link, and the    |
   |                |           |         | last page in the list       |
   |                |           |         | requested with              |
   |                |           |         | **page_reverse** set to     |
   |                |           |         | **true** will not contain   |
   |                |           |         | the "previous" link.        |
   |                |           |         |                             |
   |                |           |         | This parameter must be used |
   |                |           |         | together with **limit**.    |
   +----------------+-----------+---------+-----------------------------+
   | id             | No        | String  | Specifies the backend       |
   |                |           |         | server ID.                  |
   |                |           |         |                             |
   |                |           |         | NOTE:                       |
   |                |           |         | The value of this parameter |
   |                |           |         | is not the ID of the server |
   |                |           |         | but an ID automatically     |
   |                |           |         | generated for the backend   |
   |                |           |         | server that has already     |
   |                |           |         | associated with the load    |
   |                |           |         | balancer.                   |
   +----------------+-----------+---------+-----------------------------+
   | tenant_id      | No        | String  | Specifies the ID of the     |
   |                |           |         | project where the backend   |
   |                |           |         | server is used.             |
   |                |           |         |                             |
   |                |           |         | The value contains a        |
   |                |           |         | maximum of 255 characters.  |
   +----------------+-----------+---------+-----------------------------+
   | name           | No        | String  | Specifies the backend       |
   |                |           |         | server name.                |
   |                |           |         |                             |
   |                |           |         | The value contains a        |
   |                |           |         | maximum of 255 characters.  |
   |                |           |         |                             |
   |                |           |         | NOTE:                       |
   |                |           |         | The value of this parameter |
   |                |           |         | is not the name of server.  |
   |                |           |         | It is the name              |
   |                |           |         | automatically generated for |
   |                |           |         | the backend server          |
   |                |           |         | associated with the load    |
   |                |           |         | balancer.                   |
   +----------------+-----------+---------+-----------------------------+
   | address        | No        | String  | Specifies the private IP    |
   |                |           |         | address of the backend      |
   |                |           |         | server.                     |
   |                |           |         |                             |
   |                |           |         | The value contains a        |
   |                |           |         | maximum of 64 characters.   |
   +----------------+-----------+---------+-----------------------------+
   | protocol_port  | No        | Integer | Specifies the port used by  |
   |                |           |         | the backend server.         |
   +----------------+-----------+---------+-----------------------------+
   | subnet_id      | No        | String  | Specifies the ID of the     |
   |                |           |         | subnet where the backend    |
   |                |           |         | server works.               |
   +----------------+-----------+---------+-----------------------------+
   | admin_state_up | No        | Boolean | Specifies the               |
   |                |           |         | administrative status of    |
   |                |           |         | the backend server.         |
   |                |           |         |                             |
   |                |           |         | This parameter is reserved, |
   |                |           |         | and the default value is    |
   |                |           |         | **true**.                   |
   +----------------+-----------+---------+-----------------------------+
   | weight         | No        | Integer | Specifies the backend       |
   |                |           |         | server weight.              |
   +----------------+-----------+---------+-----------------------------+

Response
^^^^^^^^

.. _sml_t3:
.. table:: **Table 3** Response parameters

   +---------------+-------+------------------------------------+
   | Parameter     | Type  | Description                        |
   +===============+=======+====================================+
   | members       | Array | Lists the backend servers in the   |
   |               |       | backend server group. For details, |
   |               |       | see :ref:`sml_t4`.                 |
   +---------------+-------+------------------------------------+
   | members_links | Array | Provides links to the previous or  |
   |               |       | next page during pagination query, |
   |               |       | respectively.                      |
   |               |       |                                    |
   |               |       | This parameter exists only in the  |
   |               |       | response body of pagination query. |
   |               |       | For details, see :ref:`sml_t5`.    |
   +---------------+-------+------------------------------------+

.. _sml_t4:
.. table:: **Table 4** **members** parameter description

   +------------------+---------+---------------------------------------+
   | Parameter        | Type    | Description                           |
   +==================+=========+=======================================+
   | id               | String  | Specifies the backend server ID.      |
   |                  |         |                                       |
   |                  |         | NOTE:                                 |
   |                  |         | The value of this parameter is not    |
   |                  |         | the ID of the server but an ID        |
   |                  |         | automatically generated for the       |
   |                  |         | backend server that has already       |
   |                  |         | associated with the load balancer.    |
   +------------------+---------+---------------------------------------+
   | tenant_id        | String  | Specifies the ID of the project where |
   |                  |         | the backend server is used.           |
   |                  |         |                                       |
   |                  |         | The value contains a maximum of 255   |
   |                  |         | characters.                           |
   +------------------+---------+---------------------------------------+
   | name             | String  | Specifies the backend server name.    |
   |                  |         |                                       |
   |                  |         | The value contains a maximum of 255   |
   |                  |         | characters.                           |
   +------------------+---------+---------------------------------------+
   | address          | String  | Specifies the private IP address of   |
   |                  |         | the backend server. This IP address   |
   |                  |         | must be in the subnet specified by    |
   |                  |         | **subnet_id**.                        |
   |                  |         |                                       |
   |                  |         | This parameter can be set only to the |
   |                  |         | IP address of the primary NIC, for    |
   |                  |         | example, 192.168.3.11.                |
   |                  |         |                                       |
   |                  |         | The value contains a maximum of 64    |
   |                  |         | characters.                           |
   +------------------+---------+---------------------------------------+
   | protocol_port    | Integer | Specifies the port used by the        |
   |                  |         | backend server. The port number       |
   |                  |         | ranges from 1 to 65535.               |
   +------------------+---------+---------------------------------------+
   | subnet_id        | String  | Specifies the ID of the subnet where  |
   |                  |         | the backend server works. The private |
   |                  |         | IP address of the backend server is   |
   |                  |         | in this subnet.                       |
   |                  |         |                                       |
   |                  |         | IPv6 subnets are not supported.       |
   +------------------+---------+---------------------------------------+
   | admin_state_up   | Boolean | Specifies the administrative status   |
   |                  |         | of the backend server.                |
   |                  |         |                                       |
   |                  |         | This parameter is reserved. The value |
   |                  |         | can be **true** or **false**.         |
   |                  |         |                                       |
   |                  |         | -  **true**: Enabled                  |
   |                  |         | -  **false**: Disabled                |
   +------------------+---------+---------------------------------------+
   | weight           | Integer | Specifies the backend server weight.  |
   |                  |         | The value ranges from **0** to        |
   |                  |         | **100**.                              |
   |                  |         |                                       |
   |                  |         | If the value is **0**, the backend    |
   |                  |         | server will not accept new requests.  |
   |                  |         | The default value is **1**.           |
   +------------------+---------+---------------------------------------+
   | operating_status | String  | Specifies the operating status of the |
   |                  |         | load balancer. This parameter is      |
   |                  |         | reserved, and its value can only be   |
   |                  |         | **ONLINE**.                           |
   +------------------+---------+---------------------------------------+

.. _sml_t5:
.. table:: **Table 5** **members_links** parameter description

   +-----------+--------+---------------------------------------+
   | Parameter | Type   | Description                           |
   +===========+========+=======================================+
   | href      | String | Provides links to the previous or     |
   |           |        | next page during pagination query,    |
   |           |        | respectively.                         |
   +-----------+--------+---------------------------------------+
   | rel       | String | Specifies the prompt of the previous  |
   |           |        | or next page. The value can be        |
   |           |        | **next** or **previous**.             |
   |           |        |                                       |
   |           |        | -  **next**: indicates the URL of the |
   |           |        |    next page.                         |
   |           |        | -  **previous**: indicates the URL of |
   |           |        |    the previous page.                 |
   +-----------+--------+---------------------------------------+

Example Request
^^^^^^^^^^^^^^^

-  Example request 1: Querying all backend servers

   .. code::

      GET https://{Endpoint}/v2.0/lbaas/pools/5a9a3e9e-d1aa-448e-af37-a70171f2a332/members

-  Example request 2: Querying the backend cloud server whose IP address is
   10.0.0.8 and port number is 80

   .. code::

      GET https://{Endpoint}/v2.0/lbaas/pools/5a9a3e9e-d1aa-448e-af37-a70171f2a332/members?address=10.0.0.8&protocol_port=80

Example Response
^^^^^^^^^^^^^^^^

-  Example response 1

   .. code::

      {
          "members": [
              {
                  "address": "10.0.0.8",
                  "admin_state_up": true,
                  "id": "9a7aff27-fd41-4ec1-ba4c-3eb92c629313",
                  "protocol_port": 80,
                  "subnet_id": "013d3059-87a4-45a5-91e9-d721068ae0b2",
                  "tenant_id": "1a3e005cf9ce40308c900bcb08e5320c",
                  "weight": 1,
                  "operating_status": "ONLINE",
                  "name": "member-name"
              }
          ]
      }

-  Example response 2

   .. code::

      {
          "members": [
              {
                  "address": "10.0.0.8",
                  "admin_state_up": true,
                  "id": "9a7aff27-fd41-4ec1-ba4c-3eb92c629313",
                  "protocol_port": 80,
                  "subnet_id": "013d3059-87a4-45a5-91e9-d721068ae0b2",
                  "tenant_id": "1a3e005cf9ce40308c900bcb08e5320c",

                  "weight": 1,
                  "operating_status": "ONLINE",
                  "name": "member-name"
              }
          ]
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Querying Details of a Backend Server
====================================

Function
^^^^^^^^

This API is used to query details about a backend server.

URI
^^^

GET /v2.0/lbaas/pools/{pool_id}/members/{member_id}

.. table:: **Table 1** Parameter description

   +-----------+-----------+--------+-----------------------------+
   | Parameter | Mandatory | Type   | **Description**             |
   +===========+===========+========+=============================+
   | pool_id   | Yes       | String | Specifies the ID of the     |
   |           |           |        | backend server group.       |
   +-----------+-----------+--------+-----------------------------+
   | member_id | Yes       | String | Specifies the backend       |
   |           |           |        | server ID.                  |
   |           |           |        |                             |
   |           |           |        | NOTE:                       |
   |           |           |        |                             |
   |           |           |        | -  The value of this        |
   |           |           |        |    parameter is not the ID  |
   |           |           |        |    of the server but an ID  |
   |           |           |        |    automatically generated  |
   |           |           |        |    for the backend server   |
   |           |           |        |    that has already         |
   |           |           |        |    associated with the load |
   |           |           |        |    balancer.                |
   |           |           |        | -  You can obtain this      |
   |           |           |        |    value by calling the API |
   |           |           |        |    described in :ref:`sml`. |
   +-----------+-----------+--------+-----------------------------+

Request
^^^^^^^

None

Response
^^^^^^^^

.. _sms_t2:
.. table:: **Table 2** Response parameters

   +-----------+--------+--------------------------------------------------------------------+
   | Parameter | Type   | Description                                                        |
   +===========+========+====================================================================+
   | member    | Object | Lists the backend servers. For details, see :ref:`sms_t3`.         |
   +-----------+--------+--------------------------------------------------------------------+

.. _sms_t3:
.. table:: **Table 3** **member** parameter description

   +------------------+---------+---------------------------------------+
   | Parameter        | Type    | Description                           |
   +==================+=========+=======================================+
   | id               | String  | Specifies the backend server ID.      |
   |                  |         |                                       |
   |                  |         | NOTE:                                 |
   |                  |         | The value of this parameter is not    |
   |                  |         | the ID of the server but an ID        |
   |                  |         | automatically generated for the       |
   |                  |         | backend server that has already       |
   |                  |         | associated with the load balancer.    |
   +------------------+---------+---------------------------------------+
   | tenant_id        | String  | Specifies the ID of the project where |
   |                  |         | the backend server is used.           |
   |                  |         |                                       |
   |                  |         | The value contains a maximum of 255   |
   |                  |         | characters.                           |
   +------------------+---------+---------------------------------------+
   | name             | String  | Specifies the backend server name.    |
   |                  |         |                                       |
   |                  |         | The value contains a maximum of 255   |
   |                  |         | characters.                           |
   +------------------+---------+---------------------------------------+
   | address          | String  | Specifies the private IP address of   |
   |                  |         | the backend server. This IP address   |
   |                  |         | must be in the subnet specified by    |
   |                  |         | **subnet_id**.                        |
   |                  |         |                                       |
   |                  |         | This parameter can be set only to the |
   |                  |         | IP address of the primary NIC, for    |
   |                  |         | example, 192.168.3.11.                |
   |                  |         |                                       |
   |                  |         | The value contains a maximum of 64    |
   |                  |         | characters.                           |
   +------------------+---------+---------------------------------------+
   | protocol_port    | Integer | Specifies the port used by the        |
   |                  |         | backend server. The port number       |
   |                  |         | ranges from 1 to 65535.               |
   +------------------+---------+---------------------------------------+
   | subnet_id        | String  | Specifies the ID of the subnet where  |
   |                  |         | the backend server works. The private |
   |                  |         | IP address of the backend server is   |
   |                  |         | in this subnet.                       |
   |                  |         |                                       |
   |                  |         | IPv6 subnets are not supported.       |
   +------------------+---------+---------------------------------------+
   | admin_state_up   | Boolean | Specifies the administrative status   |
   |                  |         | of the backend server.                |
   |                  |         |                                       |
   |                  |         | This parameter is reserved. The value |
   |                  |         | can be **true** or **false**.         |
   |                  |         |                                       |
   |                  |         | -  **true**: Enabled                  |
   |                  |         | -  **false**: Disabled                |
   +------------------+---------+---------------------------------------+
   | weight           | Integer | Specifies the backend server weight.  |
   |                  |         | The value ranges from **0** to        |
   |                  |         | **100**.                              |
   |                  |         |                                       |
   |                  |         | If the value is **0**, the backend    |
   |                  |         | server will not accept new requests.  |
   |                  |         | The default value is **1**.           |
   +------------------+---------+---------------------------------------+
   | operating_status | String  | Specifies the health check result of  |
   |                  |         | the backend server. The value can be  |
   |                  |         | one of the following:                 |
   |                  |         |                                       |
   |                  |         | -  **ONLINE**: The backend server is  |
   |                  |         |    running normally.                  |
   |                  |         | -  **NO_MONITOR**: No health check is |
   |                  |         |    configured for the backend server  |
   |                  |         |    group that the backend server      |
   |                  |         |    belongs to.                        |
   |                  |         | -  **OFFLINE**: The cloud server used |
   |                  |         |    as the backend server is stopped   |
   |                  |         |    or does not exist.                 |
   +------------------+---------+---------------------------------------+

Example Request
^^^^^^^^^^^^^^^

-  Example request: Querying details of a backend server

   .. code::

      GET https://{Endpoint}/v2.0/lbaas/pools/5a9a3e9e-d1aa-448e-af37-a70171f2a332/members/cf024846-7516-4e3a-b0fb-6590322c836f

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   .. code::

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
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

.. _smu:

Updating a Backend Server
=========================

Function
^^^^^^^^

This API is used to update a backend server. You can modify its name and
weight. You can set a larger weight for backend servers that can receive more
traffic.

Constraints
^^^^^^^^^^^

If the provisioning status of the associated load balancer is not **ACTIVE**,
the backend server cannot be updated.

URI
^^^

PUT /v2.0/lbaas/pools/{pool_id}/members/{member_id}

.. table:: **Table 1** Parameter description

   +-----------+-----------+--------+-----------------------------+
   | Parameter | Mandatory | Type   | Description                 |
   +===========+===========+========+=============================+
   | pool_id   | Yes       | String | Specifies the ID of the     |
   |           |           |        | backend server group.       |
   +-----------+-----------+--------+-----------------------------+
   | member_id | Yes       | String | Specifies the backend       |
   |           |           |        | server ID.                  |
   |           |           |        |                             |
   |           |           |        | NOTE:                       |
   |           |           |        |                             |
   |           |           |        | -  The value of this        |
   |           |           |        |    parameter is not the ID  |
   |           |           |        |    of the server but an ID  |
   |           |           |        |    automatically generated  |
   |           |           |        |    for the backend server   |
   |           |           |        |    that has already         |
   |           |           |        |    associated with the load |
   |           |           |        |    balancer.                |
   |           |           |        | -  You can obtain this      |
   |           |           |        |    value by calling the API |
   |           |           |        |    described in :ref:`sml`. |
   +-----------+-----------+--------+-----------------------------+

Request
^^^^^^^

.. _smu_t2:
.. table:: **Table 2** Parameter description

   +-----------+-----------+--------+------------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                      |
   +===========+===========+========+==================================================================+
   | member    | Yes       | Object | Specifies the backend server. For details, see :ref:`smu_t3`.    |
   +-----------+-----------+--------+------------------------------------------------------------------+

.. _smu_t3:
.. table:: **Table 3** **member** parameter description

   +----------------+-----------+---------+-----------------------------+
   | Parameter      | Mandatory | Type    | Description                 |
   +================+===========+=========+=============================+
   | name           | No        | String  | Specifies the backend       |
   |                |           |         | server name.                |
   |                |           |         |                             |
   |                |           |         | The value contains a        |
   |                |           |         | maximum of 255 characters.  |
   +----------------+-----------+---------+-----------------------------+
   | admin_state_up | No        | Boolean | Specifies the               |
   |                |           |         | administrative status of    |
   |                |           |         | the backend server.         |
   |                |           |         |                             |
   |                |           |         | This parameter is reserved, |
   |                |           |         | and the default value is    |
   |                |           |         | **true**.                   |
   +----------------+-----------+---------+-----------------------------+
   | weight         | No        | Integer | Specifies the backend       |
   |                |           |         | server weight. The value    |
   |                |           |         | ranges from **0** to        |
   |                |           |         | **100**.                    |
   |                |           |         |                             |
   |                |           |         | If the value is **0**, the  |
   |                |           |         | backend server will not     |
   |                |           |         | accept new requests. The    |
   |                |           |         | default value is **1**.     |
   +----------------+-----------+---------+-----------------------------+

Response
^^^^^^^^

.. table:: **Table 4** Response parameters

   +-----------+--------+-------------------------------------------------------------------+
   | Parameter | Type   | Description                                                       |
   +===========+========+===================================================================+
   | member    | Object | Specifies the backend server. For details, see :ref:`smu_t5`.     |
   +-----------+--------+-------------------------------------------------------------------+

.. _smu_t5:
.. table:: **Table 5** **member** parameter description

   +------------------+---------+---------------------------------------+
   | Parameter        | Type    | Description                           |
   +==================+=========+=======================================+
   | id               | String  | Specifies the backend server ID.      |
   |                  |         |                                       |
   |                  |         | NOTE:                                 |
   |                  |         | The value of this parameter is not    |
   |                  |         | the ID of the server but an ID        |
   |                  |         | automatically generated for the       |
   |                  |         | backend server that has already       |
   |                  |         | associated with the load balancer.    |
   +------------------+---------+---------------------------------------+
   | tenant_id        | String  | Specifies the ID of the project where |
   |                  |         | the backend server is used.           |
   |                  |         |                                       |
   |                  |         | The value contains a maximum of 255   |
   |                  |         | characters.                           |
   +------------------+---------+---------------------------------------+
   | name             | String  | Specifies the backend server name.    |
   |                  |         |                                       |
   |                  |         | The value contains a maximum of 255   |
   |                  |         | characters.                           |
   +------------------+---------+---------------------------------------+
   | address          | String  | Specifies the private IP address of   |
   |                  |         | the backend server. This IP address   |
   |                  |         | must be in the subnet specified by    |
   |                  |         | **subnet_id**.                        |
   |                  |         |                                       |
   |                  |         | This parameter can be set only to the |
   |                  |         | IP address of the primary NIC, for    |
   |                  |         | example, 192.168.3.11.                |
   |                  |         |                                       |
   |                  |         | The value contains a maximum of 64    |
   |                  |         | characters.                           |
   +------------------+---------+---------------------------------------+
   | protocol_port    | Integer | Specifies the port used by the        |
   |                  |         | backend server. The port number       |
   |                  |         | ranges from 1 to 65535.               |
   +------------------+---------+---------------------------------------+
   | subnet_id        | String  | Specifies the ID of the subnet where  |
   |                  |         | the backend server works. The private |
   |                  |         | IP address of the backend server is   |
   |                  |         | in this subnet.                       |
   |                  |         |                                       |
   |                  |         | IPv6 subnets are not supported.       |
   +------------------+---------+---------------------------------------+
   | admin_state_up   | Boolean | Specifies the administrative status   |
   |                  |         | of the backend server.                |
   |                  |         |                                       |
   |                  |         | This parameter is reserved. The value |
   |                  |         | can be **true** or **false**.         |
   |                  |         |                                       |
   |                  |         | -  **true**: Enabled                  |
   |                  |         | -  **false**: Disabled                |
   +------------------+---------+---------------------------------------+
   | weight           | Integer | Specifies the backend server weight.  |
   |                  |         | The value ranges from **0** to        |
   |                  |         | **100**.                              |
   |                  |         |                                       |
   |                  |         | If the value is **0**, the backend    |
   |                  |         | server will not accept new requests.  |
   |                  |         | The default value is **1**.           |
   +------------------+---------+---------------------------------------+
   | operating_status | String  | Specifies the health check result of  |
   |                  |         | the backend server. The value can be  |
   |                  |         | one of the following:                 |
   |                  |         |                                       |
   |                  |         | -  **ONLINE**: The backend server is  |
   |                  |         |    running normally.                  |
   |                  |         | -  **NO_MONITOR**: No health check is |
   |                  |         |    configured for the backend server  |
   |                  |         |    group that the backend server      |
   |                  |         |    belongs to.                        |
   |                  |         | -  **OFFLINE**: The cloud server used |
   |                  |         |    as the backend server is stopped   |
   |                  |         |    or does not exist.                 |
   +------------------+---------+---------------------------------------+

Example Request
^^^^^^^^^^^^^^^

-  Example request: Updating the name and weight of a backend server

   .. code::

      PUT https://{Endpoint}/v2.0/lbaas/pools/5a9a3e9e-d1aa-448e-af37-a70171f2a332/members/c0042496-e220-44f6-914b-e6ca33bab503

      {
          "member": {
              "name": "member create test",
              "weight": 10
          }
      }

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   .. code::

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
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

.. _smd:

Removing a Backend Server
=========================

Function
^^^^^^^^

This API is used to remove a backend server by its ID.

Constraints
^^^^^^^^^^^

After you remove a backend server, new connections to this server will not be
established. However, long connections that have been established will be
maintained.

URI
^^^

DELETE /v2.0/lbaas/pools/{pool_id}/members/{member_id}

.. table:: **Table 1** Parameter description

   +-----------+-----------+--------+-----------------------------+
   | Parameter | Mandatory | Type   | Description                 |
   +===========+===========+========+=============================+
   | pool_id   | Yes       | String | Specifies the ID of the     |
   |           |           |        | backend server group.       |
   +-----------+-----------+--------+-----------------------------+
   | member_id | Yes       | String | Specifies the backend       |
   |           |           |        | server ID.                  |
   |           |           |        |                             |
   |           |           |        | NOTE:                       |
   |           |           |        |                             |
   |           |           |        | -  The value of this        |
   |           |           |        |    parameter is not the ID  |
   |           |           |        |    of the server but an ID  |
   |           |           |        |    automatically generated  |
   |           |           |        |    for the backend server   |
   |           |           |        |    that has already         |
   |           |           |        |    associated with the load |
   |           |           |        |    balancer.                |
   |           |           |        | -  You can obtain this      |
   |           |           |        |    value by calling the API |
   |           |           |        |    described in :ref:`sml`. |
   +-----------+-----------+--------+-----------------------------+

Request
^^^^^^^

None

Response
^^^^^^^^

None

Example Request
^^^^^^^^^^^^^^^

-  Example request: Removing a backend server

   .. code::

      DELETE https://{Endpoint}/v2.0/lbaas/pools/5a9a3e9e-d1aa-448e-af37-a70171f2a332/members/cf024846-7516-4e3a-b0fb-6590322c836f

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   None

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Querying All Backend Servers (Extension API)
============================================

Function
^^^^^^^^

This API is used to query all backend servers. Filter query and pagination
query are supported.

Constraints
^^^^^^^^^^^

Parameters **marker**, **limit**, and **page_reverse** are used for pagination
query. Parameters **marker** and **page_reverse** take effect only when they
are used together with parameter **limit**.

URI
^^^

GET /v2.0/lbaas/members

Request
^^^^^^^

.. table:: **Table 1** Parameter description

   +------------------+-----------+---------+------------------------------+
   | Parameter        | Mandatory | Type    | Description                  |
   +==================+===========+=========+==============================+
   | marker           | No        | String  | Specifies the ID of the      |
   |                  |           |         | backend server from which    |
   |                  |           |         | pagination query starts,     |
   |                  |           |         | that is, the ID of the last  |
   |                  |           |         | backend server on the        |
   |                  |           |         | previous page. If this       |
   |                  |           |         | parameter is not specified,  |
   |                  |           |         | the first page will be       |
   |                  |           |         | queried.                     |
   |                  |           |         |                              |
   |                  |           |         | This parameter must be used  |
   |                  |           |         | together with **limit**.     |
   +------------------+-----------+---------+------------------------------+
   | limit            | No        | Integer | Specifies the number of      |
   |                  |           |         | backend servers on each      |
   |                  |           |         | page. If this parameter is   |
   |                  |           |         | not set, all backend         |
   |                  |           |         | servers are queried by       |
   |                  |           |         | default.                     |
   +------------------+-----------+---------+------------------------------+
   | page_reverse     | No        | Boolean | Specifies the page           |
   |                  |           |         | direction. The value can be  |
   |                  |           |         | **true** or **false**, and   |
   |                  |           |         | the default value is         |
   |                  |           |         | **false**. The last page in  |
   |                  |           |         | the list requested with      |
   |                  |           |         | **page_reverse** set to      |
   |                  |           |         | **false** will not contain   |
   |                  |           |         | the "next" link, and the     |
   |                  |           |         | last page in the list        |
   |                  |           |         | requested with               |
   |                  |           |         | **page_reverse** set to      |
   |                  |           |         | **true** will not contain    |
   |                  |           |         | the "previous" link.         |
   |                  |           |         |                              |
   |                  |           |         | This parameter must be used  |
   |                  |           |         | together with **limit**.     |
   +------------------+-----------+---------+------------------------------+
   | id               | No        | String  | Specifies the backend        |
   |                  |           |         | server ID.                   |
   |                  |           |         |                              |
   |                  |           |         | NOTE:                        |
   |                  |           |         | The value of this parameter  |
   |                  |           |         | is not the ID of the server  |
   |                  |           |         | but an ID automatically      |
   |                  |           |         | generated for the backend    |
   |                  |           |         | server that has already      |
   |                  |           |         | associated with the load     |
   |                  |           |         | balancer.                    |
   +------------------+-----------+---------+------------------------------+
   | name             | No        | String  | Specifies the backend        |
   |                  |           |         | server name.                 |
   |                  |           |         |                              |
   |                  |           |         | The value contains a         |
   |                  |           |         | maximum of 255 characters.   |
   +------------------+-----------+---------+------------------------------+
   | address          | No        | String  | Specifies the private IP     |
   |                  |           |         | address of the backend       |
   |                  |           |         | server.                      |
   |                  |           |         |                              |
   |                  |           |         | The value contains a         |
   |                  |           |         | maximum of 64 characters.    |
   +------------------+-----------+---------+------------------------------+
   | protocol_port    | No        | Integer | Specifies the port used by   |
   |                  |           |         | the backend server.          |
   +------------------+-----------+---------+------------------------------+
   | subnet_id        | No        | String  | Specifies the ID of the      |
   |                  |           |         | subnet where the backend     |
   |                  |           |         | server works.                |
   +------------------+-----------+---------+------------------------------+
   | admin_state_up   | No        | Boolean | Specifies the                |
   |                  |           |         | administrative status of     |
   |                  |           |         | the backend server.          |
   |                  |           |         |                              |
   |                  |           |         | This parameter is reserved,  |
   |                  |           |         | and the default value is     |
   |                  |           |         | **true**.                    |
   +------------------+-----------+---------+------------------------------+
   | weight           | No        | Integer | Specifies the backend        |
   |                  |           |         | server weight.               |
   +------------------+-----------+---------+------------------------------+
   | loadbalancer_id  | No        | String  | Specifies the backend        |
   |                  |           |         | server ID.                   |
   +------------------+-----------+---------+------------------------------+
   | operating_status | No        | String  | Specifies the health check   |
   |                  |           |         | result of the backend        |
   |                  |           |         | server. The value can be     |
   |                  |           |         | one of the following:        |
   |                  |           |         |                              |
   |                  |           |         | -  **ONLINE**: The backend   |
   |                  |           |         |    server is running         |
   |                  |           |         |    normally.                 |
   |                  |           |         | -  **NO_MONITOR**: No        |
   |                  |           |         |    health check is           |
   |                  |           |         |    performed on the backend  |
   |                  |           |         |    server.                   |
   |                  |           |         | -  **OFFLINE**: The cloud    |
   |                  |           |         |    server used as the        |
   |                  |           |         |    backend server is         |
   |                  |           |         |    stopped or does not       |
   |                  |           |         |    exist.                    |
   |                  |           |         |                              |
   |                  |           |         | The default value is         |
   |                  |           |         | **ONLINE**.                  |
   +------------------+-----------+---------+------------------------------+
   | members_links    | No        | Array   | Provides links to the        |
   |                  |           |         | previous or next page        |
   |                  |           |         | during pagination query,     |
   |                  |           |         | respectively.                |
   |                  |           |         |                              |
   |                  |           |         | This parameter exists only   |
   |                  |           |         | in the response body of      |
   |                  |           |         | pagination query. For        |
   |                  |           |         | details, see :ref:`smle_t5`. |
   +------------------+-----------+---------+------------------------------+

.. _smle_t2:
.. table:: **Table 2** **members_links** parameter description

   +-----------+--------+---------------------------------------+
   | Parameter | Type   | Description                           |
   +===========+========+=======================================+
   | href      | String | Provides links to the previous or     |
   |           |        | next page during pagination query,    |
   |           |        | respectively.                         |
   +-----------+--------+---------------------------------------+
   | rel       | String | Specifies the prompt of the previous  |
   |           |        | or next page. The value can be        |
   |           |        | **next** or **previous**.             |
   |           |        |                                       |
   |           |        | -  **next**: indicates the URL of the |
   |           |        |    next page.                         |
   |           |        | -  **previous**: indicates the URL of |
   |           |        |    the previous page.                 |
   +-----------+--------+---------------------------------------+

Response
^^^^^^^^

.. table:: **Table 3** Response parameters

   +-----------+-------+---------------------------------------------------------------------------+
   | Parameter | Type  | Description                                                               |
   +===========+=======+===========================================================================+
   | members   | Array | Lists the backend servers. For details, see :ref:`smle_t4`.               |
   +-----------+-------+---------------------------------------------------------------------------+

.. _smle_t4:
.. table:: **Table 4** **members** parameter description

   +------------------+---------+---------------------------------------+
   | Parameter        | Type    | Description                           |
   +==================+=========+=======================================+
   | id               | String  | Specifies the backend server ID.      |
   |                  |         |                                       |
   |                  |         | NOTE:                                 |
   |                  |         | The value of this parameter is not    |
   |                  |         | the ID of the server but an ID        |
   |                  |         | automatically generated for the       |
   |                  |         | backend server that has already       |
   |                  |         | associated with the load balancer.    |
   +------------------+---------+---------------------------------------+
   | tenant_id        | String  | Specifies the ID of the project where |
   |                  |         | the backend server is used.           |
   |                  |         |                                       |
   |                  |         | The value contains a maximum of 255   |
   |                  |         | characters.                           |
   +------------------+---------+---------------------------------------+
   | name             | String  | Specifies the backend server name.    |
   |                  |         |                                       |
   |                  |         | The value contains a maximum of 255   |
   |                  |         | characters.                           |
   +------------------+---------+---------------------------------------+
   | address          | String  | Specifies the private IP address of   |
   |                  |         | the backend server. This IP address   |
   |                  |         | must be in the subnet specified by    |
   |                  |         | **subnet_id**.                        |
   |                  |         |                                       |
   |                  |         | This parameter can be set only to the |
   |                  |         | IP address of the primary NIC, for    |
   |                  |         | example, 192.168.3.11.                |
   |                  |         |                                       |
   |                  |         | The value contains a maximum of 64    |
   |                  |         | characters.                           |
   +------------------+---------+---------------------------------------+
   | protocol_port    | Integer | Specifies the port used by the        |
   |                  |         | backend server. The port number       |
   |                  |         | ranges from 1 to 65535.               |
   +------------------+---------+---------------------------------------+
   | subnet_id        | String  | Specifies the ID of the subnet where  |
   |                  |         | the backend server works. The private |
   |                  |         | IP address of the backend server is   |
   |                  |         | in this subnet.                       |
   |                  |         |                                       |
   |                  |         | IPv6 subnets are not supported.       |
   +------------------+---------+---------------------------------------+
   | admin_state_up   | Boolean | Specifies the administrative status   |
   |                  |         | of the backend server.                |
   |                  |         |                                       |
   |                  |         | This parameter is reserved. The value |
   |                  |         | can be **true** or **false**.         |
   |                  |         |                                       |
   |                  |         | -  **true**: Enabled                  |
   |                  |         | -  **false**: Disabled                |
   +------------------+---------+---------------------------------------+
   | weight           | Integer | Specifies the backend server weight.  |
   |                  |         | The value ranges from **0** to        |
   |                  |         | **100**.                              |
   |                  |         |                                       |
   |                  |         | If the value is **0**, the backend    |
   |                  |         | server will not accept new requests.  |
   |                  |         | The default value is **1**.           |
   +------------------+---------+---------------------------------------+
   | operating_status | String  | Specifies the health check result of  |
   |                  |         | the backend server. The value can be  |
   |                  |         | one of the following:                 |
   |                  |         |                                       |
   |                  |         | -  **ONLINE**: The backend server is  |
   |                  |         |    running normally.                  |
   |                  |         | -  **NO_MONITOR**: No health check is |
   |                  |         |    performed on the backend server.   |
   |                  |         | -  **OFFLINE**: The cloud server used |
   |                  |         |    as the backend server is stopped   |
   |                  |         |    or does not exist.                 |
   +------------------+---------+---------------------------------------+
   | device_id        | String  | Specifies the ID of the cloud server  |
   |                  |         | used as the backend server. If the    |
   |                  |         | cloud server does not exist, this     |
   |                  |         | parameter is an empty string.         |
   +------------------+---------+---------------------------------------+
   | device_owner     | String  | Specifies the resource ID and AZ ID   |
   |                  |         | of the cloud server used as the       |
   |                  |         | backend server, for example,          |
   |                  |         | **compute:az2.dc2**.                  |
   |                  |         |                                       |
   |                  |         | If no corresponding ECS is available, |
   |                  |         | the value is an empty string.         |
   +------------------+---------+---------------------------------------+
   | loadbalancer_id  | String  | Specifies the backend server ID.      |
   +------------------+---------+---------------------------------------+
   | members_links    | Array   | Provides links to the previous or     |
   |                  |         | next page during pagination query,    |
   |                  |         | respectively.                         |
   |                  |         |                                       |
   |                  |         | This parameter exists only in the     |
   |                  |         | response body of pagination query.    |
   |                  |         | For details, see :ref:`smle_t5`.      |
   +------------------+---------+---------------------------------------+
   | pool_id          | String  | Specifies the backend server ID.      |
   +------------------+---------+---------------------------------------+

.. _smle_t5:
.. table:: **Table 5** **members_links** parameter description

   +-----------+--------+---------------------------------------+
   | Parameter | Type   | Description                           |
   +===========+========+=======================================+
   | href      | String | Provides links to the previous or     |
   |           |        | next page during pagination query,    |
   |           |        | respectively.                         |
   +-----------+--------+---------------------------------------+
   | rel       | String | Specifies the prompt of the previous  |
   |           |        | or next page. The value can be        |
   |           |        | **next** or **previous**.             |
   |           |        |                                       |
   |           |        | -  **next**: indicates the URL of the |
   |           |        |    next page.                         |
   |           |        | -  **previous**: indicates the URL of |
   |           |        |    the previous page.                 |
   +-----------+--------+---------------------------------------+

Example Request
^^^^^^^^^^^^^^^

-  Example request 1: Querying all backend servers

   .. code::

      GET https://{Endpoint}/v2.0/lbaas/members

-  Example request 2: Displaying two backend servers on each page and filtering
   out backend servers whose health check result is **OFFLINE**

   .. code::

      GET https://{Endpoint}/v2.0/lbaas/members?operating_status=OFFLINE&limit=2

Example Response
^^^^^^^^^^^^^^^^

-  Example response 1

   .. code::

      {
          "members": [
              {
                  "name": "",
                  "weight": 1,
                  "admin_state_up": false,
                  "subnet_id": "03e1458a-fe0d-4e2f-bc4a-44f25a045287",
                  "tenant_id": "573d73c9f90e48d0bddfa0eb202b25c2",
                  "pool_id": "b299051c-a154-4bd6-b630-215151593306",
                  "loadbalancer_id": "77bfe95e-9f5b-4cff-afd9-900f8de5775b",
                  "device_owner": "",
                  "address": "192.168.77.11",
                  "protocol_port": 880,
                  "id": "50bd4ae0-fdf4-4540-b94a-04ce6241751e",
                  "operating_status": "OFFLINE",
                  "device_id": ""
              },
              {
                  "name": "",
                  "weight": 1,
                  "admin_state_up": false,
                  "subnet_id": "03e1458a-fe0d-4e2f-bc4a-44f25a045287",
                  "tenant_id": "573d73c9f90e48d0bddfa0eb202b25c2",
                  "pool_id": "b299051c-a154-4bd6-b630-215151593306",
                  "loadbalancer_id": "77bfe95e-9f5b-4cff-afd9-900f8de5775b",
                  "device_owner": "",
                  "address": "192.168.77.12",
                  "protocol_port": 880,
                  "id": "fa2045e3-b296-406b-ad12-1611dce44be6",
                  "operating_status": "OFFLINE",
                  "device_id": ""
              }
          ]
      }

-  Example response 2

   .. code::

      {
          "members_links": [
              {
                  "href": "https://network.localdomain.com:8020/v2.0/lbaas/members?pool_id=b299051c-a154-4bd6-b630-215151593306&marker=50bd4ae0-fdf4-4540-b94a-04ce6241751e&page_reverse=True",
                  "rel": "previous"
              }
          ],
          "members": [
              {
                  "name": "",
                  "weight": 1,
                  "admin_state_up": false,
                  "subnet_id": "03e1458a-fe0d-4e2f-bc4a-44f25a045287",
                  "tenant_id": "573d73c9f90e48d0bddfa0eb202b25c2",
                  "pool_id": "b299051c-a154-4bd6-b630-215151593306",
                  "loadbalancer_id": "77bfe95e-9f5b-4cff-afd9-900f8de5775b",
                  "device_owner": "",
                  "address": "192.168.77.11",
                  "protocol_port": 880,
                  "id": "50bd4ae0-fdf4-4540-b94a-04ce6241751e",
                  "operating_status": "OFFLINE",
                  "device_id": ""
              },
              {
                  "name": "",
                  "weight": 1,
                  "admin_state_up": false,
                  "subnet_id": "03e1458a-fe0d-4e2f-bc4a-44f25a045287",
                  "tenant_id": "573d73c9f90e48d0bddfa0eb202b25c2",
                  "pool_id": "b299051c-a154-4bd6-b630-215151593306",
                  "loadbalancer_id": "77bfe95e-9f5b-4cff-afd9-900f8de5775b",
                  "device_owner": "",
                  "address": "192.168.77.12",
                  "protocol_port": 880,
                  "id": "fa2045e3-b296-406b-ad12-1611dce44be6",
                  "operating_status": "OFFLINE",
                  "device_id": ""
              }
          ]
      }

Return Codes
^^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Batch Updating Backend Servers
==============================

Function
^^^^^^^^

This API is used to update backend servers in batches.

Constraints
^^^^^^^^^^^

-  A maximum of 200 backend servers can be modified at a time.  -  Two backend
   servers a backend server group cannot have the same private IP address or
   port number.  -  The subnet specified during server creation must be in the
   same VPC as the subnet from which the private IP address of the load
   balancer is assigned.

URI
^^^

PUT /v2.0/lbaas/pools/{pool_id}/members

.. table:: **Table 1** Parameter description

   ========= ========= ====== =============================================
   Parameter Mandatory Type   Description
   ========= ========= ====== =============================================
   pool_id   Yes       String Specifies the ID of the backend server group.
   ========= ========= ====== =============================================

Request
^^^^^^^

.. table:: **Table 2** Parameter description

   +-----------+-----------+--------+-----------------------------+
   | Parameter | Mandatory | Type   | Description                 |
   +===========+===========+========+=============================+
   | members   | Yes       | Array  | Lists the backend servers   |
   |           |           |        | in the backend server       |
   |           |           |        | group. If **action** is set |
   |           |           |        | to **add** or **replace**,  |
   |           |           |        | see :ref:`smub_t3`          |
   |           |           |        | for details about the       |
   |           |           |        | parameters. If **action**   |
   |           |           |        | is set to **delete**, see   |
   |           |           |        | :ref:`smub_t4`              |
   |           |           |        | for details about the       |
   |           |           |        | parameters.                 |
   |           |           |        |                             |
   |           |           |        | An empty list is supported. |
   |           |           |        | If **action** is set to     |
   |           |           |        | **add**, no backend server  |
   |           |           |        | is added to the backend     |
   |           |           |        | server group. If **action** |
   |           |           |        | is set to **replace**, all  |
   |           |           |        | backend servers are removed |
   |           |           |        | from the backend cloud      |
   |           |           |        | server group. If **action** |
   |           |           |        | is set to **delete**, no    |
   |           |           |        | backend server is removed.  |
   +-----------+-----------+--------+-----------------------------+
   | action    | No        | String | Specifies the operation     |
   |           |           |        | type. The value can be      |
   |           |           |        | **add**, **delete**, or     |
   |           |           |        | **replace**. The default    |
   |           |           |        | value is **replace**.       |
   |           |           |        |                             |
   |           |           |        | -  **add**: All backend     |
   |           |           |        |    servers in the request   |
   |           |           |        |    body are added to the    |
   |           |           |        |    backend server group in  |
   |           |           |        |    batches.                 |
   |           |           |        | -  **delete**: All backend  |
   |           |           |        |    servers in the request   |
   |           |           |        |    are removed from the     |
   |           |           |        |    backend server group in  |
   |           |           |        |    batches.                 |
   |           |           |        | -  **replace**: All backend |
   |           |           |        |    servers in the backend   |
   |           |           |        |    server group are         |
   |           |           |        |    replaced with those in   |
   |           |           |        |    the request body.        |
   +-----------+-----------+--------+-----------------------------+

.. _smub_t3:
.. table:: **Table 3** **members** parameter description

   +---------------+-----------+---------+-----------------------------+
   | Parameter     | Mandatory | Type    | Description                 |
   +===============+===========+=========+=============================+
   | name          | No        | String  | Specifies the backend       |
   |               |           |         | server name. The value is   |
   |               |           |         | an empty character string   |
   |               |           |         | by default.                 |
   |               |           |         |                             |
   |               |           |         | The value contains a        |
   |               |           |         | maximum of 255 characters.  |
   +---------------+-----------+---------+-----------------------------+
   | address       | Yes       | String  | Specifies the private IP    |
   |               |           |         | address of the backend      |
   |               |           |         | server. This IP address     |
   |               |           |         | must be in the subnet       |
   |               |           |         | specified by **subnet_id**. |
   |               |           |         |                             |
   |               |           |         | This parameter can be set   |
   |               |           |         | only to the IP address of   |
   |               |           |         | the primary NIC, for        |
   |               |           |         | example, 192.168.3.11.      |
   |               |           |         |                             |
   |               |           |         | The value contains a        |
   |               |           |         | maximum of 64 characters.   |
   +---------------+-----------+---------+-----------------------------+
   | protocol_port | Yes       | Integer | Specifies the port used by  |
   |               |           |         | the backend server. The     |
   |               |           |         | port number ranges from 1   |
   |               |           |         | to 65535.                   |
   +---------------+-----------+---------+-----------------------------+
   | subnet_id     | Yes       | String  | Specifies the ID of the     |
   |               |           |         | subnet where the backend    |
   |               |           |         | server works. The private   |
   |               |           |         | IP address of the backend   |
   |               |           |         | server is in this subnet.   |
   |               |           |         |                             |
   |               |           |         | IPv6 subnets are not        |
   |               |           |         | supported.                  |
   +---------------+-----------+---------+-----------------------------+
   | weight        | No        | Integer | Specifies the backend       |
   |               |           |         | server weight. The value    |
   |               |           |         | ranges from **0** to        |
   |               |           |         | **100**.                    |
   |               |           |         |                             |
   |               |           |         | If the value is **0**, the  |
   |               |           |         | backend server will not     |
   |               |           |         | accept new requests. The    |
   |               |           |         | default value is **1**.     |
   +---------------+-----------+---------+-----------------------------+

.. _smub_t4:
.. table:: **Table 4** **members** parameter description

   +-----------+-----------+--------+-----------------------------+
   | Parameter | Mandatory | Type   | Description                 |
   +===========+===========+========+=============================+
   | id        | Yes       | String | Specifies the backend       |
   |           |           |        | server ID.                  |
   |           |           |        |                             |
   |           |           |        | NOTE:                       |
   |           |           |        |                             |
   |           |           |        | -  The value of this        |
   |           |           |        |    parameter is not the ID  |
   |           |           |        |    of the server but an ID  |
   |           |           |        |    automatically generated  |
   |           |           |        |    for the backend server   |
   |           |           |        |    that has already         |
   |           |           |        |    associated with the load |
   |           |           |        |    balancer.                |
   |           |           |        | -  You can obtain this      |
   |           |           |        |    value by calling the API |
   |           |           |        |    described in :ref:`sml`. |
   +-----------+-----------+--------+-----------------------------+

Response
^^^^^^^^

None

Example Request
^^^^^^^^^^^^^^^

-  Example request 1: Adding backend servers in batches

   .. code::

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

   .. code::

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

   .. code::

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

Example Response
^^^^^^^^^^^^^^^^

-  Example response 1

   None

-  Example response 2

   None

-  Example response 3

   None

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.
