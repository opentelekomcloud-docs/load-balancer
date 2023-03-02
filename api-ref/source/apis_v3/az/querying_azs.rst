:original_name: ListAvailabilityZones.html

.. _ListAvailabilityZones:

Querying AZs
============

Function
--------

This API is used to query all available AZs when you create a dedicated load balancer.

-  One set of AZs is returned by default. When you create a dedicated load balancer, you can select one or more AZs only in this set.

-  In special scenarios, dedicated load balancers must be created in specific AZs. In the returned one or more sets of AZs, you can select as many AZs as you want as long as the selected AZs are in the same set. For example, if two sets **[az1,az2]** and **[az2,az3]** are returned, you can select **az1** and **az2** or **az2** and **az3**, but cannot select **az1** and **az3**.

URI
---

GET /v3/{project_id}/elb/availability-zones

.. table:: **Table 1** Path Parameters

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
   ========== ========= ====== =========================

.. table:: **Table 2** Query Parameters

   =================== ========= ====== =======================
   Parameter           Mandatory Type   Description
   =================== ========= ====== =======================
   public_border_group No        String Specifies the AZ group.
   =================== ========= ====== =======================

Request Parameters
------------------

.. table:: **Table 3** Request header parameters

   +--------------+-----------+--------+--------------------------------------------------+
   | Parameter    | Mandatory | Type   | Description                                      |
   +==============+===========+========+==================================================+
   | X-Auth-Token | Yes       | String | Specifies the token used for IAM authentication. |
   +--------------+-----------+--------+--------------------------------------------------+

Response Parameters
-------------------

**Status code: 200**

.. table:: **Table 4** Response body parameters

   +--------------------+------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter          | Type                                                                                     | Description                                                                                                                                                                                                                 |
   +====================+==========================================================================================+=============================================================================================================================================================================================================================+
   | request_id         | String                                                                                   | Specifies the request ID. The value is automatically generated.                                                                                                                                                             |
   +--------------------+------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | availability_zones | Array<Array<:ref:`AvailabilityZone <listavailabilityzones__response_availabilityzone>`>> | Specifies the AZs that are available during load balancer creation. For example, in **[az1,az2]** and **[az2,az3]** sets, you can select **az1** and **az2** or **az2** and **az3**, but cannot select **az1** and **az3**. |
   +--------------------+------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _listavailabilityzones__response_availabilityzone:

.. table:: **Table 5** AvailabilityZone

   +---------------------+------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter           | Type             | Description                                                                                                                                                                                                        |
   +=====================+==================+====================================================================================================================================================================================================================+
   | code                | String           | Specifies the AZ code.                                                                                                                                                                                             |
   +---------------------+------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | state               | String           | Specifies the AZ status. The value can only be **ACTIVE**.                                                                                                                                                         |
   +---------------------+------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | protocol            | Array of strings | Specifies the type of the flavor that is not sold out. **L4** indicates the flavor at Layer 4 (flavor for network load balancing). **L7** indicates the flavor at Layer 7 (flavor for application load balancing). |
   +---------------------+------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | public_border_group | String           | Specifies the AZ group, for example, **center**.                                                                                                                                                                   |
   +---------------------+------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | category            | Integer          | Specifies the AZ code. **0** indicates **center**. **21** indicates **homezone**.                                                                                                                                  |
   +---------------------+------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Example Requests
----------------

Querying AZs

.. code-block:: text

   GET https://{ELB_Endpoint}/v3/060576782980d5762f9ec014dd2f1148/elb/availability-zones

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

   {
     "availability_zones" : [ [ {
       "state" : "ACTIVE",
       "code" : "az1",
       "protocol" : [ "L4", "L7" ],
       "public_border_group" : "center",
       "category" : 0
     }, {
       "state" : "ACTIVE",
       "code" : "az2",
       "protocol" : [ "L4" ],
       "public_border_group" : "center",
       "category" : 0
     }, {
       "state" : "ACTIVE",
       "code" : "az3",
       "protocol" : [ "L7" ],
       "public_border_group" : "center",
       "category" : 0
     }, {
       "state" : "ACTIVE",
       "code" : "homezone.az0",
       "protocol" : [ "L4" ],
       "public_border_group" : "homezone.azg",
       "category" : 21
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
