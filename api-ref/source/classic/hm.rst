Health Check
############

Configuring a Health Check
==========================

Function
^^^^^^^^

This API is used to configure a health check for backend ECSs.

URI
^^^

POST /v1.0/{project_id}/elbaas/healthcheck

.. table:: **Table 1** Parameter description

   +--------------------------+-----------+---------+-----------------------------+
   | Parameter                | Mandatory | Type    | Description                 |
   +==========================+===========+=========+=============================+
   | project_id               | Yes       | String  | Specifies the project ID.   |
   +--------------------------+-----------+---------+-----------------------------+
   | listener_id              | Yes       | String  | Specifies the ID of the     |
   |                          |           |         | listener with which the     |
   |                          |           |         | health check is associated. |
   +--------------------------+-----------+---------+-----------------------------+
   | healthcheck_protocol     | No        | String  | -  Specifies the health     |
   |                          |           |         |    check protocol. A        |
   |                          |           |         |    listener using UDP is    |
   |                          |           |         |    not allowed for a        |
   |                          |           |         |    private network load     |
   |                          |           |         |    balancer.                |
   |                          |           |         | -  The value can be         |
   |                          |           |         |    **HTTP**, **TCP**, or    |
   |                          |           |         |    **UDP**.                 |
   +--------------------------+-----------+---------+-----------------------------+
   | healthcheck_uri          | No        | String  | -  Specifies the health     |
   |                          |           |         |    check URI. This          |
   |                          |           |         |    parameter is valid when  |
   |                          |           |         |    **healthcheck_protocol** |
   |                          |           |         |    is **HTTP**.             |
   |                          |           |         | -  The value can contain 1  |
   |                          |           |         |    to 80 characters that    |
   |                          |           |         |    must start with a slash  |
   |                          |           |         |    (/) and can contain only |
   |                          |           |         |    letters, digits, and     |
   |                          |           |         |    special characters such  |
   |                          |           |         |    as -/.%?#&_=             |
   +--------------------------+-----------+---------+-----------------------------+
   | healthcheck_connect_port | No        | Integer | -  Specifies the health     |
   |                          |           |         |    check port.              |
   |                          |           |         | -  The port number ranges   |
   |                          |           |         |    from 1 to 65535.         |
   +--------------------------+-----------+---------+-----------------------------+
   | healthy_threshold        | No        | Integer | -  Specifies the number of  |
   |                          |           |         |    consecutive health       |
   |                          |           |         |    checks when the health   |
   |                          |           |         |    check result of a        |
   |                          |           |         |    backend ECS changes from |
   |                          |           |         |    **fail** to **success**. |
   |                          |           |         | -  The value ranges from    |
   |                          |           |         |    **1** to **10**.         |
   +--------------------------+-----------+---------+-----------------------------+
   | unhealthy_threshold      | No        | Integer | -  Specifies the number of  |
   |                          |           |         |    consecutive health       |
   |                          |           |         |    checks when the health   |
   |                          |           |         |    check result of a        |
   |                          |           |         |    backend ECS changes from |
   |                          |           |         |    **success** to **fail**. |
   |                          |           |         | -  The value ranges from    |
   |                          |           |         |    **1** to **10**.         |
   +--------------------------+-----------+---------+-----------------------------+
   | healthcheck_timeout      | No        | Integer | -  Specifies the maximum    |
   |                          |           |         |    time required for        |
   |                          |           |         |    waiting for a response   |
   |                          |           |         |    from the health check in |
   |                          |           |         |    the unit of second.      |
   |                          |           |         | -  The value ranges from    |
   |                          |           |         |    **1** to **50**.         |
   +--------------------------+-----------+---------+-----------------------------+
   | healthcheck_interval     | No        | Integer | -  Specifies the maximum    |
   |                          |           |         |    time between health      |
   |                          |           |         |    checks in the unit of    |
   |                          |           |         |    second.                  |
   |                          |           |         | -  The value ranges from    |
   |                          |           |         |    **1** to **50**.         |
   +--------------------------+-----------+---------+-----------------------------+

