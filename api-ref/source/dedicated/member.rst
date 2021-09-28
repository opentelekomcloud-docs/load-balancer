=======
Memeber
=======

Adding a Backend Server
=======================

Function
^^^^^^^^

This API is used to add a backend server.

Constraints
^^^^^^^^^^^

When you add backend servers, note the following:

-  Two backend servers in the same backend server group must have different IP
   addresses and ports.

-  If no subnets are specified during cloud server creation, cross-VPC backend
   servers can be added. In this case, **address** must be set to an IPv4
   address, the protocol of the backend server group must be TCP, HTTP, or
   HTTPS, and cross-VPC backend must have been enabled for the load balancer.

-  If a subnet is specified during cloud server creation, the subnet must be in
   the same VPC as the subnet from which the virtual IP address bound to the
   load balancer is assigned.

-  If the backend server group supports IPv4/IPv6 dual stack, **address** can
   be an IPv4 or IPv6 address. The value of **address** depends on the IP
   address version of the backend server group.

URI
^^^

POST /v3/{project_id}/elb/pools/{pool_id}/members

.. table:: **Table 1** Path parameters

   ========== ========= ====== =============================================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =============================================
   pool_id    Yes       String Specifies the ID of the backend server group.
   project_id Yes       String Specifies the project ID.
   ========== ========= ====== =============================================

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 2** Request header parameters

   ============ ========= ====== ================================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ================================================
   X-Auth-Token Yes       String Specifies the token used for IAM authentication.
   ============ ========= ====== ================================================

.. table:: **Table 3** Request body parameters

   +-----------+-----------+----------------------+---------------------------------------------+
   | Parameter | Mandatory | Type                 | Description                                 |
   +===========+===========+======================+=============================================+
   | member    | Yes       | :ref:`dmc_co` object | Specifies request parameters for creating a |
   |           |           |                      | backend server.                             |
   +-----------+-----------+----------------------+---------------------------------------------+

.. _dmc_co:
.. table:: **Table 4** CreateMemberOption

   +----------------+-----------+---------+-----------------------------+
   | Parameter      | Mandatory | Type    | Description                 |
   +================+===========+=========+=============================+
   | address        | Yes       | String  | Specifies the IP address of |
   |                |           |         | the backend server.         |
   |                |           |         |                             |
   |                |           |         | -  The IP address must be   |
   |                |           |         |    in the subnet specified  |
   |                |           |         |    by **subnet_cidr_id**,   |
   |                |           |         |    for example,             |
   |                |           |         |    192.168.3.11.            |
   |                |           |         |                             |
   |                |           |         | -  The IP address can only  |
   |                |           |         |    be the IP address of the |
   |                |           |         |    primary NIC.             |
   |                |           |         |                             |
   |                |           |         | -  If **subnet_cidr_id** is |
   |                |           |         |    left blank, cross-VPC    |
   |                |           |         |    backend is enabled. In   |
   |                |           |         |    this case, these servers |
   |                |           |         |    must use IPv4 addresses. |
   |                |           |         |                             |
   |                |           |         | Minimum: **1**              |
   |                |           |         |                             |
   |                |           |         | Maximum: **64**             |
   +----------------+-----------+---------+-----------------------------+
   | admin_state_up | No        | Boolean | Specifies the               |
   |                |           |         | administrative status of    |
   |                |           |         | the backend server.         |
   |                |           |         |                             |
   |                |           |         | Although this parameter can |
   |                |           |         | be used in the APIs for     |
   |                |           |         | creating and updating       |
   |                |           |         | backend servers, its actual |
   |                |           |         | value depends on whether    |
   |                |           |         | cloud servers exist. If     |
   |                |           |         | cloud servers exist, the    |
   |                |           |         | value is **true**.          |
   |                |           |         | Otherwise, the value is     |
   |                |           |         | **false**.                  |
   +----------------+-----------+---------+-----------------------------+
   | name           | No        | String  | Specifies the backend       |
   |                |           |         | server name.                |
   |                |           |         |                             |
   |                |           |         | Minimum: **0**              |
   |                |           |         |                             |
   |                |           |         | Maximum: **255**            |
   +----------------+-----------+---------+-----------------------------+
   | project_id     | No        | String  | Specifies the project ID.   |
   |                |           |         |                             |
   |                |           |         | Minimum: **1**              |
   |                |           |         |                             |
   |                |           |         | Maximum: **32**             |
   +----------------+-----------+---------+-----------------------------+
   | protocol_port  | Yes       | Integer | Specifies the port used by  |
   |                |           |         | the backend server to       |
   |                |           |         | receive requests.           |
   |                |           |         |                             |
   |                |           |         | Minimum: **1**              |
   |                |           |         |                             |
   |                |           |         | Maximum: **65535**          |
   +----------------+-----------+---------+-----------------------------+
   | subnet_cidr_id | No        | String  | Specifies the ID of the     |
   |                |           |         | subnet where the backend    |
   |                |           |         | server works.               |
   |                |           |         |                             |
   |                |           |         | This subnet must be in the  |
   |                |           |         | same VPC as the subnet of   |
   |                |           |         | the load balancer with      |
   |                |           |         | which the backend server is |
   |                |           |         | associated. Only IPv4       |
   |                |           |         | subnets are supported.      |
   |                |           |         |                             |
   |                |           |         | This parameter can be left  |
   |                |           |         | blank, indicating that      |
   |                |           |         | cross-VPC backend servers   |
   |                |           |         | can be added. In this case, |
   |                |           |         | IP addresses of these       |
   |                |           |         | servers must be IPv4        |
   |                |           |         | addresses, the protocol of  |
   |                |           |         | the backend server group    |
   |                |           |         | must be TCP, HTTP, or       |
   |                |           |         | HTTPS, and cross-VPC        |
   |                |           |         | backend must have been      |
   |                |           |         | enabled for the load        |
   |                |           |         | balancer.                   |
   |                |           |         |                             |
   |                |           |         | Minimum: **1**              |
   |                |           |         |                             |
   |                |           |         | Maximum: **36**             |
   +----------------+-----------+---------+-----------------------------+
   | weight         | No        | Integer | Specifies the weight of the |
   |                |           |         | backend server.             |
   |                |           |         |                             |
   |                |           |         | Requests are routed to      |
   |                |           |         | backend servers in the same |
   |                |           |         | backend server group based  |
   |                |           |         | on their weights.           |
   |                |           |         |                             |
   |                |           |         | If the weight is 0, the     |
   |                |           |         | backend server will not     |
   |                |           |         | accept new requests.        |
   |                |           |         |                             |
   |                |           |         | This parameter is invalid   |
   |                |           |         | when **lb_algorithm** is    |
   |                |           |         | set to **SOURCE_IP** for    |
   |                |           |         | the backend server group    |
   |                |           |         | that contains the backend   |
   |                |           |         | server.                     |
   |                |           |         |                             |
   |                |           |         | Minimum: **0**              |
   |                |           |         |                             |
   |                |           |         | Maximum: **100**            |
   |                |           |         |                             |
   |                |           |         | Default: **1**              |
   +----------------+-----------+---------+-----------------------------+

