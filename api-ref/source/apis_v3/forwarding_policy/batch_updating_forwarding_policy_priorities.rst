:original_name: BatchUpdatePoliciesPriority.html

.. _BatchUpdatePoliciesPriority:

Batch Updating Forwarding Policy Priorities
===========================================

Function
--------

This API is used to batch update the priorities of forwarding policies.

Constraints
-----------

This API is only used to update the priorities of forwarding policies added to a listener of a dedicated load balancer when **action** is set to **REDIRECT_TO_POOL**.

URI
---

POST /v3/{project_id}/elb/l7policies/batch-update-priority

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

.. table:: **Table 3** Request body parameters

   +------------+-----------+------------------------------------------------------------------------------------------------------------------------------+----------------------------------+
   | Parameter  | Mandatory | Type                                                                                                                         | Description                      |
   +============+===========+==============================================================================================================================+==================================+
   | l7policies | No        | Array of :ref:`BatchUpdatePriorityRequestBody <batchupdatepoliciespriority__request_batchupdatepriorityrequestbody>` objects | Specifies the forwarding policy. |
   +------------+-----------+------------------------------------------------------------------------------------------------------------------------------+----------------------------------+

.. _batchupdatepoliciespriority__request_batchupdatepriorityrequestbody:

.. table:: **Table 4** BatchUpdatePriorityRequestBody

   +-----------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
   +=================+=================+=================+===============================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================+
   | id              | Yes             | String          | Specifies the ID of the forwarding policy.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
   |                 |                 |                 | Minimum: **1**                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
   |                 |                 |                 | Maximum: **36**                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
   +-----------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | priority        | Yes             | Integer         | Specifies the forwarding policy priority. A smaller value indicates a higher priority. The value must be unique for forwarding policies of the same listener.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
   |                 |                 |                 | This parameter will take effect only when **enhance_l7policy_enable** is set to **true**. If this parameter is passed and **enhance_l7policy_enable** is set to **false**, an error will be returned. This parameter is unsupported for shared load balancers.                                                                                                                                                                                                                                                                                                                                                                                                                |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
   |                 |                 |                 | -  If **action** is set to **REDIRECT_TO_LISTENER**, the value can only be **0**, indicating **REDIRECT_TO_LISTENER** has the highest priority.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
   |                 |                 |                 | -  If **enhance_l7policy_enable** is not enabled, forwarding policies are automatically prioritized based on the original policy sorting logic. The priorities of domain names are independent from each other. For the same domain name, the priorities are sorted in the order of exact match (**EQUAL_TO**), prefix match (**STARTS_WITH**), and regular expression match (**REGEX**). If the matching types are the same, the longer the URL is, the higher the priority is. If a forwarding policy contains only a domain name without a path specified, the path is **/**, and prefix match is used by default.                                                         |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
   |                 |                 |                 | -  If **enhance_l7policy_enable** is set to **true** and this parameter is not passed, the priority will be a sum of 1 and the highest priority of existing forwarding policy in the same listener by default. If the highest priority of existing forwarding policies is the maximum (10,000), the forwarding policy will fail to be created because the final priority for creating the forwarding policy is the sum of 1 and 10,000, which exceeds the maximum. In this case, specify a value or adjust the priorities of existing forwarding policies. If no forwarding policies exist, the highest priority of existing forwarding policies will be set to 1 by default. |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
   |                 |                 |                 | This parameter is invalid for shared load balancers.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
   |                 |                 |                 | Minimum: **1**                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
   |                 |                 |                 | Maximum: **10000**                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
   +-----------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Response Parameters
-------------------

**Status code: 202**

.. table:: **Table 5** Response body parameters

   ========== ====== =============================
   Parameter  Type   Description
   ========== ====== =============================
   request_id String Specifies the backend server.
   ========== ====== =============================

Example Requests
----------------

Batch updating the priorities of forwarding policies

.. code-block:: text

   POST https://{ELB_Endpoint}/v3/060576782980d5762f9ec014dd2f1148/elb/l7policies/batch-update-priority

   {
     "l7policies" : [ {
       "id" : "1fe93e12-6e07-47a9-8f81-3346c015601d",
       "priority" : 11
     } ]
   }

Example Responses
-----------------

**Status code: 202**

Created

.. code-block::

   {
     "request_id" : "e5c07525-1470-47b6-9b0c-567527a036aa"
   }

Status Codes
------------

=========== ===========
Status Code Description
=========== ===========
202         Created
=========== ===========

Error Codes
-----------

See :ref:`Error Codes <errorcode>`.
