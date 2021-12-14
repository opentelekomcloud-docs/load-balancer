============
Health Check
============

Configuring a Health Check
==========================

Function
^^^^^^^^

This API is used to configure a health check.

Constraints
^^^^^^^^^^^

The security groups must have rules that allow access from 100.125.0.0/16. If
you want to use UDP for health checks, ensure that the protocol of the backend
server group is UDP.
THIS IS A TYPO

URI
^^^

POST /v3/{project_id}/elb/healthmonitors

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

   +---------------+-----------+----------------------+-----------------------------+
   | Parameter     | Mandatory | Type                 | Description                 |
   +===============+===========+======================+=============================+
   | healthmonitor | Yes       | :ref:`dhmc_o` object | Specifies the health check. |
   +---------------+-----------+----------------------+-----------------------------+

.. _dhmc_o:
.. table:: **Table 4** CreateHealthMonitorOption

   +------------------+-----------+---------+-----------------------------+
   | Parameter        | Mandatory | Type    | Description                 |
   +==================+===========+=========+=============================+
   | admin_state_up   | No        | Boolean | Specifies the               |
   |                  |           |         | administrative status of    |
   |                  |           |         | the health check. Two value |
   |                  |           |         | options are available.      |
   |                  |           |         | **true** indicates that the |
   |                  |           |         | health check is enabled,    |
   |                  |           |         | and **false** indicates     |
   |                  |           |         | that the health check is    |
   |                  |           |         | disabled.                   |
   |                  |           |         |                             |
   |                  |           |         | Default: **true**           |
   +------------------+-----------+---------+-----------------------------+
   | delay            | Yes       | Integer | Specifies the interval      |
   |                  |           |         | between health checks, in   |
   |                  |           |         | seconds.                    |
   |                  |           |         |                             |
   |                  |           |         | Minimum: **1**              |
   |                  |           |         |                             |
   |                  |           |         | Maximum: **50**             |
   +------------------+-----------+---------+-----------------------------+
   | domain_name      | No        | String  | Specifies the domain name   |
   |                  |           |         | that HTTP requests are sent |
   |                  |           |         | to during the health check. |
   |                  |           |         |                             |
   |                  |           |         | This parameter is available |
   |                  |           |         | only when **type** is set   |
   |                  |           |         | to **HTTP**.                |
   |                  |           |         |                             |
   |                  |           |         | The value is left blank by  |
   |                  |           |         | default, indicating that    |
   |                  |           |         | the virtual IP address of   |
   |                  |           |         | the load balancer is used   |
   |                  |           |         | as the destination address  |
   |                  |           |         | of HTTP requests.           |
   |                  |           |         |                             |
   |                  |           |         | The value can contain only  |
   |                  |           |         | digits, letters, hyphens    |
   |                  |           |         | (-), and periods (.) and    |
   |                  |           |         | must start with a digit or  |
   |                  |           |         | letter.                     |
   |                  |           |         |                             |
   |                  |           |         | Minimum: **1**              |
   |                  |           |         |                             |
   |                  |           |         | Maximum: **100**            |
   +------------------+-----------+---------+-----------------------------+
   | expected_codes   | No        | String  | Specifies the expected HTTP |
   |                  |           |         | status code. This parameter |
   |                  |           |         | will take effect only when  |
   |                  |           |         | **type** is set to          |
   |                  |           |         | **HTTP**.                   |
   |                  |           |         |                             |
   |                  |           |         | The value options are as    |
   |                  |           |         | follows:                    |
   |                  |           |         |                             |
   |                  |           |         | -  A specific value, for    |
   |                  |           |         |    example, 200             |
   |                  |           |         |                             |
   |                  |           |         | -  A list of values that    |
   |                  |           |         |    are separated with       |
   |                  |           |         |    commas (,), for example, |
   |                  |           |         |    200, 202                 |
   |                  |           |         |                             |
   |                  |           |         | -  A value range, for       |
   |                  |           |         |    example, 200-204         |
   |                  |           |         |                             |
   |                  |           |         | This parameter is           |
   |                  |           |         | unsupported. Please do not  |
   |                  |           |         | use it.                     |
   |                  |           |         |                             |
   |                  |           |         | Default: **200**            |
   |                  |           |         |                             |
   |                  |           |         | Minimum: **1**              |
   |                  |           |         |                             |
   |                  |           |         | Maximum: **64**             |
   +------------------+-----------+---------+-----------------------------+
   | http_method      | No        | String  | Specifies the HTTP method.  |
   |                  |           |         |                             |
   |                  |           |         | The value can be **GET**,   |
   |                  |           |         | **HEAD**, **POST**,         |
   |                  |           |         | **PUT**, **DELETE**,        |
   |                  |           |         | **TRACE**, **OPTIONS**,     |
   |                  |           |         | **CONNECT**, or **PATCH**.  |
   |                  |           |         |                             |
   |                  |           |         | This parameter will take    |
   |                  |           |         | effect only when **type**   |
   |                  |           |         | is set to **HTTP**.         |
   |                  |           |         |                             |
   |                  |           |         | This parameter is           |
   |                  |           |         | unsupported. Please do not  |
   |                  |           |         | use it.                     |
   |                  |           |         |                             |
   |                  |           |         | Default: **GET**            |
   |                  |           |         |                             |
   |                  |           |         | Minimum: **1**              |
   |                  |           |         |                             |
   |                  |           |         | Maximum: **16**             |
   +------------------+-----------+---------+-----------------------------+
   | max_retries      | Yes       | Integer | Specifies the number of     |
   |                  |           |         | consecutive health checks   |
   |                  |           |         | when the health check       |
   |                  |           |         | result of a backend server  |
   |                  |           |         | changes from **OFFLINE** to |
   |                  |           |         | **ONLINE**. The value       |
   |                  |           |         | ranges from **1** to        |
   |                  |           |         | **10**.                     |
   |                  |           |         |                             |
   |                  |           |         | Minimum: **1**              |
   |                  |           |         |                             |
   |                  |           |         | Maximum: **10**             |
   +------------------+-----------+---------+-----------------------------+
   | max_retries_down | No        | Integer | Specifies the number of     |
   |                  |           |         | consecutive health checks   |
   |                  |           |         | when the health check       |
   |                  |           |         | result of a backend server  |
   |                  |           |         | changes from **ONLINE** to  |
   |                  |           |         | **OFFLINE**.                |
   |                  |           |         |                             |
   |                  |           |         | Minimum: **1**              |
   |                  |           |         |                             |
   |                  |           |         | Maximum: **10**             |
   |                  |           |         |                             |
   |                  |           |         | Default: **3**              |
   +------------------+-----------+---------+-----------------------------+
   | monitor_port     | No        | Integer | Specifies the port used for |
   |                  |           |         | the health check. If this   |
   |                  |           |         | parameter is left blank,    |
   |                  |           |         | the port of the backend     |
   |                  |           |         | server group will be used   |
   |                  |           |         | by default.                 |
   |                  |           |         |                             |
   |                  |           |         | Minimum: **1**              |
   |                  |           |         |                             |
   |                  |           |         | Maximum: **65535**          |
   +------------------+-----------+---------+-----------------------------+
   | name             | No        | String  | Specifies the health check  |
   |                  |           |         | name.                       |
   |                  |           |         |                             |
   |                  |           |         | Minimum: **0**              |
   |                  |           |         |                             |
   |                  |           |         | Maximum: **255**            |
   +------------------+-----------+---------+-----------------------------+
   | pool_id          | Yes       | String  | Specifies the ID of the     |
   |                  |           |         | backend server group for    |
   |                  |           |         | which the health check is   |
   |                  |           |         | configured.                 |
   +------------------+-----------+---------+-----------------------------+
   | project_id       | No        | String  | Specifies the project ID.   |
   |                  |           |         |                             |
   |                  |           |         | Minimum: **1**              |
   |                  |           |         |                             |
   |                  |           |         | Maximum: **32**             |
   +------------------+-----------+---------+-----------------------------+
   | timeout          | Yes       | Integer | Specifies the maximum time  |
   |                  |           |         | required for waiting for a  |
   |                  |           |         | response from the health    |
   |                  |           |         | check, in seconds. It is    |
   |                  |           |         | recommended that you set    |
   |                  |           |         | the value less than that of |
   |                  |           |         | parameter **delay**.        |
   |                  |           |         |                             |
   |                  |           |         | Minimum: **1**              |
   |                  |           |         |                             |
   |                  |           |         | Maximum: **50**             |
   +------------------+-----------+---------+-----------------------------+
   | type             | Yes       | String  | Specifies the health check  |
   |                  |           |         | protocol.                   |
   |                  |           |         |                             |
   |                  |           |         | The value can be **TCP**,   |
   |                  |           |         | **UDP_CONNECT**, **HTTP**,  |
   |                  |           |         | **HTTPS**, or **PING**.     |
   +------------------+-----------+---------+-----------------------------+
   | url_path         | No        | String  | Specifies the HTTP request  |
   |                  |           |         | path for the health check.  |
   |                  |           |         | The value must start with a |
   |                  |           |         | slash (/), and the default  |
   |                  |           |         | value is /. This parameter  |
   |                  |           |         | is available only when      |
   |                  |           |         | **type** is set to          |
   |                  |           |         | **HTTP**.                   |
   |                  |           |         |                             |
   |                  |           |         | Default: **/**              |
   |                  |           |         |                             |
   |                  |           |         | Minimum: **1**              |
   |                  |           |         |                             |
   |                  |           |         | Maximum: **255**            |
   +------------------+-----------+---------+-----------------------------+

Response Parameters
^^^^^^^^^^^^^^^^^^^

**Status code: 201**

.. table:: **Table 5** Response body parameters

   +---------------+-------------------------------------------------+----------------------------------------+
   | Parameter     | Type                                            | Description                            |
   +===============+=================================================+========================================+
   | request_id    | String                                          | Specifies the request ID. The value is |
   |               |                                                 | automatically generated.               |
   +---------------+-------------------------------------------------+----------------------------------------+
   | healthmonitor | :ref:`dhmc_hm` object                           | Specifies the health check.            |
   +---------------+-------------------------------------------------+----------------------------------------+

.. _dhmc_hm:
.. table:: **Table 6** HealthMonitor

   +------------------+---------------------------------+---------------------------------------+
   | Parameter        | Type                            | Description                           |
   +==================+=================================+=======================================+
   | admin_state_up   | Boolean                         | Specifies the administrative status   |
   |                  |                                 | of the health check. Two value        |
   |                  |                                 | options are available. **true**       |
   |                  |                                 | indicates that the health check is    |
   |                  |                                 | enabled, and **false** indicates that |
   |                  |                                 | the health check is disabled.         |
   |                  |                                 |                                       |
   |                  |                                 | Default: **true**                     |
   +------------------+---------------------------------+---------------------------------------+
   | delay            | Integer                         | Specifies the interval between health |
   |                  |                                 | checks, in seconds.                   |
   |                  |                                 |                                       |
   |                  |                                 | Minimum: **1**                        |
   |                  |                                 |                                       |
   |                  |                                 | Maximum: **50**                       |
   +------------------+---------------------------------+---------------------------------------+
   | domain_name      | String                          | Specifies the domain name that HTTP   |
   |                  |                                 | requests are sent to during the       |
   |                  |                                 | health check.                         |
   |                  |                                 |                                       |
   |                  |                                 | This parameter is available only when |
   |                  |                                 | **type** is set to **HTTP**.          |
   |                  |                                 |                                       |
   |                  |                                 | The value is left blank by default,   |
   |                  |                                 | indicating that the virtual IP        |
   |                  |                                 | address of the load balancer is used  |
   |                  |                                 | as the destination address of HTTP    |
   |                  |                                 | requests.                             |
   |                  |                                 |                                       |
   |                  |                                 | The value can contain only digits,    |
   |                  |                                 | letters, hyphens (-), and periods (.) |
   |                  |                                 | and must start with a digit or        |
   |                  |                                 | letter.                               |
   +------------------+---------------------------------+---------------------------------------+
   | expected_codes   | String                          | Specifies the expected HTTP status    |
   |                  |                                 | code. This parameter will take effect |
   |                  |                                 | only when **type** is set to          |
   |                  |                                 | **HTTP**.                             |
   |                  |                                 |                                       |
   |                  |                                 | The value options are as follows:     |
   |                  |                                 |                                       |
   |                  |                                 | -  A specific value, for example, 200 |
   |                  |                                 |                                       |
   |                  |                                 | -  A list of values that are          |
   |                  |                                 |    separated with commas (,), for     |
   |                  |                                 |    example, 200, 202                  |
   |                  |                                 |                                       |
   |                  |                                 | -  A value range, for example,        |
   |                  |                                 |    200-204                            |
   |                  |                                 |                                       |
   |                  |                                 | This parameter is unsupported. Please |
   |                  |                                 | do not use it.                        |
   |                  |                                 |                                       |
   |                  |                                 | Default: **200**                      |
   +------------------+---------------------------------+---------------------------------------+
   | http_method      | String                          | Specifies the HTTP method. This       |
   |                  |                                 | parameter will take effect only when  |
   |                  |                                 | **type** is set to **HTTP**.          |
   |                  |                                 |                                       |
   |                  |                                 | The value can be **GET**, **HEAD**,   |
   |                  |                                 | **POST**, **PUT**, **DELETE**,        |
   |                  |                                 | **TRACE**, **OPTIONS**, **CONNECT**,  |
   |                  |                                 | or **PATCH**.                         |
   |                  |                                 |                                       |
   |                  |                                 | This parameter is unsupported. Please |
   |                  |                                 | do not use it.                        |
   |                  |                                 |                                       |
   |                  |                                 | Default: **GET**                      |
   +------------------+---------------------------------+---------------------------------------+
   | id               | String                          | Specifies the health check ID.        |
   +------------------+---------------------------------+---------------------------------------+
   | max_retries      | Integer                         | Specifies the number of consecutive   |
   |                  |                                 | health checks when the health check   |
   |                  |                                 | result of a backend server changes    |
   |                  |                                 | from **OFFLINE** to **ONLINE**. The   |
   |                  |                                 | value ranges from **1** to **10**.    |
   |                  |                                 |                                       |
   |                  |                                 | Minimum: **1**                        |
   |                  |                                 |                                       |
   |                  |                                 | Maximum: **10**                       |
   +------------------+---------------------------------+---------------------------------------+
   | max_retries_down | Integer                         | Specifies the number of consecutive   |
   |                  |                                 | health checks when the health check   |
   |                  |                                 | result of a backend server changes    |
   |                  |                                 | from **ONLINE** to **OFFLINE**.       |
   |                  |                                 |                                       |
   |                  |                                 | Minimum: **1**                        |
   |                  |                                 |                                       |
   |                  |                                 | Maximum: **10**                       |
   |                  |                                 |                                       |
   |                  |                                 | Default: **3**                        |
   +------------------+---------------------------------+---------------------------------------+
   | monitor_port     | Integer                         | Specifies the port used for the       |
   |                  |                                 | health check. If this parameter is    |
   |                  |                                 | left blank, the port of the backend   |
   |                  |                                 | server group will be used by default. |
   |                  |                                 |                                       |
   |                  |                                 | Minimum: **1**                        |
   |                  |                                 |                                       |
   |                  |                                 | Maximum: **65535**                    |
   +------------------+---------------------------------+---------------------------------------+
   | name             | String                          | Specifies the health check name.      |
   +------------------+---------------------------------+---------------------------------------+
   | pools            | Array of :ref:`dhmc_pr` objects | Lists the IDs of backend server       |
   |                  |                                 | groups for which the health check is  |
   |                  |                                 | configured.                           |
   +------------------+---------------------------------+---------------------------------------+
   | project_id       | String                          | Specifies the project ID.             |
   +------------------+---------------------------------+---------------------------------------+
   | timeout          | Integer                         | Specifies the maximum time required   |
   |                  |                                 | for waiting for a response from the   |
   |                  |                                 | health check, in seconds. It is       |
   |                  |                                 | recommended that you set the value    |
   |                  |                                 | less than that of parameter           |
   |                  |                                 | **delay**.                            |
   |                  |                                 |                                       |
   |                  |                                 | Minimum: **1**                        |
   |                  |                                 |                                       |
   |                  |                                 | Maximum: **50**                       |
   +------------------+---------------------------------+---------------------------------------+
   | type             | String                          | Specifies the health check protocol.  |
   +------------------+---------------------------------+---------------------------------------+
   | url_path         | String                          | Specifies the HTTP request path for   |
   |                  |                                 | the health check. The value must      |
   |                  |                                 | start with a slash (/), and the       |
   |                  |                                 | default value is /. This parameter is |
   |                  |                                 | available only when **type** is set   |
   |                  |                                 | to **HTTP**.                          |
   |                  |                                 |                                       |
   |                  |                                 | Default: **/**                        |
   +------------------+---------------------------------+---------------------------------------+

