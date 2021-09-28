===========
Member Pool
===========

Creating a Backend Server Group
===============================

Function
^^^^^^^^

This API is used to create a backend server group.

Constraints
^^^^^^^^^^^

If **session-persistence** is specified, **cookie_name** is available only when
**type** is set to **APP_COOKIE**.

If **listener_id** is specified, the listener must have no backend server group
associated.

URI
^^^

POST /v3/{project_id}/elb/pools

.. table:: **Table 1** Path parameters

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
   ========== ========= ====== =========================

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 2** Request header parameters

   ============ ========= ====== ================================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ================================================
   X-Auth-Token Yes       String Specifies the token used for IAM authentication.
   ============ ========= ====== ================================================

.. table:: **Table 3** Request body parameters

   +-----------+-----------+----------------------+-------------------------------------+
   | Parameter | Mandatory | Type                 | Description                         |
   +===========+===========+======================+=====================================+
   | pool      | Yes       | :ref:`dpc_po` object | Specifies the backend server group. |
   +-----------+-----------+----------------------+-------------------------------------+

.. _dpc_po:
.. table:: **Table 4** CreatePoolOption

   +---------------------+-----------+-----------------------+-----------------------------+
   | Parameter           | Mandatory | Type                  | Description                 |
   +=====================+===========+=======================+=============================+
   | admin_state_up      | No        | Boolean               | Specifies the               |
   |                     |           |                       | administrative status of    |
   |                     |           |                       | the backend server group.   |
   |                     |           |                       | The value can only be       |
   |                     |           |                       | updated to **true**.        |
   |                     |           |                       |                             |
   |                     |           |                       | This parameter is           |
   |                     |           |                       | unsupported. Please do not  |
   |                     |           |                       | use it.                     |
   +---------------------+-----------+-----------------------+-----------------------------+
   | description         | No        | String                | Provides supplementary      |
   |                     |           |                       | information about the       |
   |                     |           |                       | backend server group.       |
   |                     |           |                       |                             |
   |                     |           |                       | Minimum: **0**              |
   |                     |           |                       |                             |
   |                     |           |                       | Maximum: **255**            |
   +---------------------+-----------+-----------------------+-----------------------------+
   | lb_algorithm        | Yes       | String                | Specifies the load          |
   |                     |           |                       | balancing algorithm used by |
   |                     |           |                       | the load balancer to route  |
   |                     |           |                       | requests to backend         |
   |                     |           |                       | servers.                    |
   |                     |           |                       |                             |
   |                     |           |                       | The value can be one of the |
   |                     |           |                       | following:                  |
   |                     |           |                       |                             |
   |                     |           |                       | -  **ROUND_ROBIN**:         |
   |                     |           |                       |    weighted round robin     |
   |                     |           |                       |                             |
   |                     |           |                       | -  **LEAST_CONNECTIONS**:   |
   |                     |           |                       |    weighted least           |
   |                     |           |                       |    connections              |
   |                     |           |                       |                             |
   |                     |           |                       | -  **SOURCE_IP**: source IP |
   |                     |           |                       |    hash                     |
   |                     |           |                       |                             |
   |                     |           |                       | When the value is           |
   |                     |           |                       | **SOURCE_IP**, the weights  |
   |                     |           |                       | of backend servers are      |
   |                     |           |                       | invalid.                    |
   +---------------------+-----------+-----------------------+-----------------------------+
   | listener_id         | No        | String                | Specifies the ID of the     |
   |                     |           |                       | listener associated with    |
   |                     |           |                       | the backend server group.   |
   |                     |           |                       | Specify either              |
   |                     |           |                       | **listener_id** or          |
   |                     |           |                       | **loadbalancer_id**, or     |
   |                     |           |                       | both of them.               |
   |                     |           |                       |                             |
   |                     |           |                       | Minimum: **1**              |
   |                     |           |                       |                             |
   |                     |           |                       | Maximum: **36**             |
   +---------------------+-----------+-----------------------+-----------------------------+
   | loadbalancer_id     | No        | String                | Specifies the ID of the     |
   |                     |           |                       | associated load balancer.   |
   |                     |           |                       | Specify either              |
   |                     |           |                       | **listener_id** or          |
   |                     |           |                       | **loadbalancer_id**, or     |
   |                     |           |                       | both of them.               |
   |                     |           |                       |                             |
   |                     |           |                       | Minimum: **1**              |
   |                     |           |                       |                             |
   |                     |           |                       | Maximum: **36**             |
   +---------------------+-----------+-----------------------+-----------------------------+
   | name                | No        | String                | Specifies the backend       |
   |                     |           |                       | server group name.          |
   |                     |           |                       |                             |
   |                     |           |                       | Minimum: **0**              |
   |                     |           |                       |                             |
   |                     |           |                       | Maximum: **255**            |
   +---------------------+-----------+-----------------------+-----------------------------+
   | project_id          | No        | String                | Specifies the project ID.   |
   +---------------------+-----------+-----------------------+-----------------------------+
   | protocol            | Yes       | String                | Specifies the protocol used |
   |                     |           |                       | by the backend server group |
   |                     |           |                       | to receive requests. TCP,   |
   |                     |           |                       | UDP, and HTTP are           |
   |                     |           |                       | supported.                  |
   |                     |           |                       |                             |
   |                     |           |                       | -  For UDP listeners, the   |
   |                     |           |                       |    protocol of the backend  |
   |                     |           |                       |    server group must be     |
   |                     |           |                       |    UDP.                     |
   |                     |           |                       |                             |
   |                     |           |                       | -  For TCP listeners, the   |
   |                     |           |                       |    protocol of the backend  |
   |                     |           |                       |    server group must be     |
   |                     |           |                       |    TCP.                     |
   |                     |           |                       |                             |
   |                     |           |                       | -  For HTTP or HTTPS        |
   |                     |           |                       |    listeners, the protocol  |
   |                     |           |                       |    of the backend server    |
   |                     |           |                       |    group must be HTTP.      |
   |                     |           |                       |                             |
   |                     |           |                       | Minimum: **1**              |
   |                     |           |                       |                             |
   |                     |           |                       | Maximum: **255**            |
   +---------------------+-----------+-----------------------+-----------------------------+
   | session_persistence | No        | :ref:`dpc_spo` object | Specifies whether to enable |
   |                     |           |                       | sticky sessions.            |
   +---------------------+-----------+-----------------------+-----------------------------+
   | slow_start          | No        | :ref:`dpc_sso` object | Specifies whether to enable |
   |                     |           |                       | slow start. After you       |
   |                     |           |                       | enable slow start, new      |
   |                     |           |                       | backend servers added to    |
   |                     |           |                       | the backend server group    |
   |                     |           |                       | are warmed up, and the      |
   |                     |           |                       | number of requests they can |
   |                     |           |                       | receive increases linearly  |
   |                     |           |                       | during the configured slow  |
   |                     |           |                       | start duration.             |
   |                     |           |                       |                             |
   |                     |           |                       | This parameter can be used  |
   |                     |           |                       | when the protocol of the    |
   |                     |           |                       | backend server group is     |
   |                     |           |                       | HTTP or HTTPS. An error     |
   |                     |           |                       | will be returned if the     |
   |                     |           |                       | protocol is not HTTP or     |
   |                     |           |                       | HTTPS.                      |
   |                     |           |                       |                             |
   |                     |           |                       | This parameter is           |
   |                     |           |                       | unsupported. Please do not  |
   |                     |           |                       | use it.                     |
   +---------------------+-----------+-----------------------+-----------------------------+

.. _dpc_spo:
.. table:: **Table 5** CreatePoolSessionPersistenceOption

   +---------------------+-----------+---------+-----------------------------+
   | Parameter           | Mandatory | Type    | Description                 |
   +=====================+===========+=========+=============================+
   | cookie_name         | No        | String  | Specifies the cookie name.  |
   |                     |           |         | This parameter will take    |
   |                     |           |         | effect only when **type**   |
   |                     |           |         | is set to **APP_COOKIE**.   |
   |                     |           |         | Otherwise, an error will be |
   |                     |           |         | returned.                   |
   |                     |           |         |                             |
   |                     |           |         | The value can contain only  |
   |                     |           |         | letters, digits, hyphens    |
   |                     |           |         | (-), underscores (_), and   |
   |                     |           |         | periods (.).                |
   |                     |           |         |                             |
   |                     |           |         | Minimum: **0**              |
   |                     |           |         |                             |
   |                     |           |         | Maximum: **1024**           |
   +---------------------+-----------+---------+-----------------------------+
   | type                | Yes       | String  | Specifies the sticky        |
   |                     |           |         | session type. The value can |
   |                     |           |         | be **SOURCE_IP**,           |
   |                     |           |         | **HTTP_COOKIE**, or         |
   |                     |           |         | **APP_COOKIE**.             |
   |                     |           |         |                             |
   |                     |           |         | -  If the protocol of the   |
   |                     |           |         |    backend server group is  |
   |                     |           |         |    TCP or UDP, only         |
   |                     |           |         |    **SOURCE_IP** takes      |
   |                     |           |         |    effect.                  |
   |                     |           |         |                             |
   |                     |           |         | -  For dedicated load       |
   |                     |           |         |    balancers, if the        |
   |                     |           |         |    protocol of the backend  |
   |                     |           |         |    server group is HTTP or  |
   |                     |           |         |    HTTPS, the value can     |
   |                     |           |         |    only be **HTTP_COOKIE**. |
   |                     |           |         |                             |
   |                     |           |         | -  For shared load          |
   |                     |           |         |    balancers, if the        |
   |                     |           |         |    protocol of the backend  |
   |                     |           |         |    server group is HTTP or  |
   |                     |           |         |    HTTPS, the value can be  |
   |                     |           |         |    **HTTP_COOKIE** or       |
   |                     |           |         |    **APP_COOKIE**.          |
   +---------------------+-----------+---------+-----------------------------+
   | persistence_timeout | No        | Integer | Specifies the stickiness    |
   |                     |           |         | duration, in minutes. This  |
   |                     |           |         | parameter will not take     |
   |                     |           |         | effect when **type** is set |
   |                     |           |         | to **APP_COOKIE**.          |
   |                     |           |         |                             |
   |                     |           |         | -  If the protocol of the   |
   |                     |           |         |    backend server group is  |
   |                     |           |         |    TCP or UDP, the value    |
   |                     |           |         |    ranges from **1** to     |
   |                     |           |         |    **60**, and the default  |
   |                     |           |         |    value is **1**.          |
   |                     |           |         |                             |
   |                     |           |         | -  If the protocol of the   |
   |                     |           |         |    backend server group is  |
   |                     |           |         |    HTTP or HTTPS, the value |
   |                     |           |         |    ranges from **1** to     |
   |                     |           |         |    **1440**, and the        |
   |                     |           |         |    default value is         |
   |                     |           |         |    **1440**.                |
   +---------------------+-----------+---------+-----------------------------+

