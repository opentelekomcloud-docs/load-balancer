:original_name: ListFlavors.html

.. _ListFlavors:

Querying Flavors
================

Function
--------

This API is used to query all load balancer flavors that are available to a specific user in a specific region.

Constraints
-----------

This API has the following constraints:

-  Parameters **marker**, **limit**, and **page_reverse** are used for pagination query.

-  Parameters **marker** and **page_reverse** take effect only when they are used together with parameter **limit**.

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

   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                                                                                         |
   +=================+=================+=================+=====================================================================================================================================================+
   | marker          | No              | String          | Specifies the ID of the last record on the previous page.                                                                                           |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Note:                                                                                                                                               |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | -  This parameter must be used together with **limit**.                                                                                             |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | -  If this parameter is not specified, the first page will be queried.                                                                              |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | -  This parameter cannot be left blank or set to an invalid ID.                                                                                     |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | limit           | No              | Integer         | Specifies the number of records on each page.                                                                                                       |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Minimum: **0**                                                                                                                                      |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Maximum: **2000**                                                                                                                                   |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Default: **2000**                                                                                                                                   |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | page_reverse    | No              | Boolean         | Specifies whether to use reverse query. Values:                                                                                                     |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | -  **true**: Query the previous page.                                                                                                               |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | -  **false** (default): Query the next page.                                                                                                        |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Note:                                                                                                                                               |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | -  This parameter must be used together with **limit**.                                                                                             |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | -  If **page_reverse** is set to **true** and you want to query the previous page, set the value of **marker** to the value of **previous_marker**. |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | id              | No              | Array           | Specifies the flavor ID.                                                                                                                            |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Multiple IDs can be queried in the format of *id=xxx&id=xxx*.                                                                                       |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | name            | No              | Array           | Specifies the flavor name.                                                                                                                          |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Multiple names can be queried in the format of *name=xxx&name=xxx*.                                                                                 |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | type            | No              | Array           | Specifies the flavor type. Values can be one of the following:                                                                                      |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | -  **L4** indicates a Layer-4 flavor.                                                                                                               |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | -  **L7** indicates a Layer-7 flavor.                                                                                                               |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Multiple types can be queried in the format of *type=xxx&type=xxx*.                                                                                 |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | shared          | No              | Boolean         | Specifies whether the flavor is available to all users.                                                                                             |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | -  **true** indicates that the flavor is available to all users.                                                                                    |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | -  **false** indicates that the flavor is available only to a specific user.                                                                        |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+

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

   +-----------------------+-------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | Parameter             | Type                                                        | Description                                                                                         |
   +=======================+=============================================================+=====================================================================================================+
   | id                    | String                                                      | Specifies the flavor ID.                                                                            |
   +-----------------------+-------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | info                  | :ref:`FlavorInfo <listflavors__response_flavorinfo>` object | Specifies the flavor metrics.                                                                       |
   +-----------------------+-------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | name                  | String                                                      | Specifies the flavor name.                                                                          |
   +-----------------------+-------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | shared                | Boolean                                                     | Specifies whether the flavor is available to all users.                                             |
   |                       |                                                             |                                                                                                     |
   |                       |                                                             | -  true indicates that the flavor is available to all users.                                        |
   |                       |                                                             |                                                                                                     |
   |                       |                                                             | -  false indicates that the flavor is available only to a specific user.                            |
   +-----------------------+-------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | project_id            | String                                                      | Specifies the project ID.                                                                           |
   +-----------------------+-------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | type                  | String                                                      | Specifies the flavor type. Values can be one of the following:                                      |
   |                       |                                                             |                                                                                                     |
   |                       |                                                             | -  **L4** indicates a Layer-4 flavor.                                                               |
   |                       |                                                             |                                                                                                     |
   |                       |                                                             | -  **L7** indicates a Layer-7 flavor.                                                               |
   |                       |                                                             |                                                                                                     |
   |                       |                                                             | Minimum: **1**                                                                                      |
   |                       |                                                             |                                                                                                     |
   |                       |                                                             | Maximum: **32**                                                                                     |
   +-----------------------+-------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | flavor_sold_out       | Boolean                                                     | Specifies whether the flavor is unavailable.                                                        |
   |                       |                                                             |                                                                                                     |
   |                       |                                                             | -  **true** indicates the flavor is unavailable. Load balancers with this flavor cannot be created. |
   |                       |                                                             |                                                                                                     |
   |                       |                                                             | -  **false** indicates the flavor is available. Load balancers with this flavor can be created.     |
   +-----------------------+-------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+

