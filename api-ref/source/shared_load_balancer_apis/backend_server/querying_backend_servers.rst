:original_name: elb_zq_hd_0002.html

.. _elb_zq_hd_0002:

Querying Backend Servers
========================

Function
--------

This API is used to query backend servers in a specific backend server group. Filter query and pagination query are supported. Unless otherwise specified, exact match is applied.

Constraints
-----------

Parameters **marker**, **limit**, and **page_reverse** are used for pagination query. Parameters **marker** and **page_reverse** take effect only when they are used together with parameter **limit**.

URI
---

GET /v2.0/lbaas/pools/{pool_id}/members

.. table:: **Table 1** Parameter description

   ========= ========= ====== =============================================
   Parameter Mandatory Type   Description
   ========= ========= ====== =============================================
   pool_id   Yes       String Specifies the ID of the backend server group.
   ========= ========= ====== =============================================

Request
-------

.. table:: **Table 2** Parameter description

   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                                                                                                                                                                                                                                                                                |
   +=================+=================+=================+============================================================================================================================================================================================================================================================================================================================================+
   | marker          | No              | String          | Specifies the ID of the backend server from which pagination query starts, that is, the ID of the last backend server on the previous page. If this parameter is not specified, the first page will be queried.                                                                                                                            |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 | This parameter must be used together with **limit**.                                                                                                                                                                                                                                                                                       |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | limit           | No              | Integer         | Specifies the number of backend servers on each page. If this parameter is not set, all backend servers are queried by default.                                                                                                                                                                                                            |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | page_reverse    | No              | Boolean         | Specifies the page direction. The value can be **true** or **false**, and the default value is **false**. The last page in the list requested with **page_reverse** set to **false** will not contain the "next" link, and the last page in the list requested with **page_reverse** set to **true** will not contain the "previous" link. |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 | This parameter must be used together with **limit**.                                                                                                                                                                                                                                                                                       |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | id              | No              | String          | Specifies the backend server ID.                                                                                                                                                                                                                                                                                                           |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 | .. note::                                                                                                                                                                                                                                                                                                                                  |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 |    The value of this parameter is not the ID of the server but an ID automatically generated for the backend server that has already associated with the load balancer.                                                                                                                                                                    |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tenant_id       | No              | String          | Specifies the ID of the project where the backend server is used.                                                                                                                                                                                                                                                                          |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 | The value contains a maximum of 255 characters.                                                                                                                                                                                                                                                                                            |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name            | No              | String          | Specifies the backend server name.                                                                                                                                                                                                                                                                                                         |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 | The value contains a maximum of 255 characters.                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 | .. note::                                                                                                                                                                                                                                                                                                                                  |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 |    The value of this parameter is not the name of server. It is the name automatically generated for the backend server associated with the load balancer.                                                                                                                                                                                 |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | address         | No              | String          | Specifies the private IP address of the backend server.                                                                                                                                                                                                                                                                                    |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 | The value contains a maximum of 64 characters.                                                                                                                                                                                                                                                                                             |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | protocol_port   | No              | Integer         | Specifies the port used by the backend server.                                                                                                                                                                                                                                                                                             |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | subnet_id       | No              | String          | Specifies the ID of the subnet where the backend server works.                                                                                                                                                                                                                                                                             |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up  | No              | Boolean         | Specifies the administrative status of the backend server.                                                                                                                                                                                                                                                                                 |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 | This parameter is reserved, and the default value is **true**.                                                                                                                                                                                                                                                                             |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | weight          | No              | Integer         | Specifies the backend server weight.                                                                                                                                                                                                                                                                                                       |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Response
--------

.. table:: **Table 3** Response parameters

   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                                      |
   +=======================+=======================+==================================================================================================================================================================+
   | members               | Array                 | Lists the backend servers in the backend server group. For details, see :ref:`Table 4 <elb_zq_hd_0002__en-us_topic_0096561554_table1877212199143>`.              |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | members_links         | Array                 | Provides links to the previous or next page during pagination query, respectively.                                                                               |
   |                       |                       |                                                                                                                                                                  |
   |                       |                       | This parameter exists only in the response body of pagination query. For details, see :ref:`Table 5 <elb_zq_hd_0002__en-us_topic_0096561554_table109691887394>`. |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_hd_0002__en-us_topic_0096561554_table1877212199143:

.. table:: **Table 4** **members** parameter description

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
   | operating_status      | String                | Specifies the operating status of the load balancer. This parameter is reserved, and its value can only be **ONLINE**.                                                  |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_hd_0002__en-us_topic_0096561554_table109691887394:

.. table:: **Table 5** **members_links** parameter description

   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                   |
   +=======================+=======================+===============================================================================================+
   | href                  | String                | Provides links to the previous or next page during pagination query, respectively.            |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------+
   | rel                   | String                | Specifies the prompt of the previous or next page. The value can be **next** or **previous**. |
   |                       |                       |                                                                                               |
   |                       |                       | -  **next**: indicates the URL of the next page.                                              |
   |                       |                       | -  **previous**: indicates the URL of the previous page.                                      |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------+

Example Request
---------------

-  Example request 1: Querying all backend servers

   .. code-block:: text

      GET https://{Endpoint}/v2.0/lbaas/pools/5a9a3e9e-d1aa-448e-af37-a70171f2a332/members

-  Example request 2: Querying the backend cloud server whose IP address is 10.0.0.8 and port number is 80

   .. code-block:: text

      GET https://{Endpoint}/v2.0/lbaas/pools/5a9a3e9e-d1aa-448e-af37-a70171f2a332/members?address=10.0.0.8&protocol_port=80

Example Response
----------------

-  Example response 1

   .. code-block::

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

   .. code-block::

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
-----------

For details, see :ref:`Status Codes <elb_gc_1102>`.
