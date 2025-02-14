:original_name: ShowLoadBalancerStatus.html

.. _ShowLoadBalancerStatus:

Querying the Status Tree of a Load Balancer
===========================================

Function
--------

This API is used to query the status tree of a load balancer and to show information about all resources associated with the load balancer.

When **admin_state_up** is set to **false** and **operating_status** to **OFFLINE** for a backend server, **DISABLED** is returned for **operating_status** of the backend server in the response of this API.

URI
---

GET /v3/{project_id}/elb/loadbalancers/{loadbalancer_id}/statuses

.. table:: **Table 1** Path Parameters

   =============== ========= ====== ===============================
   Parameter       Mandatory Type   Description
   =============== ========= ====== ===============================
   project_id      Yes       String Specifies the project ID.
   loadbalancer_id Yes       String Specifies the load balancer ID.
   =============== ========= ====== ===============================

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

   +------------+----------------------------------------------------------------------------------------------------+-----------------------------------------------------------------+
   | Parameter  | Type                                                                                               | Description                                                     |
   +============+====================================================================================================+=================================================================+
   | statuses   | :ref:`LoadBalancerStatusResult <showloadbalancerstatus__response_loadbalancerstatusresult>` object | Provides information about the load balancer status tree.       |
   +------------+----------------------------------------------------------------------------------------------------+-----------------------------------------------------------------+
   | request_id | String                                                                                             | Specifies the request ID. The value is automatically generated. |
   +------------+----------------------------------------------------------------------------------------------------+-----------------------------------------------------------------+

.. _showloadbalancerstatus__response_loadbalancerstatusresult:

.. table:: **Table 4** LoadBalancerStatusResult

   +--------------+----------------------------------------------------------------------------------------+---------------------------------------------------------------------------+
   | Parameter    | Type                                                                                   | Description                                                               |
   +==============+========================================================================================+===========================================================================+
   | loadbalancer | :ref:`LoadBalancerStatus <showloadbalancerstatus__response_loadbalancerstatus>` object | Specifies the statuses of the load balancer and its associated resources. |
   +--------------+----------------------------------------------------------------------------------------+---------------------------------------------------------------------------+

.. _showloadbalancerstatus__response_loadbalancerstatus:

.. table:: **Table 5** LoadBalancerStatus

   +-----------------------+------------------------------------------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                                                                                                             | Description                                                                                                                                                                                                             |
   +=======================+==================================================================================================================+=========================================================================================================================================================================================================================+
   | name                  | String                                                                                                           | Specifies the load balancer name.                                                                                                                                                                                       |
   |                       |                                                                                                                  |                                                                                                                                                                                                                         |
   |                       |                                                                                                                  | Minimum: **1**                                                                                                                                                                                                          |
   |                       |                                                                                                                  |                                                                                                                                                                                                                         |
   |                       |                                                                                                                  | Maximum: **255**                                                                                                                                                                                                        |
   +-----------------------+------------------------------------------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | provisioning_status   | String                                                                                                           | Specifies the provisioning status of the load balancer. The value can be **ACTIVE** or **PENDING_DELETE**.                                                                                                              |
   |                       |                                                                                                                  |                                                                                                                                                                                                                         |
   |                       |                                                                                                                  | -  **ACTIVE**: The load balancer is successfully provisioned.                                                                                                                                                           |
   |                       |                                                                                                                  |                                                                                                                                                                                                                         |
   |                       |                                                                                                                  | -  **PENDING_DELETE**: The load balancer is being deleted.                                                                                                                                                              |
   +-----------------------+------------------------------------------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | listeners             | Array of :ref:`LoadBalancerStatusListener <showloadbalancerstatus__response_loadbalancerstatuslistener>` objects | Lists the listeners added to the load balancer.                                                                                                                                                                         |
   +-----------------------+------------------------------------------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | pools                 | Array of :ref:`LoadBalancerStatusPool <showloadbalancerstatus__response_loadbalancerstatuspool>` objects         | Lists the backend server groups associated with the load balancer.                                                                                                                                                      |
   +-----------------------+------------------------------------------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | id                    | String                                                                                                           | Specifies the load balancer ID.                                                                                                                                                                                         |
   +-----------------------+------------------------------------------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | operating_status      | String                                                                                                           | Specifies the operating status of the load balancer.                                                                                                                                                                    |
   |                       |                                                                                                                  |                                                                                                                                                                                                                         |
   |                       |                                                                                                                  | The value can only be one of the following:                                                                                                                                                                             |
   |                       |                                                                                                                  |                                                                                                                                                                                                                         |
   |                       |                                                                                                                  | -  **ONLINE** (default): The load balancer is running normally.                                                                                                                                                         |
   |                       |                                                                                                                  |                                                                                                                                                                                                                         |
   |                       |                                                                                                                  | -  **FROZEN**: The load balancer has been frozen.                                                                                                                                                                       |
   |                       |                                                                                                                  |                                                                                                                                                                                                                         |
   |                       |                                                                                                                  | -  **DEGRADED**: This status is displayed only when **operating_status** is set to **OFFLINE** for a backend server associated with the load balancer and the API for querying the load balancer status tree is called. |
   |                       |                                                                                                                  |                                                                                                                                                                                                                         |
   |                       |                                                                                                                  | -  **DISABLED**: This status is displayed only when **admin_state_up** of the load balancer is set to **false**.                                                                                                        |
   |                       |                                                                                                                  |                                                                                                                                                                                                                         |
   |                       |                                                                                                                  | **DEGRADED** and **DISABLED** are returned only when the API for querying the load balancer status tree is called.                                                                                                      |
   +-----------------------+------------------------------------------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _showloadbalancerstatus__response_loadbalancerstatuslistener:

.. table:: **Table 6** LoadBalancerStatusListener

   +-----------------------+--------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                                                                                                         | Description                                                                                                                                                                                                                                                        |
   +=======================+==============================================================================================================+====================================================================================================================================================================================================================================================================+
   | name                  | String                                                                                                       | Specifies the name of the listener added to the load balancer.                                                                                                                                                                                                     |
   |                       |                                                                                                              |                                                                                                                                                                                                                                                                    |
   |                       |                                                                                                              | Minimum: **1**                                                                                                                                                                                                                                                     |
   |                       |                                                                                                              |                                                                                                                                                                                                                                                                    |
   |                       |                                                                                                              | Maximum: **255**                                                                                                                                                                                                                                                   |
   +-----------------------+--------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | provisioning_status   | String                                                                                                       | Specifies the provisioning status of the listener. The value can only be **ACTIVE**, indicating that the listener is successfully provisioned.                                                                                                                     |
   +-----------------------+--------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | pools                 | Array of :ref:`LoadBalancerStatusPool <showloadbalancerstatus__response_loadbalancerstatuspool>` objects     | Specifies the operating status of the backend server group associated with the listener.                                                                                                                                                                           |
   +-----------------------+--------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | l7policies            | Array of :ref:`LoadBalancerStatusPolicy <showloadbalancerstatus__response_loadbalancerstatuspolicy>` objects | Specifies the operating status of the forwarding policy added to the listener.                                                                                                                                                                                     |
   +-----------------------+--------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | id                    | String                                                                                                       | Specifies the listener ID.                                                                                                                                                                                                                                         |
   +-----------------------+--------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | operating_status      | String                                                                                                       | Specifies the operating status of the listener.                                                                                                                                                                                                                    |
   |                       |                                                                                                              |                                                                                                                                                                                                                                                                    |
   |                       |                                                                                                              | The value can only be one of the following:                                                                                                                                                                                                                        |
   |                       |                                                                                                              |                                                                                                                                                                                                                                                                    |
   |                       |                                                                                                              | -  **ONLINE** (default): The listener is running normally.                                                                                                                                                                                                         |
   |                       |                                                                                                              |                                                                                                                                                                                                                                                                    |
   |                       |                                                                                                              | -  **DEGRADED**: This status is displayed only when **provisioning_status** of a forwarding policy or a forwarding rule added to the listener is set to **ERROR** or **operating_status** is set to **OFFLINE** for a backend server associated with the listener. |
   |                       |                                                                                                              |                                                                                                                                                                                                                                                                    |
   |                       |                                                                                                              | -  **DISABLED**: This status is displayed only when **admin_state_up** of the load balancer or of the listener is set to **false**.                                                                                                                                |
   |                       |                                                                                                              |                                                                                                                                                                                                                                                                    |
   |                       |                                                                                                              |    Note: **DEGRADED** and **DISABLED** are returned only when the API for querying the load balancer status tree is called.                                                                                                                                        |
   +-----------------------+--------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _showloadbalancerstatus__response_loadbalancerstatuspolicy:

.. table:: **Table 7** LoadBalancerStatusPolicy

   +-----------------------+--------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                                                                                                         | Description                                                                                                  |
   +=======================+==============================================================================================================+==============================================================================================================+
   | action                | String                                                                                                       | Specifies whether requests are forwarded to another backend server group or redirected to an HTTPS listener. |
   |                       |                                                                                                              |                                                                                                              |
   |                       |                                                                                                              | The value can be one of the following:                                                                       |
   |                       |                                                                                                              |                                                                                                              |
   |                       |                                                                                                              | -  **REDIRECT_TO_POOL**: Requests are forwarded to another backend server group.                             |
   |                       |                                                                                                              |                                                                                                              |
   |                       |                                                                                                              | -  **REDIRECT_TO_LISTENER**: Requests are redirected to an HTTPS listener.                                   |
   +-----------------------+--------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------+
   | id                    | String                                                                                                       | Specifies the forwarding policy ID.                                                                          |
   +-----------------------+--------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------+
   | provisioning_status   | String                                                                                                       | Specifies the provisioning status of the forwarding policy.                                                  |
   |                       |                                                                                                              |                                                                                                              |
   |                       |                                                                                                              | -  **ACTIVE** (default): The forwarding policy is provisioned successfully.                                  |
   |                       |                                                                                                              |                                                                                                              |
   |                       |                                                                                                              | -  **ERROR**: Another forwarding policy of the same listener has the same forwarding rule.                   |
   +-----------------------+--------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------+
   | name                  | String                                                                                                       | Specifies the policy name.                                                                                   |
   |                       |                                                                                                              |                                                                                                              |
   |                       |                                                                                                              | Minimum: **1**                                                                                               |
   |                       |                                                                                                              |                                                                                                              |
   |                       |                                                                                                              | Maximum: **255**                                                                                             |
   +-----------------------+--------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------+
   | rules                 | Array of :ref:`LoadBalancerStatusL7Rule <showloadbalancerstatus__response_loadbalancerstatusl7rule>` objects | Specifies the forwarding rule.                                                                               |
   +-----------------------+--------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------+

.. _showloadbalancerstatus__response_loadbalancerstatusl7rule:

.. table:: **Table 8** LoadBalancerStatusL7Rule

   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                |
   +=======================+=======================+============================================================================================+
   | id                    | String                | Specifies the ID of the forwarding rule.                                                   |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------+
   | type                  | String                | Specifies the type of the match content. The value can be **HOST_NAME** or **PATH**.       |
   |                       |                       |                                                                                            |
   |                       |                       | -  **HOST_NAME**: A domain name will be used for matching.                                 |
   |                       |                       |                                                                                            |
   |                       |                       | -  **PATH**: A URL will be used for matching.                                              |
   |                       |                       |                                                                                            |
   |                       |                       | The value must be unique for each forwarding rule in a forwarding policy.                  |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------+
   | provisioning_status   | String                | Specifies the provisioning status of the forwarding rule.                                  |
   |                       |                       |                                                                                            |
   |                       |                       | -  **ACTIVE** (default): The forwarding rule is successfully provisioned.                  |
   |                       |                       |                                                                                            |
   |                       |                       | -  **ERROR**: Another forwarding policy of the same listener has the same forwarding rule. |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------+