Request
^^^^^^^

-  Request parameters

   None

-  Example request 1: Configuring an HTTP health check

   .. code:: json

      {
          "healthcheck_connect_port": 80,
          "healthcheck_interval": 5,
          "healthcheck_protocol": "HTTP",
          "healthcheck_timeout": 10,
          "healthcheck_uri": "/",
          "healthy_threshold": 3,
          "listener_id": "3ce8c4429478a5eb6ef4930de2d75b28",
          "unhealthy_threshold": 3
      }

-  Example request 2: Configuring a TCP health check

   .. code:: json

      {
          "healthcheck_connect_port": 80,
          "healthcheck_interval": 5,
          "healthcheck_protocol": "TCP",
          "healthcheck_timeout": 10,
          "healthcheck_uri": "",
          "healthy_threshold": 3,
          "listener_id": "3ce8c4429478a5eb6ef4930de2d75b28",
          "unhealthy_threshold": 3
      }

Response
^^^^^^^^

-  Response parameters

.. table:: **Table 2** Parameter description

   +--------------------------+---------+-----------------------------------------------------------------------------+
   | Parameter                | Type    | Description                                                                 |
   +==========================+=========+=============================================================================+
   | healthcheck_interval     | Integer | Specifies the maximum time between health checks in the unit of second.     |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | listener_id              | String  | Specifies the ID of the listener with which the health check is associated. |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | id                       | String  | Specifies the health check ID.                                              |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | healthcheck_protocol     | String  | Specifies the health check protocol.                                        |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | unhealthy_threshold      | Integer | Specifies the number of consecutive health checks when the health check     |
   |                          |         | result of a backend ECS changes from **success** to **fail**.               |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | update_time              | String  | Specifies the time when the health check was updated.                       |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | create_time              | String  | Specifies the time when the health check was configured.                    |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | healthcheck_connect_port | Integer | Specifies the health check port.                                            |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | healthcheck_timeout      | Integer | Specifies the maximum time required for waiting for a response from the     |
   |                          |         | health check in the unit of second.                                         |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | healthcheck_uri          | String  | Specifies the health check URI. This parameter is valid when                |
   |                          |         | **healthcheck_protocol** is **HTTP**.                                       |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | healthy_threshold        | Integer | Specifies the number of consecutive health checks when the health check     |
   |                          |         | result of a backend ECS changes from **fail** to **success**.               |
   +--------------------------+---------+-----------------------------------------------------------------------------+

-  Example response 1: Configuring an HTTP health check

   .. code:: json

      {
           "healthcheck_interval":5,
           "listener_id":"3ce8c4429478a5eb6ef4930de2d75b28",
           "id":"134e5ea962327c6a574b83e6e7f31f35",
           "healthcheck_protocol":"HTTP",
           "unhealthy_threshold":3,
           "update_time":"2015-12-25 03:57:23",
           "create_time":"2015-12-25 03:57:23",
           "healthcheck_connect_port":80,
           "healthcheck_timeout":10,
           "healthcheck_uri":"\/",
           "healthy_threshold":3
      }

-  Example response 2: Configuring a TCP health check

   .. code:: json

      {
           "healthcheck_interval":5,
           "listener_id":"3ce8c4429478a5eb6ef4930de2d75b28",
           "id":"134e5ea962327c6a574b83e6e7f31f35",
           "healthcheck_protocol":"TCP",
           "unhealthy_threshold":3,
           "update_time":"2015-12-25 03:57:23",
           "create_time":"2015-12-25 03:57:23",
           "healthcheck_connect_port":80,
           "healthcheck_timeout":10,
           "healthcheck_uri":"",
           "healthy_threshold":3
      }

Status Code
^^^^^^^^^^^