Response Parameters
^^^^^^^^^^^^^^^^^^^

**Status code: 201**

.. table:: **Table 5** Response body parameters

   +------------+---------------------+----------------------------------------+
   | Parameter  | Type                | Description                            |
   +============+=====================+========================================+
   | request_id | String              | Specifies the request ID. The value is |
   |            |                     | automatically generated.               |
   +------------+---------------------+----------------------------------------+
   | member     | :ref:`dmc_m` object | Specifies the backend server.          |
   +------------+---------------------+----------------------------------------+

.. _dmc_m:
.. table:: **Table 6** Member

   +------------------+---------+---------------------------------------+
   | Parameter        | Type    | Description                           |
   +==================+=========+=======================================+
   | address          | String  | Specifies the IP address of the       |
   |                  |         | backend server.                       |
   |                  |         |                                       |
   |                  |         | The IP address must be in the subnet  |
   |                  |         | specified by **subnet_cidr_id**, for  |
   |                  |         | example, 192.168.3.11. The IP address |
   |                  |         | can only be the IP address of the     |
   |                  |         | primary NIC.                          |
   +------------------+---------+---------------------------------------+
   | admin_state_up   | Boolean | Specifies the administrative status   |
   |                  |         | of the backend server.                |
   |                  |         |                                       |
   |                  |         | Although this parameter can be used   |
   |                  |         | in the APIs for creating and updating |
   |                  |         | backend servers, its actual value     |
   |                  |         | depends on whether cloud servers      |
   |                  |         | exist. If cloud servers exist, the    |
   |                  |         | value is **true**. Otherwise, the     |
   |                  |         | value is **false**.                   |
   |                  |         |                                       |
   |                  |         | Default: **true**                     |
   +------------------+---------+---------------------------------------+
   | id               | String  | Specifies the backend server ID.      |
   +------------------+---------+---------------------------------------+
   | name             | String  | Specifies the backend server name.    |
   +------------------+---------+---------------------------------------+
   | operating_status | String  | Specifies the operating status of the |
   |                  |         | backend server. The value can be one  |
   |                  |         | of the following:                     |
   |                  |         |                                       |
   |                  |         | -  **ONLINE**: The backend server is  |
   |                  |         |    running normally.                  |
   |                  |         |                                       |
   |                  |         | -  **NO_MONITOR**: No health check is |
   |                  |         |    configured for the backend server  |
   |                  |         |    group to which the backend server  |
   |                  |         |    belongs.                           |
   |                  |         |                                       |
   |                  |         | -  **OFFLINE**: The cloud server used |
   |                  |         |    as the backend server is stopped   |
   |                  |         |    or does not exist.                 |
   +------------------+---------+---------------------------------------+
   | project_id       | String  | Specifies the project ID.             |
   +------------------+---------+---------------------------------------+
   | protocol_port    | Integer | Specifies the port used by the        |
   |                  |         | backend server to receive requests.   |
   |                  |         |                                       |
   |                  |         | Minimum: **1**                        |
   |                  |         |                                       |
   |                  |         | Maximum: **65535**                    |
   +------------------+---------+---------------------------------------+
   | subnet_cidr_id   | String  | Specifies the ID of the subnet where  |
   |                  |         | the backend server works. This subnet |
   |                  |         | must be in the VPC as the subnet of   |
   |                  |         | the load balancer associated with the |
   |                  |         | backend server. Only IPv4 subnets are |
   |                  |         | supported. If the value is left       |
   |                  |         | blank, the backend server is not in   |
   |                  |         | the load balancer's VPC.              |
   +------------------+---------+---------------------------------------+
   | weight           | Integer | Specifies the weight of the backend   |
   |                  |         | server.                               |
   |                  |         |                                       |
   |                  |         | Requests are routed to backend        |
   |                  |         | servers in the same backend server    |
   |                  |         | group based on their weights.         |
   |                  |         |                                       |
   |                  |         | If the weight is 0, the backend       |
   |                  |         | server will not accept new requests.  |
   |                  |         |                                       |
   |                  |         | This parameter is invalid when        |
   |                  |         | **lb_algorithm** is set to            |
   |                  |         | **SOURCE_IP** for the backend server  |
   |                  |         | group that contains the backend       |
   |                  |         | server.                               |
   |                  |         |                                       |
   |                  |         | Minimum: **0**                        |
   |                  |         |                                       |
   |                  |         | Maximum: **100**                      |
   |                  |         |                                       |
   |                  |         | Default: **1**                        |
   +------------------+---------+---------------------------------------+
   | ip_version       | String  | This is a read-only attribute, which  |
   |                  |         | is automatically generated based on   |
   |                  |         | the **address** parameter. The value  |
   |                  |         | can be **v4** or **v6**.              |
   |                  |         |                                       |
   |                  |         | Default: **v4**                       |
   +------------------+---------+---------------------------------------+

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   POST

   https://{elb_endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/pools/36ce7086-a496-4666-9064-5ba0e6840c75/members

   {
     "member" : {
       "subnet_cidr_id" : "c09f620e-3492-4429-ac15-445d5dd9ca74",
       "protocol_port" : 89,
       "name" : "My member",
       "address" : "120.10.10.16"
     }
   }

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 201**