.. _showloadbalancerstatus__response_loadbalancerstatuspool:

.. table:: **Table 9** LoadBalancerStatusPool

   +-----------------------+------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                                                                                                             | Description                                                                                                                                                            |
   +=======================+==================================================================================================================+========================================================================================================================================================================+
   | provisioning_status   | String                                                                                                           | Specifies the provisioning status of the backend server group. The value can only be **ACTIVE**, indicating that the backend server group is successfully provisioned. |
   +-----------------------+------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                                                                                                           | Specifies the name of the backend server group.                                                                                                                        |
   |                       |                                                                                                                  |                                                                                                                                                                        |
   |                       |                                                                                                                  | Minimum: **1**                                                                                                                                                         |
   |                       |                                                                                                                  |                                                                                                                                                                        |
   |                       |                                                                                                                  | Maximum: **255**                                                                                                                                                       |
   +-----------------------+------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | healthmonitor         | :ref:`LoadBalancerStatusHealthMonitor <showloadbalancerstatus__response_loadbalancerstatushealthmonitor>` object | Specifies the health check results of backend servers in the load balancer status tree.                                                                                |
   +-----------------------+------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | members               | Array of :ref:`LoadBalancerStatusMember <showloadbalancerstatus__response_loadbalancerstatusmember>` objects     | Specifies the backend server.                                                                                                                                          |
   +-----------------------+------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | id                    | String                                                                                                           | Specifies the ID of the backend server group.                                                                                                                          |
   +-----------------------+------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | operating_status      | String                                                                                                           | Specifies the operating status of the backend server group.                                                                                                            |
   |                       |                                                                                                                  |                                                                                                                                                                        |
   |                       |                                                                                                                  | The value can be one of the following:                                                                                                                                 |
   |                       |                                                                                                                  |                                                                                                                                                                        |
   |                       |                                                                                                                  | -  **ONLINE**: The backend server group is running normally.                                                                                                           |
   |                       |                                                                                                                  |                                                                                                                                                                        |
   |                       |                                                                                                                  | -  **DEGRADED**: This status is displayed only when **operating_status** of a backend server in the backend server group is set to **OFFLINE**.                        |
   |                       |                                                                                                                  |                                                                                                                                                                        |
   |                       |                                                                                                                  | -  **DISABLED**: This status is displayed only when **admin_state_up** of the backend server group or of the associated load balancer is set to **false**.             |
   |                       |                                                                                                                  |                                                                                                                                                                        |
   |                       |                                                                                                                  | Note: **DEGRADED** and **DISABLED** are returned only when the API for querying the load balancer status tree is called.                                               |
   +-----------------------+------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _showloadbalancerstatus__response_loadbalancerstatushealthmonitor:

.. table:: **Table 10** LoadBalancerStatusHealthMonitor

   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                            |
   +=======================+=======================+========================================================================================================================================================+
   | type                  | String                | Specifies the health check protocol. The value can be **TCP**, **UDP_CONNECT**, or **HTTP**.                                                           |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
   | id                    | String                | Specifies the health check ID.                                                                                                                         |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                | Specifies the health check name.                                                                                                                       |
   |                       |                       |                                                                                                                                                        |
   |                       |                       | Minimum: **1**                                                                                                                                         |
   |                       |                       |                                                                                                                                                        |
   |                       |                       | Maximum: **255**                                                                                                                                       |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
   | provisioning_status   | String                | Specifies the provisioning status of the health check. The value can only be **ACTIVE**, indicating that the health check is successfully provisioned. |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _showloadbalancerstatus__response_loadbalancerstatusmember:

.. table:: **Table 11** LoadBalancerStatusMember

   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                                                                                                                                                                               |
   +=======================+=======================+===========================================================================================================================================================================================================================================================================================================+
   | provisioning_status   | String                | Specifies the provisioning status of the backend server. The value can only be **ACTIVE**, indicating that the backend server is successfully provisioned.                                                                                                                                                |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | address               | String                | Specifies the private IP address bound to the backend server.                                                                                                                                                                                                                                             |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | protocol_port         | Integer               | Specifies the port used by the backend server to receive requests. The port number ranges from 1 to 65535.                                                                                                                                                                                                |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | id                    | String                | Specifies the backend server ID.                                                                                                                                                                                                                                                                          |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | operating_status      | String                | Specifies the operating status of the backend server.                                                                                                                                                                                                                                                     |
   |                       |                       |                                                                                                                                                                                                                                                                                                           |
   |                       |                       | The value can be one of the following:                                                                                                                                                                                                                                                                    |
   |                       |                       |                                                                                                                                                                                                                                                                                                           |
   |                       |                       | -  **ONLINE**: The backend server is running normally.                                                                                                                                                                                                                                                    |
   |                       |                       |                                                                                                                                                                                                                                                                                                           |
   |                       |                       | -  **NO_MONITOR**: No health check is configured for the backend server group to which the backend server belongs.                                                                                                                                                                                        |
   |                       |                       |                                                                                                                                                                                                                                                                                                           |
   |                       |                       | -  **DISABLED**: The backend server is not available. This status is displayed only when **admin_state_up** of the backend server, or the backend server group to which it belongs, or the associated load balancer is set to **false** and the API for querying the load balancer status tree is called. |
   |                       |                       |                                                                                                                                                                                                                                                                                                           |
   |                       |                       | -  **OFFLINE**: The cloud server used as the backend server is stopped or does not exist.                                                                                                                                                                                                                 |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Example Requests
----------------

Querying the status tree of a load balancer

.. code-block:: text

   GET https://{ELB_Endpoint}/v3/{project_id}/elb/loadbalancers/38278031-cfca-44be-81be-a412f618773b/statuses

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

   {
     "statuses" : {
       "loadbalancer" : {
         "name" : "lb-jy",
         "provisioning_status" : "ACTIVE",
         "listeners" : [ {
           "name" : "listener-jy-1",
           "provisioning_status" : "ACTIVE",
           "pools" : [ {
             "name" : "pool-jy-1",
             "provisioning_status" : "ACTIVE",
             "healthmonitor" : {
               "type" : "TCP",
               "id" : "7422b51a-0ed2-4702-9429-4f88349276c6",
               "name" : "",
               "provisioning_status" : "ACTIVE"
             },
             "members" : [ {
               "protocol_port" : 80,
               "address" : "192.168.44.11",
               "id" : "7bbf7151-0dce-4087-b316-06c7fa17b894",
               "operating_status" : "ONLINE",
               "provisioning_status" : "ACTIVE"
             } ],
             "id" : "c54b3286-2349-4c5c-ade1-e6bb0b26ad18",
             "operating_status" : "ONLINE"
           } ],
           "l7policies" : [ ],
           "id" : "eb84c5b4-9bc5-4bee-939d-3900fb05dc7b",
           "operating_status" : "ONLINE"
         } ],
         "pools" : [ {
           "name" : "pool-jy-1",
           "provisioning_status" : "ACTIVE",
           "healthmonitor" : {
             "type" : "TCP",
             "id" : "7422b51a-0ed2-4702-9429-4f88349276c6",
             "name" : "",
             "provisioning_status" : "ACTIVE"
           },
           "members" : [ {
             "protocol_port" : 80,
             "address" : "192.168.44.11",
             "id" : "7bbf7151-0dce-4087-b316-06c7fa17b894",
             "operating_status" : "ONLINE",
             "provisioning_status" : "ACTIVE"
           } ],
           "id" : "c54b3286-2349-4c5c-ade1-e6bb0b26ad18",
           "operating_status" : "ONLINE"
         } ],
         "id" : "38278031-cfca-44be-81be-a412f618773b",
         "operating_status" : "ONLINE"
       }
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