.. _dpc_sso:
.. table:: **Table 6** CreatePoolSlowStartOption

   +-----------+-----------+---------+-----------------------------+
   | Parameter | Mandatory | Type    | Description                 |
   +===========+===========+=========+=============================+
   | enable    | Yes       | Boolean | Specifies whether to enable |
   |           |           |         | slow start.                 |
   |           |           |         |                             |
   |           |           |         | **true** indicates that     |
   |           |           |         | this function is enabled,   |
   |           |           |         | and **false** indicates     |
   |           |           |         | this function is disabled.  |
   |           |           |         |                             |
   |           |           |         | Default: **false**          |
   +-----------+-----------+---------+-----------------------------+
   | duration  | Yes       | Integer | Specifies the slow start    |
   |           |           |         | duration, in seconds.       |
   |           |           |         |                             |
   |           |           |         | The value ranges from       |
   |           |           |         | **30** to **1200**, and the |
   |           |           |         | default value is **30**.    |
   |           |           |         |                             |
   |           |           |         | Minimum: **30**             |
   |           |           |         |                             |
   |           |           |         | Maximum: **1200**           |
   |           |           |         |                             |
   |           |           |         | Default: **30**             |
   +-----------+-----------+---------+-----------------------------+

Response Parameters
^^^^^^^^^^^^^^^^^^^

**Status code: 201**

.. table:: **Table 7** Response body parameters

   ========== =================== ===============================================================
   Parameter  Type                Description
   ========== =================== ===============================================================
   request_id String              Specifies the request ID. The value is automatically generated.
   pool       :ref:`dpc_p` object Specifies the backend server group.
   ========== =================== ===============================================================

.. _dpc_p:
.. table:: **Table 8** Pool

   +---------------------+---------------------------------+---------------------------------------+
   | Parameter           | Type                            | Description                           |
   +=====================+=================================+=======================================+
   | admin_state_up      | Boolean                         | Specifies the administrative status   |
   |                     |                                 | of the backend server group. The      |
   |                     |                                 | value can only be updated to          |
   |                     |                                 | **true**.                             |
   |                     |                                 |                                       |
   |                     |                                 | This parameter is unsupported. Please |
   |                     |                                 | do not use it.                        |
   |                     |                                 |                                       |
   |                     |                                 | Default: **true**                     |
   +---------------------+---------------------------------+---------------------------------------+
   | description         | String                          | Provides supplementary information    |
   |                     |                                 | about the backend server group.       |
   +---------------------+---------------------------------+---------------------------------------+
   | healthmonitor_id    | String                          | Specifies the ID of the health check  |
   |                     |                                 | configured for the backend server     |
   |                     |                                 | group.                                |
   +---------------------+---------------------------------+---------------------------------------+
   | id                  | String                          | Specifies the backend server group    |
   |                     |                                 | ID.                                   |
   +---------------------+---------------------------------+---------------------------------------+
   | lb_algorithm        | String                          | Specifies the load balancing          |
   |                     |                                 | algorithm used by the load balancer   |
   |                     |                                 | to route requests to backend servers  |
   |                     |                                 | in the backend server group.          |
   |                     |                                 |                                       |
   |                     |                                 | The value can be **ROUND_ROBIN**      |
   |                     |                                 | (weighted round robin),               |
   |                     |                                 | **LEAST_CONNECTIONS** (weighted least |
   |                     |                                 | connections), or **SOURCE_IP**        |
   |                     |                                 | (source IP hash).                     |
   |                     |                                 |                                       |
   |                     |                                 | When the value is **SOURCE_IP**, the  |
   |                     |                                 | **weight** parameter is invalid.      |
   +---------------------+---------------------------------+---------------------------------------+
   | listeners           | :ref:`dpc_lir` objects          | Lists the listeners associated with   |
   |                     |                                 | the backend server group.             |
   +---------------------+---------------------------------+---------------------------------------+
   | loadbalancers       | Array of :ref:`dpc_lbr` objects | Lists the IDs of load balancers       |
   |                     |                                 | associated with the backend server    |
   |                     |                                 | group.                                |
   |                     |                                 |                                       |
   |                     |                                 | If only **listener_id** is specified  |
   |                     |                                 | during the creation of the backend    |
   |                     |                                 | server group, the ID of the           |
   |                     |                                 | **loadbalancers** parameter in the    |
   |                     |                                 | response is the ID of the load        |
   |                     |                                 | balancer to which the listener is     |
   |                     |                                 | added.                                |
   +---------------------+---------------------------------+---------------------------------------+
   | members             | Array of :ref:`dpc_mr` objects  | Lists the backend servers in the      |
   |                     |                                 | backend server group.                 |
   +---------------------+---------------------------------+---------------------------------------+
   | name                | String                          | Specifies the backend server group    |
   |                     |                                 | name.                                 |
   +---------------------+---------------------------------+---------------------------------------+
   | project_id          | String                          | Specifies the project ID.             |
   +---------------------+---------------------------------+---------------------------------------+
   | protocol            | String                          | Specifies the protocol used by the    |
   |                     |                                 | backend server group to receive       |
   |                     |                                 | requests. The protocol can be TCP,    |
   |                     |                                 | UDP, or HTTP.                         |
   |                     |                                 |                                       |
   |                     |                                 | -  For UDP listeners, the protocol of |
   |                     |                                 |    the backend server group must be   |
   |                     |                                 |    UDP.                               |
   |                     |                                 |                                       |
   |                     |                                 | -  For TCP listeners, the protocol of |
   |                     |                                 |    the backend server group must be   |
   |                     |                                 |    TCP.                               |
   |                     |                                 |                                       |
   |                     |                                 | -  For HTTP or HTTPS listeners, the   |
   |                     |                                 |    protocol of the backend server     |
   |                     |                                 |    group must be HTTP.                |
   +---------------------+---------------------------------+---------------------------------------+
   | session_persistence | :ref:`dpc_sp` object            | Specifies the sticky session.         |
   +---------------------+---------------------------------+---------------------------------------+
   | ip_version          | String                          | Specifies the IP version supported by |
   |                     |                                 | the backend server group.             |
   |                     |                                 |                                       |
   |                     |                                 | -  Shared load balancers: The default |
   |                     |                                 |    value is **v4**.                   |
   |                     |                                 |                                       |
   |                     |                                 | -  Dedicated load balancers: The      |
   |                     |                                 |    value can be **dualstack**,        |
   |                     |                                 |    **v4**, or **v6**.                 |
   |                     |                                 |                                       |
   |                     |                                 | When the protocol of the backend      |
   |                     |                                 | server group is TCP or UDP,           |
   |                     |                                 | **ip_version** is set to              |
   |                     |                                 | **dualstack**, indicating that both   |
   |                     |                                 | IPv4 and IPv6 are supported.          |
   |                     |                                 |                                       |
   |                     |                                 | When the protocol of the backend      |
   |                     |                                 | server group is HTTP, **ip_version**  |
   |                     |                                 | is set to **v4**.                     |
   |                     |                                 |                                       |
   |                     |                                 | IPv6 is unsupported. Only **v4** is   |
   |                     |                                 | returned.                             |
   |                     |                                 |                                       |
   |                     |                                 | Default: **dualstack**                |
   +---------------------+---------------------------------+---------------------------------------+
   | slow_start          | :ref:`dpc_ss` object            | Specifies whether to enable slow      |
   |                     |                                 | start. After you enable slow start,   |
   |                     |                                 | new backend servers added to the      |
   |                     |                                 | backend server group are warmed up,   |
   |                     |                                 | and the number of requests they can   |
   |                     |                                 | receive increases linearly during the |
   |                     |                                 | configured slow start duration.       |
   |                     |                                 |                                       |
   |                     |                                 | This parameter can be used when the   |
   |                     |                                 | protocol of the backend server group  |
   |                     |                                 | is HTTP or HTTPS. An error will be    |
   |                     |                                 | returned if the protocol is not HTTP  |
   |                     |                                 | or HTTPS.                             |
   |                     |                                 |                                       |
   |                     |                                 | This parameter is unsupported. Please |
   |                     |                                 | do not use it.                        |
   +---------------------+---------------------------------+---------------------------------------+

.. _dpc_lir:
.. table:: **Table 9** ListenerRef

   ========= ====== ==========================
   Parameter Type   Description
   ========= ====== ==========================
   id        String Specifies the listener ID.
   ========= ====== ==========================

.. _dpc_lbr:
.. table:: **Table 10** LoadBalancerRef

   ========= ====== ===============================
   Parameter Type   Description
   ========= ====== ===============================
   id        String Specifies the load balancer ID.
   ========= ====== ===============================

.. _dpc_mr:
.. table:: **Table 11** MemberRef

   ========= ====== ================================
   Parameter Type   Description
   ========= ====== ================================
   id        String Specifies the backend server ID.
   ========= ====== ================================

.. _dpc_sp:
.. table:: **Table 12** SessionPersistence

   +---------------------+---------+---------------------------------------+
   | Parameter           | Type    | Description                           |
   +=====================+=========+=======================================+
   | cookie_name         | String  | Specifies the cookie name.            |
   |                     |         |                                       |
   |                     |         | This parameter will take effect only  |
   |                     |         | when **type** is set to               |
   |                     |         | **APP_COOKIE**.                       |
   |                     |         |                                       |
   |                     |         | The value can contain only letters,   |
   |                     |         | digits, hyphens (-), underscores (_), |
   |                     |         | and periods (.).                      |
   |                     |         |                                       |
   |                     |         | Minimum: **0**                        |
   |                     |         |                                       |
   |                     |         | Maximum: **1024**                     |
   +---------------------+---------+---------------------------------------+
   | type                | String  | Specifies the sticky session type.    |
   |                     |         | The value can be **SOURCE_IP**,       |
   |                     |         | **HTTP_COOKIE**, or **APP_COOKIE**.   |
   |                     |         |                                       |
   |                     |         | -  If the protocol of the backend     |
   |                     |         |    server group is TCP or UDP, only   |
   |                     |         |    **SOURCE_IP** takes effect.        |
   |                     |         |                                       |
   |                     |         | -  For dedicated load balancers, if   |
   |                     |         |    the protocol of the backend server |
   |                     |         |    group is HTTP or HTTPS, the value  |
   |                     |         |    can only be **HTTP_COOKIE**.       |
   |                     |         |                                       |
   |                     |         | -  For shared load balancers, if the  |
   |                     |         |    protocol of the backend server     |
   |                     |         |    group is HTTP or HTTPS, the value  |
   |                     |         |    can be **HTTP_COOKIE** or          |
   |                     |         |    **APP_COOKIE**.                    |
   +---------------------+---------+---------------------------------------+
   | persistence_timeout | Integer | Specifies the stickiness duration, in |
   |                     |         | minutes. This parameter will not take |
   |                     |         | effect when **type** is set to        |
   |                     |         | **APP_COOKIE**.                       |
   |                     |         |                                       |
   |                     |         | -  If the protocol of the backend     |
   |                     |         |    server group is TCP or UDP, the    |
   |                     |         |    value ranges from **1** to **60**, |
   |                     |         |    and the default value is **1**.    |
   |                     |         |                                       |
   |                     |         | -  If the protocol of the backend     |
   |                     |         |    server group is HTTP or HTTPS, the |
   |                     |         |    value ranges from **1** to         |
   |                     |         |    **1440**, and the default value is |
   |                     |         |    **1440**.                          |
   +---------------------+---------+---------------------------------------+

