:original_name: DeleteLogtank.html

.. _DeleteLogtank:

Deleting a Log
==============

Function
--------

This API is used to delete a log.

URI
---

DELETE /v3/{project_id}/elb/logtanks/{logtank_id}

.. table:: **Table 1** Path Parameters

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
   logtank_id Yes       String Specifies the log ID.
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

None

Example Requests
----------------

Deleting a log

.. code-block:: text

   DELETE https://{ELB_Endpoint}/v3/060576798a80d5762fafc01a9b5eedc7/elb/logtanks/603e507f-3e18-498b-9460-01a3b6c28fc5

Example Responses
-----------------

None

Status Codes
------------

=========== ===========
Status Code Description
=========== ===========
204         No Content
=========== ===========

Error Codes
-----------

See :ref:`Error Codes <errorcode>`.