-  Normal

   200

-  Error

   =========== ================== ========================================================
   Status Code Message            Description
   =========== ================== ========================================================
   400         badRequest         Request error.
   401         unauthorized       Authentication failed.
   403         userDisabled       You do not have the permission to perform the operation.
   404         Not Found          The requested page does not exist.
   500         authFault          System error.
   503         serviceUnavailable The service is unavailable.
   =========== ================== ========================================================

Deleting a Health Check
=======================

Function
^^^^^^^^

This API is used to delete a health check.

URI
^^^

DELETE /v1.0/{project_id}/elbaas/healthcheck/{healthcheck_id}

.. table:: **Table 1** Parameter description

   ============== ============= ======== ==============================
   Parameter      **Mandatory** **Type** Description
   ============== ============= ======== ==============================
   project_id     Yes           String   Specifies the project ID.
   healthcheck_id Yes           String   Specifies the health check ID.
   ============== ============= ======== ==============================

Request
^^^^^^^

-  Request parameters

   None

-  Example request

   None

Response
^^^^^^^^

-  Response parameters

   None

-  Example response

   None

Status Code
^^^^^^^^^^^

-  Normal

   204

-  Error

   =========== ================== ========================================================
   Status Code Message            Description
   =========== ================== ========================================================
   400         badRequest         Request error.
   401         unauthorized       Authentication failed.
   403         userDisabled       You do not have the permission to perform the operation.
   404         Not Found          The requested page does not exist.
   500         authFault          System error.
   503         serviceUnavailable The service is unavailable.
   =========== ================== ========================================================

Modifying a Health Check
========================

Function
^^^^^^^^

This API is used to modify information about a health check.

URI
^^^

PUT /v1.0/{project_id}/elbaas/healthcheck/{healthcheck_id}

.. table:: **Table 1** Parameter description

   +--------------------------+-----------+---------+-----------------------------+
   | Parameter                | Mandatory | Type    | Description                 |
   +==========================+===========+=========+=============================+
   | project_id               | Yes       | String  | Specifies the project ID.   |
   +--------------------------+-----------+---------+-----------------------------+
   | healthcheck_id           | Yes       | String  | Specifies the health check  |
   |                          |           |         | ID.                         |
   +--------------------------+-----------+---------+-----------------------------+
   | healthcheck_protocol     | No        | String  | -  Specifies the health     |
   |                          |           |         |    check protocol.          |
   |                          |           |         | -  The value can be         |
   |                          |           |         |    **HTTP** or **TCP**      |
   |                          |           |         |    (case-insensitive).      |
   +--------------------------+-----------+---------+-----------------------------+
   | healthcheck_uri          | No        | String  | -  Specifies the health     |
   |                          |           |         |    check URI. This          |
   |                          |           |         |    parameter is valid when  |
   |                          |           |         |    **healthcheck_protocol** |
   |                          |           |         |    is **HTTP**.             |
   |                          |           |         | -  The value can contain 1  |
   |                          |           |         |    to 80 characters that    |
   |                          |           |         |    must start with a slash  |
   |                          |           |         |    (/) and can contain only |
   |                          |           |         |    letters, digits, and     |
   |                          |           |         |    special characters such  |
   |                          |           |         |    as -/.%?#&_=             |
   +--------------------------+-----------+---------+-----------------------------+
   | healthcheck_connect_port | No        | Integer | -  Specifies the health     |
   |                          |           |         |    check port.              |
   |                          |           |         | -  The port number ranges   |
   |                          |           |         |    from 1 to 65535.         |
   +--------------------------+-----------+---------+-----------------------------+
   | healthy_threshold        | No        | Integer | -  Specifies the number of  |
   |                          |           |         |    consecutive health       |
   |                          |           |         |    checks when the health   |
   |                          |           |         |    check result of a        |
   |                          |           |         |    backend ECS changes from |
   |                          |           |         |    **fail** to **success**. |
   |                          |           |         | -  The value ranges from    |
   |                          |           |         |    **1** to **10**.         |
   +--------------------------+-----------+---------+-----------------------------+
   | unhealthy_threshold      | No        | Integer | -  Specifies the number of  |
   |                          |           |         |    consecutive health       |
   |                          |           |         |    checks when the health   |
   |                          |           |         |    check result of a        |
   |                          |           |         |    backend ECS changes from |
   |                          |           |         |    **success** to **fail**. |
   |                          |           |         | -  The value ranges from    |
   |                          |           |         |    **1** to **10**.         |
   +--------------------------+-----------+---------+-----------------------------+
   | healthcheck_timeout      | No        | Integer | -  Specifies the maximum    |
   |                          |           |         |    time required for        |
   |                          |           |         |    waiting for a response   |
   |                          |           |         |    from the health check in |
   |                          |           |         |    the unit of second.      |
   |                          |           |         | -  The value ranges from    |
   |                          |           |         |    **1** to **50**.         |
   +--------------------------+-----------+---------+-----------------------------+
   | healthcheck_interval     | No        | Integer | -  Specifies the maximum    |
   |                          |           |         |    time between health      |
   |                          |           |         |    checks in the unit of    |
   |                          |           |         |    second.                  |
   |                          |           |         | -  The value ranges from    |
   |                          |           |         |    **1** to **50**.         |
   +--------------------------+-----------+---------+-----------------------------+

