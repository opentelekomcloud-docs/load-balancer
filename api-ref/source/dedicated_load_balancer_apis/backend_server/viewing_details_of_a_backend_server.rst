:original_name: ShowMember.html

.. _ShowMember:

Viewing Details of a Backend Server
===================================

Function
--------

This API is used to view details of a backend server.

URI
---

GET /v3/{project_id}/elb/pools/{pool_id}/members/{member_id}

.. table:: **Table 1** Path Parameters

   +------------+-----------+--------+-----------------------------------------------+
   | Parameter  | Mandatory | Type   | Description                                   |
   +============+===========+========+===============================================+
   | project_id | Yes       | String | Specifies the project ID.                     |
   +------------+-----------+--------+-----------------------------------------------+
   | pool_id    | Yes       | String | Specifies the ID of the backend server group. |
   +------------+-----------+--------+-----------------------------------------------+
   | member_id  | Yes       | String | Specifies the backend server ID.              |
   +------------+-----------+--------+-----------------------------------------------+

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
   | member     | :ref:`Member <showmember__response_member>` object | Specifies the backend server.                                   |
   +------------+----------------------------------------------------+-----------------------------------------------------------------+

.. _showmember__response_member:

.. table:: **Table 4** Member

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

   https://{elb_endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/pools/36ce7086-a496-4666-9064-5ba0e6840c75/members/1923923e-fe8a-484f-bdbc-e11559b1f48f

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

   {
     "member" : {
       "name" : "My member",
       "weight" : 10,
       "admin_state_up" : false,
       "subnet_cidr_id" : "c09f620e-3492-4429-ac15-445d5dd9ca74",
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "address" : "120.10.10.16",
       "protocol_port" : 89,
       "id" : "1923923e-fe8a-484f-bdbc-e11559b1f48f",
       "operating_status" : "NO_MONITOR",
       "ip_version" : "v4"
     },
     "request_id" : "45688823-45f1-40cd-9d24-e51a9574a45b"
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
