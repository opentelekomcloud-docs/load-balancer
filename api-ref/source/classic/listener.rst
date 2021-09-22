Listener
--------

1. .. rubric:: Adding a Listener
      :name: adding-a-listener

   #. Function

This API is used to add a listener to a load balancer.

2. URI

POST /v1.0/{project_id}/elbaas/listeners

1. Parameter description

+----------------------+-----------+---------+---------------------------+
| Parameter            | Mandatory | Type    | Description               |
+======================+===========+=========+===========================+
| project_id           | Yes       | String  | Specifies the project ID. |
+----------------------+-----------+---------+---------------------------+
| name                 | Yes       | String  | -  Specifies the listener |
|                      |           |         |    name.                  |
|                      |           |         |                           |
|                      |           |         | -  The value can contain  |
|                      |           |         |    1 to 64 characters     |
|                      |           |         |    that consist of        |
|                      |           |         |    letters, digits,       |
|                      |           |         |    underscores (_), and   |
|                      |           |         |    hyphens (-).           |
+----------------------+-----------+---------+---------------------------+
| description          | No        | String  | -  Provides supplementary |
|                      |           |         |    information about the  |
|                      |           |         |    listener.              |
|                      |           |         |                           |
|                      |           |         | -  The value contains 0   |
|                      |           |         |    to 128 characters and  |
|                      |           |         |    cannot contain angle   |
|                      |           |         |    brackets (< and >).    |
+----------------------+-----------+---------+---------------------------+
| loadbalancer_id      | Yes       | String  | Specifies the load        |
|                      |           |         | balancer ID.              |
+----------------------+-----------+---------+---------------------------+
| protocol             | Yes       | String  | -  Specifies the protocol |
|                      |           |         |    used by the listener.  |
|                      |           |         |                           |
|                      |           |         | -  The value can be       |
|                      |           |         |    **HTTP**, **TCP**,     |
|                      |           |         |    **HTTPS**, **SSL**, or |
|                      |           |         |    **UDP**.               |
|                      |           |         |                           |
|                      |           |         | -  A UDP listener cannot  |
|                      |           |         |    be added to a private  |
|                      |           |         |    network load balancer. |
+----------------------+-----------+---------+---------------------------+
| port                 | Yes       | Integer | -  Specifies the port     |
|                      |           |         |    used by the listener.  |
|                      |           |         |                           |
|                      |           |         | -  The port number ranges |
|                      |           |         |    from 1 to 65535.       |
+----------------------+-----------+---------+---------------------------+
| backend_protocol     | Yes       | String  | -  Specifies the backend  |
|                      |           |         |    ECS protocol.          |
|                      |           |         |                           |
|                      |           |         | If **protocol** is set to |
|                      |           |         | **UDP**, the value of     |
|                      |           |         | this parameter can only   |
|                      |           |         | be **UDP**.               |
|                      |           |         |                           |
|                      |           |         | If **protocol** is set to |
|                      |           |         | **SSL**, the value of     |
|                      |           |         | this parameter can only   |
|                      |           |         | be **TCP**.               |
|                      |           |         |                           |
|                      |           |         | -  The value can be       |
|                      |           |         |    **HTTP**, **TCP**, or  |
|                      |           |         |    **UDP**.               |
+----------------------+-----------+---------+---------------------------+
| backend_port         | Yes       | Integer | -  Specifies the port     |
|                      |           |         |    used by backend ECSs.  |
|                      |           |         |                           |
|                      |           |         | -  The port number ranges |
|                      |           |         |    from 1 to 65535.       |
+----------------------+-----------+---------+---------------------------+
| lb_algorithm         | Yes       | String  | -  Specifies the load     |
|                      |           |         |    balancing algorithm.   |
|                      |           |         |                           |
|                      |           |         | -  The value can be       |
|                      |           |         |    **roundrobin**,        |
|                      |           |         |    **leastconn**, or      |
|                      |           |         |    **source**.            |
+----------------------+-----------+---------+---------------------------+
| session_sticky       | No        | Boolean | -  Specifies whether to   |
|                      |           |         |    enable the sticky      |
|                      |           |         |    session feature.       |
|                      |           |         |                           |
|                      |           |         | -  The value can be       |
|                      |           |         |    **true** or **false**. |
|                      |           |         |    The feature is enabled |
|                      |           |         |    when the value is      |
|                      |           |         |    **true**.              |
|                      |           |         |                           |
|                      |           |         | -  If **protocol** is set |
|                      |           |         |    to **SSL**, the sticky |
|                      |           |         |    session feature is not |
|                      |           |         |    supported and the      |
|                      |           |         |    parameter is invalid.  |
|                      |           |         |                           |
|                      |           |         | -  If **protocol** is set |
|                      |           |         |    to **HTTP**,           |
|                      |           |         |    **HTTPS**, or **TCP**  |
|                      |           |         |    and **lb_algorithm**   |
|                      |           |         |    is not **roundrobin**, |
|                      |           |         |    the value of this      |
|                      |           |         |    parameter can only be  |
|                      |           |         |    **false**.             |
+----------------------+-----------+---------+---------------------------+
| sticky_session_type  | No        | String  | Specifies where the       |
|                      |           |         | cookie is from. The only  |
|                      |           |         | value is **insert**,      |
|                      |           |         | indicating that the       |
|                      |           |         | cookie is inserted by the |
|                      |           |         | load balancer.            |
|                      |           |         |                           |
|                      |           |         | -  This parameter is      |
|                      |           |         |    valid when             |
|                      |           |         |    **protocol** is set to |
|                      |           |         |    **HTTP** and           |
|                      |           |         |    **session_sticky** to  |
|                      |           |         |    **true**.              |
|                      |           |         |                           |
|                      |           |         | -  This parameter is      |
|                      |           |         |    invalid when           |
|                      |           |         |    **protocol** is set to |
|                      |           |         |    **TCP**, **SSL**, or   |
|                      |           |         |    **UDP**, which means   |
|                      |           |         |    that the parameter is  |
|                      |           |         |    unavailable or its     |
|                      |           |         |    value is set to        |
|                      |           |         |    **null**.              |
+----------------------+-----------+---------+---------------------------+
| cookie_timeout       | No        | Integer | -  Specifies the cookie   |
|                      |           |         |    timeout duration. This |
|                      |           |         |    parameter is valid     |
|                      |           |         |    when **protocol** is   |
|                      |           |         |    set to **HTTP**,       |
|                      |           |         |    **session_sticky** to  |
|                      |           |         |    **true**, and          |
|                      |           |         |                           |
|                      |           |         |   **sticky_session_type** |
|                      |           |         |    to **insert**. This    |
|                      |           |         |    parameter is invalid   |
|                      |           |         |    when **protocol** is   |
|                      |           |         |    set to **TCP**,        |
|                      |           |         |    **SSL**, or **UDP**.   |
|                      |           |         |                           |
|                      |           |         | -  The value ranges from  |
|                      |           |         |    **1** to **1440**.     |
+----------------------+-----------+---------+---------------------------+
| tcp_timeout          | No        | Integer | -  Specifies the TCP      |
|                      |           |         |    session timeout        |
|                      |           |         |    duration. This         |
|                      |           |         |    parameter is valid     |
|                      |           |         |    when **protocol** is   |
|                      |           |         |    set to **TCP**.        |
|                      |           |         |                           |
|                      |           |         | -  The value ranges from  |
|                      |           |         |    **1** to **1440**.     |
+----------------------+-----------+---------+---------------------------+
| tcp_draining         | No        | Boolean | -  Specifies whether to   |
|                      |           |         |    maintain TCP           |
|                      |           |         |    connections to a       |
|                      |           |         |    backend ECS that has   |
|                      |           |         |    been removed. This     |
|                      |           |         |    parameter is valid     |
|                      |           |         |    when **protocol** is   |
|                      |           |         |    set to **TCP**.        |
|                      |           |         |                           |
|                      |           |         | -  The value can be       |
|                      |           |         |    **true** or **false**. |
+----------------------+-----------+---------+---------------------------+
| tcp_draining_timeout | No        | Integer | -  Specifies the timeout  |
|                      |           |         |    duration for           |
|                      |           |         |    maintaining TCP        |
|                      |           |         |    connections to a       |
|                      |           |         |    backend ECS that has   |
|                      |           |         |    been removed in the    |
|                      |           |         |    unit of minute.        |
|                      |           |         |                           |
|                      |           |         | This parameter is valid   |
|                      |           |         | when **protocol** is set  |
|                      |           |         | to **TCP** and            |
|                      |           |         | **tcp_draining** to       |
|                      |           |         | **true**.                 |
|                      |           |         |                           |
|                      |           |         | -  The value ranges from  |
|                      |           |         |    **0** to **60**.       |
+----------------------+-----------+---------+---------------------------+
| certificate_id       | No        | String  | -  Specifies the          |
|                      |           |         |    certificate ID. This   |
|                      |           |         |    parameter is mandatory |
|                      |           |         |    when **protocol** is   |
|                      |           |         |    set to **HTTPS** or    |
|                      |           |         |    **SSL**.               |
|                      |           |         |                           |
|                      |           |         | -  The ID can be obtained |
|                      |           |         |    from the certificate   |
|                      |           |         |    list.                  |
+----------------------+-----------+---------+---------------------------+
| certificates         | No        | String  | -  Lists the certificate  |
|                      |           |         |    IDs if **protocol** is |
|                      |           |         |    set to **HTTPS**.      |
|                      |           |         |                           |
|                      |           |         | -  This parameter is      |
|                      |           |         |    mandatory in the SNI   |
|                      |           |         |    scenario and is valid  |
|                      |           |         |    only when the load     |
|                      |           |         |    balancer is a public   |
|                      |           |         |    network load balancer. |
+----------------------+-----------+---------+---------------------------+
| udp_timeout          | No        | Integer | -  Specifies the UDP      |
|                      |           |         |    session timeout        |
|                      |           |         |    duration. This         |
|                      |           |         |    parameter is valid     |
|                      |           |         |    when **protocol** is   |
|                      |           |         |    set to **UDP**.        |
|                      |           |         |                           |
|                      |           |         | -  The value ranges from  |
|                      |           |         |    **1** to **1440**.     |
+----------------------+-----------+---------+---------------------------+
| ssl_protocols        | No        | String  | -  Specifies the          |
|                      |           |         |    supported SSL/TLS      |
|                      |           |         |    protocol version. This |
|                      |           |         |    parameter is available |
|                      |           |         |    only when **protocol** |
|                      |           |         |    is set to **HTTPS** or |
|                      |           |         |    **SSL**.               |
|                      |           |         |                           |
|                      |           |         | -  The value is           |
|                      |           |         |    **TLSv1.2** or         |
|                      |           |         |    **TLSv1.2 TLSv1.1      |
|                      |           |         |    TLSv1** and the        |
|                      |           |         |    default value is       |
|                      |           |         |    **TLSv1.2**.           |
+----------------------+-----------+---------+---------------------------+
| ssl_ciphers          | No        | String  | -  Specifies the cipher   |
|                      |           |         |    suites supported by a  |
|                      |           |         |    specific SSL/TLS       |
|                      |           |         |    protocol version. This |
|                      |           |         |    parameter is available |
|                      |           |         |    only when **protocol** |
|                      |           |         |    is set to **HTTPS** or |
|                      |           |         |    **SSL**.               |
|                      |           |         |                           |
|                      |           |         | -  The value is           |
|                      |           |         |    **Default**,           |
|                      |           |         |    **Extended**, or       |
|                      |           |         |    **Strict**.            |
|                      |           |         |                           |
|                      |           |         | The value of **Default**  |
|                      |           |         | is                        |
|                      |           |         | **ECDHE-                  |
|                      |           |         | RSA-AES256-GCM-SHA384:ECD |
|                      |           |         | HE-RSA-AES128-GCM-SHA256: |
|                      |           |         | ECDHE-RSA-AES256-SHA384:E |
|                      |           |         | CDHE-RSA-AES128-SHA256**. |
|                      |           |         |                           |
|                      |           |         | The value of **Extended** |
|                      |           |         | is                        |
|                      |           |         | **                        |
|                      |           |         | ECDHE-ECDSA-AES128-SHA256 |
|                      |           |         | :ECDHE-RSA-AES128-SHA256: |
|                      |           |         | AES128-SHA256:AES256-SHA2 |
|                      |           |         | 56:ECDHE-ECDSA-AES256-SHA |
|                      |           |         | 384:ECDHE-RSA-AES256-SHA3 |
|                      |           |         | 84:ECDHE-ECDSA-AES128-SHA |
|                      |           |         | :ECDHE-RSA-AES128-SHA:DHE |
|                      |           |         | -RSA-AES128-SHA:ECDHE-RSA |
|                      |           |         | -AES256-SHA:ECDHE-ECDSA-A |
|                      |           |         | ES256-SHA:AES128-SHA:AES2 |
|                      |           |         | 56-SHA:DHE-DSS-AES128-SHA |
|                      |           |         | :CAMELLIA128-SHA:EDH-RSA- |
|                      |           |         | DES-CBC3-SHA:DES-CBC3-SHA |
|                      |           |         | :ECDHE-RSA-RC4-SHA:RC4-SH |
|                      |           |         | A:DHE-RSA-AES256-SHA:DHE- |
|                      |           |         | DSS-AES256-SHA:DHE-RSA-CA |
|                      |           |         | MELLIA256-SHA:DHE-DSS-CAM |
|                      |           |         | ELLIA256-SHA:CAMELLIA256- |
|                      |           |         | SHA:EDH-DSS-DES-CBC3-SHA: |
|                      |           |         | DHE-RSA-CAMELLIA128-SHA:D |
|                      |           |         | HE-DSS-CAMELLIA128-SHA**. |
|                      |           |         |                           |
|                      |           |         | The value of **Strict**   |
|                      |           |         | is                        |
|                      |           |         | **ECDHE-RS                |
|                      |           |         | A-AES256-GCM-SHA384:ECDHE |
|                      |           |         | -RSA-AES128-GCM-SHA256**. |
|                      |           |         |                           |
|                      |           |         | The default value is      |
|                      |           |         | **Default**. The value    |
|                      |           |         | can only be set to        |
|                      |           |         | **Extended** if           |
|                      |           |         | **ssl_protocols** is set  |
|                      |           |         | to **TLSv1.2 TLSv1.1      |
|                      |           |         | TLSv1**.                  |
+----------------------+-----------+---------+---------------------------+

