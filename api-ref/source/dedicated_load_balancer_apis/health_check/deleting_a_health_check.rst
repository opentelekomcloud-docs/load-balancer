:original_name: DeleteHealthMonitor.html

.. _DeleteHealthMonitor:

Deleting a Health Check
=======================

Function
--------

This API is used to delete a health check.

Constraints
-----------

The health check can be deleted only when the provisioning status of the associated load balancer is **ACTIVE**.

URI
---

DELETE /v3/{project_id}/elb/healthmonitors/{healthmonitor_id}

.. table:: **Table 1** Path Parameters

   ================ ========= ====== ==============================
   Parameter        Mandatory Type   Description
   ================ ========= ====== ==============================
   project_id       Yes       String Specifies the project ID.
   healthmonitor_id Yes       String Specifies the health check ID.
   ================ ========= ====== ==============================

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

   https://{elb_endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/healthmonitors/c2b210b2-60c4-449d-91e2-9e9ea1dd7441

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