Successful request.

.. code::

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
       "ip_version" : "v4"
     },
     "request_id" : "f354090d-41db-41e0-89c6-7a943ec50792"
   }

Status Codes
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
201         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Querying Backend Servers
========================

Function
^^^^^^^^

This API is used to query all backend servers.

Constraints
^^^^^^^^^^^

Parameters **marker**, **limit**, and **page_reverse** are used for pagination
query.

Parameters **marker** and **page_reverse** take effect only when they are used
together with parameter **limit**.

URI
^^^

GET /v3/{project_id}/elb/pools/{pool_id}/members

.. table:: **Table 1** Path parameters

   ========== ========= ====== =============================================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =============================================
   project_id Yes       String Specifies the project ID.
   pool_id    Yes       String Specifies the ID of the backend server group.
   ========== ========= ====== =============================================

.. table:: **Table 2** Query parameters

   +-----------------------+-----------+---------+----------------------------------------------+
   | Parameter             | Mandatory | Type    | Description                                  |
   +=======================+===========+=========+==============================================+
   | marker                | No        | String  | Specifies the ID of the                      |
   |                       |           |         | last record on the previous                  |
   |                       |           |         | page.                                        |
   |                       |           |         |                                              |
   |                       |           |         | Note:                                        |
   |                       |           |         |                                              |
   |                       |           |         | -  This parameter must be                    |
   |                       |           |         |    used together with                        |
   |                       |           |         |    **limit**.                                |
   |                       |           |         |                                              |
   |                       |           |         | -  If this parameter is not                  |
   |                       |           |         |    specified, the first                      |
   |                       |           |         |    page will be queried.                     |
   |                       |           |         |                                              |
   |                       |           |         | -  This parameter cannot be                  |
   |                       |           |         |    left blank or set to an                   |
   |                       |           |         |    invalid ID.                               |
   +-----------------------+-----------+---------+----------------------------------------------+
   | limit                 | No        | Integer | Specifies the number of                      |
   |                       |           |         | records on each page.                        |
   |                       |           |         |                                              |
   |                       |           |         | Minimum: **0**                               |
   |                       |           |         |                                              |
   |                       |           |         | Maximum: **2000**                            |
   +-----------------------+-----------+---------+----------------------------------------------+
   | page_reverse          | No        | Boolean | Specifies the page                           |
   |                       |           |         | direction.                                   |
   |                       |           |         |                                              |
   |                       |           |         | The value can be **true**                    |
   |                       |           |         | or **false**, and the                        |
   |                       |           |         | default value is **false**.                  |
   |                       |           |         |                                              |
   |                       |           |         | The last page in the list                    |
   |                       |           |         | requested with                               |
   |                       |           |         | **page_reverse** set to                      |
   |                       |           |         | **false** will not contain                   |
   |                       |           |         | the "next" link, and the                     |
   |                       |           |         | last page in the list                        |
   |                       |           |         | requested with                               |
   |                       |           |         | **page_reverse** set to                      |
   |                       |           |         | **true** will not contain                    |
   |                       |           |         | the "previous" link.                         |
   |                       |           |         |                                              |
   |                       |           |         | This parameter must be used                  |
   |                       |           |         | together with **limit**.                     |
   +-----------------------+-----------+---------+----------------------------------------------+
   | name                  | No        | Array   | Specifies the backend                        |
   |                       |           |         | server name.                                 |
   |                       |           |         |                                              |
   |                       |           |         | Multiple names can be                        |
   |                       |           |         | queried in the format of                     |
   |                       |           |         | *name=xxx&name=xxx*.                         |
   +-----------------------+-----------+---------+----------------------------------------------+
   | weight                | No        | Array   | Specifies the weight of the                  |
   |                       |           |         | backend server.                              |
   |                       |           |         |                                              |
   |                       |           |         | Requests are routed to                       |
   |                       |           |         | backend servers in the same                  |
   |                       |           |         | backend server group based                   |
   |                       |           |         | on their weights. If the                     |
   |                       |           |         | weight is 0, the backend                     |
   |                       |           |         | server will not accept new                   |
   |                       |           |         | requests.                                    |
   |                       |           |         |                                              |
   |                       |           |         | This parameter will not                      |
   |                       |           |         | take effect when                             |
   |                       |           |         | **lb_algorithm** is set to                   |
   |                       |           |         | **SOURCE_IP** for the                        |
   |                       |           |         | backend server group that                    |
   |                       |           |         | contains the backend                         |
   |                       |           |         | server.                                      |
   |                       |           |         |                                              |
   |                       |           |         | Multiple weights can be                      |
   |                       |           |         | queried in the format of                     |
   |                       |           |         | *weight=xxx&weight=xxx*.                     |
   +-----------------------+-----------+---------+----------------------------------------------+
   | admin_state_up        | No        | Boolean | Specifies the                                |
   |                       |           |         | administrative status of                     |
   |                       |           |         | the backend server.                          |
   |                       |           |         |                                              |
   |                       |           |         | Although this parameter can                  |
   |                       |           |         | be used in the APIs for                      |
   |                       |           |         | creating and updating                        |
   |                       |           |         | backend servers, its actual                  |
   |                       |           |         | value depends on whether                     |
   |                       |           |         | cloud servers that serve as                  |
   |                       |           |         | the backend servers exist.                   |
   |                       |           |         | If cloud servers exist, the                  |
   |                       |           |         | value is **true**.                           |
   |                       |           |         | Otherwise, the value is                      |
   |                       |           |         | **false**.                                   |
   +-----------------------+-----------+---------+----------------------------------------------+
   | subnet_cidr_id        | No        | Array   | Specifies the ID of the                      |
   |                       |           |         | subnet where the backend                     |
   |                       |           |         | server works.                                |
   |                       |           |         |                                              |
   |                       |           |         | This subnet must be in the                   |
   |                       |           |         | same VPC as the subnet of                    |
   |                       |           |         | the load balancer with                       |
   |                       |           |         | which the backend server is                  |
   |                       |           |         | associated. Only IPv4                        |
   |                       |           |         | subnets are supported.                       |
   |                       |           |         |                                              |
   |                       |           |         | Multiple IDs can be queried                  |
   |                       |           |         | in the format of                             |
   |                       |           |         | *subnet_cidr_id=xxx&subnet_cidr_id=xxx*.     |
   +-----------------------+-----------+---------+----------------------------------------------+
   | address               | No        | Array   | Specifies the IP address                     |
   |                       |           |         | bound to the backend                         |
   |                       |           |         | server.                                      |
   |                       |           |         |                                              |
   |                       |           |         | -  The IP address must be                    |
   |                       |           |         |    in the subnet specified                   |
   |                       |           |         |    by **subnet_cidr_id**,                    |
   |                       |           |         |    for example,                              |
   |                       |           |         |    192.168.3.11.                             |
   |                       |           |         |                                              |
   |                       |           |         | -  The IP address can be                     |
   |                       |           |         |    used only by the primary                  |
   |                       |           |         |    NIC.                                      |
   |                       |           |         |                                              |
   |                       |           |         | Multiple IP addresses can                    |
   |                       |           |         | be queried in the format of                  |
   |                       |           |         | *address=xxx&address=xxx*.                   |
   +-----------------------+-----------+---------+----------------------------------------------+
   | protocol_port         | No        | Array   | Specifies the port used by                   |
   |                       |           |         | the backend server.                          |
   |                       |           |         |                                              |
   |                       |           |         | Multiple ports can be                        |
   |                       |           |         | queried in the format of                     |
   |                       |           |         | *protocol_p                                  |
   |                       |           |         | ort=xxx&protocol_port=xxx*.                  |
   +-----------------------+-----------+---------+----------------------------------------------+
   | id                    | No        | Array   | Specifies the backend                        |
   |                       |           |         | server ID.                                   |
   |                       |           |         |                                              |
   |                       |           |         | Multiple IDs can be queried                  |
   |                       |           |         | in the format of                             |
   |                       |           |         | *id=xxx&id=xxx*.                             |
   +-----------------------+-----------+---------+----------------------------------------------+
   | operating_status      | No        | Array   | Specifies the operating                      |
   |                       |           |         | status of the backend                        |
   |                       |           |         | server. The value can be                     |
   |                       |           |         | one of the following:                        |
   |                       |           |         |                                              |
   |                       |           |         | - **ONLINE**: The backend                    |
   |                       |           |         |   server is running                          |
   |                       |           |         |   normally.                                  |
   |                       |           |         |                                              |
   |                       |           |         | - **NO_MONITOR**: No                         |
   |                       |           |         |   health check is                            |
   |                       |           |         |   configured for the                         |
   |                       |           |         |   backend server group to                    |
   |                       |           |         |   which the backend server                   |
   |                       |           |         |   belongs.                                   |
   |                       |           |         |                                              |
   |                       |           |         | - **OFFLINE**: The cloud                     |
   |                       |           |         |   server used as the                         |
   |                       |           |         |   backend server is                          |
   |                       |           |         |   stopped or does not                        |
   |                       |           |         |   exist.                                     |
   |                       |           |         |                                              |
   |                       |           |         | Multiple operating statuses                  |
   |                       |           |         | can be queried in the                        |
   |                       |           |         | format of                                    |
   |                       |           |         | *operating_status=xxx&operating_status=xxx*. |
   +-----------------------+-----------+---------+----------------------------------------------+
   | enterprise_project_id | No        | Array   | Specifies the enterprise                     |
   |                       |           |         | project ID.                                  |
   |                       |           |         |                                              |
   |                       |           |         | -  If this parameter is not                  |
   |                       |           |         |    passed, resources in the                  |
   |                       |           |         |    default enterprise                        |
   |                       |           |         |    project are queried, and                  |
   |                       |           |         |    authentication is                         |
   |                       |           |         |    performed based on the                    |
   |                       |           |         |    default enterprise                        |
   |                       |           |         |    project.                                  |
   |                       |           |         |                                              |
   |                       |           |         | -  If this parameter is                      |
   |                       |           |         |    passed, its value can be                  |
   |                       |           |         |    the ID of an existing                     |
   |                       |           |         |    enterprise project or                     |
   |                       |           |         |    **all_granted_eps**.                      |
   |                       |           |         |                                              |
   |                       |           |         | If the value is a specific                   |
   |                       |           |         | ID, resources in the                         |
   |                       |           |         | specific enterprise project                  |
   |                       |           |         | are required. If the value                   |
   |                       |           |         | is **all_granted_eps**,                      |
   |                       |           |         | resources in all enterprise                  |
   |                       |           |         | projects are queried.                        |
   |                       |           |         |                                              |
   |                       |           |         | Multiple IDs can be queried                  |
   |                       |           |         | in the format of                             |
   |                       |           |         | *enterprise_project_id=xxx&                  |
   |                       |           |         | enterprise_project_id=xxx*.                  |
   |                       |           |         |                                              |
   |                       |           |         | This parameter is                            |
   |                       |           |         | unsupported. Please do not                   |
   |                       |           |         | use it.                                      |
   +-----------------------+-----------+---------+----------------------------------------------+
   | ip_version            | No        | String  | Specifies the IP version.                    |
   |                       |           |         | The value can be **4**                       |
   |                       |           |         | (IPv4) or **6** (IPv6).                      |
   +-----------------------+-----------+---------+----------------------------------------------+

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 3** Request header parameters

   ============ ========= ====== ================================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ================================================
   X-Auth-Token Yes       String Specifies the token used for IAM authentication.
   ============ ========= ====== ================================================