.. _dpc_ss:
.. table:: **Table 13** SlowStart

   +-----------+---------+---------------------------------------+
   | Parameter | Type    | Description                           |
   +===========+=========+=======================================+
   | enable    | Boolean | Specifies whether to enable slow      |
   |           |         | start.                                |
   |           |         |                                       |
   |           |         | **true** indicates that this function |
   |           |         | is enabled, and **false** indicates   |
   |           |         | this function is disabled.            |
   |           |         |                                       |
   |           |         | Default: **false**                    |
   +-----------+---------+---------------------------------------+
   | duration  | Integer | Specifies the slow start duration, in |
   |           |         | seconds.                              |
   |           |         |                                       |
   |           |         | The value ranges from **30** to       |
   |           |         | **1200**, and the default value is    |
   |           |         | **30**.                               |
   |           |         |                                       |
   |           |         | Minimum: **30**                       |
   |           |         |                                       |
   |           |         | Maximum: **1200**                     |
   |           |         |                                       |
   |           |         | Default: **30**                       |
   +-----------+---------+---------------------------------------+

Example Requests
^^^^^^^^^^^^^^^^

Adding an HTTP backend server group

.. code::

   POST
   https://{elb_endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/pools

   {
     "pool" : {
       "name" : "My pool",
       "lb_algorithm" : "LEAST_CONNECTIONS",
       "listener_id" : "0b11747a-b139-492f-9692-2df0b1c87193",
       "protocol" : "HTTP",
       "slow_start" : {
         "enable" : true,
         "duration" : 50
       }
     }
   }

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 201**

Successful request.

.. code::

   {
     "pool" : {
       "lb_algorithm" : "LEAST_CONNECTIONS",
       "protocol" : "HTTP",
       "description" : "",
       "admin_state_up" : true,
       "loadbalancers" : [ {
         "id" : "098b2f68-af1c-41a9-8efd-69958722af62"
       } ],
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "listeners" : [ {
         "id" : "0b11747a-b139-492f-9692-2df0b1c87193"
       } ],
       "members" : [ ],
       "id" : "36ce7086-a496-4666-9064-5ba0e6840c75",
       "name" : "My pool",
       "ip_version" : "v4",
       "slow_start" : {
         "enable" : true,
         "duration" : 50
       }
     },
     "request_id" : "2d974978-0733-404d-a21a-b29204f4803a"
   }

Status Codes
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
201         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Querying Backend Server Groups
==============================

Function
^^^^^^^^

This API is used to query all backend server groups.

Constraints
^^^^^^^^^^^

Parameters **marker**, **limit**, and **page_reverse** are used for pagination
query.

Parameters **marker** and **page_reverse** take effect only when they are used
together with parameter **limit**.

URI
^^^

GET /v3/{project_id}/elb/pools

.. table:: **Table 1** Path parameters

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
   ========== ========= ====== =========================

.. table:: **Table 2** Query parameters

   +-----------------------+-----------+---------+-----------------------------+
   | Parameter             | Mandatory | Type    | Description                 |
   +=======================+===========+=========+=============================+
   | marker                | No        | String  | Specifies the ID of the     |
   |                       |           |         | last record on the previous |
   |                       |           |         | page.                       |
   |                       |           |         |                             |
   |                       |           |         | Note:                       |
   |                       |           |         |                             |
   |                       |           |         | -  This parameter must be   |
   |                       |           |         |    used together with       |
   |                       |           |         |    **limit**.               |
   |                       |           |         |                             |
   |                       |           |         | -  If this parameter is not |
   |                       |           |         |    specified, the first     |
   |                       |           |         |    page will be queried.    |
   |                       |           |         |                             |
   |                       |           |         | -  This parameter cannot be |
   |                       |           |         |    left blank or set to an  |
   |                       |           |         |    invalid ID.              |
   +-----------------------+-----------+---------+-----------------------------+
   | limit                 | No        | Integer | Specifies the number of     |
   |                       |           |         | records on each page.       |
   |                       |           |         |                             |
   |                       |           |         | Minimum: **0**              |
   |                       |           |         |                             |
   |                       |           |         | Maximum: **2000**           |
   +-----------------------+-----------+---------+-----------------------------+
   | page_reverse          | No        | Boolean | Specifies the page          |
   |                       |           |         | direction. The value can be |
   |                       |           |         | **true** or **false**, and  |
   |                       |           |         | the default value is        |
   |                       |           |         | **false**. The last page in |
   |                       |           |         | the list requested with     |
   |                       |           |         | **page_reverse** set to     |
   |                       |           |         | **false** will not contain  |
   |                       |           |         | the "next" link, and the    |
   |                       |           |         | last page in the list       |
   |                       |           |         | requested with              |
   |                       |           |         | **page_reverse** set to     |
   |                       |           |         | **true** will not contain   |
   |                       |           |         | the "previous" link. This   |
   |                       |           |         | parameter must be used      |
   |                       |           |         | together with **limit**.    |
   +-----------------------+-----------+---------+-----------------------------+
   | description           | No        | Array   | Provides supplementary      |
   |                       |           |         | information about the       |
   |                       |           |         | backend server group.       |
   |                       |           |         |                             |
   |                       |           |         | Multiple descriptions can   |
   |                       |           |         | be queried in the format of |
   |                       |           |         | *descri                     |
   |                       |           |         | ption=xxx&description=xxx*. |
   +-----------------------+-----------+---------+-----------------------------+
   | admin_state_up        | No        | Boolean | Specifies the               |
   |                       |           |         | administrative status of    |
   |                       |           |         | the backend server group.   |
   |                       |           |         |                             |
   |                       |           |         | This parameter is           |
   |                       |           |         | unsupported. Please do not  |
   |                       |           |         | use it.                     |
   +-----------------------+-----------+---------+-----------------------------+
   | healthmonitor_id      | No        | Array   | Specifies the ID of the     |
   |                       |           |         | health check configured for |
   |                       |           |         | the backend server group.   |
   |                       |           |         |                             |
   |                       |           |         | Multiple IDs can be queried |
   |                       |           |         | in the format of            |
   |                       |           |         | *healthmonitor_id           |
   |                       |           |         | =xxx&healthmonitor_id=xxx*. |
   +-----------------------+-----------+---------+-----------------------------+
   | id                    | No        | Array   | Specifies the ID of the     |
   |                       |           |         | backend server group.       |
   |                       |           |         |                             |
   |                       |           |         | Multiple IDs can be queried |
   |                       |           |         | in the format of            |
   |                       |           |         | *id=xxx&id=xxx*.            |
   +-----------------------+-----------+---------+-----------------------------+
   | name                  | No        | Array   | Specifies the backend       |
   |                       |           |         | server group name.          |
   |                       |           |         |                             |
   |                       |           |         | Multiple names can be       |
   |                       |           |         | queried in the format of    |
   |                       |           |         | *name=xxx&name=xxx*.        |
   +-----------------------+-----------+---------+-----------------------------+
   | loadbalancer_id       | No        | Array   | Specifies the ID of the     |
   |                       |           |         | load balancer associated    |
   |                       |           |         | with the backend server     |
   |                       |           |         | group.                      |
   |                       |           |         |                             |
   |                       |           |         | Multiple IDs can be queried |
   |                       |           |         | in the format of            |
   |                       |           |         | *loadbalancer_i             |
   |                       |           |         | d=xxx&loadbalancer_id=xxx*. |
   +-----------------------+-----------+---------+-----------------------------+
   | protocol              | No        | Array   | Specifies the protocol used |
   |                       |           |         | by the backend server group |
   |                       |           |         | to receive requests.        |
   |                       |           |         |                             |
   |                       |           |         | Multiple protocols can be   |
   |                       |           |         | queried in the format of    |
   |                       |           |         | *                           |
   |                       |           |         | protocol=xxx&protocol=xxx*. |
   +-----------------------+-----------+---------+-----------------------------+
   | lb_algorithm          | No        | Array   | Specifies the load          |
   |                       |           |         | balancing algorithm used by |
   |                       |           |         | the load balancer to route  |
   |                       |           |         | requests to backend servers |
   |                       |           |         | in the backend server       |
   |                       |           |         | group.                      |
   |                       |           |         |                             |
   |                       |           |         | The value can be            |
   |                       |           |         | **ROUND_ROBIN** (weighted   |
   |                       |           |         | round robin),               |
   |                       |           |         | **LEAST_CONNECTIONS**       |
   |                       |           |         | (weighted least             |
   |                       |           |         | connections), or            |
   |                       |           |         | **SOURCE_IP** (source IP    |
   |                       |           |         | hash).                      |
   |                       |           |         |                             |
   |                       |           |         | If the value is             |
   |                       |           |         | **SOURCE_IP**, **weight**   |
   |                       |           |         | will not take effect.       |
   |                       |           |         |                             |
   |                       |           |         | Multiple algorithms can be  |
   |                       |           |         | queried in the format of    |
   |                       |           |         | *lb_algor                   |
   |                       |           |         | ithm=xxx&lb_algorithm=xxx*. |
   +-----------------------+-----------+---------+-----------------------------+
   | enterprise_project_id | No        | Array   | Specifies the enterprise    |
   |                       |           |         | project ID.                 |
   |                       |           |         |                             |
   |                       |           |         | -  If this parameter is not |
   |                       |           |         |    passed, resources in the |
   |                       |           |         |    default enterprise       |
   |                       |           |         |    project are queried, and |
   |                       |           |         |    authentication is        |
   |                       |           |         |    performed based on the   |
   |                       |           |         |    default enterprise       |
   |                       |           |         |    project.                 |
   |                       |           |         |                             |
   |                       |           |         | -  If this parameter is     |
   |                       |           |         |    passed, its value can be |
   |                       |           |         |    the ID of an existing    |
   |                       |           |         |    enterprise project or    |
   |                       |           |         |    **all_granted_eps**.     |
   |                       |           |         |                             |
   |                       |           |         | If the value is a specific  |
   |                       |           |         | ID, resources in the        |
   |                       |           |         | specific enterprise project |
   |                       |           |         | are required. If the value  |
   |                       |           |         | is **all_granted_eps**,     |
   |                       |           |         | resources in all enterprise |
   |                       |           |         | projects are queried.       |
   |                       |           |         |                             |
   |                       |           |         | Multiple IDs can be queried |
   |                       |           |         | in the format of            |
   |                       |           |         | *enterprise_project_id=xxx& |
   |                       |           |         | enterprise_project_id=xxx*. |
   |                       |           |         |                             |
   |                       |           |         | This parameter is           |
   |                       |           |         | unsupported. Please do not  |
   |                       |           |         | use it.                     |
   +-----------------------+-----------+---------+-----------------------------+
   | ip_version            | No        | Array   | Specifies the IP address    |
   |                       |           |         | version of the backend      |
   |                       |           |         | server group. The value can |
   |                       |           |         | be **dualstack**, **v4**,   |
   |                       |           |         | or **v6**.                  |
   |                       |           |         |                             |
   |                       |           |         | Multiple versions can be    |
   |                       |           |         | queried in the format of    |
   |                       |           |         | *ip_v                       |
   |                       |           |         | ersion=xxx&ip_version=xxx*. |
   +-----------------------+-----------+---------+-----------------------------+
   | member_address        | No        | Array   | Specifies the private IP    |
   |                       |           |         | address bound to the        |
   |                       |           |         | backend server. This        |
   |                       |           |         | parameter is used only as a |
   |                       |           |         | query condition and is not  |
   |                       |           |         | included in the response.   |
   |                       |           |         |                             |
   |                       |           |         | Multiple IP addresses can   |
   |                       |           |         | be queried in the format of |
   |                       |           |         | *member_addre               |
   |                       |           |         | ss=xxx&member_address=xxx*. |
   +-----------------------+-----------+---------+-----------------------------+
   | member_device_id      | No        | Array   | Specifies the ID of the     |
   |                       |           |         | cloud server that serves as |
   |                       |           |         | a backend server. This      |
   |                       |           |         | parameter is used only as a |
   |                       |           |         | query condition and is not  |
   |                       |           |         | included in the response.   |
   |                       |           |         |                             |
   |                       |           |         | Multiple IDs can be queried |
   |                       |           |         | in the format of            |
   |                       |           |         | *member_device_id           |
   |                       |           |         | =xxx&member_device_id=xxx*. |
   +-----------------------+-----------+---------+-----------------------------+

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 3** Request header parameters

   ============ ========= ====== ================================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ================================================
   X-Auth-Token Yes       String Specifies the token used for IAM authentication.
   ============ ========= ====== ================================================

