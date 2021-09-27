===================
Backen Server Group
===================

Adding a Backend Server Group
=============================

Function
^^^^^^^^

This API is used to add a backend server group. After multiple backend servers
are added to a backend server group, requests are distributed among backend
servers based on the load balancing algorithm configured for the backend server
group and the weight set for each backend server.

Constraints
^^^^^^^^^^^

-  Backend server groups using different protocols cannot be added to the same
   listener.  -  If parameter **session-persistence** is configured, parameter
   **cookie_name** is available only when the value of **type** is
   **APP_COOKIE**.

URI
^^^

POST /v2.0/lbaas/pools

Request
^^^^^^^

.. table:: **Table 1** Parameter description

   +-----------+-----------+--------+---------------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                         |
   +===========+===========+========+=====================================================================+
   | pool      | Yes       | Object | Specifies the backend server group. For details, see :ref:`spc_t2`. |
   +-----------+-----------+--------+---------------------------------------------------------------------+

.. _spc_t2:
.. table:: **Table 2** **pool** parameter description

   +---------------------+-----------+---------+-----------------------------+
   | Parameter           | Mandatory | Type    | Description                 |
   +=====================+===========+=========+=============================+
   | tenant_id           | No        | String  | Specifies the ID of the     |
   |                     |           |         | project where the backend   |
   |                     |           |         | server group is used.       |
   |                     |           |         |                             |
   |                     |           |         | The value must be the same  |
   |                     |           |         | as the value of             |
   |                     |           |         | **project_id** in the       |
   |                     |           |         | token.                      |
   |                     |           |         |                             |
   |                     |           |         | The value contains a        |
   |                     |           |         | maximum of 255 characters.  |
   +---------------------+-----------+---------+-----------------------------+
   | name                | No        | String  | Specifies the name of the   |
   |                     |           |         | backend server group.       |
   |                     |           |         |                             |
   |                     |           |         | The value contains a        |
   |                     |           |         | maximum of 255 characters.  |
   +---------------------+-----------+---------+-----------------------------+
   | description         | No        | String  | Provides supplementary      |
   |                     |           |         | information about the       |
   |                     |           |         | backend server group.       |
   |                     |           |         |                             |
   |                     |           |         | The value contains a        |
   |                     |           |         | maximum of 255 characters.  |
   +---------------------+-----------+---------+-----------------------------+
   | protocol            | Yes       | String  | Specifies the protocol that |
   |                     |           |         | the backend server group    |
   |                     |           |         | uses to receive requests.   |
   |                     |           |         |                             |
   |                     |           |         | TCP, UDP, and HTTP are      |
   |                     |           |         | supported.                  |
   |                     |           |         |                             |
   |                     |           |         | When a backend server group |
   |                     |           |         | is associated with a        |
   |                     |           |         | listener, the relationships |
   |                     |           |         | between the protocol used   |
   |                     |           |         | by the listener and the     |
   |                     |           |         | protocol of the backend     |
   |                     |           |         | server group are as         |
   |                     |           |         | follows:                    |
   |                     |           |         |                             |
   |                     |           |         | -  When the protocol used   |
   |                     |           |         |    by the listener is       |
   |                     |           |         |    **UDP**, the protocol of |
   |                     |           |         |    the backend server group |
   |                     |           |         |    must be **UDP**.         |
   |                     |           |         | -  When the protocol used   |
   |                     |           |         |    by the listener is       |
   |                     |           |         |    **TCP**, the protocol of |
   |                     |           |         |    the backend server group |
   |                     |           |         |    must be **TCP**.         |
   |                     |           |         | -  When the protocol used   |
   |                     |           |         |    by the listener is       |
   |                     |           |         |    **HTTP** or              |
   |                     |           |         |    **TERMINATED_HTTPS**,    |
   |                     |           |         |    the protocol of the      |
   |                     |           |         |    backend server group     |
   |                     |           |         |    must be **HTTP**.        |
   +---------------------+-----------+---------+-----------------------------+
   | lb_algorithm        | Yes       | String  | Specifies the load          |
   |                     |           |         | balancing algorithm of the  |
   |                     |           |         | backend server group.       |
   |                     |           |         |                             |
   |                     |           |         | The value can be one of the |
   |                     |           |         | following:                  |
   |                     |           |         |                             |
   |                     |           |         | -  **ROUND_ROBIN**:         |
   |                     |           |         |    indicates the weighted   |
   |                     |           |         |    round robin algorithm.   |
   |                     |           |         | -  **LEAST_CONNECTIONS**:   |
   |                     |           |         |    indicates the weighted   |
   |                     |           |         |    least connections        |
   |                     |           |         |    algorithm.               |
   |                     |           |         | -  **SOURCE_IP**: indicates |
   |                     |           |         |    the source IP hash       |
   |                     |           |         |    algorithm.               |
   |                     |           |         |                             |
   |                     |           |         | When the value is           |
   |                     |           |         | **SOURCE_IP**, the weights  |
   |                     |           |         | of backend servers in the   |
   |                     |           |         | server group are invalid.   |
   +---------------------+-----------+---------+-----------------------------+
   | admin_state_up      | No        | Boolean | Specifies the               |
   |                     |           |         | administrative status of    |
   |                     |           |         | the backend server group.   |
   |                     |           |         |                             |
   |                     |           |         | This parameter is reserved, |
   |                     |           |         | and the default value is    |
   |                     |           |         | **true**.                   |
   +---------------------+-----------+---------+-----------------------------+
   | listener_id         | No        | String  | Specifies the ID of the     |
   |                     |           |         | listener associated with    |
   |                     |           |         | the backend server group.   |
   |                     |           |         |                             |
   |                     |           |         | Specify either              |
   |                     |           |         | **listener_id** or          |
   |                     |           |         | **loadbalancer_id**, or     |
   |                     |           |         | both of them.               |
   +---------------------+-----------+---------+-----------------------------+
   | loadbalancer_id     | No        | String  | Specifies the ID of the     |
   |                     |           |         | load balancer associated    |
   |                     |           |         | with the backend server     |
   |                     |           |         | group.                      |
   |                     |           |         |                             |
   |                     |           |         | Specify either              |
   |                     |           |         | **listener_id** or          |
   |                     |           |         | **loadbalancer_id**, or     |
   |                     |           |         | both of them.               |
   +---------------------+-----------+---------+-----------------------------+
   | session_persistence | No        | Object  | Specifies the sticky        |
   |                     |           |         | session timeout duration in |
   |                     |           |         | minutes. For details, see   |
   |                     |           |         | :ref:`spc_t3`.              |
   |                     |           |         |                             |
   |                     |           |         | If the value is **null**,   |
   |                     |           |         | the sticky session feature  |
   |                     |           |         | is disabled.                |
   +---------------------+-----------+---------+-----------------------------+

