:original_name: en-us_topic_0096561535.html

.. _en-us_topic_0096561535:

Creating a Load Balancer
========================

Function
--------

This API is used to create a private network load balancer. After the load balancer is created, its details, such as load balancer ID, IP address, and subnet ID, are returned.

To create a public network load balancer, you also need to call the API for assigning an EIP and associate this IP address to the port bound to the IP address of the private network load balancer.

URI
---

POST /v2.0/lbaas/loadbalancers

Request
-------

.. table:: **Table 1** Request parameters

   +--------------+-----------+--------+----------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter    | Mandatory | Type   | Description                                                                                                                                              |
   +==============+===========+========+==========================================================================================================================================================+
   | loadbalancer | Yes       | Object | Specifies the load balancer. For details, see :ref:`Table 2 <en-us_topic_0096561535__en-us_topic_0141008273_en-us_topic_0096561535_table1673416344910>`. |
   +--------------+-----------+--------+----------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _en-us_topic_0096561535__en-us_topic_0141008273_en-us_topic_0096561535_table1673416344910:

.. table:: **Table 2** **loadbalancer** parameter description

   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                                                                                                                                                                    |
   +=================+=================+=================+================================================================================================================================================================================================================================+
   | name            | No              | String          | Specifies the load balancer name.                                                                                                                                                                                              |
   |                 |                 |                 |                                                                                                                                                                                                                                |
   |                 |                 |                 | The value contains a maximum of 255 characters.                                                                                                                                                                                |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | description     | No              | String          | Provides supplementary information about the load balancer.                                                                                                                                                                    |
   |                 |                 |                 |                                                                                                                                                                                                                                |
   |                 |                 |                 | The value contains a maximum of 255 characters.                                                                                                                                                                                |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tenant_id       | No              | String          | Specifies the ID of the project where the load balancer is used.                                                                                                                                                               |
   |                 |                 |                 |                                                                                                                                                                                                                                |
   |                 |                 |                 | The value contains a maximum of 255 characters.                                                                                                                                                                                |
   |                 |                 |                 |                                                                                                                                                                                                                                |
   |                 |                 |                 | The value must be the same as the value of **project_id** in the token.                                                                                                                                                        |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | vip_subnet_id   | Yes             | String          | Specifies the ID of the subnet where the load balancer works. You can obtain the value by calling the API for querying subnets {VPC endpoint}/v2.0/subnets} using the GET method.                                              |
   |                 |                 |                 |                                                                                                                                                                                                                                |
   |                 |                 |                 | The private IP address of the load balancer is in this subnet.                                                                                                                                                                 |
   |                 |                 |                 |                                                                                                                                                                                                                                |
   |                 |                 |                 | Only IPv4 subnets are supported. IPv6 subnets are not supported.                                                                                                                                                               |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | provider        | No              | String          | Specifies the provider of the load balancer.                                                                                                                                                                                   |
   |                 |                 |                 |                                                                                                                                                                                                                                |
   |                 |                 |                 | The value can only be **vlb**.                                                                                                                                                                                                 |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | vip_address     | No              | String          | Specifies the private IP address of the load balancer.                                                                                                                                                                         |
   |                 |                 |                 |                                                                                                                                                                                                                                |
   |                 |                 |                 | This IP address must be the one in the subnet specified by **vip_subnet_id**. If this parameter is not specified, an IP address is automatically assigned to the load balancer from the subnet specified by **vip_subnet_id**. |
   |                 |                 |                 |                                                                                                                                                                                                                                |
   |                 |                 |                 | The value contains a maximum of 64 characters.                                                                                                                                                                                 |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up  | No              | Boolean         | Specifies the administrative status of the load balancer.                                                                                                                                                                      |
   |                 |                 |                 |                                                                                                                                                                                                                                |
   |                 |                 |                 | This parameter is reserved. The default value is **true**.                                                                                                                                                                     |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Response
--------

