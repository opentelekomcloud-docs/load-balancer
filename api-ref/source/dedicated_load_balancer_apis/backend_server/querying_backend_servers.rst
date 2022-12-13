:original_name: ListMembers.html

.. _ListMembers:

Querying Backend Servers
========================

Function
--------

This API is used to query all backend servers.

Constraints
-----------

Parameters **marker**, **limit**, and **page_reverse** are used for pagination query.

Parameters **marker** and **page_reverse** take effect only when they are used together with parameter **limit**.

URI
---

GET /v3/{project_id}/elb/pools/{pool_id}/members

.. table:: **Table 1** Path Parameters

   +------------+-----------+--------+-----------------------------------------------+
   | Parameter  | Mandatory | Type   | Description                                   |
   +============+===========+========+===============================================+
   | project_id | Yes       | String | Specifies the project ID.                     |
   +------------+-----------+--------+-----------------------------------------------+
   | pool_id    | Yes       | String | Specifies the ID of the backend server group. |
   +------------+-----------+--------+-----------------------------------------------+

.. table:: **Table 2** Query Parameters

   +-----------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Mandatory       | Type            | Description                                                                                                                                                                                                                                                             |
   +=======================+=================+=================+=========================================================================================================================================================================================================================================================================+
   | marker                | No              | String          | Specifies the ID of the last record on the previous page.                                                                                                                                                                                                               |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | Note:                                                                                                                                                                                                                                                                   |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | -  This parameter must be used together with **limit**.                                                                                                                                                                                                                 |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | -  If this parameter is not specified, the first page will be queried.                                                                                                                                                                                                  |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | -  This parameter cannot be left blank or set to an invalid ID.                                                                                                                                                                                                         |
   +-----------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | limit                 | No              | Integer         | Specifies the number of records on each page.                                                                                                                                                                                                                           |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | Minimum: **0**                                                                                                                                                                                                                                                          |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | Maximum: **2000**                                                                                                                                                                                                                                                       |
   +-----------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | page_reverse          | No              | Boolean         | Specifies the page direction.                                                                                                                                                                                                                                           |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | The value can be **true** or **false**, and the default value is **false**.                                                                                                                                                                                             |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | The last page in the list requested with **page_reverse** set to **false** will not contain the "next" link, and the last page in the list requested with **page_reverse** set to **true** will not contain the "previous" link.                                        |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | This parameter must be used together with **limit**.                                                                                                                                                                                                                    |
   +-----------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | No              | Array           | Specifies the backend server name.                                                                                                                                                                                                                                      |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | Multiple names can be queried in the format of *name=xxx&name=xxx*.                                                                                                                                                                                                     |
   +-----------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | weight                | No              | Array           | Specifies the weight of the backend server.                                                                                                                                                                                                                             |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | Requests are routed to backend servers in the same backend server group based on their weights. If the weight is 0, the backend server will not accept new requests.                                                                                                    |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | This parameter will not take effect when **lb_algorithm** is set to **SOURCE_IP** for the backend server group that contains the backend server.                                                                                                                        |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | Multiple weights can be queried in the format of *weight=xxx&weight=xxx*.                                                                                                                                                                                               |
   +-----------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up        | No              | Boolean         | Specifies the administrative status of the backend server.                                                                                                                                                                                                              |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | Although this parameter can be used in the APIs for creating and updating backend servers, its actual value depends on whether cloud servers that serve as the backend servers exist. If cloud servers exist, the value is **true**. Otherwise, the value is **false**. |
   +-----------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | subnet_cidr_id        | No              | Array           | Specifies the ID of the subnet where the backend server works.                                                                                                                                                                                                          |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | This subnet must be in the same VPC as the subnet of the load balancer with which the backend server is associated. Only IPv4 subnets are supported.                                                                                                                    |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | Multiple IDs can be queried in the format of *subnet_cidr_id=xxx&subnet_cidr_id=xxx*.                                                                                                                                                                                   |
   +-----------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | address               | No              | Array           | Specifies the IP address bound to the backend server.                                                                                                                                                                                                                   |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | -  The IP address must be in the subnet specified by **subnet_cidr_id**, for example, 192.168.3.11.                                                                                                                                                                     |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | -  The IP address can be used only by the primary NIC.                                                                                                                                                                                                                  |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | Multiple IP addresses can be queried in the format of *address=xxx&address=xxx*.                                                                                                                                                                                        |
   +-----------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | protocol_port         | No              | Array           | Specifies the port used by the backend server.                                                                                                                                                                                                                          |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | Multiple ports can be queried in the format of *protocol_port=xxx&protocol_port=xxx*.                                                                                                                                                                                   |
   +-----------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | id                    | No              | Array           | Specifies the backend server ID.                                                                                                                                                                                                                                        |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | Multiple IDs can be queried in the format of *id=xxx&id=xxx*.                                                                                                                                                                                                           |
   +-----------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | operating_status      | No              | Array           | Specifies the operating status of the backend server. The value can be one of the following:                                                                                                                                                                            |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | -  **ONLINE**: The backend server is running normally.                                                                                                                                                                                                                  |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | -  **NO_MONITOR**: No health check is configured for the backend server group to which the backend server belongs.                                                                                                                                                      |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | -  **OFFLINE**: The cloud server used as the backend server is stopped or does not exist.                                                                                                                                                                               |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | Multiple operating statuses can be queried in the format of *operating_status=xxx&operating_status=xxx*.                                                                                                                                                                |
   +-----------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | enterprise_project_id | No              | Array           | Specifies the enterprise project ID.                                                                                                                                                                                                                                    |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | -  If this parameter is not passed, resources in the default enterprise project are queried, and authentication is performed based on the default enterprise project.                                                                                                   |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | -  If this parameter is passed, its value can be the ID of an existing enterprise project or **all_granted_eps**.                                                                                                                                                       |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | If the value is a specific ID, resources in the specific enterprise project are required. If the value is **all_granted_eps**, resources in all enterprise projects are queried.                                                                                        |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | Multiple IDs can be queried in the format of *enterprise_project_id=xxx&enterprise_project_id=xxx*.                                                                                                                                                                     |
   |                       |                 |                 |                                                                                                                                                                                                                                                                         |
   |                       |                 |                 | This parameter is unsupported. Please do not use it.                                                                                                                                                                                                                    |
   +-----------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | ip_version            | No              | String          | Specifies the IP version. The value can be **4** (IPv4) or **6** (IPv6).                                                                                                                                                                                                |
   +-----------------------+-----------------+-----------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

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
   | request_id | String                                                        | Specifies the request ID. The value is automatically generated. |
   +------------+---------------------------------------------------------------+-----------------------------------------------------------------+
   | page_info  | :ref:`PageInfo <listmembers__response_pageinfo>` object       | Shows pagination information.                                   |
   +------------+---------------------------------------------------------------+-----------------------------------------------------------------+
   | members    | Array of :ref:`Member <listmembers__response_member>` objects | Lists the backend servers.                                      |
   +------------+---------------------------------------------------------------+-----------------------------------------------------------------+