.. _spc_t3:
.. table:: **Table 3** **session_persistence** parameter description

   +---------------------+-----------+---------+-----------------------------+
   | Parameter           | Mandatory | Type    | Description                 |
   +=====================+===========+=========+=============================+
   | type                | Yes       | String  | Specifies the sticky        |
   |                     |           |         | session type.               |
   |                     |           |         |                             |
   |                     |           |         | The value can be one of the |
   |                     |           |         | following:                  |
   |                     |           |         |                             |
   |                     |           |         | -  **SOURCE_IP**: Requests  |
   |                     |           |         |    are distributed based on |
   |                     |           |         |    the client's IP address. |
   |                     |           |         |    Requests from the same   |
   |                     |           |         |    IP address are sent to   |
   |                     |           |         |    the same backend server. |
   |                     |           |         | -  **HTTP_COOKIE**: When    |
   |                     |           |         |    the client sends a       |
   |                     |           |         |    request for the first    |
   |                     |           |         |    time, the load balancer  |
   |                     |           |         |    automatically generates  |
   |                     |           |         |    a cookie and inserts the |
   |                     |           |         |    cookie into the response |
   |                     |           |         |    message. Subsequent      |
   |                     |           |         |    requests are sent to the |
   |                     |           |         |    backend server that      |
   |                     |           |         |    processes the first      |
   |                     |           |         |    request.                 |
   |                     |           |         | -  **APP_COOKIE**: When the |
   |                     |           |         |    client sends a request   |
   |                     |           |         |    for the first time, the  |
   |                     |           |         |    backend server that      |
   |                     |           |         |    receives the request     |
   |                     |           |         |    generates a cookie and   |
   |                     |           |         |    inserts the cookie into  |
   |                     |           |         |    the response message.    |
   |                     |           |         |    Subsequent requests are  |
   |                     |           |         |    sent to this backend     |
   |                     |           |         |    server.                  |
   |                     |           |         |                             |
   |                     |           |         | When the protocol of the    |
   |                     |           |         | backend server group is     |
   |                     |           |         | TCP, only **SOURCE_IP**     |
   |                     |           |         | takes effect. When the      |
   |                     |           |         | protocol of the backend     |
   |                     |           |         | server group is HTTP, only  |
   |                     |           |         | **HTTP_COOKIE** or          |
   |                     |           |         | **APP_COOKIE** takes        |
   |                     |           |         | effect.                     |
   +---------------------+-----------+---------+-----------------------------+
   | cookie_name         | No        | String  | Specifies the cookie name.  |
   |                     |           |         |                             |
   |                     |           |         | This parameter is mandatory |
   |                     |           |         | when the sticky session     |
   |                     |           |         | type is **APP_COOKIE**.     |
   +---------------------+-----------+---------+-----------------------------+
   | persistence_timeout | No        | Integer | Specifies the sticky        |
   |                     |           |         | session timeout duration in |
   |                     |           |         | minutes.                    |
   |                     |           |         |                             |
   |                     |           |         | This parameter is invalid   |
   |                     |           |         | when **type** is set to     |
   |                     |           |         | **APP_COOKIE**.             |
   |                     |           |         |                             |
   |                     |           |         | The value range varies      |
   |                     |           |         | depending on the protocol   |
   |                     |           |         | of the backend server       |
   |                     |           |         | group:                      |
   |                     |           |         |                             |
   |                     |           |         | -  When the protocol of the |
   |                     |           |         |    backend server group is  |
   |                     |           |         |    TCP or UDP, the value    |
   |                     |           |         |    ranges from **1** to     |
   |                     |           |         |    **60**.                  |
   |                     |           |         | -  When the protocol of the |
   |                     |           |         |    backend server group is  |
   |                     |           |         |    HTTP or HTTPS, the value |
   |                     |           |         |    ranges from **1** to     |
   |                     |           |         |    **1440**.                |
   +---------------------+-----------+---------+-----------------------------+

Response
^^^^^^^^

.. table:: **Table 4** Response parameters

   +-----------+--------+--------------------------------------------------------------------+
   | Parameter | Type   | Description                                                        |
   +===========+========+====================================================================+
   | pool      | Object | Specifies the backend server group. For details, see :ref:`spc_t5` |
   +-----------+--------+--------------------------------------------------------------------+

.. _spc_t5:
.. table:: **Table 5** **pools** parameter description

   +---------------------+---------+------------------------------------------+
   | Parameter           | Type    | Description                              |
   +=====================+=========+==========================================+
   | id                  | String  | Specifies the ID of the backend          |
   |                     |         | server group.                            |
   +---------------------+---------+------------------------------------------+
   | tenant_id           | String  | Specifies the ID of the project where    |
   |                     |         | the backend server group is used.        |
   |                     |         |                                          |
   |                     |         | The value contains a maximum of 255      |
   |                     |         | characters.                              |
   +---------------------+---------+------------------------------------------+
   | name                | String  | Specifies the name of the backend        |
   |                     |         | server group.                            |
   |                     |         |                                          |
   |                     |         | The value contains a maximum of 255      |
   |                     |         | characters.                              |
   +---------------------+---------+------------------------------------------+
   | description         | String  | Provides supplementary information       |
   |                     |         | about the backend server group.          |
   |                     |         |                                          |
   |                     |         | The value contains a maximum of 255      |
   |                     |         | characters.                              |
   +---------------------+---------+------------------------------------------+
   | protocol            | String  | Specifies the protocol that the          |
   |                     |         | backend server group uses to receive     |
   |                     |         | requests.                                |
   |                     |         |                                          |
   |                     |         | TCP, UDP, and HTTP are supported.        |
   |                     |         |                                          |
   |                     |         | When a backend server group is           |
   |                     |         | associated with a listener, the          |
   |                     |         | relationships between the protocol       |
   |                     |         | used by the listener and the protocol    |
   |                     |         | of the backend server group are as       |
   |                     |         | follows:                                 |
   |                     |         |                                          |
   |                     |         | -  When the protocol used by the         |
   |                     |         |    listener is **UDP**, the protocol     |
   |                     |         |    of the backend server group must      |
   |                     |         |    be **UDP**.                           |
   |                     |         | -  When the protocol used by the         |
   |                     |         |    listener is **TCP**, the protocol     |
   |                     |         |    of the backend server group must      |
   |                     |         |    be **TCP**.                           |
   |                     |         | -  When the protocol used by the         |
   |                     |         |    listener is **HTTP** or               |
   |                     |         |    **TERMINATED_HTTPS**, the protocol    |
   |                     |         |    of the backend server group must      |
   |                     |         |    be **HTTP**.                          |
   +---------------------+---------+------------------------------------------+
   | lb_algorithm        | String  | Specifies the load balancing             |
   |                     |         | algorithm of the backend server          |
   |                     |         | group.                                   |
   |                     |         |                                          |
   |                     |         | The value can be one of the              |
   |                     |         | following:                               |
   |                     |         |                                          |
   |                     |         | -  **ROUND_ROBIN**: indicates the        |
   |                     |         |    weighted round robin algorithm.       |
   |                     |         | -  **LEAST_CONNECTIONS**: indicates      |
   |                     |         |    the weighted least connections        |
   |                     |         |    algorithm.                            |
   |                     |         | -  **SOURCE_IP**: indicates the          |
   |                     |         |    source IP hash algorithm. When the    |
   |                     |         |    value is **SOURCE_IP**, the           |
   |                     |         |    weights of backend servers in the     |
   |                     |         |    server group are invalid.             |
   +---------------------+---------+------------------------------------------+
   | members             | Array   | Lists the IDs of backend servers in      |
   |                     |         | the backend server group.                |
   +---------------------+---------+------------------------------------------+
   | healthmonitor_id    | String  | Specifies the ID of the health check     |
   |                     |         | configured for the backend server        |
   |                     |         | group.                                   |
   +---------------------+---------+------------------------------------------+
   | admin_state_up      | Boolean | Specifies the administrative status      |
   |                     |         | of the backend server group.             |
   |                     |         |                                          |
   |                     |         | This parameter is reserved. The value    |
   |                     |         | can be **true** or **false**.            |
   |                     |         |                                          |
   |                     |         | -  **true**: Enabled                     |
   |                     |         | -  **false**: Disabled                   |
   +---------------------+---------+------------------------------------------+
   | listeners           | Array   | Lists the IDs of listeners associated    |
   |                     |         | with the backend server group.           |
   +---------------------+---------+------------------------------------------+
   | loadbalancers       | Array   | Lists the IDs of load balancers          |
   |                     |         | associated with the backend server       |
   |                     |         | group.                                   |
   +---------------------+---------+------------------------------------------+
   | session_persistence | Object  | Specifies whether to enable sticky       |
   |                     |         | sessions. For details, see :ref:`spc_t9` |
   |                     |         |                                          |
   |                     |         | Once sticky session are enabled,         |
   |                     |         | requests from the same client are        |
   |                     |         | sent to the same backend server          |
   |                     |         | during the session.                      |
   |                     |         |                                          |
   |                     |         | When sticky sessions are disabled,       |
   |                     |         | the value is **null**.                   |
   +---------------------+---------+------------------------------------------+

