:original_name: DeleteListener.html

.. _DeleteListener:

Deleting a Listener
===================

Function
--------

This API is used to delete a listener.

Constraints
-----------

Before you delete a listener, delete the associated backend server group or disassociate the backend server group from the listener, and then delete all forwarding policies.

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

   DELETE
   https://{elb_endpoint}/v3/{project_id}/elb/listeners/{listener_id}

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
