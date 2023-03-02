:original_name: DeleteL7Policy.html

.. _DeleteL7Policy:

Deleting a Forwarding Policy
============================

Function
--------

This API is used to delete a forwarding policy.

URI
---

DELETE /v3/{project_id}/elb/l7policies/{l7policy_id}

.. table:: **Table 1** Path Parameters

   =========== ========= ====== ===================================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ===================================
   project_id  Yes       String Specifies the project ID.
   l7policy_id Yes       String Specifies the forwarding policy ID.
   =========== ========= ====== ===================================

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

None

Example Requests
----------------

.. code-block:: text

   DELETE https://{ELB_Endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/l7policies/cf4360fd-8631-41ff-a6f5-b72c35da74be

Example Responses
-----------------

None

Status Codes
------------

=========== ===================
Status Code Description
=========== ===================
204         Successful request.
=========== ===================

Error Codes
-----------

See :ref:`Error Codes <errorcode>`.