.. _listflavors__response_flavorinfo:

.. table:: **Table 6** FlavorInfo

   +------------+---------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter  | Type    | Description                                                                                                                                                                      |
   +============+=========+==================================================================================================================================================================================+
   | connection | Integer | Specifies the number of concurrent connections per second.                                                                                                                       |
   +------------+---------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | cps        | Integer | Specifies the number of new connections per second.                                                                                                                              |
   +------------+---------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | qps        | Integer | Specifies the number of requests per second. This parameter is available only for load balancers at Layer 7.                                                                     |
   +------------+---------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | bandwidth  | Integer | Specifies the bandwidth.                                                                                                                                                         |
   +------------+---------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | lcu        | Integer | Specifies the number of LCUs in the flavor. An LCU measures the dimensions on which a dedicated load balancer routes the traffic. The higher value indicates better perfromance. |
   +------------+---------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | https_cps  | Integer | Specifies the number of new HTTPS connections. This parameter is available only for load balancers at Layer 7.                                                                   |
   +------------+---------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _listflavors__response_pageinfo:

.. table:: **Table 7** PageInfo

   +-----------------+---------+----------------------------------------------------------------------+
   | Parameter       | Type    | Description                                                          |
   +=================+=========+======================================================================+
   | previous_marker | String  | Specifies the ID of the first record in the pagination query result. |
   +-----------------+---------+----------------------------------------------------------------------+
   | next_marker     | String  | Specifies the ID of the last record in the pagination query result.  |
   +-----------------+---------+----------------------------------------------------------------------+
   | current_count   | Integer | Specifies the number of records.                                     |
   +-----------------+---------+----------------------------------------------------------------------+

Example Requests
----------------

Querying load balancer flavors on each page

.. code-block:: text

   GET https://{ELB_Endpoint}/v3/057ef081eb00d2732fd1c01a9be75e6f/elb/flavors?limit=2&marker=179568ef-5ba4-4ca0-8c5e-5d581db779b1

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

   {
     "request_id" : "b36bff1e331f195a3b8934a490fbcbf0",
     "flavors" : [ {
       "shared" : true,
       "project_id" : "8d53f081ea24444aa95e2bfa942ef6ee",
       "info" : {
         "connection" : 20000000,
         "cps" : 400000,
         "lcu" : 400
       },
       "id" : "22f1ef4f-7be7-4d85-bd35-45344a18f63a",
       "name" : "L4_flavor.elb.s2.large",
       "type" : "L4",
       "flavor_sold_out" : false
     }, {
       "shared" : true,
       "project_id" : "8d53f081ea24444aa95e2bfa942ef6ee",
       "info" : {
         "bandwidth" : 50000,
         "connection" : 200000,
         "cps" : 2000,
         "https_cps" : 200,
         "lcu" : 10,
         "qps" : 4000
       },
       "id" : "2f124f60-980a-42f3-b201-35461df1b936",
       "name" : "L7_flavor.elb.s1.small",
       "type" : "L7",
       "flavor_sold_out" : false
     } ],
     "page_info" : {
       "next_marker" : "2f124f60-980a-42f3-b201-35461df1b936",
       "previous_marker" : "22f1ef4f-7be7-4d85-bd35-45344a18f63a",
       "current_count" : 2
     }
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