.. _spc_t6:
.. table:: **Table 6** **members** parameter description

   ========= ====== ==================================================
   Parameter Type   Description
   ========= ====== ==================================================
   id        String Specifies the ID of the associated backend server.
   ========= ====== ==================================================

.. table:: **Table 7** **listeners** parameter description

   ========= ====== ========================================================
   Parameter Type   Description
   ========= ====== ========================================================
   id        String Specifies the ID of the associated backend server group.
   ========= ====== ========================================================

.. table:: **Table 8** **loadbalancers** parameter description

   ========= ====== =================================================
   Parameter Type   Description
   ========= ====== =================================================
   id        String Specifies the ID of the associated load balancer.
   ========= ====== =================================================

.. _spc_t9:
.. table:: **Table 9** **session_persistence** parameter description

   +---------------------+---------+---------------------------------------+
   | Parameter           | Type    | Description                           |
   +=====================+=========+=======================================+
   | type                | String  | Specifies the sticky session type.    |
   |                     |         |                                       |
   |                     |         | The value can be one of the           |
   |                     |         | following:                            |
   |                     |         |                                       |
   |                     |         | -  **SOURCE_IP**: Requests are        |
   |                     |         |    distributed based on the client's  |
   |                     |         |    IP address. Requests from the same |
   |                     |         |    IP address are sent to the same    |
   |                     |         |    backend server.                    |
   |                     |         | -  **HTTP_COOKIE**: When the client   |
   |                     |         |    sends a request for the first      |
   |                     |         |    time, the load balancer            |
   |                     |         |    automatically generates a cookie   |
   |                     |         |    and inserts the cookie into the    |
   |                     |         |    response message. Subsequent       |
   |                     |         |    requests are sent to the backend   |
   |                     |         |    server that processes the first    |
   |                     |         |    request.                           |
   |                     |         | -  **APP_COOKIE**: When the client    |
   |                     |         |    sends a request for the first      |
   |                     |         |    time, the backend server that      |
   |                     |         |    receives the request generates a   |
   |                     |         |    cookie and inserts the cookie into |
   |                     |         |    the response message. Subsequent   |
   |                     |         |    requests are sent to this backend  |
   |                     |         |    server.                            |
   |                     |         |                                       |
   |                     |         | When the protocol of the backend      |
   |                     |         | server group is TCP, only             |
   |                     |         | **SOURCE_IP** takes effect. When the  |
   |                     |         | protocol of the backend server group  |
   |                     |         | is HTTP, only **HTTP_COOKIE** or      |
   |                     |         | **APP_COOKIE** takes effect.          |
   +---------------------+---------+---------------------------------------+
   | cookie_name         | String  | Specifies the cookie name.            |
   |                     |         |                                       |
   |                     |         | This parameter is mandatory when the  |
   |                     |         | sticky session type is                |
   |                     |         | **APP_COOKIE**.                       |
   +---------------------+---------+---------------------------------------+
   | persistence_timeout | Integer | Specifies the sticky session timeout  |
   |                     |         | duration in minutes.                  |
   |                     |         |                                       |
   |                     |         | This parameter is invalid when        |
   |                     |         | **type** is set to **APP_COOKIE**.    |
   |                     |         |                                       |
   |                     |         | -  Optional value ranges are as       |
   |                     |         |    follows:                           |
   |                     |         |                                       |
   |                     |         |    -  When the protocol of the        |
   |                     |         |       backend server group is TCP or  |
   |                     |         |       UDP, the value ranges from      |
   |                     |         |       **1** to **60**.                |
   |                     |         |    -  When the protocol of the        |
   |                     |         |       backend server group is HTTP or |
   |                     |         |       HTTPS, the value ranges from    |
   |                     |         |       **1** to **1440**.              |
   +---------------------+---------+---------------------------------------+

Example Request
^^^^^^^^^^^^^^^

-  Example request 1: Adding a backend server group with the sticky session
   feature disabled

   .. code::

      POST https://{Endpoint}/v2.0/lbaas/pools

      {
          "pool": {
              "lb_algorithm":"ROUND_ROBIN",
              "loadbalancer_id": "63ad9dfe-4750-479f-9630-ada43ccc8117",
              "protocol":"HTTP"
          }
      }

-  Example request 2: Adding an HTTP backend server group with the value of
   **type** set to **APP_COOKIE**

   .. code::

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

-  Example request 3: Adding an HTTP backend server group with the value of
   **type** set to **HTTP_COOKIE**

   .. code::

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
^^^^^^^^^^^^^^^^

-  Example response 1

   .. code:: json

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

   .. code:: json

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

   .. code:: json

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
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Querying Backend Server Groups
==============================

Request
^^^^^^^

.. table:: **Table 1** Request parameters

   +------------------+-----------+---------+--------------------------------+
   | Parameter        | Mandatory | Type    | Description                    |
   +==================+===========+=========+================================+
   | marker           | No        | String  | Specifies the ID of the        |
   |                  |           |         | backend server group from      |
   |                  |           |         | which pagination query         |
   |                  |           |         | starts, that is, the ID of     |
   |                  |           |         | the last backend server        |
   |                  |           |         | group on the previous page.    |
   |                  |           |         | If this parameter is not       |
   |                  |           |         | specified, the first page      |
   |                  |           |         | will be queried.               |
   |                  |           |         |                                |
   |                  |           |         | This parameter must be used    |
   |                  |           |         | together with **limit**.       |
   +------------------+-----------+---------+--------------------------------+
   | limit            | No        | Integer | Specifies the number of        |
   |                  |           |         | backend server groups on       |
   |                  |           |         | each page.                     |
   +------------------+-----------+---------+--------------------------------+
   | page_reverse     | No        | Boolean | Specifies the page             |
   |                  |           |         | direction. The value can be    |
   |                  |           |         | **true** or **false**, and     |
   |                  |           |         | the default value is           |
   |                  |           |         | **false**. The last page in    |
   |                  |           |         | the list requested with        |
   |                  |           |         | **page_reverse** set to        |
   |                  |           |         | **false** will not contain     |
   |                  |           |         | the "next" link, and the       |
   |                  |           |         | last page in the list          |
   |                  |           |         | requested with                 |
   |                  |           |         | **page_reverse** set to        |
   |                  |           |         | **true** will not contain      |
   |                  |           |         | the "previous" link.           |
   |                  |           |         |                                |
   |                  |           |         | This parameter must be used    |
   |                  |           |         | together with **limit**.       |
   +------------------+-----------+---------+--------------------------------+
   | id               | No        | String  | Specifies the ID of the        |
   |                  |           |         | backend server group.          |
   +------------------+-----------+---------+--------------------------------+
   | tenant_id        | No        | String  | Specifies the ID of the        |
   |                  |           |         | project where the backend      |
   |                  |           |         | server group is used.          |
   |                  |           |         |                                |
   |                  |           |         | The value contains a           |
   |                  |           |         | maximum of 255 characters.     |
   +------------------+-----------+---------+--------------------------------+
   | name             | No        | String  | Specifies the backend          |
   |                  |           |         | server group name.             |
   |                  |           |         |                                |
   |                  |           |         | The value contains a           |
   |                  |           |         | maximum of 255 characters.     |
   +------------------+-----------+---------+--------------------------------+
   | description      | No        | String  | Provides supplementary         |
   |                  |           |         | information about the          |
   |                  |           |         | backend server group.          |
   |                  |           |         |                                |
   |                  |           |         | The value contains a           |
   |                  |           |         | maximum of 255 characters.     |
   +------------------+-----------+---------+--------------------------------+
   | healthmonitor_id | No        | String  | Specifies the ID of the        |
   |                  |           |         | health check configured for    |
   |                  |           |         | the backend server group.      |
   +------------------+-----------+---------+--------------------------------+
   | loadbalancer_id  | No        | String  | Specifies the ID of the        |
   |                  |           |         | load balancer associated       |
   |                  |           |         | with the backend server        |
   |                  |           |         | group.                         |
   +------------------+-----------+---------+--------------------------------+
   | protocol         | No        | String  | Specifies the protocol that    |
   |                  |           |         | the backend server group       |
   |                  |           |         | uses to receive requests.      |
   |                  |           |         |                                |
   |                  |           |         | TCP, UDP, and HTTP are         |
   |                  |           |         | supported.                     |
   +------------------+-----------+---------+--------------------------------+
   | lb_algorithm     | No        | String  | Specifies the load             |
   |                  |           |         | balancing algorithm of the     |
   |                  |           |         | backend server group.          |
   |                  |           |         |                                |
   |                  |           |         | The value options are as       |
   |                  |           |         | follows:                       |
   |                  |           |         |                                |
   |                  |           |         | -  **ROUND_ROBIN**:            |
   |                  |           |         |    indicates the weighted      |
   |                  |           |         |    round robin algorithm.      |
   |                  |           |         | -  **LEAST_CONNECTIONS**:      |
   |                  |           |         |    indicates the weighted      |
   |                  |           |         |    least connections           |
   |                  |           |         |    algorithm.                  |
   |                  |           |         | -  **SOURCE_IP**: indicates    |
   |                  |           |         |    the source IP hash          |
   |                  |           |         |    algorithm.                  |
   |                  |           |         |                                |
   |                  |           |         | When the value is              |
   |                  |           |         | **SOURCE_IP**, the weights     |
   |                  |           |         | of backend servers in the      |
   |                  |           |         | server group are invalid.      |
   |                  |           |         | For details about parameter    |
   |                  |           |         | **weight**, see :ref:`sms_t2`. |
   +------------------+-----------+---------+--------------------------------+
   | member_address   | No        | String  | Lists the IDs of backend       |
   |                  |           |         | servers in the backend         |
   |                  |           |         | server group.                  |
   +------------------+-----------+---------+--------------------------------+
   | member_device_id | No        | String  | Specifies the ID of the ECS    |
   |                  |           |         | corresponding to the           |
   |                  |           |         | backend server in the          |
   |                  |           |         | backend server group.          |
   +------------------+-----------+---------+--------------------------------+

