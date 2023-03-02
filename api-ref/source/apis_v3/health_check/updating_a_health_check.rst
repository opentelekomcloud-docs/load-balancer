:original_name: UpdateHealthMonitor.html

.. _UpdateHealthMonitor:

Updating a Health Check
=======================

Function
--------

This API is used to update a health check.

Constraints
-----------

The health check can be updated only when the provisioning status of the associated load balancer is **ACTIVE**.

URI
---

PUT /v3/{project_id}/elb/healthmonitors/{healthmonitor_id}

.. table:: **Table 1** Path Parameters

   ================ ========= ====== ==============================
   Parameter        Mandatory Type   Description
   ================ ========= ====== ==============================
   healthmonitor_id Yes       String Specifies the health check ID.
   project_id       Yes       String Specifies the project ID.
   ================ ========= ====== ==============================

Request Parameters
------------------

.. table:: **Table 2** Request header parameters

   +--------------+-----------+--------+--------------------------------------------------+
   | Parameter    | Mandatory | Type   | Description                                      |
   +==============+===========+========+==================================================+
   | X-Auth-Token | Yes       | String | Specifies the token used for IAM authentication. |
   +--------------+-----------+--------+--------------------------------------------------+

.. table:: **Table 3** Request body parameters

   +---------------+-----------+--------------------------------------------------------------------------------------------------+-----------------------------+
   | Parameter     | Mandatory | Type                                                                                             | Description                 |
   +===============+===========+==================================================================================================+=============================+
   | healthmonitor | Yes       | :ref:`UpdateHealthMonitorOption <updatehealthmonitor__request_updatehealthmonitoroption>` object | Specifies the health check. |
   +---------------+-----------+--------------------------------------------------------------------------------------------------+-----------------------------+

.. _updatehealthmonitor__request_updatehealthmonitoroption:

.. table:: **Table 4** UpdateHealthMonitorOption

   +------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter        | Mandatory       | Type            | Description                                                                                                                                                                                           |
   +==================+=================+=================+=======================================================================================================================================================================================================+
   | admin_state_up   | No              | Boolean         | Specifies the administrative status of the health check.                                                                                                                                              |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | -  **true** (default): Health check is enabled.                                                                                                                                                       |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | -  **false**: Health check is disabled.                                                                                                                                                               |
   +------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | delay            | No              | Integer         | Specifies the interval between health checks, in seconds. The value ranges from **1** to **50**.                                                                                                      |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | Minimum: **1**                                                                                                                                                                                        |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | Maximum: **50**                                                                                                                                                                                       |
   +------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | domain_name      | No              | String          | Specifies the domain name that HTTP requests are sent to during the health check.                                                                                                                     |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | The value can contain only digits, letters, hyphens (-), and periods (.) and must start with a digit or letter.                                                                                       |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | The value cannot be left blank, but can be specified as null or cannot be passed, indicating that the virtual IP address of the load balancer is used as the destination address of HTTP requests.    |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | This parameter is available only when **type** is set to **HTTP**.                                                                                                                                    |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | Minimum: **1**                                                                                                                                                                                        |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | Maximum: **100**                                                                                                                                                                                      |
   +------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | expected_codes   | No              | String          | Specifies the expected HTTP status code. This parameter will take effect only when **type** is set to **HTTP** or **HTTPS**.                                                                          |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | The value options are as follows:                                                                                                                                                                     |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | -  A specific value, for example, 200                                                                                                                                                                 |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | -  A list of values that are separated with commas (,), for example, 200, 202                                                                                                                         |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | -  A value range, for example, 200-204                                                                                                                                                                |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | The default value is **200**. Multiple status codes can be queried in the format of *expected_codes=xxx&expected_codes=xxx*.                                                                          |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | Minimum: **1**                                                                                                                                                                                        |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | Maximum: **64**                                                                                                                                                                                       |
   +------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | http_method      | No              | String          | Specifies the HTTP method.                                                                                                                                                                            |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | The value can be **GET**, **HEAD**, **POST**, **PUT**, **DELETE**, **TRACE**, **OPTIONS**, **CONNECT**, or **PATCH**.                                                                                 |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | This parameter will take effect only when **type** is set to **HTTP**.                                                                                                                                |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | This parameter is unsupported. Please do not use it.                                                                                                                                                  |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | Minimum: **1**                                                                                                                                                                                        |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | Maximum: **16**                                                                                                                                                                                       |
   +------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | max_retries      | No              | Integer         | Specifies the number of consecutive health checks when the health check result of a backend server changes from **OFFLINE** to **ONLINE**.                                                            |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | The value ranges from **1** to **10**                                                                                                                                                                 |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | Minimum: **1**                                                                                                                                                                                        |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | Maximum: **10**                                                                                                                                                                                       |
   +------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | max_retries_down | No              | Integer         | Specifies the number of consecutive health checks when the health check result of a backend server changes from **ONLINE** to **OFFLINE**. The value ranges from **1** to **10**.                     |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | Minimum: **1**                                                                                                                                                                                        |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | Maximum: **10**                                                                                                                                                                                       |
   +------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | monitor_port     | No              | Integer         | Specifies the port used for the health check. This parameter cannot be left blank, but can be set to **null**, indicating that the port used by the backend server will be used.                      |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | Minimum: **1**                                                                                                                                                                                        |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | Maximum: **65535**                                                                                                                                                                                    |
   +------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name             | No              | String          | Specifies the health check name.                                                                                                                                                                      |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | Minimum: **0**                                                                                                                                                                                        |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | Maximum: **255**                                                                                                                                                                                      |
   +------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | timeout          | No              | Integer         | Specifies the maximum time required for waiting for a response from the health check, in seconds. It is recommended that you set the value less than that of parameter **delay**.                     |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | Minimum: **1**                                                                                                                                                                                        |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | Maximum: **50**                                                                                                                                                                                       |
   +------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | url_path         | No              | String          | Specifies the HTTP request path for the health check. The value must start with a slash (/), and the default value is **/**. Note: This parameter is available only when **type** is set to **HTTP**. |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | Minimum: **1**                                                                                                                                                                                        |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | Maximum: **80**                                                                                                                                                                                       |
   +------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | type             | No              | String          | Specifies the health check protocol. The value can be **TCP**, **UDP_CONNECT**, **HTTP**, or **HTTPS**.                                                                                               |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | Note:                                                                                                                                                                                                 |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | -  If the protocol of the backend server is QUIC, the value can only be **UDP_CONNECT**.                                                                                                              |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | -  If the protocol of the backend server is UDP, the value can only be **UDP_CONNECT**.                                                                                                               |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | -  If the protocol of the backend server is TCP, the value can only be **TCP**, **HTTP**, or **HTTPS**.                                                                                               |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | -  If the protocol of the backend server is HTTP, the value can only be **TCP**, **HTTP**, or **HTTPS**.                                                                                              |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | -  If the protocol of the backend server is HTTPS, the value can only be **TCP**, **HTTP**, or **HTTPS**.                                                                                             |
   |                  |                 |                 |                                                                                                                                                                                                       |
   |                  |                 |                 | QUIC protocol is not supported in **eu-nl** region.                                                                                                                                                   |
   +------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Response Parameters
-------------------

**Status code: 200**

.. table:: **Table 5** Response body parameters

   +---------------+---------------------------------------------------------------------------+-----------------------------------------------------------------+
   | Parameter     | Type                                                                      | Description                                                     |
   +===============+===========================================================================+=================================================================+
   | request_id    | String                                                                    | Specifies the request ID. The value is automatically generated. |
   +---------------+---------------------------------------------------------------------------+-----------------------------------------------------------------+
   | healthmonitor | :ref:`HealthMonitor <updatehealthmonitor__response_healthmonitor>` object | Specifies the health check.                                     |
   +---------------+---------------------------------------------------------------------------+-----------------------------------------------------------------+

.. _updatehealthmonitor__response_healthmonitor:

.. table:: **Table 6** HealthMonitor

   +-----------------------+-------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                                                                    | Description                                                                                                                                                                                                |
   +=======================+=========================================================================+============================================================================================================================================================================================================+
   | admin_state_up        | Boolean                                                                 | Specifies the administrative status of the health check.                                                                                                                                                   |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | -  **true**\ (default) indicates that the health check is enabled.                                                                                                                                         |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | -  **false** indicates that the health check is disabled.                                                                                                                                                  |
   +-----------------------+-------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | delay                 | Integer                                                                 | Specifies the interval between health checks, in seconds. The value ranges from **1** to **50**.                                                                                                           |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | Minimum: **1**                                                                                                                                                                                             |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | Maximum: **50**                                                                                                                                                                                            |
   +-----------------------+-------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | domain_name           | String                                                                  | Specifies the domain name that HTTP requests are sent to during the health check.                                                                                                                          |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | The value can contain only digits, letters, hyphens (-), and periods (.) and must start with a digit or letter.                                                                                            |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | The value is left blank by default, indicating that the virtual IP address of the load balancer is used as the destination address of HTTP requests.                                                       |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | This parameter is available only when **type** is set to **HTTP**.                                                                                                                                         |
   +-----------------------+-------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | expected_codes        | String                                                                  | Specifies the expected HTTP status code. This parameter will take effect only when **type** is set to **HTTP** or **HTTPS**.                                                                               |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | The value options are as follows:                                                                                                                                                                          |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | -  A specific value, for example, 200                                                                                                                                                                      |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | -  A list of values that are separated with commas (,), for example, 200, 202                                                                                                                              |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | -  A value range, for example, 200-204                                                                                                                                                                     |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | The default value is **200**. Multiple status codes can be queried in the format of *expected_codes=xxx&expected_codes=xxx*.                                                                               |
   +-----------------------+-------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | http_method           | String                                                                  | Specifies the HTTP method. The value can be **GET**, **HEAD**, **POST**, **PUT**, **DELETE**, **TRACE**, **OPTIONS**, **CONNECT**, or **PATCH**. The default value is **GET**.                             |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | This parameter is available when **type** is set to **HTTP** or **HTTPS**.                                                                                                                                 |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | This parameter is unsupported. Please do not use it.                                                                                                                                                       |
   +-----------------------+-------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | id                    | String                                                                  | Specifies the health check ID.                                                                                                                                                                             |
   +-----------------------+-------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | max_retries           | Integer                                                                 | Specifies the number of consecutive health checks when the health check result of a backend server changes from **OFFLINE** to **ONLINE**.                                                                 |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | The value ranges from **1** to **10**                                                                                                                                                                      |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | Minimum: **1**                                                                                                                                                                                             |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | Maximum: **10**                                                                                                                                                                                            |
   +-----------------------+-------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | max_retries_down      | Integer                                                                 | Specifies the number of consecutive health checks when the health check result of a backend server changes from **ONLINE** to **OFFLINE**.                                                                 |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | The value ranges from **1** to **10**, and the default value is **3**.                                                                                                                                     |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | Minimum: **1**                                                                                                                                                                                             |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | Maximum: **10**                                                                                                                                                                                            |
   +-----------------------+-------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | monitor_port          | Integer                                                                 | Specifies the port used for the health check. If this parameter is left blank, a port of the backend server will be used by default. The port number ranges from 1 to 65535.                               |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | Minimum: **1**                                                                                                                                                                                             |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | Maximum: **65535**                                                                                                                                                                                         |
   +-----------------------+-------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                                                                  | Specifies the health check name.                                                                                                                                                                           |
   +-----------------------+-------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | pools                 | Array of :ref:`PoolRef <updatehealthmonitor__response_poolref>` objects | Lists the IDs of backend server groups for which the health check is configured. Only one ID will be returned.                                                                                             |
   +-----------------------+-------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | project_id            | String                                                                  | Specifies the project ID.                                                                                                                                                                                  |
   +-----------------------+-------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | timeout               | Integer                                                                 | Specifies the maximum time required for waiting for a response from the health check, in seconds. It is recommended that you set the value less than that of parameter **delay**.                          |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | Minimum: **1**                                                                                                                                                                                             |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | Maximum: **50**                                                                                                                                                                                            |
   +-----------------------+-------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | type                  | String                                                                  | Specifies the health check protocol. The value can be **TCP**, **UDP_CONNECT**, **HTTP**, or **HTTPS**.                                                                                                    |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | Note:                                                                                                                                                                                                      |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | -  If the protocol of the backend server is QUIC, the value can only be **UDP_CONNECT**.                                                                                                                   |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | -  If the protocol of the backend server is UDP, the value can only be **UDP_CONNECT**.                                                                                                                    |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | -  If the protocol of the backend server is TCP, the value can only be **TCP**, **HTTP**, or **HTTPS**.                                                                                                    |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | -  If the protocol of the backend server is HTTP, the value can only be **TCP**, **HTTP**, or **HTTPS**.                                                                                                   |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | -  If the protocol of the backend server is HTTPS, the value can only be **TCP**, **HTTP**, or **HTTPS**.                                                                                                  |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | QUIC protocol is not supported in **eu-nl** region.                                                                                                                                                        |
   +-----------------------+-------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | url_path              | String                                                                  | Specifies the HTTP request path for the health check. The value must start with a slash (/), and the default value is **/**. Note: This parameter is available only when **type** is set to **HTTP**.      |
   +-----------------------+-------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | created_at            | String                                                                  | Specifies the time when the health check was configured. The format is yyyy-MM-dd'T'HH:mm:ss'Z' (UTC time).                                                                                                |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | This is a new field in this version, and it will not be returned for resources associated with existing dedicated load balancers and for resources associated with existing and new shared load balancers. |
   +-----------------------+-------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | updated_at            | String                                                                  | Specifies the time when the health check was updated. The format is yyyy-MM-dd'T'HH:mm:ss'Z' (UTC time).                                                                                                   |
   |                       |                                                                         |                                                                                                                                                                                                            |
   |                       |                                                                         | This is a new field in this version, and it will not be returned for resources associated with existing dedicated load balancers and for resources associated with existing and new shared load balancers. |
   +-----------------------+-------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _updatehealthmonitor__response_poolref:

.. table:: **Table 7** PoolRef

   ========= ====== =============================================
   Parameter Type   Description
   ========= ====== =============================================
   id        String Specifies the ID of the backend server group.
   ========= ====== =============================================

Example Requests
----------------

.. code-block:: text

   PUT https://{ELB_Endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/healthmonitors/c2b210b2-60c4-449d-91e2-9e9ea1dd7441

   {
     "healthmonitor" : {
       "name" : "My Healthmonitor update",
       "max_retries" : 10,
       "delay" : 10
     }
   }

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

   {
     "request_id" : "08d6ffea-d092-4cfa-860a-e364f3bef1be",
     "healthmonitor" : {
       "monitor_port" : null,
       "id" : "c2b210b2-60c4-449d-91e2-9e9ea1dd7441",
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "domain_name" : null,
       "name" : "My Healthmonitor update",
       "delay" : 10,
       "max_retries" : 10,
       "pools" : [ {
         "id" : "488acc50-6bcf-423d-8f0a-0f4184f5b8a0"
       } ],
       "admin_state_up" : true,
       "timeout" : 30,
       "type" : "HTTP",
       "expected_codes" : "200",
       "url_path" : "/",
       "http_method" : "GET"
     }
   }

Status Codes
------------

=========== ===========================================
Status Code Description
=========== ===========================================
200         Successful request.
400         Invalid request body or request parameters.
403         Failed to verify the token.
404         The queried resource does not exist.
409         A conflict occurred.
431         The request headers are too large.
494         The request header or cookie is too large.
500         A service error occurred.
=========== ===========================================

Error Codes
-----------

See :ref:`Error Codes <errorcode>`.
