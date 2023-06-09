:original_name: ListIpGroups.html

.. _ListIpGroups:

Querying IP Address Groups
==========================

Function
--------

This API is used to query IP address groups.This function is not supported in **eu-nl** region. Please do not use it.

Constraints
-----------

This API has the following constraints:

-  Parameters **marker**, **limit**, and **page_reverse** are used for pagination query.

-  Parameters **marker** and **page_reverse** take effect only when they are used together with parameter **limit**.

URI
---

GET /v3/{project_id}/elb/ipgroups

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
   | id              | No              | Array           | Specifies the ID of the IP address group.                                                                                                           |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | name            | No              | Array           | Specifies the name of the IP address group.                                                                                                         |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | description     | No              | Array           | Provides supplementary information about the IP address group.                                                                                      |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | ip_list         | No              | Array           | Lists the IP addresses in the IP address group. Multiple IP addresses are separated with commas.                                                    |
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

   +------------+------------------------------------------------------------------+-----------------------------------------------------------------+
   | Parameter  | Type                                                             | Description                                                     |
   +============+==================================================================+=================================================================+
   | ipgroups   | Array of :ref:`IpGroup <listipgroups__response_ipgroup>` objects | Lists the returned IP address groups.                           |
   +------------+------------------------------------------------------------------+-----------------------------------------------------------------+
   | request_id | String                                                           | Specifies the request ID. The value is automatically generated. |
   +------------+------------------------------------------------------------------+-----------------------------------------------------------------+
   | page_info  | :ref:`PageInfo <listipgroups__response_pageinfo>` object         | Shows pagination information.                                   |
   +------------+------------------------------------------------------------------+-----------------------------------------------------------------+

.. _listipgroups__response_ipgroup:

.. table:: **Table 5** IpGroup

   +-------------+--------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | Parameter   | Type                                                                     | Description                                                                                         |
   +=============+==========================================================================+=====================================================================================================+
   | created_at  | String                                                                   | Specifies the time when the IP address group was created.                                           |
   +-------------+--------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | description | String                                                                   | Specifies the time when the IP address group was updated.                                           |
   +-------------+--------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | id          | String                                                                   | Specifies the ID of the IP address group.                                                           |
   +-------------+--------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | ip_list     | Array of :ref:`IpInfo <listipgroups__response_ipinfo>` objects           | Specifies the IP addresses or CIDR blocks in the IP address group. **[]** indicates any IP address. |
   +-------------+--------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | listeners   | Array of :ref:`ListenerRef <listipgroups__response_listenerref>` objects | Lists the IDs of listeners with which the IP address group is associated.                           |
   +-------------+--------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | name        | String                                                                   | Specifies the IP address group name.                                                                |
   +-------------+--------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | project_id  | String                                                                   | Specifies the project ID of the IP address group.                                                   |
   +-------------+--------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | updated_at  | String                                                                   | Specifies the time when the IP address group was updated.                                           |
   +-------------+--------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+

.. _listipgroups__response_ipinfo:

.. table:: **Table 6** IpInfo

   +-----------------------+-----------------------+----------------------------------------------------------+
   | Parameter             | Type                  | Description                                              |
   +=======================+=======================+==========================================================+
   | ip                    | String                | Specifies the IP addresses in the IP address group.      |
   |                       |                       |                                                          |
   |                       |                       | IPv6 is unsupported. Please do not enter IPv6 addresses. |
   +-----------------------+-----------------------+----------------------------------------------------------+
   | description           | String                | Provides remarks about the IP address group.             |
   |                       |                       |                                                          |
   |                       |                       | Minimum: **0**                                           |
   |                       |                       |                                                          |
   |                       |                       | Maximum: **255**                                         |
   +-----------------------+-----------------------+----------------------------------------------------------+

.. _listipgroups__response_listenerref:

.. table:: **Table 7** ListenerRef

   ========= ====== ==========================
   Parameter Type   Description
   ========= ====== ==========================
   id        String Specifies the listener ID.
   ========= ====== ==========================

.. _listipgroups__response_pageinfo:

.. table:: **Table 8** PageInfo

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

Querying IP address groups on each page

.. code-block:: text

   GET https://{ELB_Endpoint}/v3/45977fa2dbd7482098dd68d0d8970117/elb/ipgroups?limit=1

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

   {
     "ipgroups" : [ {
       "description" : "",
       "id" : "8722e0e0-9cc9-4490-9660-8c9a5732fbb0",
       "name" : "test_ipg",
       "project_id" : "45977fa2dbd7482098dd68d0d8970117",
       "ip_list" : [ {
         "ip" : "192.168.1.123",
         "description" : ""
       }, {
         "ip" : "192.168.3.0/24",
         "description" : "test_ip"
       } ],
       "listeners" : [ {
         "id" : "88f9c079-29cb-435a-b98f-0c5c0b90c2bd"
       }, {
         "id" : "2f4c9644-d5d2-4cf8-a3c0-944239a4f58c"
       } ],
       "created_at" : "2018-01-16T03:19:16",
       "updated_at" : "2018-01-16T03:19:16"
     } ],
     "page_info" : {
       "previous_marker" : "1d321f77-bc7b-45d3-9cfe-d7c0b65a3620",
       "current_count" : 1
     },
     "request_id" : "8d9f423c-8766-4b6a-9952-275a88ac1ce3"
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