Response
^^^^^^^^

.. table:: **Table 2** Parameter description

   +-------------+-------+---------------------------------------+
   | Parameter   | Type  | Description                           |
   +=============+=======+=======================================+
   | pools       | Array | Lists the backend server groups. For  |
   |             |       | details, see :ref:`spl_t3`.           |
   +-------------+-------+---------------------------------------+
   | pools_links | List  | Provides links to the previous or     |
   |             |       | next page during pagination query,    |
   |             |       | respectively.                         |
   |             |       |                                       |
   |             |       | This parameter exists only in the     |
   |             |       | response body of pagination query.    |
   |             |       | For details, see :ref:`spl_t8`.       |
   +-------------+-------+---------------------------------------+

.. _spl_t3:
.. table:: **Table 3** **pools** parameter description

   +---------------------+---------+---------------------------------------+
   | Parameter           | Type    | Description                           |
   +=====================+=========+=======================================+
   | id                  | String  | Specifies the ID of the backend       |
   |                     |         | server group.                         |
   +---------------------+---------+---------------------------------------+
   | tenant_id           | String  | Specifies the ID of the project where |
   |                     |         | the backend server group is used.     |
   |                     |         |                                       |
   |                     |         | The value contains a maximum of 255   |
   |                     |         | characters.                           |
   +---------------------+---------+---------------------------------------+
   | name                | String  | Specifies the backend server group    |
   |                     |         | name.                                 |
   |                     |         |                                       |
   |                     |         | The value contains a maximum of 255   |
   |                     |         | characters.                           |
   +---------------------+---------+---------------------------------------+
   | description         | String  | Provides supplementary information    |
   |                     |         | about the backend server group.       |
   |                     |         |                                       |
   |                     |         | The value contains a maximum of 255   |
   |                     |         | characters.                           |
   +---------------------+---------+---------------------------------------+
   | protocol            | String  | Specifies the protocol that the       |
   |                     |         | backend server group uses to receive  |
   |                     |         | requests.                             |
   |                     |         |                                       |
   |                     |         | TCP, UDP, and HTTP are supported.     |
   +---------------------+---------+---------------------------------------+
   | lb_algorithm        | String  | Specifies the load balancing          |
   |                     |         | algorithm of the backend server       |
   |                     |         | group.                                |
   |                     |         |                                       |
   |                     |         | The value options are as follows:     |
   |                     |         |                                       |
   |                     |         | -  **ROUND_ROBIN**: indicates the     |
   |                     |         |    weighted round robin algorithm.    |
   |                     |         | -  **LEAST_CONNECTIONS**: indicates   |
   |                     |         |    the weighted least connections     |
   |                     |         |    algorithm.                         |
   |                     |         | -  **SOURCE_IP**: indicates the       |
   |                     |         |    source IP hash algorithm.          |
   |                     |         |                                       |
   |                     |         | When the value is **SOURCE_IP**, the  |
   |                     |         | weights of backend servers in the     |
   |                     |         | server group are invalid.             |
   +---------------------+---------+---------------------------------------+
   | members             | Array   | Lists the IDs of backend servers in   |
   |                     |         | the backend server group.             |
   +---------------------+---------+---------------------------------------+
   | healthmonitor_id    | String  | Specifies the ID of the health check  |
   |                     |         | configured for the backend server     |
   |                     |         | group.                                |
   +---------------------+---------+---------------------------------------+
   | admin_state_up      | Boolean | Specifies the administrative status   |
   |                     |         | of the backend server group.          |
   |                     |         |                                       |
   |                     |         | This parameter is reserved. The       |
   |                     |         | default value is **true**.            |
   +---------------------+---------+---------------------------------------+
   | listeners           | Array   | Lists the IDs of listeners associated |
   |                     |         | with the backend server group.        |
   +---------------------+---------+---------------------------------------+
   | loadbalancers       | String  | Lists the IDs of load balancers       |
   |                     |         | associated with the backend server    |
   |                     |         | group.                                |
   +---------------------+---------+---------------------------------------+
   | session_persistence | Object  | Specifies whether to enable the       |
   |                     |         | sticky session feature. For details,  |
   |                     |         | see :ref:`spl_t7`.                    |
   |                     |         |                                       |
   |                     |         | Once the sticky session feature is    |
   |                     |         | enabled, requests from the same       |
   |                     |         | client are sent to the same backend   |
   |                     |         | server within the specified period.   |
   |                     |         |                                       |
   |                     |         | When this feature is disabled, the    |
   |                     |         | parameter value is **null**.          |
   +---------------------+---------+---------------------------------------+

.. table:: **Table 4** **members** parameter description

   ========= ====== ==================================================
   Parameter Type   Description
   ========= ====== ==================================================
   id        String Specifies the ID of the associated backend server.
   ========= ====== ==================================================

.. table:: **Table 5** **listeners** parameter description

   ========= ====== ========================================================
   Parameter Type   Description
   ========= ====== ========================================================
   id        String Specifies the ID of the associated backend server group.
   ========= ====== ========================================================

.. table:: **Table 6** **loadbalancers** parameter description

   ========= ====== =================================================
   Parameter Type   Description
   ========= ====== =================================================
   id        String Specifies the ID of the associated load balancer.
   ========= ====== =================================================

