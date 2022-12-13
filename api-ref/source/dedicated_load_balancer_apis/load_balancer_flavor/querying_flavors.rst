:original_name: ListFlavors.html

.. _ListFlavors:

Querying Flavors
================

Function
--------

This API is used to query all load balancer flavors that are available to a specific user in a specific region.

Constraints
-----------

Parameters **marker**, **limit**, and **page_reverse** are used for pagination query.

Parameters **marker** and **page_reverse** take effect only when they are used together with parameter **limit**.

URI
---

GET /v3/{project_id}/elb/flavors

.. table:: **Table 1** Path Parameters

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
   ========== ========= ====== =========================

.. table:: **Table 2** Query Parameters

   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                                                                                                                                                                      |
   +=================+=================+=================+==================================================================================================================================================================================================================================+
   | marker          | No              | String          | Specifies the ID of the last record on the previous page.                                                                                                                                                                        |
   |                 |                 |                 |                                                                                                                                                                                                                                  |
   |                 |                 |                 | Note:                                                                                                                                                                                                                            |
   |                 |                 |                 |                                                                                                                                                                                                                                  |
   |                 |                 |                 | -  This parameter must be used together with **limit**.                                                                                                                                                                          |
   |                 |                 |                 |                                                                                                                                                                                                                                  |
   |                 |                 |                 | -  If this parameter is not specified, the first page will be queried.                                                                                                                                                           |
   |                 |                 |                 |                                                                                                                                                                                                                                  |
   |                 |                 |                 | -  This parameter cannot be left blank or set to an invalid ID.                                                                                                                                                                  |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | limit           | No              | Integer         | Specifies the number of records on each page.                                                                                                                                                                                    |
   |                 |                 |                 |                                                                                                                                                                                                                                  |
   |                 |                 |                 | Minimum: **0**                                                                                                                                                                                                                   |
   |                 |                 |                 |                                                                                                                                                                                                                                  |
   |                 |                 |                 | Maximum: **2000**                                                                                                                                                                                                                |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | page_reverse    | No              | Boolean         | Specifies the page direction.                                                                                                                                                                                                    |
   |                 |                 |                 |                                                                                                                                                                                                                                  |
   |                 |                 |                 | The value can be **true** or **false**, and the default value is **false**.                                                                                                                                                      |
   |                 |                 |                 |                                                                                                                                                                                                                                  |
   |                 |                 |                 | The last page in the list requested with **page_reverse** set to **false** will not contain the "next" link, and the last page in the list requested with **page_reverse** set to **true** will not contain the "previous" link. |
   |                 |                 |                 |                                                                                                                                                                                                                                  |
   |                 |                 |                 | This parameter must be used together with **limit**.                                                                                                                                                                             |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | id              | No              | Array           | Specifies the flavor ID.                                                                                                                                                                                                         |
   |                 |                 |                 |                                                                                                                                                                                                                                  |
   |                 |                 |                 | Multiple IDs can be queried in the format of *id=xxx&id=xxx*.                                                                                                                                                                    |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name            | No              | Array           | Specifies the flavor name.                                                                                                                                                                                                       |
   |                 |                 |                 |                                                                                                                                                                                                                                  |
   |                 |                 |                 | Multiple names can be queried in the format of *name=xxx&name=xxx*.                                                                                                                                                              |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | type            | No              | Array           | Specifies the flavor type. Flavors can be filtered by type.                                                                                                                                                                      |
   |                 |                 |                 |                                                                                                                                                                                                                                  |
   |                 |                 |                 | Multiple types can be queried in the format of *type=xxx&type=xxx*.                                                                                                                                                              |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | shared          | No              | Boolean         | Specifies whether the flavor is available to all users.                                                                                                                                                                          |
   |                 |                 |                 |                                                                                                                                                                                                                                  |
   |                 |                 |                 | -  **true** indicates that the flavor is available to all users.                                                                                                                                                                 |
   |                 |                 |                 |                                                                                                                                                                                                                                  |
   |                 |                 |                 | -  **false** indicates that the flavor is available only to a specific user.                                                                                                                                                     |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

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

   +------------+---------------------------------------------------------------+-----------------------------------------------------------------+
   | Parameter  | Type                                                          | Description                                                     |
   +============+===============================================================+=================================================================+
   | flavors    | Array of :ref:`Flavor <listflavors__response_flavor>` objects | Lists the flavors.                                              |
   +------------+---------------------------------------------------------------+-----------------------------------------------------------------+
   | page_info  | :ref:`PageInfo <listflavors__response_pageinfo>` object       | Shows pagination information about the load balancer flavors.   |
   +------------+---------------------------------------------------------------+-----------------------------------------------------------------+
   | request_id | String                                                        | Specifies the request ID. The value is automatically generated. |
   +------------+---------------------------------------------------------------+-----------------------------------------------------------------+