#. Request

-  Request parameters

None

-  Example request

| {
| "name": "listener1",
| "description": "",
| "loadbalancer_id": "0b07acf06d243925bc24a0ac7445267a",
| "protocol": "HTTP",
| "port": 88,
| "backend_protocol": "HTTP",
| "backend_port": 80,
| "lb_algorithm": "roundrobin",
| "session_sticky": true,
| "sticky_session_type": "insert",
| "cookie_timeout": 100,
| "tcp_draining": true,
| "tcp_draining_timeout": 5
| }

#. Response

-  Response parameters

   1. Parameter description

+----------------------+---------+-------------------------------+
| Parameter            | Type    | Description                   |
+======================+=========+===============================+
| update_time          | String  | Specifies the time when the   |
|                      |         | listener was updated.         |
+----------------------+---------+-------------------------------+
| backend_port         | Integer | Specifies the port used by    |
|                      |         | backend ECSs.                 |
+----------------------+---------+-------------------------------+
| id                   | String  | Specifies the listener ID.    |
+----------------------+---------+-------------------------------+
| backend_protocol     | String  | Specifies the protocol used   |
|                      |         | by backend ECSs.              |
+----------------------+---------+-------------------------------+
| sticky_session_type  | String  | Specifies where the cookie is |
|                      |         | from. The only value is       |
|                      |         | **insert**, indicating that   |
|                      |         | the cookie is inserted by the |
|                      |         | load balancer. This parameter |
|                      |         | is valid when **protocol** is |
|                      |         | set to **HTTP** and           |
|                      |         | **session_sticky** to         |
|                      |         | **true**.                     |
+----------------------+---------+-------------------------------+
| description          | String  | Provides supplementary        |
|                      |         | information about the         |
|                      |         | listener.                     |
+----------------------+---------+-------------------------------+
| loadbalancer_id      | String  | Specifies the load balancer   |
|                      |         | ID.                           |
+----------------------+---------+-------------------------------+
| create_time          | String  | Specifies the time when the   |
|                      |         | listener was created.         |
+----------------------+---------+-------------------------------+
| status               | String  | Specifies the listener        |
|                      |         | status. The value can be      |
|                      |         | **ACTIVE**,                   |
|                      |         | **PENDING_CREATE**, or        |
|                      |         | **ERROR**.                    |
+----------------------+---------+-------------------------------+
| protocol             | String  | Specifies the protocol used   |
|                      |         | for load balancing at Layer 4 |
|                      |         | or Layer 7.                   |
+----------------------+---------+-------------------------------+
| port                 | Integer | Specifies the port used by    |
|                      |         | the listener.                 |
+----------------------+---------+-------------------------------+
| cookie_timeout       | Integer | -  Specifies the cookie       |
|                      |         |    timeout duration in the    |
|                      |         |    unit of minute. This       |
|                      |         |    parameter is valid when    |
|                      |         |    **session_sticky** is set  |
|                      |         |    to **true** and            |
|                      |         |    **sticky_session_type** to |
|                      |         |    **insert**.                |
|                      |         |                               |
|                      |         | -  The value ranges from      |
|                      |         |    **1** to **1440**.         |
+----------------------+---------+-------------------------------+
| admin_state_up       | Boolean | -  Specifies the              |
|                      |         |    administrative status of   |
|                      |         |    the load balancer.         |
|                      |         |                               |
|                      |         | -  Two options are available: |
|                      |         |                               |
|                      |         | **false**: The load balancer  |
|                      |         | is disabled.                  |
|                      |         |                               |
|                      |         | **true**: The load balancer   |
|                      |         | is running properly.          |
+----------------------+---------+-------------------------------+
| session_sticky       | Boolean | Specifies whether to enable   |
|                      |         | the sticky session feature.   |
|                      |         | The feature is enabled when   |
|                      |         | the value is **true**.        |
+----------------------+---------+-------------------------------+
| lb_algorithm         | String  | Specifies the load balancing  |
|                      |         | algorithm.                    |
+----------------------+---------+-------------------------------+
| name                 | String  | Specifies the listener name.  |
+----------------------+---------+-------------------------------+
| tcp_draining         | Boolean | -  Specifies whether to       |
|                      |         |    maintain TCP connections   |
|                      |         |    to a backend ECS that has  |
|                      |         |    been removed. This         |
|                      |         |    parameter is valid when    |
|                      |         |    **protocol** is set to     |
|                      |         |    **TCP**.                   |
|                      |         |                               |
|                      |         | -  The value can be **true**  |
|                      |         |    or **false**.              |
+----------------------+---------+-------------------------------+
| tcp_draining_timeout | Integer | -  Specifies the timeout      |
|                      |         |    duration for maintaining   |
|                      |         |    TCP connections to a       |
|                      |         |    backend ECS that has been  |
|                      |         |    removed in the unit of     |
|                      |         |    minute.                    |
|                      |         |                               |
|                      |         | This parameter is valid when  |
|                      |         | **protocol** is set to        |
|                      |         | **TCP** and **tcp_draining**  |
|                      |         | to **true**.                  |
|                      |         |                               |
|                      |         | -  The value ranges from      |
|                      |         |    **0** to **60**.           |
+----------------------+---------+-------------------------------+
| ssl_protocols        | String  | -  Specifies the supported    |
|                      |         |    SSL/TLS protocol version.  |
|                      |         |                               |
|                      |         | -  This parameter is          |
|                      |         |    available only when        |
|                      |         |    **protocol** is set to     |
|                      |         |    **HTTPS** or **SSL**.      |
+----------------------+---------+-------------------------------+
| ssl_ciphers          | String  | -  Specifies the cipher suite |
|                      |         |    of an encryption protocol. |
|                      |         |                               |
|                      |         | -  This parameter is          |
|                      |         |    available only when        |
|                      |         |    **protocol** is set to     |
|                      |         |    **HTTPS** or **SSL**.      |
+----------------------+---------+-------------------------------+
| certificate_id       | String  | -  Specifies the default      |
|                      |         |    certificate ID.            |
|                      |         |                               |
|                      |         | -  This parameter is          |
|                      |         |    available only when        |
|                      |         |    **protocol** is set to     |
|                      |         |    **HTTPS** or **SSL**.      |
+----------------------+---------+-------------------------------+
| certificates         | String  | -  Lists the certificate IDs  |
|                      |         |    if **protocol** is set to  |
|                      |         |    **HTTPS**.                 |
|                      |         |                               |
|                      |         | -  This parameter is          |
|                      |         |    mandatory in the SNI       |
|                      |         |    scenario.                  |
+----------------------+---------+-------------------------------+

