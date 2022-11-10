:original_name: ShowHealthMonitor.html

.. _ShowHealthMonitor:

Viewing Details of a Health Check
=================================

Function
--------

This API is used to view details of a health check.

URI
---

GET /v3/{project_id}/elb/healthmonitors/{healthmonitor_id}

.. table:: **Table 1** Path Parameters

   ================ ========= ====== ==============================
   Parameter        Mandatory Type   Description
   ================ ========= ====== ==============================
   project_id       Yes       String Specifies the project ID.
   healthmonitor_id Yes       String Specifies the health check ID.
   ================ ========= ====== ==============================

Request Parameters
------------------

.. table:: **Table 2** Request header parameters

   +--------------+-----------+--------+--------------------------------------------------+
   | Parameter    | Mandatory | Type   | Description                                      |
   +==============+===========+========+==================================================+
   | X-Auth-Token | Yes       | String | Specifies the token used for IAM authentication. |
   +--------------+-----------+--------+--------------------------------------------------+

Response Parameters
-------------------

**Status code: 200**

.. table:: **Table 3** Response body parameters

   +---------------+-------------------------------------------------------------------------+-----------------------------------------------------------------+
   | Parameter     | Type                                                                    | Description                                                     |
   +===============+=========================================================================+=================================================================+
   | request_id    | String                                                                  | Specifies the request ID. The value is automatically generated. |
   +---------------+-------------------------------------------------------------------------+-----------------------------------------------------------------+
   | healthmonitor | :ref:`HealthMonitor <showhealthmonitor__response_healthmonitor>` object | Specifies the health check.                                     |
   +---------------+-------------------------------------------------------------------------+-----------------------------------------------------------------+

.. _showhealthmonitor__response_healthmonitor:

.. table:: **Table 4** HealthMonitor

   +-----------------------+-----------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                                                                  | Description                                                                                                                                                                                               |
   +=======================+=======================================================================+===========================================================================================================================================================================================================+
   | admin_state_up        | Boolean                                                               | Specifies the administrative status of the health check. Two value options are available. **true** indicates that the health check is enabled, and **false** indicates that the health check is disabled. |
   |                       |                                                                       |                                                                                                                                                                                                           |
   |                       |                                                                       | Default: **true**                                                                                                                                                                                         |
   +-----------------------+-----------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | delay                 | Integer                                                               | Specifies the interval between health checks, in seconds.                                                                                                                                                 |
   |                       |                                                                       |                                                                                                                                                                                                           |
   |                       |                                                                       | Minimum: **1**                                                                                                                                                                                            |
   |                       |                                                                       |                                                                                                                                                                                                           |
   |                       |                                                                       | Maximum: **50**                                                                                                                                                                                           |
   +-----------------------+-----------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | domain_name           | String                                                                | Specifies the domain name that HTTP requests are sent to during the health check.                                                                                                                         |
   |                       |                                                                       |                                                                                                                                                                                                           |
   |                       |                                                                       | This parameter is available only when **type** is set to **HTTP**.                                                                                                                                        |
   |                       |                                                                       |                                                                                                                                                                                                           |
   |                       |                                                                       | The value is left blank by default, indicating that the virtual IP address of the load balancer is used as the destination address of HTTP requests.                                                      |
   |                       |                                                                       |                                                                                                                                                                                                           |
   |                       |                                                                       | The value can contain only digits, letters, hyphens (-), and periods (.) and must start with a digit or letter.                                                                                           |
   +-----------------------+-----------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | expected_codes        | String                                                                | Specifies the expected HTTP status code. This parameter will take effect only when **type** is set to **HTTP**.                                                                                           |
   |                       |                                                                       |                                                                                                                                                                                                           |
   |                       |                                                                       | The value options are as follows:                                                                                                                                                                         |
   |                       |                                                                       |                                                                                                                                                                                                           |
   |                       |                                                                       | -  A specific value, for example, 200                                                                                                                                                                     |
   |                       |                                                                       |                                                                                                                                                                                                           |
   |                       |                                                                       | -  A list of values that are separated with commas (,), for example, 200, 202                                                                                                                             |
   |                       |                                                                       |                                                                                                                                                                                                           |
   |                       |                                                                       | -  A value range, for example, 200-204                                                                                                                                                                    |
   |                       |                                                                       |                                                                                                                                                                                                           |
   |                       |                                                                       | This parameter is unsupported. Please do not use it.                                                                                                                                                      |
   |                       |                                                                       |                                                                                                                                                                                                           |
   |                       |                                                                       | Default: **200**                                                                                                                                                                                          |
   +-----------------------+-----------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | http_method           | String                                                                | Specifies the HTTP method. This parameter will take effect only when **type** is set to **HTTP**.                                                                                                         |
   |                       |                                                                       |                                                                                                                                                                                                           |
   |                       |                                                                       | The value can be **GET**, **HEAD**, **POST**, **PUT**, **DELETE**, **TRACE**, **OPTIONS**, **CONNECT**, or **PATCH**.                                                                                     |
   |                       |                                                                       |                                                                                                                                                                                                           |
   |                       |                                                                       | This parameter is unsupported. Please do not use it.                                                                                                                                                      |
   |                       |                                                                       |                                                                                                                                                                                                           |
   |                       |                                                                       | Default: **GET**                                                                                                                                                                                          |
   +-----------------------+-----------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | id                    | String                                                                | Specifies the health check ID.                                                                                                                                                                            |
   +-----------------------+-----------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | max_retries           | Integer                                                               | Specifies the number of consecutive health checks when the health check result of a backend server changes from **OFFLINE** to **ONLINE**. The value ranges from **1** to **10**.                         |
   |                       |                                                                       |                                                                                                                                                                                                           |
   |                       |                                                                       | Minimum: **1**                                                                                                                                                                                            |
   |                       |                                                                       |                                                                                                                                                                                                           |
   |                       |                                                                       | Maximum: **10**                                                                                                                                                                                           |
   +-----------------------+-----------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | max_retries_down      | Integer                                                               | Specifies the number of consecutive health checks when the health check result of a backend server changes from **ONLINE** to **OFFLINE**.                                                                |
   |                       |                                                                       |                                                                                                                                                                                                           |
   |                       |                                                                       | Minimum: **1**                                                                                                                                                                                            |
   |                       |                                                                       |                                                                                                                                                                                                           |
   |                       |                                                                       | Maximum: **10**                                                                                                                                                                                           |
   |                       |                                                                       |                                                                                                                                                                                                           |
   |                       |                                                                       | Default: **3**                                                                                                                                                                                            |
   +-----------------------+-----------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | monitor_port          | Integer                                                               | Specifies the port used for the health check. If this parameter is left blank, the port of the backend server group will be used by default.                                                              |
   |                       |                                                                       |                                                                                                                                                                                                           |
   |                       |                                                                       | Minimum: **1**                                                                                                                                                                                            |
   |                       |                                                                       |                                                                                                                                                                                                           |
   |                       |                                                                       | Maximum: **65535**                                                                                                                                                                                        |
   +-----------------------+-----------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                                                                | Specifies the health check name.                                                                                                                                                                          |
   +-----------------------+-----------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | pools                 | Array of :ref:`PoolRef <showhealthmonitor__response_poolref>` objects | Lists the IDs of backend server groups for which the health check is configured.                                                                                                                          |
   +-----------------------+-----------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | project_id            | String                                                                | Specifies the project ID.                                                                                                                                                                                 |
   +-----------------------+-----------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | timeout               | Integer                                                               | Specifies the maximum time required for waiting for a response from the health check, in seconds. It is recommended that you set the value less than that of parameter **delay**.                         |
   |                       |                                                                       |                                                                                                                                                                                                           |
   |                       |                                                                       | Minimum: **1**                                                                                                                                                                                            |
   |                       |                                                                       |                                                                                                                                                                                                           |
   |                       |                                                                       | Maximum: **50**                                                                                                                                                                                           |
   +-----------------------+-----------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | type                  | String                                                                | Specifies the health check protocol.                                                                                                                                                                      |
   +-----------------------+-----------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | url_path              | String                                                                | Specifies the HTTP request path for the health check. The value must start with a slash (/), and the default value is /. This parameter is available only when **type** is set to **HTTP**.               |
   |                       |                                                                       |                                                                                                                                                                                                           |
   |                       |                                                                       | Default: **/**                                                                                                                                                                                            |
   +-----------------------+-----------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _showhealthmonitor__response_poolref:

.. table:: **Table 5** PoolRef

   ========= ====== =============================================
   Parameter Type   Description
   ========= ====== =============================================
   id        String Specifies the ID of the backend server group.
   ========= ====== =============================================

Example Requests
----------------

.. code-block:: text

   GET

   https://{elb_endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/healthmonitors/c2b210b2-60c4-449d-91e2-9e9ea1dd7441

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

   {
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
     },
     "request_id" : "3702e8f0-f5f0-4d35-9097-fc7160005fae"
   }

Status Codes
------------

=========== ===================
Status Code Description
=========== ===================
200         Successful request.
=========== ===================

Error Codes
-----------

See :ref:`Error Codes <errorcode>`.
