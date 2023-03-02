:original_name: elb_zq_hz_0002.html

.. _elb_zq_hz_0002:

Querying Backend Server Groups
==============================

Function
--------

This API is used to query the backend server groups and display them in a list. Filter query and pagination query are supported. Unless otherwise specified, exact match is applied.

Constraints
-----------

Parameters **marker**, **limit**, and **page_reverse** are used for pagination query. Parameters **marker** and **page_reverse** take effect only when they are used together with parameter **limit**.

URI
---

GET /v2.0/lbaas/pools

Request
-------

.. table:: **Table 1** Request parameters

   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter        | Mandatory       | Type            | Description                                                                                                                                                                                                                                                                                                                                |
   +==================+=================+=================+============================================================================================================================================================================================================================================================================================================================================+
   | marker           | No              | String          | Specifies the ID of the backend server group from which pagination query starts, that is, the ID of the last backend server group on the previous page. If this parameter is not specified, the first page will be queried.                                                                                                                |
   |                  |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                  |                 |                 | This parameter must be used together with **limit**.                                                                                                                                                                                                                                                                                       |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | limit            | No              | Integer         | Specifies the number of backend server groups on each page.                                                                                                                                                                                                                                                                                |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | page_reverse     | No              | Boolean         | Specifies the page direction. The value can be **true** or **false**, and the default value is **false**. The last page in the list requested with **page_reverse** set to **false** will not contain the "next" link, and the last page in the list requested with **page_reverse** set to **true** will not contain the "previous" link. |
   |                  |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                  |                 |                 | This parameter must be used together with **limit**.                                                                                                                                                                                                                                                                                       |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | id               | No              | String          | Specifies the ID of the backend server group.                                                                                                                                                                                                                                                                                              |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tenant_id        | No              | String          | Specifies the ID of the project where the backend server group is used.                                                                                                                                                                                                                                                                    |
   |                  |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                  |                 |                 | The value contains a maximum of 255 characters.                                                                                                                                                                                                                                                                                            |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name             | No              | String          | Specifies the backend server group name.                                                                                                                                                                                                                                                                                                   |
   |                  |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                  |                 |                 | The value contains a maximum of 255 characters.                                                                                                                                                                                                                                                                                            |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | description      | No              | String          | Provides supplementary information about the backend server group.                                                                                                                                                                                                                                                                         |
   |                  |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                  |                 |                 | The value contains a maximum of 255 characters.                                                                                                                                                                                                                                                                                            |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | healthmonitor_id | No              | String          | Specifies the ID of the health check configured for the backend server group.                                                                                                                                                                                                                                                              |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | loadbalancer_id  | No              | String          | Specifies the ID of the load balancer associated with the backend server group.                                                                                                                                                                                                                                                            |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | protocol         | No              | String          | Specifies the protocol that the backend server group uses to receive requests.                                                                                                                                                                                                                                                             |
   |                  |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                  |                 |                 | TCP, UDP, and HTTP are supported.                                                                                                                                                                                                                                                                                                          |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | lb_algorithm     | No              | String          | Specifies the load balancing algorithm of the backend server group.                                                                                                                                                                                                                                                                        |
   |                  |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                  |                 |                 | The value options are as follows:                                                                                                                                                                                                                                                                                                          |
   |                  |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                  |                 |                 | -  **ROUND_ROBIN**: indicates the weighted round robin algorithm.                                                                                                                                                                                                                                                                          |
   |                  |                 |                 | -  **LEAST_CONNECTIONS**: indicates the weighted least connections algorithm.                                                                                                                                                                                                                                                              |
   |                  |                 |                 | -  **SOURCE_IP**: indicates the source IP hash algorithm.                                                                                                                                                                                                                                                                                  |
   |                  |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                  |                 |                 | When the value is **SOURCE_IP**, the weights of backend servers in the server group are invalid. For details about parameter **weight**, see :ref:`Table 2 <elb_zq_hd_0003__en-us_topic_0096561555_en-us_topic_0049139656_table63335993>`.                                                                                                 |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | member_address   | No              | String          | Lists the IDs of backend servers in the backend server group.                                                                                                                                                                                                                                                                              |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | member_device_id | No              | String          | Specifies the ID of the ECS corresponding to the backend server in the backend server group.                                                                                                                                                                                                                                               |
   +------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Response
--------

.. table:: **Table 2** Parameter description

   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                 |
   +=======================+=======================+=============================================================================================================================================+
   | pools                 | Array                 | Lists the backend server groups. For details, see :ref:`Table 3 <elb_zq_hz_0002__table92302230217>`.                                        |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------+
   | pools_links           | List                  | Provides links to the previous or next page during pagination query, respectively.                                                          |
   |                       |                       |                                                                                                                                             |
   |                       |                       | This parameter exists only in the response body of pagination query. For details, see :ref:`Table 8 <elb_zq_hz_0002__table18892135113610>`. |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_hz_0002__table92302230217:

