:original_name: elb_zq_hz_0004.html

.. _elb_zq_hz_0004:

Updating a Backend Server Group
===============================

Function
--------

This API is used to update a backend server group.

Constraints
-----------

If the provisioning status of the load balancer associated with a backend server group is not **ACTIVE**, the backend server group cannot be updated.

URI
---

PUT /v2.0/lbaas/pools/{pool_id}

.. table:: **Table 1** Parameter description

   ========= ========= ====== =============================================
   Parameter Mandatory Type   Description
   ========= ========= ====== =============================================
   pool_id   Yes       String Specifies the ID of the backend server group.
   ========= ========= ====== =============================================

Request
-------

.. table:: **Table 2** Parameter description

   +-----------+-----------+--------+-----------------------------------------------------------------------------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                                                                                       |
   +===========+===========+========+===================================================================================================================================+
   | pool      | Yes       | Object | Specifies the backend server group. For details, see :ref:`Table 3 <elb_zq_hz_0004__en-us_topic_0096561550_table14485185810613>`. |
   +-----------+-----------+--------+-----------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_hz_0004__en-us_topic_0096561550_table14485185810613:

.. table:: **Table 3** **pool** parameter description

   +---------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter           | Mandatory       | Type            | Description                                                                                                                                             |
   +=====================+=================+=================+=========================================================================================================================================================+
   | name                | No              | String          | Specifies the name of the backend server group.                                                                                                         |
   |                     |                 |                 |                                                                                                                                                         |
   |                     |                 |                 | The value contains a maximum of 255 characters.                                                                                                         |
   +---------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
   | description         | No              | String          | Provides supplementary information about the backend server group.                                                                                      |
   |                     |                 |                 |                                                                                                                                                         |
   |                     |                 |                 | The value contains a maximum of 255 characters.                                                                                                         |
   +---------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
   | lb_algorithm        | No              | String          | Specifies the load balancing algorithm of the backend server group.                                                                                     |
   |                     |                 |                 |                                                                                                                                                         |
   |                     |                 |                 | Value options:                                                                                                                                          |
   |                     |                 |                 |                                                                                                                                                         |
   |                     |                 |                 | -  **ROUND_ROBIN**: indicates the weighted round robin algorithm.                                                                                       |
   |                     |                 |                 | -  **LEAST_CONNECTIONS**: indicates the weighted least connections algorithm.                                                                           |
   |                     |                 |                 | -  **SOURCE_IP**: indicates the source IP hash algorithm.                                                                                               |
   |                     |                 |                 |                                                                                                                                                         |
   |                     |                 |                 | When the value is **SOURCE_IP**, the weights of backend servers in the server group are invalid.                                                        |
   +---------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up      | No              | Boolean         | Specifies the administrative status of the backend server group.                                                                                        |
   |                     |                 |                 |                                                                                                                                                         |
   |                     |                 |                 | This parameter is reserved, and the default value is **true**.                                                                                          |
   +---------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
   | session_persistence | No              | Object          | Specifies whether to enable the sticky session feature. For details, see :ref:`Table 10 <elb_zq_hz_0004__en-us_topic_0096561550_table112431127175217>`. |
   |                     |                 |                 |                                                                                                                                                         |
   |                     |                 |                 | Once sticky session are enabled, requests from the same client are sent to the same backend server during the session.                                  |
   |                     |                 |                 |                                                                                                                                                         |
   |                     |                 |                 | When sticky sessions are disabled, the value is **null**.                                                                                               |
   +---------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+

.. table:: **Table 4** **session_persistence** parameter description

   +---------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter           | Mandatory       | Type            | Description                                                                                                                                                                                                                                                       |
   +=====================+=================+=================+===================================================================================================================================================================================================================================================================+
   | type                | No              | String          | Specifies the sticky session type.                                                                                                                                                                                                                                |
   |                     |                 |                 |                                                                                                                                                                                                                                                                   |
   |                     |                 |                 | Value options:                                                                                                                                                                                                                                                    |
   |                     |                 |                 |                                                                                                                                                                                                                                                                   |
   |                     |                 |                 | -  **SOURCE_IP**: Requests are distributed based on the client's IP address. Requests from the same IP address are sent to the same backend server.                                                                                                               |
   |                     |                 |                 | -  **HTTP_COOKIE**: When the client sends a request for the first time, the load balancer automatically generates a cookie and inserts the cookie into the response message. Subsequent requests are sent to the backend server that processes the first request. |
   |                     |                 |                 | -  **APP_COOKIE**: When the client sends a request for the first time, the backend server that receives the request generates a cookie and inserts the cookie into the response message. Subsequent requests are sent to this backend server.                     |
   |                     |                 |                 |                                                                                                                                                                                                                                                                   |
   |                     |                 |                 | -  When the protocol of the backend server group is TCP, only **SOURCE_IP** takes effect. When the protocol of the backend server group is HTTP, only **HTTP_COOKIE** or **APP_COOKIE** takes effect.                                                             |
   +---------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | cookie_name         | No              | String          | Specifies the cookie name.                                                                                                                                                                                                                                        |
   |                     |                 |                 |                                                                                                                                                                                                                                                                   |
   |                     |                 |                 | This parameter is mandatory and can be specified when the sticky session type is **APP_COOKIE**.                                                                                                                                                                  |
   +---------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | persistence_timeout | No              | Integer         | Specifies the sticky session timeout duration in minutes.                                                                                                                                                                                                         |
   |                     |                 |                 |                                                                                                                                                                                                                                                                   |
   |                     |                 |                 | This parameter is invalid when **type** is set to **APP_COOKIE**.                                                                                                                                                                                                 |
   |                     |                 |                 |                                                                                                                                                                                                                                                                   |
   |                     |                 |                 | Value range options are as follows:                                                                                                                                                                                                                               |
   |                     |                 |                 |                                                                                                                                                                                                                                                                   |
   |                     |                 |                 | -  When the protocol of the backend server group is TCP or UDP, the value ranges from **1** to **60**.                                                                                                                                                            |
   |                     |                 |                 | -  When the protocol of the backend server group is HTTP or HTTPS, the value ranges from **1** to **1440**.                                                                                                                                                       |
   +---------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Response
