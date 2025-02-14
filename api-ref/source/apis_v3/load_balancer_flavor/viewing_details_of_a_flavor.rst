:original_name: ShowFlavor.html

.. _ShowFlavor:

Viewing Details of a Flavor
===========================

Function
--------

This API is used to view details of a flavor.

URI
---

GET /v3/{project_id}/elb/flavors/{flavor_id}

.. table:: **Table 1** Path Parameters

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
   flavor_id  Yes       String Specifies the flavor ID.
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

   +------------+----------------------------------------------------+-----------------------------------------------------------------+
   | Parameter  | Type                                               | Description                                                     |
   +============+====================================================+=================================================================+
   | request_id | String                                             | Specifies the request ID. The value is automatically generated. |
   +------------+----------------------------------------------------+-----------------------------------------------------------------+
   | flavor     | :ref:`Flavor <showflavor__response_flavor>` object | Specifies the flavor.                                           |
   +------------+----------------------------------------------------+-----------------------------------------------------------------+

.. _showflavor__response_flavor:

.. table:: **Table 4** Flavor

   +-----------------------+------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                                                       | Description                                                                                                             |
   +=======================+============================================================+=========================================================================================================================+
   | id                    | String                                                     | Specifies the flavor ID.                                                                                                |
   +-----------------------+------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------+
   | info                  | :ref:`FlavorInfo <showflavor__response_flavorinfo>` object | Specifies the flavor metrics.                                                                                           |
   +-----------------------+------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                                                     | Specifies the flavor name.                                                                                              |
   +-----------------------+------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------+
   | shared                | Boolean                                                    | Specifies whether the flavor is available to all users.                                                                 |
   |                       |                                                            |                                                                                                                         |
   |                       |                                                            | -  true indicates that the flavor is available to all users.                                                            |
   |                       |                                                            |                                                                                                                         |
   |                       |                                                            | -  false indicates that the flavor is available only to a specific user.                                                |
   +-----------------------+------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------+
   | project_id            | String                                                     | Specifies the project ID.                                                                                               |
   +-----------------------+------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------+
   | type                  | String                                                     | Specifies the flavor type. The value can be one of the following:                                                       |
   |                       |                                                            |                                                                                                                         |
   |                       |                                                            | -  **L4**: a Layer-4 flavor.                                                                                            |
   |                       |                                                            |                                                                                                                         |
   |                       |                                                            | -  **L7**: a Layer-7 flavor.                                                                                            |
   |                       |                                                            |                                                                                                                         |
   |                       |                                                            | -  **L4_elastic_max**: the maximum elastic flavor at Layer 4.                                                           |
   |                       |                                                            |                                                                                                                         |
   |                       |                                                            | -  **L7_elastic_max**: the maximum elastic flavor at Layer 7.                                                           |
   |                       |                                                            |                                                                                                                         |
   |                       |                                                            | -  **L4_elastic** indicates minimum elastic flavor at Layer 4. This parameter has been discarded. Please do not use it. |
   |                       |                                                            |                                                                                                                         |
   |                       |                                                            | -  **L7_elastic** indicates minimum elastic flavor at Layer 7. This parameter has been discarded. Please do not use it. |
   |                       |                                                            |                                                                                                                         |
   |                       |                                                            | Minimum: **1**                                                                                                          |
   |                       |                                                            |                                                                                                                         |
   |                       |                                                            | Maximum: **32**                                                                                                         |
   +-----------------------+------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------+
   | flavor_sold_out       | Boolean                                                    | Specifies whether the flavor is unavailable.                                                                            |
   |                       |                                                            |                                                                                                                         |
   |                       |                                                            | -  **true** indicates the flavor is unavailable. Load balancers with this flavor cannot be created.                     |
   |                       |                                                            |                                                                                                                         |
   |                       |                                                            | -  **false** indicates the flavor is available. Load balancers with this flavor can be created.                         |
   +-----------------------+------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------+

.. _showflavor__response_flavorinfo:

.. table:: **Table 5** FlavorInfo

   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                          |
   +=======================+=======================+======================================================================================================================================+
   | connection            | Integer               | Specifies the number of concurrent connections per second.                                                                           |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------+
   | cps                   | Integer               | Specifies the number of new connections per second.                                                                                  |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------+
   | qps                   | Integer               | Specifies the number of requests per second. This parameter is available only for load balancers at Layer 7.                         |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------+
   | bandwidth             | Integer               | Specifies the bandwidth.                                                                                                             |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------+
   | lcu                   | Integer               | Specifies the number of LCUs in the flavor.                                                                                          |
   |                       |                       |                                                                                                                                      |
   |                       |                       | An LCU measures the dimensions on which a dedicated load balancer routes the traffic. The higher value indicates better performance. |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------+
   | https_cps             | Integer               | Specifies the number of new HTTPS connections. This parameter is available only for load balancers at Layer 7.                       |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------+

Example Requests
----------------

.. code-block:: text

   GET https://{ELB_Endpoint}/v3/{project_id}/elb/flavors/{flavor_id}

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

   {
     "flavor" : {
       "shared" : true,
       "project_id" : "8d53f081ea24444aa95e2bfa942ef6ee",
       "info" : {
         "bandwidth" : 10000000,
         "connection" : 8000000,
         "cps" : 80000,
         "qps" : 160000,
         "lcu" : 100
       },
       "id" : "3588b525-63ed-4b8f-8a03-6aaa9ad1c36a",
       "name" : "L7_flavor.slb.s2.large",
       "type" : "L7",
       "flavor_sold_out" : false
     },
     "request_id" : "3b9fb516-b7bb-4760-9128-4a23dd36ae10"
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
