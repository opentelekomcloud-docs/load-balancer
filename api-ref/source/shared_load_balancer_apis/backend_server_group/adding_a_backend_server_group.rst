:original_name: elb_zq_hz_0001.html

.. _elb_zq_hz_0001:

Adding a Backend Server Group
=============================

Function
--------

This API is used to add a backend server group. After multiple backend servers are added to a backend server group, requests are distributed among backend servers based on the load balancing algorithm configured for the backend server group and the weight set for each backend server.

Constraints
-----------

-  Backend server groups using different protocols cannot be added to the same listener.
-  If parameter **session-persistence** is configured, parameter **cookie_name** is available only when the value of **type** is **APP_COOKIE**.

URI
---

POST /v2.0/lbaas/pools

Request
-------

.. table:: **Table 1** Parameter description

   +-----------+-----------+--------+-------------------------------------------------------------------------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                                                                                   |
   +===========+===========+========+===============================================================================================================================+
   | pool      | Yes       | Object | Specifies the backend server group. For details, see :ref:`Table 2 <elb_zq_hz_0001__en-us_topic_0096561549_table1263319159>`. |
   +-----------+-----------+--------+-------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_hz_0001__en-us_topic_0096561549_table1263319159:

.. table:: **Table 2** **pool** parameter description

   +---------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter           | Mandatory       | Type            | Description                                                                                                                                                                         |
   +=====================+=================+=================+=====================================================================================================================================================================================+
   | tenant_id           | No              | String          | Specifies the ID of the project where the backend server group is used.                                                                                                             |
   |                     |                 |                 |                                                                                                                                                                                     |
   |                     |                 |                 | The value must be the same as the value of **project_id** in the token.                                                                                                             |
   |                     |                 |                 |                                                                                                                                                                                     |
   |                     |                 |                 | The value contains a maximum of 255 characters.                                                                                                                                     |
   +---------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                | No              | String          | Specifies the name of the backend server group.                                                                                                                                     |
   |                     |                 |                 |                                                                                                                                                                                     |
   |                     |                 |                 | The value contains a maximum of 255 characters.                                                                                                                                     |
   +---------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | description         | No              | String          | Provides supplementary information about the backend server group.                                                                                                                  |
   |                     |                 |                 |                                                                                                                                                                                     |
   |                     |                 |                 | The value contains a maximum of 255 characters.                                                                                                                                     |
   +---------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | protocol            | Yes             | String          | Specifies the protocol that the backend server group uses to receive requests.                                                                                                      |
   |                     |                 |                 |                                                                                                                                                                                     |
   |                     |                 |                 | TCP, UDP, and HTTP are supported.                                                                                                                                                   |
   |                     |                 |                 |                                                                                                                                                                                     |
   |                     |                 |                 | When a backend server group is associated with a listener, the relationships between the protocol used by the listener and the protocol of the backend server group are as follows: |
   |                     |                 |                 |                                                                                                                                                                                     |
   |                     |                 |                 | -  When the protocol used by the listener is **UDP**, the protocol of the backend server group must be **UDP**.                                                                     |
   |                     |                 |                 | -  When the protocol used by the listener is **TCP**, the protocol of the backend server group must be **TCP**.                                                                     |
   |                     |                 |                 | -  When the protocol used by the listener is **HTTP** or **TERMINATED_HTTPS**, the protocol of the backend server group must be **HTTP**.                                           |
   +---------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | lb_algorithm        | Yes             | String          | Specifies the load balancing algorithm of the backend server group.                                                                                                                 |
   |                     |                 |                 |                                                                                                                                                                                     |
   |                     |                 |                 | The value can be one of the following:                                                                                                                                              |
   |                     |                 |                 |                                                                                                                                                                                     |
   |                     |                 |                 | -  **ROUND_ROBIN**: indicates the weighted round robin algorithm.                                                                                                                   |
   |                     |                 |                 | -  **LEAST_CONNECTIONS**: indicates the weighted least connections algorithm.                                                                                                       |
   |                     |                 |                 | -  **SOURCE_IP**: indicates the source IP hash algorithm.                                                                                                                           |
   |                     |                 |                 |                                                                                                                                                                                     |
   |                     |                 |                 | When the value is **SOURCE_IP**, the weights of backend servers in the server group are invalid.                                                                                    |
   +---------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up      | No              | Boolean         | Specifies the administrative status of the backend server group.                                                                                                                    |
   |                     |                 |                 |                                                                                                                                                                                     |
   |                     |                 |                 | This parameter is reserved, and the default value is **true**.                                                                                                                      |
   +---------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | listener_id         | No              | String          | Specifies the ID of the listener associated with the backend server group.                                                                                                          |
   |                     |                 |                 |                                                                                                                                                                                     |
   |                     |                 |                 | Specify either **listener_id** or **loadbalancer_id**, or both of them.                                                                                                             |
   +---------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | loadbalancer_id     | No              | String          | Specifies the ID of the load balancer associated with the backend server group.                                                                                                     |
   |                     |                 |                 |                                                                                                                                                                                     |
   |                     |                 |                 | Specify either **listener_id** or **loadbalancer_id**, or both of them.                                                                                                             |
   +---------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | session_persistence | No              | Object          | Specifies the sticky session timeout duration in minutes. For details, see :ref:`Table 3 <elb_zq_hz_0001__en-us_topic_0096561549_table168044271458>`.                               |
   |                     |                 |                 |                                                                                                                                                                                     |
   |                     |                 |                 | If the value is **null**, the sticky session feature is disabled.                                                                                                                   |
   +---------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_hz_0001__en-us_topic_0096561549_table168044271458:

.. table:: **Table 3** **session_persistence** parameter description

   +---------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter           | Mandatory       | Type            | Description                                                                                                                                                                                                                                                       |
   +=====================+=================+=================+===================================================================================================================================================================================================================================================================+
   | type                | Yes             | String          | Specifies the sticky session type.                                                                                                                                                                                                                                |
   |                     |                 |                 |                                                                                                                                                                                                                                                                   |
   |                     |                 |                 | The value can be one of the following:                                                                                                                                                                                                                            |
   |                     |                 |                 |                                                                                                                                                                                                                                                                   |
   |                     |                 |                 | -  **SOURCE_IP**: Requests are distributed based on the client's IP address. Requests from the same IP address are sent to the same backend server.                                                                                                               |
   |                     |                 |                 | -  **HTTP_COOKIE**: When the client sends a request for the first time, the load balancer automatically generates a cookie and inserts the cookie into the response message. Subsequent requests are sent to the backend server that processes the first request. |
   |                     |                 |                 | -  **APP_COOKIE**: When the client sends a request for the first time, the backend server that receives the request generates a cookie and inserts the cookie into the response message. Subsequent requests are sent to this backend server.                     |
   |                     |                 |                 |                                                                                                                                                                                                                                                                   |
   |                     |                 |                 | When the protocol of the backend server group is TCP, only **SOURCE_IP** takes effect. When the protocol of the backend server group is HTTP, only **HTTP_COOKIE** or **APP_COOKIE** takes effect.                                                                |
   +---------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | cookie_name         | No              | String          | Specifies the cookie name.                                                                                                                                                                                                                                        |
   |                     |                 |                 |                                                                                                                                                                                                                                                                   |
   |                     |                 |                 | This parameter is mandatory when the sticky session type is **APP_COOKIE**.                                                                                                                                                                                       |
   +---------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | persistence_timeout | No              | Integer         | Specifies the sticky session timeout duration in minutes.                                                                                                                                                                                                         |
   |                     |                 |                 |                                                                                                                                                                                                                                                                   |
   |                     |                 |                 | This parameter is invalid when **type** is set to **APP_COOKIE**.                                                                                                                                                                                                 |
   |                     |                 |                 |                                                                                                                                                                                                                                                                   |
   |                     |                 |                 | The value range varies depending on the protocol of the backend server group:                                                                                                                                                                                     |
   |                     |                 |                 |                                                                                                                                                                                                                                                                   |
   |                     |                 |                 | -  When the protocol of the backend server group is TCP or UDP, the value ranges from **1** to **60**.                                                                                                                                                            |
   |                     |                 |                 | -  When the protocol of the backend server group is HTTP or HTTPS, the value ranges from **1** to **1440**.                                                                                                                                                       |
   +---------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Response