--------

.. table:: **Table 5** Parameter description

   +-----------+--------+---------------------------------------------------------------------------------------------------------------------------------+
   | Parameter | Type   | Description                                                                                                                     |
   +===========+========+=================================================================================================================================+
   | pool      | Object | Specifies the backend server group. For details, see :ref:`Table 6 <elb_zq_hz_0004__en-us_topic_0096561550_table186106238710>`. |
   +-----------+--------+---------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_hz_0004__en-us_topic_0096561550_table186106238710:

.. table:: **Table 6** **pools** parameter description

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

.. table:: **Table 7** **members** parameter description

   ========= ====== ==================================================
   Parameter Type   Description
   ========= ====== ==================================================
   id        String Specifies the ID of the associated backend server.
   ========= ====== ==================================================

.. table:: **Table 8** **listeners** parameter description

   +-----------+--------+----------------------------------------------------------+
   | Parameter | Type   | Description                                              |
   +===========+========+==========================================================+
   | id        | String | Specifies the ID of the associated backend server group. |
   +-----------+--------+----------------------------------------------------------+

.. table:: **Table 9** **loadbalancers** parameter description

   ========= ====== =================================================
   Parameter Type   Description
   ========= ====== =================================================
   id        String Specifies the ID of the associated load balancer.
   ========= ====== =================================================

.. _elb_zq_hz_0004__en-us_topic_0096561550_table112431127175217:

.. table:: **Table 10** **session_persistence** parameter description

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

-  Example request 1: Updating a backend server group

   .. code-block:: text

      PUT https://{Endpoint}/v2.0/lbaas/pools/12ff63af-4127-4074-a251-bcb2ecc53ebe

      {
          "pool": {
              "name": "pool2",
              "description": "pool two",
              "lb_algorithm": "LEAST_CONNECTIONS"
          }
      }

-  Example request 2: Disabling the sticky session feature of a backend server group

   .. code-block:: text

      PUT https://{Endpoint}/v2.0/lbaas/pools/d46eab56-d76b-4cd3-8952-3c3c4cf113aa

      {
          "pool": {
              "session_persistence":null
          }
      }

Example Response
----------------

-  Example response 1

   .. code-block::

      {
          "pool": {
              "lb_algorithm": "LEAST_CONNECTIONS",
              "protocol": "HTTP",
              "description": "pool two",
              "loadbalancers": [
                  {
                      "id": "63ad9dfe-4750-479f-9630-ada43ccc8117"
                  }
              ],
              "admin_state_up": true,
              "tenant_id": "1a3e005cf9ce40308c900bcb08e5320c",
              "session_persistence": {
                  "cookie_name": null,
                  "type": "HTTP_COOKIE",
                  "persistence_timeout": 1
              },
              "healthmonitor_id": null,
              "listeners": [
                  {
                      "id": "39de4d56-d663-46e5-85a1-5b9d5fa17829"
                  }
              ],
              "members": [],
              "id": "12ff63af-4127-4074-a251-bcb2ecc53ebe",
              "name": "pool2"
          }
      }

-  Example response 2

   .. code-block::

      {
          "pool": {
              "lb_algorithm": "ROUND_ROBIN",
              "protocol": "HTTP",
              "description": "",
              "admin_state_up": true,
              "loadbalancers": [
                  {
                      "id": "63ad9dfe-4750-479f-9630-ada43ccc8117"
                  }
              ],
              "tenant_id": "601240b9c5c94059b63d484c92cfe308",
              "session_persistence": null,
              "healthmonitor_id": null,
              "listeners": [],
              "members": [],
              "id": "d46eab56-d76b-4cd3-8952-3c3c4cf113aa",
              "name": ""
          }
      }

Status Code
-----------

For details, see :ref:`Status Codes <elb_gc_1102>`.