-  Example response

| {
| "update_time": "2015-09-15 07:41:17",
| "backend_port": 80,
| "tcp_draining": true,
| "id": "248425d7b97dc26920eb23720115e068",
| "backend_protocol": "HTTP",
| "sticky_session_type": "insert",
| "description": "",
| "loadbalancer_id": "0b07acf06d243925bc24a0ac7445267a",
| "create_time": "2015-09-15 07:41:17",
| "status": "ACTIVE",
| "protocol": "TCP",
| "port": 88,
| "cookie_timeout": 100,
| "admin_state_up": true,
| "session_sticky": true,
| "lb_algorithm": "roundrobin",
| "name": "listener1",
| "tcp_draining": true,
| "tcp_draining_timeout": 5
| }

#. Status Code

-  Normal

200

-  Error

+-------------+--------------------+--------------------------------+
| Status Code | Message            | Description                    |
+=============+====================+================================+
| 400         | badRequest         | Request error.                 |
+-------------+--------------------+--------------------------------+
| 401         | unauthorized       | Authentication failed.         |
+-------------+--------------------+--------------------------------+
| 403         | userDisabled       | You do not have the permission |
|             |                    | to perform the operation.      |
+-------------+--------------------+--------------------------------+
| 404         | Not Found          | The requested page does not    |
|             |                    | exist.                         |
+-------------+--------------------+--------------------------------+
| 500         | authFault          | System error.                  |
+-------------+--------------------+--------------------------------+
| 503         | serviceUnavailable | The service is unavailable.    |
+-------------+--------------------+--------------------------------+

