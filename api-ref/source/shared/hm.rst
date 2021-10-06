==============
Health Monitor
==============

Configuring a Health Check
==========================

Function
^^^^^^^^

This API is used to configure a health check for a backend server group to check the status of backend servers. If the health check result is **OFFLINE**, backend servers are considered unhealthy. You need to check the server configuration.

Constraints
^^^^^^^^^^^

The security group must allow access from 100.125.0.0/16. Otherwise, the health check cannot be performed.

URI
^^^

POST /v2.0/lbaas/healthmonitors

Request
^^^^^^^

.. table:: **Table 1** Parameter description

   +---------------+-----------+--------+--------------------------------------------------------------------------+
   | **Parameter** | Mandatory | Type   | Description                                                              |
   +===============+===========+========+==========================================================================+
   | healthmonitor | Yes       | Object | Specifies the health check. For details, see :ref:`shared_hm_create_t2`. |
   +---------------+-----------+--------+--------------------------------------------------------------------------+

.. _shared_hm_create_t2:
.. table:: **Table 2** **healthmonitor** parameter description

   +------------------+-----------+---------+-----------------------------+
   | Parameter        | Mandatory | Type    | Description                 |
   +==================+===========+=========+=============================+
   | tenant_id        | No        | String  | Specifies the ID of the     |
   |                  |           |         | project where the health    |
   |                  |           |         | check is performed.         |
   |                  |           |         |                             |
   |                  |           |         | The value must be the same  |
   |                  |           |         | as the value of             |
   |                  |           |         | **project_id** in the       |
   |                  |           |         | token.                      |
   |                  |           |         |                             |
   |                  |           |         | The value contains a        |
   |                  |           |         | maximum of 255 characters.  |
   +------------------+-----------+---------+-----------------------------+
   | name             | No        | String  | Specifies the health check  |
   |                  |           |         | name.                       |
   |                  |           |         |                             |
   |                  |           |         | The value contains a        |
   |                  |           |         | maximum of 255 characters.  |
   +------------------+-----------+---------+-----------------------------+
   | delay            | Yes       | Integer | Specifies the maximum time  |
   |                  |           |         | between health checks in    |
   |                  |           |         | the unit of second. The     |
   |                  |           |         | value ranges from **1** to  |
   |                  |           |         | **50**.                     |
   +------------------+-----------+---------+-----------------------------+
   | max_retries      | Yes       | Integer | Specifies the number of     |
   |                  |           |         | consecutive health checks   |
   |                  |           |         | when the health check       |
   |                  |           |         | result of a backend server  |
   |                  |           |         | changes from **OFFLINE** to |
   |                  |           |         | **ONLINE**. The value       |
   |                  |           |         | ranges from **1** to        |
   |                  |           |         | **10**.                     |
   +------------------+-----------+---------+-----------------------------+
   | max_retries_down | No        | Integer | Specifies the number of     |
   |                  |           |         | consecutive health checks   |
   |                  |           |         | when the health check       |
   |                  |           |         | result of a backend server  |
   |                  |           |         | changes from **ONLINE** to  |
   |                  |           |         | **OFFLINE**. The value      |
   |                  |           |         | ranges from **1** to        |
   |                  |           |         | **10**.                     |
   +------------------+-----------+---------+-----------------------------+
   | pool_id          | Yes       | String  | Specifies the ID of the     |
   |                  |           |         | backend server group.       |
   |                  |           |         |                             |
   |                  |           |         | Only one health check can   |
   |                  |           |         | be configured for each      |
   |                  |           |         | backend server group.       |
   +------------------+-----------+---------+-----------------------------+
   | admin_state_up   | No        | Boolean | Specifies the               |
   |                  |           |         | administrative status of    |
   |                  |           |         | the health check.           |
   |                  |           |         |                             |
   |                  |           |         | This parameter is reserved, |
   |                  |           |         | and the default value is    |
   |                  |           |         | **true**.                   |
   +------------------+-----------+---------+-----------------------------+
   | timeout          | Yes       | Integer | Specifies the health check  |
   |                  |           |         | timeout duration in the     |
   |                  |           |         | unit of second. The value   |
   |                  |           |         | ranges from **1** to        |
   |                  |           |         | **50**.                     |
   |                  |           |         |                             |
   |                  |           |         | NOTE:                       |
   |                  |           |         | You are advised to set the  |
   |                  |           |         | value less than that of     |
   |                  |           |         | parameter **delay**.        |
   +------------------+-----------+---------+-----------------------------+
   | type             | Yes       | String  | Specifies the health check  |
   |                  |           |         | protocol.                   |
   |                  |           |         |                             |
   |                  |           |         | The value can be **TCP**,   |
   |                  |           |         | **UDP_CONNECT**, or         |
   |                  |           |         | **HTTP**.                   |
   |                  |           |         |                             |
   |                  |           |         | The relationships between   |
   |                  |           |         | the health check protocol   |
   |                  |           |         | and the protocol used by    |
   |                  |           |         | the backend server group    |
   |                  |           |         | are as follows:             |
   |                  |           |         |                             |
   |                  |           |         | -  If the protocol of the   |
   |                  |           |         |    backend server group is  |
   |                  |           |         |    UDP, the parameter value |
   |                  |           |         |    can only be              |
   |                  |           |         |    **UDP_CONNECT**.         |
   |                  |           |         | -  If the protocol of the   |
   |                  |           |         |    backend server group is  |
   |                  |           |         |    TCP, the parameter value |
   |                  |           |         |    can be **TCP** or        |
   |                  |           |         |    **HTTP**.                |
   |                  |           |         | -  If the protocol of the   |
   |                  |           |         |    backend server group is  |
   |                  |           |         |    HTTP, the parameter      |
   |                  |           |         |    value can be **TCP** or  |
   |                  |           |         |    **HTTP**.                |
   +------------------+-----------+---------+-----------------------------+
   | monitor_port     | No        | Integer | Specifies the health check  |
   |                  |           |         | port. The port number       |
   |                  |           |         | ranges from 1 to 65535.     |
   |                  |           |         |                             |
   |                  |           |         | The value is left blank by  |
   |                  |           |         | default, indicating that    |
   |                  |           |         | the port of the backend     |
   |                  |           |         | server is used as the       |
   |                  |           |         | health check port.          |
   +------------------+-----------+---------+-----------------------------+
   | domain_name      | No        | String  | Specifies the domain name   |
   |                  |           |         | of HTTP requests during the |
   |                  |           |         | health check.               |
   |                  |           |         |                             |
   |                  |           |         | This parameter is valid     |
   |                  |           |         | only when the value of      |
   |                  |           |         | **type** is set to          |
   |                  |           |         | **HTTP**.                   |
   |                  |           |         |                             |
   |                  |           |         | The value is left blank by  |
   |                  |           |         | default, indicating that    |
   |                  |           |         | the private IP address of   |
   |                  |           |         | the load balancer is used   |
   |                  |           |         | as the destination address  |
   |                  |           |         | of HTTP requests.           |
   |                  |           |         |                             |
   |                  |           |         | The value can contain only  |
   |                  |           |         | digits, letters, hyphens    |
   |                  |           |         | (-), and periods (.) and    |
   |                  |           |         | must start with a digit or  |
   |                  |           |         | letter, for example,        |
   |                  |           |         | **www.test.com**.           |
   |                  |           |         |                             |
   |                  |           |         | The value contains a        |
   |                  |           |         | maximum of 100 characters.  |
   +------------------+-----------+---------+-----------------------------+
   | url_path         | No        | String  | Specifies the HTTP request  |
   |                  |           |         | path for the health check.  |
   |                  |           |         | The default value is **/**, |
   |                  |           |         | and the value must start    |
   |                  |           |         | with a slash (/).           |
   |                  |           |         |                             |
   |                  |           |         | This parameter is valid     |
   |                  |           |         | only when the value of      |
   |                  |           |         | **type** is set to          |
   |                  |           |         | **HTTP**.                   |
   |                  |           |         |                             |
   |                  |           |         | An example value is         |
   |                  |           |         | **/test**.                  |
   |                  |           |         |                             |
   |                  |           |         | The value contains a        |
   |                  |           |         | maximum of 255 characters.  |
   +------------------+-----------+---------+-----------------------------+
   | expected_codes   | No        | String  | Specifies the expected HTTP |
   |                  |           |         | status code. The following  |
   |                  |           |         | options are available:      |
   |                  |           |         |                             |
   |                  |           |         | A single value, such as     |
   |                  |           |         | **200**                     |
   |                  |           |         |                             |
   |                  |           |         | A list of values, such as   |
   |                  |           |         | **200,202**                 |
   |                  |           |         |                             |
   |                  |           |         | A value range, such as      |
   |                  |           |         | **200-204**                 |
   |                  |           |         |                             |
   |                  |           |         | This parameter is valid     |
   |                  |           |         | only when the value of      |
   |                  |           |         | **type** is set to          |
   |                  |           |         | **HTTP**.                   |
   |                  |           |         |                             |
   |                  |           |         | The value contains a        |
   |                  |           |         | maximum of 64 characters.   |
   |                  |           |         |                             |
   |                  |           |         | NOTE:                       |
   |                  |           |         | This parameter is reserved. |
   +------------------+-----------+---------+-----------------------------+
   | http_method      | No        | String  | Specifies the HTTP request  |
   |                  |           |         | method. The default value   |
   |                  |           |         | is **GET**.                 |
   |                  |           |         |                             |
   |                  |           |         | The value can be **GET**,   |
   |                  |           |         | **HEAD**, **POST**,         |
   |                  |           |         | **PUT**, **DELETE**,        |
   |                  |           |         | **TRACE**, **OPTIONS**,     |
   |                  |           |         | **CONNECT**, and **PATCH**. |
   |                  |           |         |                             |
   |                  |           |         | This parameter is valid     |
   |                  |           |         | only when the value of      |
   |                  |           |         | **type** is set to          |
   |                  |           |         | **HTTP**.                   |
   |                  |           |         |                             |
   |                  |           |         | NOTE:                       |
   |                  |           |         | This parameter is reserved. |
   +------------------+-----------+---------+-----------------------------+

