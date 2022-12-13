:original_name: elb_zq_fz_0004.html

.. _elb_zq_fz_0004:

Querying the Status Tree of a Load Balancer
===========================================

Function
--------

This API is used to query the status tree of a load balancer. You can use this API to query details about the associated listeners, backend server groups, backend servers, health checks, forwarding policies, and forwarding rules, helping you understand the topology of resources associated with the load balancer.

URI
---

GET /v2.0/lbaas/loadbalancers/{loadbalancer_id}/statuses

.. table:: **Table 1** Parameter description

   =============== ========= ====== ===============================
   Parameter       Mandatory Type   Description
   =============== ========= ====== ===============================
   loadbalancer_id Yes       String Specifies the load balancer ID.
   =============== ========= ====== ===============================

Request
-------

None

Response
--------

.. table:: **Table 2** Response parameters

   +-----------+--------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter | Type   | Description                                                                                                                                                       |
   +===========+========+===================================================================================================================================================================+
   | statuses  | Object | Specifies the status tree of a load balancer. For details, see :ref:`Table 3 <elb_zq_fz_0004__en-us_topic_0141008272_en-us_topic_0096561533_table1112044734716>`. |
   +-----------+--------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_fz_0004__en-us_topic_0141008272_en-us_topic_0096561533_table1112044734716:

.. table:: **Table 3** **statuses** parameter description

   +--------------+--------+-------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter    | Type   | Description                                                                                                                                     |
   +==============+========+=================================================================================================================================================+
   | loadbalancer | Object | Specifies the load balancer. For details, see :ref:`Table 4 <elb_zq_fz_0004__en-us_topic_0141008272_en-us_topic_0096561533_table712410117487>`. |
   +--------------+--------+-------------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_fz_0004__en-us_topic_0141008272_en-us_topic_0096561533_table712410117487:

.. table:: **Table 4** **loadbalancer** parameter description

   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                                                                                                                          |
   +=======================+=======================+======================================================================================================================================================================================================================================================+
   | id                    | String                | Specifies the load balancer ID.                                                                                                                                                                                                                      |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                | Specifies the load balancer name.                                                                                                                                                                                                                    |
   |                       |                       |                                                                                                                                                                                                                                                      |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                                                                                                                      |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | listeners             | Array                 | Lists the listeners added to the load balancer. For details of this parameter, see :ref:`Table 5 <elb_zq_fz_0004__en-us_topic_0141008272_d0e1809>`.                                                                                                  |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | pools                 | Array                 | Lists the backend server groups associated with the load balancer. For details of this parameter, see :ref:`Table 6 <elb_zq_fz_0004__en-us_topic_0141008272_table99441432133413>`.                                                                   |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | operating_status      | String                | This field is reserved.                                                                                                                                                                                                                              |
   |                       |                       |                                                                                                                                                                                                                                                      |
   |                       |                       | It specifies the operating status of the load balancer. The value can be one of the following:                                                                                                                                                       |
   |                       |                       |                                                                                                                                                                                                                                                      |
   |                       |                       | -  **ONLINE** (default): The load balancer is running normally.                                                                                                                                                                                      |
   |                       |                       | -  **DEGRADED**: This status is displayed only when **provisioning_status** of a forwarding policy or forwarding rule added to a listener of the load balancer is set to **ERROR** and the API for querying the load balancer status tree is called. |
   |                       |                       | -  **DISABLED**: This status is displayed only when **admin_state_up** of the load balancer is set to **false** and the API for querying the load balancer status tree is called.                                                                    |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | provisioning_status   | String                | This parameter is reserved, and its value can only be **ACTIVE**.                                                                                                                                                                                    |
   |                       |                       |                                                                                                                                                                                                                                                      |
   |                       |                       | It specifies the provisioning status of the load balancer.                                                                                                                                                                                           |
   +-----------------------+-----------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_fz_0004__en-us_topic_0141008272_d0e1809:

.. table:: **Table 5** **listeners** parameter description

   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                                                   |
   +=======================+=======================+===============================================================================================================================================================================+
   | id                    | String                | Specifies the listener ID.                                                                                                                                                    |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                | Specifies the listener name.                                                                                                                                                  |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | l7policies            | Array                 | Lists associated forwarding policies. For details of this parameter, see :ref:`Table 9 <elb_zq_fz_0004__en-us_topic_0141008272_table129151528185512>`.                        |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | pools                 | Array                 | Lists the backend server groups associated with the listener. For details of this parameter, see :ref:`Table 6 <elb_zq_fz_0004__en-us_topic_0141008272_table99441432133413>`. |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | operating_status      | String                | This parameter is reserved, and its value can only be **ONLINE**.                                                                                                             |
   |                       |                       |                                                                                                                                                                               |
   |                       |                       | It specifies the operating status of the listener.                                                                                                                            |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | provisioning_status   | String                | This parameter is reserved, and its value can only be **ACTIVE**.                                                                                                             |
   |                       |                       |                                                                                                                                                                               |
   |                       |                       | It specifies the provisioning status of the listener.                                                                                                                         |
   +-----------------------+-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_fz_0004__en-us_topic_0141008272_table99441432133413:

