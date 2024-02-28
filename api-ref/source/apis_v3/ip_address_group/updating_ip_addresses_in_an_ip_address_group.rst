:original_name: UpdateIpList.html

.. _UpdateIpList:

Updating IP Addresses in an IP Address Group
============================================

Function
--------

This API is used to update the IP addresses in an IP address group.

URI
---

POST /v3/{project_id}/elb/ipgroups/{ipgroup_id}/iplist/create-or-update

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

   +-----------+-----------+-----------------------------------------------------------------------------+---------------------------------------------------------------------------------------+
   | Parameter | Mandatory | Type                                                                        | Description                                                                           |
   +===========+===========+=============================================================================+=======================================================================================+
   | ipgroup   | No        | :ref:`UpdateIpListOption <updateiplist__request_updateiplistoption>` object | Specifies the request parameter for updating the IP addresses of an IP address group. |
   +-----------+-----------+-----------------------------------------------------------------------------+---------------------------------------------------------------------------------------+

.. _updateiplist__request_updateiplistoption:

.. table:: **Table 4** UpdateIpListOption

   +-------------+-----------+-----------------------------------------------------------------------------------------------+-----------------------------------------------------------------+
   | Parameter   | Mandatory | Type                                                                                          | Description                                                     |
   +=============+===========+===============================================================================================+=================================================================+
   | name        | No        | String                                                                                        | Specifies the name of the IP address group.                     |
   +-------------+-----------+-----------------------------------------------------------------------------------------------+-----------------------------------------------------------------+
   | ip_list     | No        | Array of :ref:`UpadateIpGroupIpOption <updateiplist__request_upadateipgroupipoption>` objects | Specifies the IP addresses in the IP address group.             |
   +-------------+-----------+-----------------------------------------------------------------------------------------------+-----------------------------------------------------------------+
   | description | No        | String                                                                                        | Specifies supplementary information about the IP address group. |
   +-------------+-----------+-----------------------------------------------------------------------------------------------+-----------------------------------------------------------------+

.. _updateiplist__request_upadateipgroupipoption:

.. table:: **Table 5** UpadateIpGroupIpOption

   +-----------------+-----------------+-----------------+-----------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                         |
   +=================+=================+=================+=====================================================+
   | ip              | Yes             | String          | Specifies the IP addresses in the IP address group. |
   +-----------------+-----------------+-----------------+-----------------------------------------------------+
   | description     | No              | String          | Provides remarks about the IP address group.        |
   |                 |                 |                 |                                                     |
   |                 |                 |                 | Minimum: **0**                                      |
   |                 |                 |                 |                                                     |
   |                 |                 |                 | Maximum: **255**                                    |
   +-----------------+-----------------+-----------------+-----------------------------------------------------+

Response Parameters
-------------------

**Status code: 200**

.. table:: **Table 6** Response body parameters

   +------------+--------------------------------------------------------+-----------------------------------------------------------------+
   | Parameter  | Type                                                   | Description                                                     |
   +============+========================================================+=================================================================+
   | ipgroup    | :ref:`IpGroup <updateiplist__response_ipgroup>` object | Shows IP address information.                                   |
   +------------+--------------------------------------------------------+-----------------------------------------------------------------+
   | request_id | String                                                 | Specifies the request ID. The value is automatically generated. |
   +------------+--------------------------------------------------------+-----------------------------------------------------------------+

.. _updateiplist__response_ipgroup:

.. table:: **Table 7** IpGroup

   +-----------------------+--------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | Parameter             | Type                                                                     | Description                                                                                         |
   +=======================+==========================================================================+=====================================================================================================+
   | created_at            | String                                                                   | Specifies the time when the IP address group was created.                                           |
   +-----------------------+--------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | description           | String                                                                   | Specifies the time when the IP address group was updated.                                           |
   +-----------------------+--------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | id                    | String                                                                   | Specifies the ID of the IP address group.                                                           |
   +-----------------------+--------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | ip_list               | Array of :ref:`IpInfo <updateiplist__response_ipinfo>` objects           | Specifies the IP addresses or CIDR blocks in the IP address group. **[]** indicates any IP address. |
   |                       |                                                                          |                                                                                                     |
   |                       |                                                                          | Array Length: **0 - 300**                                                                           |
   +-----------------------+--------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | listeners             | Array of :ref:`ListenerRef <updateiplist__response_listenerref>` objects | Lists the IDs of listeners with which the IP address group is associated.                           |
   +-----------------------+--------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | name                  | String                                                                   | Specifies the IP address group name.                                                                |
   +-----------------------+--------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | project_id            | String                                                                   | Specifies the project ID of the IP address group.                                                   |
   +-----------------------+--------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | updated_at            | String                                                                   | Specifies the time when the IP address group was updated.                                           |
   +-----------------------+--------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+

.. _updateiplist__response_ipinfo:

.. table:: **Table 8** IpInfo

   +-----------------------+-----------------------+-----------------------------------------------------+
   | Parameter             | Type                  | Description                                         |
   +=======================+=======================+=====================================================+
   | ip                    | String                | Specifies the IP addresses in the IP address group. |
   +-----------------------+-----------------------+-----------------------------------------------------+
   | description           | String                | Provides remarks about the IP address group.        |
   |                       |                       |                                                     |
   |                       |                       | Minimum: **0**                                      |
   |                       |                       |                                                     |
   |                       |                       | Maximum: **255**                                    |
   +-----------------------+-----------------------+-----------------------------------------------------+

.. _updateiplist__response_listenerref:

.. table:: **Table 9** ListenerRef

   ========= ====== ==========================
   Parameter Type   Description
   ========= ====== ==========================
   id        String Specifies the listener ID.
   ========= ====== ==========================

Example Requests
----------------

Updating IP addresses in an IP address group

.. code-block:: text

   POST https://{ELB_Endpoint}/v3/45977fa2dbd7482098dd68d0d8970117/elb/ipgroups/8722e0e0-9cc9-4490-9660-8c9a5732fbb0/iplist/create-or-update

   {
     "ipgroup" : {
       "name" : "test_ipg",
       "ip_list" : [ {
         "ip" : "192.168.1.123",
         "description" : "test"
       }, {
         "ip" : "192.168.1.120",
         "description" : "test update ip0"
       } ]
     }
   }

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

   {
     "request_id" : "46d0dcbec23987f1429491731dce0feb",
     "ipgroup" : {
       "id" : "353d6c3b-aca0-40b7-a059-fad8b20419e7",
       "name" : "test_ipg",
       "project_id" : "060576798a80d5762fafc01a9b5eedc7",
       "description" : "",
       "ip_list" : [ {
         "ip" : "192.168.1.120",
         "description" : "test update ip0"
       }, {
         "ip" : "192.168.1.122",
         "description" : "test update ip2"
       }, {
         "ip" : "192.168.1.123",
         "description" : "test"
       } ],
       "listeners" : [ {
         "id" : "acef0c4d-3bd5-4cd0-8d83-c53e5b1fd652"
       }, {
         "id" : "edb23879-5511-4412-8b7b-9574de7a1295"
       } ],
       "created_at" : "2021-11-29T10:40:30Z",
       "updated_at" : "2022-12-05T13:14:01Z"
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
