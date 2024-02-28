:original_name: ListMembers.html

.. _ListMembers:

Querying Backend Servers
========================

Function
--------

This API is used to query all backend servers.

Constraints
-----------

This API has the following constraints:

-  Parameters **marker**, **limit**, and **page_reverse** are used for pagination query.

-  Parameters **marker** and **page_reverse** take effect only when they are used together with parameter **limit**.

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

   +-----------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Mandatory       | Type            | Description                                                                                                                                                                                                                           |
   +=======================+=================+=================+=======================================================================================================================================================================================================================================+
   | marker                | No              | String          | Specifies the ID of the last record on the previous page.                                                                                                                                                                             |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | Note:                                                                                                                                                                                                                                 |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | -  This parameter must be used together with **limit**.                                                                                                                                                                               |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | -  If this parameter is not specified, the first page will be queried.                                                                                                                                                                |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | -  This parameter cannot be left blank or set to an invalid ID.                                                                                                                                                                       |
   +-----------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | limit                 | No              | Integer         | Specifies the number of records on each page.                                                                                                                                                                                         |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | Minimum: **0**                                                                                                                                                                                                                        |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | Maximum: **2000**                                                                                                                                                                                                                     |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | Default: **2000**                                                                                                                                                                                                                     |
   +-----------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | page_reverse          | No              | Boolean         | Specifies whether to use reverse query. Values:                                                                                                                                                                                       |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | -  **true**: Query the previous page.                                                                                                                                                                                                 |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | -  **false** (default): Query the next page.                                                                                                                                                                                          |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | Note:                                                                                                                                                                                                                                 |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | -  This parameter must be used together with **limit**.                                                                                                                                                                               |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | -  If **page_reverse** is set to **true** and you want to query the previous page, set the value of **marker** to the value of **previous_marker**.                                                                                   |
   +-----------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | No              | Array           | Specifies the backend server name.                                                                                                                                                                                                    |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | Multiple names can be queried in the format of *name=xxx&name=xxx*.                                                                                                                                                                   |
   +-----------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | weight                | No              | Array           | Specifies the weight of the backend server. Requests are routed to backend servers in the same backend server group based on their weights.                                                                                           |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | The value ranges from **0** to **100**. The larger the weight is, the higher proportion of requests the backend server receives. If the weight is set to 0, the backend server will not accept new requests.                          |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | Multiple weights can be queried in the format of *weight=xxx&weight=xxx*.                                                                                                                                                             |
   +-----------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up        | No              | Boolean         | Specifies the administrative status of the backend server. The value can be **true** or **false**.                                                                                                                                    |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | Although this parameter can be used in the APIs for creating and updating backend servers, its actual value depends on whether cloud servers exist. If cloud servers exist, the value is **true**. Otherwise, the value is **false**. |
   +-----------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | subnet_cidr_id        | No              | Array           | Specifies the ID of the IPv4 or IPv6 subnet where the backend server resides.                                                                                                                                                         |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | Multiple IDs can be queried in the format of *subnet_cidr_id=xxx&subnet_cidr_id=xxx*.                                                                                                                                                 |
   +-----------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | address               | No              | Array           | Specifies the IP address bound to the backend server.                                                                                                                                                                                 |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | Multiple IP addresses can be queried in the format of *address=xxx&address=xxx*.                                                                                                                                                      |
   +-----------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | protocol_port         | No              | Array           | Specifies the port used by the backend server to receive requests.                                                                                                                                                                    |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | Multiple ports can be queried in the format of *protocol_port=xxx&protocol_port=xxx*.                                                                                                                                                 |
   +-----------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | id                    | No              | Array           | Specifies the backend server ID.                                                                                                                                                                                                      |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | Multiple IDs can be queried in the format of *id=xxx&id=xxx*.                                                                                                                                                                         |
   +-----------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | operating_status      | No              | Array           | Specifies the health status of the backend server. The value can be one of the following:                                                                                                                                             |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | -  **ONLINE**: The backend server is running normally.                                                                                                                                                                                |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | -  **NO_MONITOR**: No health check is configured for the backend server group to which the backend server belongs.                                                                                                                    |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | -  **OFFLINE**: The cloud server used as the backend server is stopped or does not exist.                                                                                                                                             |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | Multiple operating statuses can be queried in the format of *operating_status=xxx&operating_status=xxx*.                                                                                                                              |
   +-----------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | enterprise_project_id | No              | Array           | Specifies the enterprise project ID.                                                                                                                                                                                                  |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | -  If this parameter is not passed, resources in the default enterprise project are queried, and authentication is performed based on the default enterprise project.                                                                 |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | -  If this parameter is passed, its value can be the ID of an existing enterprise project (resources in the specific enterprise project are required) or **all_granted_eps** (resources in all enterprise projects are queried).      |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | Multiple IDs can be queried in the format of *enterprise_project_id=xxx&enterprise_project_id=xxx*.                                                                                                                                   |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | This parameter is unsupported. Please do not use it.                                                                                                                                                                                  |
   +-----------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | ip_version            | No              | Array           | Specifies the IP version supported by the backend server. The value can be **v4** (IPv4) or **v6** (IPv6).                                                                                                                            |
   +-----------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | member_type           | No              | Array           | Specifies the type of the backend server. Values:                                                                                                                                                                                     |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | -  **ip**: IP as Backend servers                                                                                                                                                                                                      |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | -  **instance**: ECSs used as backend servers Multiple values can be queried in the format of *member_type=xxx&member_type=xxx*.                                                                                                      |
   +-----------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | instance_id           | No              | Array           | Specifies the ID of the instance associated with the backend server. If this parameter is left blank, the backend server is not an ECS. It may be an IP address.                                                                      |
   |                       |                 |                 |                                                                                                                                                                                                                                       |
   |                       |                 |                 | Multiple instance id can be queried in the format of *instance_id=xxx&instance_id=xxx*.                                                                                                                                               |
   +-----------------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

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

   +-----------------+---------+----------------------------------------------------------------------+
   | Parameter       | Type    | Description                                                          |
   +=================+=========+======================================================================+
   | previous_marker | String  | Specifies the ID of the first record in the pagination query result. |
   +-----------------+---------+----------------------------------------------------------------------+
   | next_marker     | String  | Specifies the ID of the last record in the pagination query result.  |
   +-----------------+---------+----------------------------------------------------------------------+
   | current_count   | Integer | Specifies the number of records.                                     |
   +-----------------+---------+----------------------------------------------------------------------+