.. _spl_t7:
.. table:: **Table 7** **session_persistence** parameter description

   +---------------------+---------+---------------------------------------+
   | Parameter           | Type    | Description                           |
   +=====================+=========+=======================================+
   | type                | String  | Specifies the sticky session type.    |
   |                     |         |                                       |
   |                     |         | The value can be one of the           |
   |                     |         | following:                            |
   |                     |         |                                       |
   |                     |         | -  **SOURCE_IP**: Requests are        |
   |                     |         |    distributed based on the client's  |
   |                     |         |    IP address. Requests from the same |
   |                     |         |    IP address are sent to the same    |
   |                     |         |    backend server.                    |
   |                     |         | -  **HTTP_COOKIE**: When the client   |
   |                     |         |    sends a request for the first      |
   |                     |         |    time, the load balancer            |
   |                     |         |    automatically generates a cookie   |
   |                     |         |    and inserts the cookie into the    |
   |                     |         |    response message. Subsequent       |
   |                     |         |    requests are sent to the backend   |
   |                     |         |    server that processes the first    |
   |                     |         |    request.                           |
   |                     |         | -  **APP_COOKIE**: When the client    |
   |                     |         |    sends a request for the first      |
   |                     |         |    time, the backend server that      |
   |                     |         |    receives the request generates a   |
   |                     |         |    cookie and inserts the cookie into |
   |                     |         |    the response message. Subsequent   |
   |                     |         |    requests are sent to this backend  |
   |                     |         |    server.                            |
   |                     |         |                                       |
   |                     |         | When the protocol of the backend      |
   |                     |         | server group is TCP, only             |
   |                     |         | **SOURCE_IP** takes effect. When the  |
   |                     |         | protocol of the backend server group  |
   |                     |         | is HTTP, only **HTTP_COOKIE** or      |
   |                     |         | **APP_COOKIE** takes effect.          |
   +---------------------+---------+---------------------------------------+
   | cookie_name         | String  | Specifies the cookie name.            |
   |                     |         |                                       |
   |                     |         | This parameter is mandatory when the  |
   |                     |         | sticky session type is                |
   |                     |         | **APP_COOKIE**.                       |
   +---------------------+---------+---------------------------------------+
   | persistence_timeout | Integer | Specifies the sticky session timeout  |
   |                     |         | duration in minutes.                  |
   |                     |         |                                       |
   |                     |         | This parameter is invalid when        |
   |                     |         | **type** is set to **APP_COOKIE**.    |
   |                     |         |                                       |
   |                     |         | -  Optional value ranges are as       |
   |                     |         |    follows:                           |
   |                     |         |                                       |
   |                     |         |    -  When the protocol of the        |
   |                     |         |       backend server group is TCP or  |
   |                     |         |       UDP, the value ranges from      |
   |                     |         |       **1** to **60**.                |
   |                     |         |    -  When the protocol of the        |
   |                     |         |       backend server group is HTTP or |
   |                     |         |       HTTPS, the value ranges from    |
   |                     |         |       **1** to **1440**.              |
   +---------------------+---------+---------------------------------------+

.. _spl_t8:
.. table:: **Table 8** **pools_links** parameter description

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

-  Example request 1: Adding a backend server group with the sticky session feature disabled

   .. code::

      POST https://{Endpoint}/v2.0/lbaas/pools

      {
          "pool": {
              "lb_algorithm":"ROUND_ROBIN",
              "loadbalancer_id": "63ad9dfe-4750-479f-9630-ada43ccc8117",
              "protocol":"HTTP"
          }
      }

-  Example request 2: Querying backend server groups whose load balancing algorithm is **SOURCE_IP**

   .. code::

      GET https://{Endpoint}/v2.0/lbaas/pools

-  Example response 2

   .. code::

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
^^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Querying Details of a Backend Server Group
==========================================

Function
^^^^^^^^

This API is used to query details about a backend server group using its ID.

URI
^^^

GET /v2.0/lbaas/pools/{pool_id}

.. table:: **Table 1** Parameter description

   ========= ========= ====== =============================================
   Parameter Mandatory Type   Description
   ========= ========= ====== =============================================
   pool_id   Yes       String Specifies the ID of the backend server group.
   ========= ========= ====== =============================================

Request
^^^^^^^

None

Response
^^^^^^^^

.. _sps_t2:
.. table:: **Table 2** Response parameters

   +-----------+--------+---------------------------------------------------------------------+
   | Parameter | Type   | Description                                                         |
   +===========+========+=====================================================================+
   | pool      | Object | Specifies the backend server group. For details, see :ref:`sps_t3`. |
   +-----------+--------+---------------------------------------------------------------------+

.. _sps_t3:
.. table:: **Table 3** **pools** parameter description

   +---------------------+---------+-------------------------------------------+
   | Parameter           | Type    | Description                               |
   +=====================+=========+===========================================+
   | id                  | String  | Specifies the ID of the backend           |
   |                     |         | server group.                             |
   +---------------------+---------+-------------------------------------------+
   | tenant_id           | String  | Specifies the ID of the project where     |
   |                     |         | the backend server group is used.         |
   |                     |         |                                           |
   |                     |         | The value contains a maximum of 255       |
   |                     |         | characters.                               |
   +---------------------+---------+-------------------------------------------+
   | name                | String  | Specifies the name of the backend         |
   |                     |         | server group.                             |
   |                     |         |                                           |
   |                     |         | The value contains a maximum of 255       |
   |                     |         | characters.                               |
   +---------------------+---------+-------------------------------------------+
   | description         | String  | Provides supplementary information        |
   |                     |         | about the backend server group.           |
   |                     |         |                                           |
   |                     |         | The value contains a maximum of 255       |
   |                     |         | characters.                               |
   +---------------------+---------+-------------------------------------------+
   | protocol            | String  | Specifies the protocol that the           |
   |                     |         | backend server group uses to receive      |
   |                     |         | requests.                                 |
   |                     |         |                                           |
   |                     |         | TCP, UDP, and HTTP are supported.         |
   |                     |         |                                           |
   |                     |         | When a backend server group is            |
   |                     |         | associated with a listener, the           |
   |                     |         | relationships between the protocol        |
   |                     |         | used by the listener and the protocol     |
   |                     |         | of the backend server group are as        |
   |                     |         | follows:                                  |
   |                     |         |                                           |
   |                     |         | -  When the protocol used by the          |
   |                     |         |    listener is **UDP**, the protocol      |
   |                     |         |    of the backend server group must       |
   |                     |         |    be **UDP**.                            |
   |                     |         | -  When the protocol used by the          |
   |                     |         |    listener is **TCP**, the protocol      |
   |                     |         |    of the backend server group must       |
   |                     |         |    be **TCP**.                            |
   |                     |         | -  When the protocol used by the          |
   |                     |         |    listener is **HTTP** or                |
   |                     |         |    **TERMINATED_HTTPS**, the protocol     |
   |                     |         |    of the backend server group must       |
   |                     |         |    be **HTTP**.                           |
   +---------------------+---------+-------------------------------------------+
   | lb_algorithm        | String  | Specifies the load balancing              |
   |                     |         | algorithm of the backend server           |
   |                     |         | group.                                    |
   |                     |         |                                           |
   |                     |         | The value can be one of the               |
   |                     |         | following:                                |
   |                     |         |                                           |
   |                     |         | -  **ROUND_ROBIN**: indicates the         |
   |                     |         |    weighted round robin algorithm.        |
   |                     |         | -  **LEAST_CONNECTIONS**: indicates       |
   |                     |         |    the weighted least connections         |
   |                     |         |    algorithm.                             |
   |                     |         | -  **SOURCE_IP**: indicates the           |
   |                     |         |    source IP hash algorithm. When the     |
   |                     |         |    value is **SOURCE_IP**, the            |
   |                     |         |    weights of backend servers in the      |
   |                     |         |    server group are invalid.              |
   +---------------------+---------+-------------------------------------------+
   | members             | Array   | Lists the IDs of backend servers in       |
   |                     |         | the backend server group.                 |
   +---------------------+---------+-------------------------------------------+
   | healthmonitor_id    | String  | Specifies the ID of the health check      |
   |                     |         | configured for the backend server         |
   |                     |         | group.                                    |
   +---------------------+---------+-------------------------------------------+
   | admin_state_up      | Boolean | Specifies the administrative status       |
   |                     |         | of the backend server group.              |
   |                     |         |                                           |
   |                     |         | This parameter is reserved. The value     |
   |                     |         | can be **true** or **false**.             |
   |                     |         |                                           |
   |                     |         | -  **true**: Enabled                      |
   |                     |         | -  **false**: Disabled                    |
   +---------------------+---------+-------------------------------------------+
   | listeners           | Array   | Lists the IDs of listeners associated     |
   |                     |         | with the backend server group.            |
   +---------------------+---------+-------------------------------------------+
   | loadbalancers       | Array   | Lists the IDs of load balancers           |
   |                     |         | associated with the backend server        |
   |                     |         | group.                                    |
   +---------------------+---------+-------------------------------------------+
   | session_persistence | Object  | Specifies whether to enable sticky        |
   |                     |         | sessions. For details, see :ref:`spc_t9`. |
   |                     |         |                                           |
   |                     |         | Once sticky session are enabled,          |
   |                     |         | requests from the same client are         |
   |                     |         | sent to the same backend server           |
   |                     |         | during the session.                       |
   |                     |         |                                           |
   |                     |         | When sticky sessions are disabled,        |
   |                     |         | the value is **null**.                    |
   +---------------------+---------+-------------------------------------------+

