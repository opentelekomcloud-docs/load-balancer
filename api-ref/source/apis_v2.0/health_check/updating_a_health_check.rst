:original_name: elb_zq_jk_0004.html

.. _elb_zq_jk_0004:

Updating a Health Check
=======================

Function
--------

This API is used to update a health check.

Constraints
-----------

If **provisioning_status** of the load balancer for which the health check is configured is not **ACTIVE**, the health check cannot be updated.

URI
---

PUT /v2.0/lbaas/healthmonitors/{healthmonitor_id}

.. table:: **Table 1** Parameter description

   ================ ========= ====== ==============================
   Parameter        Mandatory Type   Description
   ================ ========= ====== ==============================
   healthmonitor_id Yes       String Specifies the health check ID.
   ================ ========= ====== ==============================

Request
-------

.. table:: **Table 2** Parameter description

   +---------------+-----------+--------+------------------------------------------------------------------------------------------------------------------------+
   | Parameter     | Mandatory | Type   | Description                                                                                                            |
   +===============+===========+========+========================================================================================================================+
   | healthmonitor | Yes       | Object | Specifies the health check. For details, see :ref:`Table 3 <elb_zq_jk_0004__en-us_topic_0096561564_table61361617301>`. |
   +---------------+-----------+--------+------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_jk_0004__en-us_topic_0096561564_table61361617301:

.. table:: **Table 3** **healthmonitor** parameter description

   +------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter        | Mandatory       | Type            | Description                                                                                                                                                                       |
   +==================+=================+=================+===================================================================================================================================================================================+
   | name             | No              | String          | Specifies the health check name.                                                                                                                                                  |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | The value contains a maximum of 255 characters.                                                                                                                                   |
   +------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | delay            | No              | Integer         | Specifies the maximum time between health checks in the unit of second. The value ranges from **1** to **50**.                                                                    |
   +------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | max_retries      | No              | Integer         | Specifies the number of consecutive health checks when the health check result of a backend server changes from **OFFLINE** to **ONLINE**. The value ranges from **1** to **10**. |
   +------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | max_retries_down | No              | Integer         | Specifies the number of consecutive health checks when the health check result of a backend server changes from **ONLINE** to **OFFLINE**. The value ranges from **1** to **10**. |
   +------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up   | No              | Boolean         | Specifies the administrative status of the health check.                                                                                                                          |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | This parameter is reserved, and the default value is **true**.                                                                                                                    |
   +------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | timeout          | No              | Integer         | Specifies the health check timeout duration in the unit of second. The value ranges from **1** to **50**.                                                                         |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | .. note::                                                                                                                                                                         |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 |    You are advised to set the value less than that of parameter **delay**.                                                                                                        |
   +------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | type             | No              | String          | Specifies the health check protocol.                                                                                                                                              |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | The value can be **TCP**, **UDP_CONNECT**, or **HTTP**.                                                                                                                           |
   +------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | monitor_port     | No              | Integer         | Specifies the health check port. The port number ranges from 1 to 65535.                                                                                                          |
   |                  |                 |                 |                                                                                                                                                                                   |
   |                  |                 |                 | The value is left blank by default, indicating that the port of the backend server is used as the health check port.                                                              |
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

.. table:: **Table 4** Response parameters

   +---------------+--------+------------------------------------------------------------------------------------------------------------------------+
   | Parameter     | Type   | Description                                                                                                            |
   +===============+========+========================================================================================================================+
   | healthmonitor | Object | Specifies the health check. For details, see :ref:`Table 5 <elb_zq_jk_0004__en-us_topic_0096561564_table25969311303>`. |
   +---------------+--------+------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_jk_0004__en-us_topic_0096561564_table25969311303:

.. table:: **Table 5** **healthmonitor** parameter description

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

.. table:: **Table 6** **pools** parameter description

   +-----------+--------+----------------------------------------------------------+
   | Parameter | Type   | Description                                              |
   +===========+========+==========================================================+
   | id        | String | Specifies the ID of the associated backend server group. |
   +-----------+--------+----------------------------------------------------------+

Example Request
---------------

-  Example request: Updating a health check

   .. code-block:: text

      PUT https://{Endpoint}/v2.0/lbaas/healthmonitors/b7633ade-24dc-4d72-8475-06aa22be5412

      {
        "healthmonitor": {
          "delay": 15,
          "name": "health-xx",
          "timeout": 12
         }
      }

Example Response
----------------

-  Example response

   .. code-block::

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
-----------

For details, see :ref:`Status Codes <elb_gc_1102>`.
