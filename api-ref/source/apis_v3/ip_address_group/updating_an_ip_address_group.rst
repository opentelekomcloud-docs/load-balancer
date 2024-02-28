:original_name: UpdateIpGroup.html

.. _UpdateIpGroup:

Updating an IP Address Group
============================

Function
--------

This API is used to update an IP address group. All IP addresses in the IP address group will be overwritten, and the IP addresses that are not included in the **ip_list** parameter in the request body will be removed. The IP address can contain IP addresses or CIDR blocks. 0.0.0.0 will be considered the same as 0.0.0.0/32. If you enter both 0.0.0.0 and 0.0.0.0/32, only one will be kept. 0:0:0:0:0:0:0:1 will be considered the same as ::1 and ::1/128. If you enter 0:0:0:0:0:0:0:1, ::1 and ::1/128, only one will be kept.

URI
---

PUT /v3/{project_id}/elb/ipgroups/{ipgroup_id}

.. table:: **Table 1** Path Parameters

   ========== ========= ====== =========================================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================================
   ipgroup_id Yes       String Specifies the ID of the IP address group.
   project_id Yes       String Specifies the project ID.
   ========== ========= ====== =========================================

Request Parameters
------------------

.. table:: **Table 2** Request header parameters

   +--------------+-----------+--------+--------------------------------------------------+
   | Parameter    | Mandatory | Type   | Description                                      |
   +==============+===========+========+==================================================+
   | X-Auth-Token | Yes       | String | Specifies the token used for IAM authentication. |
   +--------------+-----------+--------+--------------------------------------------------+

.. table:: **Table 3** Request body parameters

   +-----------+-----------+--------------------------------------------------------------------------------+---------------------------------+
   | Parameter | Mandatory | Type                                                                           | Description                     |
   +===========+===========+================================================================================+=================================+
   | ipgroup   | Yes       | :ref:`UpdateIpGroupOption <updateipgroup__request_updateipgroupoption>` object | Specifies the IP address group. |
   +-----------+-----------+--------------------------------------------------------------------------------+---------------------------------+

.. _updateipgroup__request_updateipgroupoption:

.. table:: **Table 4** UpdateIpGroupOption

   +-----------------+-----------------+------------------------------------------------------------------------------------------------+----------------------------------------------------------------+
   | Parameter       | Mandatory       | Type                                                                                           | Description                                                    |
   +=================+=================+================================================================================================+================================================================+
   | description     | No              | String                                                                                         | Provides supplementary information about the IP address group. |
   |                 |                 |                                                                                                |                                                                |
   |                 |                 |                                                                                                | Minimum: **0**                                                 |
   |                 |                 |                                                                                                |                                                                |
   |                 |                 |                                                                                                | Maximum: **255**                                               |
   +-----------------+-----------------+------------------------------------------------------------------------------------------------+----------------------------------------------------------------+
   | name            | No              | String                                                                                         | Specifies the IP address group name.                           |
   |                 |                 |                                                                                                |                                                                |
   |                 |                 |                                                                                                | Minimum: **0**                                                 |
   |                 |                 |                                                                                                |                                                                |
   |                 |                 |                                                                                                | Maximum: **255**                                               |
   +-----------------+-----------------+------------------------------------------------------------------------------------------------+----------------------------------------------------------------+
   | ip_list         | No              | Array of :ref:`UpadateIpGroupIpOption <updateipgroup__request_upadateipgroupipoption>` objects | Lists the IP addresses in the IP address group.                |
   |                 |                 |                                                                                                |                                                                |
   |                 |                 |                                                                                                | Array Length: **0 - 300**                                      |
   +-----------------+-----------------+------------------------------------------------------------------------------------------------+----------------------------------------------------------------+

.. _updateipgroup__request_upadateipgroupipoption:

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

   +------------+---------------------------------------------------------+-----------------------------------------------------------------+
   | Parameter  | Type                                                    | Description                                                     |
   +============+=========================================================+=================================================================+
   | ipgroup    | :ref:`IpGroup <updateipgroup__response_ipgroup>` object | Specifies the IP address group.                                 |
   +------------+---------------------------------------------------------+-----------------------------------------------------------------+
   | request_id | String                                                  | Specifies the request ID. The value is automatically generated. |
   +------------+---------------------------------------------------------+-----------------------------------------------------------------+

.. _updateipgroup__response_ipgroup:

.. table:: **Table 7** IpGroup

   +-----------------------+---------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | Parameter             | Type                                                                      | Description                                                                                         |
   +=======================+===========================================================================+=====================================================================================================+
   | created_at            | String                                                                    | Specifies the time when the IP address group was created.                                           |
   +-----------------------+---------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | description           | String                                                                    | Specifies the time when the IP address group was updated.                                           |
   +-----------------------+---------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | id                    | String                                                                    | Specifies the ID of the IP address group.                                                           |
   +-----------------------+---------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | ip_list               | Array of :ref:`IpInfo <updateipgroup__response_ipinfo>` objects           | Specifies the IP addresses or CIDR blocks in the IP address group. **[]** indicates any IP address. |
   |                       |                                                                           |                                                                                                     |
   |                       |                                                                           | Array Length: **0 - 300**                                                                           |
   +-----------------------+---------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | listeners             | Array of :ref:`ListenerRef <updateipgroup__response_listenerref>` objects | Lists the IDs of listeners with which the IP address group is associated.                           |
   +-----------------------+---------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | name                  | String                                                                    | Specifies the IP address group name.                                                                |
   +-----------------------+---------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | project_id            | String                                                                    | Specifies the project ID of the IP address group.                                                   |
   +-----------------------+---------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+
   | updated_at            | String                                                                    | Specifies the time when the IP address group was updated.                                           |
   +-----------------------+---------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------+

.. _updateipgroup__response_ipinfo:

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

.. _updateipgroup__response_listenerref:

.. table:: **Table 9** ListenerRef

   ========= ====== ==========================
   Parameter Type   Description
   ========= ====== ==========================
   id        String Specifies the listener ID.
   ========= ====== ==========================

Example Requests
----------------

Updating an IP address group

.. code-block:: text

   PUT https://{ELB_Endpoint}/v3/45977fa2dbd7482098dd68d0d8970117/elb/ipgroups/8722e0e0-9cc9-4490-9660-8c9a5732fbb0

   {
     "ipgroup" : {
       "name" : "test_ipg",
       "ip_list" : [ {
         "ip" : "192.168.1.123"
       }, {
         "ip" : "192.168.3.0/24",
         "description" : "test_ip"
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
