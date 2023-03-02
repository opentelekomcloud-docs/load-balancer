:original_name: elb_jd_zs_0002.html

.. _elb_jd_zs_0002:

Deleting a Certificate
======================

Function
--------

This API is used to delete a certificate.

URI
---

DELETE /v1.0/{project_id}/elbaas/certificate/{certificate_id}

.. table:: **Table 1** Parameter description

   ============== ========= ====== =============================
   Parameter      Mandatory Type   Description
   ============== ========= ====== =============================
   project_id     Yes       String Specifies the project ID.
   certificate_id Yes       String Specifies the certificate ID.
   ============== ========= ====== =============================

Request
-------

-  Request parameters

   None

-  Example request

   None

Response
--------

-  Response parameters

   None

-  Example response

   None

Status Code
-----------

-  Normal

   204

-  Error

   +-------------+--------------------+----------------------------------------------------------+
   | Status Code | Message            | Description                                              |
   +=============+====================+==========================================================+
   | 400         | badRequest         | Request error.                                           |
   +-------------+--------------------+----------------------------------------------------------+
   | 401         | unauthorized       | Authentication failed.                                   |
   +-------------+--------------------+----------------------------------------------------------+
   | 403         | userDisabled       | You do not have the permission to perform the operation. |
   +-------------+--------------------+----------------------------------------------------------+
   | 404         | Not Found          | The requested page does not exist.                       |
   +-------------+--------------------+----------------------------------------------------------+
   | 500         | authFault          | System error.                                            |
   +-------------+--------------------+----------------------------------------------------------+
   | 503         | serviceUnavailable | The service is unavailable.                              |
   +-------------+--------------------+----------------------------------------------------------+
