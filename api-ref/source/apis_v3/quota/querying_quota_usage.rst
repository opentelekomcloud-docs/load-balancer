:original_name: ListQuotaDetails.html

.. _ListQuotaDetails:

Querying Quota Usage
====================

Function
--------

This API is used to query the current quotas and used quotas of resources related to a dedicated load balancer in a specific project.

URI
---

GET /v3/{project_id}/elb/quotas/details

.. table:: **Table 1** Path Parameters

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
   ========== ========= ====== =========================

.. table:: **Table 2** Query Parameters

   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                                                                                                                                                                                                    |
   +=================+=================+=================+================================================================================================================================================================================================================================================================+
   | quota_key       | No              | Array           | Specifies the resource type. The value can be **loadbalancer**, **listener**, **ipgroup**, **pool**, **member**, **members_per_pool**, **healthmonitor**, **l7policy**, **certificate**, **security_policy**, **ipgroup_bindings**, or **ipgroup_max_length**. |
   |                 |                 |                 |                                                                                                                                                                                                                                                                |
   |                 |                 |                 | **members_per_pool** indicates the maximum number of backend servers that can be added to a backend server group.                                                                                                                                              |
   |                 |                 |                 |                                                                                                                                                                                                                                                                |
   |                 |                 |                 | **ipgroup_bindings** indicates the maximum number of listeners that can be bound to a ipgroup.                                                                                                                                                                 |
   |                 |                 |                 |                                                                                                                                                                                                                                                                |
   |                 |                 |                 | **ipgroup_max_length** indicates the maximum number of ip addresses that can be added to a ipgroup.                                                                                                                                                            |
   |                 |                 |                 |                                                                                                                                                                                                                                                                |
   |                 |                 |                 | Multiple values can be queried in the format of *quota_key=xxx&quota_key=xxx.*                                                                                                                                                                                 |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

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

   +------------+--------------------------------------------------------------------------+-----------------------------------------------------------------+
   | Parameter  | Type                                                                     | Description                                                     |
   +============+==========================================================================+=================================================================+
   | request_id | String                                                                   | Specifies the request ID. The value is automatically generated. |
   +------------+--------------------------------------------------------------------------+-----------------------------------------------------------------+
   | quotas     | Array of :ref:`QuotaInfo <listquotadetails__response_quotainfo>` objects | Specifies the resource quotas.                                  |
   +------------+--------------------------------------------------------------------------+-----------------------------------------------------------------+

.. _listquotadetails__response_quotainfo:

.. table:: **Table 5** QuotaInfo

   +-----------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                                                                                                                                    |
   +=======================+=======================+================================================================================================================================================================================================================================================================+
   | quota_key             | String                | Specifies the resource type. The value can be **loadbalancer**, **listener**, **ipgroup**, **pool**, **member**, **members_per_pool**, **healthmonitor**, **l7policy**, **certificate**, **security_policy**, **ipgroup_bindings**, or **ipgroup_max_length**. |
   |                       |                       |                                                                                                                                                                                                                                                                |
   |                       |                       | **members_per_pool** indicates the maximum number of backend servers that can be added to a backend server group.                                                                                                                                              |
   |                       |                       |                                                                                                                                                                                                                                                                |
   |                       |                       | **ipgroup_bindings** indicates the maximum number of listeners that can be bound to a ipgroup.                                                                                                                                                                 |
   |                       |                       |                                                                                                                                                                                                                                                                |
   |                       |                       | **ipgroup_max_length** indicates the maximum number of ip addresses that can be added to a ipgroup.                                                                                                                                                            |
   +-----------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | quota_limit           | Integer               | Specifies the total quota. Values:                                                                                                                                                                                                                             |
   |                       |                       |                                                                                                                                                                                                                                                                |
   |                       |                       | -  If the value is greater than or equal to 0, it indicates the current quota.                                                                                                                                                                                 |
   |                       |                       |                                                                                                                                                                                                                                                                |
   |                       |                       | -  **-1** indicates that the quota is not limited.                                                                                                                                                                                                             |
   +-----------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | used                  | Integer               | Specifies the used quota.                                                                                                                                                                                                                                      |
   +-----------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | unit                  | String                | Specifies the quota unit. The value can only be **count**.                                                                                                                                                                                                     |
   +-----------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Example Requests
----------------

Querying the quota of a specific resource type

.. code-block::

   https://{ELB_Endpoint}/v3/06b9dc6cbf80d5952f18c0181a2f4654/elb/quotas/details?quota_key=members_per_pool&quota_key=loadbalancer

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

   {
     "request_id" : "3682f26f8509d52faf895f09040c63c0",
     "quotas" : [ {
       "quota_key" : "members_per_pool",
       "used" : 50,
       "quota_limit" : 1000,
       "unit" : "count"
     }, {
       "quota_key" : "loadbalancer",
       "used" : 198,
       "quota_limit" : 1000,
       "unit" : "count"
     }, {
       "quota_key" : "security_policy",
       "used" : 6,
       "quota_limit" : 50,
       "unit" : "count"
     }, {
       "quota_key" : "ipgroup",
       "used" : 6,
       "quota_limit" : 1000,
       "unit" : "count"
     }, {
       "quota_key" : "listener",
       "used" : 229,
       "quota_limit" : 1500,
       "unit" : "count"
     }, {
       "quota_key" : "pool",
       "used" : 215,
       "quota_limit" : 5000,
       "unit" : "count"
     }, {
       "quota_key" : "member",
       "used" : 327,
       "quota_limit" : 3000,
       "unit" : "count"
     }, {
       "quota_key" : "certificate",
       "used" : 50,
       "quota_limit" : 100,
       "unit" : "count"
     }, {
       "quota_key" : "l7policy",
       "used" : 21,
       "quota_limit" : 500,
       "unit" : "count"
     }, {
       "quota_key" : "healthmonitor",
       "used" : 188,
       "quota_limit" : -1,
       "unit" : "count"
     }, {
       "quota_key" : "ipgroup_max_length",
       "used" : 3,
       "quota_limit" : 300,
       "unit" : "count"
     }, {
       "quota_key" : "ipgroup_bindings",
       "used" : 2,
       "quota_limit" : 50,
       "unit" : "count"
     } ]
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