--------

.. table:: **Table 4** Response parameters

   +-----------+--------+---------------------------------------------------------------------------------------------------------------------------------+
   | Parameter | Type   | Description                                                                                                                     |
   +===========+========+=================================================================================================================================+
   | pool      | Object | Specifies the backend server group. For details, see :ref:`Table 5 <elb_zq_hz_0001__en-us_topic_0096561549_table549816561954>`. |
   +-----------+--------+---------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_hz_0001__en-us_topic_0096561549_table549816561954:

.. table:: **Table 5** **pools** parameter description

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

.. table:: **Table 6** **members** parameter description

   ========= ====== ==================================================
   Parameter Type   Description
   ========= ====== ==================================================
   id        String Specifies the ID of the associated backend server.
   ========= ====== ==================================================

.. table:: **Table 7** **listeners** parameter description

   +-----------+--------+----------------------------------------------------------+
   | Parameter | Type   | Description                                              |
   +===========+========+==========================================================+
   | id        | String | Specifies the ID of the associated backend server group. |
   +-----------+--------+----------------------------------------------------------+

.. table:: **Table 8** **loadbalancers** parameter description

   ========= ====== =================================================
   Parameter Type   Description
   ========= ====== =================================================
   id        String Specifies the ID of the associated load balancer.
   ========= ====== =================================================

.. _elb_zq_hz_0001__en-us_topic_0096561549_table1659974218492:

.. table:: **Table 9** **session_persistence** parameter description

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

-  Example request 1: Adding a backend server group with the sticky session feature disabled

   .. code-block:: text

      POST https://{Endpoint}/v2.0/lbaas/pools

      {
          "pool": {
              "lb_algorithm":"ROUND_ROBIN",
              "loadbalancer_id": "63ad9dfe-4750-479f-9630-ada43ccc8117",
              "protocol":"HTTP"
          }
      }

-  Example request 2: Adding an HTTP backend server group with the value of **type** set to **APP_COOKIE**

   .. code-block:: text

      POST https://{Endpoint}/v2.0/lbaas/pools

      {
        "pool": {
          "lb_algorithm": "ROUND_ROBIN",
          "listener_id": "370fb112-e920-486a-b051-1d0d30704dd3",
          "protocol": "HTTP",
          "session_persistence": {
            "cookie_name": "my_cookie",
            "type": "APP_COOKIE",
            "persistence_timeout": 1
          },
          "admin_state_up": true
        }
      }

-  Example request 3: Adding an HTTP backend server group with the value of **type** set to **HTTP_COOKIE**

   .. code-block:: text

      POST https://{Endpoint}/v2.0/lbaas/pools

      {
          "pool": {
              "lb_algorithm":"ROUND_ROBIN",
              "loadbalancer_id": "63ad9dfe-4750-479f-9630-ada43ccc8117",
              "protocol":"HTTP",
              "session_persistence":{
                  "type":"HTTP_COOKIE"
              }
          }
      }

Example Response
----------------

-  Example response 1

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
              "id": "4e496951-befb-47bf-9573-c1cd11825c07",
              "name": ""
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
              "id": "6b041b9e-976b-40ba-b075-375be6110b53"
            }
          ],
          "tenant_id": "145483a5107745e9b3d80f956713e6a3",

          "session_persistence": {
            "cookie_name": "my_cookie",
            "type": "APP_COOKIE",
            "persistence_timeout": 1
          },
          "healthmonitor_id": null,
          "listeners": [
            {
              "id": "370fb112-e920-486a-b051-1d0d30704dd3"
            }
          ],
          "members": [

          ],
          "id": "307f8968-9474-4d0c-8434-66be09dabcc1",
          "name": ""
        }
      }

-  Example response 3

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
              "session_persistence": {
                  "persistence_timeout": 1440,
                  "cookie_name": null,
                  "type": "HTTP_COOKIE"
              },
              "healthmonitor_id": null,
              "listeners": [],
              "members": [],
              "id": "d46eab56-d76b-4cd3-8952-3c3c4cf113aa",
              "name": ""
          }
      }

Status Code
-----------

For details, see :ref:`HTTP Status Codes of Shared Load Balancers <elb_gc_0002>`.
