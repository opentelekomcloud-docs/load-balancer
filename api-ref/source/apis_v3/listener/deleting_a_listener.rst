:original_name: DeleteListener.html

.. _DeleteListener:

Deleting a Listener
===================

Function
--------

This API is used to delete a listener.

Constraints
-----------

Before you delete a listener, delete associated backend server groups or remove all backend servers in the default backend server group, and delete all forwarding policies.

URI
---

DELETE /v3/{project_id}/elb/listeners/{listener_id}

.. table:: **Table 1** Path Parameters

   =========== ========= ====== ==========================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ==========================
   project_id  Yes       String Specifies the project ID.
   listener_id Yes       String Specifies the listener ID.
   =========== ========= ====== ==========================

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

   DELETE https://{ELB_Endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/listeners/0b11747a-b139-492f-9692-2df0b1c87193

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