Response Parameters
^^^^^^^^^^^^^^^^^^^

**Status code: 200**

.. table:: **Table 4** Response body parameters

   +------------+-------------------------------+----------------------------------------+
   | Parameter  | Type                          | Description                            |
   +============+===============================+========================================+
   | request_id | String                        | Specifies the request ID. The value is |
   |            |                               | automatically generated.               |
   +------------+-------------------------------+----------------------------------------+
   | page_info  | :ref:`dpl_pi` object          | Shows pagination information.          |
   +------------+-------------------------------+----------------------------------------+
   | pools      | Array of :ref:`dpl_p` objects | Lists the backend server groups.       |
   +------------+-------------------------------+----------------------------------------+

.. _dpl_pi:
.. table:: **Table 5** PageInfo

   +-----------------+---------+----------------------------------------------------------------------------------------+
   | Parameter       | Type    | Description                                                                            |
   +=================+=========+========================================================================================+
   | previous_marker | String  | Specifies the ID of the first record in the pagination query result. This parameter    |
   |                 |         | will not be returned if no query result is returned.                                   |
   +-----------------+---------+----------------------------------------------------------------------------------------+
   | next_marker     | String  | Marks the start record on the next page in the pagination query result. This parameter |
   |                 |         | will not be returned if there is no next page.                                         |
   +-----------------+---------+----------------------------------------------------------------------------------------+
   | current_count   | Integer | Specifies the number of records.                                                       |
   +-----------------+---------+----------------------------------------------------------------------------------------+

.. _dpl_p:
.. table:: **Table 6** Pool

   +---------------------+---------------------------------+---------------------------------------+
   | Parameter           | Type                            | Description                           |
   +=====================+=================================+=======================================+
   | admin_state_up      | Boolean                         | Specifies the administrative status   |
   |                     |                                 | of the backend server group. The      |
   |                     |                                 | value can only be updated to          |
   |                     |                                 | **true**.                             |
   |                     |                                 |                                       |
   |                     |                                 | This parameter is unsupported. Please |
   |                     |                                 | do not use it.                        |
   |                     |                                 |                                       |
   |                     |                                 | Default: **true**                     |
   +---------------------+---------------------------------+---------------------------------------+
   | description         | String                          | Provides supplementary information    |
   |                     |                                 | about the backend server group.       |
   +---------------------+---------------------------------+---------------------------------------+
   | healthmonitor_id    | String                          | Specifies the ID of the health check  |
   |                     |                                 | configured for the backend server     |
   |                     |                                 | group.                                |
   +---------------------+---------------------------------+---------------------------------------+
   | id                  | String                          | Specifies the backend server group    |
   |                     |                                 | ID.                                   |
   +---------------------+---------------------------------+---------------------------------------+
   | lb_algorithm        | String                          | Specifies the load balancing          |
   |                     |                                 | algorithm used by the load balancer   |
   |                     |                                 | to route requests to backend servers  |
   |                     |                                 | in the backend server group.          |
   |                     |                                 |                                       |
   |                     |                                 | The value can be **ROUND_ROBIN**      |
   |                     |                                 | (weighted round robin),               |
   |                     |                                 | **LEAST_CONNECTIONS** (weighted least |
   |                     |                                 | connections), or **SOURCE_IP**        |
   |                     |                                 | (source IP hash).                     |
   |                     |                                 |                                       |
   |                     |                                 | When the value is **SOURCE_IP**, the  |
   |                     |                                 | **weight** parameter is invalid.      |
   +---------------------+---------------------------------+---------------------------------------+
   | listeners           | Array of :ref:`dpl_lir` objects | Lists the listeners associated with   |
   |                     |                                 | the backend server group.             |
   +---------------------+---------------------------------+---------------------------------------+
   | loadbalancers       | Array of :ref:`dpl_lbr` objects | Lists the IDs of load balancers       |
   |                     |                                 | associated with the backend server    |
   |                     |                                 | group.                                |
   |                     |                                 |                                       |
   |                     |                                 | If only **listener_id** is specified  |
   |                     |                                 | during the creation of the backend    |
   |                     |                                 | server group, the ID of the           |
   |                     |                                 | **loadbalancers** parameter in the    |
   |                     |                                 | response is the ID of the load        |
   |                     |                                 | balancer to which the listener is     |
   |                     |                                 | added.                                |
   +---------------------+---------------------------------+---------------------------------------+
   | members             | Array of :ref:`dpl_mr` objects  | Lists the backend servers in the      |
   |                     |                                 | backend server group.                 |
   +---------------------+---------------------------------+---------------------------------------+
   | name                | String                          | Specifies the backend server group    |
   |                     |                                 | name.                                 |
   +---------------------+---------------------------------+---------------------------------------+
   | project_id          | String                          | Specifies the project ID.             |
   +---------------------+---------------------------------+---------------------------------------+
   | protocol            | String                          | Specifies the protocol used by the    |
   |                     |                                 | backend server group to receive       |
   |                     |                                 | requests. The protocol can be TCP,    |
   |                     |                                 | UDP, or HTTP.                         |
   |                     |                                 |                                       |
   |                     |                                 | -  For UDP listeners, the protocol of |
   |                     |                                 |    the backend server group must be   |
   |                     |                                 |    UDP.                               |
   |                     |                                 |                                       |
   |                     |                                 | -  For TCP listeners, the protocol of |
   |                     |                                 |    the backend server group must be   |
   |                     |                                 |    TCP.                               |
   |                     |                                 |                                       |
   |                     |                                 | -  For HTTP or HTTPS listeners, the   |
   |                     |                                 |    protocol of the backend server     |
   |                     |                                 |    group must be HTTP.                |
   +---------------------+---------------------------------+---------------------------------------+
   | session_persistence | :ref:`dpl_sp` object            | Specifies the sticky session.         |
   +---------------------+---------------------------------+---------------------------------------+
   | ip_version          | String                          | Specifies the IP version supported by |
   |                     |                                 | the backend server group.             |
   |                     |                                 |                                       |
   |                     |                                 | -  Shared load balancers: The default |
   |                     |                                 |    value is **v4**.                   |
   |                     |                                 |                                       |
   |                     |                                 | -  Dedicated load balancers: The      |
   |                     |                                 |    value can be **dualstack**,        |
   |                     |                                 |    **v4**, or **v6**.                 |
   |                     |                                 |                                       |
   |                     |                                 | When the protocol of the backend      |
   |                     |                                 | server group is TCP or UDP,           |
   |                     |                                 | **ip_version** is set to              |
   |                     |                                 | **dualstack**, indicating that both   |
   |                     |                                 | IPv4 and IPv6 are supported.          |
   |                     |                                 |                                       |
   |                     |                                 | When the protocol of the backend      |
   |                     |                                 | server group is HTTP, **ip_version**  |
   |                     |                                 | is set to **v4**.                     |
   |                     |                                 |                                       |
   |                     |                                 | IPv6 is unsupported. Only **v4** is   |
   |                     |                                 | returned.                             |
   |                     |                                 |                                       |
   |                     |                                 | Default: **dualstack**                |
   +---------------------+---------------------------------+---------------------------------------+
   | slow_start          | :ref:`dpl_ss` object            | Specifies whether to enable slow      |
   |                     |                                 | start. After you enable slow start,   |
   |                     |                                 | new backend servers added to the      |
   |                     |                                 | backend server group are warmed up,   |
   |                     |                                 | and the number of requests they can   |
   |                     |                                 | receive increases linearly during the |
   |                     |                                 | configured slow start duration.       |
   |                     |                                 |                                       |
   |                     |                                 | This parameter can be used when the   |
   |                     |                                 | protocol of the backend server group  |
   |                     |                                 | is HTTP or HTTPS. An error will be    |
   |                     |                                 | returned if the protocol is not HTTP  |
   |                     |                                 | or HTTPS.                             |
   |                     |                                 |                                       |
   |                     |                                 | This parameter is unsupported. Please |
   |                     |                                 | do not use it.                        |
   +---------------------+---------------------------------+---------------------------------------+

