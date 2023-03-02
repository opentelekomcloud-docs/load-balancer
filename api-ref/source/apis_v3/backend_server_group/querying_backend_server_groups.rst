:original_name: ListPools.html

.. _ListPools:

Querying Backend Server Groups
==============================

Function
--------

This API is used to query all backend server groups.

Constraints
-----------

This API has the following constraints:

-  Parameters **marker**, **limit**, and **page_reverse** are used for pagination query.

-  Parameters **marker** and **page_reverse** take effect only when they are used together with parameter **limit**.

URI
---

GET /v3/{project_id}/elb/pools

.. table:: **Table 1** Path Parameters

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
   ========== ========= ====== =========================

.. table:: **Table 2** Query Parameters

   +-----------------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter                         | Mandatory       | Type            | Description                                                                                                                                                                                                                      |
   +===================================+=================+=================+==================================================================================================================================================================================================================================+
   | marker                            | No              | String          | Specifies the ID of the last record on the previous page.                                                                                                                                                                        |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | Note:                                                                                                                                                                                                                            |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | -  This parameter must be used together with **limit**.                                                                                                                                                                          |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | -  If this parameter is not specified, the first page will be queried.                                                                                                                                                           |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | -  This parameter cannot be left blank or set to an invalid ID.                                                                                                                                                                  |
   +-----------------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | limit                             | No              | Integer         | Specifies the number of records on each page.                                                                                                                                                                                    |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | Minimum: **0**                                                                                                                                                                                                                   |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | Maximum: **2000**                                                                                                                                                                                                                |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | Default: **2000**                                                                                                                                                                                                                |
   +-----------------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | page_reverse                      | No              | Boolean         | Specifies whether to use reverse query. Values:                                                                                                                                                                                  |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | -  **true**: Query the previous page.                                                                                                                                                                                            |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | -  **false** (default): Query the next page.                                                                                                                                                                                     |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | Note:                                                                                                                                                                                                                            |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | -  This parameter must be used together with **limit**.                                                                                                                                                                          |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | -  If **page_reverse** is set to **true** and you want to query the previous page, set the value of **marker** to the value of **previous_marker**.                                                                              |
   +-----------------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | description                       | No              | Array           | Provides supplementary information about the backend server group.                                                                                                                                                               |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | Multiple descriptions can be queried in the format of *description=xxx&description=xxx*.                                                                                                                                         |
   +-----------------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up                    | No              | Boolean         | Specifies the administrative status of the backend server group.                                                                                                                                                                 |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | This parameter is unsupported. Please do not use it.                                                                                                                                                                             |
   +-----------------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | healthmonitor_id                  | No              | Array           | Specifies the ID of the health check configured for the backend server group.                                                                                                                                                    |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | Multiple IDs can be queried in the format of *healthmonitor_id=xxx&healthmonitor_id=xxx*.                                                                                                                                        |
   +-----------------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | id                                | No              | Array           | Specifies the ID of the backend server group.                                                                                                                                                                                    |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | Multiple IDs can be queried in the format of *id=xxx&id=xxx*.                                                                                                                                                                    |
   +-----------------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                              | No              | Array           | Specifies the backend server group name.                                                                                                                                                                                         |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | Multiple names can be queried in the format of *name=xxx&name=xxx*.                                                                                                                                                              |
   +-----------------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | loadbalancer_id                   | No              | Array           | Specifies the ID of the load balancer with which the backend server group is associated.                                                                                                                                         |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | Multiple IDs can be queried in the format of *loadbalancer_id=xxx&loadbalancer_id=xxx*.                                                                                                                                          |
   +-----------------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | protocol                          | No              | Array           | Specifies the protocol used by the backend server group to receive requests from the load balancer. The value can be **TCP**, **UDP**, **HTTP**, **HTTPS**, or **QUIC**.                                                         |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | Multiple protocols can be queried in the format of *protocol=xxx&protocol=xxx*.                                                                                                                                                  |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | QUIC protocol is not supported in **eu-nl** region.                                                                                                                                                                              |
   +-----------------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | lb_algorithm                      | No              | Array           | Specifies the load balancing algorithm used by the load balancer to route requests to backend servers in the associated backend server group.                                                                                    |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | The value can be one of the following:                                                                                                                                                                                           |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | -  **ROUND_ROBIN**: weighted round robin                                                                                                                                                                                         |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | -  **LEAST_CONNECTIONS**: weighted least connections                                                                                                                                                                             |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | -  **SOURCE_IP**: source IP hash                                                                                                                                                                                                 |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | -  **QUIC_CID**: connection ID                                                                                                                                                                                                   |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | Multiple algorithms can be queried in the format of *lb_algorithm=xxx&lb_algorithm=xxx*.                                                                                                                                         |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | QUIC_CID is not supported in **eu-nl** region.                                                                                                                                                                                   |
   +-----------------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | enterprise_project_id             | No              | Array           | Specifies the enterprise project ID.                                                                                                                                                                                             |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | -  If this parameter is not passed, resources in the default enterprise project are queried, and authentication is performed based on the default enterprise project.                                                            |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | -  If this parameter is passed, its value can be the ID of an existing enterprise project (resources in the specific enterprise project are required) or **all_granted_eps** (resources in all enterprise projects are queried). |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | Multiple IDs can be queried in the format of *enterprise_project_id=xxx&enterprise_project_id=xxx*.                                                                                                                              |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | This parameter is unsupported. Please do not use it.                                                                                                                                                                             |
   +-----------------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | ip_version                        | No              | Array           | Specifies the IP address version supported by the backend server group.                                                                                                                                                          |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | Multiple versions can be queried in the format of *ip_version=xxx&ip_version=xxx*.                                                                                                                                               |
   +-----------------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | member_address                    | No              | Array           | Specifies the private IP address bound to the backend server. This is a query parameter and will not be included in the response.                                                                                                |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | Multiple IP addresses can be queried in the format of *member_address=xxx&member_address=xxx*.                                                                                                                                   |
   +-----------------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | member_device_id                  | No              | Array           | Specifies the ID of the cloud server that serves as a backend server. This parameter is used only as a query condition and is not included in the response.                                                                      |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | Multiple IDs can be queried in the format of *member_device_id=xxx&member_device_id=xxx*.                                                                                                                                        |
   +-----------------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | member_deletion_protection_enable | No              | Boolean         | Specifies whether to enable removal protection on backend servers.                                                                                                                                                               |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | -  **true**: Enable removal protection.                                                                                                                                                                                          |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | -  **false**: Disable removal protection.                                                                                                                                                                                        |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | All backend servers will be queried if this parameter is not passed.                                                                                                                                                             |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | This parameter is not available in **eu-nl** region. Please do not use it.                                                                                                                                                       |
   +-----------------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | listener_id                       | No              | Array           | Specifies the IDs of the associated listeners, including the listeners associated through forwarding policies.                                                                                                                   |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | Multiple IDs can be queried in the format of *listener_id=xxx&listener_id=xxx*.                                                                                                                                                  |
   +-----------------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | member_instance_id                | No              | Array           | Specifies the backend server ID. This parameter is used only as a query condition and is not included in the response. Multiple IDs can be queried in the format of *member_instance_id=xxx&member_instance_id=xxx*.             |
   +-----------------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | vpc_id                            | No              | Array           | Specifies the ID of the VPC where the backend server group works.                                                                                                                                                                |
   +-----------------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | type                              | No              | Array           | Specifies the type of the backend server group.                                                                                                                                                                                  |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | Values:                                                                                                                                                                                                                          |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | -  **instance**: Any type of backend servers can be added. **vpc_id** is mandatory.                                                                                                                                              |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | -  **ip**: Only cross-VPC backend servers can be added. **vpc_id** cannot be specified.                                                                                                                                          |
   |                                   |                 |                 |                                                                                                                                                                                                                                  |
   |                                   |                 |                 | -  **""**: Any type of backend servers can be added.                                                                                                                                                                             |
   +-----------------------------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

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

   +------------+---------------------------------------------------------+-----------------------------------------------------------------+
   | Parameter  | Type                                                    | Description                                                     |
   +============+=========================================================+=================================================================+
   | request_id | String                                                  | Specifies the request ID. The value is automatically generated. |
   +------------+---------------------------------------------------------+-----------------------------------------------------------------+
   | page_info  | :ref:`PageInfo <listpools__response_pageinfo>` object   | Shows pagination information.                                   |
   +------------+---------------------------------------------------------+-----------------------------------------------------------------+
   | pools      | Array of :ref:`Pool <listpools__response_pool>` objects | Lists the backend server groups.                                |
   +------------+---------------------------------------------------------+-----------------------------------------------------------------+