.. _listmembers__response_pageinfo:

.. table:: **Table 5** PageInfo

   +-----------------+---------+------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Type    | Description                                                                                                                              |
   +=================+=========+==========================================================================================================================================+
   | previous_marker | String  | Specifies the ID of the first record in the pagination query result. This parameter will not be returned if no query result is returned. |
   +-----------------+---------+------------------------------------------------------------------------------------------------------------------------------------------+
   | next_marker     | String  | Marks the start record on the next page in the pagination query result. This parameter will not be returned if there is no next page.    |
   +-----------------+---------+------------------------------------------------------------------------------------------------------------------------------------------+
   | current_count   | Integer | Specifies the number of records.                                                                                                         |
   +-----------------+---------+------------------------------------------------------------------------------------------------------------------------------------------+

.. _listmembers__response_member:

.. table:: **Table 6** Member

   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                                                                                                                                                             |
   +=======================+=======================+=========================================================================================================================================================================================================================================================================================+
   | address               | String                | Specifies the IP address of the backend server.                                                                                                                                                                                                                                         |
   |                       |                       |                                                                                                                                                                                                                                                                                         |
   |                       |                       | The IP address must be in the subnet specified by **subnet_cidr_id**, for example, 192.168.3.11. The IP address can only be the IP address of the primary NIC.                                                                                                                          |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up        | Boolean               | Specifies the administrative status of the backend server.                                                                                                                                                                                                                              |
   |                       |                       |                                                                                                                                                                                                                                                                                         |
   |                       |                       | Although this parameter can be used in the APIs for creating and updating backend servers, its actual value depends on whether cloud servers exist. If cloud servers exist, the value is **true**. Otherwise, the value is **false**.                                                   |
   |                       |                       |                                                                                                                                                                                                                                                                                         |
   |                       |                       | Default: **true**                                                                                                                                                                                                                                                                       |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | id                    | String                | Specifies the backend server ID.                                                                                                                                                                                                                                                        |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                | Specifies the backend server name.                                                                                                                                                                                                                                                      |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | operating_status      | String                | Specifies the operating status of the backend server. The value can be one of the following:                                                                                                                                                                                            |
   |                       |                       |                                                                                                                                                                                                                                                                                         |
   |                       |                       | -  **ONLINE**: The backend server is running normally.                                                                                                                                                                                                                                  |
   |                       |                       |                                                                                                                                                                                                                                                                                         |
   |                       |                       | -  **NO_MONITOR**: No health check is configured for the backend server group to which the backend server belongs.                                                                                                                                                                      |
   |                       |                       |                                                                                                                                                                                                                                                                                         |
   |                       |                       | -  **OFFLINE**: The cloud server used as the backend server is stopped or does not exist.                                                                                                                                                                                               |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | project_id            | String                | Specifies the project ID.                                                                                                                                                                                                                                                               |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | protocol_port         | Integer               | Specifies the port used by the backend server to receive requests.                                                                                                                                                                                                                      |
   |                       |                       |                                                                                                                                                                                                                                                                                         |
   |                       |                       | Minimum: **1**                                                                                                                                                                                                                                                                          |
   |                       |                       |                                                                                                                                                                                                                                                                                         |
   |                       |                       | Maximum: **65535**                                                                                                                                                                                                                                                                      |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | subnet_cidr_id        | String                | Specifies the ID of the subnet where the backend server works. This subnet must be in the VPC as the subnet of the load balancer associated with the backend server. Only IPv4 subnets are supported. If the value is left blank, the backend server is not in the load balancer's VPC. |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | weight                | Integer               | Specifies the weight of the backend server.                                                                                                                                                                                                                                             |
   |                       |                       |                                                                                                                                                                                                                                                                                         |
   |                       |                       | Requests are routed to backend servers in the same backend server group based on their weights.                                                                                                                                                                                         |
   |                       |                       |                                                                                                                                                                                                                                                                                         |
   |                       |                       | If the weight is 0, the backend server will not accept new requests.                                                                                                                                                                                                                    |
   |                       |                       |                                                                                                                                                                                                                                                                                         |
   |                       |                       | This parameter is invalid when **lb_algorithm** is set to **SOURCE_IP** for the backend server group that contains the backend server.                                                                                                                                                  |
   |                       |                       |                                                                                                                                                                                                                                                                                         |
   |                       |                       | Minimum: **0**                                                                                                                                                                                                                                                                          |
   |                       |                       |                                                                                                                                                                                                                                                                                         |
   |                       |                       | Maximum: **100**                                                                                                                                                                                                                                                                        |
   |                       |                       |                                                                                                                                                                                                                                                                                         |
   |                       |                       | Default: **1**                                                                                                                                                                                                                                                                          |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | ip_version            | String                | This is a read-only attribute, which is automatically generated based on the **address** parameter. The value can be **v4** or **v6**.                                                                                                                                                  |
   |                       |                       |                                                                                                                                                                                                                                                                                         |
   |                       |                       | Default: **v4**                                                                                                                                                                                                                                                                         |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Example Requests