.. _dpl_lir:
.. table:: **Table 7** ListenerRef

   ========= ====== ==========================
   Parameter Type   Description
   ========= ====== ==========================
   id        String Specifies the listener ID.
   ========= ====== ==========================

.. _dpl_lbr:
.. table:: **Table 8** LoadBalancerRef

   ========= ====== ===============================
   Parameter Type   Description
   ========= ====== ===============================
   id        String Specifies the load balancer ID.
   ========= ====== ===============================

.. _dpl_mr:
.. table:: **Table 9** MemberRef

   ========= ====== ================================
   Parameter Type   Description
   ========= ====== ================================
   id        String Specifies the backend server ID.
   ========= ====== ================================

.. _dpl_sp:
.. table:: **Table 10** SessionPersistence

   +---------------------+---------+---------------------------------------+
   | Parameter           | Type    | Description                           |
   +=====================+=========+=======================================+
   | cookie_name         | String  | Specifies the cookie name.            |
   |                     |         |                                       |
   |                     |         | This parameter will take effect only  |
   |                     |         | when **type** is set to               |
   |                     |         | **APP_COOKIE**.                       |
   |                     |         |                                       |
   |                     |         | The value can contain only letters,   |
   |                     |         | digits, hyphens (-), underscores (_), |
   |                     |         | and periods (.).                      |
   |                     |         |                                       |
   |                     |         | Minimum: **0**                        |
   |                     |         |                                       |
   |                     |         | Maximum: **1024**                     |
   +---------------------+---------+---------------------------------------+
   | type                | String  | Specifies the sticky session type.    |
   |                     |         | The value can be **SOURCE_IP**,       |
   |                     |         | **HTTP_COOKIE**, or **APP_COOKIE**.   |
   |                     |         |                                       |
   |                     |         | -  If the protocol of the backend     |
   |                     |         |    server group is TCP or UDP, only   |
   |                     |         |    **SOURCE_IP** takes effect.        |
   |                     |         |                                       |
   |                     |         | -  For dedicated load balancers, if   |
   |                     |         |    the protocol of the backend server |
   |                     |         |    group is HTTP or HTTPS, the value  |
   |                     |         |    can only be **HTTP_COOKIE**.       |
   |                     |         |                                       |
   |                     |         | -  For shared load balancers, if the  |
   |                     |         |    protocol of the backend server     |
   |                     |         |    group is HTTP or HTTPS, the value  |
   |                     |         |    can be **HTTP_COOKIE** or          |
   |                     |         |    **APP_COOKIE**.                    |
   +---------------------+---------+---------------------------------------+
   | persistence_timeout | Integer | Specifies the stickiness duration, in |
   |                     |         | minutes. This parameter will not take |
   |                     |         | effect when **type** is set to        |
   |                     |         | **APP_COOKIE**.                       |
   |                     |         |                                       |
   |                     |         | -  If the protocol of the backend     |
   |                     |         |    server group is TCP or UDP, the    |
   |                     |         |    value ranges from **1** to **60**, |
   |                     |         |    and the default value is **1**.    |
   |                     |         |                                       |
   |                     |         | -  If the protocol of the backend     |
   |                     |         |    server group is HTTP or HTTPS, the |
   |                     |         |    value ranges from **1** to         |
   |                     |         |    **1440**, and the default value is |
   |                     |         |    **1440**.                          |
   +---------------------+---------+---------------------------------------+

.. _dpl_ss:
.. table:: **Table 11** SlowStart

   +-----------+---------+---------------------------------------+
   | Parameter | Type    | Description                           |
   +===========+=========+=======================================+
   | enable    | Boolean | Specifies whether to enable slow      |
   |           |         | start.                                |
   |           |         |                                       |
   |           |         | **true** indicates that this function |
   |           |         | is enabled, and **false** indicates   |
   |           |         | this function is disabled.            |
   |           |         |                                       |
   |           |         | Default: **false**                    |
   +-----------+---------+---------------------------------------+
   | duration  | Integer | Specifies the slow start duration, in |
   |           |         | seconds.                              |
   |           |         |                                       |
   |           |         | The value ranges from **30** to       |
   |           |         | **1200**, and the default value is    |
   |           |         | **30**.                               |
   |           |         |                                       |
   |           |         | Minimum: **30**                       |
   |           |         |                                       |
   |           |         | Maximum: **1200**                     |
   |           |         |                                       |
   |           |         | Default: **30**                       |
   +-----------+---------+---------------------------------------+

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   GET https://{elb_endpoint}/v3/{project_id}/elb/pools?limit=2

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 200**

Successful request.

.. code::

   {
     "pools" : [ {
       "lb_algorithm" : "ROUND_ROBIN",
       "protocol" : "HTTP",
       "description" : "",
       "admin_state_up" : true,
       "loadbalancers" : [ {
         "id" : "309a0f61-0b62-45f2-97d1-742f3434338e"
       } ],
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "session_persistence" : {
         "cookie_name" : "my_cookie",
         "type" : "APP_COOKIE",
         "persistence_timeout" : 1
       },
       "healthmonitor_id" : "",
       "listeners" : [ ],
       "members" : [ ],
       "id" : "73bd4fe0-ffbb-4b56-aab4-4f26ddf7a103",
       "name" : "",
       "ip_version" : "v4"
     }, {
       "lb_algorithm" : "SOURCE_IP",
       "protocol" : "TCP",
       "description" : "",
       "admin_state_up" : true,
       "loadbalancers" : [ {
         "id" : "d9763e59-64b7-4e93-aec7-0ff7881ef9bc"
       } ],
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "session_persistence" : {
         "cookie_name" : "",
         "type" : "SOURCE_IP",
         "persistence_timeout" : 1
       },
       "healthmonitor_id" : "",
       "listeners" : [ {
         "id" : "8d21db6f-b475-429e-a9cb-90439b0413b2"
       } ],
       "members" : [ ],
       "id" : "74db02d1-5711-4c77-b383-a450e2b93142",
       "name" : "pool_tcp_001",
       "ip_version" : "dualstack"
     } ],
     "page_info" : {
       "next_marker" : "74db02d1-5711-4c77-b383-a450e2b93142",
       "previous_marker" : "73bd4fe0-ffbb-4b56-aab4-4f26ddf7a103",
       "current_count" : 2
     },
     "request_id" : "a1a7e852-1928-48f7-bbc9-ca8469898713"
   }

Status Codes
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
200         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Viewing Details of a Backend Server Group
=========================================

Function
^^^^^^^^

This API is used to view details of a backend server group.

URI
^^^

GET /v3/{project_id}/elb/pools/{pool_id}

.. table:: **Table 1** Path parameters

   ========== ========= ====== =============================================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =============================================
   project_id Yes       String Specifies the project ID.
   pool_id    Yes       String Specifies the ID of the backend server group.
   ========== ========= ====== =============================================

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 2** Request header parameters

   ============ ========= ====== ================================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ================================================
   X-Auth-Token Yes       String Specifies the token used for IAM authentication.
   ============ ========= ====== ================================================

Response Parameters
^^^^^^^^^^^^^^^^^^^

**Status code: 200**

.. table:: **Table 3** Response body parameters

   ========== =================== ===============================================================
   Parameter  Type                Description
   ========== =================== ===============================================================
   request_id String              Specifies the request ID. The value is automatically generated.
   pool       :ref:`dps_p` object Specifies the backend server group.
   ========== =================== ===============================================================

