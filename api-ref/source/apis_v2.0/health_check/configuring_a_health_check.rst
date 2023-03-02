:original_name: elb_zq_jk_0001.html

.. _elb_zq_jk_0001:

Configuring a Health Check
==========================

Function
--------

This API is used to configure a health check for a backend server group to check the status of backend servers. If the health check result is **OFFLINE**, backend servers are considered unhealthy. You need to check the server configuration.

Constraints
-----------

The security group must allow access from 100.125.0.0/16. Otherwise, the health check cannot be performed.

URI
---

POST /v2.0/lbaas/healthmonitors

Request
-------

.. table:: **Table 1** Parameter description

   +---------------+-----------+--------+----------------------------------------------------------------------------------------------------------------------------+
   | Parameter     | Mandatory | Type   | Description                                                                                                                |
   +===============+===========+========+============================================================================================================================+
   | healthmonitor | Yes       | Object | Specifies the health check. For details, see :ref:`Table 2 <elb_zq_jk_0001__en-us_topic_0096561563_table154092042172813>`. |
   +---------------+-----------+--------+----------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_jk_0001__en-us_topic_0096561563_table154092042172813:

.. table:: **Table 2** **healthmonitor** parameter description

   +------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter        | Mandatory       | Type            | Description                                                                                                                                                                       |
   +==================+=================+=================+===================================================================================================================================================================================+
   | tenant_id        | No              | String          | Specifies the ID of the project where the health check is performed.                                                                                                              |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | The value must be the same as the value of **project_id** in the token.                                                                                                           |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | The value contains a maximum of 255 characters.                                                                                                                                   |
   +------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name             | No              | String          | Specifies the health check name.                                                                                                                                                  |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | The value contains a maximum of 255 characters.                                                                                                                                   |
   +------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | delay            | Yes             | Integer         | Specifies the maximum time between health checks in the unit of second. The value ranges from **1** to **50**.                                                                    |
   +------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | max_retries      | Yes             | Integer         | Specifies the number of consecutive health checks when the health check result of a backend server changes from **OFFLINE** to **ONLINE**. The value ranges from **1** to **10**. |
   +------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | max_retries_down | No              | Integer         | Specifies the number of consecutive health checks when the health check result of a backend server changes from **ONLINE** to **OFFLINE**. The value ranges from **1** to **10**. |
   +------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | pool_id          | Yes             | String          | Specifies the ID of the backend server group.                                                                                                                                     |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | Only one health check can be configured for each backend server group.                                                                                                            |
   +------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up   | No              | Boolean         | Specifies the administrative status of the health check.                                                                                                                          |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | This parameter is reserved, and the default value is **true**.                                                                                                                    |
   +------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | timeout          | Yes             | Integer         | Specifies the health check timeout duration in the unit of second. The value ranges from **1** to **50**.                                                                         |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | .. note::                                                                                                                                                                         |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 |    You are advised to set the value less than that of parameter **delay**.                                                                                                        |
   +------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | type             | Yes             | String          | Specifies the health check protocol.                                                                                                                                              |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | The value can be **TCP**, **UDP_CONNECT**, or **HTTP**.                                                                                                                           |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | The relationships between the health check protocol and the protocol used by the backend server group are as follows:                                                             |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | -  If the protocol of the backend server group is UDP, the parameter value can only be **UDP_CONNECT**.                                                                           |
   |                  |                 |                 | -  If the protocol of the backend server group is TCP, the parameter value can be **TCP** or **HTTP**.                                                                            |
   |                  |                 |                 | -  If the protocol of the backend server group is HTTP, the parameter value can be **TCP** or **HTTP**.                                                                           |
   +------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | monitor_port     | No              | Integer         | Specifies the health check port. The port number ranges from 1 to 65535.                                                                                                          |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | The value is left blank by default, indicating that the port of the backend server is used as the health check port.                                                              |
   +------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | domain_name      | No              | String          | Specifies the domain name of HTTP requests during the health check.                                                                                                               |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | This parameter is valid only when the value of **type** is set to **HTTP**.                                                                                                       |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | The value is left blank by default, indicating that the private IP address of the load balancer is used as the destination address of HTTP requests.                              |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | The value can contain only digits, letters, hyphens (-), and periods (.) and must start with a digit or letter, for example, **www.test.com**.                                    |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | The value contains a maximum of 100 characters.                                                                                                                                   |
   +------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | url_path         | No              | String          | Specifies the HTTP request path for the health check. The default value is **/**, and the value must start with a slash (/).                                                      |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | This parameter is valid only when the value of **type** is set to **HTTP**.                                                                                                       |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | An example value is **/test**.                                                                                                                                                    |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | The value contains a maximum of 80 characters.                                                                                                                                    |
   +------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | expected_codes   | No              | String          | Specifies the expected HTTP status code. The following options are available:                                                                                                     |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | A single value, such as **200**                                                                                                                                                   |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | A list of values, such as **200,202**                                                                                                                                             |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | A value range, such as **200-204**                                                                                                                                                |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | This parameter is valid only when the value of **type** is set to **HTTP**.                                                                                                       |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | The value contains a maximum of 64 characters.                                                                                                                                    |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | .. note::                                                                                                                                                                         |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 |    This parameter is reserved.                                                                                                                                                    |
   +------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | http_method      | No              | String          | Specifies the HTTP request method. The default value is **GET**.                                                                                                                  |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | The value can be **GET**, **HEAD**, **POST**, **PUT**, **DELETE**, **TRACE**, **OPTIONS**, **CONNECT**, or **PATCH**.                                                             |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | This parameter is valid only when the value of **type** is set to **HTTP**.                                                                                                       |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | .. note::                                                                                                                                                                         |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 |    This parameter is reserved.                                                                                                                                                    |
   +------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Response