----------------

.. code-block:: text

   GET

   https://{elb_endpoint}/v3/{project_id}/elb/pools/36ce7086-a496-4666-9064-5ba0e6840c75/members

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

   {
     "members" : [ {
       "name" : "quark-neutron",
       "weight" : 100,
       "admin_state_up" : false,
       "subnet_cidr_id" : "c09f620e-3492-4429-ac15-445d5dd9ca74",
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "address" : "120.10.10.2",
       "protocol_port" : 2100,
       "id" : "0aa23a52-1ac2-4a2d-8dfa-1e11cb26079d",
       "operating_status" : "NO_MONITOR",
       "ip_version" : "v4"
     }, {
       "name" : "quark-neutron",
       "weight" : 100,
       "admin_state_up" : false,
       "subnet_cidr_id" : "c09f620e-3492-4429-ac15-445d5dd9ca74",
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "address" : "120.10.10.2",
       "protocol_port" : 2101,
       "id" : "315b928b-39e4-4d5f-8e48-39e9108c1035",
       "operating_status" : "NO_MONITOR",
       "ip_version" : "v4"
     }, {
       "name" : "quark-neutron",
       "weight" : 100,
       "admin_state_up" : false,
       "subnet_cidr_id" : "27e4ab69-a5ed-46c6-921a-5212be19ce87",
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "address" : "2001:db8:a583:6a::4",
       "protocol_port" : 2101,
       "id" : "53976f72-d2aa-47f5-baf4-4906ed6b42d6",
       "operating_status" : "NO_MONITOR",
       "ip_version" : "v6"
     } ],
     "page_info" : {
       "previous_marker" : "0aa23a52-1ac2-4a2d-8dfa-1e11cb26079d",
       "current_count" : 3
     },
     "request_id" : "87e29592-7ab8-401a-9bf4-66cf6747eab9"
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