.. _listmembers__response_member:

.. table:: **Table 6** Member

   +-----------------------+---------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                                                                      | Description                                                                                                                                                                                                                                                        |
   +=======================+===========================================================================+====================================================================================================================================================================================================================================================================+
   | id                    | String                                                                    | Specifies the backend server ID.                                                                                                                                                                                                                                   |
   |                       |                                                                           |                                                                                                                                                                                                                                                                    |
   |                       |                                                                           | Note:                                                                                                                                                                                                                                                              |
   |                       |                                                                           |                                                                                                                                                                                                                                                                    |
   |                       |                                                                           | The value of this parameter is not the ID of the server but an ID automatically generated for the backend server that has already associated with the load balancer.                                                                                               |
   +-----------------------+---------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                                                                    | Specifies the backend server name.                                                                                                                                                                                                                                 |
   +-----------------------+---------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | project_id            | String                                                                    | Specifies the project ID of the backend server.                                                                                                                                                                                                                    |
   +-----------------------+---------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up        | Boolean                                                                   | Specifies the administrative status of the backend server. The value can be **true** or **false**.                                                                                                                                                                 |
   |                       |                                                                           |                                                                                                                                                                                                                                                                    |
   |                       |                                                                           | Although this parameter can be used in the APIs for creating and updating backend servers, its actual value depends on whether cloud servers exist. If cloud servers exist, the value is **true**. Otherwise, the value is **false**.                              |
   +-----------------------+---------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | subnet_cidr_id        | String                                                                    | Specifies the ID of the IPv4 or IPv6 subnet where the backend server resides.                                                                                                                                                                                      |
   |                       |                                                                           |                                                                                                                                                                                                                                                                    |
   |                       |                                                                           | This parameter can be left blank, indicating that **IP as a Backend Server** has been enabled for the load balancer. In this case, IP addresses of these servers must be IPv4 addresses, and the protocol of the backend server group must be TCP, HTTP, or HTTPS. |
   |                       |                                                                           |                                                                                                                                                                                                                                                                    |
   |                       |                                                                           | The IPv4 or IPv6 subnet must be in the same VPC as the subnet of the load balancer.                                                                                                                                                                                |
   +-----------------------+---------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | protocol_port         | Integer                                                                   | Specifies the port used by the backend server to receive requests.                                                                                                                                                                                                 |
   |                       |                                                                           |                                                                                                                                                                                                                                                                    |
   |                       |                                                                           | Minimum: **1**                                                                                                                                                                                                                                                     |
   |                       |                                                                           |                                                                                                                                                                                                                                                                    |
   |                       |                                                                           | Maximum: **65535**                                                                                                                                                                                                                                                 |
   +-----------------------+---------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | weight                | Integer                                                                   | Specifies the weight of the backend server. Requests are routed to backend servers in the same backend server group based on their weights.                                                                                                                        |
   |                       |                                                                           |                                                                                                                                                                                                                                                                    |
   |                       |                                                                           | The value ranges from **0** to **100**, and the default value is **1**. The larger the weight is, the higher proportion of requests the backend server receives. If the weight is set to 0, the backend server will not accept new requests.                       |
   |                       |                                                                           |                                                                                                                                                                                                                                                                    |
   |                       |                                                                           | If **lb_algorithm** is set to **SOURCE_IP**, this parameter will not take effect.                                                                                                                                                                                  |
   |                       |                                                                           |                                                                                                                                                                                                                                                                    |
   |                       |                                                                           | Minimum: **0**                                                                                                                                                                                                                                                     |
   |                       |                                                                           |                                                                                                                                                                                                                                                                    |
   |                       |                                                                           | Maximum: **100**                                                                                                                                                                                                                                                   |
   +-----------------------+---------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | address               | String                                                                    | Specifies the private IP address bound to the backend server.                                                                                                                                                                                                      |
   |                       |                                                                           |                                                                                                                                                                                                                                                                    |
   |                       |                                                                           | -  If **subnet_cidr_id** is left blank, **IP as a Backend Server** is enabled. In this case, the IP address must be an IPv4 address.                                                                                                                               |
   |                       |                                                                           |                                                                                                                                                                                                                                                                    |
   |                       |                                                                           | -  If **subnet_cidr_id** is not left blank, the IP address can be IPv4 or IPv6. It must be in the subnet specified by **subnet_cidr_id** and can only be bound to the primary NIC of the backend server.                                                           |
   +-----------------------+---------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | ip_version            | String                                                                    | Specifies the IP version supported by the backend server. The value can be **v4** (IPv4) or **v6** (IPv6), depending on the value of **address** returned by the system.                                                                                           |
   +-----------------------+---------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | operating_status      | String                                                                    | Specifies the health status of the backend server if **listener_id** under **status** is not specified. The value can be one of the following:                                                                                                                     |
   |                       |                                                                           |                                                                                                                                                                                                                                                                    |
   |                       |                                                                           | -  **ONLINE**: The backend server is running normally.                                                                                                                                                                                                             |
   |                       |                                                                           |                                                                                                                                                                                                                                                                    |
   |                       |                                                                           | -  **NO_MONITOR**: No health check is configured for the backend server group to which the backend server belongs.                                                                                                                                                 |
   |                       |                                                                           |                                                                                                                                                                                                                                                                    |
   |                       |                                                                           | -  **OFFLINE**: The cloud server used as the backend server is stopped or does not exist.                                                                                                                                                                          |
   +-----------------------+---------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | status                | Array of :ref:`MemberStatus <listmembers__response_memberstatus>` objects | Specifies the health status of the backend server if **listener_id** is specified.                                                                                                                                                                                 |
   +-----------------------+---------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | loadbalancer_id       | String                                                                    | Specifies the ID of the load balancer with which the backend server is associated.                                                                                                                                                                                 |
   |                       |                                                                           |                                                                                                                                                                                                                                                                    |
   |                       |                                                                           | This parameter is unsupported. Please do not use it.                                                                                                                                                                                                               |
   +-----------------------+---------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | loadbalancers         | Array of :ref:`ResourceID <listmembers__response_resourceid>` objects     | Specifies the IDs of the load balancers associated with the backend server.                                                                                                                                                                                        |
   |                       |                                                                           |                                                                                                                                                                                                                                                                    |
   |                       |                                                                           | This parameter is unsupported. Please do not use it.                                                                                                                                                                                                               |
   +-----------------------+---------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | created_at            | String                                                                    | Specifies the time when a backend server was added. The format is yyyy-MM-dd'T'HH:mm:ss'Z' (UTC time).                                                                                                                                                             |
   |                       |                                                                           |                                                                                                                                                                                                                                                                    |
   |                       |                                                                           | This is a new field in this version, and it will not be returned for resources associated with existing dedicated load balancers and for resources associated with existing and new shared load balancers.                                                         |
   +-----------------------+---------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | updated_at            | String                                                                    | Specifies the time when a backend server was updated. The format is yyyy-MM-dd'T'HH:mm:ss'Z' (UTC time).                                                                                                                                                           |
   |                       |                                                                           |                                                                                                                                                                                                                                                                    |
   |                       |                                                                           | This is a new field in this version, and it will not be returned for resources associated with existing dedicated load balancers and for resources associated with existing and new shared load balancers.                                                         |
   +-----------------------+---------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | member_type           | String                                                                    | Specifies the type of the backend server. Values:                                                                                                                                                                                                                  |
   |                       |                                                                           |                                                                                                                                                                                                                                                                    |
   |                       |                                                                           | -  **ip**: IP as Backend servers                                                                                                                                                                                                                                   |
   |                       |                                                                           |                                                                                                                                                                                                                                                                    |
   |                       |                                                                           | -  **instance**: ECSs used as backend servers                                                                                                                                                                                                                      |
   +-----------------------+---------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | instance_id           | String                                                                    | Specifies the ID of the ECS used as the backend server. If this parameter is left blank, the backend server is not an ECS. For example, it may be an IP address.                                                                                                   |
   +-----------------------+---------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _listmembers__response_memberstatus:

.. table:: **Table 7** MemberStatus

   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                        |
   +=======================+=======================+====================================================================================================================+
   | listener_id           | String                | Specifies the listener ID.                                                                                         |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------+
   | operating_status      | String                | Specifies the health status of the backend server. The value can be one of the following:                          |
   |                       |                       |                                                                                                                    |
   |                       |                       | -  **ONLINE**: The backend server is running normally.                                                             |
   |                       |                       |                                                                                                                    |
   |                       |                       | -  **NO_MONITOR**: No health check is configured for the backend server group to which the backend server belongs. |
   |                       |                       |                                                                                                                    |
   |                       |                       | -  **OFFLINE**: The cloud server used as the backend server is stopped or does not exist.                          |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------+

.. _listmembers__response_resourceid:

.. table:: **Table 8** ResourceID

   ========= ====== ==========================
   Parameter Type   Description
   ========= ====== ==========================
   id        String Specifies the resource ID.
   ========= ====== ==========================

Example Requests
----------------

.. code-block:: text

   GET https://{ELB_Endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/pools/36ce7086-a496-4666-9064-5ba0e6840c75/members

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