Response
^^^^^^^^

.. table:: **Table 3** Response parameters

   +---------------+--------+--------------------------------------------------------------------------+
   | Parameter     | Type   | Description                                                              |
   +===============+========+==========================================================================+
   | healthmonitor | Object | Specifies the health check. For details, see :ref:`shared_hm_create_t4`. |
   +---------------+--------+--------------------------------------------------------------------------+

.. _shared_hm_create_t4:
.. table:: **Table 4** **healthmonitor** parameter description

   +------------------+---------+------------------------------------------------------------+
   | Parameter        | Type    | Description                                                |
   +==================+=========+============================================================+
   | id               | String  | Specifies the health check ID.                             |
   +------------------+---------+------------------------------------------------------------+
   | tenant_id        | String  | Specifies the ID of the project where                      |
   |                  |         | the health check is performed.                             |
   +------------------+---------+------------------------------------------------------------+
   | name             | String  | Specifies the health check name.                           |
   +------------------+---------+------------------------------------------------------------+
   | delay            | Integer | Specifies the maximum time between                         |
   |                  |         | health checks in the unit of second.                       |
   |                  |         | The value ranges from **1** to                             |
   |                  |         | **50**.                                                    |
   +------------------+---------+------------------------------------------------------------+
   | max_retries      | Integer | Specifies the number of consecutive                        |
   |                  |         | health checks when the health check                        |
   |                  |         | result of a backend server changes                         |
   |                  |         | from **OFFLINE** to **ONLINE**. The                        |
   |                  |         | value ranges from **1** to **10**.                         |
   +------------------+---------+------------------------------------------------------------+
   | max_retries_down | Integer | Specifies the number of consecutive                        |
   |                  |         | health checks when the health check                        |
   |                  |         | result of a backend server changes                         |
   |                  |         | from **ONLINE** to **OFFLINE**. The                        |
   |                  |         | value ranges from **1** to **10**.                         |
   +------------------+---------+------------------------------------------------------------+
   | pools            | Array   | Specifies the ID of the backend                            |
   |                  |         | server group associated with the                           |
   |                  |         | health check. For details, see :ref:`shared_hm_create_t5`. |
   +------------------+---------+------------------------------------------------------------+
   | admin_state_up   | Boolean | Specifies the administrative status                        |
   |                  |         | of the health check.                                       |
   |                  |         |                                                            |
   |                  |         | This parameter is reserved. The value                      |
   |                  |         | can be **true** or **false**.                              |
   |                  |         |                                                            |
   |                  |         | -  **true**: Enabled                                       |
   |                  |         | -  **false**: Disabled                                     |
   +------------------+---------+------------------------------------------------------------+
   | timeout          | Integer | Specifies the health check timeout                         |
   |                  |         | duration in the unit of second. The                        |
   |                  |         | value ranges from **1** to **50**.                         |
   |                  |         |                                                            |
   |                  |         | NOTE:                                                      |
   |                  |         | You are advised to set the value less                      |
   |                  |         | than that of parameter **delay**.                          |
   +------------------+---------+------------------------------------------------------------+
   | type             | String  | Specifies the health check protocol.                       |
   |                  |         |                                                            |
   |                  |         | The value can be **TCP**,                                  |
   |                  |         | **UDP_CONNECT**, or **HTTP**.                              |
   |                  |         |                                                            |
   |                  |         | The relationships between the value                        |
   |                  |         | of this parameter and the protocol of                      |
   |                  |         | the backend server group are as                            |
   |                  |         | follows:                                                   |
   |                  |         |                                                            |
   |                  |         | -  If the protocol of the backend                          |
   |                  |         |    server group is UDP, the parameter                      |
   |                  |         |    value can only be **UDP_CONNECT**.                      |
   |                  |         | -  If the protocol of the backend                          |
   |                  |         |    server group is TCP, the parameter                      |
   |                  |         |    value can be **TCP** or **HTTP**.                       |
   |                  |         | -  If the protocol of the backend                          |
   |                  |         |    server group is HTTP, the                               |
   |                  |         |    parameter value can be **TCP** or                       |
   |                  |         |    **HTTP**.                                               |
   +------------------+---------+------------------------------------------------------------+
   | monitor_port     | Integer | Specifies the health check port. The                       |
   |                  |         | port number ranges from 1 to 65535.                        |
   |                  |         |                                                            |
   |                  |         | The value is left blank by default,                        |
   |                  |         | indicating that the port of the                            |
   |                  |         | backend server is used as the health                       |
   |                  |         | check port.                                                |
   +------------------+---------+------------------------------------------------------------+
   | expected_codes   | String  | Specifies the expected HTTP status                         |
   |                  |         | code. The following options are                            |
   |                  |         | available:                                                 |
   |                  |         |                                                            |
   |                  |         | - A single value, such as **200**                          |
   |                  |         | - A list of values, such as **200,202**                    |
   |                  |         | - A value range, such as **200-204**                       |
   |                  |         |                                                            |
   |                  |         | This parameter is valid only when the                      |
   |                  |         | value of **type** is set to **HTTP**.                      |
   |                  |         |                                                            |
   |                  |         | Currently, this parameter is not                           |
   |                  |         | supported and is fixed at **200**.                         |
   +------------------+---------+------------------------------------------------------------+
   | domain_name      | String  | Specifies the domain name of HTTP                          |
   |                  |         | requests during the health check.                          |
   |                  |         |                                                            |
   |                  |         | This parameter is valid only when the                      |
   |                  |         | value of **type** is set to **HTTP**.                      |
   |                  |         |                                                            |
   |                  |         | The value is left blank by default,                        |
   |                  |         | indicating that the private IP                             |
   |                  |         | address of the load balancer is used                       |
   |                  |         | as the destination address of HTTP                         |
   |                  |         | requests.                                                  |
   |                  |         |                                                            |
   |                  |         | The value can contain only digits,                         |
   |                  |         | letters, hyphens (-), and periods (.)                      |
   |                  |         | and must start with a digit or                             |
   |                  |         | letter, for example,                                       |
   |                  |         | **www.test.com**.                                          |
   +------------------+---------+------------------------------------------------------------+
   | url_path         | String  | Specifies the HTTP request path for                        |
   |                  |         | the health check. The default value                        |
   |                  |         | is **/**, and the value must start                         |
   |                  |         | with a slash (/).                                          |
   |                  |         |                                                            |
   |                  |         | This parameter is valid only when the                      |
   |                  |         | value of **type** is set to **HTTP**.                      |
   |                  |         |                                                            |
   |                  |         | An example value is **/test**.                             |
   +------------------+---------+------------------------------------------------------------+
   | http_method      | String  | Specifies the HTTP request method.                         |
   |                  |         | The default value is **GET**.                              |
   |                  |         |                                                            |
   |                  |         | The value can be **GET**, **HEAD**,                        |
   |                  |         | **POST**, **PUT**, **DELETE**,                             |
   |                  |         | **TRACE**, **OPTIONS**, **CONNECT**,                       |
   |                  |         | and **PATCH**.                                             |
   |                  |         |                                                            |
   |                  |         | This parameter is valid only when the                      |
   |                  |         | value of **type** is set to **HTTP**.                      |
   |                  |         |                                                            |
   |                  |         | NOTE:                                                      |
   |                  |         | This parameter is reserved.                                |
   +------------------+---------+------------------------------------------------------------+