Response Parameters
^^^^^^^^^^^^^^^^^^^

**Status code: 200**

.. table:: **Table 4** Response body parameters

   +------------+-------------------------------+----------------------------------------+
   | Parameter  | Type                          | Description                            |
   +============+===============================+========================================+
   | request_id | String                        | Specifies the request ID. The value is |
   |            |                               | automatically generated.               |
   +------------+-------------------------------+----------------------------------------+
   | page_info  | :ref:`dml_pi` object          | Shows pagination information.          |
   +------------+-------------------------------+----------------------------------------+
   | members    | Array of :ref:`dml_m` objects | Lists the backend servers.             |
   +------------+-------------------------------+----------------------------------------+

.. _dml_pi:
.. table:: **Table 5** PageInfo

   +-----------------+---------+----------------------------------------------------------------------------------------+
   | Parameter       | Type    | Description                                                                            |
   +=================+=========+========================================================================================+
   | previous_marker | String  | Specifies the ID of the first record in the pagination query result. This parameter    |
   |                 |         | will not be returned if no query result is returned.                                   |
   +-----------------+---------+----------------------------------------------------------------------------------------+
   | next_marker     | String  | Marks the start record on the next page in the pagination query result. This parameter |
   |                 |         | will not be returned if there is no next page.                                         |
   +-----------------+---------+----------------------------------------------------------------------------------------+
   | current_count   | Integer | Specifies the number of records.                                                       |
   +-----------------+---------+----------------------------------------------------------------------------------------+

