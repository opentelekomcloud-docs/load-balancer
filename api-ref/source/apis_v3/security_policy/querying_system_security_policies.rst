:original_name: ListSystemSecurityPolicies.html

.. _ListSystemSecurityPolicies:

Querying System Security Policies
=================================

Function
--------

This API is used to query system security policies.

System security policies are available to all users and cannot be created or modified.

URI
---

GET /v3/{project_id}/elb/system-security-policies

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

   +--------------------------+----------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------+
   | Parameter                | Type                                                                                                     | Description                                                     |
   +==========================+==========================================================================================================+=================================================================+
   | system_security_policies | Array of :ref:`SystemSecurityPolicy <listsystemsecuritypolicies__response_systemsecuritypolicy>` objects | Lists system security policies.                                 |
   +--------------------------+----------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------+
   | request_id               | String                                                                                                   | Specifies the request ID. The value is automatically generated. |
   +--------------------------+----------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------+

.. _listsystemsecuritypolicies__response_systemsecuritypolicy:

.. table:: **Table 4** SystemSecurityPolicy

   +------------+--------+------------------------------------------------------------------+
   | Parameter  | Type   | Description                                                      |
   +============+========+==================================================================+
   | name       | String | Specifies the name of the system security policy.                |
   +------------+--------+------------------------------------------------------------------+
   | protocols  | String | Lists the TLS protocols supported by the system security policy. |
   +------------+--------+------------------------------------------------------------------+
   | ciphers    | String | Lists the cipher suites supported by the system security policy. |
   +------------+--------+------------------------------------------------------------------+
   | project_id | String | Specifies the project ID.                                        |
   +------------+--------+------------------------------------------------------------------+

Example Requests
----------------

Querying system security policies