Request
^^^^^^^

-  Request parameters

   None

-  Example request

   .. code:: json

      {
          "healthcheck_connect_port": 88,
          "healthcheck_interval": 5,
          "healthcheck_protocol": "HTTP",
          "healthcheck_timeout": 10,
          "healthcheck_uri": "/",
          "healthy_threshold": 3,
          "unhealthy_threshold": 2
      }

Response
^^^^^^^^

-  Response parameters

.. table:: **Table 2** Parameter description

   +--------------------------+---------+-----------------------------------------------------------------------------+
   | Parameter                | Type    | Description                                                                 |
   +==========================+=========+=============================================================================+
   | healthcheck_interval     | Integer | Specifies the maximum time between health checks in the unit of second.     |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | listener_id              | String  | Specifies the ID of the listener with which the health check is associated. |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | id                       | String  | Specifies the health check ID.                                              |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | healthcheck_protocol     | String  | Specifies the health check protocol.                                        |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | unhealthy_threshold      | Integer | Specifies the number of consecutive health checks when the health check     |
   |                          |         | result of a backend ECS changes from **success** to **fail**.               |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | update_time              | String  | Specifies the time when the certificate was updated.                        |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | create_time              | String  | Specifies the time when the health check was created.                       |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | healthcheck_connect_port | Integer | Specifies the health check port.                                            |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | healthcheck_timeout      | Integer | Specifies the maximum time required for waiting for a response from the     |
   |                          |         | health check in the unit of second.                                         |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | healthcheck_uri          | String  | Specifies the health check URI. This parameter is valid when                |
   |                          |         | **healthcheck_protocol** is **HTTP**.                                       |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | healthy_threshold        | Integer | Specifies the threshold at which the health check result is **success**,    |
   |                          |         | that is, the number of consecutive successful health checks when the health |
   |                          |         | check result of a backend ECS changes from **fail** to **success**.         |
   +--------------------------+---------+-----------------------------------------------------------------------------+

-  Example response

   .. code:: json

      {
          "healthcheck_interval": 5,
          "listener_id": "3ce8c4429478a5eb6ef4930de2d75b28",
          "id": "134e5ea962327c6a574b83e6e7f31f35",
          "healthcheck_protocol": "HTTP",
          "unhealthy_threshold": 2,
          "update_time": "2015-12-25 03:57:23",
          "create_time": "2015-12-25 03:57:23",
          "healthcheck_connect_port": 88,
          "healthcheck_timeout": 10,
          "healthcheck_uri": "/",
          "healthy_threshold": 3
      }