Deleting a Listener
~~~~~~~~~~~~~~~~~~~

#. Function

This API is used to delete a listener.

2. URI

DELETE /v1.0/{project_id}/elbaas/listeners/{listener_id}

1. Parameter description

+-------------+-----------+--------+----------------------------+
| Parameter   | Mandatory | Type   | Description                |
+=============+===========+========+============================+
| project_id  | Yes       | String | Specifies the project ID.  |
+-------------+-----------+--------+----------------------------+
| listener_id | Yes       | String | Specifies the listener ID. |
+-------------+-----------+--------+----------------------------+

3. Request

-  Request parameters

None

-  Example request

None

#. Response

-  Response parameters

None

-  Example response

None

#. Status Code

-  Normal

204

-  Error

+-------------+--------------------+--------------------------------+
| Status Code | Message            | Description                    |
+=============+====================+================================+
| 400         | badRequest         | Request error.                 |
+-------------+--------------------+--------------------------------+
| 401         | unauthorized       | Authentication failed.         |
+-------------+--------------------+--------------------------------+
| 403         | userDisabled       | You do not have the permission |
|             |                    | to perform the operation.      |
+-------------+--------------------+--------------------------------+
| 404         | Not Found          | The requested page does not    |
|             |                    | exist.                         |
+-------------+--------------------+--------------------------------+
| 500         | authFault          | System error.                  |
+-------------+--------------------+--------------------------------+
| 503         | serviceUnavailable | The service is unavailable.    |
+-------------+--------------------+--------------------------------+

Modifying a Listener
~~~~~~~~~~~~~~~~~~~~

#. Function

This API is used to modify the listener information, including the
listener name, description, and status.

2. URI

PUT /v1.0/{project_id}/elbaas/listeners/{listener_id}

1. Parameter description

+----------------------+-----------+---------+-------------------------------------------+
| Parameter            | Mandatory | Type    | Description                               |
+======================+===========+=========+===========================================+
| project_id           | Yes       | String  | Specifies the project ID.                 |
+----------------------+-----------+---------+-------------------------------------------+
| listener_id          | Yes       | String  | Specifies the listener ID.                |
+----------------------+-----------+---------+-------------------------------------------+
| name                 | No        | String  | -  Specifies the listener name.           |
|                      |           |         |                                           |
|                      |           |         | -  The value can contain 1 to 64          |
|                      |           |         |    characters that consist of letters,    |
|                      |           |         |    digits, underscores (_), and hyphens   |
|                      |           |         |    (-).                                   |
+----------------------+-----------+---------+-------------------------------------------+
| description          | No        | String  | -  Provides supplementary information     |
|                      |           |         |    about the listener.                    |
|                      |           |         |                                           |
|                      |           |         | -  The value contains 0 to 128 characters |
|                      |           |         |    and cannot contain angle brackets (<   |
|                      |           |         |    and >).                                |
+----------------------+-----------+---------+-------------------------------------------+
| port                 | No        | Integer | -  Specifies the port used by the         |
|                      |           |         |    listener.                              |
|                      |           |         |                                           |
|                      |           |         | -  The port number ranges from 1 to       |
|                      |           |         |    65535.                                 |
+----------------------+-----------+---------+-------------------------------------------+
| backend_port         | No        | Integer | -  Specifies the port used by backend     |
|                      |           |         |    ECSs.                                  |
|                      |           |         |                                           |
|                      |           |         | -  The port number ranges from 1 to       |
|                      |           |         |    65535.                                 |
+----------------------+-----------+---------+-------------------------------------------+
| lb_algorithm         | No        | String  | -  Specifies the load balancing           |
|                      |           |         |    algorithm.                             |
|                      |           |         |                                           |
|                      |           |         | -  The value can be **roundrobin**,       |
|                      |           |         |    **leastconn**, or **source**.          |
+----------------------+-----------+---------+-------------------------------------------+
| tcp_timeout          | No        | Integer | -  Specifies the TCP session timeout      |
|                      |           |         |    duration. This parameter is valid when |
|                      |           |         |    **protocol** is set to **TCP**.        |
|                      |           |         |                                           |
|                      |           |         | -  The value ranges from **1** to         |
|                      |           |         |    **1440**.                              |
+----------------------+-----------+---------+-------------------------------------------+
| tcp_draining         | No        | Boolean | -  Specifies whether to maintain TCP      |
|                      |           |         |    connections to a backend ECS that has  |
|                      |           |         |    been removed. This parameter is valid  |
|                      |           |         |    when **protocol** is set to **TCP**.   |
|                      |           |         |                                           |
|                      |           |         | -  The value can be **true** or           |
|                      |           |         |    **false**.                             |
+----------------------+-----------+---------+-------------------------------------------+
| tcp_draining_timeout | No        | Integer | -  Specifies the timeout duration for     |
|                      |           |         |    maintaining TCP connections to a       |
|                      |           |         |    backend ECS that has been removed in   |
|                      |           |         |    the unit of minute.                    |
|                      |           |         |                                           |
|                      |           |         | This parameter is valid when **protocol** |
|                      |           |         | is set to **TCP** and **tcp_draining** to |
|                      |           |         | **true**.                                 |
|                      |           |         |                                           |
|                      |           |         | -  The value ranges from **0** to **60**. |
+----------------------+-----------+---------+-------------------------------------------+
| udp_timeout          | No        | Integer | -  Specifies the UDP session timeout      |
|                      |           |         |    duration. This parameter is valid when |
|                      |           |         |    **protocol** is set to **UDP**.        |
|                      |           |         |                                           |
|                      |           |         | -  The value ranges from **1** to         |
|                      |           |         |    **1440**.                              |
+----------------------+-----------+---------+-------------------------------------------+
| ssl_protocols        | No        | String  | -  Specifies the supported SSL/TLS        |
|                      |           |         |    protocol version. This parameter is    |
|                      |           |         |    available only when **protocol** is    |
|                      |           |         |    set to **HTTPS** or **SSL**.           |
|                      |           |         |                                           |
|                      |           |         | -  The value is **TLSv1.2** or **TLSv1.2  |
|                      |           |         |    TLSv1.1 TLSv1** and the default value  |
|                      |           |         |    is **TLSv1.2**.                        |
+----------------------+-----------+---------+-------------------------------------------+
| ssl_ciphers          | No        | String  | -  Specifies the cipher suites supported  |
|                      |           |         |    by a specific SSL/TLS protocol         |
|                      |           |         |    version. This parameter is available   |
|                      |           |         |    only when **protocol** is set to       |
|                      |           |         |    **HTTPS** or **SSL**.                  |
|                      |           |         |                                           |
|                      |           |         | -  The value is **Default**,              |
|                      |           |         |    **Extended**, or **Strict**.           |
|                      |           |         |                                           |
|                      |           |         | The value of **Default** is               |
|                      |           |         | **ECDHE-RSA-AES256-GCM-SHA                |
|                      |           |         | 384:ECDHE-RSA-AES128-GCM-SHA256:ECDHE-RSA |
|                      |           |         | -AES256-SHA384:ECDHE-RSA-AES128-SHA256**. |
|                      |           |         |                                           |
|                      |           |         | The value of **Extended** is              |
|                      |           |         | **ECDHE-ECDSA-AES128-SHA256:ECDHE-R       |
|                      |           |         | SA-AES128-SHA256:AES128-SHA256:AES256-SHA |
|                      |           |         | 256:ECDHE-ECDSA-AES256-SHA384:ECDHE-RSA-A |
|                      |           |         | ES256-SHA384:ECDHE-ECDSA-AES128-SHA:ECDHE |
|                      |           |         | -RSA-AES128-SHA:DHE-RSA-AES128-SHA:ECDHE- |
|                      |           |         | RSA-AES256-SHA:ECDHE-ECDSA-AES256-SHA:AES |
|                      |           |         | 128-SHA:AES256-SHA:DHE-DSS-AES128-SHA:CAM |
|                      |           |         | ELLIA128-SHA:EDH-RSA-DES-CBC3-SHA:DES-CBC |
|                      |           |         | 3-SHA:ECDHE-RSA-RC4-SHA:RC4-SHA:DHE-RSA-A |
|                      |           |         | ES256-SHA:DHE-DSS-AES256-SHA:DHE-RSA-CAME |
|                      |           |         | LLIA256-SHA:DHE-DSS-CAMELLIA256-SHA:CAMEL |
|                      |           |         | LIA256-SHA:EDH-DSS-DES-CBC3-SHA:DHE-RSA-C |
|                      |           |         | AMELLIA128-SHA:DHE-DSS-CAMELLIA128-SHA**. |
|                      |           |         |                                           |
|                      |           |         | The value of **Strict** is                |
|                      |           |         | **ECDHE-RSA-AES256-                       |
|                      |           |         | GCM-SHA384:ECDHE-RSA-AES128-GCM-SHA256**. |
|                      |           |         |                                           |
|                      |           |         | The default value is **Default**. The     |
|                      |           |         | value can only be set to **Extended** if  |
|                      |           |         | **ssl_protocols** is set to **TLSv1.2     |
|                      |           |         | TLSv1.1 TLSv1**.                          |
+----------------------+-----------+---------+-------------------------------------------+
| certificate_id       | No        | String  | -  Specifies the default certificate ID.  |
|                      |           |         |    This parameter is mandatory when       |
|                      |           |         |    **protocol** is set to **HTTPS** or    |
|                      |           |         |    **SSL**.                               |
|                      |           |         |                                           |
|                      |           |         | -  The ID can be obtained from the        |
|                      |           |         |    certificate list.                      |
+----------------------+-----------+---------+-------------------------------------------+
| certificates         | No        | String  | -  Lists the certificate IDs if           |
|                      |           |         |    **protocol** is set to **HTTPS**.      |
|                      |           |         |                                           |
|                      |           |         | -  This parameter is mandatory in the SNI |
|                      |           |         |    scenario.                              |
|                      |           |         |                                           |
|                      |           |         | -  This parameter is valid only when the  |
|                      |           |         |    load balancer is a public network load |
|                      |           |         |    balancer.                              |
+----------------------+-----------+---------+-------------------------------------------+