.. _dps_p:
.. table:: **Table 4** Pool

   +---------------------+---------------------------------+---------------------------------------+
   | Parameter           | Type                            | Description                           |
   +=====================+=================================+=======================================+
   | admin_state_up      | Boolean                         | Specifies the administrative status   |
   |                     |                                 | of the backend server group. The      |
   |                     |                                 | value can only be updated to          |
   |                     |                                 | **true**.                             |
   |                     |                                 |                                       |
   |                     |                                 | This parameter is unsupported. Please |
   |                     |                                 | do not use it.                        |
   |                     |                                 |                                       |
   |                     |                                 | Default: **true**                     |
   +---------------------+---------------------------------+---------------------------------------+
   | description         | String                          | Provides supplementary information    |
   |                     |                                 | about the backend server group.       |
   +---------------------+---------------------------------+---------------------------------------+
   | healthmonitor_id    | String                          | Specifies the ID of the health check  |
   |                     |                                 | configured for the backend server     |
   |                     |                                 | group.                                |
   +---------------------+---------------------------------+---------------------------------------+
   | id                  | String                          | Specifies the backend server group    |
   |                     |                                 | ID.                                   |
   +---------------------+---------------------------------+---------------------------------------+
   | lb_algorithm        | String                          | Specifies the load balancing          |
   |                     |                                 | algorithm used by the load balancer   |
   |                     |                                 | to route requests to backend servers  |
   |                     |                                 | in the backend server group.          |
   |                     |                                 |                                       |
   |                     |                                 | The value can be **ROUND_ROBIN**      |
   |                     |                                 | (weighted round robin),               |
   |                     |                                 | **LEAST_CONNECTIONS** (weighted least |
   |                     |                                 | connections), or **SOURCE_IP**        |
   |                     |                                 | (source IP hash).                     |
   |                     |                                 |                                       |
   |                     |                                 | When the value is **SOURCE_IP**, the  |
   |                     |                                 | **weight** parameter is invalid.      |
   +---------------------+---------------------------------+---------------------------------------+
   | listeners           | Array of :ref:`dps_lir` objects | Lists the listeners associated with   |
   |                     |                                 | the backend server group.             |
   +---------------------+---------------------------------+---------------------------------------+
   | loadbalancers       | Array of :ref:`dps_lbr` objects | Lists the IDs of load balancers       |
   |                     |                                 | associated with the backend server    |
   |                     |                                 | group.                                |
   |                     |                                 |                                       |
   |                     |                                 | If only **listener_id** is specified  |
   |                     |                                 | during the creation of the backend    |
   |                     |                                 | server group, the ID of the           |
   |                     |                                 | **loadbalancers** parameter in the    |
   |                     |                                 | response is the ID of the load        |
   |                     |                                 | balancer to which the listener is     |
   |                     |                                 | added.                                |
   +---------------------+---------------------------------+---------------------------------------+
   | members             | Array of :ref:`dps_mr` objects  | Lists the backend servers in the      |
   |                     |                                 | backend server group.                 |
   +---------------------+---------------------------------+---------------------------------------+
   | name                | String                          | Specifies the backend server group    |
   |                     |                                 | name.                                 |
   +---------------------+---------------------------------+---------------------------------------+
   | project_id          | String                          | Specifies the project ID.             |
   +---------------------+---------------------------------+---------------------------------------+
   | protocol            | String                          | Specifies the protocol used by the    |
   |                     |                                 | backend server group to receive       |
   |                     |                                 | requests. The protocol can be TCP,    |
   |                     |                                 | UDP, or HTTP.                         |
   |                     |                                 |                                       |
   |                     |                                 | -  For UDP listeners, the protocol of |
   |                     |                                 |    the backend server group must be   |
   |                     |                                 |    UDP.                               |
   |                     |                                 |                                       |
   |                     |                                 | -  For TCP listeners, the protocol of |
   |                     |                                 |    the backend server group must be   |
   |                     |                                 |    TCP.                               |
   |                     |                                 |                                       |
   |                     |                                 | -  For HTTP or HTTPS listeners, the   |
   |                     |                                 |    protocol of the backend server     |
   |                     |                                 |    group must be HTTP.                |
   +---------------------+---------------------------------+---------------------------------------+
   | session_persistence | :ref:`dps_sp` object            | Specifies the sticky session.         |
   +---------------------+---------------------------------+---------------------------------------+
   | ip_version          | String                          | Specifies the IP version supported by |
   |                     |                                 | the backend server group.             |
   |                     |                                 |                                       |
   |                     |                                 | -  Shared load balancers: The default |
   |                     |                                 |    value is **v4**.                   |
   |                     |                                 |                                       |
   |                     |                                 | -  Dedicated load balancers: The      |
   |                     |                                 |    value can be **dualstack**,        |
   |                     |                                 |    **v4**, or **v6**.                 |
   |                     |                                 |                                       |
   |                     |                                 | When the protocol of the backend      |
   |                     |                                 | server group is TCP or UDP,           |
   |                     |                                 | **ip_version** is set to              |
   |                     |                                 | **dualstack**, indicating that both   |
   |                     |                                 | IPv4 and IPv6 are supported.          |
   |                     |                                 |                                       |
   |                     |                                 | When the protocol of the backend      |
   |                     |                                 | server group is HTTP, **ip_version**  |
   |                     |                                 | is set to **v4**.                     |
   |                     |                                 |                                       |
   |                     |                                 | IPv6 is unsupported. Only **v4** is   |
   |                     |                                 | returned.                             |
   |                     |                                 |                                       |
   |                     |                                 | Default: **dualstack**                |
   +---------------------+---------------------------------+---------------------------------------+
   | slow_start          | :ref:`dps_ss` object            | Specifies whether to enable slow      |
   |                     |                                 | start. After you enable slow start,   |
   |                     |                                 | new backend servers added to the      |
   |                     |                                 | backend server group are warmed up,   |
   |                     |                                 | and the number of requests they can   |
   |                     |                                 | receive increases linearly during the |
   |                     |                                 | configured slow start duration.       |
   |                     |                                 |                                       |
   |                     |                                 | This parameter can be used when the   |
   |                     |                                 | protocol of the backend server group  |
   |                     |                                 | is HTTP or HTTPS. An error will be    |
   |                     |                                 | returned if the protocol is not HTTP  |
   |                     |                                 | or HTTPS.                             |
   |                     |                                 |                                       |
   |                     |                                 | This parameter is unsupported. Please |
   |                     |                                 | do not use it.                        |
   +---------------------+---------------------------------+---------------------------------------+

.. _dps_lir:
.. table:: **Table 5** ListenerRef

   ========= ====== ==========================
   Parameter Type   Description
   ========= ====== ==========================
   id        String Specifies the listener ID.
   ========= ====== ==========================

.. _dps_lbr:
.. table:: **Table 6** LoadBalancerRef

   ========= ====== ===============================
   Parameter Type   Description
   ========= ====== ===============================
   id        String Specifies the load balancer ID.
   ========= ====== ===============================

.. _dps_mr:
.. table:: **Table 7** MemberRef

   ========= ====== ================================
   Parameter Type   Description
   ========= ====== ================================
   id        String Specifies the backend server ID.
   ========= ====== ================================

.. _dps_sp:
.. table:: **Table 8** SessionPersistence

   +---------------------+---------+---------------------------------------+
   | Parameter           | Type    | Description                           |
   +=====================+=========+=======================================+
   | cookie_name         | String  | Specifies the cookie name.            |
   |                     |         |                                       |
   |                     |         | This parameter will take effect only  |
   |                     |         | when **type** is set to               |
   |                     |         | **APP_COOKIE**.                       |
   |                     |         |                                       |
   |                     |         | The value can contain only letters,   |
   |                     |         | digits, hyphens (-), underscores (_), |
   |                     |         | and periods (.).                      |
   |                     |         |                                       |
   |                     |         | Minimum: **0**                        |
   |                     |         |                                       |
   |                     |         | Maximum: **1024**                     |
   +---------------------+---------+---------------------------------------+
   | type                | String  | Specifies the sticky session type.    |
   |                     |         | The value can be **SOURCE_IP**,       |
   |                     |         | **HTTP_COOKIE**, or **APP_COOKIE**.   |
   |                     |         |                                       |
   |                     |         | -  If the protocol of the backend     |
   |                     |         |    server group is TCP or UDP, only   |
   |                     |         |    **SOURCE_IP** takes effect.        |
   |                     |         |                                       |
   |                     |         | -  For dedicated load balancers, if   |
   |                     |         |    the protocol of the backend server |
   |                     |         |    group is HTTP or HTTPS, the value  |
   |                     |         |    can only be **HTTP_COOKIE**.       |
   |                     |         |                                       |
   |                     |         | -  For shared load balancers, if the  |
   |                     |         |    protocol of the backend server     |
   |                     |         |    group is HTTP or HTTPS, the value  |
   |                     |         |    can be **HTTP_COOKIE** or          |
   |                     |         |    **APP_COOKIE**.                    |
   +---------------------+---------+---------------------------------------+
   | persistence_timeout | Integer | Specifies the stickiness duration, in |
   |                     |         | minutes. This parameter will not take |
   |                     |         | effect when **type** is set to        |
   |                     |         | **APP_COOKIE**.                       |
   |                     |         |                                       |
   |                     |         | -  If the protocol of the backend     |
   |                     |         |    server group is TCP or UDP, the    |
   |                     |         |    value ranges from **1** to **60**, |
   |                     |         |    and the default value is **1**.    |
   |                     |         |                                       |
   |                     |         | -  If the protocol of the backend     |
   |                     |         |    server group is HTTP or HTTPS, the |
   |                     |         |    value ranges from **1** to         |
   |                     |         |    **1440**, and the default value is |
   |                     |         |    **1440**.                          |
   +---------------------+---------+---------------------------------------+

.. _dps_ss:
.. table:: **Table 9** SlowStart

   +-----------+---------+---------------------------------------+
   | Parameter | Type    | Description                           |
   +===========+=========+=======================================+
   | enable    | Boolean | Specifies whether to enable slow      |
   |           |         | start.                                |
   |           |         |                                       |
   |           |         | **true** indicates that this function |
   |           |         | is enabled, and **false** indicates   |
   |           |         | this function is disabled.            |
   |           |         |                                       |
   |           |         | Default: **false**                    |
   +-----------+---------+---------------------------------------+
   | duration  | Integer | Specifies the slow start duration, in |
   |           |         | seconds.                              |
   |           |         |                                       |
   |           |         | The value ranges from **30** to       |
   |           |         | **1200**, and the default value is    |
   |           |         | **30**.                               |
   |           |         |                                       |
   |           |         | Minimum: **30**                       |
   |           |         |                                       |
   |           |         | Maximum: **1200**                     |
   |           |         |                                       |
   |           |         | Default: **30**                       |
   +-----------+---------+---------------------------------------+

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   GET

   https://{elb_endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/pools/36ce7086-a496-4666-9064-5ba0e6840c75

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 200**

Successful request.

.. code::

   {
     "pool" : {
       "lb_algorithm" : "LEAST_CONNECTIONS",
       "protocol" : "TCP",
       "description" : "My pool",
       "admin_state_up" : true,
       "loadbalancers" : [ {
         "id" : "098b2f68-af1c-41a9-8efd-69958722af62"
       } ],
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "session_persistence" : "",
       "healthmonitor_id" : "",
       "listeners" : [ {
         "id" : "0b11747a-b139-492f-9692-2df0b1c87193"
       }, {
         "id" : "61942790-2367-482a-8b0e-93840ea2a1c6"
       }, {
         "id" : "fd8f954c-f0f8-4d39-bb1d-41637cd6b1be"
       } ],
       "members" : [ ],
       "id" : "36ce7086-a496-4666-9064-5ba0e6840c75",
       "name" : "My pool.",
       "ip_version" : "dualstack"
     },
     "request_id" : "c1a60da2-1ec7-4a1c-b4cc-73e1a57b368e"
   }

Status Codes
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
200         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Updating a Backend Server Group
===============================

Function
^^^^^^^^

This API is used to update a backend server group.

Constraints
^^^^^^^^^^^

The backend server group can be updated only when the provisioning status of
the associated load balancer is **ACTIVE**.

URI
^^^

PUT /v3/{project_id}/elb/pools/{pool_id}

.. table:: **Table 1** Path parameters

   ========== ========= ====== ======================================
   Parameter  Mandatory Type   Description
   ========== ========= ====== ======================================
   pool_id    Yes       String Specifies the backend server group ID.
   project_id Yes       String Specifies the project ID.
   ========== ========= ====== ======================================

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 2** Request body parameters

   +-----------+-----------+----------------------+-------------------------------------+
   | Parameter | Mandatory | Type                 | Description                         |
   +===========+===========+======================+=====================================+
   | pool      | Yes       | :ref:`dpu_po` object | Specifies the backend server group. |
   +-----------+-----------+----------------------+-------------------------------------+