.. _dml_m:
.. table:: **Table 6** Member

   +------------------+---------+---------------------------------------+
   | Parameter        | Type    | Description                           |
   +==================+=========+=======================================+
   | address          | String  | Specifies the IP address of the       |
   |                  |         | backend server.                       |
   |                  |         |                                       |
   |                  |         | The IP address must be in the subnet  |
   |                  |         | specified by **subnet_cidr_id**, for  |
   |                  |         | example, 192.168.3.11. The IP address |
   |                  |         | can only be the IP address of the     |
   |                  |         | primary NIC.                          |
   +------------------+---------+---------------------------------------+
   | admin_state_up   | Boolean | Specifies the administrative status   |
   |                  |         | of the backend server.                |
   |                  |         |                                       |
   |                  |         | Although this parameter can be used   |
   |                  |         | in the APIs for creating and updating |
   |                  |         | backend servers, its actual value     |
   |                  |         | depends on whether cloud servers      |
   |                  |         | exist. If cloud servers exist, the    |
   |                  |         | value is **true**. Otherwise, the     |
   |                  |         | value is **false**.                   |
   |                  |         |                                       |
   |                  |         | Default: **true**                     |
   +------------------+---------+---------------------------------------+
   | id               | String  | Specifies the backend server ID.      |
   +------------------+---------+---------------------------------------+
   | name             | String  | Specifies the backend server name.    |
   +------------------+---------+---------------------------------------+
   | operating_status | String  | Specifies the operating status of the |
   |                  |         | backend server. The value can be one  |
   |                  |         | of the following:                     |
   |                  |         |                                       |
   |                  |         | -  **ONLINE**: The backend server is  |
   |                  |         |    running normally.                  |
   |                  |         |                                       |
   |                  |         | -  **NO_MONITOR**: No health check is |
   |                  |         |    configured for the backend server  |
   |                  |         |    group to which the backend server  |
   |                  |         |    belongs.                           |
   |                  |         |                                       |
   |                  |         | -  **OFFLINE**: The cloud server used |
   |                  |         |    as the backend server is stopped   |
   |                  |         |    or does not exist.                 |
   +------------------+---------+---------------------------------------+
   | project_id       | String  | Specifies the project ID.             |
   +------------------+---------+---------------------------------------+
   | protocol_port    | Integer | Specifies the port used by the        |
   |                  |         | backend server to receive requests.   |
   |                  |         |                                       |
   |                  |         | Minimum: **1**                        |
   |                  |         |                                       |
   |                  |         | Maximum: **65535**                    |
   +------------------+---------+---------------------------------------+
   | subnet_cidr_id   | String  | Specifies the ID of the subnet where  |
   |                  |         | the backend server works. This subnet |
   |                  |         | must be in the VPC as the subnet of   |
   |                  |         | the load balancer associated with the |
   |                  |         | backend server. Only IPv4 subnets are |
   |                  |         | supported. If the value is left       |
   |                  |         | blank, the backend server is not in   |
   |                  |         | the load balancer's VPC.              |
   +------------------+---------+---------------------------------------+
   | weight           | Integer | Specifies the weight of the backend   |
   |                  |         | server.                               |
   |                  |         |                                       |
   |                  |         | Requests are routed to backend        |
   |                  |         | servers in the same backend server    |
   |                  |         | group based on their weights.         |
   |                  |         |                                       |
   |                  |         | If the weight is 0, the backend       |
   |                  |         | server will not accept new requests.  |
   |                  |         |                                       |
   |                  |         | This parameter is invalid when        |
   |                  |         | **lb_algorithm** is set to            |
   |                  |         | **SOURCE_IP** for the backend server  |
   |                  |         | group that contains the backend       |
   |                  |         | server.                               |
   |                  |         |                                       |
   |                  |         | Minimum: **0**                        |
   |                  |         |                                       |
   |                  |         | Maximum: **100**                      |
   |                  |         |                                       |
   |                  |         | Default: **1**                        |
   +------------------+---------+---------------------------------------+
   | ip_version       | String  | This is a read-only attribute, which  |
   |                  |         | is automatically generated based on   |
   |                  |         | the **address** parameter. The value  |
   |                  |         | can be **v4** or **v6**.              |
   |                  |         |                                       |
   |                  |         | Default: **v4**                       |
   +------------------+---------+---------------------------------------+

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   GET

   https://{elb_endpoint}/v3/{project_id}/elb/pools/36ce7086-a496-4666-9064-5ba0e6840c75/members

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 200**