#. Request

-  Request parameters

None

-  Example request

| {
| "name": "lis",
| "description": "",
| "port": 9090,
| "backend_port": 9090,
| "lb_algorithm": "roundrobin"
| }

#. Response

-  Response parameters

   1. Parameter description

+----------------------+---------+----------------------------------------------+
| Parameter            | Type    | Description                                  |
+======================+=========+==============================================+
| update_time          | String  | Specifies the time when the listener was     |
|                      |         | updated.                                     |
+----------------------+---------+----------------------------------------------+
| backend_port         | Integer | Specifies the port used by backend ECSs.     |
+----------------------+---------+----------------------------------------------+
| id                   | String  | Specifies the listener ID in UUID format.    |
+----------------------+---------+----------------------------------------------+
| backend_protocol     | String  | Specifies the protocol used by backend ECSs. |
+----------------------+---------+----------------------------------------------+
| sticky_session_type  | String  | Specifies where the cookie is from. The      |
|                      |         | only value is **insert**, indicating that    |
|                      |         | the cookie is inserted by the load           |
|                      |         | balancer.                                    |
|                      |         |                                              |
|                      |         | -  This parameter is valid when              |
|                      |         |    **protocol** is set to **HTTP** and       |
|                      |         |    **session_sticky** to **true**.           |
|                      |         |                                              |
|                      |         | -  This parameter is invalid when            |
|                      |         |    **protocol** is set to **TCP**, **SSL**,  |
|                      |         |    or **UDP**, which means that the          |
|                      |         |    parameter is unavailable or its value is  |
|                      |         |    set to **null**.                          |
+----------------------+---------+----------------------------------------------+
| description          | String  | Provides supplementary information about     |
|                      |         | the listener.                                |
+----------------------+---------+----------------------------------------------+
| loadbalancer_id      | String  | Specifies the load balancer ID.              |
+----------------------+---------+----------------------------------------------+
| create_time          | String  | Specifies the time when the listener was     |
|                      |         | created.                                     |
+----------------------+---------+----------------------------------------------+
| status               | String  | Specifies the listener status. The value     |
|                      |         | can be **ACTIVE**, **PENDING_CREATE**, or    |
|                      |         | **ERROR**.                                   |
+----------------------+---------+----------------------------------------------+
| protocol             | String  | Specifies the protocol used for load         |
|                      |         | balancing at Layer 4 or Layer 7.             |
+----------------------+---------+----------------------------------------------+
| port                 | Integer | Specifies the port used by the listener.     |
+----------------------+---------+----------------------------------------------+
| cookie_timeout       | Integer | -  Specifies the cookie timeout duration.    |
|                      |         |    This parameter is valid when              |
|                      |         |    **session_sticky** is set to **true**     |
|                      |         |    and **sticky_session_type** to            |
|                      |         |    **insert**.                               |
|                      |         |                                              |
|                      |         | -  The value ranges from **1** to **1440**.  |
+----------------------+---------+----------------------------------------------+
| admin_state_up       | Boolean | -  Specifies the administrative status of    |
|                      |         |    the load balancer.                        |
|                      |         |                                              |
|                      |         | -  Two options are available:                |
|                      |         |                                              |
|                      |         | **false**: The load balancer is disabled.    |
|                      |         |                                              |
|                      |         | **true**: The load balancer is running       |
|                      |         | properly.                                    |
+----------------------+---------+----------------------------------------------+
| healthcheck_id       | String  | Specifies the health check ID.               |
|                      |         |                                              |
+----------------------+---------+----------------------------------------------+
| session_sticky       | Boolean | Specifies whether to enable the sticky       |
|                      |         | session feature. The feature is enabled      |
|                      |         | when the value is **true**. This parameter   |
|                      |         | is valid only when **protocol** is set to    |
|                      |         | **HTTP**.                                    |
+----------------------+---------+----------------------------------------------+
| lb_algorithm         | String  | Specifies the load balancing algorithm.      |
|                      |         |                                              |
+----------------------+---------+----------------------------------------------+
| name                 | String  | Specifies the listener name.                 |
+----------------------+---------+----------------------------------------------+
| tcp_draining         | Boolean | -  Specifies whether to maintain TCP         |
|                      |         |    connections to a backend ECS that has     |
|                      |         |    been removed. This parameter is valid     |
|                      |         |    when **protocol** is set to **TCP**.      |
|                      |         |                                              |
|                      |         | -  The value can be **true** or **false**.   |
+----------------------+---------+----------------------------------------------+
| tcp_draining_timeout | Integer | -  Specifies the timeout duration for        |
|                      |         |    maintaining TCP connections to a backend  |
|                      |         |    ECS that has been removed. The unit is    |
|                      |         |    minute.                                   |
|                      |         |                                              |
|                      |         | This parameter is valid when **protocol**    |
|                      |         | is set to **TCP** and **tcp_draining** to    |
|                      |         | **true**.                                    |
|                      |         |                                              |
|                      |         | -  The value ranges from **0** to **60**.    |
+----------------------+---------+----------------------------------------------+
| certificate_id       | String  | Specifies the ID of the SSL certificate for  |
|                      |         | security authentication.                     |
|                      |         |                                              |
|                      |         | This parameter is mandatory when             |
|                      |         | **protocol** is set to **HTTPS** or          |
|                      |         | **SSL**. Otherwise, the parameter value is   |
|                      |         | **null**.                                    |
+----------------------+---------+----------------------------------------------+
| certificates         | String  | Lists the certificate IDs if **protocol**    |
|                      |         | is set to **HTTPS**.                         |
|                      |         |                                              |
|                      |         | This parameter is mandatory in the SNI       |
|                      |         | scenario.                                    |
+----------------------+---------+----------------------------------------------+