--------

.. table:: **Table 3** Response parameters

   +---------------+--------+-------------------------------------------------------------------------------------------------------------------------+
   | Parameter     | Type   | Description                                                                                                             |
   +===============+========+=========================================================================================================================+
   | healthmonitor | Object | Specifies the health check. For details, see :ref:`Table 4 <elb_zq_jk_0001__en-us_topic_0096561563_table186706722915>`. |
   +---------------+--------+-------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_jk_0001__en-us_topic_0096561563_table186706722915:

.. table:: **Table 4** **healthmonitor** parameter description

   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                                                       |
   +=======================+=======================+===================================================================================================================================================================================+
   | id                    | String                | Specifies the health check ID.                                                                                                                                                    |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tenant_id             | String                | Specifies the ID of the project where the health check is performed.                                                                                                              |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                | Specifies the health check name.                                                                                                                                                  |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | delay                 | Integer               | Specifies the maximum time between health checks in the unit of second. The value ranges from **1** to **50**.                                                                    |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | max_retries           | Integer               | Specifies the number of consecutive health checks when the health check result of a backend server changes from **OFFLINE** to **ONLINE**. The value ranges from **1** to **10**. |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | max_retries_down      | Integer               | Specifies the number of consecutive health checks when the health check result of a backend server changes from **ONLINE** to **OFFLINE**. The value ranges from **1** to **10**. |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | pools                 | Array                 | Specifies the ID of the backend server group associated with the health check. For details, see :ref:`Table 5 <elb_zq_jk_0001__en-us_topic_0096561563_table567815515351>`.        |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up        | Boolean               | Specifies the administrative status of the health check.                                                                                                                          |
   |                       |                       |                                                                                                                                                                                   |
   |                       |                       | This parameter is reserved. The value can be **true** or **false**.                                                                                                               |
   |                       |                       |                                                                                                                                                                                   |
   |                       |                       | -  **true**: Enabled                                                                                                                                                              |
   |                       |                       | -  **false**: Disabled                                                                                                                                                            |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | timeout               | Integer               | Specifies the health check timeout duration in the unit of second. The value ranges from **1** to **50**.                                                                         |
   |                       |                       |                                                                                                                                                                                   |
   |                       |                       | .. note::                                                                                                                                                                         |
   |                       |                       |                                                                                                                                                                                   |
   |                       |                       |    You are advised to set the value less than that of parameter **delay**.                                                                                                        |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | type                  | String                | Specifies the health check protocol.                                                                                                                                              |
   |                       |                       |                                                                                                                                                                                   |
   |                       |                       | The value can be **TCP**, **UDP_CONNECT**, or **HTTP**.                                                                                                                           |
   |                       |                       |                                                                                                                                                                                   |
   |                       |                       | The relationships between the value of this parameter and the protocol of the backend server group are as follows:                                                                |
   |                       |                       |                                                                                                                                                                                   |
   |                       |                       | -  If the protocol of the backend server group is UDP, the parameter value can only be **UDP_CONNECT**.                                                                           |
   |                       |                       | -  If the protocol of the backend server group is TCP, the parameter value can be **TCP** or **HTTP**.                                                                            |
   |                       |                       | -  If the protocol of the backend server group is HTTP, the parameter value can be **TCP** or **HTTP**.                                                                           |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | monitor_port          | Integer               | Specifies the health check port. The port number ranges from 1 to 65535.                                                                                                          |
   |                       |                       |                                                                                                                                                                                   |
   |                       |                       | The value is left blank by default, indicating that the port of the backend server is used as the health check port.                                                              |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | expected_codes        | String                | Specifies the expected HTTP status code. The following options are available:                                                                                                     |
   |                       |                       |                                                                                                                                                                                   |
   |                       |                       | A single value, such as **200**                                                                                                                                                   |
   |                       |                       |                                                                                                                                                                                   |
   |                       |                       | A list of values, such as **200,202**                                                                                                                                             |
   |                       |                       |                                                                                                                                                                                   |
   |                       |                       | A value range, such as **200-204**                                                                                                                                                |
   |                       |                       |                                                                                                                                                                                   |
   |                       |                       | This parameter is valid only when the value of **type** is set to **HTTP**.                                                                                                       |
   |                       |                       |                                                                                                                                                                                   |
   |                       |                       | Currently, this parameter is not supported and is fixed at **200**.                                                                                                               |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | domain_name           | String                | Specifies the domain name of HTTP requests during the health check.                                                                                                               |
   |                       |                       |                                                                                                                                                                                   |
   |                       |                       | This parameter is valid only when the value of **type** is set to **HTTP**.                                                                                                       |
   |                       |                       |                                                                                                                                                                                   |
   |                       |                       | The value is left blank by default, indicating that the private IP address of the load balancer is used as the destination address of HTTP requests.                              |
   |                       |                       |                                                                                                                                                                                   |
   |                       |                       | The value can contain only digits, letters, hyphens (-), and periods (.) and must start with a digit or letter, for example, **www.test.com**.                                    |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | url_path              | String                | Specifies the HTTP request path for the health check. The default value is **/**, and the value must start with a slash (/).                                                      |
   |                       |                       |                                                                                                                                                                                   |
   |                       |                       | This parameter is valid only when the value of **type** is set to **HTTP**.                                                                                                       |
   |                       |                       |                                                                                                                                                                                   |
   |                       |                       | An example value is **/test**.                                                                                                                                                    |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | http_method           | String                | Specifies the HTTP request method. The default value is **GET**.                                                                                                                  |
   |                       |                       |                                                                                                                                                                                   |
   |                       |                       | The value can be **GET**, **HEAD**, **POST**, **PUT**, **DELETE**, **TRACE**, **OPTIONS**, **CONNECT**, or **PATCH**.                                                             |
   |                       |                       |                                                                                                                                                                                   |
   |                       |                       | This parameter is valid only when the value of **type** is set to **HTTP**.                                                                                                       |
   |                       |                       |                                                                                                                                                                                   |
   |                       |                       | .. note::                                                                                                                                                                         |
   |                       |                       |                                                                                                                                                                                   |
   |                       |                       |    This parameter is reserved.                                                                                                                                                    |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_jk_0001__en-us_topic_0096561563_table567815515351:

.. table:: **Table 5** **pools** parameter description

   +-----------+--------+----------------------------------------------------------+
   | Parameter | Type   | Description                                              |
   +===========+========+==========================================================+
   | id        | String | Specifies the ID of the associated backend server group. |
   +-----------+--------+----------------------------------------------------------+

Example Request
---------------

-  Example request: Configuring a health check

   .. code-block:: text

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
----------------

-  Example response

   .. code-block::

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
-----------

For details, see :ref:`Status Codes <elb_gc_1102>`.
