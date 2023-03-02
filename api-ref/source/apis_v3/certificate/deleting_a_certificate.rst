:original_name: DeleteCertificate.html

.. _DeleteCertificate:

Deleting a Certificate
======================

Function
--------

This API is used to delete an SSL certificate.

Constraints
-----------

If the certificate is used by a listener, the certificate cannot be deleted, and the 409 Conflict error code will be displayed.

URI
---

DELETE /v3/{project_id}/elb/certificates/{certificate_id}

.. table:: **Table 1** Path Parameters

   ============== ========= ====== ===========================
   Parameter      Mandatory Type   Description
   ============== ========= ====== ===========================
   project_id     Yes       String Specifies the project ID.
   certificate_id Yes       String Specifies a certificate ID.
   ============== ========= ====== ===========================

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

Deleting an SSL certificate

.. code-block:: text

   DELETE https://{ELB_Endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/certificates/233a325e5e3e4ce8beeb320aa714cc12

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
