============
Querying AZs
============

Function
^^^^^^^^

This API is used to query all available AZs when you create a dedicated load
balancer.

One set of AZs is returned. When you create a dedicated load balancer, you
can select one or more AZs only in the set.

URI
^^^

GET /v3/{project_id}/elb/availability-zones

.. table:: **Table 1** Path parameters

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
   ========== ========= ====== =========================

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 2** Request header parameters

   ============ ========= ====== ================================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ================================================
   X-Auth-Token Yes       String Specifies the token used for IAM authentication.
   ============ ========= ====== ================================================

Response Parameters
^^^^^^^^^^^^^^^^^^^

**Status code: 200**

.. table:: **Table 3** Response body parameters

   +--------------------+------------+---------------------------------------------+
   | Parameter          | Type       | Description                                 |
   +====================+============+=============================================+
   | availability_zones | :ref:`daz` | Specifies the AZs that are available during |
   |                    |            | load balancer creation.                     |
   +--------------------+------------+---------------------------------------------+
   | request_id         | String     | Specifies the request ID. The value is      |
   |                    |            | automatically generated.                    |
   +--------------------+------------+---------------------------------------------+

.. _daz:
.. table:: **Table 4** AvailabilityZone

   ========= ====== ==========================================================
   Parameter Type   Description
   ========= ====== ==========================================================
   state     String Specifies the AZ status. The value can only be **ACTIVE**.
   code      String Specifies the AZ code.
   ========= ====== ==========================================================

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   GET

   https://{ELB_Endpoint}/v3/060576782980d5762f9ec014dd2f1148/elb/availability-zones

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 200**

Successful request.

.. code::

   {
     "availability_zones" : [ [ {
       "state" : "ACTIVE",
       "code" : "az1"
     }, {
       "state" : "ACTIVE",
       "code" : "az2"
     }, {
       "state" : "ACTIVE",
       "code" : "az3"
     } ] ],
     "request_id" : "0d799435-259e-459f-b2bc-0beee06f6a77"
   }

Status Codes
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
200         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.
