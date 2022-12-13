:original_name: ShowFlavor.html

.. _ShowFlavor:

Viewing Details of a Flavor
===========================

Function
--------

This API is used to view details of a flavor.

Constraints
-----------

This API can only be used to view the details of a flavor.

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

   +-----------------------+------------------------------------------------------------+------------------------------------------------------------------------------+
   | Parameter             | Type                                                       | Description                                                                  |
   +=======================+============================================================+==============================================================================+
   | id                    | String                                                     | Specifies the flavor ID.                                                     |
   +-----------------------+------------------------------------------------------------+------------------------------------------------------------------------------+
   | info                  | :ref:`FlavorInfo <showflavor__response_flavorinfo>` object | Specifies the flavor details.                                                |
   +-----------------------+------------------------------------------------------------+------------------------------------------------------------------------------+
   | name                  | String                                                     | Specifies the flavor name.                                                   |
   +-----------------------+------------------------------------------------------------+------------------------------------------------------------------------------+
   | shared                | Boolean                                                    | Specifies whether the flavor is available to all users.                      |
   |                       |                                                            |                                                                              |
   |                       |                                                            | -  **true** indicates that the flavor is available to all users.             |
   |                       |                                                            |                                                                              |
   |                       |                                                            | -  **false** indicates that the flavor is available only to a specific user. |
   |                       |                                                            |                                                                              |
   |                       |                                                            | Default: **true**                                                            |
   +-----------------------+------------------------------------------------------------+------------------------------------------------------------------------------+
   | project_id            | String                                                     | Specifies the project ID.                                                    |
   +-----------------------+------------------------------------------------------------+------------------------------------------------------------------------------+
   | type                  | String                                                     | Specifies the flavor type. Flavors can be filtered by type.                  |
   |                       |                                                            |                                                                              |
   |                       |                                                            | Minimum: **1**                                                               |
   |                       |                                                            |                                                                              |
   |                       |                                                            | Maximum: **32**                                                              |
   +-----------------------+------------------------------------------------------------+------------------------------------------------------------------------------+

.. _showflavor__response_flavorinfo:

.. table:: **Table 5** FlavorInfo

   +------------+---------+---------------------------------------------------------------------+
   | Parameter  | Type    | Description                                                         |
   +============+=========+=====================================================================+
   | connection | Integer | Specifies the maximum concurrent connections.                       |
   +------------+---------+---------------------------------------------------------------------+
   | cps        | Integer | Specifies the number of new connections per second.                 |
   +------------+---------+---------------------------------------------------------------------+
   | qps        | Integer | Specifies the number of requests per second at Layer 7.             |
   +------------+---------+---------------------------------------------------------------------+
   | bandwidth  | Integer | Specifies the inbound and outbound bandwidth in the unit of Kbit/s. |
   +------------+---------+---------------------------------------------------------------------+

Example Requests
----------------

.. code-block:: text

   GET https://{elb_endpoint}/v3/{project_id}/elb/flavors/{flavor_id}

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

   {
     "flavor" : {
       "shared" : true,
       "project_id" : "573d73c9f90e48d0bddfa0eb202b25c2",
       "info" : {
         "connection" : 6000,
         "cps" : 3000,
         "qps" : 1000
       },
       "id" : "becf3beb-7653-45ab-a025-961597a901bc",
       "name" : "L7_flavor.elb.s2.medium",
       "type" : "L7"
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