.. table:: **Table 4** **members** parameter description

   ========= ====== ==================================================
   Parameter Type   Description
   ========= ====== ==================================================
   id        String Specifies the ID of the associated backend server.
   ========= ====== ==================================================

.. table:: **Table 5** **listeners** parameter description

   ========= ====== ========================================================
   Parameter Type   Description
   ========= ====== ========================================================
   id        String Specifies the ID of the associated backend server group.
   ========= ====== ========================================================

.. table:: **Table 6** **loadbalancers** parameter description

   ========= ====== =================================================
   Parameter Type   Description
   ========= ====== =================================================
   id        String Specifies the ID of the associated load balancer.
   ========= ====== =================================================

.. table:: **Table 7** **session_persistence** parameter description

   +---------------------+---------+---------------------------------------+
   | Parameter           | Type    | Description                           |
   +=====================+=========+=======================================+
   | type                | String  | Specifies the sticky session type.    |
   |                     |         |                                       |
   |                     |         | The value can be one of the           |
   |                     |         | following:                            |
   |                     |         |                                       |
   |                     |         | -  **SOURCE_IP**: Requests are        |
   |                     |         |    distributed based on the client's  |
   |                     |         |    IP address. Requests from the same |
   |                     |         |    IP address are sent to the same    |
   |                     |         |    backend server.                    |
   |                     |         | -  **HTTP_COOKIE**: When the client   |
   |                     |         |    sends a request for the first      |
   |                     |         |    time, the load balancer            |
   |                     |         |    automatically generates a cookie   |
   |                     |         |    and inserts the cookie into the    |
   |                     |         |    response message. Subsequent       |
   |                     |         |    requests are sent to the backend   |
   |                     |         |    server that processes the first    |
   |                     |         |    request.                           |
   |                     |         | -  **APP_COOKIE**: When the client    |
   |                     |         |    sends a request for the first      |
   |                     |         |    time, the backend server that      |
   |                     |         |    receives the request generates a   |
   |                     |         |    cookie and inserts the cookie into |
   |                     |         |    the response message. Subsequent   |
   |                     |         |    requests are sent to this backend  |
   |                     |         |    server.                            |
   |                     |         |                                       |
   |                     |         | When the protocol of the backend      |
   |                     |         | server group is TCP, only             |
   |                     |         | **SOURCE_IP** takes effect. When the  |
   |                     |         | protocol of the backend server group  |
   |                     |         | is HTTP, only **HTTP_COOKIE** or      |
   |                     |         | **APP_COOKIE** takes effect.          |
   +---------------------+---------+---------------------------------------+
   | cookie_name         | String  | Specifies the cookie name.            |
   |                     |         |                                       |
   |                     |         | This parameter is mandatory when the  |
   |                     |         | sticky session type is                |
   |                     |         | **APP_COOKIE**.                       |
   +---------------------+---------+---------------------------------------+
   | persistence_timeout | Integer | Specifies the sticky session timeout  |
   |                     |         | duration in minutes.                  |
   |                     |         |                                       |
   |                     |         | This parameter is invalid when        |
   |                     |         | **type** is set to **APP_COOKIE**.    |
   |                     |         |                                       |
   |                     |         | -  Optional value ranges are as       |
   |                     |         |    follows:                           |
   |                     |         |                                       |
   |                     |         |    -  When the protocol of the        |
   |                     |         |       backend server group is TCP or  |
   |                     |         |       UDP, the value ranges from      |
   |                     |         |       **1** to **60**.                |
   |                     |         |    -  When the protocol of the        |
   |                     |         |       backend server group is HTTP or |
   |                     |         |       HTTPS, the value ranges from    |
   |                     |         |       **1** to **1440**.              |
   +---------------------+---------+---------------------------------------+

Example Request
^^^^^^^^^^^^^^^

-  Example request: Querying details of a backend server group

   .. code::

      GET https://{Endpoint}/v2.0/lbaas/pools/5a9a3e9e-d1aa-448e-af37-a70171f2a332

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   .. code:: json

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
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Updating a Backend Server Group
===============================

Function
^^^^^^^^

This API is used to update a backend server group.

Constraints
^^^^^^^^^^^

If the provisioning status of the load balancer associated with a backend
server group is not **ACTIVE**, the backend server group cannot be updated.

URI
^^^

PUT /v2.0/lbaas/pools/{pool_id}

.. table:: **Table 1** Parameter description

   ========= ========= ====== =============================================
   Parameter Mandatory Type   Description
   ========= ========= ====== =============================================
   pool_id   Yes       String Specifies the ID of the backend server group.
   ========= ========= ====== =============================================

Request
^^^^^^^

.. table:: **Table 2** Parameter description

   +-----------+-----------+--------+---------------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                         |
   +===========+===========+========+=====================================================================+
   | pool      | Yes       | Object | Specifies the backend server group. For details, see :ref:`spu_t3`. |
   +-----------+-----------+--------+---------------------------------------------------------------------+

.. _spu_t3:
.. table:: **Table 3** **pool** parameter description

   +---------------------+-----------+---------+----------------------------------+
   | Parameter           | Mandatory | Type    | Description                      |
   +=====================+===========+=========+==================================+
   | name                | No        | String  | Specifies the name of the        |
   |                     |           |         | backend server group.            |
   |                     |           |         |                                  |
   |                     |           |         | The value contains a             |
   |                     |           |         | maximum of 255 characters.       |
   +---------------------+-----------+---------+----------------------------------+
   | description         | No        | String  | Provides supplementary           |
   |                     |           |         | information about the            |
   |                     |           |         | backend server group.            |
   |                     |           |         |                                  |
   |                     |           |         | The value contains a             |
   |                     |           |         | maximum of 255 characters.       |
   +---------------------+-----------+---------+----------------------------------+
   | lb_algorithm        | No        | String  | Specifies the load               |
   |                     |           |         | balancing algorithm of the       |
   |                     |           |         | backend server group.            |
   |                     |           |         |                                  |
   |                     |           |         | Value options:                   |
   |                     |           |         |                                  |
   |                     |           |         | -  **ROUND_ROBIN**:              |
   |                     |           |         |    indicates the weighted        |
   |                     |           |         |    round robin algorithm.        |
   |                     |           |         | -  **LEAST_CONNECTIONS**:        |
   |                     |           |         |    indicates the weighted        |
   |                     |           |         |    least connections             |
   |                     |           |         |    algorithm.                    |
   |                     |           |         | -  **SOURCE_IP**: indicates      |
   |                     |           |         |    the source IP hash            |
   |                     |           |         |    algorithm.                    |
   |                     |           |         |                                  |
   |                     |           |         | When the value is                |
   |                     |           |         | **SOURCE_IP**, the weights       |
   |                     |           |         | of backend servers in the        |
   |                     |           |         | server group are invalid.        |
   +---------------------+-----------+---------+----------------------------------+
   | admin_state_up      | No        | Boolean | Specifies the                    |
   |                     |           |         | administrative status of         |
   |                     |           |         | the backend server group.        |
   |                     |           |         |                                  |
   |                     |           |         | This parameter is reserved,      |
   |                     |           |         | and the default value is         |
   |                     |           |         | **true**.                        |
   +---------------------+-----------+---------+----------------------------------+
   | session_persistence | No        | Object  | Specifies whether to enable      |
   |                     |           |         | the sticky session feature.      |
   |                     |           |         | For details, see :ref:`spu_t10`. |
   |                     |           |         |                                  |
   |                     |           |         | Once sticky session are          |
   |                     |           |         | enabled, requests from the       |
   |                     |           |         | same client are sent to the      |
   |                     |           |         | same backend server during       |
   |                     |           |         | the session.                     |
   |                     |           |         |                                  |
   |                     |           |         | When sticky sessions are         |
   |                     |           |         | disabled, the value is           |
   |                     |           |         | **null**.                        |
   +---------------------+-----------+---------+----------------------------------+

