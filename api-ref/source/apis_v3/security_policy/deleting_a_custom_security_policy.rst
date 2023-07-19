:original_name: DeleteSecurityPolicy.html

.. _DeleteSecurityPolicy:

Deleting a Custom Security Policy
=================================

Function
--------

This API is used to delete a custom security policy.

Constraints
-----------

A custom security policy that has been used by a listener cannot be deleted.

URI
---

DELETE /v3/{project_id}/elb/security-policies/{security_policy_id}

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

None

Example Requests
----------------

Deleting a custom security policy

.. code-block:: text

   DELETE https://{ELB_Endpoint}/v3/45977fa2dbd7482098dd68d0d8970117/elb/security-policies/8722e0e0-9cc9-4490-9660-8c9a5732fbb0

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
