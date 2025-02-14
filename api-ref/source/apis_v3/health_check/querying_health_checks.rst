:original_name: ListHealthMonitors.html

.. _ListHealthMonitors:

Querying Health Checks
======================

Function
--------

This API is used to query all health checks.

Constraints
-----------

This API has the following constraints:

-  Parameters **marker**, **limit**, and **page_reverse** are used for pagination query.

-  Parameters **marker** and **page_reverse** take effect only when they are used together with parameter **limit**.

URI
---

GET /v3/{project_id}/elb/healthmonitors

.. table:: **Table 1** Path Parameters

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
   ========== ========= ====== =========================

.. table:: **Table 2** Query Parameters

   +-----------------------+-----------------+-------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Mandatory       | Type              | Description                                                                                                                                                                                                                      |
   +=======================+=================+===================+==================================================================================================================================================================================================================================+
   | marker                | No              | String            | Specifies the ID of the last record on the previous page.                                                                                                                                                                        |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | Note:                                                                                                                                                                                                                            |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | -  This parameter must be used together with **limit**.                                                                                                                                                                          |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | -  If this parameter is not specified, the first page will be queried.                                                                                                                                                           |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | -  This parameter cannot be left blank or set to an invalid ID.                                                                                                                                                                  |
   +-----------------------+-----------------+-------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | limit                 | No              | Integer           | Specifies the number of records on each page.                                                                                                                                                                                    |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | Minimum: **0**                                                                                                                                                                                                                   |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | Maximum: **2000**                                                                                                                                                                                                                |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | Default: **2000**                                                                                                                                                                                                                |
   +-----------------------+-----------------+-------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | page_reverse          | No              | Boolean           | Specifies whether to use reverse query. Values:                                                                                                                                                                                  |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | -  **true**: Query the previous page.                                                                                                                                                                                            |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | -  **false** (default): Query the next page.                                                                                                                                                                                     |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | Note:                                                                                                                                                                                                                            |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | -  This parameter must be used together with **limit**.                                                                                                                                                                          |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | -  If **page_reverse** is set to **true** and you want to query the previous page, set the value of **marker** to the value of **previous_marker**.                                                                              |
   +-----------------------+-----------------+-------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | id                    | No              | Array of strings  | Specifies the health check ID.                                                                                                                                                                                                   |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | Multiple IDs can be queried in the format of *id=xxx&id=xxx*.                                                                                                                                                                    |
   +-----------------------+-----------------+-------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | monitor_port          | No              | Array of integers | Specifies the port used for the health check.                                                                                                                                                                                    |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | Multiple ports can be queried in the format of *monitor_port=xxx&monitor_port=xxx*.                                                                                                                                              |
   +-----------------------+-----------------+-------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | domain_name           | No              | Array of strings  | Specifies the domain name to which HTTP requests are sent during the health check.                                                                                                                                               |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | The value can contain only digits, letters, hyphens (-), and periods (.) and must start with a digit or letter.                                                                                                                  |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | Multiple domain names can be queried in the format of *domain_name=xxx&domain_name=xxx*.                                                                                                                                         |
   +-----------------------+-----------------+-------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | No              | Array of strings  | Specifies the health check name.                                                                                                                                                                                                 |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | Multiple names can be queried in the format of *name=xxx&name=xxx*.                                                                                                                                                              |
   +-----------------------+-----------------+-------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | delay                 | No              | Array of integers | Specifies the interval between health checks, in seconds. The value ranges from **1** to **50**.                                                                                                                                 |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | Multiple intervals can be queried in the format of *delay=xxx&delay=xxx*.                                                                                                                                                        |
   +-----------------------+-----------------+-------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | max_retries           | No              | Array of integers | Specifies the number of consecutive health checks when the health check result of a backend server changes from **OFFLINE** to **ONLINE**.                                                                                       |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | Multiple values can be queried in the format of *max_retries=xxx&max_retries=xxx*.                                                                                                                                               |
   +-----------------------+-----------------+-------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up        | No              | Boolean           | Specifies the administrative status of the health check.                                                                                                                                                                         |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | The value can be **true** (health check is enabled) or **false** (health check is disabled).                                                                                                                                     |
   +-----------------------+-----------------+-------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | max_retries_down      | No              | Array of integers | Specifies the number of consecutive health checks when the health check result of a backend server changes from **ONLINE** to **OFFLINE**. The value ranges from **1** to **10**.                                                |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | Multiple values can be queried in the format of *max_retries_down=xxx&max_retries_down=xxx*.                                                                                                                                     |
   +-----------------------+-----------------+-------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | timeout               | No              | Integer           | Specifies the maximum time required for waiting for a response from the health check, in seconds.                                                                                                                                |
   +-----------------------+-----------------+-------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | type                  | No              | Array of strings  | Specifies the health check protocol. The value can be **TCP**, **UDP_CONNECT**, **HTTP**, or **HTTPS**.                                                                                                                          |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | Multiple protocols can be queried in the format of *type=xxx&type=xxx*.                                                                                                                                                          |
   +-----------------------+-----------------+-------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | expected_codes        | No              | Array of strings  | Specifies the expected HTTP status code. This parameter will take effect only when **type** is set to **HTTP** or **HTTPS**.                                                                                                     |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | The value options are as follows:                                                                                                                                                                                                |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | -  A specific value, for example, 200                                                                                                                                                                                            |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | -  A list of values that are separated with commas (,), for example, 200, 202                                                                                                                                                    |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | -  A value range, for example, 200-204                                                                                                                                                                                           |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | The default value is **200**.                                                                                                                                                                                                    |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | Multiple status codes can be queried in the format of *expected_codes=xxx&expected_codes=xxx*.                                                                                                                                   |
   +-----------------------+-----------------+-------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | url_path              | No              | Array of strings  | Specifies the HTTP request path for the health check. The value must start with a slash (/), and the default value is **/**. This parameter is available only when **type** is set to **HTTP**.                                  |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | Multiple paths can be queried in the format of *url_path=xxx&url_path=xxx*.                                                                                                                                                      |
   +-----------------------+-----------------+-------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | http_method           | No              | Array of strings  | Specifies the HTTP method.                                                                                                                                                                                                       |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | The value can be **GET**, **HEAD**, **POST**, **PUT**, **DELETE**, **TRACE**, **OPTIONS**, **CONNECT**, or **PATCH**.                                                                                                            |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | Multiple methods can be queried in the format of *http_method=xxx&http_method=xxx*.                                                                                                                                              |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | This parameter is unsupported. Please do not use it.                                                                                                                                                                             |
   +-----------------------+-----------------+-------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | enterprise_project_id | No              | Array of strings  | Specifies the enterprise project ID.                                                                                                                                                                                             |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | -  If this parameter is not passed, resources in the default enterprise project are queried, and authentication is performed based on the default enterprise project.                                                            |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | -  If this parameter is passed, its value can be the ID of an existing enterprise project (resources in the specific enterprise project are required) or **all_granted_eps** (resources in all enterprise projects are queried). |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | Multiple IDs can be queried in the format of *enterprise_project_id=xxx&enterprise_project_id=xxx*.                                                                                                                              |
   |                       |                 |                   |                                                                                                                                                                                                                                  |
   |                       |                 |                   | This parameter is unsupported. Please do not use it.                                                                                                                                                                             |
   +-----------------------+-----------------+-------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Request Parameters
------------------

.. table:: **Table 3** Request header parameters

   +--------------+-----------+--------+--------------------------------------------------+
   | Parameter    | Mandatory | Type   | Description                                      |
   +==============+===========+========+==================================================+
   | X-Auth-Token | Yes       | String | Specifies the token used for IAM authentication. |
   +--------------+-----------+--------+--------------------------------------------------+

Response Parameters
-------------------

**Status code: 200**

.. table:: **Table 4** Response body parameters

   +----------------+------------------------------------------------------------------------------------+-----------------------------------------------------------------+
   | Parameter      | Type                                                                               | Description                                                     |
   +================+====================================================================================+=================================================================+
   | request_id     | String                                                                             | Specifies the request ID. The value is automatically generated. |
   +----------------+------------------------------------------------------------------------------------+-----------------------------------------------------------------+
   | page_info      | :ref:`PageInfo <listhealthmonitors__response_pageinfo>` object                     | Shows pagination information.                                   |
   +----------------+------------------------------------------------------------------------------------+-----------------------------------------------------------------+
   | healthmonitors | Array of :ref:`HealthMonitor <listhealthmonitors__response_healthmonitor>` objects | Specifies the health check.                                     |
   +----------------+------------------------------------------------------------------------------------+-----------------------------------------------------------------+

.. _listhealthmonitors__response_pageinfo:

.. table:: **Table 5** PageInfo

   +-----------------+---------+----------------------------------------------------------------------+
   | Parameter       | Type    | Description                                                          |
   +=================+=========+======================================================================+
   | previous_marker | String  | Specifies the ID of the first record in the pagination query result. |
   +-----------------+---------+----------------------------------------------------------------------+
   | next_marker     | String  | Specifies the ID of the last record in the pagination query result.  |
   +-----------------+---------+----------------------------------------------------------------------+
   | current_count   | Integer | Specifies the number of records.                                     |
   +-----------------+---------+----------------------------------------------------------------------+

.. _listhealthmonitors__response_healthmonitor:

.. table:: **Table 6** HealthMonitor

   +-----------------------+------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                                                                   | Description                                                                                                                                                                                                |
   +=======================+========================================================================+============================================================================================================================================================================================================+
   | admin_state_up        | Boolean                                                                | Specifies the administrative status of the health check.                                                                                                                                                   |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | -  **true**\ (default) indicates that the health check is enabled.                                                                                                                                         |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | -  **false** indicates that the health check is disabled.                                                                                                                                                  |
   +-----------------------+------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | delay                 | Integer                                                                | Specifies the interval between health checks, in seconds. The value ranges from **1** to **50**.                                                                                                           |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | Minimum: **1**                                                                                                                                                                                             |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | Maximum: **50**                                                                                                                                                                                            |
   +-----------------------+------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | domain_name           | String                                                                 | Specifies the domain name that HTTP requests are sent to during the health check.                                                                                                                          |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | The value can contain only digits, letters, hyphens (-), and periods (.) and must start with a digit or letter.                                                                                            |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | The value is left blank by default, indicating that the virtual IP address of the load balancer is used as the destination address of HTTP requests.                                                       |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | This parameter is available only when **type** is set to **HTTP**.                                                                                                                                         |
   +-----------------------+------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | expected_codes        | String                                                                 | Specifies the expected HTTP status code. This parameter will take effect only when **type** is set to **HTTP** or **HTTPS**.                                                                               |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | The value options are as follows:                                                                                                                                                                          |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | -  A specific value, for example, 200                                                                                                                                                                      |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | -  A list of values that are separated with commas (,), for example, 200, 202                                                                                                                              |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | -  A value range, for example, 200-204                                                                                                                                                                     |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | The default value is **200**.                                                                                                                                                                              |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | Multiple status codes can be queried in the format of *expected_codes=xxx&expected_codes=xxx*.                                                                                                             |
   +-----------------------+------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | http_method           | String                                                                 | Specifies the HTTP method. The value can be **GET**, **HEAD**, **POST**, **PUT**, **DELETE**, **TRACE**, **OPTIONS**, **CONNECT**, or **PATCH**. The default value is **GET**.                             |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | This parameter is available when **type** is set to **HTTP** or **HTTPS**.                                                                                                                                 |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | This parameter is unsupported. Please do not use it.                                                                                                                                                       |
   +-----------------------+------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | id                    | String                                                                 | Specifies the health check ID.                                                                                                                                                                             |
   +-----------------------+------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | max_retries           | Integer                                                                | Specifies the number of consecutive health checks when the health check result of a backend server changes from **OFFLINE** to **ONLINE**.                                                                 |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | The value ranges from **1** to **10**                                                                                                                                                                      |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | Minimum: **1**                                                                                                                                                                                             |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | Maximum: **10**                                                                                                                                                                                            |
   +-----------------------+------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | max_retries_down      | Integer                                                                | Specifies the number of consecutive health checks when the health check result of a backend server changes from **ONLINE** to **OFFLINE**.                                                                 |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | The value ranges from **1** to **10**, and the default value is **3**.                                                                                                                                     |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | Minimum: **1**                                                                                                                                                                                             |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | Maximum: **10**                                                                                                                                                                                            |
   +-----------------------+------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | monitor_port          | Integer                                                                | Specifies the port used for the health check. If this parameter is left blank, a port of the backend server will be used by default. The port number ranges from 1 to 65535.                               |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | Minimum: **1**                                                                                                                                                                                             |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | Maximum: **65535**                                                                                                                                                                                         |
   +-----------------------+------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                                                                 | Specifies the health check name.                                                                                                                                                                           |
   +-----------------------+------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | pools                 | Array of :ref:`PoolRef <listhealthmonitors__response_poolref>` objects | Lists the IDs of backend server groups for which the health check is configured. Only one ID will be returned.                                                                                             |
   +-----------------------+------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | project_id            | String                                                                 | Specifies the project ID.                                                                                                                                                                                  |
   +-----------------------+------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | timeout               | Integer                                                                | Specifies the maximum time required for waiting for a response from the health check, in seconds.                                                                                                          |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | It is recommended that you set the value less than that of parameter **delay**.                                                                                                                            |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | Minimum: **1**                                                                                                                                                                                             |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | Maximum: **50**                                                                                                                                                                                            |
   +-----------------------+------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | type                  | String                                                                 | Specifies the health check protocol. The value can be **TCP**, **UDP_CONNECT**, **HTTP**, or **HTTPS**.                                                                                                    |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | Note:                                                                                                                                                                                                      |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | -  If the protocol of the backend server is QUIC, the value can only be **UDP_CONNECT**.                                                                                                                   |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | -  If the protocol of the backend server is UDP, the value can only be **UDP_CONNECT**.                                                                                                                    |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | -  If the protocol of the backend server is TCP, the value can only be **TCP**, **HTTP**, or **HTTPS**.                                                                                                    |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | -  If the protocol of the backend server is HTTP, the value can only be **TCP**, **HTTP**, or **HTTPS**.                                                                                                   |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | -  If the protocol of the backend server is HTTPS, the value can only be **TCP**, **HTTP**, or **HTTPS**.                                                                                                  |
   +-----------------------+------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | url_path              | String                                                                 | Specifies the HTTP request path for the health check. The value must start with a slash (/), and the default value is **/**.                                                                               |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | Note: This parameter is available only when **type** is set to **HTTP**.                                                                                                                                   |
   +-----------------------+------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | created_at            | String                                                                 | Specifies the time when the health check was configured. The format is yyyy-MM-dd'T'HH:mm:ss'Z' (UTC time).                                                                                                |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | This is a new field in this version, and it will not be returned for resources associated with existing dedicated load balancers and for resources associated with existing and new shared load balancers. |
   +-----------------------+------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | updated_at            | String                                                                 | Specifies the time when the health check was updated. The format is yyyy-MM-dd'T'HH:mm:ss'Z' (UTC time).                                                                                                   |
   |                       |                                                                        |                                                                                                                                                                                                            |
   |                       |                                                                        | This is a new field in this version, and it will not be returned for resources associated with existing dedicated load balancers and for resources associated with existing and new shared load balancers. |
   +-----------------------+------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _listhealthmonitors__response_poolref:

.. table:: **Table 7** PoolRef

   ========= ====== =============================================
   Parameter Type   Description
   ========= ====== =============================================
   id        String Specifies the ID of the backend server group.
   ========= ====== =============================================

Example Requests
----------------

.. code-block:: text

   GET https://{ELB_Endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/healthmonitors

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

   {
     "healthmonitors" : [ {
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
     }, {
       "monitor_port" : null,
       "id" : "cda1af03-0660-4fd2-8edf-e38c79846e08",
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "domain_name" : "akik..un.com",
       "name" : "lijunqiu",
       "delay" : 50,
       "max_retries" : 1,
       "pools" : [ {
         "id" : "ae6e45ba-be84-4074-8ac6-bc4a56484809"
       } ],
       "admin_state_up" : false,
       "timeout" : 3,
       "type" : "UDP_CONNECT",
       "expected_codes" : null,
       "url_path" : "/world",
       "http_method" : null
     } ],
     "page_info" : {
       "next_marker" : "cda1af03-0660-4fd2-8edf-e38c79846e08",
       "previous_marker" : "c2b210b2-60c4-449d-91e2-9e9ea1dd7441",
       "current_count" : 2
     },
     "request_id" : "814bc40e-8b0a-4ced-b8e5-f136c3e1df6a"
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