.. code-block:: text

   GET https://{ELB_Endpoint}/v3/7a9941d34fc1497d8d0797429ecfd354/elb/system-security-policies

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

   {
     "request_id" : "fa83d976-e617-4a96-9a43-5bdb33011f30",
     "system_security_policies" : [ {
       "name" : "tls-1-0",
       "project_id" : "7a9941d34fc1497d8d0797429ecfd354",
       "protocols" : "TLSv1.2 TLSv1.1 TLSv1",
       "ciphers" : "ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES128-SHA256:ECDHE-ECDSA-AES256-SHA384:ECDHE-ECDSA-AES128-SHA:ECDHE-ECDSA-AES256-SHA:ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-AES128-GCM-SHA256:AES128-GCM-SHA256:AES256-GCM-SHA384:ECDHE-RSA-AES128-SHA256:AES128-SHA256:AES256-SHA256:ECDHE-RSA-AES256-SHA384:ECDHE-RSA-AES128-SHA:ECDHE-RSA-AES256-SHA:AES128-SHA:AES256-SHA"
     }, {
       "name" : "tls-1-0-inherit",
       "project_id" : "7a9941d34fc1497d8d0797429ecfd354",
       "protocols" : "TLSv1.2 TLSv1.1 TLSv1",
       "ciphers" : "ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES128-SHA256:ECDHE-ECDSA-AES256-SHA384:ECDHE-ECDSA-AES128-SHA:ECDHE-ECDSA-AES256-SHA:ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-AES128-GCM-SHA256:AES128-GCM-SHA256:AES256-GCM-SHA384:ECDHE-RSA-AES128-SHA256:AES128-SHA256:AES256-SHA256:ECDHE-RSA-AES256-SHA384:ECDHE-RSA-AES128-SHA:DHE-RSA-AES128-SHA:ECDHE-RSA-AES256-SHA:AES128-SHA:AES256-SHA:DHE-DSS-AES128-SHA:CAMELLIA128-SHA:EDH-RSA-DES-CBC3-SHA:DES-CBC3-SHA:ECDHE-RSA-RC4-SHA:RC4-SHA:DHE-RSA-AES256-SHA:DHE-DSS-AES256-SHA:DHE-RSA-CAMELLIA256-SHA:DHE-DSS-CAMELLIA256-SHA:CAMELLIA256-SHA:EDH-DSS-DES-CBC3-SHA:DHE-RSA-CAMELLIA128-SHA:DHE-DSS-CAMELLIA128-SHA"
     }, {
       "name" : "tls-1-1",
       "project_id" : "7a9941d34fc1497d8d0797429ecfd354",
       "protocols" : "TLSv1.2 TLSv1.1",
       "ciphers" : "ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES128-SHA256:ECDHE-ECDSA-AES256-SHA384:ECDHE-ECDSA-AES128-SHA:ECDHE-ECDSA-AES256-SHA:ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-AES128-GCM-SHA256:AES128-GCM-SHA256:AES256-GCM-SHA384:ECDHE-RSA-AES128-SHA256:AES128-SHA256:AES256-SHA256:ECDHE-RSA-AES256-SHA384:ECDHE-RSA-AES128-SHA:ECDHE-RSA-AES256-SHA:AES128-SHA:AES256-SHA"
     }, {
       "name" : "tls-1-2",
       "project_id" : "7a9941d34fc1497d8d0797429ecfd354",
       "protocols" : "TLSv1.2",
       "ciphers" : "ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES128-SHA256:ECDHE-ECDSA-AES256-SHA384:ECDHE-ECDSA-AES128-SHA:ECDHE-ECDSA-AES256-SHA:ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-AES128-GCM-SHA256:AES128-GCM-SHA256:AES256-GCM-SHA384:ECDHE-RSA-AES128-SHA256:AES128-SHA256:AES256-SHA256:ECDHE-RSA-AES256-SHA384:ECDHE-RSA-AES128-SHA:ECDHE-RSA-AES256-SHA:AES128-SHA:AES256-SHA"
     }, {
       "name" : "tls-1-2-strict",
       "project_id" : "7a9941d34fc1497d8d0797429ecfd354",
       "protocols" : "TLSv1.2",
       "ciphers" : "ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES128-SHA256:ECDHE-ECDSA-AES256-SHA384:ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-AES128-GCM-SHA256:AES128-GCM-SHA256:AES256-GCM-SHA384:ECDHE-RSA-AES128-SHA256:AES128-SHA256:AES256-SHA256:ECDHE-RSA-AES256-SHA384"
     }, {
       "name" : "tls-1-2-fs",
       "project_id" : "7a9941d34fc1497d8d0797429ecfd354",
       "protocols" : "TLSv1.2",
       "ciphers" : "ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES128-SHA256:ECDHE-ECDSA-AES256-SHA384:ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-AES128-GCM-SHA256:ECDHE-RSA-AES128-SHA256:ECDHE-RSA-AES256-SHA384"
     }, {
       "name" : "tls-1-0-with-1-3",
       "project_id" : "7a9941d34fc1497d8d0797429ecfd354",
       "protocols" : "TLSv1.3 TLSv1.2 TLSv1.1 TLSv1",
       "ciphers" : "ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES128-SHA256:ECDHE-ECDSA-AES256-SHA384:ECDHE-ECDSA-AES128-SHA:ECDHE-ECDSA-AES256-SHA:ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-AES128-GCM-SHA256:AES128-GCM-SHA256:AES256-GCM-SHA384:ECDHE-RSA-AES128-SHA256:AES128-SHA256:AES256-SHA256:ECDHE-RSA-AES256-SHA384:ECDHE-RSA-AES128-SHA:ECDHE-RSA-AES256-SHA:AES128-SHA:AES256-SHA:TLS_AES_128_GCM_SHA256:TLS_AES_256_GCM_SHA384:TLS_CHACHA20_POLY1305_SHA256:TLS_AES_128_CCM_SHA256:TLS_AES_128_CCM_8_SHA256"
     }, {
       "name" : "tls-1-2-fs-with-1-3",
       "project_id" : "7a9941d34fc1497d8d0797429ecfd354",
       "protocols" : "TLSv1.3 TLSv1.2",
       "ciphers" : "ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES128-SHA256:ECDHE-ECDSA-AES256-SHA384:ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-AES128-GCM-SHA256:ECDHE-RSA-AES128-SHA256:ECDHE-RSA-AES256-SHA384:TLS_AES_128_GCM_SHA256:TLS_AES_256_GCM_SHA384:TLS_CHACHA20_POLY1305_SHA256:TLS_AES_128_CCM_SHA256:TLS_AES_128_CCM_8_SHA256"
     }, {
       "name" : "hybrid-policy-1-0",
       "project_id" : "7a9941d34fc1497d8d0797429ecfd354",
       "protocols" : "TLSv1.2 TLSv1.1",
       "ciphers" : "ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES128-SHA256:ECDHE-ECDSA-AES256-SHA384:ECDHE-ECDSA-AES128-SHA:ECDHE-ECDSA-AES256-SHA:ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-AES128-GCM-SHA256:AES128-GCM-SHA256:AES256-GCM-SHA384:ECDHE-RSA-AES128-SHA256:AES128-SHA256:AES256-SHA256:ECDHE-RSA-AES256-SHA384:ECDHE-RSA-AES128-SHA:ECDHE-RSA-AES256-SHA:AES128-SHA:AES256-SHA"
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