Status Code
^^^^^^^^^^^

-  Normal

   200

-  Error

   =========== ================== ========================================================
   Status Code Message            Description
   =========== ================== ========================================================
   400         badRequest         Request error.
   401         unauthorized       Authentication failed.
   403         userDisabled       You do not have the permission to perform the operation.
   404         Not Found          The requested page does not exist.
   500         authFault          System error.
   503         serviceUnavailable The service is unavailable.
   =========== ================== ========================================================

Querying Details of a Health Check
==================================

Function
^^^^^^^^

This API is used to query details about a health check.

URI
^^^

GET /v1.0/{project_id}/elbaas/healthcheck/{healthcheck_id}

.. table:: **Table 1** Parameter description

   ============== ============= ======== ==============================
   Parameter      **Mandatory** **Type** Description
   ============== ============= ======== ==============================
   project_id     Yes           String   Specifies the project ID.
   healthcheck_id Yes           String   Specifies the health check ID.
   ============== ============= ======== ==============================

Request
^^^^^^^

-  Request parameters

   None

-  Example request

   None

Response
^^^^^^^^

-  Response parameters

.. table:: **Table 2** Parameter description

   +--------------------------+---------+-----------------------------------------------------------------------------+
   | Parameter                | Type    | Description                                                                 |
   +==========================+=========+=============================================================================+
   | healthcheck_interval     | Integer | Specifies the maximum time between health checks in the unit of second.     |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | listener_id              | String  | Specifies the ID of the listener with which the health check is associated. |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | id                       | String  | Specifies the health check ID.                                              |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | healthcheck_protocol     | String  | Specifies the health check protocol.                                        |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | unhealthy_threshold      | Integer | Specifies the number of consecutive health checks when the health check     |
   |                          |         | result of a backend ECS changes from **success** to **fail**.               |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | update_time              | String  | Specifies the time when the health check was updated.                       |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | create_time              | String  | Specifies the time when the health check was configured.                    |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | healthcheck_connect_port | Integer | Specifies the health check port.                                            |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | healthcheck_timeout      | Integer | Specifies the maximum time required for waiting for a response from the     |
   |                          |         | health check in the unit of second.                                         |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | healthcheck_uri          | String  | Specifies the health check URI. This parameter is valid when                |
   |                          |         | **healthcheck_protocol** is **HTTP**.                                       |
   +--------------------------+---------+-----------------------------------------------------------------------------+
   | healthy_threshold        | Integer | Specifies the threshold at which the health check result is **success**,    |
   |                          |         | that is, the number of consecutive successful health checks when the health |
   |                          |         | check result of a backend ECS changes from **fail** to **success**.         |
   +--------------------------+---------+-----------------------------------------------------------------------------+

-  Example response

   .. code:: json

      {
          "healthcheck_interval": 5,
          "listener_id": "3ce8c4429478a5eb6ef4930de2d75b28",
          "id": "134e5ea962327c6a574b83e6e7f31f35",
          "healthcheck_protocol": "HTTP",
          "unhealthy_threshold": 2,
          "update_time": "2015-12-25 03:57:23",
          "create_time": "2015-12-25 03:57:23",
          "healthcheck_connect_port": 88,
          "healthcheck_timeout": 10,
          "healthcheck_uri": "/",
          "healthy_threshold": 3
      }

Status Code
^^^^^^^^^^^

-  Normal

   200

-  Error

   =========== ================== ========================================================
   Status Code Message            Description
   =========== ================== ========================================================
   400         badRequest         Request error.
   401         unauthorized       Authentication failed.
   403         userDisabled       You do not have the permission to perform the operation.
   404         Not Found          The requested page does not exist.
   500         authFault          System error.
   503         serviceUnavailable The service is unavailable.
   =========== ================== ========================================================