.. _shared_hm_create_t5:
.. table:: **Table 5** **pools** parameter description

   ========= ====== ========================================================
   Parameter Type   Description
   ========= ====== ========================================================
   id        String Specifies the ID of the associated backend server group.
   ========= ====== ========================================================

Example Request
^^^^^^^^^^^^^^^

-  Example request: Configuring a health check

   .. code::

      POST https://{Endpoint}/v2.0/lbaas/healthmonitors

      {
        "healthmonitor": {
          "admin_state_up": true,
          "pool_id": "bb44bffb-05d9-412c-9d9c-b189d9e14193",
          "domain_name": "www.test.com",
          "delay": 10,
          "max_retries": 10,
          "max_retries_down": 5,
          "timeout": 10,
          "type": "HTTP"
        }
      }

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   .. code::

      {
        "healthmonitor": {
          "name": "",
          "admin_state_up": true,
          "tenant_id": "145483a5107745e9b3d80f956713e6a3",
          "domain_name": "www.test.com",
          "delay": 10,
          "max_retries": 10,
          "expected_codes": "200",
          "max_retries_down": 5,
          "http_method": "GET",
          "timeout": 10,
          "pools": [
            {
              "id": "bb44bffb-05d9-412c-9d9c-b189d9e14193"
            }
          ],
          "url_path": "/",
          "type": "HTTP",
          "id": "2dca3867-98c5-4cde-8f2c-b89ae6bd7e36",
          "monitor_port": 112
        }
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Querying Health Checks
======================

Function
^^^^^^^^

This API is used to query the health checks. Filter query and pagination query are supported. Unless otherwise specified, exact match is applied.

URI
^^^

GET /v2.0/lbaas/healthmonitors

Constraints
^^^^^^^^^^^

Parameters **marker**, **limit**, and **page_reverse** are used for pagination query. Parameters **marker** and **page_reverse** take effect only when they are used together with parameter **limit**.

Request
^^^^^^^

.. table:: **Table 1** Parameter description

   +------------------+---------------+---------+-----------------------------+
   | Parameter        | **Mandatory** | Type    | Description                 |
   +==================+===============+=========+=============================+
   | marker           | No            | String  | Specifies the ID of the     |
   |                  |               |         | health check from which     |
   |                  |               |         | pagination query starts,    |
   |                  |               |         | that is, the ID of the last |
   |                  |               |         | health check on the         |
   |                  |               |         | previous page.              |
   |                  |               |         |                             |
   |                  |               |         | This parameter must be used |
   |                  |               |         | together with **limit**.    |
   +------------------+---------------+---------+-----------------------------+
   | limit            | No            | Integer | Specifies the number of     |
   |                  |               |         | health checks on each page. |
   |                  |               |         | If this parameter is not    |
   |                  |               |         | set, all health checks are  |
   |                  |               |         | queried by default.         |
   +------------------+---------------+---------+-----------------------------+
   | page_reverse     | No            | Boolean | Specifies the page          |
   |                  |               |         | direction. The value can be |
   |                  |               |         | **true** or **false**, and  |
   |                  |               |         | the default value is        |
   |                  |               |         | **false**. The last page in |
   |                  |               |         | the list requested with     |
   |                  |               |         | **page_reverse** set to     |
   |                  |               |         | **false** will not contain  |
   |                  |               |         | the "next" link, and the    |
   |                  |               |         | last page in the list       |
   |                  |               |         | requested with              |
   |                  |               |         | **page_reverse** set to     |
   |                  |               |         | **true** will not contain   |
   |                  |               |         | the "previous" link.        |
   |                  |               |         |                             |
   |                  |               |         | This parameter must be used |
   |                  |               |         | together with **limit**.    |
   +------------------+---------------+---------+-----------------------------+
   | id               | No            | String  | Specifies the health check  |
   |                  |               |         | ID.                         |
   +------------------+---------------+---------+-----------------------------+
   | tenant_id        | No            | String  | Specifies the ID of the     |
   |                  |               |         | project where the health    |
   |                  |               |         | check is performed.         |
   |                  |               |         |                             |
   |                  |               |         | The value contains a        |
   |                  |               |         | maximum of 255 characters.  |
   +------------------+---------------+---------+-----------------------------+
   | name             | No            | String  | Specifies the health check  |
   |                  |               |         | name.                       |
   |                  |               |         |                             |
   |                  |               |         | The value contains a        |
   |                  |               |         | maximum of 255 characters.  |
   +------------------+---------------+---------+-----------------------------+
   | delay            | No            | Integer | Specifies the maximum time  |
   |                  |               |         | between health checks in    |
   |                  |               |         | the unit of second. The     |
   |                  |               |         | value ranges from **1** to  |
   |                  |               |         | **50**.                     |
   +------------------+---------------+---------+-----------------------------+
   | max_retries      | No            | Integer | Specifies the number of     |
   |                  |               |         | consecutive health checks   |
   |                  |               |         | when the health check       |
   |                  |               |         | result of a backend server  |
   |                  |               |         | changes from **OFFLINE** to |
   |                  |               |         | **ONLINE**. The value       |
   |                  |               |         | ranges from **1** to        |
   |                  |               |         | **10**.                     |
   +------------------+---------------+---------+-----------------------------+
   | max_retries_down | No            | Integer | Specifies the number of     |
   |                  |               |         | consecutive health checks   |
   |                  |               |         | when the health check       |
   |                  |               |         | result of a backend server  |
   |                  |               |         | changes from **ONLINE** to  |
   |                  |               |         | **OFFLINE**. The value      |
   |                  |               |         | ranges from **1** to        |
   |                  |               |         | **10**.                     |
   +------------------+---------------+---------+-----------------------------+
   | admin_state_up   | No            | Boolean | Specifies the               |
   |                  |               |         | administrative status of    |
   |                  |               |         | the health check.           |
   |                  |               |         |                             |
   |                  |               |         | This parameter is reserved, |
   |                  |               |         | and the default value is    |
   |                  |               |         | **true**.                   |
   +------------------+---------------+---------+-----------------------------+
   | timeout          | No            | Integer | Specifies the health check  |
   |                  |               |         | timeout duration in the     |
   |                  |               |         | unit of second. The value   |
   |                  |               |         | ranges from **1** to        |
   |                  |               |         | **50**.                     |
   |                  |               |         |                             |
   |                  |               |         | NOTE:                       |
   |                  |               |         | You are advised to set the  |
   |                  |               |         | value less than that of     |
   |                  |               |         | parameter **delay**.        |
   +------------------+---------------+---------+-----------------------------+
   | type             | No            | String  | Specifies the health check  |
   |                  |               |         | protocol.                   |
   |                  |               |         |                             |
   |                  |               |         | The value can be **TCP**,   |
   |                  |               |         | **UDP_CONNECT**, or         |
   |                  |               |         | **HTTP**.                   |
   +------------------+---------------+---------+-----------------------------+
   | monitor_port     | No            | Integer | Specifies the port used for |
   |                  |               |         | the health check.           |
   |                  |               |         |                             |
   |                  |               |         | The value is left blank by  |
   |                  |               |         | default, indicating that    |
   |                  |               |         | the port of the backend     |
   |                  |               |         | server is used as the       |
   |                  |               |         | health check port.          |
   +------------------+---------------+---------+-----------------------------+
   | expected_codes   | No            | String  | Specifies the expected HTTP |
   |                  |               |         | status code. The following  |
   |                  |               |         | options are available:      |
   |                  |               |         |                             |
   |                  |               |         | A single value, such as     |
   |                  |               |         | **200**                     |
   |                  |               |         |                             |
   |                  |               |         | A list of values, such as   |
   |                  |               |         | **200,202**                 |
   |                  |               |         |                             |
   |                  |               |         | A value range, such as      |
   |                  |               |         | **200-204**                 |
   |                  |               |         |                             |
   |                  |               |         | This parameter is valid     |
   |                  |               |         | only when the value of      |
   |                  |               |         | **type** is set to          |
   |                  |               |         | **HTTP**.                   |
   |                  |               |         |                             |
   |                  |               |         | The value contains a        |
   |                  |               |         | maximum of 64 characters.   |
   |                  |               |         |                             |
   |                  |               |         | NOTE:                       |
   |                  |               |         | This parameter is reserved. |
   +------------------+---------------+---------+-----------------------------+
   | domain_name      | No            | String  | Specifies the domain name   |
   |                  |               |         | of HTTP requests during the |
   |                  |               |         | health check.               |
   |                  |               |         |                             |
   |                  |               |         | This parameter is valid     |
   |                  |               |         | only when the value of      |
   |                  |               |         | **type** is set to          |
   |                  |               |         | **HTTP**.                   |
   |                  |               |         |                             |
   |                  |               |         | The value is left blank by  |
   |                  |               |         | default, indicating that    |
   |                  |               |         | the private IP address of   |
   |                  |               |         | the load balancer is used   |
   |                  |               |         | as the destination address  |
   |                  |               |         | of HTTP requests.           |
   |                  |               |         |                             |
   |                  |               |         | The value can contain only  |
   |                  |               |         | digits, letters, hyphens    |
   |                  |               |         | (-), and periods (.) and    |
   |                  |               |         | must start with a digit or  |
   |                  |               |         | letter, for example,        |
   |                  |               |         | **www.test.com**.           |
   |                  |               |         |                             |
   |                  |               |         | The value contains a        |
   |                  |               |         | maximum of 100 characters.  |
   +------------------+---------------+---------+-----------------------------+
   | url_path         | No            | String  | Specifies the HTTP request  |
   |                  |               |         | path for the health check.  |
   |                  |               |         | The default value is **/**, |
   |                  |               |         | and the value must start    |
   |                  |               |         | with a slash (/).           |
   |                  |               |         |                             |
   |                  |               |         | This parameter is valid     |
   |                  |               |         | only when the value of      |
   |                  |               |         | **type** is set to          |
   |                  |               |         | **HTTP**.                   |
   |                  |               |         |                             |
   |                  |               |         | An example value is         |
   |                  |               |         | **/test**.                  |
   |                  |               |         |                             |
   |                  |               |         | The value contains a        |
   |                  |               |         | maximum of 255 characters.  |
   +------------------+---------------+---------+-----------------------------+
   | http_method      | No            | String  | Specifies the HTTP request  |
   |                  |               |         | method. The default value   |
   |                  |               |         | is **GET**.                 |
   |                  |               |         |                             |
   |                  |               |         | The value can be **GET**,   |
   |                  |               |         | **HEAD**, **POST**,         |
   |                  |               |         | **PUT**, **DELETE**,        |
   |                  |               |         | **TRACE**, **OPTIONS**,     |
   |                  |               |         | **CONNECT**, and **PATCH**. |
   |                  |               |         |                             |
   |                  |               |         | This parameter is valid     |
   |                  |               |         | only when the value of      |
   |                  |               |         | **type** is set to          |
   |                  |               |         | **HTTP**.                   |
   |                  |               |         |                             |
   |                  |               |         | NOTE:                       |
   |                  |               |         | This parameter is reserved. |
   +------------------+---------------+---------+-----------------------------+

Response
^^^^^^^^

.. table:: **Table 2** Response parameters

   +----------------------+-------+--------------------------------------------+
   | Parameter            | Type  | Description                                |
   +======================+=======+============================================+
   | healthmonitors       | Array | Lists the health checks. For details,      |
   |                      |       | see :ref:`shared_hm_list_t3`.              |
   +----------------------+-------+--------------------------------------------+
   | healthmonitors_links | Array | Provides links to the previous or          |
   |                      |       | next page during pagination query,         |
   |                      |       | respectively.                              |
   |                      |       |                                            |
   |                      |       | This parameter exists only in the          |
   |                      |       | response body of pagination query.         |
   |                      |       |                                            |
   |                      |       | For details, see :ref:`shared_hm_list_t5`. |
   +----------------------+-------+--------------------------------------------+

.. _shared_hm_list_t3:
.. table:: **Table 3** **healthmonitors** parameter description

   +------------------+---------+---------------------------------------+
   | Parameter        | Type    | Description                           |
   +==================+=========+=======================================+
   | id               | String  | Specifies the health check ID.        |
   +------------------+---------+---------------------------------------+
   | tenant_id        | String  | Specifies the ID of the project where |
   |                  |         | the health check is performed.        |
   +------------------+---------+---------------------------------------+
   | name             | String  | Specifies the health check name.      |
   |                  |         |                                       |
   |                  |         | The value contains a maximum of 255   |
   |                  |         | characters.                           |
   +------------------+---------+---------------------------------------+
   | delay            | Integer | Specifies the maximum time between    |
   |                  |         | health checks in the unit of second.  |
   |                  |         | The value ranges from **1** to        |
   |                  |         | **50**.                               |
   +------------------+---------+---------------------------------------+
   | max_retries      | Integer | Specifies the number of consecutive   |
   |                  |         | health checks when the health check   |
   |                  |         | result of a backend server changes    |
   |                  |         | from **OFFLINE** to **ONLINE**.       |
   |                  |         |                                       |
   |                  |         | The value ranges from **1** to        |
   |                  |         | **10**.                               |
   +------------------+---------+---------------------------------------+
   | max_retries_down | Integer | Specifies the number of consecutive   |
   |                  |         | health checks when the health check   |
   |                  |         | result of a backend server changes    |
   |                  |         | from **ONLINE** to **OFFLINE**.       |
   |                  |         |                                       |
   |                  |         | The value ranges from **1** to        |
   |                  |         | **10**.                               |
   +------------------+---------+---------------------------------------+
   | pools            | Array   | Lists the IDs of backend server       |
   |                  |         | groups associated with the health     |
   |                  |         | check.                                |
   +------------------+---------+---------------------------------------+
   | admin_state_up   | Boolean | Specifies the administrative status   |
   |                  |         | of the health check.                  |
   |                  |         |                                       |
   |                  |         | This parameter is reserved. The value |
   |                  |         | can be **true** or **false**.         |
   |                  |         |                                       |
   |                  |         | -  **true**: Enabled                  |
   |                  |         | -  **false**: Disabled                |
   +------------------+---------+---------------------------------------+
   | timeout          | Integer | Specifies the health check timeout    |
   |                  |         | duration in the unit of second. The   |
   |                  |         | value ranges from **1** to **50**.    |
   |                  |         |                                       |
   |                  |         | NOTE:                                 |
   |                  |         | You are advised to set the value less |
   |                  |         | than that of parameter **delay**.     |
   +------------------+---------+---------------------------------------+
   | type             | String  | Specifies the health check protocol.  |
   |                  |         |                                       |
   |                  |         | The value can be **TCP**,             |
   |                  |         | **UDP_CONNECT**, or **HTTP**.         |
   +------------------+---------+---------------------------------------+
   | monitor_port     | Integer | Specifies the health check port. The  |
   |                  |         | port number ranges from 1 to 65535.   |
   |                  |         |                                       |
   |                  |         | The value is left blank by default,   |
   |                  |         | indicating that the port of the       |
   |                  |         | backend server is used as the health  |
   |                  |         | check port.                           |
   +------------------+---------+---------------------------------------+
   | expected_codes   | String  | Specifies the expected HTTP status    |
   |                  |         | code. The following options are       |
   |                  |         | available:                            |
   |                  |         |                                       |
   |                  |         | A single value, such as **200**       |
   |                  |         |                                       |
   |                  |         | A list of values, such as **200,202** |
   |                  |         |                                       |
   |                  |         | A value range, such as **200-204**    |
   |                  |         |                                       |
   |                  |         | This parameter is valid only when the |
   |                  |         | value of **type** is set to **HTTP**. |
   |                  |         |                                       |
   |                  |         | The value contains a maximum of 64    |
   |                  |         | characters.                           |
   +------------------+---------+---------------------------------------+
   | domain_name      | String  | Specifies the domain name of HTTP     |
   |                  |         | requests during the health check.     |
   |                  |         |                                       |
   |                  |         | This parameter is valid only when the |
   |                  |         | value of **type** is set to **HTTP**. |
   |                  |         |                                       |
   |                  |         | The value is left blank by default,   |
   |                  |         | indicating that the private IP        |
   |                  |         | address of the load balancer is used  |
   |                  |         | as the destination address of HTTP    |
   |                  |         | requests.                             |
   |                  |         |                                       |
   |                  |         | The value can contain only digits,    |
   |                  |         | letters, hyphens (-), and periods (.) |
   |                  |         | and must start with a digit or        |
   |                  |         | letter, for example,                  |
   |                  |         | **www.test.com**.                     |
   |                  |         |                                       |
   |                  |         | The value contains a maximum of 100   |
   |                  |         | characters.                           |
   +------------------+---------+---------------------------------------+
   | url_path         | String  | Specifies the HTTP request path for   |
   |                  |         | the health check. The default value   |
   |                  |         | is **/**, and the value must start    |
   |                  |         | with a slash (/).                     |
   |                  |         |                                       |
   |                  |         | This parameter is valid only when the |
   |                  |         | value of **type** is set to **HTTP**. |
   |                  |         |                                       |
   |                  |         | An example value is **/test**.        |
   |                  |         |                                       |
   |                  |         | The value contains a maximum of 255   |
   |                  |         | characters.                           |
   +------------------+---------+---------------------------------------+
   | http_method      | String  | Specifies the HTTP request method.    |
   |                  |         | The default value is **GET**.         |
   |                  |         |                                       |
   |                  |         | The value can be **GET**, **HEAD**,   |
   |                  |         | **POST**, **PUT**, **DELETE**,        |
   |                  |         | **TRACE**, **OPTIONS**, **CONNECT**,  |
   |                  |         | and **PATCH**.                        |
   |                  |         |                                       |
   |                  |         | This parameter is valid only when the |
   |                  |         | value of **type** is set to **HTTP**. |
   |                  |         |                                       |
   |                  |         | NOTE:                                 |
   |                  |         | This parameter is reserved.           |
   +------------------+---------+---------------------------------------+

.. _shared_hm_list_t4:
.. table:: **Table 4** **pools** parameter description

   ========= ====== ========================================================
   Parameter Type   Description
   ========= ====== ========================================================
   id        String Specifies the ID of the associated backend server group.
   ========= ====== ========================================================

.. _shared_hm_list_t5:
.. table:: **Table 5** **healthmonitors_links** parameter description

   +-----------+--------+---------------------------------------+
   | Parameter | Type   | Description                           |
   +===========+========+=======================================+
   | href      | String | Provides links to the previous or     |
   |           |        | next page during pagination query,    |
   |           |        | respectively.                         |
   +-----------+--------+---------------------------------------+
   | rel       | String | Specifies the prompt of the previous  |
   |           |        | or next page.                         |
   |           |        |                                       |
   |           |        | The value can be **next** or          |
   |           |        | **previous**. The value **next**      |
   |           |        | indicates the href containing the URL |
   |           |        | of the next page, and **previous**    |
   |           |        | indicates the href containing the URL |
   |           |        | of the previous page.                 |
   +-----------+--------+---------------------------------------+

Example Request
^^^^^^^^^^^^^^^

-  Example request 1: Querying all health checks

   .. code::

      GET https://{Endpoint}/v2.0/lbaas/healthmonitors

-  Example request 2: Querying HTTP health checks

   .. code::

      GET https://{Endpoint}/v2.0/lbaas/healthmonitors?type=HTTP

Example Response
^^^^^^^^^^^^^^^^

-  Example response 1

   .. code::

      {
          "healthmonitors": [
              {
                  "monitor_port": null,
                  "name": "",
                  "admin_state_up": true,
                  "tenant_id": "601240b9c5c94059b63d484c92cfe308",

                  "domain_name": null,
                  "delay": 5,

                  "max_retries": 3,
                  "max_retries_down": 5,
                  "http_method": "GET",
                  "timeout": 10,
                  "pools": [
                      {
                          "id": "caef8316-6b65-4676-8293-cf41fb63cc2a"
                      }
                  ],
                  "url_path": "/",
                  "type": "HTTP",
                  "id": "1b587819-d619-49c1-9101-fe72d8b361ef"
              }
          ]
      }

-  Example response 2

   .. code::

      {
          "healthmonitors": [
              {
                  "monitor_port": null,
                  "name": "",
                  "admin_state_up": true,
                  "tenant_id": "601240b9c5c94059b63d484c92cfe308",
                  "domain_name": null,
                  "delay": 5,
                  "expected_codes": "200-204,300-302,401",
                  "max_retries": 3,
                  "max_retries_down": 5,
                  "http_method": "GET",
                  "timeout": 10,
                  "pools": [
                      {
                          "id": "caef8316-6b65-4676-8293-cf41fb63cc2a"
                      }
                  ],
                  "url_path": "/",
                  "type": "HTTP",
                  "id": "1b587819-d619-49c1-9101-fe72d8b361ef"
              }
          ]
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Querying Details of a Health Check
==================================

Function
^^^^^^^^

This API is used to query details about a health check using its iD.

URI
^^^

GET /v2.0/lbaas/healthmonitors/{healthmonitor_id}

.. table:: **Table 1** Parameter description

   ================ ========= ====== ==============================
   Parameter        Mandatory Type   Description
   ================ ========= ====== ==============================
   healthmonitor_id Yes       String Specifies the health check ID.
   ================ ========= ====== ==============================

Request
^^^^^^^

None

Response
^^^^^^^^

.. table:: **Table 2** Response parameters

   +---------------+--------+------------------------------------------------------------------------+
   | Parameter     | Type   | Description                                                            |
   +===============+========+========================================================================+
   | healthmonitor | Object | Specifies the health check. For details, see :ref:`shared_hm_show_t3`. |
   +---------------+--------+------------------------------------------------------------------------+

.. _shared_hm_show_t3:
.. table:: **Table 3** **healthmonitor** parameter description

   +------------------+---------+----------------------------------------------------------+
   | Parameter        | Type    | Description                                              |
   +==================+=========+==========================================================+
   | id               | String  | Specifies the health check ID.                           |
   +------------------+---------+----------------------------------------------------------+
   | tenant_id        | String  | Specifies the ID of the project where                    |
   |                  |         | the health check is performed.                           |
   +------------------+---------+----------------------------------------------------------+
   | name             | String  | Specifies the health check name.                         |
   +------------------+---------+----------------------------------------------------------+
   | delay            | Integer | Specifies the maximum time between                       |
   |                  |         | health checks in the unit of second.                     |
   |                  |         | The value ranges from **1** to                           |
   |                  |         | **50**.                                                  |
   +------------------+---------+----------------------------------------------------------+
   | max_retries      | Integer | Specifies the number of consecutive                      |
   |                  |         | health checks when the health check                      |
   |                  |         | result of a backend server changes                       |
   |                  |         | from **OFFLINE** to **ONLINE**. The                      |
   |                  |         | value ranges from **1** to **10**.                       |
   +------------------+---------+----------------------------------------------------------+
   | max_retries_down | Integer | Specifies the number of consecutive                      |
   |                  |         | health checks when the health check                      |
   |                  |         | result of a backend server changes                       |
   |                  |         | from **ONLINE** to **OFFLINE**. The                      |
   |                  |         | value ranges from **1** to **10**.                       |
   +------------------+---------+----------------------------------------------------------+
   | pools            | Array   | Specifies the ID of the backend                          |
   |                  |         | server group associated with the                         |
   |                  |         | health check. For details, see :ref:`shared_hm_show_t4`. |
   +------------------+---------+----------------------------------------------------------+
   | admin_state_up   | Boolean | Specifies the administrative status                      |
   |                  |         | of the health check.                                     |
   |                  |         |                                                          |
   |                  |         | This parameter is reserved. The value                    |
   |                  |         | can be **true** or **false**.                            |
   |                  |         |                                                          |
   |                  |         | -  **true**: Enabled                                     |
   |                  |         | -  **false**: Disabled                                   |
   +------------------+---------+----------------------------------------------------------+
   | timeout          | Integer | Specifies the health check timeout                       |
   |                  |         | duration in the unit of second. The                      |
   |                  |         | value ranges from **1** to **50**.                       |
   |                  |         |                                                          |
   |                  |         | NOTE:                                                    |
   |                  |         | You are advised to set the value less                    |
   |                  |         | than that of parameter **delay**.                        |
   +------------------+---------+----------------------------------------------------------+
   | type             | String  | Specifies the health check protocol.                     |
   |                  |         |                                                          |
   |                  |         | The value can be **TCP**,                                |
   |                  |         | **UDP_CONNECT**, or **HTTP**.                            |
   |                  |         |                                                          |
   |                  |         | The relationships between the value                      |
   |                  |         | of this parameter and the protocol of                    |
   |                  |         | the backend server group are as                          |
   |                  |         | follows:                                                 |
   |                  |         |                                                          |
   |                  |         | -  If the protocol of the backend                        |
   |                  |         |    server group is UDP, the parameter                    |
   |                  |         |    value can only be **UDP_CONNECT**.                    |
   |                  |         | -  If the protocol of the backend                        |
   |                  |         |    server group is TCP, the parameter                    |
   |                  |         |    value can be **TCP** or **HTTP**.                     |
   |                  |         | -  If the protocol of the backend                        |
   |                  |         |    server group is HTTP, the                             |
   |                  |         |    parameter value can be **TCP** or                     |
   |                  |         |    **HTTP**.                                             |
   +------------------+---------+----------------------------------------------------------+
   | monitor_port     | Integer | Specifies the health check port. The                     |
   |                  |         | port number ranges from 1 to 65535.                      |
   |                  |         |                                                          |
   |                  |         | The value is left blank by default,                      |
   |                  |         | indicating that the port of the                          |
   |                  |         | backend server is used as the health                     |
   |                  |         | check port.                                              |
   +------------------+---------+----------------------------------------------------------+
   | expected_codes   | String  | Specifies the expected HTTP status                       |
   |                  |         | code. The following options are                          |
   |                  |         | available:                                               |
   |                  |         |                                                          |
   |                  |         | A single value, such as **200**                          |
   |                  |         |                                                          |
   |                  |         | A list of values, such as **200,202**                    |
   |                  |         |                                                          |
   |                  |         | A value range, such as **200-204**                       |
   |                  |         |                                                          |
   |                  |         | This parameter is valid only when the                    |
   |                  |         | value of **type** is set to **HTTP**.                    |
   |                  |         |                                                          |
   |                  |         | Currently, this parameter is not                         |
   |                  |         | supported and is fixed at **200**.                       |
   +------------------+---------+----------------------------------------------------------+
   | domain_name      | String  | Specifies the domain name of HTTP                        |
   |                  |         | requests during the health check.                        |
   |                  |         |                                                          |
   |                  |         | This parameter is valid only when the                    |
   |                  |         | value of **type** is set to **HTTP**.                    |
   |                  |         |                                                          |
   |                  |         | The value is left blank by default,                      |
   |                  |         | indicating that the private IP                           |
   |                  |         | address of the load balancer is used                     |
   |                  |         | as the destination address of HTTP                       |
   |                  |         | requests.                                                |
   |                  |         |                                                          |
   |                  |         | The value can contain only digits,                       |
   |                  |         | letters, hyphens (-), and periods (.)                    |
   |                  |         | and must start with a digit or                           |
   |                  |         | letter, for example,                                     |
   |                  |         | **www.test.com**.                                        |
   +------------------+---------+----------------------------------------------------------+
   | url_path         | String  | Specifies the HTTP request path for                      |
   |                  |         | the health check. The default value                      |
   |                  |         | is **/**, and the value must start                       |
   |                  |         | with a slash (/).                                        |
   |                  |         |                                                          |
   |                  |         | This parameter is valid only when the                    |
   |                  |         | value of **type** is set to **HTTP**.                    |
   |                  |         |                                                          |
   |                  |         | An example value is **/test**.                           |
   +------------------+---------+----------------------------------------------------------+
   | http_method      | String  | Specifies the HTTP request method.                       |
   |                  |         | The default value is **GET**.                            |
   |                  |         |                                                          |
   |                  |         | The value can be **GET**, **HEAD**,                      |
   |                  |         | **POST**, **PUT**, **DELETE**,                           |
   |                  |         | **TRACE**, **OPTIONS**, **CONNECT**,                     |
   |                  |         | and **PATCH**.                                           |
   |                  |         |                                                          |
   |                  |         | This parameter is valid only when the                    |
   |                  |         | value of **type** is set to **HTTP**.                    |
   |                  |         |                                                          |
   |                  |         | NOTE:                                                    |
   |                  |         | This parameter is reserved.                              |
   +------------------+---------+----------------------------------------------------------+

.. _shared_hm_show_t4:
.. table:: **Table 4** **pools** parameter description

   ========= ====== ========================================================
   Parameter Type   Description
   ========= ====== ========================================================
   id        String Specifies the ID of the associated backend server group.
   ========= ====== ========================================================

Example Request
^^^^^^^^^^^^^^^

-  Example request: Querying details of a health check

   .. code::

      GET https://{Endpoint}/v2.0/lbaas/healthmonitors/b7633ade-24dc-4d72-8475-06aa22be5412

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   .. code::

      {
        "healthmonitor": {
          "name": "",
          "admin_state_up": true,
          "tenant_id": "145483a5107745e9b3d80f956713e6a3",
          "domain_name": null,
          "delay": 10,
          "expected_codes": "200-204,300-302,401",
          "max_retries": 10,
          "max_retries_down": 5,
          "http_method": "GET",
          "timeout": 10,
          "pools": [
            {
              "id": "bb44bffb-05d9-412c-9d9c-b189d9e14193"
            }
          ],
          "url_path": "/",
          "type": "HTTP",
          "id": "61c24cba-19bb-45c1-a013-7565e5f98872",
          "monitor_port": 112
        }
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Updating a Health Check
=======================

Function
^^^^^^^^

This API is used to update a health check.

Constraints
^^^^^^^^^^^

If **provisioning_status** of the load balancer for which the health check is configured is not **ACTIVE**, the health check cannot be updated.

URI
^^^

PUT /v2.0/lbaas/healthmonitors/{healthmonitor_id}

.. table:: **Table 1** Parameter description

   ================ ========= ====== ==============================
   Parameter        Mandatory Type   Description
   ================ ========= ====== ==============================
   healthmonitor_id Yes       String Specifies the health check ID.
   ================ ========= ====== ==============================

Request
^^^^^^^

.. table:: **Table 2** Parameter description

   +---------------+-----------+--------+--------------------------------------------------------------------------+
   | Parameter     | Mandatory | Type   | Description                                                              |
   +===============+===========+========+==========================================================================+
   | healthmonitor | Yes       | Object | Specifies the health check. For details, see :ref:`shared_hm_update_t3`. |
   +---------------+-----------+--------+--------------------------------------------------------------------------+

.. _shared_hm_update_t3:
.. table:: **Table 3** **healthmonitor** parameter description

   +------------------+-----------+---------+-----------------------------+
   | Parameter        | Mandatory | Type    | Description                 |
   +==================+===========+=========+=============================+
   | name             | No        | String  | Specifies the health check  |
   |                  |           |         | name.                       |
   |                  |           |         |                             |
   |                  |           |         | The value contains a        |
   |                  |           |         | maximum of 255 characters.  |
   +------------------+-----------+---------+-----------------------------+
   | delay            | No        | Integer | Specifies the maximum time  |
   |                  |           |         | between health checks in    |
   |                  |           |         | the unit of second. The     |
   |                  |           |         | value ranges from **1** to  |
   |                  |           |         | **50**.                     |
   +------------------+-----------+---------+-----------------------------+
   | max_retries      | No        | Integer | Specifies the number of     |
   |                  |           |         | consecutive health checks   |
   |                  |           |         | when the health check       |
   |                  |           |         | result of a backend server  |
   |                  |           |         | changes from **OFFLINE** to |
   |                  |           |         | **ONLINE**. The value       |
   |                  |           |         | ranges from **1** to        |
   |                  |           |         | **10**.                     |
   +------------------+-----------+---------+-----------------------------+
   | max_retries_down | No        | Integer | Specifies the number of     |
   |                  |           |         | consecutive health checks   |
   |                  |           |         | when the health check       |
   |                  |           |         | result of a backend server  |
   |                  |           |         | changes from **ONLINE** to  |
   |                  |           |         | **OFFLINE**. The value      |
   |                  |           |         | ranges from **1** to        |
   |                  |           |         | **10**.                     |
   +------------------+-----------+---------+-----------------------------+
   | admin_state_up   | No        | Boolean | Specifies the               |
   |                  |           |         | administrative status of    |
   |                  |           |         | the health check.           |
   |                  |           |         |                             |
   |                  |           |         | This parameter is reserved, |
   |                  |           |         | and the default value is    |
   |                  |           |         | **true**.                   |
   +------------------+-----------+---------+-----------------------------+
   | timeout          | No        | Integer | Specifies the health check  |
   |                  |           |         | timeout duration in the     |
   |                  |           |         | unit of second. The value   |
   |                  |           |         | ranges from **1** to        |
   |                  |           |         | **50**.                     |
   |                  |           |         |                             |
   |                  |           |         | NOTE:                       |
   |                  |           |         | You are advised to set the  |
   |                  |           |         | value less than that of     |
   |                  |           |         | parameter **delay**.        |
   +------------------+-----------+---------+-----------------------------+
   | type             | No        | String  | Specifies the health check  |
   |                  |           |         | protocol.                   |
   |                  |           |         |                             |
   |                  |           |         | The value can be **TCP**,   |
   |                  |           |         | **UDP_CONNECT**, or         |
   |                  |           |         | **HTTP**.                   |
   +------------------+-----------+---------+-----------------------------+
   | monitor_port     | No        | Integer | Specifies the health check  |
   |                  |           |         | port. The port number       |
   |                  |           |         | ranges from 1 to 65535.     |
   |                  |           |         |                             |
   |                  |           |         | The value is left blank by  |
   |                  |           |         | default, indicating that    |
   |                  |           |         | the port of the backend     |
   |                  |           |         | server is used as the       |
   |                  |           |         | health check port.          |
   +------------------+-----------+---------+-----------------------------+
   | expected_codes   | No        | String  | Specifies the expected HTTP |
   |                  |           |         | status code. The following  |
   |                  |           |         | options are available:      |
   |                  |           |         |                             |
   |                  |           |         | A single value, such as     |
   |                  |           |         | **200**                     |
   |                  |           |         |                             |
   |                  |           |         | A list of values, such as   |
   |                  |           |         | **200,202**                 |
   |                  |           |         |                             |
   |                  |           |         | A value range, such as      |
   |                  |           |         | **200-204**                 |
   |                  |           |         |                             |
   |                  |           |         | This parameter is valid     |
   |                  |           |         | only when the value of      |
   |                  |           |         | **type** is set to          |
   |                  |           |         | **HTTP**.                   |
   +------------------+-----------+---------+-----------------------------+
   | domain_name      | No        | String  | Specifies the domain name   |
   |                  |           |         | of HTTP requests during the |
   |                  |           |         | health check.               |
   |                  |           |         |                             |
   |                  |           |         | This parameter is valid     |
   |                  |           |         | only when the value of      |
   |                  |           |         | **type** is set to          |
   |                  |           |         | **HTTP**.                   |
   |                  |           |         |                             |
   |                  |           |         | The value is left blank by  |
   |                  |           |         | default, indicating that    |
   |                  |           |         | the private IP address of   |
   |                  |           |         | the load balancer is used   |
   |                  |           |         | as the destination address  |
   |                  |           |         | of HTTP requests.           |
   |                  |           |         |                             |
   |                  |           |         | The value can contain only  |
   |                  |           |         | digits, letters, hyphens    |
   |                  |           |         | (-), and periods (.) and    |
   |                  |           |         | must start with a digit or  |
   |                  |           |         | letter, for example,        |
   |                  |           |         | **www.test.com**.           |
   |                  |           |         |                             |
   |                  |           |         | The value contains a        |
   |                  |           |         | maximum of 100 characters.  |
   +------------------+-----------+---------+-----------------------------+
   | url_path         | No        | String  | Specifies the HTTP request  |
   |                  |           |         | path for the health check.  |
   |                  |           |         | The default value is **/**, |
   |                  |           |         | and the value must start    |
   |                  |           |         | with a slash (/).           |
   |                  |           |         |                             |
   |                  |           |         | This parameter is valid     |
   |                  |           |         | only when the value of      |
   |                  |           |         | **type** is set to          |
   |                  |           |         | **HTTP**.                   |
   |                  |           |         |                             |
   |                  |           |         | An example value is         |
   |                  |           |         | **/test**.                  |
   |                  |           |         |                             |
   |                  |           |         | The value contains a        |
   |                  |           |         | maximum of 255 characters.  |
   +------------------+-----------+---------+-----------------------------+
   | http_method      | No        | String  | Specifies the HTTP request  |
   |                  |           |         | method. The default value   |
   |                  |           |         | is **GET**.                 |
   |                  |           |         |                             |
   |                  |           |         | The value can be **GET**,   |
   |                  |           |         | **HEAD**, **POST**,         |
   |                  |           |         | **PUT**, **DELETE**,        |
   |                  |           |         | **TRACE**, **OPTIONS**,     |
   |                  |           |         | **CONNECT**, and **PATCH**. |
   |                  |           |         |                             |
   |                  |           |         | This parameter is valid     |
   |                  |           |         | only when the value of      |
   |                  |           |         | **type** is set to          |
   |                  |           |         | **HTTP**.                   |
   |                  |           |         |                             |
   |                  |           |         | NOTE:                       |
   |                  |           |         | This parameter is reserved. |
   +------------------+-----------+---------+-----------------------------+

Response
^^^^^^^^

.. table:: **Table 4** Response parameters

   +---------------+--------+--------------------------------------------------------------------------+
   | Parameter     | Type   | Description                                                              |
   +===============+========+==========================================================================+
   | healthmonitor | Object | Specifies the health check. For details, see :ref:`shared_hm_update_t5`. |
   +---------------+--------+--------------------------------------------------------------------------+

.. _shared_hm_update_t5:
.. table:: **Table 5** **healthmonitor** parameter description

   +------------------+---------+------------------------------------------------------------+
   | Parameter        | Type    | Description                                                |
   +==================+=========+============================================================+
   | id               | String  | Specifies the health check ID.                             |
   +------------------+---------+------------------------------------------------------------+
   | tenant_id        | String  | Specifies the ID of the project where                      |
   |                  |         | the health check is performed.                             |
   +------------------+---------+------------------------------------------------------------+
   | name             | String  | Specifies the health check name.                           |
   +------------------+---------+------------------------------------------------------------+
   | delay            | Integer | Specifies the maximum time between                         |
   |                  |         | health checks in the unit of second.                       |
   |                  |         | The value ranges from **1** to                             |
   |                  |         | **50**.                                                    |
   +------------------+---------+------------------------------------------------------------+
   | max_retries      | Integer | Specifies the number of consecutive                        |
   |                  |         | health checks when the health check                        |
   |                  |         | result of a backend server changes                         |
   |                  |         | from **OFFLINE** to **ONLINE**. The                        |
   |                  |         | value ranges from **1** to **10**.                         |
   +------------------+---------+------------------------------------------------------------+
   | max_retries_down | Integer | Specifies the number of consecutive                        |
   |                  |         | health checks when the health check                        |
   |                  |         | result of a backend server changes                         |
   |                  |         | from **ONLINE** to **OFFLINE**. The                        |
   |                  |         | value ranges from **1** to **10**.                         |
   +------------------+---------+------------------------------------------------------------+
   | pools            | Array   | Specifies the ID of the backend                            |
   |                  |         | server group associated with the                           |
   |                  |         | health check. For details, see :ref:`shared_hm_update_t5`. |
   +------------------+---------+------------------------------------------------------------+
   | admin_state_up   | Boolean | Specifies the administrative status                        |
   |                  |         | of the health check.                                       |
   |                  |         |                                                            |
   |                  |         | This parameter is reserved. The value                      |
   |                  |         | can be **true** or **false**.                              |
   |                  |         |                                                            |
   |                  |         | -  **true**: Enabled                                       |
   |                  |         | -  **false**: Disabled                                     |
   +------------------+---------+------------------------------------------------------------+
   | timeout          | Integer | Specifies the health check timeout                         |
   |                  |         | duration in the unit of second. The                        |
   |                  |         | value ranges from **1** to **50**.                         |
   |                  |         |                                                            |
   |                  |         | NOTE:                                                      |
   |                  |         | You are advised to set the value less                      |
   |                  |         | than that of parameter **delay**.                          |
   +------------------+---------+------------------------------------------------------------+
   | type             | String  | Specifies the health check protocol.                       |
   |                  |         |                                                            |
   |                  |         | The value can be **TCP**,                                  |
   |                  |         | **UDP_CONNECT**, or **HTTP**.                              |
   |                  |         |                                                            |
   |                  |         | The relationships between the value                        |
   |                  |         | of this parameter and the protocol of                      |
   |                  |         | the backend server group are as                            |
   |                  |         | follows:                                                   |
   |                  |         |                                                            |
   |                  |         | -  If the protocol of the backend                          |
   |                  |         |    server group is UDP, the parameter                      |
   |                  |         |    value can only be **UDP_CONNECT**.                      |
   |                  |         | -  If the protocol of the backend                          |
   |                  |         |    server group is TCP, the parameter                      |
   |                  |         |    value can be **TCP** or **HTTP**.                       |
   |                  |         | -  If the protocol of the backend                          |
   |                  |         |    server group is HTTP, the                               |
   |                  |         |    parameter value can be **TCP** or                       |
   |                  |         |    **HTTP**.                                               |
   +------------------+---------+------------------------------------------------------------+
   | monitor_port     | Integer | Specifies the health check port. The                       |
   |                  |         | port number ranges from 1 to 65535.                        |
   |                  |         |                                                            |
   |                  |         | The value is left blank by default,                        |
   |                  |         | indicating that the port of the                            |
   |                  |         | backend server is used as the health                       |
   |                  |         | check port.                                                |
   +------------------+---------+------------------------------------------------------------+
   | expected_codes   | String  | Specifies the expected HTTP status                         |
   |                  |         | code. The following options are                            |
   |                  |         | available:                                                 |
   |                  |         |                                                            |
   |                  |         | A single value, such as **200**                            |
   |                  |         |                                                            |
   |                  |         | A list of values, such as **200,202**                      |
   |                  |         |                                                            |
   |                  |         | A value range, such as **200-204**                         |
   |                  |         |                                                            |
   |                  |         | This parameter is valid only when the                      |
   |                  |         | value of **type** is set to **HTTP**.                      |
   |                  |         |                                                            |
   |                  |         | Currently, this parameter is not                           |
   |                  |         | supported and is fixed at **200**.                         |
   +------------------+---------+------------------------------------------------------------+
   | domain_name      | String  | Specifies the domain name of HTTP                          |
   |                  |         | requests during the health check.                          |
   |                  |         |                                                            |
   |                  |         | This parameter is valid only when the                      |
   |                  |         | value of **type** is set to **HTTP**.                      |
   |                  |         |                                                            |
   |                  |         | The value is left blank by default,                        |
   |                  |         | indicating that the private IP                             |
   |                  |         | address of the load balancer is used                       |
   |                  |         | as the destination address of HTTP                         |
   |                  |         | requests.                                                  |
   |                  |         |                                                            |
   |                  |         | The value can contain only digits,                         |
   |                  |         | letters, hyphens (-), and periods (.)                      |
   |                  |         | and must start with a digit or                             |
   |                  |         | letter, for example,                                       |
   |                  |         | **www.test.com**.                                          |
   +------------------+---------+------------------------------------------------------------+
   | url_path         | String  | Specifies the HTTP request path for                        |
   |                  |         | the health check. The default value                        |
   |                  |         | is **/**, and the value must start                         |
   |                  |         | with a slash (/).                                          |
   |                  |         |                                                            |
   |                  |         | This parameter is valid only when the                      |
   |                  |         | value of **type** is set to **HTTP**.                      |
   |                  |         |                                                            |
   |                  |         | An example value is **/test**.                             |
   +------------------+---------+------------------------------------------------------------+
   | http_method      | String  | Specifies the HTTP request method.                         |
   |                  |         | The default value is **GET**.                              |
   |                  |         |                                                            |
   |                  |         | The value can be **GET**, **HEAD**,                        |
   |                  |         | **POST**, **PUT**, **DELETE**,                             |
   |                  |         | **TRACE**, **OPTIONS**, **CONNECT**,                       |
   |                  |         | and **PATCH**.                                             |
   |                  |         |                                                            |
   |                  |         | This parameter is valid only when the                      |
   |                  |         | value of **type** is set to **HTTP**.                      |
   |                  |         |                                                            |
   |                  |         | NOTE:                                                      |
   |                  |         | This parameter is reserved.                                |
   +------------------+---------+------------------------------------------------------------+

.. _shared_hm_update_t6:
.. table:: **Table 6** **pools** parameter description

   ========= ====== ========================================================
   Parameter Type   Description
   ========= ====== ========================================================
   id        String Specifies the ID of the associated backend server group.
   ========= ====== ========================================================

Example Request
^^^^^^^^^^^^^^^

-  Example request: Updating a health check

   .. code::

      PUT https://{Endpoint}/v2.0/lbaas/healthmonitors/b7633ade-24dc-4d72-8475-06aa22be5412

      {
        "healthmonitor": {
          "delay": 15,
          "name": "health-xx",
          "timeout": 12
         }
      }

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   .. code::

      {
        "healthmonitor": {
          "name": "health-xx",
          "admin_state_up": true,
          "tenant_id": "145483a5107745e9b3d80f956713e6a3",
          "domain_name": null,
          "delay": 15,
          "expected_codes": "200",
          "max_retries": 10,
          "max_retries_down": 5,
          "http_method": "GET",
          "timeout": 12,
          "pools": [
            {
              "id": "bb44bffb-05d9-412c-9d9c-b189d9e14193"
            }
          ],
          "url_path": "/",
          "type": "HTTP",
          "id": "2dca3867-98c5-4cde-8f2c-b89ae6bd7e36",
          "monitor_port": 112
        }
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Deleting a Health Check
=======================

Function
^^^^^^^^

This API is used to delete a health check.

Constraints
^^^^^^^^^^^

If **provisioning_status** of the load balancer for which the health check is configured is not **ACTIVE**, the health check cannot be deleted.

URI
^^^

DELETE /v2.0/lbaas/healthmonitors/{healthmonitor_id}

.. table:: **Table 1** Parameter description

   ================ ========= ====== ==============================
   Parameter        Mandatory Type   Description
   ================ ========= ====== ==============================
   healthmonitor_id Yes       String Specifies the health check ID.
   ================ ========= ====== ==============================

Request
^^^^^^^

None

Response
^^^^^^^^

None

Example Request
^^^^^^^^^^^^^^^

-  Example request: Deleting a health check

   .. code::

      DELETE https://{Endpoint}/v2.0/lbaas/healthmonitors/b7633ade-24dc-4d72-8475-06aa22be5412

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   None

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.