-  Example response

| {
| "update_time": "2016-12-01 07:12:59",
| "backend_port": 9090,
| "id": "a824584fb3ba4d39ba0cf372c7cbbb67",
| "backend_protocol": "TCP",
| "sticky_session_type": null,
| "certificate_id": null,
| "description": "",
| "loadbalancer_id": "f54c65b1b5dd4a4f95b71b44796ac013",
| "create_time": "2016-12-01 07:12:43",
| "admin_state_up": false,
| "status": "ACTIVE",
| "protocol": "TCP",
| "cookie_timeout": 100,
| "port": 9092,
| "tcp_draining": true,
| "tcp_timeout": 1,
| "lb_algorithm": "roundrobin",
| "healthcheck_id": null,
| "session_sticky": true,
| "tcp_draining_timeout": 5,
| "name": "lis"
| }

#. Status Code

-  Normal

200

-  Error

+-------------+--------------------+--------------------------------+
| Status Code | Message            | Description                    |
+=============+====================+================================+
| 400         | badRequest         | Request error.                 |
+-------------+--------------------+--------------------------------+
| 401         | unauthorized       | Authentication failed.         |
+-------------+--------------------+--------------------------------+
| 403         | userDisabled       | You do not have the permission |
|             |                    | to perform the operation.      |
+-------------+--------------------+--------------------------------+
| 404         | Not Found          | The requested page does not    |
|             |                    | exist.                         |
+-------------+--------------------+--------------------------------+
| 500         | authFault          | System error.                  |
+-------------+--------------------+--------------------------------+
| 503         | serviceUnavailable | The service is unavailable.    |
+-------------+--------------------+--------------------------------+

Querying Details of a Listener
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#. Function

This API is used to query details about a listener.

2. URI

GET /v1.0/{project_id}/elbaas/listeners/{listener_id}

1. Parameter description

+-------------+-----------+--------+----------------------------+
| Parameter   | Mandatory | Type   | Description                |
+=============+===========+========+============================+
| project_id  | Yes       | String | Specifies the project ID.  |
+-------------+-----------+--------+----------------------------+
| listener_id | Yes       | String | Specifies the listener ID. |
+-------------+-----------+--------+----------------------------+

3. Request

-  Request parameters

None

-  Example request

None

#. Response

-  Response parameters

   1. Parameter description

