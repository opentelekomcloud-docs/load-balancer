:original_name: CreateMember.html

.. _CreateMember:

Adding a Backend Server
=======================

Function
--------

This API is used to add a backend server.

Constraints
-----------

When you add backend servers, note the following:

-  Two backend servers in the same backend server group must have different IP addresses and ports.

-  If no subnets are specified during cloud server creation, cross-VPC backend servers can be added. In this case, **address** must be set to an IPv4 address, the protocol of the backend server group must be TCP, HTTP, or HTTPS, and cross-VPC backend must have been enabled for the load balancer.

-  If a subnet is specified during cloud server creation, the subnet must be in the same VPC as that where the load balancer resides.

-  If the backend server group supports IPv4/IPv6 dual stack, **address** can be an IPv4 address or an IPv6 address. If the backend server group supports only IPv4, **address** can only be an IPv4 address.

-  IPv6 is unsupported.

URI
---

POST /v3/{project_id}/elb/pools/{pool_id}/members

.. table:: **Table 1** Path Parameters

   +------------+-----------+--------+-----------------------------------------------+
   | Parameter  | Mandatory | Type   | Description                                   |
   +============+===========+========+===============================================+
   | pool_id    | Yes       | String | Specifies the ID of the backend server group. |
   +------------+-----------+--------+-----------------------------------------------+
   | project_id | Yes       | String | Specifies the project ID.                     |
   +------------+-----------+--------+-----------------------------------------------+

Request Parameters
------------------

.. table:: **Table 2** Request header parameters

   +--------------+-----------+--------+--------------------------------------------------+
   | Parameter    | Mandatory | Type   | Description                                      |
   +==============+===========+========+==================================================+
   | X-Auth-Token | Yes       | String | Specifies the token used for IAM authentication. |
   +--------------+-----------+--------+--------------------------------------------------+

.. table:: **Table 3** Request body parameters

   +-----------+-----------+-----------------------------------------------------------------------------+-------------------------------+
   | Parameter | Mandatory | Type                                                                        | Description                   |
   +===========+===========+=============================================================================+===============================+
   | member    | Yes       | :ref:`CreateMemberOption <createmember__request_creatememberoption>` object | Specifies the backend server. |
   +-----------+-----------+-----------------------------------------------------------------------------+-------------------------------+

.. _createmember__request_creatememberoption:

.. table:: **Table 4** CreateMemberOption

   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                                                                                                                                                                                      |
   +=================+=================+=================+==================================================================================================================================================================================================================================================+
   | address         | Yes             | String          | Specifies the private IP address bound to the backend server.                                                                                                                                                                                    |
   |                 |                 |                 |                                                                                                                                                                                                                                                  |
   |                 |                 |                 | -  If **subnet_cidr_id** is left blank, cross-VPC backend is enabled. In this case, the IP address must be an IPv4 address.                                                                                                                      |
   |                 |                 |                 |                                                                                                                                                                                                                                                  |
   |                 |                 |                 | -  If **subnet_cidr_id** is not left blank, the IP address can be IPv4 or IPv6. It must be in the subnet specified by **subnet_cidr_id** and can only be bound to the primary NIC of the backend server.                                         |
   |                 |                 |                 |                                                                                                                                                                                                                                                  |
   |                 |                 |                 | IPv6 is unsupported. Please do not enter an IPv6 address.                                                                                                                                                                                        |
   |                 |                 |                 |                                                                                                                                                                                                                                                  |
   |                 |                 |                 | Minimum: **1**                                                                                                                                                                                                                                   |
   |                 |                 |                 |                                                                                                                                                                                                                                                  |
   |                 |                 |                 | Maximum: **64**                                                                                                                                                                                                                                  |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up  | No              | Boolean         | Specifies the administrative status of the backend server. The value can be **true** or **false**.                                                                                                                                               |
   |                 |                 |                 |                                                                                                                                                                                                                                                  |
   |                 |                 |                 | Although this parameter can be used in the APIs for creating and updating backend servers, its actual value depends on whether cloud servers exist. If cloud servers exist, the value is **true**. Otherwise, the value is **false**.            |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name            | No              | String          | Specifies the backend server name.                                                                                                                                                                                                               |
   |                 |                 |                 |                                                                                                                                                                                                                                                  |
   |                 |                 |                 | Minimum: **0**                                                                                                                                                                                                                                   |
   |                 |                 |                 |                                                                                                                                                                                                                                                  |
   |                 |                 |                 | Maximum: **255**                                                                                                                                                                                                                                 |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | project_id      | No              | String          | Specifies the project ID.                                                                                                                                                                                                                        |
   |                 |                 |                 |                                                                                                                                                                                                                                                  |
   |                 |                 |                 | Minimum: **1**                                                                                                                                                                                                                                   |
   |                 |                 |                 |                                                                                                                                                                                                                                                  |
   |                 |                 |                 | Maximum: **32**                                                                                                                                                                                                                                  |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | protocol_port   | Yes             | Integer         | Specifies the port used by the backend server to receive requests.                                                                                                                                                                               |
   |                 |                 |                 |                                                                                                                                                                                                                                                  |
   |                 |                 |                 | Minimum: **1**                                                                                                                                                                                                                                   |
   |                 |                 |                 |                                                                                                                                                                                                                                                  |
   |                 |                 |                 | Maximum: **65535**                                                                                                                                                                                                                               |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | subnet_cidr_id  | No              | String          | Specifies the ID of the IPv4 or IPv6 subnet where the backend server resides.                                                                                                                                                                    |
   |                 |                 |                 |                                                                                                                                                                                                                                                  |
   |                 |                 |                 | Note:                                                                                                                                                                                                                                            |
   |                 |                 |                 |                                                                                                                                                                                                                                                  |
   |                 |                 |                 | -  The IPv4 or IPv6 subnet must be in the same VPC as the subnet of the load balancer.                                                                                                                                                           |
   |                 |                 |                 |                                                                                                                                                                                                                                                  |
   |                 |                 |                 | -  If this parameter is not passed, cross-VPC backend has been enabled for the load balancer. In this case, cross-VPC backend servers must use private IPv4 addresses, and the protocol of the backend server group must be TCP, HTTP, or HTTPS. |
   |                 |                 |                 |                                                                                                                                                                                                                                                  |
   |                 |                 |                 | IPv6 is unsupported. Please do not set the value to the ID of an IPv6 subnet.                                                                                                                                                                    |
   |                 |                 |                 |                                                                                                                                                                                                                                                  |
   |                 |                 |                 | Minimum: **1**                                                                                                                                                                                                                                   |
   |                 |                 |                 |                                                                                                                                                                                                                                                  |
   |                 |                 |                 | Maximum: **36**                                                                                                                                                                                                                                  |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | weight          | No              | Integer         | Specifies the weight of the backend server. Requests are routed to backend servers in the same backend server group based on their weights.                                                                                                      |
   |                 |                 |                 |                                                                                                                                                                                                                                                  |
   |                 |                 |                 | The value ranges from **0** to **100**, and the default value is **1**. The larger the weight is, the higher proportion of requests the backend server receives. If the weight is set to 0, the backend server will not accept new requests.     |
   |                 |                 |                 |                                                                                                                                                                                                                                                  |
   |                 |                 |                 | If **lb_algorithm** is set to **SOURCE_IP**, this parameter will not take effect.                                                                                                                                                                |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Response Parameters
-------------------

**Status code: 201**

.. table:: **Table 5** Response body parameters

   +------------+------------------------------------------------------+-----------------------------------------------------------------+
   | Parameter  | Type                                                 | Description                                                     |
   +============+======================================================+=================================================================+
   | request_id | String                                               | Specifies the request ID. The value is automatically generated. |
   +------------+------------------------------------------------------+-----------------------------------------------------------------+
   | member     | :ref:`Member <createmember__response_member>` object | Specifies the backend server.                                   |
   +------------+------------------------------------------------------+-----------------------------------------------------------------+

.. _createmember__response_member:

.. table:: **Table 6** Member

   +-----------------------+----------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                                                                       | Description                                                                                                                                                                                                                                               |
   +=======================+============================================================================+===========================================================================================================================================================================================================================================================+
   | id                    | String                                                                     | Specifies the backend server ID.                                                                                                                                                                                                                          |
   |                       |                                                                            |                                                                                                                                                                                                                                                           |
   |                       |                                                                            | Note:                                                                                                                                                                                                                                                     |
   |                       |                                                                            |                                                                                                                                                                                                                                                           |
   |                       |                                                                            | The value of this parameter is not the ID of the server but an ID automatically generated for the backend server that has already associated with the load balancer.                                                                                      |
   +-----------------------+----------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                                                                     | Specifies the backend server name.                                                                                                                                                                                                                        |
   +-----------------------+----------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | project_id            | String                                                                     | Specifies the project ID of the backend server.                                                                                                                                                                                                           |
   +-----------------------+----------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | pool_id               | String                                                                     | Specifies the ID of the backend server group to which the backend server belongs.                                                                                                                                                                         |
   |                       |                                                                            |                                                                                                                                                                                                                                                           |
   |                       |                                                                            | This parameter is unsupported. Please do not use it.                                                                                                                                                                                                      |
   +-----------------------+----------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up        | Boolean                                                                    | Specifies the administrative status of the backend server. The value can be **true** or **false**.                                                                                                                                                        |
   |                       |                                                                            |                                                                                                                                                                                                                                                           |
   |                       |                                                                            | Although this parameter can be used in the APIs for creating and updating backend servers, its actual value depends on whether cloud servers exist. If cloud servers exist, the value is **true**. Otherwise, the value is **false**.                     |
   +-----------------------+----------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | subnet_cidr_id        | String                                                                     | Specifies the ID of the IPv4 or IPv6 subnet where the backend server resides.                                                                                                                                                                             |
   |                       |                                                                            |                                                                                                                                                                                                                                                           |
   |                       |                                                                            | This parameter can be left blank, indicating that cross-VPC backend has been enabled for the load balancer. In this case, IP addresses of these servers must be IPv4 addresses, and the protocol of the backend server group must be TCP, HTTP, or HTTPS. |
   |                       |                                                                            |                                                                                                                                                                                                                                                           |
   |                       |                                                                            | The IPv4 or IPv6 subnet must be in the same VPC as the subnet of the load balancer.                                                                                                                                                                       |
   |                       |                                                                            |                                                                                                                                                                                                                                                           |
   |                       |                                                                            | IPv6 is unsupported. Please do not set the value to the ID of an IPv6 subnet.                                                                                                                                                                             |
   +-----------------------+----------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | protocol_port         | Integer                                                                    | Specifies the port used by the backend server to receive requests.                                                                                                                                                                                        |
   |                       |                                                                            |                                                                                                                                                                                                                                                           |
   |                       |                                                                            | Minimum: **1**                                                                                                                                                                                                                                            |
   |                       |                                                                            |                                                                                                                                                                                                                                                           |
   |                       |                                                                            | Maximum: **65535**                                                                                                                                                                                                                                        |
   +-----------------------+----------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | weight                | Integer                                                                    | Specifies the weight of the backend server. Requests are routed to backend servers in the same backend server group based on their weights.                                                                                                               |
   |                       |                                                                            |                                                                                                                                                                                                                                                           |
   |                       |                                                                            | The value ranges from **0** to **100**, and the default value is **1**. The larger the weight is, the higher proportion of requests the backend server receives. If the weight is set to 0, the backend server will not accept new requests.              |
   |                       |                                                                            |                                                                                                                                                                                                                                                           |
   |                       |                                                                            | If **lb_algorithm** is set to **SOURCE_IP**, this parameter will not take effect.                                                                                                                                                                         |
   |                       |                                                                            |                                                                                                                                                                                                                                                           |
   |                       |                                                                            | Minimum: **0**                                                                                                                                                                                                                                            |
   |                       |                                                                            |                                                                                                                                                                                                                                                           |
   |                       |                                                                            | Maximum: **100**                                                                                                                                                                                                                                          |
   +-----------------------+----------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | address               | String                                                                     | Specifies the private IP address bound to the backend server.                                                                                                                                                                                             |
   |                       |                                                                            |                                                                                                                                                                                                                                                           |
   |                       |                                                                            | -  If **subnet_cidr_id** is left blank, cross-VPC backend is enabled. In this case, the IP address must be an IPv4 address.                                                                                                                               |
   |                       |                                                                            |                                                                                                                                                                                                                                                           |
   |                       |                                                                            | -  If **subnet_cidr_id** is not left blank, the IP address can be IPv4 or IPv6. It must be in the subnet specified by **subnet_cidr_id** and can only be bound to the primary NIC of the backend server.                                                  |
   |                       |                                                                            |                                                                                                                                                                                                                                                           |
   |                       |                                                                            | IPv6 is unsupported. Please do not enter an IPv6 address.                                                                                                                                                                                                 |
   +-----------------------+----------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | ip_version            | String                                                                     | Specifies the IP version supported by the backend server. The value can be **v4** (IPv4) or **v6** (IPv6), depending on the value of **address** returned by the system.                                                                                  |
   +-----------------------+----------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | operating_status      | String                                                                     | Specifies the health status of the backend server if **listener_id** under **status** is not specified. The value can be one of the following:                                                                                                            |
   |                       |                                                                            |                                                                                                                                                                                                                                                           |
   |                       |                                                                            | -  **ONLINE**: The backend server is running normally.                                                                                                                                                                                                    |
   |                       |                                                                            |                                                                                                                                                                                                                                                           |
   |                       |                                                                            | -  **NO_MONITOR**: No health check is configured for the backend server group to which the backend server belongs.                                                                                                                                        |
   |                       |                                                                            |                                                                                                                                                                                                                                                           |
   |                       |                                                                            | -  **OFFLINE**: The cloud server used as the backend server is stopped or does not exist.                                                                                                                                                                 |
   +-----------------------+----------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | status                | Array of :ref:`MemberStatus <createmember__response_memberstatus>` objects | Specifies the health status of the backend server if **listener_id** is specified.                                                                                                                                                                        |
   +-----------------------+----------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | loadbalancer_id       | String                                                                     | Specifies the ID of the load balancer with which the backend server is associated.                                                                                                                                                                        |
   |                       |                                                                            |                                                                                                                                                                                                                                                           |
   |                       |                                                                            | This parameter is unsupported. Please do not use it.                                                                                                                                                                                                      |
   +-----------------------+----------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | loadbalancers         | Array of :ref:`ResourceID <createmember__response_resourceid>` objects     | Specifies the IDs of the load balancers associated with the backend server.                                                                                                                                                                               |
   |                       |                                                                            |                                                                                                                                                                                                                                                           |
   |                       |                                                                            | This parameter is unsupported. Please do not use it.                                                                                                                                                                                                      |
   +-----------------------+----------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | created_at            | String                                                                     | Specifies the time when a backend server was added. The format is yyyy-MM-dd'T'HH:mm:ss'Z' (UTC time).                                                                                                                                                    |
   |                       |                                                                            |                                                                                                                                                                                                                                                           |
   |                       |                                                                            | This is a new field in this version, and it will not be returned for resources associated with existing dedicated load balancers and for resources associated with existing and new shared load balancers.                                                |
   +-----------------------+----------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | updated_at            | String                                                                     | Specifies the time when a backend server was updated. The format is yyyy-MM-dd'T'HH:mm:ss'Z' (UTC time).                                                                                                                                                  |
   |                       |                                                                            |                                                                                                                                                                                                                                                           |
   |                       |                                                                            | This is a new field in this version, and it will not be returned for resources associated with existing dedicated load balancers and for resources associated with existing and new shared load balancers.                                                |
   +-----------------------+----------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | member_type           | String                                                                     | Specifies the type of the backend server. Values:                                                                                                                                                                                                         |
   |                       |                                                                            |                                                                                                                                                                                                                                                           |
   |                       |                                                                            | -  **ip**: cross-VPC backend servers                                                                                                                                                                                                                      |
   |                       |                                                                            |                                                                                                                                                                                                                                                           |
   |                       |                                                                            | -  **instance**: ECSs used as backend servers                                                                                                                                                                                                             |
   +-----------------------+----------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | instance_id           | String                                                                     | Specifies the ID of the ECS used as the backend server. If this parameter is left blank, the backend server is not an ECS. For example, it may be an IP address.                                                                                          |
   +-----------------------+----------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _createmember__response_memberstatus:

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

