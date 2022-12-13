:original_name: ListAvailabilityZones.html

.. _ListAvailabilityZones:

Querying AZs
============

Function
--------

This API is used to query all available AZs when you create a load balancer.

One set of AZs is returned. When you create a load balancer, you can select one or more AZs only in the set.

In special scenarios, load balancers must be created in specific AZs. In the returned one or more sets of AZs, you can select as many AZs as you want as long as the selected AZs are in the same set. For example, if two sets **[az1,az2]** and **[az2,az3]** are returned, you can select **az1** and **az2** or **az2** and **az3**, but cannot select **az1** and **az3**.

URI
---

GET /v3/{project_id}/elb/availability-zones

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

Response Parameters
-------------------

**Status code: 200**

.. table:: **Table 3** Response body parameters

   +--------------------+------------------------------------------------------------------------------------------+---------------------------------------------------------------------+
   | Parameter          | Type                                                                                     | Description                                                         |
   +====================+==========================================================================================+=====================================================================+
   | availability_zones | Array<Array<:ref:`AvailabilityZone <listavailabilityzones__response_availabilityzone>`>> | Specifies the AZs that are available during load balancer creation. |
   +--------------------+------------------------------------------------------------------------------------------+---------------------------------------------------------------------+
   | request_id         | String                                                                                   | Specifies the request ID. The value is automatically generated.     |
   +--------------------+------------------------------------------------------------------------------------------+---------------------------------------------------------------------+

.. _listavailabilityzones__response_availabilityzone:

.. table:: **Table 4** AvailabilityZone

   +-----------+--------+------------------------------------------------------------+
   | Parameter | Type   | Description                                                |
   +===========+========+============================================================+
   | state     | String | Specifies the AZ status. The value can only be **ACTIVE**. |
   +-----------+--------+------------------------------------------------------------+
   | code      | String | Specifies the AZ code.                                     |
   +-----------+--------+------------------------------------------------------------+

Example Requests
----------------

.. code-block:: text

   GET

   https://{ELB_Endpoint}/v3/060576782980d5762f9ec014dd2f1148/elb/availability-zones

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

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
------------

=========== ===================
Status Code Description
=========== ===================
200         Successful request.
=========== ===================

Error Codes
-----------

See :ref:`Error Codes <errorcode>`.