.. _dhmc_pr:
.. table:: **Table 7** PoolRef

   ========= ====== =============================================
   Parameter Type   Description
   ========= ====== =============================================
   id        String Specifies the ID of the backend server group.
   ========= ====== =============================================

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   POST

   https://{elb_endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/healthmonitors

   {
     "healthmonitor" : {
       "name" : "My Healthmonitor",
       "max_retries" : 3,
       "pool_id" : "488acc50-6bcf-423d-8f0a-0f4184f5b8a0",
       "type" : "HTTP",
       "timeout" : 30,
       "delay" : 1
     }
   }

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 201**

Successful request.

.. code::

   {
     "request_id" : "0e837340-f1bd-4037-8f61-9923d0f0b19e",
     "healthmonitor" : {
       "id" : "c2b210b2-60c4-449d-91e2-9e9ea1dd7441",
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "name" : "My Healthmonitor",
       "delay" : 1,
       "max_retries" : 3,
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
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
201         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Querying Health Checks
======================

Function
^^^^^^^^

This API is used to query all health checks.

Constraints
^^^^^^^^^^^

Parameters **marker**, **limit**, and **page_reverse** are used for pagination
query.

Parameters **marker** and **page_reverse** take effect only when they are used
together with parameter **limit**.

URI
^^^

GET /v3/{project_id}/elb/healthmonitors

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
   |                       |           |         | direction.                  |
   |                       |           |         |                             |
   |                       |           |         | The value can be **true**   |
   |                       |           |         | or **false**, and the       |
   |                       |           |         | default value is **false**. |
   |                       |           |         |                             |
   |                       |           |         | The last page in the list   |
   |                       |           |         | requested with              |
   |                       |           |         | **page_reverse** set to     |
   |                       |           |         | **false** will not contain  |
   |                       |           |         | the "next" link, and the    |
   |                       |           |         | last page in the list       |
   |                       |           |         | requested with              |
   |                       |           |         | **page_reverse** set to     |
   |                       |           |         | **true** will not contain   |
   |                       |           |         | the "previous" link.        |
   |                       |           |         |                             |
   |                       |           |         | This parameter must be used |
   |                       |           |         | together with **limit**.    |
   +-----------------------+-----------+---------+-----------------------------+
   | id                    | No        | Array   | Specifies the health check  |
   |                       |           |         | ID.                         |
   |                       |           |         |                             |
   |                       |           |         | Multiple IDs can be queried |
   |                       |           |         | in the format of            |
   |                       |           |         | *id=xxx&id=xxx*.            |
   +-----------------------+-----------+---------+-----------------------------+
   | monitor_port          | No        | Array   | Specifies the port used for |
   |                       |           |         | the health check.           |
   |                       |           |         |                             |
   |                       |           |         | Multiple ports can be       |
   |                       |           |         | queried in the format of    |
   |                       |           |         | *monitor_                   |
   |                       |           |         | port=xxx&monitor_port=xxx*. |
   +-----------------------+-----------+---------+-----------------------------+
   | domain_name           | No        | Array   | Specifies the domain name   |
   |                       |           |         | to which HTTP requests are  |
   |                       |           |         | sent during the health      |
   |                       |           |         | check.                      |
   |                       |           |         |                             |
   |                       |           |         | This parameter will take    |
   |                       |           |         | effect only when **type**   |
   |                       |           |         | is set to **HTTP**.         |
   |                       |           |         |                             |
   |                       |           |         | The value is left blank by  |
   |                       |           |         | default, indicating that    |
   |                       |           |         | the virtual IP address      |
   |                       |           |         | bound to the load balancer  |
   |                       |           |         | is used as the destination  |
   |                       |           |         | of HTTP requests.           |
   |                       |           |         |                             |
   |                       |           |         | The value can contain only  |
   |                       |           |         | digits, letters, hyphens    |
   |                       |           |         | (-), and periods (.) and    |
   |                       |           |         | must start with a digit or  |
   |                       |           |         | letter.                     |
   |                       |           |         |                             |
   |                       |           |         | Multiple domain names can   |
   |                       |           |         | be queried in the format of |
   |                       |           |         | *domain                     |
   |                       |           |         | _name=xxx&domain_name=xxx*. |
   +-----------------------+-----------+---------+-----------------------------+
   | name                  | No        | Array   | Specifies the health check  |
   |                       |           |         | name.                       |
   |                       |           |         |                             |
   |                       |           |         | Multiple names can be       |
   |                       |           |         | queried in the format of    |
   |                       |           |         | *name=xxx&name=xxx*.        |
   +-----------------------+-----------+---------+-----------------------------+
   | delay                 | No        | Array   | Specifies the interval      |
   |                       |           |         | between health checks, in   |
   |                       |           |         | seconds.                    |
   |                       |           |         |                             |
   |                       |           |         | Multiple intervals can be   |
   |                       |           |         | queried in the format of    |
   |                       |           |         | *delay=xxx&delay=xxx*.      |
   +-----------------------+-----------+---------+-----------------------------+
   | max_retries           | No        | Array   | Specifies the maximum       |
   |                       |           |         | number of retries.          |
   |                       |           |         |                             |
   |                       |           |         | Multiple values can be      |
   |                       |           |         | queried in the format of    |
   |                       |           |         | *max_re                     |
   |                       |           |         | tries=xxx&max_retries=xxx*. |
   +-----------------------+-----------+---------+-----------------------------+
   | admin_state_up        | No        | Boolean | Specifies the               |
   |                       |           |         | administrative status of    |
   |                       |           |         | the health check.           |
   |                       |           |         |                             |
   |                       |           |         | Although this parameter can |
   |                       |           |         | be used in the APIs for     |
   |                       |           |         | creating and updating       |
   |                       |           |         | health checks, its actual   |
   |                       |           |         | value depends on whether    |
   |                       |           |         | cloud servers that serve as |
   |                       |           |         | the backend servers exist.  |
   |                       |           |         | If cloud servers exist, the |
   |                       |           |         | value is **true**.          |
   |                       |           |         | Otherwise, the value is     |
   |                       |           |         | **false**.                  |
   +-----------------------+-----------+---------+-----------------------------+
   | max_retries_down      | No        | Array   | Specifies the number of     |
   |                       |           |         | consecutive health checks   |
   |                       |           |         | when the health check       |
   |                       |           |         | result of a backend server  |
   |                       |           |         | changes from **ONLINE** to  |
   |                       |           |         | **OFFLINE**. The value      |
   |                       |           |         | ranges from **1** to        |
   |                       |           |         | **10**.                     |
   +-----------------------+-----------+---------+-----------------------------+
   | timeout               | No        | Integer | Specifies the maximum time  |
   |                       |           |         | required for waiting for a  |
   |                       |           |         | response from the health    |
   |                       |           |         | check, in seconds. It is    |
   |                       |           |         | recommended that you set    |
   |                       |           |         | the value less than that of |
   |                       |           |         | parameter **delay**.        |
   +-----------------------+-----------+---------+-----------------------------+
   | type                  | No        | Array   | Specifies the health check  |
   |                       |           |         | protocol.                   |
   |                       |           |         |                             |
   |                       |           |         | Multiple protocols can be   |
   |                       |           |         | queried in the format of    |
   |                       |           |         | *type=xxx&type=xxx*.        |
   +-----------------------+-----------+---------+-----------------------------+
   | expected_codes        | No        | Array   | Specifies the expected HTTP |
   |                       |           |         | status code. This parameter |
   |                       |           |         | will take effect only when  |
   |                       |           |         | **type** is set to          |
   |                       |           |         | **HTTP**.                   |
   |                       |           |         |                             |
   |                       |           |         | The value options are as    |
   |                       |           |         | follows:                    |
   |                       |           |         |                             |
   |                       |           |         | -  A specific value, for    |
   |                       |           |         |    example, 200             |
   |                       |           |         |                             |
   |                       |           |         | -  A list of values that    |
   |                       |           |         |    are separated with       |
   |                       |           |         |    commas (,), for example, |
   |                       |           |         |    200, 202                 |
   |                       |           |         |                             |
   |                       |           |         | -  A value range, for       |
   |                       |           |         |    example, 200-204         |
   |                       |           |         |                             |
   |                       |           |         | Multiple status codes can   |
   |                       |           |         | be queried in the format of |
   |                       |           |         | *expected_cod               |
   |                       |           |         | es=xxx&expected_codes=xxx*. |
   |                       |           |         |                             |
   |                       |           |         | This parameter is           |
   |                       |           |         | unsupported. Please do not  |
   |                       |           |         | use it.                     |
   +-----------------------+-----------+---------+-----------------------------+
   | url_path              | No        | Array   | Specifies the HTTP request  |
   |                       |           |         | path for the health check.  |
   |                       |           |         | The value must start with a |
   |                       |           |         | slash (/), and the default  |
   |                       |           |         | value is /. This parameter  |
   |                       |           |         | is available only when      |
   |                       |           |         | **type** is set to          |
   |                       |           |         | **HTTP**.                   |
   |                       |           |         |                             |
   |                       |           |         | Multiple paths can be       |
   |                       |           |         | queried in the format of    |
   |                       |           |         | *                           |
   |                       |           |         | url_path=xxx&url_path=xxx*. |
   +-----------------------+-----------+---------+-----------------------------+
   | http_method           | No        | Array   | Specifies the HTTP method.  |
   |                       |           |         | This parameter will take    |
   |                       |           |         | effect only when **type**   |
   |                       |           |         | is set to **HTTP**.         |
   |                       |           |         |                             |
   |                       |           |         | The value can be **GET**,   |
   |                       |           |         | **HEAD**, **POST**,         |
   |                       |           |         | **PUT**, **DELETE**,        |
   |                       |           |         | **TRACE**, **OPTIONS**,     |
   |                       |           |         | **CONNECT**, or **PATCH**.  |
   |                       |           |         |                             |
   |                       |           |         | Multiple methods can be     |
   |                       |           |         | queried in the format of    |
   |                       |           |         | *http_m                     |
   |                       |           |         | ethod=xxx&http_method=xxx*. |
   |                       |           |         |                             |
   |                       |           |         | This parameter is           |
   |                       |           |         | unsupported. Please do not  |
   |                       |           |         | use it.                     |
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

   +----------------+---------------------------------+----------------------------------------+
   | Parameter      | Type                            | Description                            |
   +================+=================================+========================================+
   | request_id     | String                          | Specifies the request ID. The value is |
   |                |                                 | automatically generated.               |
   +----------------+---------------------------------+----------------------------------------+
   | page_info      | :ref:`dhml_pi` object           | Shows pagination information.          |
   +----------------+---------------------------------+----------------------------------------+
   | healthmonitors | Array of :ref:`dhml_hm` objects | Specifies the health check.            |
   +----------------+---------------------------------+----------------------------------------+

.. _dhml_pi:
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

.. _dhml_hm:
.. table:: **Table 6** HealthMonitor

   +------------------+---------------------------------+---------------------------------------+
   | Parameter        | Type                            | Description                           |
   +==================+=================================+=======================================+
   | admin_state_up   | Boolean                         | Specifies the administrative status   |
   |                  |                                 | of the health check. Two value        |
   |                  |                                 | options are available. **true**       |
   |                  |                                 | indicates that the health check is    |
   |                  |                                 | enabled, and **false** indicates that |
   |                  |                                 | the health check is disabled.         |
   |                  |                                 |                                       |
   |                  |                                 | Default: **true**                     |
   +------------------+---------------------------------+---------------------------------------+
   | delay            | Integer                         | Specifies the interval between health |
   |                  |                                 | checks, in seconds.                   |
   |                  |                                 |                                       |
   |                  |                                 | Minimum: **1**                        |
   |                  |                                 |                                       |
   |                  |                                 | Maximum: **50**                       |
   +------------------+---------------------------------+---------------------------------------+
   | domain_name      | String                          | Specifies the domain name that HTTP   |
   |                  |                                 | requests are sent to during the       |
   |                  |                                 | health check.                         |
   |                  |                                 |                                       |
   |                  |                                 | This parameter is available only when |
   |                  |                                 | **type** is set to **HTTP**.          |
   |                  |                                 |                                       |
   |                  |                                 | The value is left blank by default,   |
   |                  |                                 | indicating that the virtual IP        |
   |                  |                                 | address of the load balancer is used  |
   |                  |                                 | as the destination address of HTTP    |
   |                  |                                 | requests.                             |
   |                  |                                 |                                       |
   |                  |                                 | The value can contain only digits,    |
   |                  |                                 | letters, hyphens (-), and periods (.) |
   |                  |                                 | and must start with a digit or        |
   |                  |                                 | letter.                               |
   +------------------+---------------------------------+---------------------------------------+
   | expected_codes   | String                          | Specifies the expected HTTP status    |
   |                  |                                 | code. This parameter will take effect |
   |                  |                                 | only when **type** is set to          |
   |                  |                                 | **HTTP**.                             |
   |                  |                                 |                                       |
   |                  |                                 | The value options are as follows:     |
   |                  |                                 |                                       |
   |                  |                                 | -  A specific value, for example, 200 |
   |                  |                                 |                                       |
   |                  |                                 | -  A list of values that are          |
   |                  |                                 |    separated with commas (,), for     |
   |                  |                                 |    example, 200, 202                  |
   |                  |                                 |                                       |
   |                  |                                 | -  A value range, for example,        |
   |                  |                                 |    200-204                            |
   |                  |                                 |                                       |
   |                  |                                 | This parameter is unsupported. Please |
   |                  |                                 | do not use it.                        |
   |                  |                                 |                                       |
   |                  |                                 | Default: **200**                      |
   +------------------+---------------------------------+---------------------------------------+
   | http_method      | String                          | Specifies the HTTP method. This       |
   |                  |                                 | parameter will take effect only when  |
   |                  |                                 | **type** is set to **HTTP**.          |
   |                  |                                 |                                       |
   |                  |                                 | The value can be **GET**, **HEAD**,   |
   |                  |                                 | **POST**, **PUT**, **DELETE**,        |
   |                  |                                 | **TRACE**, **OPTIONS**, **CONNECT**,  |
   |                  |                                 | or **PATCH**.                         |
   |                  |                                 |                                       |
   |                  |                                 | This parameter is unsupported. Please |
   |                  |                                 | do not use it.                        |
   |                  |                                 |                                       |
   |                  |                                 | Default: **GET**                      |
   +------------------+---------------------------------+---------------------------------------+
   | id               | String                          | Specifies the health check ID.        |
   +------------------+---------------------------------+---------------------------------------+
   | max_retries      | Integer                         | Specifies the number of consecutive   |
   |                  |                                 | health checks when the health check   |
   |                  |                                 | result of a backend server changes    |
   |                  |                                 | from **OFFLINE** to **ONLINE**. The   |
   |                  |                                 | value ranges from **1** to **10**.    |
   |                  |                                 |                                       |
   |                  |                                 | Minimum: **1**                        |
   |                  |                                 |                                       |
   |                  |                                 | Maximum: **10**                       |
   +------------------+---------------------------------+---------------------------------------+
   | max_retries_down | Integer                         | Specifies the number of consecutive   |
   |                  |                                 | health checks when the health check   |
   |                  |                                 | result of a backend server changes    |
   |                  |                                 | from **ONLINE** to **OFFLINE**.       |
   |                  |                                 |                                       |
   |                  |                                 | Minimum: **1**                        |
   |                  |                                 |                                       |
   |                  |                                 | Maximum: **10**                       |
   |                  |                                 |                                       |
   |                  |                                 | Default: **3**                        |
   +------------------+---------------------------------+---------------------------------------+
   | monitor_port     | Integer                         | Specifies the port used for the       |
   |                  |                                 | health check. If this parameter is    |
   |                  |                                 | left blank, the port of the backend   |
   |                  |                                 | server group will be used by default. |
   |                  |                                 |                                       |
   |                  |                                 | Minimum: **1**                        |
   |                  |                                 |                                       |
   |                  |                                 | Maximum: **65535**                    |
   +------------------+---------------------------------+---------------------------------------+
   | name             | String                          | Specifies the health check name.      |
   +------------------+---------------------------------+---------------------------------------+
   | pools            | Array of :ref:`dhml_pr` objects | Lists the IDs of backend server       |
   |                  |                                 | groups for which the health check is  |
   |                  |                                 | configured.                           |
   +------------------+---------------------------------+---------------------------------------+
   | project_id       | String                          | Specifies the project ID.             |
   +------------------+---------------------------------+---------------------------------------+
   | timeout          | Integer                         | Specifies the maximum time required   |
   |                  |                                 | for waiting for a response from the   |
   |                  |                                 | health check, in seconds. It is       |
   |                  |                                 | recommended that you set the value    |
   |                  |                                 | less than that of parameter           |
   |                  |                                 | **delay**.                            |
   |                  |                                 |                                       |
   |                  |                                 | Minimum: **1**                        |
   |                  |                                 |                                       |
   |                  |                                 | Maximum: **50**                       |
   +------------------+---------------------------------+---------------------------------------+
   | type             | String                          | Specifies the health check protocol.  |
   +------------------+---------------------------------+---------------------------------------+
   | url_path         | String                          | Specifies the HTTP request path for   |
   |                  |                                 | the health check. The value must      |
   |                  |                                 | start with a slash (/), and the       |
   |                  |                                 | default value is /. This parameter is |
   |                  |                                 | available only when **type** is set   |
   |                  |                                 | to **HTTP**.                          |
   |                  |                                 |                                       |
   |                  |                                 | Default: **/**                        |
   +------------------+---------------------------------+---------------------------------------+

.. _dhml_pr:
.. table:: **Table 7** PoolRef

   ========= ====== =============================================
   Parameter Type   Description
   ========= ====== =============================================
   id        String Specifies the ID of the backend server group.
   ========= ====== =============================================

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   GET

   https://{elb_endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/healthmonitors

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 200**

Successful request.

.. code::

   {
     "healthmonitors" : [ {
       "id" : "c2b210b2-60c4-449d-91e2-9e9ea1dd7441",
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
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
       "url_path" : "/world"
     } ],
     "page_info" : {
       "next_marker" : "cda1af03-0660-4fd2-8edf-e38c79846e08",
       "previous_marker" : "c2b210b2-60c4-449d-91e2-9e9ea1dd7441",
       "current_count" : 2
     },
     "request_id" : "814bc40e-8b0a-4ced-b8e5-f136c3e1df6a"
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

Viewing Details of a Health Check
=================================

Function
^^^^^^^^

This API is used to view details of a health check.

URI
^^^

GET /v3/{project_id}/elb/healthmonitors/{healthmonitor_id}

.. table:: **Table 1** Path parameters

   ================ ========= ====== ==============================
   Parameter        Mandatory Type   Description
   ================ ========= ====== ==============================
   project_id       Yes       String Specifies the project ID.
   healthmonitor_id Yes       String Specifies the health check ID.
   ================ ========= ====== ==============================

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

   +---------------+-----------------------+----------------------------------------+
   | Parameter     | Type                  | Description                            |
   +===============+=======================+========================================+
   | request_id    | String                | Specifies the request ID. The value is |
   |               |                       | automatically generated.               |
   +---------------+-----------------------+----------------------------------------+
   | healthmonitor | :ref:`dhms_hm` object | Specifies the health check.            |
   +---------------+-----------------------+----------------------------------------+

.. _dhms_hm:
.. table:: **Table 4** HealthMonitor

   +------------------+---------------------------------+---------------------------------------+
   | Parameter        | Type                            | Description                           |
   +==================+=================================+=======================================+
   | admin_state_up   | Boolean                         | Specifies the administrative status   |
   |                  |                                 | of the health check. Two value        |
   |                  |                                 | options are available. **true**       |
   |                  |                                 | indicates that the health check is    |
   |                  |                                 | enabled, and **false** indicates that |
   |                  |                                 | the health check is disabled.         |
   |                  |                                 |                                       |
   |                  |                                 | Default: **true**                     |
   +------------------+---------------------------------+---------------------------------------+
   | delay            | Integer                         | Specifies the interval between health |
   |                  |                                 | checks, in seconds.                   |
   |                  |                                 |                                       |
   |                  |                                 | Minimum: **1**                        |
   |                  |                                 |                                       |
   |                  |                                 | Maximum: **50**                       |
   +------------------+---------------------------------+---------------------------------------+
   | domain_name      | String                          | Specifies the domain name that HTTP   |
   |                  |                                 | requests are sent to during the       |
   |                  |                                 | health check.                         |
   |                  |                                 |                                       |
   |                  |                                 | This parameter is available only when |
   |                  |                                 | **type** is set to **HTTP**.          |
   |                  |                                 |                                       |
   |                  |                                 | The value is left blank by default,   |
   |                  |                                 | indicating that the virtual IP        |
   |                  |                                 | address of the load balancer is used  |
   |                  |                                 | as the destination address of HTTP    |
   |                  |                                 | requests.                             |
   |                  |                                 |                                       |
   |                  |                                 | The value can contain only digits,    |
   |                  |                                 | letters, hyphens (-), and periods (.) |
   |                  |                                 | and must start with a digit or        |
   |                  |                                 | letter.                               |
   +------------------+---------------------------------+---------------------------------------+
   | expected_codes   | String                          | Specifies the expected HTTP status    |
   |                  |                                 | code. This parameter will take effect |
   |                  |                                 | only when **type** is set to          |
   |                  |                                 | **HTTP**.                             |
   |                  |                                 |                                       |
   |                  |                                 | The value options are as follows:     |
   |                  |                                 |                                       |
   |                  |                                 | -  A specific value, for example, 200 |
   |                  |                                 |                                       |
   |                  |                                 | -  A list of values that are          |
   |                  |                                 |    separated with commas (,), for     |
   |                  |                                 |    example, 200, 202                  |
   |                  |                                 |                                       |
   |                  |                                 | -  A value range, for example,        |
   |                  |                                 |    200-204                            |
   |                  |                                 |                                       |
   |                  |                                 | This parameter is unsupported. Please |
   |                  |                                 | do not use it.                        |
   |                  |                                 |                                       |
   |                  |                                 | Default: **200**                      |
   +------------------+---------------------------------+---------------------------------------+
   | http_method      | String                          | Specifies the HTTP method. This       |
   |                  |                                 | parameter will take effect only when  |
   |                  |                                 | **type** is set to **HTTP**.          |
   |                  |                                 |                                       |
   |                  |                                 | The value can be **GET**, **HEAD**,   |
   |                  |                                 | **POST**, **PUT**, **DELETE**,        |
   |                  |                                 | **TRACE**, **OPTIONS**, **CONNECT**,  |
   |                  |                                 | or **PATCH**.                         |
   |                  |                                 |                                       |
   |                  |                                 | This parameter is unsupported. Please |
   |                  |                                 | do not use it.                        |
   |                  |                                 |                                       |
   |                  |                                 | Default: **GET**                      |
   +------------------+---------------------------------+---------------------------------------+
   | id               | String                          | Specifies the health check ID.        |
   +------------------+---------------------------------+---------------------------------------+
   | max_retries      | Integer                         | Specifies the number of consecutive   |
   |                  |                                 | health checks when the health check   |
   |                  |                                 | result of a backend server changes    |
   |                  |                                 | from **OFFLINE** to **ONLINE**. The   |
   |                  |                                 | value ranges from **1** to **10**.    |
   |                  |                                 |                                       |
   |                  |                                 | Minimum: **1**                        |
   |                  |                                 |                                       |
   |                  |                                 | Maximum: **10**                       |
   +------------------+---------------------------------+---------------------------------------+
   | max_retries_down | Integer                         | Specifies the number of consecutive   |
   |                  |                                 | health checks when the health check   |
   |                  |                                 | result of a backend server changes    |
   |                  |                                 | from **ONLINE** to **OFFLINE**.       |
   |                  |                                 |                                       |
   |                  |                                 | Minimum: **1**                        |
   |                  |                                 |                                       |
   |                  |                                 | Maximum: **10**                       |
   |                  |                                 |                                       |
   |                  |                                 | Default: **3**                        |
   +------------------+---------------------------------+---------------------------------------+
   | monitor_port     | Integer                         | Specifies the port used for the       |
   |                  |                                 | health check. If this parameter is    |
   |                  |                                 | left blank, the port of the backend   |
   |                  |                                 | server group will be used by default. |
   |                  |                                 |                                       |
   |                  |                                 | Minimum: **1**                        |
   |                  |                                 |                                       |
   |                  |                                 | Maximum: **65535**                    |
   +------------------+---------------------------------+---------------------------------------+
   | name             | String                          | Specifies the health check name.      |
   +------------------+---------------------------------+---------------------------------------+
   | pools            | Array of :ref:`dhms_pr` objects | Lists the IDs of backend server       |
   |                  |                                 | groups for which the health check is  |
   |                  |                                 | configured.                           |
   +------------------+---------------------------------+---------------------------------------+
   | project_id       | String                          | Specifies the project ID.             |
   +------------------+---------------------------------+---------------------------------------+
   | timeout          | Integer                         | Specifies the maximum time required   |
   |                  |                                 | for waiting for a response from the   |
   |                  |                                 | health check, in seconds. It is       |
   |                  |                                 | recommended that you set the value    |
   |                  |                                 | less than that of parameter           |
   |                  |                                 | **delay**.                            |
   |                  |                                 |                                       |
   |                  |                                 | Minimum: **1**                        |
   |                  |                                 |                                       |
   |                  |                                 | Maximum: **50**                       |
   +------------------+---------------------------------+---------------------------------------+
   | type             | String                          | Specifies the health check protocol.  |
   +------------------+---------------------------------+---------------------------------------+
   | url_path         | String                          | Specifies the HTTP request path for   |
   |                  |                                 | the health check. The value must      |
   |                  |                                 | start with a slash (/), and the       |
   |                  |                                 | default value is /. This parameter is |
   |                  |                                 | available only when **type** is set   |
   |                  |                                 | to **HTTP**.                          |
   |                  |                                 |                                       |
   |                  |                                 | Default: **/**                        |
   +------------------+---------------------------------+---------------------------------------+

.. _dhms_pr:
.. table:: **Table 5** PoolRef

   ========= ====== =============================================
   Parameter Type   Description
   ========= ====== =============================================
   id        String Specifies the ID of the backend server group.
   ========= ====== =============================================

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   GET

   https://{elb_endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/healthmonitors/c2b210b2-60c4-449d-91e2-9e9ea1dd7441

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 200**

Successful request.

.. code::

   {
     "healthmonitor" : {
       "id" : "c2b210b2-60c4-449d-91e2-9e9ea1dd7441",
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
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
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
200         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Updating a Health Check
=======================

Function
^^^^^^^^

This API is used to update a health check.

Constraints
^^^^^^^^^^^

The health check can be updated only when the provisioning status of the
associated load balancer is **ACTIVE**.

URI
^^^

PUT /v3/{project_id}/elb/healthmonitors/{healthmonitor_id}

.. table:: **Table 1** Path parameters

   ================ ========= ====== ==============================
   Parameter        Mandatory Type   Description
   ================ ========= ====== ==============================
   healthmonitor_id Yes       String Specifies the health check ID.
   project_id       Yes       String Specifies the project ID.
   ================ ========= ====== ==============================

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 2** Request header parameters

   ============ ========= ====== ================================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ================================================
   X-Auth-Token Yes       String Specifies the token used for IAM authentication.
   ============ ========= ====== ================================================

.. table:: **Table 3** Request body parameters

   +---------------+-----------+-----------------------+-----------------------------+
   | Parameter     | Mandatory | Type                  | Description                 |
   +===============+===========+=======================+=============================+
   | healthmonitor | Yes       | :ref:`dhmu_ho` object | Specifies the health check. |
   +---------------+-----------+-----------------------+-----------------------------+

.. _dhmu_ho:
.. table:: **Table 4** UpdateHealthMonitorOption

   +------------------+-----------+---------+-----------------------------+
   | Parameter        | Mandatory | Type    | Description                 |
   +==================+===========+=========+=============================+
   | admin_state_up   | No        | Boolean | Specifies the               |
   |                  |           |         | administrative status of    |
   |                  |           |         | the health check. Two value |
   |                  |           |         | options are available.      |
   |                  |           |         | **true** indicates that the |
   |                  |           |         | health check is enabled,    |
   |                  |           |         | and **false** indicates     |
   |                  |           |         | that the health check is    |
   |                  |           |         | disabled.                   |
   |                  |           |         |                             |
   |                  |           |         | Default: **true**           |
   +------------------+-----------+---------+-----------------------------+
   | delay            | No        | Integer | Specifies the interval      |
   |                  |           |         | between health checks, in   |
   |                  |           |         | seconds.                    |
   |                  |           |         |                             |
   |                  |           |         | Minimum: **1**              |
   |                  |           |         |                             |
   |                  |           |         | Maximum: **50**             |
   +------------------+-----------+---------+-----------------------------+
   | domain_name      | No        | String  | Specifies the domain name   |
   |                  |           |         | that HTTP requests are sent |
   |                  |           |         | to during the health check. |
   |                  |           |         |                             |
   |                  |           |         | This parameter is available |
   |                  |           |         | only when **type** is set   |
   |                  |           |         | to **HTTP**.                |
   |                  |           |         |                             |
   |                  |           |         | The value is left blank by  |
   |                  |           |         | default, indicating that    |
   |                  |           |         | the virtual IP address of   |
   |                  |           |         | the load balancer is used   |
   |                  |           |         | as the destination address  |
   |                  |           |         | of HTTP requests.           |
   |                  |           |         |                             |
   |                  |           |         | The value can contain only  |
   |                  |           |         | digits, letters, hyphens    |
   |                  |           |         | (-), and periods (.) and    |
   |                  |           |         | must start with a digit or  |
   |                  |           |         | letter.                     |
   |                  |           |         |                             |
   |                  |           |         | Minimum: **1**              |
   |                  |           |         |                             |
   |                  |           |         | Maximum: **100**            |
   +------------------+-----------+---------+-----------------------------+
   | expected_codes   | No        | String  | Specifies the expected HTTP |
   |                  |           |         | status code. This parameter |
   |                  |           |         | will take effect only when  |
   |                  |           |         | **type** is set to          |
   |                  |           |         | **HTTP**.                   |
   |                  |           |         |                             |
   |                  |           |         | The value options are as    |
   |                  |           |         | follows:                    |
   |                  |           |         |                             |
   |                  |           |         | -  A specific value, for    |
   |                  |           |         |    example, 200             |
   |                  |           |         |                             |
   |                  |           |         | -  A list of values that    |
   |                  |           |         |    are separated with       |
   |                  |           |         |    commas (,), for example, |
   |                  |           |         |    200, 202                 |
   |                  |           |         |                             |
   |                  |           |         | -  A value range, for       |
   |                  |           |         |    example, 200-204         |
   |                  |           |         |                             |
   |                  |           |         | This parameter is           |
   |                  |           |         | unsupported. Please do not  |
   |                  |           |         | use it.                     |
   |                  |           |         |                             |
   |                  |           |         | Default: **200**            |
   |                  |           |         |                             |
   |                  |           |         | Minimum: **1**              |
   |                  |           |         |                             |
   |                  |           |         | Maximum: **64**             |
   +------------------+-----------+---------+-----------------------------+
   | http_method      | No        | String  | Specifies the HTTP method.  |
   |                  |           |         | The value can be **GET**,   |
   |                  |           |         | **HEAD**, **POST**,         |
   |                  |           |         | **PUT**, **DELETE**,        |
   |                  |           |         | **TRACE**, **OPTIONS**,     |
   |                  |           |         | **CONNECT**, or **PATCH**.  |
   |                  |           |         | This parameter will take    |
   |                  |           |         | effect only when **type**   |
   |                  |           |         | is set to **HTTP**.         |
   |                  |           |         |                             |
   |                  |           |         | This parameter is           |
   |                  |           |         | unsupported. Please do not  |
   |                  |           |         | use it.                     |
   |                  |           |         |                             |
   |                  |           |         | Default: **GET**            |
   |                  |           |         |                             |
   |                  |           |         | Minimum: **1**              |
   |                  |           |         |                             |
   |                  |           |         | Maximum: **16**             |
   +------------------+-----------+---------+-----------------------------+
   | max_retries      | No        | Integer | Specifies the maximum       |
   |                  |           |         | health check retries.       |
   |                  |           |         |                             |
   |                  |           |         | Minimum: **1**              |
   |                  |           |         |                             |
   |                  |           |         | Maximum: **10**             |
   +------------------+-----------+---------+-----------------------------+
   | max_retries_down | No        | Integer | Specifies the number of     |
   |                  |           |         | consecutive health checks   |
   |                  |           |         | when the health check       |
   |                  |           |         | result of a backend server  |
   |                  |           |         | changes from **ONLINE** to  |
   |                  |           |         | **OFFLINE**.                |
   |                  |           |         |                             |
   |                  |           |         | Minimum: **1**              |
   |                  |           |         |                             |
   |                  |           |         | Maximum: **10**             |
   +------------------+-----------+---------+-----------------------------+
   | monitor_port     | No        | Integer | Specifies the port used for |
   |                  |           |         | the health check. If this   |
   |                  |           |         | parameter is left blank,    |
   |                  |           |         | the port of the backend     |
   |                  |           |         | server group will be used   |
   |                  |           |         | by default.                 |
   |                  |           |         |                             |
   |                  |           |         | Minimum: **1**              |
   |                  |           |         |                             |
   |                  |           |         | Maximum: **65535**          |
   +------------------+-----------+---------+-----------------------------+
   | name             | No        | String  | Specifies the health check  |
   |                  |           |         | name.                       |
   |                  |           |         |                             |
   |                  |           |         | Minimum: **0**              |
   |                  |           |         |                             |
   |                  |           |         | Maximum: **255**            |
   +------------------+-----------+---------+-----------------------------+
   | timeout          | No        | Integer | Specifies the maximum time  |
   |                  |           |         | required for waiting for a  |
   |                  |           |         | response from the health    |
   |                  |           |         | check, in seconds. It is    |
   |                  |           |         | recommended that you set    |
   |                  |           |         | the value less than that of |
   |                  |           |         | parameter **delay**.        |
   |                  |           |         |                             |
   |                  |           |         | Minimum: **1**              |
   |                  |           |         |                             |
   |                  |           |         | Maximum: **50**             |
   +------------------+-----------+---------+-----------------------------+
   | url_path         | No        | String  | Specifies the HTTP request  |
   |                  |           |         | path for the health check.  |
   |                  |           |         | The value must start with a |
   |                  |           |         | slash (/), and the default  |
   |                  |           |         | value is /. This parameter  |
   |                  |           |         | is available only when      |
   |                  |           |         | **type** is set to          |
   |                  |           |         | **HTTP**.                   |
   |                  |           |         |                             |
   |                  |           |         | Default: **/**              |
   |                  |           |         |                             |
   |                  |           |         | Minimum: **1**              |
   |                  |           |         |                             |
   |                  |           |         | Maximum: **255**            |
   +------------------+-----------+---------+-----------------------------+
   | type             | No        | String  | Specifies the protocol used |
   |                  |           |         | for the health check.       |
   |                  |           |         |                             |
   |                  |           |         | The value can be **TCP**,   |
   |                  |           |         | **UDP_CONNECT**, **HTTP**,  |
   |                  |           |         | **HTTPS**, or **PING**.     |
   +------------------+-----------+---------+-----------------------------+

Response Parameters
^^^^^^^^^^^^^^^^^^^

**Status code: 200**

.. table:: **Table 5** Response body parameters

   +---------------+-----------------------+----------------------------------------+
   | Parameter     | Type                  | Description                            |
   +===============+=======================+========================================+
   | request_id    | String                | Specifies the request ID. The value is |
   |               |                       | automatically generated.               |
   +---------------+-----------------------+----------------------------------------+
   | healthmonitor | :ref:`dhmu_hm` object | Specifies the health check.            |
   +---------------+-----------------------+----------------------------------------+

.. _dhmu_hm:
.. table:: **Table 6** HealthMonitor

   +------------------+---------------------------------+---------------------------------------+
   | Parameter        | Type                            | Description                           |
   +==================+=================================+=======================================+
   | admin_state_up   | Boolean                         | Specifies the administrative status   |
   |                  |                                 | of the health check. Two value        |
   |                  |                                 | options are available. **true**       |
   |                  |                                 | indicates that the health check is    |
   |                  |                                 | enabled, and **false** indicates that |
   |                  |                                 | the health check is disabled.         |
   |                  |                                 |                                       |
   |                  |                                 | Default: **true**                     |
   +------------------+---------------------------------+---------------------------------------+
   | delay            | Integer                         | Specifies the interval between health |
   |                  |                                 | checks, in seconds.                   |
   |                  |                                 |                                       |
   |                  |                                 | Minimum: **1**                        |
   |                  |                                 |                                       |
   |                  |                                 | Maximum: **50**                       |
   +------------------+---------------------------------+---------------------------------------+
   | domain_name      | String                          | Specifies the domain name that HTTP   |
   |                  |                                 | requests are sent to during the       |
   |                  |                                 | health check.                         |
   |                  |                                 |                                       |
   |                  |                                 | This parameter is available only when |
   |                  |                                 | **type** is set to **HTTP**.          |
   |                  |                                 |                                       |
   |                  |                                 | The value is left blank by default,   |
   |                  |                                 | indicating that the virtual IP        |
   |                  |                                 | address of the load balancer is used  |
   |                  |                                 | as the destination address of HTTP    |
   |                  |                                 | requests.                             |
   |                  |                                 |                                       |
   |                  |                                 | The value can contain only digits,    |
   |                  |                                 | letters, hyphens (-), and periods (.) |
   |                  |                                 | and must start with a digit or        |
   |                  |                                 | letter.                               |
   +------------------+---------------------------------+---------------------------------------+
   | expected_codes   | String                          | Specifies the expected HTTP status    |
   |                  |                                 | code. This parameter will take effect |
   |                  |                                 | only when **type** is set to          |
   |                  |                                 | **HTTP**.                             |
   |                  |                                 |                                       |
   |                  |                                 | The value options are as follows:     |
   |                  |                                 |                                       |
   |                  |                                 | -  A specific value, for example, 200 |
   |                  |                                 |                                       |
   |                  |                                 | -  A list of values that are          |
   |                  |                                 |    separated with commas (,), for     |
   |                  |                                 |    example, 200, 202                  |
   |                  |                                 |                                       |
   |                  |                                 | -  A value range, for example,        |
   |                  |                                 |    200-204                            |
   |                  |                                 |                                       |
   |                  |                                 | This parameter is unsupported. Please |
   |                  |                                 | do not use it.                        |
   |                  |                                 |                                       |
   |                  |                                 | Default: **200**                      |
   +------------------+---------------------------------+---------------------------------------+
   | http_method      | String                          | Specifies the HTTP method. This       |
   |                  |                                 | parameter will take effect only when  |
   |                  |                                 | **type** is set to **HTTP**.          |
   |                  |                                 |                                       |
   |                  |                                 | The value can be **GET**, **HEAD**,   |
   |                  |                                 | **POST**, **PUT**, **DELETE**,        |
   |                  |                                 | **TRACE**, **OPTIONS**, **CONNECT**,  |
   |                  |                                 | or **PATCH**.                         |
   |                  |                                 |                                       |
   |                  |                                 | This parameter is unsupported. Please |
   |                  |                                 | do not use it.                        |
   |                  |                                 |                                       |
   |                  |                                 | Default: **GET**                      |
   +------------------+---------------------------------+---------------------------------------+
   | id               | String                          | Specifies the health check ID.        |
   +------------------+---------------------------------+---------------------------------------+
   | max_retries      | Integer                         | Specifies the number of consecutive   |
   |                  |                                 | health checks when the health check   |
   |                  |                                 | result of a backend server changes    |
   |                  |                                 | from **OFFLINE** to **ONLINE**. The   |
   |                  |                                 | value ranges from **1** to **10**.    |
   |                  |                                 |                                       |
   |                  |                                 | Minimum: **1**                        |
   |                  |                                 |                                       |
   |                  |                                 | Maximum: **10**                       |
   +------------------+---------------------------------+---------------------------------------+
   | max_retries_down | Integer                         | Specifies the number of consecutive   |
   |                  |                                 | health checks when the health check   |
   |                  |                                 | result of a backend server changes    |
   |                  |                                 | from **ONLINE** to **OFFLINE**.       |
   |                  |                                 |                                       |
   |                  |                                 | Minimum: **1**                        |
   |                  |                                 |                                       |
   |                  |                                 | Maximum: **10**                       |
   |                  |                                 |                                       |
   |                  |                                 | Default: **3**                        |
   +------------------+---------------------------------+---------------------------------------+
   | monitor_port     | Integer                         | Specifies the port used for the       |
   |                  |                                 | health check. If this parameter is    |
   |                  |                                 | left blank, the port of the backend   |
   |                  |                                 | server group will be used by default. |
   |                  |                                 |                                       |
   |                  |                                 | Minimum: **1**                        |
   |                  |                                 |                                       |
   |                  |                                 | Maximum: **65535**                    |
   +------------------+---------------------------------+---------------------------------------+
   | name             | String                          | Specifies the health check name.      |
   +------------------+---------------------------------+---------------------------------------+
   | pools            | Array of :ref:`dhmu_pr` objects | Lists the IDs of backend server       |
   |                  |                                 | groups for which the health check is  |
   |                  |                                 | configured.                           |
   +------------------+---------------------------------+---------------------------------------+
   | project_id       | String                          | Specifies the project ID.             |
   +------------------+---------------------------------+---------------------------------------+
   | timeout          | Integer                         | Specifies the maximum time required   |
   |                  |                                 | for waiting for a response from the   |
   |                  |                                 | health check, in seconds. It is       |
   |                  |                                 | recommended that you set the value    |
   |                  |                                 | less than that of parameter           |
   |                  |                                 | **delay**.                            |
   |                  |                                 |                                       |
   |                  |                                 | Minimum: **1**                        |
   |                  |                                 |                                       |
   |                  |                                 | Maximum: **50**                       |
   +------------------+---------------------------------+---------------------------------------+
   | type             | String                          | Specifies the health check protocol.  |
   +------------------+---------------------------------+---------------------------------------+
   | url_path         | String                          | Specifies the HTTP request path for   |
   |                  |                                 | the health check. The value must      |
   |                  |                                 | start with a slash (/), and the       |
   |                  |                                 | default value is /. This parameter is |
   |                  |                                 | available only when **type** is set   |
   |                  |                                 | to **HTTP**.                          |
   |                  |                                 |                                       |
   |                  |                                 | Default: **/**                        |
   +------------------+---------------------------------+---------------------------------------+

.. _dhmu_pr:
.. table:: **Table 7** PoolRef

   ========= ====== =============================================
   Parameter Type   Description
   ========= ====== =============================================
   id        String Specifies the ID of the backend server group.
   ========= ====== =============================================

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   PUT

   https://{elb_endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/healthmonitors/c2b210b2-60c4-449d-91e2-9e9ea1dd7441

   {
     "healthmonitor" : {
       "name" : "My Healthmonitor update",
       "max_retries" : 10,
       "delay" : 10
     }
   }

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 200**

Successful request.

.. code::

   {
     "request_id" : "08d6ffea-d092-4cfa-860a-e364f3bef1be",
     "healthmonitor" : {
       "id" : "c2b210b2-60c4-449d-91e2-9e9ea1dd7441",
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
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
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
200         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Deleting a Health Check
=======================

Function
^^^^^^^^

This API is used to delete a health check.

Constraints
^^^^^^^^^^^

The health check can be deleted only when the provisioning status of the
associated load balancer is **ACTIVE**.

URI
^^^

DELETE /v3/{project_id}/elb/healthmonitors/{healthmonitor_id}

.. table:: **Table 1** Path parameters

   ================ ========= ====== ==============================
   Parameter        Mandatory Type   Description
   ================ ========= ====== ==============================
   project_id       Yes       String Specifies the project ID.
   healthmonitor_id Yes       String Specifies the health check ID.
   ================ ========= ====== ==============================

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

   https://{elb_endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/healthmonitors/c2b210b2-60c4-449d-91e2-9e9ea1dd7441

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