.. _listpools__response_pageinfo:

.. table:: **Table 5** PageInfo

   +-----------------+---------+---------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Type    | Description                                                                                                         |
   +=================+=========+=====================================================================================================================+
   | previous_marker | String  | Specifies the ID of the first record in the pagination query result. Set this parameter to query the previous page. |
   +-----------------+---------+---------------------------------------------------------------------------------------------------------------------+
   | next_marker     | String  | Specifies the ID of the last record in the pagination query result. Set this to marker when query the next page.    |
   +-----------------+---------+---------------------------------------------------------------------------------------------------------------------+
   | current_count   | Integer | Specifies the number of records.                                                                                    |
   +-----------------+---------+---------------------------------------------------------------------------------------------------------------------+

.. _listpools__response_pool:

.. table:: **Table 6** Pool

   +-----------------------------------+-------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter                         | Type                                                                          | Description                                                                                                                                                                                                                               |
   +===================================+===============================================================================+===========================================================================================================================================================================================================================================+
   | admin_state_up                    | Boolean                                                                       | Specifies the administrative status of the backend server group. The value can only be **true**.                                                                                                                                          |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | This parameter is unsupported. Please do not use it.                                                                                                                                                                                      |
   +-----------------------------------+-------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | description                       | String                                                                        | Provides supplementary information about the backend server group.                                                                                                                                                                        |
   +-----------------------------------+-------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | healthmonitor_id                  | String                                                                        | Specifies the ID of the health check configured for the backend server group.                                                                                                                                                             |
   +-----------------------------------+-------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | id                                | String                                                                        | Specifies the backend server group ID.                                                                                                                                                                                                    |
   +-----------------------------------+-------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | lb_algorithm                      | String                                                                        | Specifies the load balancing algorithm used by the load balancer to route requests to backend servers in the associated backend server group.                                                                                             |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | The value can be one of the following:                                                                                                                                                                                                    |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | -  **ROUND_ROBIN**: weighted round robin                                                                                                                                                                                                  |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | -  **LEAST_CONNECTIONS**: weighted least connections                                                                                                                                                                                      |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | -  **SOURCE_IP**: source IP hash                                                                                                                                                                                                          |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | -  **QUIC_CID**: connection ID                                                                                                                                                                                                            |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | Note:                                                                                                                                                                                                                                     |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | -  If the value is **SOURCE_IP**, the **weight** parameter will not take effect for backend servers.                                                                                                                                      |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | -  **QUIC_CID** is supported only when the protocol of the backend server group is QUIC.                                                                                                                                                  |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | QUIC_CID is not supported in **eu-nl** region.                                                                                                                                                                                            |
   +-----------------------------------+-------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | listeners                         | Array of :ref:`ListenerRef <listpools__response_listenerref>` objects         | Specifies the IDs of the listeners with which the backend server group is associated.                                                                                                                                                     |
   +-----------------------------------+-------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | loadbalancers                     | Array of :ref:`LoadBalancerRef <listpools__response_loadbalancerref>` objects | Specifies the IDs of the load balancers with which the backend server group is associated.                                                                                                                                                |
   +-----------------------------------+-------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | members                           | Array of :ref:`MemberRef <listpools__response_memberref>` objects             | Specifies the IDs of the backend servers in the backend server group.                                                                                                                                                                     |
   +-----------------------------------+-------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                              | String                                                                        | Specifies the backend server group name.                                                                                                                                                                                                  |
   +-----------------------------------+-------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | project_id                        | String                                                                        | Specifies the project ID.                                                                                                                                                                                                                 |
   +-----------------------------------+-------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | protocol                          | String                                                                        | Specifies the protocol used by the backend server group to receive requests. The value can be **TCP**, **UDP**, **HTTP**, **HTTPS**, or **QUIC**.                                                                                         |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | -  If the listener's protocol is **UDP**, the protocol of the backend server group must be **UDP**.                                                                                                                                       |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | -  If the listener's protocol is **TCP**, the protocol of the backend server group must be **TCP**.                                                                                                                                       |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | -  If the listener's protocol is **HTTP**, the protocol of the backend server group must be **HTTP**.                                                                                                                                     |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | -  If the listener's protocol is **HTTPS**, the protocol of the backend server group can be **HTTP** or **HTTPS**.                                                                                                                        |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | -  If the listener's protocol is **TERMINATED_HTTPS**, the protocol of the backend server group must be **HTTP**.                                                                                                                         |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | -  If the backend server group protocol is **QUIC**, sticky session must be enabled with **type** set to **SOURCE_IP**.                                                                                                                   |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | QUIC protocol is not supported in **eu-nl** region.                                                                                                                                                                                       |
   +-----------------------------------+-------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | session_persistence               | :ref:`SessionPersistence <listpools__response_sessionpersistence>` object     | Specifies the sticky session.                                                                                                                                                                                                             |
   +-----------------------------------+-------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | ip_version                        | String                                                                        | Specifies the IP address version supported by the backend server group.                                                                                                                                                                   |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | IPv6 is unsupported. Only **v4** will be returned.                                                                                                                                                                                        |
   +-----------------------------------+-------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | slow_start                        | :ref:`SlowStart <listpools__response_slowstart>` object                       | Specifies slow start details. After you enable slow start, new backend servers added to the backend server group are warmed up, and the number of requests they can receive increases linearly during the configured slow start duration. |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | This parameter can be used when the protocol of the backend server group is HTTP or HTTPS. An error will be returned if the protocol is not HTTP or HTTPS. This parameter is not available in **eu-nl** region. Please do not use it.     |
   +-----------------------------------+-------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | member_deletion_protection_enable | Boolean                                                                       | Specifies whether to enable removal protection.                                                                                                                                                                                           |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | -  **true**: Enable removal protection.                                                                                                                                                                                                   |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | -  **false**: Disable removal protection.                                                                                                                                                                                                 |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | .. note::                                                                                                                                                                                                                                 |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               |    Disable removal protection for all your resources before deleting your account.                                                                                                                                                        |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | This parameter is not available in **eu-nl** region. Please do not use it.                                                                                                                                                                |
   +-----------------------------------+-------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | created_at                        | String                                                                        | Specifies the time when a backend server group was created. The format is yyyy-MM-dd'T'HH:mm:ss'Z' (UTC time).                                                                                                                            |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | This is a new field in this version, and it will not be returned for resources associated with existing dedicated load balancers and for resources associated with existing and new shared load balancers.                                |
   +-----------------------------------+-------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | updated_at                        | String                                                                        | Specifies the time when when a backend server group was updated. The format is yyyy-MM-dd'T'HH:mm:ss'Z' (UTC time).                                                                                                                       |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | This is a new field in this version, and it will not be returned for resources associated with existing dedicated load balancers and for resources associated with existing and new shared load balancers.                                |
   +-----------------------------------+-------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | vpc_id                            | String                                                                        | Specifies the ID of the VPC where the backend server group works.                                                                                                                                                                         |
   +-----------------------------------+-------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | type                              | String                                                                        | Specifies the type of the backend server group.                                                                                                                                                                                           |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | Values:                                                                                                                                                                                                                                   |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | -  **instance**: Any type of backend servers can be added. **vpc_id** is mandatory.                                                                                                                                                       |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | -  **ip**: Only cross-VPC backend servers can be added. **vpc_id** cannot be specified.                                                                                                                                                   |
   |                                   |                                                                               |                                                                                                                                                                                                                                           |
   |                                   |                                                                               | -  **""**: Any type of backend servers can be added.                                                                                                                                                                                      |
   +-----------------------------------+-------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _listpools__response_listenerref:

.. table:: **Table 7** ListenerRef

   ========= ====== ==========================
   Parameter Type   Description
   ========= ====== ==========================
   id        String Specifies the listener ID.
   ========= ====== ==========================

.. _listpools__response_loadbalancerref:

.. table:: **Table 8** LoadBalancerRef

   ========= ====== ===============================
   Parameter Type   Description
   ========= ====== ===============================
   id        String Specifies the load balancer ID.
   ========= ====== ===============================

.. _listpools__response_memberref:

.. table:: **Table 9** MemberRef

   ========= ====== ================================
   Parameter Type   Description
   ========= ====== ================================
   id        String Specifies the backend server ID.
   ========= ====== ================================

.. _listpools__response_sessionpersistence:

.. table:: **Table 10** SessionPersistence

   +-----------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                                                                              |
   +=======================+=======================+==========================================================================================================================================================================================================+
   | cookie_name           | String                | Specifies the cookie name. The value can contain only letters, digits, hyphens (-), underscores (_), and periods (.). Note: This parameter will take effect only when **type** is set to **APP_COOKIE**. |
   +-----------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | type                  | String                | Specifies the sticky session type. The value can be **SOURCE_IP**, **HTTP_COOKIE**, or **APP_COOKIE**.Note:                                                                                              |
   |                       |                       |                                                                                                                                                                                                          |
   |                       |                       | -  If the protocol of the backend server group is **TCP** or **UDP**, only **SOURCE_IP** takes effect.                                                                                                   |
   |                       |                       |                                                                                                                                                                                                          |
   |                       |                       | -  For dedicated load balancers, if the protocol of the backend server group is **HTTP** or **HTTPS**, the value can only be **HTTP_COOKIE**.                                                            |
   |                       |                       |                                                                                                                                                                                                          |
   |                       |                       | -  If the backend server group protocol is **QUIC**, sticky session must be enabled with **type** set to **SOURCE_IP**.                                                                                  |
   |                       |                       |                                                                                                                                                                                                          |
   |                       |                       | QUIC protocol is not supported in **eu-nl** region.                                                                                                                                                      |
   +-----------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | persistence_timeout   | Integer               | Specifies the stickiness duration, in minutes. This parameter will not take effect when **type** is set to **APP_COOKIE**.                                                                               |
   |                       |                       |                                                                                                                                                                                                          |
   |                       |                       | -  If the protocol of the backend server group is TCP, UDP, or QUIC, the value ranges from **1** to **60**, and the default value is **1**.                                                              |
   |                       |                       |                                                                                                                                                                                                          |
   |                       |                       | -  If the protocol of the backend server group is HTTP or HTTPS, the value ranges from **1** to **1440**, and the default value is **1440**.                                                             |
   |                       |                       |                                                                                                                                                                                                          |
   |                       |                       | QUIC protocol is not supported in **eu-nl** region.                                                                                                                                                      |
   +-----------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _listpools__response_slowstart:

.. table:: **Table 11** SlowStart

   +-----------------------+-----------------------+----------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                |
   +=======================+=======================+============================================================================+
   | enable                | Boolean               | Specifies whether to enable slow start.                                    |
   |                       |                       |                                                                            |
   |                       |                       | -  **true**: Enable slow start.                                            |
   |                       |                       |                                                                            |
   |                       |                       | -  **false**: Disable slow start.                                          |
   |                       |                       |                                                                            |
   |                       |                       | Default: **false**                                                         |
   +-----------------------+-----------------------+----------------------------------------------------------------------------+
   | duration              | Integer               | Specifies the slow start duration, in seconds.                             |
   |                       |                       |                                                                            |
   |                       |                       | The value ranges from **30** to **1200**, and the default value is **30**. |
   |                       |                       |                                                                            |
   |                       |                       | Minimum: **30**                                                            |
   |                       |                       |                                                                            |
   |                       |                       | Maximum: **1200**                                                          |
   |                       |                       |                                                                            |
   |                       |                       | Default: **30**                                                            |
   +-----------------------+-----------------------+----------------------------------------------------------------------------+

Example Requests
----------------

.. code-block:: text

   GET https://{ELB_Endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/pools?limit=2

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

   {
     "pools" : [ {
       "lb_algorithm" : "ROUND_ROBIN",
       "protocol" : "HTTP",
       "type" : "",
       "vpc_id" : "",
       "description" : "",
       "admin_state_up" : true,
       "member_deletion_protection_enable" : false,
       "loadbalancers" : [ {
         "id" : "309a0f61-0b62-45f2-97d1-742f3434338e"
       } ],
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "session_persistence" : {
         "cookie_name" : "my_cookie",
         "type" : "APP_COOKIE",
         "persistence_timeout" : 1
       },
       "healthmonitor_id" : "",
       "listeners" : [ ],
       "members" : [ ],
       "id" : "73bd4fe0-ffbb-4b56-aab4-4f26ddf7a103",
       "name" : "",
       "ip_version" : "v4"
     }, {
       "lb_algorithm" : "SOURCE_IP",
       "protocol" : "TCP",
       "description" : "",
       "admin_state_up" : true,
       "member_deletion_protection_enable" : false,
       "loadbalancers" : [ {
         "id" : "d9763e59-64b7-4e93-aec7-0ff7881ef9bc"
       } ],
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "session_persistence" : {
         "cookie_name" : "",
         "type" : "SOURCE_IP",
         "persistence_timeout" : 1
       },
       "healthmonitor_id" : "",
       "listeners" : [ {
         "id" : "8d21db6f-b475-429e-a9cb-90439b0413b2"
       } ],
       "members" : [ ],
       "id" : "74db02d1-5711-4c77-b383-a450e2b93142",
       "name" : "pool_tcp_001",
       "ip_version" : "dualstack"
     } ],
     "page_info" : {
       "next_marker" : "74db02d1-5711-4c77-b383-a450e2b93142",
       "previous_marker" : "73bd4fe0-ffbb-4b56-aab4-4f26ddf7a103",
       "current_count" : 2
     },
     "request_id" : "a1a7e852-1928-48f7-bbc9-ca8469898713"
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