.. _spu_t4:
.. table:: **Table 4** **session_persistence** parameter description

   +---------------------+-----------+---------+-----------------------------+
   | Parameter           | Mandatory | Type    | Description                 |
   +=====================+===========+=========+=============================+
   | type                | No        | String  | Specifies the sticky        |
   |                     |           |         | session type.               |
   |                     |           |         |                             |
   |                     |           |         | Value options:              |
   |                     |           |         |                             |
   |                     |           |         | -  **SOURCE_IP**: Requests  |
   |                     |           |         |    are distributed based on |
   |                     |           |         |    the client's IP address. |
   |                     |           |         |    Requests from the same   |
   |                     |           |         |    IP address are sent to   |
   |                     |           |         |    the same backend server. |
   |                     |           |         | -  **HTTP_COOKIE**: When    |
   |                     |           |         |    the client sends a       |
   |                     |           |         |    request for the first    |
   |                     |           |         |    time, the load balancer  |
   |                     |           |         |    automatically generates  |
   |                     |           |         |    a cookie and inserts the |
   |                     |           |         |    cookie into the response |
   |                     |           |         |    message. Subsequent      |
   |                     |           |         |    requests are sent to the |
   |                     |           |         |    backend server that      |
   |                     |           |         |    processes the first      |
   |                     |           |         |    request.                 |
   |                     |           |         | -  **APP_COOKIE**: When the |
   |                     |           |         |    client sends a request   |
   |                     |           |         |    for the first time, the  |
   |                     |           |         |    backend server that      |
   |                     |           |         |    receives the request     |
   |                     |           |         |    generates a cookie and   |
   |                     |           |         |    inserts the cookie into  |
   |                     |           |         |    the response message.    |
   |                     |           |         |    Subsequent requests are  |
   |                     |           |         |    sent to this backend     |
   |                     |           |         |    server.                  |
   |                     |           |         |                             |
   |                     |           |         | -  When the protocol of the |
   |                     |           |         |    backend server group is  |
   |                     |           |         |    TCP, only **SOURCE_IP**  |
   |                     |           |         |    takes effect. When the   |
   |                     |           |         |    protocol of the backend  |
   |                     |           |         |    server group is HTTP,    |
   |                     |           |         |    only **HTTP_COOKIE** or  |
   |                     |           |         |    **APP_COOKIE** takes     |
   |                     |           |         |    effect.                  |
   +---------------------+-----------+---------+-----------------------------+
   | cookie_name         | No        | String  | Specifies the cookie name.  |
   |                     |           |         |                             |
   |                     |           |         | This parameter is mandatory |
   |                     |           |         | and can be specified when   |
   |                     |           |         | the sticky session type is  |
   |                     |           |         | **APP_COOKIE**.             |
   +---------------------+-----------+---------+-----------------------------+
   | persistence_timeout | No        | Integer | Specifies the sticky        |
   |                     |           |         | session timeout duration in |
   |                     |           |         | minutes.                    |
   |                     |           |         |                             |
   |                     |           |         | This parameter is invalid   |
   |                     |           |         | when **type** is set to     |
   |                     |           |         | **APP_COOKIE**.             |
   |                     |           |         |                             |
   |                     |           |         | Value range options are as  |
   |                     |           |         | follows:                    |
   |                     |           |         |                             |
   |                     |           |         | -  When the protocol of the |
   |                     |           |         |    backend server group is  |
   |                     |           |         |    TCP or UDP, the value    |
   |                     |           |         |    ranges from **1** to     |
   |                     |           |         |    **60**.                  |
   |                     |           |         | -  When the protocol of the |
   |                     |           |         |    backend server group is  |
   |                     |           |         |    HTTP or HTTPS, the value |
   |                     |           |         |    ranges from **1** to     |
   |                     |           |         |    **1440**.                |
   +---------------------+-----------+---------+-----------------------------+

Response
^^^^^^^^

.. table:: **Table 5** Parameter description

   +-----------+--------+---------------------------------------------------------------------+
   | Parameter | Type   | Description                                                         |
   +===========+========+=====================================================================+
   | pool      | Object | Specifies the backend server group. For details, see :ref:`spu_t6`. |
   +-----------+--------+---------------------------------------------------------------------+

.. _spu_t6:
.. table:: **Table 6** **pools** parameter description

   +---------------------+---------+-------------------------------------------+
   | Parameter           | Type    | Description                               |
   +=====================+=========+===========================================+
   | id                  | String  | Specifies the ID of the backend           |
   |                     |         | server group.                             |
   +---------------------+---------+-------------------------------------------+
   | tenant_id           | String  | Specifies the ID of the project where     |
   |                     |         | the backend server group is used.         |
   |                     |         |                                           |
   |                     |         | The value contains a maximum of 255       |
   |                     |         | characters.                               |
   +---------------------+---------+-------------------------------------------+
   | name                | String  | Specifies the name of the backend         |
   |                     |         | server group.                             |
   |                     |         |                                           |
   |                     |         | The value contains a maximum of 255       |
   |                     |         | characters.                               |
   +---------------------+---------+-------------------------------------------+
   | description         | String  | Provides supplementary information        |
   |                     |         | about the backend server group.           |
   |                     |         |                                           |
   |                     |         | The value contains a maximum of 255       |
   |                     |         | characters.                               |
   +---------------------+---------+-------------------------------------------+
   | protocol            | String  | Specifies the protocol that the           |
   |                     |         | backend server group uses to receive      |
   |                     |         | requests.                                 |
   |                     |         |                                           |
   |                     |         | TCP, UDP, and HTTP are supported.         |
   |                     |         |                                           |
   |                     |         | When a backend server group is            |
   |                     |         | associated with a listener, the           |
   |                     |         | relationships between the protocol        |
   |                     |         | used by the listener and the protocol     |
   |                     |         | of the backend server group are as        |
   |                     |         | follows:                                  |
   |                     |         |                                           |
   |                     |         | -  When the protocol used by the          |
   |                     |         |    listener is **UDP**, the protocol      |
   |                     |         |    of the backend server group must       |
   |                     |         |    be **UDP**.                            |
   |                     |         | -  When the protocol used by the          |
   |                     |         |    listener is **TCP**, the protocol      |
   |                     |         |    of the backend server group must       |
   |                     |         |    be **TCP**.                            |
   |                     |         | -  When the protocol used by the          |
   |                     |         |    listener is **HTTP** or                |
   |                     |         |    **TERMINATED_HTTPS**, the protocol     |
   |                     |         |    of the backend server group must       |
   |                     |         |    be **HTTP**.                           |
   +---------------------+---------+-------------------------------------------+
   | lb_algorithm        | String  | Specifies the load balancing              |
   |                     |         | algorithm of the backend server           |
   |                     |         | group.                                    |
   |                     |         |                                           |
   |                     |         | The value can be one of the               |
   |                     |         | following:                                |
   |                     |         |                                           |
   |                     |         | -  **ROUND_ROBIN**: indicates the         |
   |                     |         |    weighted round robin algorithm.        |
   |                     |         | -  **LEAST_CONNECTIONS**: indicates       |
   |                     |         |    the weighted least connections         |
   |                     |         |    algorithm.                             |
   |                     |         | -  **SOURCE_IP**: indicates the           |
   |                     |         |    source IP hash algorithm. When the     |
   |                     |         |    value is **SOURCE_IP**, the            |
   |                     |         |    weights of backend servers in the      |
   |                     |         |    server group are invalid.              |
   +---------------------+---------+-------------------------------------------+
   | members             | Array   | Lists the IDs of backend servers in       |
   |                     |         | the backend server group.                 |
   +---------------------+---------+-------------------------------------------+
   | healthmonitor_id    | String  | Specifies the ID of the health check      |
   |                     |         | configured for the backend server         |
   |                     |         | group.                                    |
   +---------------------+---------+-------------------------------------------+
   | admin_state_up      | Boolean | Specifies the administrative status       |
   |                     |         | of the backend server group.              |
   |                     |         |                                           |
   |                     |         | This parameter is reserved. The value     |
   |                     |         | can be **true** or **false**.             |
   |                     |         |                                           |
   |                     |         | -  **true**: Enabled                      |
   |                     |         | -  **false**: Disabled                    |
   +---------------------+---------+-------------------------------------------+
   | listeners           | Array   | Lists the IDs of listeners associated     |
   |                     |         | with the backend server group.            |
   +---------------------+---------+-------------------------------------------+
   | loadbalancers       | Array   | Lists the IDs of load balancers           |
   |                     |         | associated with the backend server        |
   |                     |         | group.                                    |
   +---------------------+---------+-------------------------------------------+
   | session_persistence | Object  | Specifies whether to enable sticky        |
   |                     |         | sessions. For details, see :ref:`spc_t9`. |
   |                     |         |                                           |
   |                     |         | Once sticky session are enabled,          |
   |                     |         | requests from the same client are         |
   |                     |         | sent to the same backend server           |
   |                     |         | during the session.                       |
   |                     |         |                                           |
   |                     |         | When sticky sessions are disabled,        |
   |                     |         | the value is **null**.                    |
   +---------------------+---------+-------------------------------------------+