.. table:: **Table 6** **pools** parameter description

   +-----------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                                                |
   +=======================+=======================+============================================================================================================================================================================+
   | id                    | String                | Specifies the ID of the backend server group.                                                                                                                              |
   +-----------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                | Specifies the name of the backend server group.                                                                                                                            |
   +-----------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | healthmonitor         | Object                | Provides health check details of the backend server group. For details of this parameter, see :ref:`Table 7 <elb_zq_fz_0004__en-us_topic_0141008272_table10522133654610>`. |
   +-----------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | members               | Array                 | Lists the members contained in the backend server group. For details of this parameter, see :ref:`Table 8 <elb_zq_fz_0004__en-us_topic_0141008272_table1563417579480>`.    |
   +-----------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | operating_status      | String                | This parameter is reserved, and its value can only be **ONLINE**.                                                                                                          |
   |                       |                       |                                                                                                                                                                            |
   |                       |                       | It specifies the operating status of the backend server group.                                                                                                             |
   +-----------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | provisioning_status   | String                | This parameter is reserved, and its value can only be **ACTIVE**.                                                                                                          |
   |                       |                       |                                                                                                                                                                            |
   |                       |                       | It specifies the provisioning status of the backend server group.                                                                                                          |
   +-----------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_fz_0004__en-us_topic_0141008272_table10522133654610:

.. table:: **Table 7** **healthmonitor** parameter description

   +-----------------------+-----------------------+-------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                       |
   +=======================+=======================+===================================================================+
   | id                    | String                | Specifies the health check ID.                                    |
   +-----------------------+-----------------------+-------------------------------------------------------------------+
   | name                  | String                | Specifies the health check name.                                  |
   +-----------------------+-----------------------+-------------------------------------------------------------------+
   | type                  | String                | -  Specifies the health check protocol.                           |
   |                       |                       | -  The value can be **UDP_CONNECT**, **TCP**, or **HTTP**.        |
   +-----------------------+-----------------------+-------------------------------------------------------------------+
   | provisioning_status   | String                | This parameter is reserved, and its value can only be **ACTIVE**. |
   |                       |                       |                                                                   |
   |                       |                       | It specifies the provisioning status of the health check.         |
   +-----------------------+-----------------------+-------------------------------------------------------------------+

.. _elb_zq_fz_0004__en-us_topic_0141008272_table1563417579480:

.. table:: **Table 8** **members** parameter description

   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                                                                                                                                                                               |
   +=======================+=======================+===========================================================================================================================================================================================================================================================================================================+
   | id                    | String                | Specifies the backend server ID.                                                                                                                                                                                                                                                                          |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | address               | String                | Specifies the private IP address of the backend server, for example, 192.168.3.11.                                                                                                                                                                                                                        |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | protocol_port         | Integer               | Specifies the port used by the backend server. The port number ranges from 0 to 65535.                                                                                                                                                                                                                    |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | operating_status      | String                | This parameter is reserved. It specifies the operating status of the backend server. The value can be one of the following:                                                                                                                                                                               |
   |                       |                       |                                                                                                                                                                                                                                                                                                           |
   |                       |                       | -  **ONLINE**: The backend server is running normally.                                                                                                                                                                                                                                                    |
   |                       |                       | -  **NO_MONITOR**: No health check is configured for the backend server group that the backend server belongs to.                                                                                                                                                                                         |
   |                       |                       | -  **DISABLED**: The backend server is not available. This status is displayed only when **admin_state_up** of the backend server, or the backend server group to which it belongs, or the associated load balancer is set to **false** and the API for querying the load balancer status tree is called. |
   |                       |                       | -  **OFFLINE**: The cloud server used as the backend server is stopped or does not exist.                                                                                                                                                                                                                 |
   |                       |                       |                                                                                                                                                                                                                                                                                                           |
   |                       |                       | .. note::                                                                                                                                                                                                                                                                                                 |
   |                       |                       |                                                                                                                                                                                                                                                                                                           |
   |                       |                       |    When **admin_state_up** is set to **false** and **operating_status** is set to **OFFLINE** for a backend server, **DISABLED** is returned for **operating_status** of the backend server in the response of this API.                                                                                  |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | provisioning_status   | String                | This parameter is reserved, and its value can only be **ACTIVE**.                                                                                                                                                                                                                                         |
   |                       |                       |                                                                                                                                                                                                                                                                                                           |
   |                       |                       | It specifies the provisioning status of the backend server.                                                                                                                                                                                                                                               |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_fz_0004__en-us_topic_0141008272_table129151528185512:

.. table:: **Table 9** **l7policies** parameter description

   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                                         |
   +=======================+=======================+=====================================================================================================================================================================+
   | id                    | String                | Specifies the forwarding policy ID.                                                                                                                                 |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                | Specifies the forwarding policy name.                                                                                                                               |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | rules                 | Array                 | Lists the forwarding rules of the forwarding policy. For details of this parameter, see :ref:`Table 10 <elb_zq_fz_0004__en-us_topic_0141008272_table197162765814>`. |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | action                | String                | -  Specifies whether requests are forwarded to another backend server group or redirected to an HTTPS listener.                                                     |
   |                       |                       | -  The value can be **REDIRECT_TO_POOL** or **REDIRECT_TO_LISTENER**.                                                                                               |
   |                       |                       |                                                                                                                                                                     |
   |                       |                       |    -  **REDIRECT_TO_POOL**: Requests are forwarded to another backend server group.                                                                                 |
   |                       |                       |    -  **REDIRECT_TO_LISTENER**: Requests are redirected to an HTTPS listener.                                                                                       |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | provisioning_status   | String                | This parameter is reserved.                                                                                                                                         |
   |                       |                       |                                                                                                                                                                     |
   |                       |                       | It specifies the provisioning status of the forwarding policy. Value options:                                                                                       |
   |                       |                       |                                                                                                                                                                     |
   |                       |                       | -  **ACTIVE** (default): The forwarding policy is normal.                                                                                                           |
   |                       |                       | -  **ERROR**: Another forwarding policy of the same listener has the same forwarding rule.                                                                          |
   +-----------------------+-----------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_fz_0004__en-us_topic_0141008272_table197162765814:

.. table:: **Table 10** **rules** parameter description

   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                         |
   +=======================+=======================+=====================================================================================================+
   | id                    | String                | Specifies the forwarding rule ID.                                                                   |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------+
   | type                  | String                | -  Specifies the match type of a forwarding rule.                                                   |
   |                       |                       | -  The value can be **PATH** or **HOST_NAME**.                                                      |
   |                       |                       |                                                                                                     |
   |                       |                       |    -  **PATH**: matches the path in the request.                                                    |
   |                       |                       |    -  **HOST_NAME**: matches the domain name in the request.                                        |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------+
   | provisioning_status   | String                | This parameter is reserved.                                                                         |
   |                       |                       |                                                                                                     |
   |                       |                       | It specifies the provisioning status of the forwarding rule. The value can be one of the following: |
   |                       |                       |                                                                                                     |
   |                       |                       | -  **ACTIVE** (default): The forwarding rule is normal.                                             |
   |                       |                       | -  **ERROR**: Another forwarding policy of the same listener has the same forwarding rule.          |
   +-----------------------+-----------------------+-----------------------------------------------------------------------------------------------------+

Example Request
---------------

-  Example request

   .. code-block:: text

      GET https://{Endpoint}/v2.0/lbaas/loadbalancers/38278031-cfca-44be-81be-a412f618773b/statuses

Example Response
----------------

-  Example response

   .. code-block::

      {
          "statuses": {
              "loadbalancer": {
                  "name": "lb-jy",
                  "provisioning_status": "ACTIVE",
                  "listeners": [
                      {
                          "name": "listener-jy-1",
                          "provisioning_status": "ACTIVE",
                          "pools": [
                              {
                                  "name": "pool-jy-1",
                                  "provisioning_status": "ACTIVE",
                                  "healthmonitor": {
                                      "type": "TCP",
                                      "id": "7422b51a-0ed2-4702-9429-4f88349276c6",
                                      "name": "",
                                      "provisioning_status": "ACTIVE"
                                  },
                                  "members": [
                                      {
                                          "protocol_port": 80,
                                          "address": "192.168.44.11",
                                          "id": "7bbf7151-0dce-4087-b316-06c7fa17b894",
                                          "operating_status": "ONLINE",
                                          "provisioning_status": "ACTIVE"
                                      }
                                  ],
                                  "id": "c54b3286-2349-4c5c-ade1-e6bb0b26ad18",
                                  "operating_status": "ONLINE"
                              }
                          ],
                          "l7policies": [],
                          "id": "eb84c5b4-9bc5-4bee-939d-3900fb05dc7b",
                          "operating_status": "ONLINE"
                      }
                  ],
                  "pools": [
                      {
                          "name": "pool-jy-1",
                          "provisioning_status": "ACTIVE",
                          "healthmonitor": {
                              "type": "TCP",
                              "id": "7422b51a-0ed2-4702-9429-4f88349276c6",
                              "name": "",
                              "provisioning_status": "ACTIVE"
                          },
                          "members": [
                              {
                                  "protocol_port": 80,
                                  "address": "192.168.44.11",
                                  "id": "7bbf7151-0dce-4087-b316-06c7fa17b894",
                                  "operating_status": "ONLINE",
                                  "provisioning_status": "ACTIVE"
                              }
                          ],
                          "id": "c54b3286-2349-4c5c-ade1-e6bb0b26ad18",
                          "operating_status": "ONLINE"
                      }
                  ],
                  "id": "38278031-cfca-44be-81be-a412f618773b",
                  "operating_status": "ONLINE"
              }
          }
      }

Status Code
-----------

For details, see :ref:`Status Codes <elb_gc_1102>`.