.. _createmember__response_resourceid:

.. table:: **Table 8** ResourceID

   ========= ====== ==========================
   Parameter Type   Description
   ========= ====== ==========================
   id        String Specifies the resource ID.
   ========= ====== ==========================

Example Requests
----------------

-  Example 1: Adding a backend server

   .. code-block:: text

      POST https://{ELB_Endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/pools/36ce7086-a496-4666-9064-5ba0e6840c75/members

      {
        "member" : {
          "subnet_cidr_id" : "c09f620e-3492-4429-ac15-445d5dd9ca74",
          "protocol_port" : 89,
          "name" : "My member",
          "address" : "120.10.10.16"
        }
      }

-  Example 2: Adding a cross-VPC backend server

   .. code-block:: text

      POST https://{ELB_Endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/pools/36ce7086-a496-4666-9064-5ba0e6840c75/members

      {
        "member" : {
          "protocol_port" : 89,
          "name" : "My member",
          "address" : "120.10.10.16"
        }
      }

Example Responses
-----------------

**Status code: 201**

Normal response to POST requests.

.. code-block::

   {
     "member" : {
       "name" : "My member",
       "weight" : 1,
       "admin_state_up" : false,
       "subnet_cidr_id" : "c09f620e-3492-4429-ac15-445d5dd9ca74",
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "address" : "120.10.10.16",
       "protocol_port" : 89,
       "id" : "1923923e-fe8a-484f-bdbc-e11559b1f48f",
       "operating_status" : "NO_MONITOR",
       "status" : [ {
         "listener_id" : "427eee03-b569-4d6c-b1f1-712032f7ec2d",
         "operating_status" : "NO_MONITOR"
       } ],
       "ip_version" : "v4"
     },
     "request_id" : "f354090d-41db-41e0-89c6-7a943ec50792"
   }

Status Codes
------------

=========== =================================
Status Code Description
=========== =================================
201         Normal response to POST requests.
=========== =================================

Error Codes
-----------

See :ref:`Error Codes <errorcode>`.