+---------------------+---------+-------------------------------------------------+
| Parameter           | Type    | Description                                     |
+=====================+=========+=================================================+
| update_time         | String  | Specifies the time when the listener was        |
|                     |         | updated.                                        |
+---------------------+---------+-------------------------------------------------+
| backend_port        | Integer | Specifies the port used by backend ECSs.        |
+---------------------+---------+-------------------------------------------------+
| id                  | String  | Specifies the listener ID.                      |
+---------------------+---------+-------------------------------------------------+
| backend_protocol    | String  | Specifies the protocol used by backend ECSs.    |
+---------------------+---------+-------------------------------------------------+
| sticky_session_type | String  | Specifies where the cookie is from. The only    |
|                     |         | value is **insert**, indicating that the cookie |
|                     |         | is inserted by the load balancer.               |
|                     |         |                                                 |
|                     |         | -  This parameter is valid when **protocol** is |
|                     |         |    set to **HTTP** and **session_sticky** to    |
|                     |         |    **true**. The default value is **insert**.   |
|                     |         |                                                 |
|                     |         | -  This parameter is invalid when **protocol**  |
|                     |         |    is set to **TCP**, which means that the      |
|                     |         |    parameter is unavailable or its value is set |
|                     |         |    to **null**.                                 |
+---------------------+---------+-------------------------------------------------+
| description         | String  | Provides supplementary information about the    |
|                     |         | listener.                                       |
+---------------------+---------+-------------------------------------------------+
| loadbalancer_id     | String  | Specifies the load balancer ID.                 |
+---------------------+---------+-------------------------------------------------+
| create_time         | String  | Specifies the time when the listener was        |
|                     |         | created.                                        |
+---------------------+---------+-------------------------------------------------+
| status              | String  | Specifies the listener status. The value can be |
|                     |         | **ACTIVE**, **PENDING_CREATE**, or **ERROR**.   |
+---------------------+---------+-------------------------------------------------+
| protocol            | String  | Specifies the protocol used for load balancing  |
|                     |         | at Layer 4 or Layer 7.                          |
+---------------------+---------+-------------------------------------------------+
| port                | Integer | Specifies the port used by the listener.        |
+---------------------+---------+-------------------------------------------------+
| cookie_timeout      | Integer | -  Specifies the cookie timeout duration. This  |
|                     |         |    parameter is valid when **session_sticky**   |
|                     |         |    is set to **true** and                       |
|                     |         |    **sticky_session_type** to **insert**.       |
|                     |         |                                                 |
|                     |         | -  The value ranges from **1** to **1440**.     |
+---------------------+---------+-------------------------------------------------+
| admin_state_up      | Boolean | -  Specifies the administrative status of the   |
|                     |         |    load balancer.                               |
|                     |         |                                                 |
|                     |         | -  Two options are available:                   |
|                     |         |                                                 |
|                     |         | **false**: The load balancer is disabled.       |
|                     |         |                                                 |
|                     |         | **true**: The load balancer is running          |
|                     |         | properly.                                       |
+---------------------+---------+-------------------------------------------------+
| member_number       | Integer | Specifies the quantity of backend ECSs.         |
+---------------------+---------+-------------------------------------------------+
| healthckeck_id      | String  | Specifies the health check ID.                  |
+---------------------+---------+-------------------------------------------------+
| session_sticky      | Boolean | Specifies whether to enable the sticky session  |
|                     |         | feature. The feature is enabled when the value  |
|                     |         | is **true**.                                    |
+---------------------+---------+-------------------------------------------------+
| lb_algorithm        | String  | Specifies the load balancing algorithm.         |
|                     |         |                                                 |
+---------------------+---------+-------------------------------------------------+
| name                | String  | Specifies the listener name.                    |
+---------------------+---------+-------------------------------------------------+
| certificate_id      | String  | Specifies the ID of the SSL certificate for     |
|                     |         | security authentication.                        |
|                     |         |                                                 |
|                     |         | This parameter is mandatory when **protocol**   |
|                     |         | is set to **HTTPS** or **SSL**. Otherwise, the  |
|                     |         | parameter value is **null**.                    |
+---------------------+---------+-------------------------------------------------+
| certificates        | String  | Lists the certificate IDs if **protocol** is    |
|                     |         | set to **HTTPS**.                               |
|                     |         |                                                 |
|                     |         | This parameter is mandatory in the SNI          |
|                     |         | scenario.                                       |
+---------------------+---------+-------------------------------------------------+
| tcp_timeout         | Integer | Specifies the TCP session timeout duration.     |
+---------------------+---------+-------------------------------------------------+
| udp_timeout         | Integer | Specifies the UDP session timeout duration.     |
+---------------------+---------+-------------------------------------------------+
| ssl_protocols       | String  | Specifies the supported SSL/TLS protocol        |
|                     |         | version. This parameter is available only when  |
|                     |         | **protocol** is set to **HTTPS** or **SSL**.    |
|                     |         |                                                 |
|                     |         | NOTE                                            |
|                     |         |                                                 |
|                     |         | For HTTPS listeners in versions earlier than    |
|                     |         | 1.2.8, the parameter value is **TLSv1.2**.      |
+---------------------+---------+-------------------------------------------------+
| ssl_ciphers         | String  | Specifies the cipher suite of an encryption     |
|                     |         | protocol. This parameter is available only when |
|                     |         | **protocol** is set to **HTTPS** or **SSL**.    |
+---------------------+---------+-------------------------------------------------+

-  Example response

| {
| "update_time": "2015-09-15 07:41:17",
| "backend_port": 80,
| "id": "248425d7b97dc26920eb23720115e068",
| "backend_protocol": "TCP",
| "sticky_session_type": "insert",
| "description": "",
| "loadbalancer_id": "0b07acf06d243925bc24a0ac7445267a",
| "create_time": "2015-09-15 07:41:17",
| "status": "ACTIVE",
| "protocol": "TCP",
| "port": 88,
| "cookie_timeout": 100,
| "admin_state_up": true,
| "member_number": 0,
| "healthcheck_id": null,
| "session_sticky": true,
| "lb_algorithm": "roundrobin",
| "name": "listener1",
| "tcp_draining": true,
| "tcp_draining_timeout": 5
| }

| {
| "update_time": "2016-12-01 07:12:59",
| "backend_port": 9090,
| "id": "a824584fb3ba4d39ba0cf372c7cbbb67",
| "backend_protocol": "TCP",
| "sticky_session_type": null,
| "certificate_id": null,
| "description": "",
| "loadbalancer_id": "f54c65b1b5dd4a4f95b71b44796ac013",
| "lb_algorithm": "roundrobin",
| "create_time": "2016-12-01 07:12:43",
| "admin_state_up": false,
| "status": "ACTIVE",
| "protocol": "TCP",
| "cookie_timeout": 100,
| "port": 9092,
| "tcp_draining": 1,
| "tcp_timeout": 1,
| "member_number": 0,
| "healthcheck_id": null,
| "session_sticky": true,
| "tcp_draining_timeout": 5,
| "name": "lis"
| }

#. Status Code

-  Normal

200

-  Error

+-------------+--------------------+--------------------------------+
| Status Code | Message            | Description                    |
+=============+====================+================================+
| 400         | badRequest         | Request error.                 |
+-------------+--------------------+--------------------------------+
| 401         | unauthorized       | Authentication failed.         |
+-------------+--------------------+--------------------------------+
| 403         | userDisabled       | You do not have the permission |
|             |                    | to perform the operation.      |
+-------------+--------------------+--------------------------------+
| 404         | Not Found          | The requested page does not    |
|             |                    | exist.                         |
+-------------+--------------------+--------------------------------+
| 500         | authFault          | System error.                  |
+-------------+--------------------+--------------------------------+
| 503         | serviceUnavailable | The service is unavailable.    |
+-------------+--------------------+--------------------------------+

Querying Listeners
~~~~~~~~~~~~~~~~~~

#. Function

This API is used to query listeners using search criteria and display
them in a list.

2. URI

GET
/v1.0/{project_id}/elbaas/listeners?loadbalancer_id={loadbalancer_id}

.. image:: /media/image2.png
   :width: 0.75in
   :height: 0.26042in

Enter a question mark (?) and an ampersand (&) at the end of the URI to
define multiple search criteria. You can filter the listeners using the
parameters in the response except **update_time**, **create_time**,
**admin_state_up**, **session_sticky**, and **member_number**.

1. Parameter description

+-----------------+-----------+--------+---------------------------------+
| Parameter       | Mandatory | Type   | Description                     |
+=================+===========+========+=================================+
| project_id      | Yes       | String | Specifies the project ID.       |
+-----------------+-----------+--------+---------------------------------+
| loadbalancer_id | No        | String | Specifies the load balancer ID. |
+-----------------+-----------+--------+---------------------------------+

3. Request

-  Request parameters

None

-  Example request

None

#. Response

-  Response parameters

   1. Parameter description