Successful request.

.. code::

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
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
200         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Viewing Details of a Backend Server
===================================

Function
^^^^^^^^

This API is used to view details of a backend server.

URI
^^^

GET /v3/{project_id}/elb/pools/{pool_id}/members/{member_id}

.. table:: **Table 1** Path parameters

   ========== ========= ====== =============================================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =============================================
   project_id Yes       String Specifies the project ID.
   pool_id    Yes       String Specifies the ID of the backend server group.
   member_id  Yes       String Specifies the backend server ID.
   ========== ========= ====== =============================================

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 2** Request header parameters

   ============ ========= ====== ================================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ================================================
   X-Auth-Token Yes       String Specifies the token used for IAM authentication.
   ============ ========= ====== ================================================

Response Parameters
^^^^^^^^^^^^^^^^^^^

**Status code: 200**

.. table:: **Table 3** Response body parameters

   +------------+---------------------+----------------------------------------+
   | Parameter  | Type                | Description                            |
   +============+=====================+========================================+
   | request_id | String              | Specifies the request ID. The value is |
   |            |                     | automatically generated.               |
   +------------+---------------------+----------------------------------------+
   | member     | :ref:`dms_m` object | Specifies the backend server.          |
   +------------+---------------------+----------------------------------------+

.. _dms_m:
.. table:: **Table 4** Member

   +------------------+---------+---------------------------------------+
   | Parameter        | Type    | Description                           |
   +==================+=========+=======================================+
   | address          | String  | Specifies the IP address of the       |
   |                  |         | backend server.                       |
   |                  |         |                                       |
   |                  |         | The IP address must be in the subnet  |
   |                  |         | specified by **subnet_cidr_id**, for  |
   |                  |         | example, 192.168.3.11. The IP address |
   |                  |         | can only be the IP address of the     |
   |                  |         | primary NIC.                          |
   +------------------+---------+---------------------------------------+
   | admin_state_up   | Boolean | Specifies the administrative status   |
   |                  |         | of the backend server.                |
   |                  |         |                                       |
   |                  |         | Although this parameter can be used   |
   |                  |         | in the APIs for creating and updating |
   |                  |         | backend servers, its actual value     |
   |                  |         | depends on whether cloud servers      |
   |                  |         | exist. If cloud servers exist, the    |
   |                  |         | value is **true**. Otherwise, the     |
   |                  |         | value is **false**.                   |
   |                  |         |                                       |
   |                  |         | Default: **true**                     |
   +------------------+---------+---------------------------------------+
   | id               | String  | Specifies the backend server ID.      |
   +------------------+---------+---------------------------------------+
   | name             | String  | Specifies the backend server name.    |
   +------------------+---------+---------------------------------------+
   | operating_status | String  | Specifies the operating status of the |
   |                  |         | backend server. The value can be one  |
   |                  |         | of the following:                     |
   |                  |         |                                       |
   |                  |         | -  **ONLINE**: The backend server is  |
   |                  |         |    running normally.                  |
   |                  |         |                                       |
   |                  |         | -  **NO_MONITOR**: No health check is |
   |                  |         |    configured for the backend server  |
   |                  |         |    group to which the backend server  |
   |                  |         |    belongs.                           |
   |                  |         |                                       |
   |                  |         | -  **OFFLINE**: The cloud server used |
   |                  |         |    as the backend server is stopped   |
   |                  |         |    or does not exist.                 |
   +------------------+---------+---------------------------------------+
   | project_id       | String  | Specifies the project ID.             |
   +------------------+---------+---------------------------------------+
   | protocol_port    | Integer | Specifies the port used by the        |
   |                  |         | backend server to receive requests.   |
   |                  |         |                                       |
   |                  |         | Minimum: **1**                        |
   |                  |         |                                       |
   |                  |         | Maximum: **65535**                    |
   +------------------+---------+---------------------------------------+
   | subnet_cidr_id   | String  | Specifies the ID of the subnet where  |
   |                  |         | the backend server works. This subnet |
   |                  |         | must be in the VPC as the subnet of   |
   |                  |         | the load balancer associated with the |
   |                  |         | backend server. Only IPv4 subnets are |
   |                  |         | supported. If the value is left       |
   |                  |         | blank, the backend server is not in   |
   |                  |         | the load balancer's VPC.              |
   +------------------+---------+---------------------------------------+
   | weight           | Integer | Specifies the weight of the backend   |
   |                  |         | server.                               |
   |                  |         |                                       |
   |                  |         | Requests are routed to backend        |
   |                  |         | servers in the same backend server    |
   |                  |         | group based on their weights.         |
   |                  |         |                                       |
   |                  |         | If the weight is 0, the backend       |
   |                  |         | server will not accept new requests.  |
   |                  |         |                                       |
   |                  |         | This parameter is invalid when        |
   |                  |         | **lb_algorithm** is set to            |
   |                  |         | **SOURCE_IP** for the backend server  |
   |                  |         | group that contains the backend       |
   |                  |         | server.                               |
   |                  |         |                                       |
   |                  |         | Minimum: **0**                        |
   |                  |         |                                       |
   |                  |         | Maximum: **100**                      |
   |                  |         |                                       |
   |                  |         | Default: **1**                        |
   +------------------+---------+---------------------------------------+
   | ip_version       | String  | This is a read-only attribute, which  |
   |                  |         | is automatically generated based on   |
   |                  |         | the **address** parameter. The value  |
   |                  |         | can be **v4** or **v6**.              |
   |                  |         |                                       |
   |                  |         | Default: **v4**                       |
   +------------------+---------+---------------------------------------+

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   GET

   https://{elb_endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/pools/36ce7086-a496-4666-9064-5ba0e6840c75/members/1923923e-fe8a-484f-bdbc-e11559b1f48f

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 200**