.. table:: **Table 3** **pools** parameter description

   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                |
   +=======================+=======================+============================================================================================================================================+
   | id                    | String                | Specifies the ID of the backend server group.                                                                                              |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
   | tenant_id             | String                | Specifies the ID of the project where the backend server group is used.                                                                    |
   |                       |                       |                                                                                                                                            |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                            |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                | Specifies the backend server group name.                                                                                                   |
   |                       |                       |                                                                                                                                            |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                            |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
   | description           | String                | Provides supplementary information about the backend server group.                                                                         |
   |                       |                       |                                                                                                                                            |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                            |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
   | protocol              | String                | Specifies the protocol that the backend server group uses to receive requests.                                                             |
   |                       |                       |                                                                                                                                            |
   |                       |                       | TCP, UDP, and HTTP are supported.                                                                                                          |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
   | lb_algorithm          | String                | Specifies the load balancing algorithm of the backend server group.                                                                        |
   |                       |                       |                                                                                                                                            |
   |                       |                       | The value options are as follows:                                                                                                          |
   |                       |                       |                                                                                                                                            |
   |                       |                       | -  **ROUND_ROBIN**: indicates the weighted round robin algorithm.                                                                          |
   |                       |                       | -  **LEAST_CONNECTIONS**: indicates the weighted least connections algorithm.                                                              |
   |                       |                       | -  **SOURCE_IP**: indicates the source IP hash algorithm.                                                                                  |
   |                       |                       |                                                                                                                                            |
   |                       |                       | When the value is **SOURCE_IP**, the weights of backend servers in the server group are invalid.                                           |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
   | members               | Array                 | Lists the IDs of backend servers in the backend server group.                                                                              |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
   | healthmonitor_id      | String                | Specifies the ID of the health check configured for the backend server group.                                                              |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up        | Boolean               | Specifies the administrative status of the backend server group.                                                                           |
   |                       |                       |                                                                                                                                            |
   |                       |                       | This parameter is reserved. The default value is **true**.                                                                                 |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
   | listeners             | Array                 | Lists the IDs of listeners associated with the backend server group.                                                                       |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
   | loadbalancers         | String                | Lists the IDs of load balancers associated with the backend server group.                                                                  |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
   | session_persistence   | Object                | Specifies whether to enable the sticky session feature. For details, see :ref:`Table 7 <elb_zq_hz_0002__table576515134510>`.               |
   |                       |                       |                                                                                                                                            |
   |                       |                       | Once the sticky session feature is enabled, requests from the same client are sent to the same backend server within the specified period. |
   |                       |                       |                                                                                                                                            |
   |                       |                       | When this feature is disabled, the parameter value is **null**.                                                                            |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------+

.. table:: **Table 4** **members** parameter description

   ========= ====== ==================================================
   Parameter Type   Description
   ========= ====== ==================================================
   id        String Specifies the ID of the associated backend server.
   ========= ====== ==================================================

.. table:: **Table 5** **listeners** parameter description

   +-----------+--------+----------------------------------------------------------+
   | Parameter | Type   | Description                                              |
   +===========+========+==========================================================+
   | id        | String | Specifies the ID of the associated backend server group. |
   +-----------+--------+----------------------------------------------------------+

.. table:: **Table 6** **loadbalancers** parameter description

   ========= ====== =================================================
   Parameter Type   Description
   ========= ====== =================================================
   id        String Specifies the ID of the associated load balancer.
   ========= ====== =================================================

.. _elb_zq_hz_0002__table576515134510:

.. table:: **Table 7** **session_persistence** parameter description

   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                                                                                                                                       |
   +=======================+=======================+===================================================================================================================================================================================================================================================================+
   | type                  | String                | Specifies the sticky session type.                                                                                                                                                                                                                                |
   |                       |                       |                                                                                                                                                                                                                                                                   |
   |                       |                       | The value can be one of the following:                                                                                                                                                                                                                            |
   |                       |                       |                                                                                                                                                                                                                                                                   |
   |                       |                       | -  **SOURCE_IP**: Requests are distributed based on the client's IP address. Requests from the same IP address are sent to the same backend server.                                                                                                               |
   |                       |                       | -  **HTTP_COOKIE**: When the client sends a request for the first time, the load balancer automatically generates a cookie and inserts the cookie into the response message. Subsequent requests are sent to the backend server that processes the first request. |
   |                       |                       | -  **APP_COOKIE**: When the client sends a request for the first time, the backend server that receives the request generates a cookie and inserts the cookie into the response message. Subsequent requests are sent to this backend server.                     |
   |                       |                       |                                                                                                                                                                                                                                                                   |
   |                       |                       | When the protocol of the backend server group is TCP, only **SOURCE_IP** takes effect. When the protocol of the backend server group is HTTP, only **HTTP_COOKIE** or **APP_COOKIE** takes effect.                                                                |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | cookie_name           | String                | Specifies the cookie name.                                                                                                                                                                                                                                        |
   |                       |                       |                                                                                                                                                                                                                                                                   |
   |                       |                       | This parameter is mandatory when the sticky session type is **APP_COOKIE**.                                                                                                                                                                                       |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | persistence_timeout   | Integer               | Specifies the sticky session timeout duration in minutes.                                                                                                                                                                                                         |
   |                       |                       |                                                                                                                                                                                                                                                                   |
   |                       |                       | This parameter is invalid when **type** is set to **APP_COOKIE**.                                                                                                                                                                                                 |
   |                       |                       |                                                                                                                                                                                                                                                                   |
   |                       |                       | -  Optional value ranges are as follows:                                                                                                                                                                                                                          |
   |                       |                       |                                                                                                                                                                                                                                                                   |
   |                       |                       |    -  When the protocol of the backend server group is TCP or UDP, the value ranges from **1** to **60**.                                                                                                                                                         |
   |                       |                       |    -  When the protocol of the backend server group is HTTP or HTTPS, the value ranges from **1** to **1440**.                                                                                                                                                    |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_hz_0002__table18892135113610:

.. table:: **Table 8** **pools_links** parameter description

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

-  Example request 1: Querying backend server groups by pages

   .. code-block:: text

      GET https://{Endpoint}/v2.0/lbaas/pools?limit=2

-  Example request 2: Querying backend server groups whose load balancing algorithm is **SOURCE_IP**

   .. code-block:: text

      GET https://{Endpoint}/v2.0/lbaas/pools?lb_algorithm=SOURCE_IP

Example Response
----------------

-  Example response 1

   .. code-block::

      {
          "pools": [
              {
                  "lb_algorithm": "SOURCE_IP",
                  "protocol": "TCP",
                  "description": "",
                  "admin_state_up": true,
                  "loadbalancers": [
                      {
                          "id": "07d28d4a-4899-40a3-a939-5d09d69019e1"
                      }
                  ],
                  "tenant_id": "1867112d054b427e808cc6096d8193a1",

                  "session_persistence": null,
                  "healthmonitor_id": null,
                  "listeners": [
                      {
                          "id": "1b421c2d-7e78-4a78-9ee4-c8ccba41f15b"
                      }
                  ],
                  "members": [
                      {
                          "id": "88f9c079-29cb-435a-b98f-0c5c0b90c2bd"
                      },
                      {
                          "id": "2f4c9644-d5d2-4cf8-a3c0-944239a4f58c"
                      }
                  ],
                  "id": "3a9f50bb-f041-4eac-a117-82472d8a0007",
                  "name": "my-pool"
              }
          ],
          "pools_links": [
              {
              "href": "https://{Endpoint}/v2.0/lbaas/pools?limit=2&marker=0469a5ad-6233-4669-8d38-5920f2bd95b6",
              "rel": "next"
              },
              {
              "href": "https://{Endpoint}/v2.0/lbaas/pools?limit=2&marker=02d43e35-e874-4139-bdba-d65609db20ab&page_reverse=True",
              "rel": "previous"
              }
          ]
      }

-  Example response 2

   .. code-block::

      {
          "pools": [
              {
                  "lb_algorithm": "SOURCE_IP",
                  "protocol": "TCP",
                  "description": "",
                  "admin_state_up": true,
                  "loadbalancers": [
                      {
                          "id": "07d28d4a-4899-40a3-a939-5d09d69019e1"
                      }
                  ],
                  "tenant_id": "1867112d054b427e808cc6096d8193a1",
                  "session_persistence": null,
                  "healthmonitor_id": null,
                  "listeners": [
                      {
                          "id": "1b421c2d-7e78-4a78-9ee4-c8ccba41f15b"
                      }
                  ],
                  "members": [
                      {
                          "id": "88f9c079-29cb-435a-b98f-0c5c0b90c2bd"
                      },
                      {
                          "id": "2f4c9644-d5d2-4cf8-a3c0-944239a4f58c"
                      }
                  ],
                  "id": "3a9f50bb-f041-4eac-a117-82472d8a0007",
                  "name": "my-pool"
              }
          ]
      }

-  Example response 2

   .. code-block::

      {
          "pools": [
              {
                  "lb_algorithm": "SOURCE_IP",
                  "protocol": "TCP",
                  "description": "",
                  "admin_state_up": true,
                  "loadbalancers": [
                      {
                          "id": "07d28d4a-4899-40a3-a939-5d09d69019e1"
                      }
                  ],
                  "tenant_id": "1867112d054b427e808cc6096d8193a1",
                  "session_persistence": null,
                  "healthmonitor_id": null,
                  "listeners": [
                      {
                          "id": "1b421c2d-7e78-4a78-9ee4-c8ccba41f15b"
                      }
                  ],
                  "members": [
                      {
                          "id": "88f9c079-29cb-435a-b98f-0c5c0b90c2bd"
                      },
                      {
                          "id": "2f4c9644-d5d2-4cf8-a3c0-944239a4f58c"
                      }
                  ],
                  "id": "3a9f50bb-f041-4eac-a117-82472d8a0007",
                  "name": "my-pool"
              }
          ]
      }

Status Codes
------------

See :ref:`HTTP Status Codes of Shared Load Balancers <elb_gc_0002>`.