+---------------------+---------+--------------------------------------------------+
| Parameter           | Type    | Description                                      |
+=====================+=========+==================================================+
| update_time         | String  | Specifies the time when the listener was         |
|                     |         | updated.                                         |
+---------------------+---------+--------------------------------------------------+
| backend_port        | Integer | Specifies the port used by backend ECSs.         |
+---------------------+---------+--------------------------------------------------+
| id                  | String  | Specifies the listener ID.                       |
+---------------------+---------+--------------------------------------------------+
| backend_protocol    | String  | Specifies the protocol used by backend ECSs.     |
+---------------------+---------+--------------------------------------------------+
| sticky_session_type | String  | Specifies where the cookie is from. The only     |
|                     |         | value is **insert**, indicating that the cookie  |
|                     |         | is inserted by the load balancer.                |
|                     |         |                                                  |
|                     |         | -  This parameter is valid when **protocol** is  |
|                     |         |    set to **HTTP** and **session_sticky** to     |
|                     |         |    **true**. The default value is **insert**.    |
|                     |         |                                                  |
|                     |         | -  This parameter is invalid when **protocol**   |
|                     |         |    is set to **TCP**, which means that the       |
|                     |         |    parameter is unavailable or its value is set  |
|                     |         |    to **null**.                                  |
+---------------------+---------+--------------------------------------------------+
| description         | String  | Provides supplementary information about the     |
|                     |         | listener.                                        |
+---------------------+---------+--------------------------------------------------+
| loadbalancer_id     | String  | Specifies the load balancer ID.                  |
+---------------------+---------+--------------------------------------------------+
| create_time         | String  | Specifies the time when the listener was         |
|                     |         | created.                                         |
+---------------------+---------+--------------------------------------------------+
| status              | String  | Specifies the listener status. The value can be  |
|                     |         | **ACTIVE**, **PENDING_CREATE**, or **ERROR**.    |
+---------------------+---------+--------------------------------------------------+
| protocol            | String  | Specifies the protocol used for load balancing   |
|                     |         | at Layer 4 or Layer 7.                           |
+---------------------+---------+--------------------------------------------------+
| lb_algorithm        | String  | Specifies the load balancing algorithm.          |
|                     |         |                                                  |
+---------------------+---------+--------------------------------------------------+
| admin_state_up      | Boolean | -  Specifies the administrative status of the    |
|                     |         |    load balancer.                                |
|                     |         |                                                  |
|                     |         | -  Two options are available:                    |
|                     |         |                                                  |
|                     |         | **false**: The load balancer is disabled.        |
|                     |         | **true**: The load balancer is running properly. |
+---------------------+---------+--------------------------------------------------+
| cookie_timeout      | Integer | -  Specifies the cookie timeout duration. This   |
|                     |         |    parameter is valid when **session_sticky** is |
|                     |         |    set to **true** and **sticky_session_type**   |
|                     |         |    to **insert**.                                |
|                     |         |                                                  |
|                     |         | -  The value ranges from **1** to **1440**.      |
+---------------------+---------+--------------------------------------------------+
| member_number       | Integer | Specifies the quantity of backend ECSs.          |
+---------------------+---------+--------------------------------------------------+
| healthcheck_id      | String  | Specifies the health check ID.                   |
+---------------------+---------+--------------------------------------------------+
| session_sticky      | Boolean | Specifies whether to enable the sticky session   |
|                     |         | feature. The feature is enabled when the value   |
|                     |         | is **true**.                                     |
+---------------------+---------+--------------------------------------------------+
| port                | Integer | Specifies the port used by the listener.         |
+---------------------+---------+--------------------------------------------------+
| name                | String  | Specifies the listener name.                     |
+---------------------+---------+--------------------------------------------------+
| certificate_id      | String  | Specifies the ID of the SSL certificate for      |
|                     |         | security authentication. This parameter is       |
|                     |         | mandatory when **protocol** is set to **HTTPS**  |
|                     |         | or **SSL**. Otherwise, the parameter value is    |
|                     |         | **null**.                                        |
+---------------------+---------+--------------------------------------------------+
| certificates        | String  | Lists the certificate IDs if **protocol** is set |
|                     |         | to **HTTPS**.                                    |
|                     |         |                                                  |
|                     |         | This parameter is mandatory in the SNI scenario. |
+---------------------+---------+--------------------------------------------------+
| tcp_timeout         | Integer | Specifies the TCP session timeout duration.      |
|                     |         |                                                  |
+---------------------+---------+--------------------------------------------------+
| udp_timeout         | Integer | Specifies the UDP session timeout duration.      |
|                     |         |                                                  |
+---------------------+---------+--------------------------------------------------+
| ssl_protocols       | String  | Specifies the supported SSL/TLS protocol         |
|                     |         | version. This parameter is available only when   |
|                     |         | **protocol** is set to **HTTPS** or **SSL**.     |
|                     |         |                                                  |
|                     |         | NOTE                                             |
|                     |         |                                                  |
|                     |         | For HTTPS listeners in versions earlier than     |
|                     |         | 1.2.8, the parameter value is **TLSv1.2**.       |
+---------------------+---------+--------------------------------------------------+
| ssl_ciphers         | String  | Specifies the cipher suite of an encryption      |
|                     |         | protocol. This parameter is available only when  |
|                     |         | **protocol** is set to **HTTPS** or **SSL**.     |
+---------------------+---------+--------------------------------------------------+

-  Example response

| [
| {
| "update_time": "2016-12-01 07:12:59",
| "backend_port": 9090,
| "id": "a824584fb3ba4d39ba0cf372c7cbbb67",
| "backend_protocol": "TCP",
| "sticky_session_type": null,
| "certificate_id": null,
| "description": "",
| "loadbalancer_id": "f54c65b1b5dd4a4f95b71b44796ac013",
| "lb_algorithm": "roundrobin",
| "create_time": "2016-12-01 07:12:43",
| "admin_state_up": false,
| "status": "ACTIVE",
| "protocol": "TCP",
| "cookie_timeout": 100,
| "port": 9092,
| "tcp_draining": true,
| "tcp_timeout": 1,
| "member_number": 0,
| "healthcheck_id": null,
| "session_sticky": true,
| "tcp_draining_timeout": 5,
| "name": "lis"
| },
| {
| "update_time": "2016-12-01 07:11:49",
| "backend_port": 9090,
| "id": "4818300858fc43e0a4d843ce74ee83a4",
| "backend_protocol": "HTTP",
| "sticky_session_type": "insert",
| "certificate_id": null,
| "description": "",
| "loadbalancer_id": "f54c65b1b5dd4a4f95b71b44796ac013",
| "lb_algorithm": "roundrobin",
| "create_time": "2016-12-01 07:11:30",
| "admin_state_up": false,
| "status": "ACTIVE",
| "protocol": "HTTP",
| "cookie_timeout": 100,
| "port": 9091,
| "tcp_draining": true,
| "tcp_timeout": null,
| "member_number": 0,
| "healthcheck_id": null,
| "session_sticky": true,
| "tcp_draining_timeout": 5,
| "name": "lis"
| }
| ]

#. Status Code

-  Normal

200

-  Error

+-------------+--------------------+--------------------------------+
| Status Code | Message            | Description                    |
+=============+====================+================================+
| 400         | badRequest         | Request error.                 |
+-------------+--------------------+--------------------------------+
| 401         | unauthorized       | Authentication failed.         |
+-------------+--------------------+--------------------------------+
| 403         | userDisabled       | You do not have the permission |
|             |                    | to perform the operation.      |
+-------------+--------------------+--------------------------------+
| 404         | Not Found          | The requested page does not    |
|             |                    | exist.                         |
+-------------+--------------------+--------------------------------+
| 500         | authFault          | System error.                  |
+-------------+--------------------+--------------------------------+
| 503         | serviceUnavailable | The service is unavailable.    |
+-------------+--------------------+--------------------------------+