Successful request.

.. code::

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
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
200         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Updating a Backend Server
=========================

Function
^^^^^^^^

The backend server can be updated only when the provisioning status of the
associated load balancer is **ACTIVE**.

URI
^^^

PUT /v3/{project_id}/elb/pools/{pool_id}/members/{member_id}

.. table:: **Table 1** Path parameters

   ========== ========= ====== =============================================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =============================================
   member_id  Yes       String Specifies the backend server ID.
   pool_id    Yes       String Specifies the ID of the backend server group.
   project_id Yes       String Specifies the project ID.
   ========== ========= ====== =============================================

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 2** Request header parameters

   ============ ========= ====== ================================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ================================================
   X-Auth-Token Yes       String Specifies the token used for IAM authentication.
   ============ ========= ====== ================================================

.. table:: **Table 3** Request body parameters

   +-----------+-----------+----------------------+---------------------------------------------+
   | Parameter | Mandatory | Type                 | Description                                 |
   +===========+===========+======================+=============================================+
   | member    | Yes       | :ref:`dmu_mo` object | Specifies request parameters for updating a |
   |           |           |                      | backend server.                             |
   +-----------+-----------+----------------------+---------------------------------------------+

.. _dmu_mo:
.. table:: **Table 4** UpdateMemberOption

   +----------------+-----------+---------+-----------------------------+
   | Parameter      | Mandatory | Type    | Description                 |
   +================+===========+=========+=============================+
   | admin_state_up | No        | Boolean | Specifies the               |
   |                |           |         | administrative status of    |
   |                |           |         | the backend server.         |
   |                |           |         |                             |
   |                |           |         | Although this parameter can |
   |                |           |         | be used in the APIs for     |
   |                |           |         | creating and updating       |
   |                |           |         | backend servers, its actual |
   |                |           |         | value depends on whether    |
   |                |           |         | cloud servers exist. If     |
   |                |           |         | cloud servers exist, the    |
   |                |           |         | value is **true**.          |
   |                |           |         | Otherwise, the value is     |
   |                |           |         | **false**.                  |
   +----------------+-----------+---------+-----------------------------+
   | name           | No        | String  | Specifies the backend       |
   |                |           |         | server name.                |
   |                |           |         |                             |
   |                |           |         | Minimum: **0**              |
   |                |           |         |                             |
   |                |           |         | Maximum: **255**            |
   +----------------+-----------+---------+-----------------------------+
   | weight         | No        | Integer | Specifies the weight of the |
   |                |           |         | backend server.             |
   |                |           |         |                             |
   |                |           |         | Requests are routed to      |
   |                |           |         | backend servers in the same |
   |                |           |         | backend server group based  |
   |                |           |         | on their weights. If the    |
   |                |           |         | weight is 0, the backend    |
   |                |           |         | server will not accept new  |
   |                |           |         | requests.                   |
   |                |           |         |                             |
   |                |           |         | This parameter is invalid   |
   |                |           |         | when **lb_algorithm** is    |
   |                |           |         | set to **SOURCE_IP** for    |
   |                |           |         | the backend server group    |
   |                |           |         | that contains the backend   |
   |                |           |         | server.                     |
   |                |           |         |                             |
   |                |           |         | Minimum: **0**              |
   |                |           |         |                             |
   |                |           |         | Maximum: **100**            |
   |                |           |         |                             |
   |                |           |         | Default: **1**              |
   +----------------+-----------+---------+-----------------------------+

Response Parameters
^^^^^^^^^^^^^^^^^^^

**Status code: 200**

.. table:: **Table 5** Response body parameters

   +------------+---------------------+----------------------------------------+
   | Parameter  | Type                | Description                            |
   +============+=====================+========================================+
   | request_id | String              | Specifies the request ID. The value is |
   |            |                     | automatically generated.               |
   +------------+---------------------+----------------------------------------+
   | member     | :ref:`dmu_m` object | Specifies the backend server.          |
   +------------+---------------------+----------------------------------------+