.. _dpu_po:
.. table:: **Table 3** UpdatePoolOption

   +---------------------+-----------+-----------------------+-----------------------------+
   | Parameter           | Mandatory | Type                  | Description                 |
   +=====================+===========+=======================+=============================+
   | admin_state_up      | No        | Boolean               | Specifies the               |
   |                     |           |                       | administrative status of    |
   |                     |           |                       | the backend server group.   |
   |                     |           |                       | The value can only be       |
   |                     |           |                       | updated to **true**.        |
   |                     |           |                       |                             |
   |                     |           |                       | This parameter is           |
   |                     |           |                       | unsupported. Please do not  |
   |                     |           |                       | use it.                     |
   +---------------------+-----------+-----------------------+-----------------------------+
   | description         | No        | String                | Provides supplementary      |
   |                     |           |                       | information about the       |
   |                     |           |                       | backend server group.       |
   |                     |           |                       |                             |
   |                     |           |                       | Minimum: **0**              |
   |                     |           |                       |                             |
   |                     |           |                       | Maximum: **255**            |
   +---------------------+-----------+-----------------------+-----------------------------+
   | lb_algorithm        | No        | String                | Specifies the load          |
   |                     |           |                       | balancing algorithm used by |
   |                     |           |                       | the load balancer to route  |
   |                     |           |                       | requests to backend         |
   |                     |           |                       | servers.                    |
   |                     |           |                       |                             |
   |                     |           |                       | The value can be one of the |
   |                     |           |                       | following:                  |
   |                     |           |                       |                             |
   |                     |           |                       | -  **ROUND_ROBIN**:         |
   |                     |           |                       |    weighted round robin     |
   |                     |           |                       |                             |
   |                     |           |                       | -  **LEAST_CONNECTIONS**:   |
   |                     |           |                       |    weighted least           |
   |                     |           |                       |    connections              |
   |                     |           |                       |                             |
   |                     |           |                       | -  **SOURCE_IP**: source IP |
   |                     |           |                       |    hash                     |
   |                     |           |                       |                             |
   |                     |           |                       | When the value is           |
   |                     |           |                       | **SOURCE_IP**, the weights  |
   |                     |           |                       | of backend servers are      |
   |                     |           |                       | invalid.                    |
   +---------------------+-----------+-----------------------+-----------------------------+
   | name                | No        | String                | Specifies the backend       |
   |                     |           |                       | server group name.          |
   |                     |           |                       |                             |
   |                     |           |                       | Minimum: **0**              |
   |                     |           |                       |                             |
   |                     |           |                       | Maximum: **255**            |
   +---------------------+-----------+-----------------------+-----------------------------+
   | session_persistence | No        | :ref:`dpu_spo` object | Specifies whether to enable |
   |                     |           |                       | sticky sessions.            |
   +---------------------+-----------+-----------------------+-----------------------------+
   | slow_start          | No        | :ref:`dpu_sso` object | Specifies whether to enable |
   |                     |           |                       | slow start. After you       |
   |                     |           |                       | enable slow start, new      |
   |                     |           |                       | backend servers added to    |
   |                     |           |                       | the backend server group    |
   |                     |           |                       | are warmed up, and the      |
   |                     |           |                       | number of requests they can |
   |                     |           |                       | receive increases linearly  |
   |                     |           |                       | during the configured slow  |
   |                     |           |                       | start duration.             |
   |                     |           |                       |                             |
   |                     |           |                       | This parameter can be used  |
   |                     |           |                       | when the protocol of the    |
   |                     |           |                       | backend server group is     |
   |                     |           |                       | HTTP or HTTPS. An error     |
   |                     |           |                       | will be returned if the     |
   |                     |           |                       | protocol is not HTTP or     |
   |                     |           |                       | HTTPS.                      |
   |                     |           |                       |                             |
   |                     |           |                       | This parameter is           |
   |                     |           |                       | unsupported. Please do not  |
   |                     |           |                       | use it.                     |
   +---------------------+-----------+-----------------------+-----------------------------+

.. _dpu_spo:
.. table:: **Table 4** UpdatePoolSessionPersistenceOption

   +---------------------+-----------+---------+-----------------------------+
   | Parameter           | Mandatory | Type    | Description                 |
   +=====================+===========+=========+=============================+
   | cookie_name         | No        | String  | Specifies the cookie name.  |
   |                     |           |         |                             |
   |                     |           |         | This parameter will take    |
   |                     |           |         | effect only when **type**   |
   |                     |           |         | is set to **APP_COOKIE**.   |
   |                     |           |         | Otherwise, an error will be |
   |                     |           |         | returned.                   |
   |                     |           |         |                             |
   |                     |           |         | The value can contain only  |
   |                     |           |         | letters, digits, hyphens    |
   |                     |           |         | (-), underscores (_), and   |
   |                     |           |         | periods (.).                |
   |                     |           |         |                             |
   |                     |           |         | Minimum: **0**              |
   |                     |           |         |                             |
   |                     |           |         | Maximum: **1024**           |
   +---------------------+-----------+---------+-----------------------------+
   | type                | Yes       | String  | Specifies the sticky        |
   |                     |           |         | session type. The value can |
   |                     |           |         | be **SOURCE_IP**,           |
   |                     |           |         | **HTTP_COOKIE**, or         |
   |                     |           |         | **APP_COOKIE**.             |
   |                     |           |         |                             |
   |                     |           |         | -  If the protocol of the   |
   |                     |           |         |    backend server group is  |
   |                     |           |         |    TCP or UDP, only         |
   |                     |           |         |    **SOURCE_IP** takes      |
   |                     |           |         |    effect.                  |
   |                     |           |         |                             |
   |                     |           |         | -  For dedicated load       |
   |                     |           |         |    balancers, if the        |
   |                     |           |         |    protocol of the backend  |
   |                     |           |         |    server group is HTTP or  |
   |                     |           |         |    HTTPS, the value can     |
   |                     |           |         |    only be **HTTP_COOKIE**. |
   |                     |           |         |                             |
   |                     |           |         | -  For shared load          |
   |                     |           |         |    balancers, if the        |
   |                     |           |         |    protocol of the backend  |
   |                     |           |         |    server group is HTTP or  |
   |                     |           |         |    HTTPS, the value can be  |
   |                     |           |         |    **HTTP_COOKIE** or       |
   |                     |           |         |    **APP_COOKIE**.          |
   +---------------------+-----------+---------+-----------------------------+
   | persistence_timeout | No        | Integer | Specifies the stickiness    |
   |                     |           |         | duration, in minutes.       |
   |                     |           |         |                             |
   |                     |           |         | This parameter will not     |
   |                     |           |         | take effect when **type**   |
   |                     |           |         | is set to **APP_COOKIE**.   |
   |                     |           |         |                             |
   |                     |           |         | -  If the protocol of the   |
   |                     |           |         |    backend server group is  |
   |                     |           |         |    TCP or UDP, the value    |
   |                     |           |         |    ranges from **1** to     |
   |                     |           |         |    **60**, and the default  |
   |                     |           |         |    value is **1**.          |
   |                     |           |         |                             |
   |                     |           |         | -  If the protocol of the   |
   |                     |           |         |    backend server group is  |
   |                     |           |         |    HTTP or HTTPS, the value |
   |                     |           |         |    ranges from **1** to     |
   |                     |           |         |    **1440**, and the        |
   |                     |           |         |    default value is         |
   |                     |           |         |    **1440**.                |
   +---------------------+-----------+---------+-----------------------------+

.. _dpu_sso:
.. table:: **Table 5** UpdatePoolSlowStartOption

   +-----------+-----------+---------+-----------------------------+
   | Parameter | Mandatory | Type    | Description                 |
   +===========+===========+=========+=============================+
   | enable    | Yes       | Boolean | Specifies whether slow      |
   |           |           |         | start is enabled.           |
   |           |           |         |                             |
   |           |           |         | **true** indicates that     |
   |           |           |         | slow start is enabled, and  |
   |           |           |         | **false** indicates slow    |
   |           |           |         | start is disabled.          |
   |           |           |         |                             |
   |           |           |         | Default: **false**          |
   +-----------+-----------+---------+-----------------------------+
   | duration  | Yes       | Integer | Specifies the slow start    |
   |           |           |         | duration, in seconds.       |
   |           |           |         |                             |
   |           |           |         | The value ranges from       |
   |           |           |         | **30** to **1200**, and the |
   |           |           |         | default value is **30**.    |
   |           |           |         |                             |
   |           |           |         | Minimum: **30**             |
   |           |           |         |                             |
   |           |           |         | Maximum: **1200**           |
   |           |           |         |                             |
   |           |           |         | Default: **30**             |
   +-----------+-----------+---------+-----------------------------+

Response Parameters
^^^^^^^^^^^^^^^^^^^

**Status code: 200**

.. table:: **Table 6** Response body parameters

   ========== =================== ===============================================================
   Parameter  Type                Description
   ========== =================== ===============================================================
   request_id String              Specifies the request ID. The value is automatically generated.
   pool       :ref:`dpu_p` object Specifies the backend server group.
   ========== =================== ===============================================================

