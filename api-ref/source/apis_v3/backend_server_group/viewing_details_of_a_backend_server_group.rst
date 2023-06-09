:original_name: ShowPool.html

.. _ShowPool:

Viewing Details of a Backend Server Group
=========================================

Function
--------

This API is used to view details of a backend server group.

URI
---

GET /v3/{project_id}/elb/pools/{pool_id}

.. table:: **Table 1** Path Parameters

   +------------+-----------+--------+-----------------------------------------------+
   | Parameter  | Mandatory | Type   | Description                                   |
   +============+===========+========+===============================================+
   | project_id | Yes       | String | Specifies the project ID.                     |
   +------------+-----------+--------+-----------------------------------------------+
   | pool_id    | Yes       | String | Specifies the ID of the backend server group. |
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

   +------------+----------------------------------------------+-----------------------------------------------------------------+
   | Parameter  | Type                                         | Description                                                     |
   +============+==============================================+=================================================================+
   | request_id | String                                       | Specifies the request ID. The value is automatically generated. |
   +------------+----------------------------------------------+-----------------------------------------------------------------+
   | pool       | :ref:`Pool <showpool__response_pool>` object | Specifies the backend server group.                             |
   +------------+----------------------------------------------+-----------------------------------------------------------------+

.. _showpool__response_pool:

.. table:: **Table 4** Pool

   +-----------------------------------+------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter                         | Type                                                                         | Description                                                                                                                                                                                                                               |
   +===================================+==============================================================================+===========================================================================================================================================================================================================================================+
   | admin_state_up                    | Boolean                                                                      | Specifies the administrative status of the backend server group. The value can only be **true**.                                                                                                                                          |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | This parameter is unsupported. Please do not use it.                                                                                                                                                                                      |
   +-----------------------------------+------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | description                       | String                                                                       | Provides supplementary information about the backend server group.                                                                                                                                                                        |
   +-----------------------------------+------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | healthmonitor_id                  | String                                                                       | Specifies the ID of the health check configured for the backend server group.                                                                                                                                                             |
   +-----------------------------------+------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | id                                | String                                                                       | Specifies the backend server group ID.                                                                                                                                                                                                    |
   +-----------------------------------+------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | lb_algorithm                      | String                                                                       | Specifies the load balancing algorithm used by the load balancer to route requests to backend servers in the associated backend server group.                                                                                             |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | The value can be one of the following:                                                                                                                                                                                                    |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | -  **ROUND_ROBIN**: weighted round robin                                                                                                                                                                                                  |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | -  **LEAST_CONNECTIONS**: weighted least connections                                                                                                                                                                                      |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | -  **SOURCE_IP**: source IP hash                                                                                                                                                                                                          |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | -  **QUIC_CID**: connection ID                                                                                                                                                                                                            |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | Note:                                                                                                                                                                                                                                     |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | -  If the value is **SOURCE_IP**, the **weight** parameter will not take effect for backend servers.                                                                                                                                      |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | -  **QUIC_CID** is supported only when the protocol of the backend server group is QUIC.                                                                                                                                                  |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | QUIC_CID is not supported in **eu-nl** region.                                                                                                                                                                                            |
   +-----------------------------------+------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | listeners                         | Array of :ref:`ListenerRef <showpool__response_listenerref>` objects         | Specifies the IDs of the listeners with which the backend server group is associated.                                                                                                                                                     |
   +-----------------------------------+------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | loadbalancers                     | Array of :ref:`LoadBalancerRef <showpool__response_loadbalancerref>` objects | Specifies the IDs of the load balancers with which the backend server group is associated.                                                                                                                                                |
   +-----------------------------------+------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | members                           | Array of :ref:`MemberRef <showpool__response_memberref>` objects             | Specifies the IDs of the backend servers in the backend server group.                                                                                                                                                                     |
   +-----------------------------------+------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                              | String                                                                       | Specifies the backend server group name.                                                                                                                                                                                                  |
   +-----------------------------------+------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | project_id                        | String                                                                       | Specifies the project ID.                                                                                                                                                                                                                 |
   +-----------------------------------+------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | protocol                          | String                                                                       | Specifies the protocol used by the backend server group to receive requests. The value can be **TCP**, **UDP**, **HTTP**, **HTTPS**, or **QUIC**.                                                                                         |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | -  If the listener's protocol is **UDP**, the protocol of the backend server group must be **UDP**.                                                                                                                                       |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | -  If the listener's protocol is **TCP**, the protocol of the backend server group must be **TCP**.                                                                                                                                       |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | -  If the listener's protocol is **HTTP**, the protocol of the backend server group must be **HTTP**.                                                                                                                                     |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | -  If the listener's protocol is **HTTPS**, the protocol of the backend server group can be **HTTP** or **HTTPS**.                                                                                                                        |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | -  If the listener's protocol is **TERMINATED_HTTPS**, the protocol of the backend server group must be **HTTP**.                                                                                                                         |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | -  If the backend server group protocol is **QUIC**, sticky session must be enabled with **type** set to **SOURCE_IP**.                                                                                                                   |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | QUIC protocol is not supported in **eu-nl** region.                                                                                                                                                                                       |
   +-----------------------------------+------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | session_persistence               | :ref:`SessionPersistence <showpool__response_sessionpersistence>` object     | Specifies the sticky session.                                                                                                                                                                                                             |
   +-----------------------------------+------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | ip_version                        | String                                                                       | Specifies the IP address version supported by the backend server group.                                                                                                                                                                   |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | IPv6 is unsupported. Only **v4** will be returned.                                                                                                                                                                                        |
   +-----------------------------------+------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | slow_start                        | :ref:`SlowStart <showpool__response_slowstart>` object                       | Specifies slow start details. After you enable slow start, new backend servers added to the backend server group are warmed up, and the number of requests they can receive increases linearly during the configured slow start duration. |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | This parameter can be used when the protocol of the backend server group is HTTP or HTTPS. An error will be returned if the protocol is not HTTP or HTTPS. This parameter is not available in **eu-nl** region. Please do not use it.     |
   +-----------------------------------+------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | member_deletion_protection_enable | Boolean                                                                      | Specifies whether to enable removal protection.                                                                                                                                                                                           |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | -  **true**: Enable removal protection.                                                                                                                                                                                                   |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | -  **false**: Disable removal protection.                                                                                                                                                                                                 |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | .. note::                                                                                                                                                                                                                                 |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              |    Disable removal protection for all your resources before deleting your account.                                                                                                                                                        |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | This parameter is not available in **eu-nl** region. Please do not use it.                                                                                                                                                                |
   +-----------------------------------+------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | created_at                        | String                                                                       | Specifies the time when a backend server group was created. The format is yyyy-MM-dd'T'HH:mm:ss'Z' (UTC time).                                                                                                                            |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | This is a new field in this version, and it will not be returned for resources associated with existing dedicated load balancers and for resources associated with existing and new shared load balancers.                                |
   +-----------------------------------+------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | updated_at                        | String                                                                       | Specifies the time when when a backend server group was updated. The format is yyyy-MM-dd'T'HH:mm:ss'Z' (UTC time).                                                                                                                       |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | This is a new field in this version, and it will not be returned for resources associated with existing dedicated load balancers and for resources associated with existing and new shared load balancers.                                |
   +-----------------------------------+------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | vpc_id                            | String                                                                       | Specifies the ID of the VPC where the backend server group works.                                                                                                                                                                         |
   +-----------------------------------+------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | type                              | String                                                                       | Specifies the type of the backend server group.                                                                                                                                                                                           |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | Values:                                                                                                                                                                                                                                   |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | -  **instance**: Any type of backend servers can be added. **vpc_id** is mandatory.                                                                                                                                                       |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | -  **ip**: Only IP as Backend servers can be added. **vpc_id** cannot be specified.                                                                                                                                                       |
   |                                   |                                                                              |                                                                                                                                                                                                                                           |
   |                                   |                                                                              | -  **""**: Any type of backend servers can be added.                                                                                                                                                                                      |
   +-----------------------------------+------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _showpool__response_listenerref:

.. table:: **Table 5** ListenerRef

   ========= ====== ==========================
   Parameter Type   Description
   ========= ====== ==========================
   id        String Specifies the listener ID.
   ========= ====== ==========================

.. _showpool__response_loadbalancerref:

.. table:: **Table 6** LoadBalancerRef

   ========= ====== ===============================
   Parameter Type   Description
   ========= ====== ===============================
   id        String Specifies the load balancer ID.
   ========= ====== ===============================

.. _showpool__response_memberref:

.. table:: **Table 7** MemberRef

   ========= ====== ================================
   Parameter Type   Description
   ========= ====== ================================
   id        String Specifies the backend server ID.
   ========= ====== ================================

.. _showpool__response_sessionpersistence:

.. table:: **Table 8** SessionPersistence

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

.. _showpool__response_slowstart:

.. table:: **Table 9** SlowStart

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

   GET https://{ELB_Endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/pools/36ce7086-a496-4666-9064-5ba0e6840c75

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

   {
     "pool" : {
       "type" : "",
       "vpc_id" : "",
       "lb_algorithm" : "LEAST_CONNECTIONS",
       "protocol" : "TCP",
       "description" : "My pool",
       "admin_state_up" : true,
       "member_deletion_protection_enable" : false,
       "loadbalancers" : [ {
         "id" : "098b2f68-af1c-41a9-8efd-69958722af62"
       } ],
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "session_persistence" : null,
       "healthmonitor_id" : "",
       "listeners" : [ {
         "id" : "0b11747a-b139-492f-9692-2df0b1c87193"
       }, {
         "id" : "61942790-2367-482a-8b0e-93840ea2a1c6"
       }, {
         "id" : "fd8f954c-f0f8-4d39-bb1d-41637cd6b1be"
       } ],
       "members" : [ ],
       "id" : "36ce7086-a496-4666-9064-5ba0e6840c75",
       "name" : "My pool.",
       "ip_version" : "dualstack"
     },
     "request_id" : "c1a60da2-1ec7-4a1c-b4cc-73e1a57b368e"
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