.. _listflavors__response_flavor:

.. table:: **Table 5** Flavor

   +-----------------------+-------------------------------------------------------------+------------------------------------------------------------------------------+
   | Parameter             | Type                                                        | Description                                                                  |
   +=======================+=============================================================+==============================================================================+
   | id                    | String                                                      | Specifies the flavor ID.                                                     |
   +-----------------------+-------------------------------------------------------------+------------------------------------------------------------------------------+
   | info                  | :ref:`FlavorInfo <listflavors__response_flavorinfo>` object | Specifies the flavor details.                                                |
   +-----------------------+-------------------------------------------------------------+------------------------------------------------------------------------------+
   | name                  | String                                                      | Specifies the flavor name.                                                   |
   +-----------------------+-------------------------------------------------------------+------------------------------------------------------------------------------+
   | shared                | Boolean                                                     | Specifies whether the flavor is available to all users.                      |
   |                       |                                                             |                                                                              |
   |                       |                                                             | -  **true** indicates that the flavor is available to all users.             |
   |                       |                                                             |                                                                              |
   |                       |                                                             | -  **false** indicates that the flavor is available only to a specific user. |
   |                       |                                                             |                                                                              |
   |                       |                                                             | Default: **true**                                                            |
   +-----------------------+-------------------------------------------------------------+------------------------------------------------------------------------------+
   | project_id            | String                                                      | Specifies the project ID.                                                    |
   +-----------------------+-------------------------------------------------------------+------------------------------------------------------------------------------+
   | type                  | String                                                      | Specifies the flavor type. Flavors can be filtered by type.                  |
   |                       |                                                             |                                                                              |
   |                       |                                                             | Minimum: **1**                                                               |
   |                       |                                                             |                                                                              |
   |                       |                                                             | Maximum: **32**                                                              |
   +-----------------------+-------------------------------------------------------------+------------------------------------------------------------------------------+

.. _listflavors__response_flavorinfo:

.. table:: **Table 6** FlavorInfo

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

.. _listflavors__response_pageinfo:

.. table:: **Table 7** PageInfo

   +-----------------+---------+------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Type    | Description                                                                                                                              |
   +=================+=========+==========================================================================================================================================+
   | previous_marker | String  | Specifies the ID of the first record in the pagination query result. This parameter will not be returned if no query result is returned. |
   +-----------------+---------+------------------------------------------------------------------------------------------------------------------------------------------+
   | next_marker     | String  | Marks the start record on the next page in the pagination query result. This parameter will not be returned if there is no next page.    |
   +-----------------+---------+------------------------------------------------------------------------------------------------------------------------------------------+
   | current_count   | Integer | Specifies the number of records.                                                                                                         |
   +-----------------+---------+------------------------------------------------------------------------------------------------------------------------------------------+

Example Requests
----------------

.. code-block:: text

   GET https://{ELB_Endpoint}/v3/{060576782980d5762f9ec014dd2f1148}/elb/flavors?limit=2&marker=179568ef-5ba4-4ca0-8c5e-5d581db779b1

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

   {
     "flavors" : [ {
       "shared" : true,
       "project_id" : "573d73c9f90e48d0bddfa0eb202b25c2",
       "info" : {
         "connection" : 1000000,
         "cps" : 80000,
         "qps" : 50000
       },
       "id" : "b2c5d750-5ea8-42f8-a6a8-8b0a1441168a",
       "name" : "L7_flavor.elb.s2.medium",
       "type" : "L7"
     }, {
       "shared" : true,
       "project_id" : "573d73c9f90e48d0bddfa0eb202b25c2",
       "info" : {
         "connection" : 6000,
         "cps" : 3000
       },
       "id" : "becf3beb-7653-45ab-a025-961597a901bc",
       "name" : "L4_flavor.elb.s2.small",
       "type" : "L4"
     } ],
     "page_info" : {
       "next_marker" : "fb9394ab-d63d-4b4d-8ea0-b6dc974accc6",
       "previous_marker" : "b2c5d750-5ea8-42f8-a6a8-8b0a1441168a",
       "current_count" : 3
     },
     "request_id" : "07b7cabe-bfb5-4809-8c28-5a90a961a707"
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