.. _dpu_p:
.. table:: **Table 7** Pool

   +---------------------+---------------------------------+---------------------------------------+
   | Parameter           | Type                            | Description                           |
   +=====================+=================================+=======================================+
   | admin_state_up      | Boolean                         | Specifies the administrative status   |
   |                     |                                 | of the backend server group. The      |
   |                     |                                 | value can only be updated to          |
   |                     |                                 | **true**.                             |
   |                     |                                 |                                       |
   |                     |                                 | This parameter is unsupported. Please |
   |                     |                                 | do not use it.                        |
   |                     |                                 |                                       |
   |                     |                                 | Default: **true**                     |
   +---------------------+---------------------------------+---------------------------------------+
   | description         | String                          | Provides supplementary information    |
   |                     |                                 | about the backend server group.       |
   +---------------------+---------------------------------+---------------------------------------+
   | healthmonitor_id    | String                          | Specifies the ID of the health check  |
   |                     |                                 | configured for the backend server     |
   |                     |                                 | group.                                |
   +---------------------+---------------------------------+---------------------------------------+
   | id                  | String                          | Specifies the backend server group    |
   |                     |                                 | ID.                                   |
   +---------------------+---------------------------------+---------------------------------------+
   | lb_algorithm        | String                          | Specifies the load balancing          |
   |                     |                                 | algorithm used by the load balancer   |
   |                     |                                 | to route requests to backend servers  |
   |                     |                                 | in the backend server group.          |
   |                     |                                 |                                       |
   |                     |                                 | The value can be **ROUND_ROBIN**      |
   |                     |                                 | (weighted round robin),               |
   |                     |                                 | **LEAST_CONNECTIONS** (weighted least |
   |                     |                                 | connections), or **SOURCE_IP**        |
   |                     |                                 | (source IP hash).                     |
   |                     |                                 |                                       |
   |                     |                                 | When the value is **SOURCE_IP**, the  |
   |                     |                                 | **weight** parameter is invalid.      |
   +---------------------+---------------------------------+---------------------------------------+
   | listeners           | Array of :ref:`dpu_lir` objects | Lists the listeners associated with   |
   |                     |                                 | the backend server group.             |
   +---------------------+---------------------------------+---------------------------------------+
   | loadbalancers       | Array of :ref:`dpu_lbr` objects | Lists the IDs of load balancers       |
   |                     |                                 | associated with the backend server    |
   |                     |                                 | group.                                |
   |                     |                                 |                                       |
   |                     |                                 | If only **listener_id** is specified  |
   |                     |                                 | during the creation of the backend    |
   |                     |                                 | server group, the ID of the           |
   |                     |                                 | **loadbalancers** parameter in the    |
   |                     |                                 | response is the ID of the load        |
   |                     |                                 | balancer to which the listener is     |
   |                     |                                 | added.                                |
   +---------------------+---------------------------------+---------------------------------------+
   | members             | Array of :ref:`dpu_mr` objects  | Lists the backend servers in the      |
   |                     |                                 | backend server group.                 |
   +---------------------+---------------------------------+---------------------------------------+
   | name                | String                          | Specifies the backend server group    |
   |                     |                                 | name.                                 |
   +---------------------+---------------------------------+---------------------------------------+
   | project_id          | String                          | Specifies the project ID.             |
   +---------------------+---------------------------------+---------------------------------------+
   | protocol            | String                          | Specifies the protocol used by the    |
   |                     |                                 | backend server group to receive       |
   |                     |                                 | requests. The protocol can be TCP,    |
   |                     |                                 | UDP, or HTTP.                         |
   |                     |                                 |                                       |
   |                     |                                 | -  For UDP listeners, the protocol of |
   |                     |                                 |    the backend server group must be   |
   |                     |                                 |    UDP.                               |
   |                     |                                 |                                       |
   |                     |                                 | -  For TCP listeners, the protocol of |
   |                     |                                 |    the backend server group must be   |
   |                     |                                 |    TCP.                               |
   |                     |                                 |                                       |
   |                     |                                 | -  For HTTP or HTTPS listeners, the   |
   |                     |                                 |    protocol of the backend server     |
   |                     |                                 |    group must be HTTP.                |
   +---------------------+---------------------------------+---------------------------------------+
   | session_persistence | :ref:`dpu_sp` object            | Specifies the sticky session.         |
   +---------------------+---------------------------------+---------------------------------------+
   | ip_version          | String                          | Specifies the IP version supported by |
   |                     |                                 | the backend server group.             |
   |                     |                                 |                                       |
   |                     |                                 | -  Shared load balancers: The default |
   |                     |                                 |    value is **v4**.                   |
   |                     |                                 |                                       |
   |                     |                                 | -  Dedicated load balancers: The      |
   |                     |                                 |    value can be **dualstack**,        |
   |                     |                                 |    **v4**, or **v6**.                 |
   |                     |                                 |                                       |
   |                     |                                 | When the protocol of the backend      |
   |                     |                                 | server group is TCP or UDP,           |
   |                     |                                 | **ip_version** is set to              |
   |                     |                                 | **dualstack**, indicating that both   |
   |                     |                                 | IPv4 and IPv6 are supported.          |
   |                     |                                 |                                       |
   |                     |                                 | When the protocol of the backend      |
   |                     |                                 | server group is HTTP, **ip_version**  |
   |                     |                                 | is set to **v4**.                     |
   |                     |                                 |                                       |
   |                     |                                 | IPv6 is unsupported. Only **v4** is   |
   |                     |                                 | returned.                             |
   |                     |                                 |                                       |
   |                     |                                 | Default: **dualstack**                |
   +---------------------+---------------------------------+---------------------------------------+
   | slow_start          | :ref:`dpu_ss` object            | Specifies whether to enable slow      |
   |                     |                                 | start. After you enable slow start,   |
   |                     |                                 | new backend servers added to the      |
   |                     |                                 | backend server group are warmed up,   |
   |                     |                                 | and the number of requests they can   |
   |                     |                                 | receive increases linearly during the |
   |                     |                                 | configured slow start duration.       |
   |                     |                                 |                                       |
   |                     |                                 | This parameter can be used when the   |
   |                     |                                 | protocol of the backend server group  |
   |                     |                                 | is HTTP or HTTPS. An error will be    |
   |                     |                                 | returned if the protocol is not HTTP  |
   |                     |                                 | or HTTPS.                             |
   |                     |                                 |                                       |
   |                     |                                 | This parameter is unsupported. Please |
   |                     |                                 | do not use it.                        |
   +---------------------+---------------------------------+---------------------------------------+

.. _dpu_lir:
.. table:: **Table 8** ListenerRef

   ========= ====== ==========================
   Parameter Type   Description
   ========= ====== ==========================
   id        String Specifies the listener ID.
   ========= ====== ==========================

.. _dpu_lbr:
.. table:: **Table 9** LoadBalancerRef

   ========= ====== ===============================
   Parameter Type   Description
   ========= ====== ===============================
   id        String Specifies the load balancer ID.
   ========= ====== ===============================

.. _dpu_mr:
.. table:: **Table 10** MemberRef

   ========= ====== ================================
   Parameter Type   Description
   ========= ====== ================================
   id        String Specifies the backend server ID.
   ========= ====== ================================

.. _dpu_sp:
.. table:: **Table 11** SessionPersistence

   +---------------------+---------+---------------------------------------+
   | Parameter           | Type    | Description                           |
   +=====================+=========+=======================================+
   | cookie_name         | String  | Specifies the cookie name.            |
   |                     |         |                                       |
   |                     |         | This parameter will take effect only  |
   |                     |         | when **type** is set to               |
   |                     |         | **APP_COOKIE**.                       |
   |                     |         |                                       |
   |                     |         | The value can contain only letters,   |
   |                     |         | digits, hyphens (-), underscores (_), |
   |                     |         | and periods (.).                      |
   |                     |         |                                       |
   |                     |         | Minimum: **0**                        |
   |                     |         |                                       |
   |                     |         | Maximum: **1024**                     |
   +---------------------+---------+---------------------------------------+
   | type                | String  | Specifies the sticky session type.    |
   |                     |         | The value can be **SOURCE_IP**,       |
   |                     |         | **HTTP_COOKIE**, or **APP_COOKIE**.   |
   |                     |         |                                       |
   |                     |         | -  If the protocol of the backend     |
   |                     |         |    server group is TCP or UDP, only   |
   |                     |         |    **SOURCE_IP** takes effect.        |
   |                     |         |                                       |
   |                     |         | -  For dedicated load balancers, if   |
   |                     |         |    the protocol of the backend server |
   |                     |         |    group is HTTP or HTTPS, the value  |
   |                     |         |    can only be **HTTP_COOKIE**.       |
   |                     |         |                                       |
   |                     |         | -  For shared load balancers, if the  |
   |                     |         |    protocol of the backend server     |
   |                     |         |    group is HTTP or HTTPS, the value  |
   |                     |         |    can be **HTTP_COOKIE** or          |
   |                     |         |    **APP_COOKIE**.                    |
   +---------------------+---------+---------------------------------------+
   | persistence_timeout | Integer | Specifies the stickiness duration, in |
   |                     |         | minutes. This parameter will not take |
   |                     |         | effect when **type** is set to        |
   |                     |         | **APP_COOKIE**.                       |
   |                     |         |                                       |
   |                     |         | -  If the protocol of the backend     |
   |                     |         |    server group is TCP or UDP, the    |
   |                     |         |    value ranges from **1** to **60**, |
   |                     |         |    and the default value is **1**.    |
   |                     |         |                                       |
   |                     |         | -  If the protocol of the backend     |
   |                     |         |    server group is HTTP or HTTPS, the |
   |                     |         |    value ranges from **1** to         |
   |                     |         |    **1440**, and the default value is |
   |                     |         |    **1440**.                          |
   +---------------------+---------+---------------------------------------+

.. _dpu_ss:
.. table:: **Table 12** SlowStart

   +-----------+---------+---------------------------------------+
   | Parameter | Type    | Description                           |
   +===========+=========+=======================================+
   | enable    | Boolean | Specifies whether to enable slow      |
   |           |         | start.                                |
   |           |         |                                       |
   |           |         | **true** indicates that this function |
   |           |         | is enabled, and **false** indicates   |
   |           |         | this function is disabled.            |
   |           |         |                                       |
   |           |         | Default: **false**                    |
   +-----------+---------+---------------------------------------+
   | duration  | Integer | Specifies the slow start duration, in |
   |           |         | seconds.                              |
   |           |         |                                       |
   |           |         | The value ranges from **30** to       |
   |           |         | **1200**, and the default value is    |
   |           |         | **30**.                               |
   |           |         |                                       |
   |           |         | Minimum: **30**                       |
   |           |         |                                       |
   |           |         | Maximum: **1200**                     |
   |           |         |                                       |
   |           |         | Default: **30**                       |
   +-----------+---------+---------------------------------------+

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   PUT

   https://{elb_endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/pools/36ce7086-a496-4666-9064-5ba0e6840c75

   {
     "pool" : {
       "name" : "My pool.",
       "description" : "My pool update",
       "lb_algorithm" : "LEAST_CONNECTIONS"
     }
   }

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 200**

Successful request.

.. code::

   {
     "pool" : {
       "lb_algorithm" : "LEAST_CONNECTIONS",
       "protocol" : "TCP",
       "description" : "My pool update",
       "admin_state_up" : true,
       "loadbalancers" : [ {
         "id" : "098b2f68-af1c-41a9-8efd-69958722af62"
       } ],
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "listeners" : [ {
         "id" : "0b11747a-b139-492f-9692-2df0b1c87193"
       }, {
         "id" : "61942790-2367-482a-8b0e-93840ea2a1c6"
       }, {
         "id" : "fd8f954c-f0f8-4d39-bb1d-41637cd6b1be"
       } ],
       "members" : [ ],
       "id" : "36ce7086-a496-4666-9064-5ba0e6840c75",
       "name" : "My pool.",
       "ip_version" : "dualstack"
     },
     "request_id" : "8f40128b-c72b-4b64-986a-f7e2c633d75f"
   }

Status Codes
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
200         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Deleting a Backend Server Group
===============================

Function
^^^^^^^^

This API is used to delete a backend server group.

Constraints
^^^^^^^^^^^

A backend server group can be deleted only after all servers are removed from
the group, the health check configured for the group is deleted, and the group
has no forwarding policies associated.

URI
^^^

DELETE /v3/{project_id}/elb/pools/{pool_id}

.. table:: **Table 1** Path parameters

   ========== ========= ====== =============================================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =============================================
   project_id Yes       String Specifies the project ID.
   pool_id    Yes       String Specifies the ID of the backend server group.
   ========== ========= ====== =============================================

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 2** Request header parameters

   ============ ========= ====== ================================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ================================================
   X-Auth-Token Yes       String Specifies the token used for IAM authentication.
   ============ ========= ====== ================================================

Response Parameters
^^^^^^^^^^^^^^^^^^^

None

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   DELETE

   https://{elb_endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/pools/36ce7086-a496-4666-9064-5ba0e6840c75

Example Responses
^^^^^^^^^^^^^^^^^

None

Status Codes
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
204         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.