.. _spu_t7:
.. table:: **Table 7** **members** parameter description

   ========= ====== ==================================================
   Parameter Type   Description
   ========= ====== ==================================================
   id        String Specifies the ID of the associated backend server.
   ========= ====== ==================================================

.. _spu_t8:
.. table:: **Table 8** **listeners** parameter description

   ========= ====== ========================================================
   Parameter Type   Description
   ========= ====== ========================================================
   id        String Specifies the ID of the associated backend server group.
   ========= ====== ========================================================

.. _spu_t9:
.. table:: **Table 9** **loadbalancers** parameter description

   ========= ====== =================================================
   Parameter Type   Description
   ========= ====== =================================================
   id        String Specifies the ID of the associated load balancer.
   ========= ====== =================================================

.. _spu_t10:
.. table:: **Table 10** **session_persistence** parameter description

   +---------------------+---------+---------------------------------------+
   | Parameter           | Type    | Description                           |
   +=====================+=========+=======================================+
   | type                | String  | Specifies the sticky session type.    |
   |                     |         |                                       |
   |                     |         | The value can be one of the           |
   |                     |         | following:                            |
   |                     |         |                                       |
   |                     |         | -  **SOURCE_IP**: Requests are        |
   |                     |         |    distributed based on the client's  |
   |                     |         |    IP address. Requests from the same |
   |                     |         |    IP address are sent to the same    |
   |                     |         |    backend server.                    |
   |                     |         | -  **HTTP_COOKIE**: When the client   |
   |                     |         |    sends a request for the first      |
   |                     |         |    time, the load balancer            |
   |                     |         |    automatically generates a cookie   |
   |                     |         |    and inserts the cookie into the    |
   |                     |         |    response message. Subsequent       |
   |                     |         |    requests are sent to the backend   |
   |                     |         |    server that processes the first    |
   |                     |         |    request.                           |
   |                     |         | -  **APP_COOKIE**: When the client    |
   |                     |         |    sends a request for the first      |
   |                     |         |    time, the backend server that      |
   |                     |         |    receives the request generates a   |
   |                     |         |    cookie and inserts the cookie into |
   |                     |         |    the response message. Subsequent   |
   |                     |         |    requests are sent to this backend  |
   |                     |         |    server.                            |
   |                     |         |                                       |
   |                     |         | When the protocol of the backend      |
   |                     |         | server group is TCP, only             |
   |                     |         | **SOURCE_IP** takes effect. When the  |
   |                     |         | protocol of the backend server group  |
   |                     |         | is HTTP, only **HTTP_COOKIE** or      |
   |                     |         | **APP_COOKIE** takes effect.          |
   +---------------------+---------+---------------------------------------+
   | cookie_name         | String  | Specifies the cookie name.            |
   |                     |         |                                       |
   |                     |         | This parameter is mandatory when the  |
   |                     |         | sticky session type is                |
   |                     |         | **APP_COOKIE**.                       |
   +---------------------+---------+---------------------------------------+
   | persistence_timeout | Integer | Specifies the sticky session timeout  |
   |                     |         | duration in minutes.                  |
   |                     |         |                                       |
   |                     |         | This parameter is invalid when        |
   |                     |         | **type** is set to **APP_COOKIE**.    |
   |                     |         |                                       |
   |                     |         | -  Optional value ranges are as       |
   |                     |         |    follows:                           |
   |                     |         |                                       |
   |                     |         |    -  When the protocol of the        |
   |                     |         |       backend server group is TCP or  |
   |                     |         |       UDP, the value ranges from      |
   |                     |         |       **1** to **60**.                |
   |                     |         |    -  When the protocol of the        |
   |                     |         |       backend server group is HTTP or |
   |                     |         |       HTTPS, the value ranges from    |
   |                     |         |       **1** to **1440**.              |
   +---------------------+---------+---------------------------------------+

Example Request
^^^^^^^^^^^^^^^

-  Example request 1: Updating a backend server group

   .. code::

      PUT https://{Endpoint}/v2.0/lbaas/pools/12ff63af-4127-4074-a251-bcb2ecc53ebe

      {
          "pool": {
              "name": "pool2",
              "description": "pool two",
              "lb_algorithm": "LEAST_CONNECTIONS"
          }
      }

-  Example request 2: Disabling the sticky session feature of a backend server group

   .. code::

      PUT https://{Endpoint}/v2.0/lbaas/pools/d46eab56-d76b-4cd3-8952-3c3c4cf113aa

      {
          "pool": {
              "session_persistence":null
          }
      }

Example Response
^^^^^^^^^^^^^^^^

-  Example response 1

   .. code:: json

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

   .. code:: json

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
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Deleting a Backend Server Group
===============================

Function
^^^^^^^^

This API is used to delete a backend server group.

Constraints
^^^^^^^^^^^

Before deleting a backend server group, remove all backend servers, delete the
health check, and disassociate forwarding policies from the backend server
group by changing the value of **redirect_pool_id** to **null**. For details,
see :ref:`sl7pu`.

URI
^^^

DELETE /v2.0/lbaas/pools/{pool_id}

.. table:: **Table 1** Parameter description

   ========= ========= ====== =============================================
   Parameter Mandatory Type   Description
   ========= ========= ====== =============================================
   pool_id   Yes       String Specifies the ID of the backend server group.
   ========= ========= ====== =============================================

Request
^^^^^^^

None

Response
^^^^^^^^

None

Example Request
^^^^^^^^^^^^^^^

-  Example request: Deleting a backend server group

   .. code::

      DELETE  /v2.0/lbaas/pools/5a9a3e9e-d1aa-448e-af37-a70171f2a332

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   None

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.
