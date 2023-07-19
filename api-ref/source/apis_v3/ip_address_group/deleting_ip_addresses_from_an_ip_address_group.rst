:original_name: BatchDeleteIpList.html

.. _BatchDeleteIpList:

Deleting IP Addresses from an IP Address Group
==============================================

Function
--------

This API is used to delete IP addresses from an IP address group.

URI
---

POST /v3/{project_id}/elb/ipgroups/{ipgroup_id}/iplist/batch-delete

.. table:: **Table 1** Path Parameters

   ========== ========= ====== =========================================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================================
   project_id Yes       String Specifies the project ID.
   ipgroup_id Yes       String Specifies the ID of the IP address group.
   ========== ========= ====== =========================================

Request Parameters
------------------

.. table:: **Table 2** Request header parameters

   +--------------+-----------+--------+--------------------------------------------------+
   | Parameter    | Mandatory | Type   | Description                                      |
   +==============+===========+========+==================================================+
   | X-Auth-Token | No        | String | Specifies the token used for IAM authentication. |
   +--------------+-----------+--------+--------------------------------------------------+

.. table:: **Table 3** Request body parameters

   +-----------+-----------+--------------------------------------------------------------------------------------------+----------------------------------------------------------------------------------+
   | Parameter | Mandatory | Type                                                                                       | Description                                                                      |
   +===========+===========+============================================================================================+==================================================================================+
   | ipgroup   | No        | :ref:`BatchDeleteIpListOption <batchdeleteiplist__request_batchdeleteiplistoption>` object | Specifies IP addresses that will be deleted from an IP address group in batches. |
   +-----------+-----------+--------------------------------------------------------------------------------------------+----------------------------------------------------------------------------------+

.. _batchdeleteiplist__request_batchdeleteiplistoption:

.. table:: **Table 4** BatchDeleteIpListOption

   +-----------+-----------+--------------------------------------------------------------------------+-------------------------+
   | Parameter | Mandatory | Type                                                                     | Description             |
   +===========+===========+==========================================================================+=========================+
   | ip_list   | No        | Array of :ref:`IpGroupIp <batchdeleteiplist__request_ipgroupip>` objects | Specifies IP addresses. |
   +-----------+-----------+--------------------------------------------------------------------------+-------------------------+

.. _batchdeleteiplist__request_ipgroupip:

.. table:: **Table 5** IpGroupIp

   ========= ========= ====== ============================================
   Parameter Mandatory Type   Description
   ========= ========= ====== ============================================
   ip        Yes       String Specifies an IP address or IP address range.
   ========= ========= ====== ============================================

Response Parameters
-------------------

**Status code: 200**

.. table:: **Table 6** Response body parameters

   +------------+-------------------------------------------------------------+-----------------------------------------------------------------+
   | Parameter  | Type                                                        | Description                                                     |
   +============+=============================================================+=================================================================+
   | ipgroup    | :ref:`IpGroup <batchdeleteiplist__response_ipgroup>` object | Shows IP address information.                                   |
   +------------+-------------------------------------------------------------+-----------------------------------------------------------------+
   | request_id | String                                                      | Specifies the request ID. The value is automatically generated. |
   +------------+-------------------------------------------------------------+-----------------------------------------------------------------+

.. _batchdeleteiplist__response_ipgroup:

.. table:: **Table 7** IpGroup

   +-------------+-------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | Parameter   | Type                                                                          | Description                                                                                         |
   +=============+===============================================================================+=====================================================================================================+
   | created_at  | String                                                                        | Specifies the time when the IP address group was created.                                           |
   +-------------+-------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | description | String                                                                        | Specifies the time when the IP address group was updated.                                           |
   +-------------+-------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | id          | String                                                                        | Specifies the ID of the IP address group.                                                           |
   +-------------+-------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | ip_list     | Array of :ref:`IpInfo <batchdeleteiplist__response_ipinfo>` objects           | Specifies the IP addresses or CIDR blocks in the IP address group. **[]** indicates any IP address. |
   +-------------+-------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | listeners   | Array of :ref:`ListenerRef <batchdeleteiplist__response_listenerref>` objects | Lists the IDs of listeners with which the IP address group is associated.                           |
   +-------------+-------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | name        | String                                                                        | Specifies the IP address group name.                                                                |
   +-------------+-------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | project_id  | String                                                                        | Specifies the project ID of the IP address group.                                                   |
   +-------------+-------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | updated_at  | String                                                                        | Specifies the time when the IP address group was updated.                                           |
   +-------------+-------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+

.. _batchdeleteiplist__response_ipinfo:

.. table:: **Table 8** IpInfo

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

.. _batchdeleteiplist__response_listenerref:

.. table:: **Table 9** ListenerRef

   ========= ====== ==========================
   Parameter Type   Description
   ========= ====== ==========================
   id        String Specifies the listener ID.
   ========= ====== ==========================

Example Requests
----------------

Deleting IP addresses from an IP address group

.. code-block:: text

   POST https://{ELB_Endpoint}/v3/45977fa2dbd7482098dd68d0d8970117/elb/ipgroups/8722e0e0-9cc9-4490-9660-8c9a5732fbb0/iplist/batch-delete

   {
     "ipgroup" : {
       "ip_list" : [ {
         "ip" : "192.168.1.123"
       }, {
         "ip" : "192.168.3.0/24"
       } ]
     }
   }

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

   {
     "ipgroup" : {
       "description" : "",
       "id" : "8722e0e0-9cc9-4490-9660-8c9a5732fbb0",
       "name" : "test_ipg",
       "project_id" : "45977fa2dbd7482098dd68d0d8970117",
       "ip_list" : [ {
         "ip" : "192.168.1.122",
         "description" : ""
       } ],
       "listeners" : [ {
         "id" : "88f9c079-29cb-435a-b98f-0c5c0b90c2bd"
       }, {
         "id" : "2f4c9644-d5d2-4cf8-a3c0-944239a4f58c"
       } ],
       "created_at" : "2018-01-16T03:19:16",
       "updated_at" : "2018-01-16T03:19:16"
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
