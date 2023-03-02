:original_name: ListSecurityPolicies.html

.. _ListSecurityPolicies:

Querying Custom Security Policies
=================================

Function
--------

This API is used to query custom security policies.Customizing security policy is not supported in **eu-nl** region. Please do not use it.

Constraints
-----------

This API has the following constraints:

-  Parameters **marker**, **limit**, and **page_reverse** are used for pagination query.

-  Parameters **marker** and **page_reverse** take effect only when they are used together with parameter **limit**.

URI
---

GET /v3/{project_id}/elb/security-policies

.. table:: **Table 1** Path Parameters

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
   ========== ========= ====== =========================

.. table:: **Table 2** Query Parameters

   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                                                                                         |
   +=================+=================+=================+=====================================================================================================================================================+
   | marker          | No              | String          | Specifies the ID of the last record on the previous page.                                                                                           |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Note:                                                                                                                                               |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | -  This parameter must be used together with **limit**.                                                                                             |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | -  If this parameter is not specified, the first page will be queried.                                                                              |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | -  This parameter cannot be left blank or set to an invalid ID.                                                                                     |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | limit           | No              | Integer         | Specifies the number of records on each page.                                                                                                       |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Minimum: **0**                                                                                                                                      |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Maximum: **2000**                                                                                                                                   |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Default: **2000**                                                                                                                                   |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | page_reverse    | No              | Boolean         | Specifies whether to use reverse query. Values:                                                                                                     |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | -  **true**: Query the previous page.                                                                                                               |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | -  **false** (default): Query the next page.                                                                                                        |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Note:                                                                                                                                               |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | -  This parameter must be used together with **limit**.                                                                                             |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | -  If **page_reverse** is set to **true** and you want to query the previous page, set the value of **marker** to the value of **previous_marker**. |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | id              | No              | Array           | Specifies the ID of the custom security policy.                                                                                                     |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Multiple IDs can be queried in the format of *id=xxx&id=xxx*.                                                                                       |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | name            | No              | Array           | Specifies the name of the custom security policy.                                                                                                   |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Multiple names can be queried in the format of *name=xxx&name=xxx*.                                                                                 |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | description     | No              | Array           | Provides supplementary information about the custom security policy.                                                                                |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Multiple descriptions can be queried in the format of *description=xxx&description=xxx*.                                                            |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | protocols       | No              | Array           | Specifies the TLS protocols supported by the custom security policy. (Multiple protocols are separated using spaces.)                               |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Multiple protocols can be queried in the format of *protocols=xxx&protocols=xxx*.                                                                   |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | ciphers         | No              | Array           | Specifies the cipher suites supported by the custom security policy. (Multiple cipher suites are separated using colons.)                           |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Multiple cipher suites can be queried in the format of *ciphers=xxx&ciphers=xxx*.                                                                   |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+

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

   +-------------------+----------------------------------------------------------------------------------------+-----------------------------------------------------------------+
   | Parameter         | Type                                                                                   | Description                                                     |
   +===================+========================================================================================+=================================================================+
   | security_policies | Array of :ref:`SecurityPolicy <listsecuritypolicies__response_securitypolicy>` objects | Lists the security policies.                                    |
   +-------------------+----------------------------------------------------------------------------------------+-----------------------------------------------------------------+
   | request_id        | String                                                                                 | Specifies the request ID. The value is automatically generated. |
   +-------------------+----------------------------------------------------------------------------------------+-----------------------------------------------------------------+
   | page_info         | :ref:`PageInfo <listsecuritypolicies__response_pageinfo>` object                       | Shows pagination information.                                   |
   +-------------------+----------------------------------------------------------------------------------------+-----------------------------------------------------------------+

.. _listsecuritypolicies__response_securitypolicy:

.. table:: **Table 5** SecurityPolicy

   +-------------+----------------------------------------------------------------------------------+----------------------------------------------------------------------+
   | Parameter   | Type                                                                             | Description                                                          |
   +=============+==================================================================================+======================================================================+
   | id          | String                                                                           | Specifies the ID of the custom security policy.                      |
   +-------------+----------------------------------------------------------------------------------+----------------------------------------------------------------------+
   | project_id  | String                                                                           | Specifies the project ID of the custom security policy.              |
   +-------------+----------------------------------------------------------------------------------+----------------------------------------------------------------------+
   | name        | String                                                                           | Specifies the name of the custom security policy.                    |
   +-------------+----------------------------------------------------------------------------------+----------------------------------------------------------------------+
   | description | String                                                                           | Provides supplementary information about the custom security policy. |
   +-------------+----------------------------------------------------------------------------------+----------------------------------------------------------------------+
   | listeners   | Array of :ref:`ListenerRef <listsecuritypolicies__response_listenerref>` objects | Specifies the listeners that use the custom security policies.       |
   +-------------+----------------------------------------------------------------------------------+----------------------------------------------------------------------+
   | protocols   | Array of strings                                                                 | Lists the TLS protocols supported by the custom security policy.     |
   +-------------+----------------------------------------------------------------------------------+----------------------------------------------------------------------+
   | ciphers     | Array of strings                                                                 | Lists the cipher suites supported by the custom security policy.     |
   +-------------+----------------------------------------------------------------------------------+----------------------------------------------------------------------+
   | created_at  | String                                                                           | Specifies the time when the custom security policy was created.      |
   +-------------+----------------------------------------------------------------------------------+----------------------------------------------------------------------+
   | updated_at  | String                                                                           | Specifies the time when the custom security policy was updated.      |
   +-------------+----------------------------------------------------------------------------------+----------------------------------------------------------------------+

.. _listsecuritypolicies__response_listenerref:

.. table:: **Table 6** ListenerRef

   ========= ====== ==========================
   Parameter Type   Description
   ========= ====== ==========================
   id        String Specifies the listener ID.
   ========= ====== ==========================

.. _listsecuritypolicies__response_pageinfo:

.. table:: **Table 7** PageInfo

   +-----------------+---------+---------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Type    | Description                                                                                                         |
   +=================+=========+=====================================================================================================================+
   | previous_marker | String  | Specifies the ID of the first record in the pagination query result. Set this parameter to query the previous page. |
   +-----------------+---------+---------------------------------------------------------------------------------------------------------------------+
   | next_marker     | String  | Specifies the ID of the last record in the pagination query result. Set this to marker when query the next page.    |
   +-----------------+---------+---------------------------------------------------------------------------------------------------------------------+
   | current_count   | Integer | Specifies the number of records.                                                                                    |
   +-----------------+---------+---------------------------------------------------------------------------------------------------------------------+

Example Requests
----------------

Querying custom security policies on each page

.. code-block:: text

   GET https://{ELB_Endpoint}/v3/7a9941d34fc1497d8d0797429ecfd354/elb/security-policies?limit=2

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

   {
     "request_id" : "88424a61-6fa1-4850-aa8b-ce31d78abcf2",
     "security_policies" : [ {
       "id" : "03cf511a-d130-445e-9b02-12d7049ddabf",
       "name" : "test_security_policy",
       "project_id" : "7a9941d34fc1497d8d0797429ecfd354",
       "description" : "",
       "protocols" : [ "TLSv1", "TLSv1.3" ],
       "ciphers" : [ "AES128-SHA", "TLS_AES_128_GCM_SHA256", "TLS_AES_256_GCM_SHA384", "TLS_CHACHA20_POLY1305_SHA256", "TLS_AES_128_CCM_SHA256", "TLS_AES_128_CCM_8_SHA256" ],
       "listeners" : [ {
         "id" : "6f7c0d75-81c4-4735-87a0-dc5df0f27f5a"
       } ],
       "created_at" : "2021-02-06T10:07:10Z",
       "updated_at" : "2021-02-06T10:07:10Z"
     }, {
       "id" : "04e5d426-628c-42db-867c-fcaefbed2cab",
       "name" : "update_securitypolicy",
       "project_id" : "7a9941d34fc1497d8d0797429ecfd354",
       "description" : "",
       "protocols" : [ "TLSv1.2", "TLSv1.1", "TLSv1.3" ],
       "ciphers" : [ "CAMELLIA128-SHA", "TLS_AES_256_GCM_SHA384", "TLS_CHACHA20_POLY1305_SHA256", "TLS_AES_128_CCM_SHA256", "TLS_AES_128_CCM_8_SHA256" ],
       "listeners" : [ {
         "id" : "e19b7379-807e-47fb-b53d-46aff540580c"
       } ],
       "created_at" : "2021-02-06T10:01:58Z",
       "updated_at" : "2021-03-20T07:18:59Z"
     } ],
     "page_info" : {
       "next_marker" : "04e5d426-628c-42db-867c-fcaefbed2cab",
       "previous_marker" : "03cf511a-d130-445e-9b02-12d7049ddabf",
       "current_count" : 2
     }
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
