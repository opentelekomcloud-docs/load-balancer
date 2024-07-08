:original_name: ListLogtanks.html

.. _ListLogtanks:

Querying Logs
=============

Function
--------

This API is used to query logs.

Constraints
-----------

This API has the following constraints:

-  Parameters **marker**, **limit**, and **page_reverse** are used for pagination query.

-  Parameters **marker** and **page_reverse** take effect only when they are used together with parameter **limit**.

URI
---

GET /v3/{project_id}/elb/logtanks

.. table:: **Table 1** Path Parameters

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
   ========== ========= ====== =========================

.. table:: **Table 2** Query Parameters

   +-----------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Mandatory       | Type            | Description                                                                                                                                         |
   +=======================+=================+=================+=====================================================================================================================================================+
   | limit                 | No              | Integer         | Specifies the number of records on each page.                                                                                                       |
   |                       |                 |                 |                                                                                                                                                     |
   |                       |                 |                 | Minimum: **0**                                                                                                                                      |
   |                       |                 |                 |                                                                                                                                                     |
   |                       |                 |                 | Maximum: **2000**                                                                                                                                   |
   |                       |                 |                 |                                                                                                                                                     |
   |                       |                 |                 | Default: **2000**                                                                                                                                   |
   +-----------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | marker                | No              | String          | Specifies the ID of the last record on the previous page.                                                                                           |
   |                       |                 |                 |                                                                                                                                                     |
   |                       |                 |                 | Note:                                                                                                                                               |
   |                       |                 |                 |                                                                                                                                                     |
   |                       |                 |                 | -  This parameter must be used together with **limit**.                                                                                             |
   |                       |                 |                 |                                                                                                                                                     |
   |                       |                 |                 | -  If this parameter is not specified, the first page will be queried.                                                                              |
   |                       |                 |                 |                                                                                                                                                     |
   |                       |                 |                 | -  This parameter cannot be left blank or set to an invalid ID.                                                                                     |
   +-----------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | page_reverse          | No              | Boolean         | Specifies whether to use reverse query. Values:                                                                                                     |
   |                       |                 |                 |                                                                                                                                                     |
   |                       |                 |                 | -  **true**: Query the previous page.                                                                                                               |
   |                       |                 |                 |                                                                                                                                                     |
   |                       |                 |                 | -  **false** (default): Query the next page.                                                                                                        |
   |                       |                 |                 |                                                                                                                                                     |
   |                       |                 |                 | Note:                                                                                                                                               |
   |                       |                 |                 |                                                                                                                                                     |
   |                       |                 |                 | -  This parameter must be used together with **limit**.                                                                                             |
   |                       |                 |                 |                                                                                                                                                     |
   |                       |                 |                 | -  If **page_reverse** is set to **true** and you want to query the previous page, set the value of **marker** to the value of **previous_marker**. |
   +-----------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | enterprise_project_id | No              | Array           | Specifies the enterprise project ID.                                                                                                                |
   |                       |                 |                 |                                                                                                                                                     |
   |                       |                 |                 | Multiple IDs can be queried in the format of *enterprise_project_id=xxx&enterprise_project_id=xxx*.                                                 |
   |                       |                 |                 |                                                                                                                                                     |
   |                       |                 |                 | This parameter is unsupported. Please do not use it.                                                                                                |
   +-----------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | id                    | No              | Array           | Specifies the ID of the log tank.                                                                                                                   |
   |                       |                 |                 |                                                                                                                                                     |
   |                       |                 |                 | Multiple IDs can be queried in the format of *id=xxx&id=xxx*.                                                                                       |
   +-----------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | loadbalancer_id       | No              | Array           | Specifies the ID of a load balancer.                                                                                                                |
   |                       |                 |                 |                                                                                                                                                     |
   |                       |                 |                 | Multiple IDs can be queried in the format of *loadbalancer_id=xxx&loadbalancer_id=xxx*.                                                             |
   +-----------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | log_group_id          | No              | Array           | Specifies the log group ID.                                                                                                                         |
   |                       |                 |                 |                                                                                                                                                     |
   |                       |                 |                 | Multiple IDs can be queried in the format of *log_group_id=xxx&log_group_id=xxx*.                                                                   |
   +-----------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | log_topic_id          | No              | Array           | Specifies the log topic ID.                                                                                                                         |
   |                       |                 |                 |                                                                                                                                                     |
   |                       |                 |                 | Multiple IDs can be queried in the format of *log_topic_id=xxx&log_topic_id=xxx*.                                                                   |
   +-----------------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+

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

   +------------+------------------------------------------------------------------+-----------------------------------------------------------------+
   | Parameter  | Type                                                             | Description                                                     |
   +============+==================================================================+=================================================================+
   | logtanks   | Array of :ref:`Logtank <listlogtanks__response_logtank>` objects | Provides supplementary information.                             |
   +------------+------------------------------------------------------------------+-----------------------------------------------------------------+
   | page_info  | :ref:`PageInfo <listlogtanks__response_pageinfo>` object         | Specifies pagination information about the load balancer.       |
   +------------+------------------------------------------------------------------+-----------------------------------------------------------------+
   | request_id | String                                                           | Specifies the request ID. The value is automatically generated. |
   +------------+------------------------------------------------------------------+-----------------------------------------------------------------+

.. _listlogtanks__response_logtank:

.. table:: **Table 5** Logtank

   =============== ====== ====================================
   Parameter       Type   Description
   =============== ====== ====================================
   id              String Specifies the log ID.
   project_id      String Specifies the ID of a load balancer.
   loadbalancer_id String Specifies the ID of a load balancer.
   log_group_id    String Specifies the log group ID.
   log_topic_id    String Specifies the log topic ID.
   =============== ====== ====================================

.. _listlogtanks__response_pageinfo:

.. table:: **Table 6** PageInfo

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

Querying logs of multiple load balancers

.. code-block:: text

   GET https://{ELB_Endpoint}/v3/060576798a80d5762fafc01a9b5eedc7/elb/logtanks?loadbalancer_id=995b98d7-6010-4502-a91a-756f399088f8&loadbalancer_id=37e9c3e3-08a2-48e9-acee-431159a33cc2

Example Responses
-----------------

**Status code: 200**

OK

.. code-block::

   {
     "request_id" : "5b43d31cd5217ffca57c2c4177e1b1ee",
     "logtanks" : [ {
       "project_id" : "060576798a80d5762fafc01a9b5eedc7",
       "log_topic_id" : "5b9b8370-a1fc-4c59-a509-483a673c8a94",
       "id" : "281e8768-94f9-45e9-9f3d-9fe2a122ad67",
       "log_group_id" : "7733882e-f7fa-4fb0-a460-0605c48a2280",
       "loadbalancer_id" : "995b98d7-6010-4502-a91a-756f399088f8"
     } ],
     "page_info" : {
       "next_marker" : "281e8768-94f9-45e9-9f3d-9fe2a122ad67",
       "previous_marker" : "281e8768-94f9-45e9-9f3d-9fe2a122ad67",
       "current_count" : 1
     }
   }

Status Codes
------------

=========== ===========
Status Code Description
=========== ===========
200         OK
=========== ===========

Error Codes
-----------

See :ref:`Error Codes <errorcode>`.
