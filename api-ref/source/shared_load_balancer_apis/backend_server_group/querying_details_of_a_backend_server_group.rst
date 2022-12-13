:original_name: elb_zq_hz_0003.html

.. _elb_zq_hz_0003:

Querying Details of a Backend Server Group
==========================================

Function
--------

This API is used to query details about a backend server group using its ID.

URI
---

GET /v2.0/lbaas/pools/{pool_id}

.. table:: **Table 1** Parameter description

   ========= ========= ====== =============================================
   Parameter Mandatory Type   Description
   ========= ========= ====== =============================================
   pool_id   Yes       String Specifies the ID of the backend server group.
   ========= ========= ====== =============================================

Request
-------

None

Response
--------

.. table:: **Table 2** Response parameters

   +-----------+--------+---------------------------------------------------------------------------------------------------------------------------------+
   | Parameter | Type   | Description                                                                                                                     |
   +===========+========+=================================================================================================================================+
   | pool      | Object | Specifies the backend server group. For details, see :ref:`Table 3 <elb_zq_hz_0003__en-us_topic_0096561548_table374714321310>`. |
   +-----------+--------+---------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_hz_0003__en-us_topic_0096561548_table374714321310:

.. table:: **Table 3** **pools** parameter description

   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                                                         |
   +=======================+=======================+=====================================================================================================================================================================================+
   | id                    | String                | Specifies the ID of the backend server group.                                                                                                                                       |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tenant_id             | String                | Specifies the ID of the project where the backend server group is used.                                                                                                             |
   |                       |                       |                                                                                                                                                                                     |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                                                     |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                | Specifies the name of the backend server group.                                                                                                                                     |
   |                       |                       |                                                                                                                                                                                     |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                                                     |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | description           | String                | Provides supplementary information about the backend server group.                                                                                                                  |
   |                       |                       |                                                                                                                                                                                     |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                                                     |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | protocol              | String                | Specifies the protocol that the backend server group uses to receive requests.                                                                                                      |
   |                       |                       |                                                                                                                                                                                     |
   |                       |                       | TCP, UDP, and HTTP are supported.                                                                                                                                                   |
   |                       |                       |                                                                                                                                                                                     |
   |                       |                       | When a backend server group is associated with a listener, the relationships between the protocol used by the listener and the protocol of the backend server group are as follows: |
   |                       |                       |                                                                                                                                                                                     |
   |                       |                       | -  When the protocol used by the listener is **UDP**, the protocol of the backend server group must be **UDP**.                                                                     |
   |                       |                       | -  When the protocol used by the listener is **TCP**, the protocol of the backend server group must be **TCP**.                                                                     |
   |                       |                       | -  When the protocol used by the listener is **HTTP** or **TERMINATED_HTTPS**, the protocol of the backend server group must be **HTTP**.                                           |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | lb_algorithm          | String                | Specifies the load balancing algorithm of the backend server group.                                                                                                                 |
   |                       |                       |                                                                                                                                                                                     |
   |                       |                       | The value can be one of the following:                                                                                                                                              |
   |                       |                       |                                                                                                                                                                                     |
   |                       |                       | -  **ROUND_ROBIN**: indicates the weighted round robin algorithm.                                                                                                                   |
   |                       |                       | -  **LEAST_CONNECTIONS**: indicates the weighted least connections algorithm.                                                                                                       |
   |                       |                       | -  **SOURCE_IP**: indicates the source IP hash algorithm. When the value is **SOURCE_IP**, the weights of backend servers in the server group are invalid.                          |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | members               | Array                 | Lists the IDs of backend servers in the backend server group.                                                                                                                       |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | healthmonitor_id      | String                | Specifies the ID of the health check configured for the backend server group.                                                                                                       |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up        | Boolean               | Specifies the administrative status of the backend server group.                                                                                                                    |
   |                       |                       |                                                                                                                                                                                     |
   |                       |                       | This parameter is reserved. The value can be **true** or **false**.                                                                                                                 |
   |                       |                       |                                                                                                                                                                                     |
   |                       |                       | -  **true**: Enabled                                                                                                                                                                |
   |                       |                       | -  **false**: Disabled                                                                                                                                                              |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | listeners             | Array                 | Lists the IDs of listeners associated with the backend server group.                                                                                                                |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | loadbalancers         | Array                 | Lists the IDs of load balancers associated with the backend server group.                                                                                                           |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | session_persistence   | Object                | Specifies whether to enable sticky sessions. For details, see :ref:`Table 9 <elb_zq_hz_0001__en-us_topic_0096561549_table1659974218492>`.                                           |
   |                       |                       |                                                                                                                                                                                     |
   |                       |                       | Once sticky session are enabled, requests from the same client are sent to the same backend server during the session.                                                              |
   |                       |                       |                                                                                                                                                                                     |
   |                       |                       | When sticky sessions are disabled, the value is **null**.                                                                                                                           |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

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

Example Request
---------------

-  Example request: Querying details of a backend server group

   .. code-block:: text

      GET https://{Endpoint}/v2.0/lbaas/pools/5a9a3e9e-d1aa-448e-af37-a70171f2a332

Example Response
----------------

-  Example response

   .. code-block::

      {
          "pool": {
              "lb_algorithm": "SOURCE_IP",
              "protocol": "TCP",
              "description": "",
              "admin_state_up": true,
              "loadbalancers": [
                  {
                      "id": "6f52004c-3fe9-4c09-b8ce-ed9d9c74a3b1"
                  }
              ],
              "tenant_id": "1867112d054b427e808cc6096d8193a1",
              "session_persistence": null,
              "healthmonitor_id": null,
              "listeners": [
                  {
                      "id": "6e29b2cd-4e53-40f6-ae7b-29e918de67f2"
                  }
              ],
              "members": [],
              "id": "5a9a3e9e-d1aa-448e-af37-a70171f2a332",
              "name": "my-pool"
          }
      }

Status Code
-----------

For details, see :ref:`Status Codes <elb_gc_1102>`.