.. table:: **Table 3** Response parameters

   +--------------+--------+----------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter    | Type   | Description                                                                                                                                              |
   +==============+========+==========================================================================================================================================================+
   | loadbalancer | Object | Specifies the load balancer. For details, see :ref:`Table 4 <en-us_topic_0096561535__en-us_topic_0141008273_en-us_topic_0096561535_table1857116262516>`. |
   +--------------+--------+----------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _en-us_topic_0096561535__en-us_topic_0141008273_en-us_topic_0096561535_table1857116262516:

.. table:: **Table 4** **loadbalancer** parameter description

   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                                                    |
   +=======================+=======================+================================================================================================================================================================================+
   | id                    | String                | Specifies the load balancer ID.                                                                                                                                                |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tenant_id             | String                | Specifies the ID of the project where the load balancer is used.                                                                                                               |
   |                       |                       |                                                                                                                                                                                |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                                                |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                | Specifies the load balancer name.                                                                                                                                              |
   |                       |                       |                                                                                                                                                                                |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                                                |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | description           | String                | Provides supplementary information about the load balancer.                                                                                                                    |
   |                       |                       |                                                                                                                                                                                |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                                                |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | vip_subnet_id         | String                | Specifies the ID of the subnet where the load balancer works.                                                                                                                  |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | vip_port_id           | String                | Specifies the ID of the port bound to the private IP address of the load balancer.                                                                                             |
   |                       |                       |                                                                                                                                                                                |
   |                       |                       | When you create a load balancer, the system automatically creates a port and associates it with a security group. However, the security group will not take effect.            |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | provider              | String                | Specifies the provider of the load balancer.                                                                                                                                   |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | vip_address           | String                | Specifies the private IP address of the load balancer.                                                                                                                         |
   |                       |                       |                                                                                                                                                                                |
   |                       |                       | The value contains a maximum of 64 characters.                                                                                                                                 |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | listeners             | Array                 | Lists the IDs of listeners added to the load balancer. For details, see :ref:`Table 5 <en-us_topic_0096561535__en-us_topic_0141008273_table107875111574>`.                     |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | pools                 | Array                 | Lists the IDs of backend server groups associated with the load balancer. For details, see :ref:`Table 6 <en-us_topic_0096561535__en-us_topic_0141008273_table1566642411246>`. |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | operating_status      | String                | This parameter is reserved, and its value can only be **ONLINE**.                                                                                                              |
   |                       |                       |                                                                                                                                                                                |
   |                       |                       | It specifies the operating status of the load balancer.                                                                                                                        |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | provisioning_status   | String                | This parameter is reserved, and its value can only be **ACTIVE**.                                                                                                              |
   |                       |                       |                                                                                                                                                                                |
   |                       |                       | It specifies the provisioning status of the load balancer.                                                                                                                     |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up        | Boolean               | Specifies the administrative status of the load balancer.                                                                                                                      |
   |                       |                       |                                                                                                                                                                                |
   |                       |                       | This parameter is reserved. The value can be **true** or **false**.                                                                                                            |
   |                       |                       |                                                                                                                                                                                |
   |                       |                       | -  **true**: Enabled                                                                                                                                                           |
   |                       |                       | -  **false**: Disabled                                                                                                                                                         |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tags                  | Array                 | Lists load balancer tags.                                                                                                                                                      |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | created_at            | String                | Specifies the time when the load balancer was created.                                                                                                                         |
   |                       |                       |                                                                                                                                                                                |
   |                       |                       | The UTC time is in *YYYY-MM-DDTHH:MM:SS* format.                                                                                                                               |
   |                       |                       |                                                                                                                                                                                |
   |                       |                       | The value contains a maximum of 19 characters.                                                                                                                                 |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | updated_at            | String                | Specifies the time when the load balancer was updated.                                                                                                                         |
   |                       |                       |                                                                                                                                                                                |
   |                       |                       | The UTC time is in *YYYY-MM-DDTHH:MM:SS* format.                                                                                                                               |
   |                       |                       |                                                                                                                                                                                |
   |                       |                       | The value contains a maximum of 19 characters.                                                                                                                                 |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _en-us_topic_0096561535__en-us_topic_0141008273_table107875111574:

.. table:: **Table 5** **listeners** parameter description

   ========= ====== ============================================
   Parameter Type   Description
   ========= ====== ============================================
   id        String Specifies the ID of the associated listener.
   ========= ====== ============================================

.. _en-us_topic_0096561535__en-us_topic_0141008273_table1566642411246:

.. table:: **Table 6** **pools** parameter description

   +-----------+--------+----------------------------------------------------------+
   | Parameter | Type   | Description                                              |
   +===========+========+==========================================================+
   | id        | String | Specifies the ID of the associated backend server group. |
   +-----------+--------+----------------------------------------------------------+

Example Request
---------------

-  Example request 1: Creating a private network load balancer

   .. code-block:: text

      POST https://{Endpoint}/v2.0/lbaas/loadbalancers

      {
          "loadbalancer": {
              "name": "loadbalancer1",
              "description": "simple lb",
              "tenant_id": "1867112d054b427e808cc6096d8193a1",
              "vip_subnet_id": "58077bdb-d470-424b-8c45-2e3c65060a5b",
              "vip_address": "192.168.0.100",
              "admin_state_up": true
          }
      }

-  Example request 2

   (Bind an EIP to the port that has been bound to the load balancer's private IP address. For details about the parameters, see :ref:`Table 7 <en-us_topic_0096561535__en-us_topic_0141008273_table88881449047>`.)

   .. _en-us_topic_0096561535__en-us_topic_0141008273_table88881449047:

   .. table:: **Table 7** Request parameter

      +-----------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------+
      | Parameter             | Mandatory       | Type            | Description                                                                                                                                      |
      +=======================+=================+=================+==================================================================================================================================================+
      | publicip              | Yes             | Object          | Specifies the EIP. For details, see :ref:`Table 8 <en-us_topic_0096561535__en-us_topic_0141008273_table16889549343>`.                            |
      +-----------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------+
      | bandwidth             | Yes             | Object          | Specifies the bandwidth. For details, see :ref:`Table 9 <en-us_topic_0096561535__en-us_topic_0141008273_table14891249945>`.                      |
      +-----------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------+
      | enterprise_project_id | No              | String          | -  Specifies the enterprise project ID. The value is **0** or a string that contains a maximum of 36 characters in UUID format with hyphens (-). |
      |                       |                 |                 | -  When assigning an EIP, you need to bind an enterprise project ID to the EIP.                                                                  |
      |                       |                 |                 | -  If this parameter is not specified, the default value is **0**.                                                                               |
      |                       |                 |                 |                                                                                                                                                  |
      |                       |                 |                 | .. note::                                                                                                                                        |
      |                       |                 |                 |                                                                                                                                                  |
      |                       |                 |                 |    For more information about enterprise projects and how to obtain enterprise project IDs, see the *Enterprise Management User Guide*.          |
      +-----------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------+

   .. _en-us_topic_0096561535__en-us_topic_0141008273_table16889549343:

   .. table:: **Table 8** **publicip** parameter description

      +-----------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------+
      | Parameter       | Mandatory       | Type            | Description                                                                                                   |
      +=================+=================+=================+===============================================================================================================+
      | type            | Yes             | String          | -  Specifies the EIP type.                                                                                    |
      |                 |                 |                 | -  Constraints:                                                                                               |
      |                 |                 |                 |                                                                                                               |
      |                 |                 |                 |    -  The configured value must be supported by the system.                                                   |
      |                 |                 |                 |    -  **publicip_id** is an IPv4 port. If **publicip_type** is not specified, the default value is **5_bgp**. |
      +-----------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------+
      | ip_version      | No              | Integer         | -  Specifies the EIP version.                                                                                 |
      |                 |                 |                 | -  The value can be **4** and **6**. **4** indicates an IPv4 address, and **6** indicates an IPv6 address.    |
      |                 |                 |                 | -  Constraints:                                                                                               |
      |                 |                 |                 |                                                                                                               |
      |                 |                 |                 |    -  The configured value must be supported by the system.                                                   |
      |                 |                 |                 |    -  If this parameter is left blank or is an empty string, an IPv4 address is assigned by default.          |
      +-----------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------+
      | ip_address      | No              | String          | -  Specifies the EIP to be assigned. The system automatically assigns an EIP if you do not specify it.        |
      |                 |                 |                 | -  The value must be a valid IPv4 address in the available IP address range.                                  |
      +-----------------+-----------------+-----------------+---------------------------------------------------------------------------------------------------------------+

   .. _en-us_topic_0096561535__en-us_topic_0141008273_table14891249945:

   .. table:: **Table 9** **bandwidth** parameter description

      +-----------------+-----------------+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | Parameter       | Mandatory       | Type            | Description                                                                                                                                                                                          |
      +=================+=================+=================+======================================================================================================================================================================================================+
      | name            | Yes             | String          | -  Specifies the bandwidth name.                                                                                                                                                                     |
      |                 |                 |                 | -  The value is a string of 1 to 64 characters that can contain letters, digits, underscores (_), hyphens (-), and periods (.).                                                                      |
      |                 |                 |                 | -  This parameter is mandatory when **share_type** is set to **PER**. This parameter will be ignored when **share_type** is set to **WHOLE** with an ID specified.                                   |
      +-----------------+-----------------+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | size            | Yes             | Integer         | -  Specifies the bandwidth (Mbit/s).                                                                                                                                                                 |
      |                 |                 |                 | -  The value ranges from **1** to **1000** by default. (The range may vary depending on the configuration in each region. You can see the bandwidth range of each region on the management console.) |
      |                 |                 |                 | -  This parameter is mandatory when **share_type** is set to **PER**. This parameter will be ignored when **share_type** is set to **WHOLE** with an ID specified.                                   |
      |                 |                 |                 | -  The minimum increment for bandwidth adjustment varies depending on the bandwidth range. The details are as follows:                                                                               |
      |                 |                 |                 |                                                                                                                                                                                                      |
      |                 |                 |                 |    -  The minimum increment is 1 Mbit/s if the allowed bandwidth ranges from 0 Mbit/s to 300 Mbit/s (with 300 Mbit/s included).                                                                      |
      |                 |                 |                 |    -  The minimum increment is 50 Mbit/s if the allowed bandwidth ranges from 301 Mbit/s to 1000 Mbit/s.                                                                                             |
      |                 |                 |                 |    -  The minimum increment is 500 Mbit/s if the allowed bandwidth is greater than 1000 Mbit/s.                                                                                                      |
      +-----------------+-----------------+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | id              | No              | String          | -  Specifies the bandwidth ID. You can specify an existing shared bandwidth when assigning an EIP.                                                                                                   |
      |                 |                 |                 | -  The value can be the ID of the shared bandwidth whose type is set to **WHOLE**.                                                                                                                   |
      +-----------------+-----------------+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | share_type      | Yes             | String          | -  Specifies the bandwidth type.                                                                                                                                                                     |
      |                 |                 |                 | -  The value is **PER**, indicating that the bandwidth is dedicated.                                                                                                                                 |
      +-----------------+-----------------+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
      | charge_mode     | No              | String          | -  If the value is **traffic**, the bandwidth is billed by traffic.                                                                                                                                  |
      +-----------------+-----------------+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

   -  Step 1: Apply for an EIP.

      .. code-block:: text

         POST https://{VPCEndpoint}/v1/8b7e35ad379141fc9df3e178bd64f55c/publicips

         {
             "publicip": {
                 "type": "5_bgp",
                 "ip_version": 4
             },
             "bandwidth": {
                 "name": "bandwidth123",
                 "size": 10,
                 "share_type": "PER"
             }
         }

   -  .. _en-us_topic_0096561535__en-us_topic_0141008273_li4893134914410:

      Example response

      .. code-block::

         {
             "publicip": {
                 "id": "f588ccfa-8750-4d7c-bf5d-2ede24414706",
                 "status": "PENDING_CREATE",
                 "type": "5_bgp",
                 "public_ip_address": "139.9.204.183",
                 "tenant_id": "8b7e35ad379141fc9df3e178bd64f55c",
                 "ip_version": 4,
                 "create_time": "2019-06-29 06:45:32",
                 "bandwidth_size": 1

             }
         }

   -  Step 2: Bind the EIP. (The value of **public_id** is the same as that in the :ref:`▪ Example response <en-us_topic_0096561535__en-us_topic_0141008273_li4893134914410>`, and the value of **port_id** is the same as that of **vip_port_id** in :ref:`Example response 1 <en-us_topic_0096561535__en-us_topic_0141008273_li4893134914410>`.)

      .. code-block:: text

         PUT /v1/8b7e35ad379141fc9df3e178bd64f55c/publicips/f588ccfa-8750-4d7c-bf5d-2ede24414706

         {
             "publicip": {
                 "port_id": "a7ecbdb5-5a63-41dd-a830-e16c0a7e04a7"
             }
         }

   -  Example response

      .. code-block::

         {
           "publicip": {
             "id": "f588ccfa-8750-4d7c-bf5d-2ede24414706",
             "status": "ACTIVE",
             "type": "5_bgp",
             "port_id": "a7ecbdb5-5a63-41dd-a830-e16c0a7e04a7",
             "public_ip_address": "139.9.204.183",
             "private_ip_address": "192.168.1.131",
             "tenant_id": "8b7e35ad379141fc9df3e178bd64f55c",
             "create_time": "2019-06-29 07:33:18",
             "bandwidth_size": 1,
             "ip_version": 4
           }
         }

   -  After the preceding steps are complete, the load balancer has the capability of accessing the public network. You can access the load balancer using 139.9.204.183, the value of parameter **public_ip_address**.

Example Response
----------------

-  Example response 1

   .. code-block::

      {
          "loadbalancer": {
              "description": "simple lb",
              "provisioning_status": "ACTIVE",
              "tenant_id": "1867112d054b427e808cc6096d8193a1",
              "created_at": "2019-01-19T05:32:56",
              "admin_state_up": true,
              "updated_at": "2019-01-19T05:32:57",
              "id": "ea2843da-4026-49ec-8338-8fa015b067fc",
              "pools": [],
              "listeners": [],
              "vip_port_id": "a7ecbdb5-5a63-41dd-a830-e16c0a7e04a7",
              "operating_status": "ONLINE",
              "vip_address": "192.168.0.100",
              "vip_subnet_id": "58077bdb-d470-424b-8c45-2e3c65060a5b",
              "provider": "vlb",
              "tags": [],
              "name": "loadbalancer1"
          }
      }

-  Example response 2

   .. code-block:: text

      POST https://{Endpoint}/v2.0/lbaas/loadbalancers

      {
          "loadbalancer": {
              "name": "loadbalancer1",
              "description": "simple lb",
              "tenant_id": "1867112d054b427e808cc6096d8193a1",
              "vip_subnet_id": "58077bdb-d470-424b-8c45-2e3c65060a5b",
              "vip_address": "192.168.0.100",
              "admin_state_up": true
          }
      }

After the preceding steps are complete, the load balancer has the capability of accessing the public network. You can access the load balancer using 139.9.204.183, the value of parameter **public_ip_address**.

Status Codes
------------

See :ref:`HTTP Status Codes of Shared Load Balancers <elb_gc_0002>`.
