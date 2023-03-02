:original_name: ShowQuota.html

.. _ShowQuota:

Querying Quotas
===============

Function
--------

This API is used to query the quotas of load balancers and related resources in a specific project.

URI
---

GET /v3/{project_id}/elb/quotas

.. table:: **Table 1** Path Parameters

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
   ========== ========= ====== =========================

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

   +------------+-------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter  | Type                                            | Description                                                                                                                                           |
   +============+=================================================+=======================================================================================================================================================+
   | request_id | String                                          | Specifies the request ID. The value is automatically generated.                                                                                       |
   +------------+-------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------+
   | quota      | :ref:`Quota <showquota__response_quota>` object | Specifies the quotas of load balancers and associated resources. Only the total quotas are returned. Remaining available quotas will not be returned. |
   +------------+-------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _showquota__response_quota:

.. table:: **Table 4** Quota

   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                   |
   +=======================+=======================+===============================================================================================+
   | project_id            | String                | Specifies the project ID.                                                                     |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------+
   | loadbalancer          | Integer               | Specifies the load balancer quota.                                                            |
   |                       |                       |                                                                                               |
   |                       |                       | -  If the value is greater than or equal to 0, it indicates the load balancer quota.          |
   |                       |                       |                                                                                               |
   |                       |                       | -  If the value is **-1**, the quota is not limited.                                          |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------+
   | certificate           | Integer               | Specifies the certificate quota.                                                              |
   |                       |                       |                                                                                               |
   |                       |                       | -  If the value is greater than or equal to 0, it indicates the certificate quota.            |
   |                       |                       |                                                                                               |
   |                       |                       | -  If the value is **-1**, the quota is not limited.                                          |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------+
   | listener              | Integer               | Specifies the listener quota.                                                                 |
   |                       |                       |                                                                                               |
   |                       |                       | -  If the value is greater than or equal to 0, it indicates the listener quota.               |
   |                       |                       |                                                                                               |
   |                       |                       | -  If the value is **-1**, the quota is not limited.                                          |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------+
   | l7policy              | Integer               | Specifies the forwarding policy quota.                                                        |
   |                       |                       |                                                                                               |
   |                       |                       | -  If the value is greater than or equal to 0, it indicates the forwarding policy quota.      |
   |                       |                       |                                                                                               |
   |                       |                       | -  If the value is **-1**, the quota is not limited.                                          |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------+
   | pool                  | Integer               | Specifies the backend server group quota.                                                     |
   |                       |                       |                                                                                               |
   |                       |                       | -  If the value is greater than or equal to 0, it indicates the backend server group quota.   |
   |                       |                       |                                                                                               |
   |                       |                       | -  If the value is **-1**, the quota is not limited.                                          |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------+
   | healthmonitor         | Integer               | Specifies the health check quota.                                                             |
   |                       |                       |                                                                                               |
   |                       |                       | -  If the value is greater than or equal to 0, it indicates the health check quota.           |
   |                       |                       |                                                                                               |
   |                       |                       | -  If the value is **-1**, the quota is not limited.                                          |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------+
   | member                | Integer               | Specifies the backend server quota.                                                           |
   |                       |                       |                                                                                               |
   |                       |                       | -  If the value is greater than or equal to 0, it indicates the backend server quota.         |
   |                       |                       |                                                                                               |
   |                       |                       | -  If the value is **-1**, the quota is not limited.                                          |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------+
   | members_per_pool      | Integer               | Specifies the quota of backend servers in a backend server group.                             |
   |                       |                       |                                                                                               |
   |                       |                       | -  If the value is greater than or equal to 0, it indicates the backend server quota.         |
   |                       |                       |                                                                                               |
   |                       |                       | -  If the value is **-1**, the quota is not limited.                                          |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------+
   | ipgroup               | Integer               | Specifies the IP address group quota.                                                         |
   |                       |                       |                                                                                               |
   |                       |                       | -  If the value is greater than or equal to 0, it indicates the IP address group quota.       |
   |                       |                       |                                                                                               |
   |                       |                       | -  If the value is **-1**, the quota is not limited.                                          |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------+
   | security_policy       | Integer               | Specifies the custom security policy quota.                                                   |
   |                       |                       |                                                                                               |
   |                       |                       | -  If the value is greater than or equal to 0, it indicates the custom security policy quota. |
   |                       |                       |                                                                                               |
   |                       |                       | -  If the value is **-1**, the quota is not limited.                                          |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------+
   | ipgroup_bindings      | String                | Specifies the quota of listeners that can be bound to a ipgroup.                              |
   |                       |                       |                                                                                               |
   |                       |                       | -  If the value is greater than or equal to 0, it indicates the listener quota for ipgroup.   |
   |                       |                       |                                                                                               |
   |                       |                       | -  If the value is **-1**, the quota is not limited.                                          |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------+
   | ipgroup_max_length    | String                | Specifies the number of ip addresses that can be added to an ipgroup.                         |
   |                       |                       |                                                                                               |
   |                       |                       | -  If the value is greater than or equal to 0, it indicates the ip address quota.             |
   |                       |                       |                                                                                               |
   |                       |                       | -  If the value is **-1**, the quota is not limited.                                          |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------+

Example Requests
----------------

Specifies the resource quotas of a specific user.

.. code-block:: text

   GET https://{ELB_Endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/quotas

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

   {
     "quota" : {
       "member" : 500,
       "members_per_pool" : 500,
       "certificate" : 120,
       "l7policy" : 500,
       "listener" : 100,
       "loadbalancer" : 50,
       "healthmonitor" : -1,
       "ipgroup" : 50,
       "pool" : 500,
       "security_policy" : 500,
       "ipgroup_bindings" : 50,
       "ipgroup_max_length" : 300,
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24"
     },
     "request_id" : "8d7eba6f-ec79-42d2-8d8c-16149645549d"
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