.. _dmu_m:
.. table:: **Table 6** Member

   +------------------+---------+---------------------------------------+
   | Parameter        | Type    | Description                           |
   +==================+=========+=======================================+
   | address          | String  | Specifies the IP address of the       |
   |                  |         | backend server.                       |
   |                  |         |                                       |
   |                  |         | The IP address must be in the subnet  |
   |                  |         | specified by **subnet_cidr_id**, for  |
   |                  |         | example, 192.168.3.11. The IP address |
   |                  |         | can only be the IP address of the     |
   |                  |         | primary NIC.                          |
   +------------------+---------+---------------------------------------+
   | admin_state_up   | Boolean | Specifies the administrative status   |
   |                  |         | of the backend server.                |
   |                  |         |                                       |
   |                  |         | Although this parameter can be used   |
   |                  |         | in the APIs for creating and updating |
   |                  |         | backend servers, its actual value     |
   |                  |         | depends on whether cloud servers      |
   |                  |         | exist. If cloud servers exist, the    |
   |                  |         | value is **true**. Otherwise, the     |
   |                  |         | value is **false**.                   |
   |                  |         |                                       |
   |                  |         | Default: **true**                     |
   +------------------+---------+---------------------------------------+
   | id               | String  | Specifies the backend server ID.      |
   +------------------+---------+---------------------------------------+
   | name             | String  | Specifies the backend server name.    |
   +------------------+---------+---------------------------------------+
   | operating_status | String  | Specifies the operating status of the |
   |                  |         | backend server. The value can be one  |
   |                  |         | of the following:                     |
   |                  |         |                                       |
   |                  |         | -  **ONLINE**: The backend server is  |
   |                  |         |    running normally.                  |
   |                  |         |                                       |
   |                  |         | -  **NO_MONITOR**: No health check is |
   |                  |         |    configured for the backend server  |
   |                  |         |    group to which the backend server  |
   |                  |         |    belongs.                           |
   |                  |         |                                       |
   |                  |         | -  **OFFLINE**: The cloud server used |
   |                  |         |    as the backend server is stopped   |
   |                  |         |    or does not exist.                 |
   +------------------+---------+---------------------------------------+
   | project_id       | String  | Specifies the project ID.             |
   +------------------+---------+---------------------------------------+
   | protocol_port    | Integer | Specifies the port used by the        |
   |                  |         | backend server to receive requests.   |
   |                  |         |                                       |
   |                  |         | Minimum: **1**                        |
   |                  |         |                                       |
   |                  |         | Maximum: **65535**                    |
   +------------------+---------+---------------------------------------+
   | subnet_cidr_id   | String  | Specifies the ID of the subnet where  |
   |                  |         | the backend server works. This subnet |
   |                  |         | must be in the VPC as the subnet of   |
   |                  |         | the load balancer associated with the |
   |                  |         | backend server. Only IPv4 subnets are |
   |                  |         | supported. If the value is left       |
   |                  |         | blank, the backend server is not in   |
   |                  |         | the load balancer's VPC.              |
   +------------------+---------+---------------------------------------+
   | weight           | Integer | Specifies the weight of the backend   |
   |                  |         | server.                               |
   |                  |         |                                       |
   |                  |         | Requests are routed to backend        |
   |                  |         | servers in the same backend server    |
   |                  |         | group based on their weights.         |
   |                  |         |                                       |
   |                  |         | If the weight is 0, the backend       |
   |                  |         | server will not accept new requests.  |
   |                  |         |                                       |
   |                  |         | This parameter is invalid when        |
   |                  |         | **lb_algorithm** is set to            |
   |                  |         | **SOURCE_IP** for the backend server  |
   |                  |         | group that contains the backend       |
   |                  |         | server.                               |
   |                  |         |                                       |
   |                  |         | Minimum: **0**                        |
   |                  |         |                                       |
   |                  |         | Maximum: **100**                      |
   |                  |         |                                       |
   |                  |         | Default: **1**                        |
   +------------------+---------+---------------------------------------+
   | ip_version       | String  | This is a read-only attribute, which  |
   |                  |         | is automatically generated based on   |
   |                  |         | the **address** parameter. The value  |
   |                  |         | can be **v4** or **v6**.              |
   |                  |         |                                       |
   |                  |         | Default: **v4**                       |
   +------------------+---------+---------------------------------------+

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   PUT

   https://{elb_endpoint}/v3/9a3fff0d03c428eac3678da6a7d0f24/elb/pools/36ce7086-a496-4666-9064-5ba0e6840c75/members/1923923e-fe8a-484f-bdbc-e11559b1f48f

   {
     "member" : {
       "name" : "My member",
       "weight" : 10
     }
   }

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 200**

Successful request.

.. code::

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
     "request_id" : "e7b569d4-15ad-494d-9dd9-8cd740eef8f6"
   }

Status Codes
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
200         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Removing a Backend Server
=========================

Function
^^^^^^^^

This API is used to remove a backend server.

Constraints
^^^^^^^^^^^

When you remove backend servers, note the following:

-  After you remove a backend server, new connections to this server will not
   be established. However, persistent connections that have been established
   will be maintained.

-  The last backend server cannot be removed. If it is removed, 403 will be
   returned.

URI
^^^

DELETE /v3/{project_id}/elb/pools/{pool_id}/members/{member_id}

.. table:: **Table 1** Path parameters

   ========== ========= ====== =============================================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =============================================
   project_id Yes       String Specifies the project ID.
   pool_id    Yes       String Specifies the ID of the backend server group.
   member_id  Yes       String Specifies the backend server ID.
   ========== ========= ====== =============================================

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 2** Request header parameters

   ============ ========= ====== ================================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ================================================
   X-Auth-Token Yes       String Specifies the token used for IAM authentication.
   ============ ========= ====== ================================================

Response Parameters
^^^^^^^^^^^^^^^^^^^

None

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   DELETE

   https://{elb_endpoint}/v3/9a3fff0d03c428eac3678da6a7d0f24/elb/pools/36ce7086-a496-4666-9064-5ba0e6840c75/members/1923923e-fe8a-484f-bdbc-e11559b1f48f

Example Responses
^^^^^^^^^^^^^^^^^

None

Status Codes
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
204         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.
