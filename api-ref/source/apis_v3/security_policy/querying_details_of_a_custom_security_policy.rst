:original_name: ShowSecurityPolicy.html

.. _ShowSecurityPolicy:

Querying Details of a Custom Security Policy
============================================

Function
--------

This API is used to query details of a custom security policy.Customizing security policy is not supported in **eu-nl** region. Please do not use it.

URI
---

GET /v3/{project_id}/elb/security-policies/{security_policy_id}

.. table:: **Table 1** Path Parameters

   +--------------------+-----------+--------+-------------------------------------------------+
   | Parameter          | Mandatory | Type   | Description                                     |
   +====================+===========+========+=================================================+
   | project_id         | Yes       | String | Specifies the project ID.                       |
   +--------------------+-----------+--------+-------------------------------------------------+
   | security_policy_id | Yes       | String | Specifies the ID of the custom security policy. |
   +--------------------+-----------+--------+-------------------------------------------------+

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

   +-----------------+----------------------------------------------------------------------------+-----------------------------------------------------------------+
   | Parameter       | Type                                                                       | Description                                                     |
   +=================+============================================================================+=================================================================+
   | security_policy | :ref:`SecurityPolicy <showsecuritypolicy__response_securitypolicy>` object | This API is used to query details of a custom security policy.  |
   +-----------------+----------------------------------------------------------------------------+-----------------------------------------------------------------+
   | request_id      | String                                                                     | Specifies the request ID. The value is automatically generated. |
   +-----------------+----------------------------------------------------------------------------+-----------------------------------------------------------------+

.. _showsecuritypolicy__response_securitypolicy:

.. table:: **Table 4** SecurityPolicy

   +-------------+--------------------------------------------------------------------------------+----------------------------------------------------------------------+
   | Parameter   | Type                                                                           | Description                                                          |
   +=============+================================================================================+======================================================================+
   | id          | String                                                                         | Specifies the ID of the custom security policy.                      |
   +-------------+--------------------------------------------------------------------------------+----------------------------------------------------------------------+
   | project_id  | String                                                                         | Specifies the project ID of the custom security policy.              |
   +-------------+--------------------------------------------------------------------------------+----------------------------------------------------------------------+
   | name        | String                                                                         | Specifies the name of the custom security policy.                    |
   +-------------+--------------------------------------------------------------------------------+----------------------------------------------------------------------+
   | description | String                                                                         | Provides supplementary information about the custom security policy. |
   +-------------+--------------------------------------------------------------------------------+----------------------------------------------------------------------+
   | listeners   | Array of :ref:`ListenerRef <showsecuritypolicy__response_listenerref>` objects | Specifies the listeners that use the custom security policies.       |
   +-------------+--------------------------------------------------------------------------------+----------------------------------------------------------------------+
   | protocols   | Array of strings                                                               | Lists the TLS protocols supported by the custom security policy.     |
   +-------------+--------------------------------------------------------------------------------+----------------------------------------------------------------------+
   | ciphers     | Array of strings                                                               | Lists the cipher suites supported by the custom security policy.     |
   +-------------+--------------------------------------------------------------------------------+----------------------------------------------------------------------+
   | created_at  | String                                                                         | Specifies the time when the custom security policy was created.      |
   +-------------+--------------------------------------------------------------------------------+----------------------------------------------------------------------+
   | updated_at  | String                                                                         | Specifies the time when the custom security policy was updated.      |
   +-------------+--------------------------------------------------------------------------------+----------------------------------------------------------------------+

.. _showsecuritypolicy__response_listenerref:

.. table:: **Table 5** ListenerRef

   ========= ====== ==========================
   Parameter Type   Description
   ========= ====== ==========================
   id        String Specifies the listener ID.
   ========= ====== ==========================

Example Requests
----------------

Querying details of a custom security policy

.. code-block:: text

   GET https://{ELB_Endpoint}/v3/7a9941d34fc1497d8d0797429ecfd354/elb/security-policies/c73e0138-9bdc-40fb-951e-6a1598266ccd

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

   {
     "security_policy" : {
       "id" : "c73e0138-9bdc-40fb-951e-6a1598266ccd",
       "name" : "update_securitypolicy",
       "project_id" : "7a9941d34fc1497d8d0797429ecfd354",
       "description" : "",
       "protocols" : [ "TLSv1", "TLSv1.1", "TLSv1.2", "TLSv1.3" ],
       "ciphers" : [ "AES128-SHA", "AES256-GCM-SHA384", "ECDHE-ECDSA-AES128-GCM-SHA256", "ECDHE-RSA-AES256-GCM-SHA384", "ECDHE-RSA-AES256-SHA", "TLS_AES_128_GCM_SHA256", "TLS_AES_256_GCM_SHA384", "TLS_CHACHA20_POLY1305_SHA256", "TLS_AES_128_CCM_SHA256", "TLS_AES_128_CCM_8_SHA256" ],
       "listeners" : [ {
         "id" : "8e92b7c3-cdae-4039-aa62-c76d09a5950a"
       } ],
       "created_at" : "2021-03-20T09:48:14Z",
       "updated_at" : "2021-03-20T12:45:50Z"
     },
     "request_id" : "dab5d1de-c115-4623-b21d-363478fa0af4"
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
