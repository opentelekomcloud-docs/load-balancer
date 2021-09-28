=============
Load Balancer
=============

Creating a Load Balancer
========================

Function
^^^^^^^^

This API is used to create a private network load balancer. After the load balancer is created, its details, such as load balancer ID, IP address, and subnet ID, are returned.

To create a public network load balancer, you also need to call the API for assigning an EIP and associate this IP address to the port bound to the IP address of the private network load balancer.

URI
^^^

POST /v2.0/lbaas/loadbalancers

Request
^^^^^^^

.. table:: **Table 1** Request parameters

   +--------------+-----------+--------+-------------------------------------------------------------------------------+
   | Parameter    | Mandatory | Type   | Description                                                                   |
   +==============+===========+========+===============================================================================+
   | loadbalancer | Yes       | Object | Specifies the load balancer. For details, see Table 2.                        |
   +--------------+-----------+--------+-------------------------------------------------------------------------------+

.. table:: **Table 2** **loadbalancer** parameter description

   +----------------+-----------+---------+-----------------------------+
   | Parameter      | Mandatory | Type    | Description                 |
   +================+===========+=========+=============================+
   | name           | No        | String  | Specifies the load balancer |
   |                |           |         | name.                       |
   |                |           |         |                             |
   |                |           |         | The value contains a        |
   |                |           |         | maximum of 255 characters.  |
   +----------------+-----------+---------+-----------------------------+
   | description    | No        | String  | Provides supplementary      |
   |                |           |         | information about the load  |
   |                |           |         | balancer.                   |
   |                |           |         |                             |
   |                |           |         | The value contains a        |
   |                |           |         | maximum of 255 characters.  |
   +----------------+-----------+---------+-----------------------------+
   | tenant_id      | No        | String  | Specifies the ID of the     |
   |                |           |         | project where the load      |
   |                |           |         | balancer is used.           |
   |                |           |         |                             |
   |                |           |         | The value contains a        |
   |                |           |         | maximum of 255 characters.  |
   |                |           |         |                             |
   |                |           |         | The value must be the same  |
   |                |           |         | as the value of             |
   |                |           |         | **project_id** in the       |
   |                |           |         | token.                      |
   +----------------+-----------+---------+-----------------------------+
   | vip_subnet_id  | Yes       | String  | Specifies the ID of the     |
   |                |           |         | subnet where the load       |
   |                |           |         | balancer works. You can     |
   |                |           |         | obtain the value by calling |
   |                |           |         | the API for querying        |
   |                |           |         | subnets {VPC                |
   |                |           |         | endpoint}/v2.0/subnets}     |
   |                |           |         | using the GET method.       |
   |                |           |         |                             |
   |                |           |         | The private IP address of   |
   |                |           |         | the load balancer is in     |
   |                |           |         | this subnet.                |
   |                |           |         |                             |
   |                |           |         | Only IPv4 subnets are       |
   |                |           |         | supported. IPv6 subnets are |
   |                |           |         | not supported.              |
   +----------------+-----------+---------+-----------------------------+
   | provider       | No        | String  | Specifies the provider of   |
   |                |           |         | the load balancer.          |
   |                |           |         |                             |
   |                |           |         | The value can only be       |
   |                |           |         | **vlb**.                    |
   +----------------+-----------+---------+-----------------------------+
   | vip_address    | No        | String  | Specifies the private IP    |
   |                |           |         | address of the load         |
   |                |           |         | balancer.                   |
   |                |           |         |                             |
   |                |           |         | This IP address must be the |
   |                |           |         | one in the subnet specified |
   |                |           |         | by **vip_subnet_id**. If    |
   |                |           |         | this parameter is not       |
   |                |           |         | specified, an IP address is |
   |                |           |         | automatically assigned to   |
   |                |           |         | the load balancer from the  |
   |                |           |         | subnet specified by         |
   |                |           |         | **vip_subnet_id**.          |
   |                |           |         |                             |
   |                |           |         | The value contains a        |
   |                |           |         | maximum of 64 characters.   |
   +----------------+-----------+---------+-----------------------------+
   | admin_state_up | No        | Boolean | Specifies the               |
   |                |           |         | administrative status of    |
   |                |           |         | the load balancer.          |
   |                |           |         |                             |
   |                |           |         | This parameter is reserved. |
   |                |           |         | The default value is        |
   |                |           |         | **true**.                   |
   +----------------+-----------+---------+-----------------------------+

Response
^^^^^^^^

.. table:: **Table 3** Response parameters

   +--------------+--------+-------------------------------------------------------+
   | Parameter    | Type   | Description                                           |
   +==============+========+=======================================================+
   | loadbalancer | Object | Specifies the load balancer. For details, see Table 4 |
   +--------------+--------+-------------------------------------------------------+

.. table:: **Table 4** **loadbalancer** parameter description

   +---------------------+---------+---------------------------------------+
   | Parameter           | Type    | Description                           |
   +=====================+=========+=======================================+
   | id                  | String  | Specifies the load balancer ID.       |
   +---------------------+---------+---------------------------------------+
   | tenant_id           | String  | Specifies the ID of the project where |
   |                     |         | the load balancer is used.            |
   |                     |         |                                       |
   |                     |         | The value contains a maximum of 255   |
   |                     |         | characters.                           |
   +---------------------+---------+---------------------------------------+
   | name                | String  | Specifies the load balancer name.     |
   |                     |         |                                       |
   |                     |         | The value contains a maximum of 255   |
   |                     |         | characters.                           |
   +---------------------+---------+---------------------------------------+
   | description         | String  | Provides supplementary information    |
   |                     |         | about the load balancer.              |
   |                     |         |                                       |
   |                     |         | The value contains a maximum of 255   |
   |                     |         | characters.                           |
   +---------------------+---------+---------------------------------------+
   | vip_subnet_id       | String  | Specifies the ID of the subnet where  |
   |                     |         | the load balancer works.              |
   +---------------------+---------+---------------------------------------+
   | vip_port_id         | String  | Specifies the ID of the port bound to |
   |                     |         | the private IP address of the load    |
   |                     |         | balancer.                             |
   |                     |         |                                       |
   |                     |         | When you create a load balancer, the  |
   |                     |         | system automatically creates a port   |
   |                     |         | and associates it with a security     |
   |                     |         | group. However, the security group    |
   |                     |         | will not take effect.                 |
   +---------------------+---------+---------------------------------------+
   | provider            | String  | Specifies the provider of the load    |
   |                     |         | balancer.                             |
   +---------------------+---------+---------------------------------------+
   | vip_address         | String  | Specifies the private IP address of   |
   |                     |         | the load balancer.                    |
   |                     |         |                                       |
   |                     |         | The value contains a maximum of 64    |
   |                     |         | characters.                           |
   +---------------------+---------+---------------------------------------+
   | listeners           | Array   | Lists the IDs of listeners added to   |
   |                     |         | the load balancer. For details, see   |
   |                     |         | Table 5.                              |
   +---------------------+---------+---------------------------------------+
   | pools               | Array   | Lists the IDs of backend server       |
   |                     |         | groups associated with the load       |
   |                     |         | balancer. For details, see Table 6.   |
   +---------------------+---------+---------------------------------------+
   | operating_status    | String  | This parameter is reserved, and its   |
   |                     |         | value can only be **ONLINE**.         |
   |                     |         |                                       |
   |                     |         | It specifies the operating status of  |
   |                     |         | the load balancer.                    |
   +---------------------+---------+---------------------------------------+
   | provisioning_status | String  | This parameter is reserved, and its   |
   |                     |         | value can only be **ACTIVE**.         |
   |                     |         |                                       |
   |                     |         | It specifies the provisioning status  |
   |                     |         | of the load balancer.                 |
   +---------------------+---------+---------------------------------------+
   | admin_state_up      | Boolean | Specifies the administrative status   |
   |                     |         | of the load balancer.                 |
   |                     |         |                                       |
   |                     |         | This parameter is reserved. The value |
   |                     |         | can be **true** or **false**.         |
   |                     |         |                                       |
   |                     |         | -  **true**: Enabled                  |
   |                     |         | -  **false**: Disabled                |
   +---------------------+---------+---------------------------------------+
   | tags                | Array   | Lists load balancer tags.             |
   +---------------------+---------+---------------------------------------+
   | created_at          | String  | Specifies the time when the load      |
   |                     |         | balancer was created.                 |
   |                     |         |                                       |
   |                     |         | The UTC time is in                    |
   |                     |         | *YYYY-MM-DDTHH:MM:SS* format.         |
   |                     |         |                                       |
   |                     |         | The value contains a maximum of 19    |
   |                     |         | characters.                           |
   +---------------------+---------+---------------------------------------+
   | updated_at          | String  | Specifies the time when the load      |
   |                     |         | balancer was updated.                 |
   |                     |         |                                       |
   |                     |         | The UTC time is in                    |
   |                     |         | *YYYY-MM-DDTHH:MM:SS* format.         |
   |                     |         |                                       |
   |                     |         | The value contains a maximum of 19    |
   |                     |         | characters.                           |
   +---------------------+---------+---------------------------------------+

.. table:: **Table 5** **listeners** parameter description

   ========= ====== ============================================
   Parameter Type   Description
   ========= ====== ============================================
   id        String Specifies the ID of the associated listener.
   ========= ====== ============================================

.. table:: **Table 6** **pools** parameter description

   ========= ====== ========================================================
   Parameter Type   Description
   ========= ====== ========================================================
   id        String Specifies the ID of the associated backend server group.
   ========= ====== ========================================================

Example Request
^^^^^^^^^^^^^^^

-  Example request 1: Creating a private network load balancer

   .. code::

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

   (Bind an EIP to the port that has been bound to the load balancer's private IP address. For details about the parameters, see Table 7.)

.. table:: **Table 7** Request parameter

   +-----------------------+-----------+--------+-----------------------------+
   | Parameter             | Mandatory | Type   | Description                 |
   +=======================+===========+========+=============================+
   | publicip              | Yes       | Object | Specifies the EIP. For      |
   |                       |           |        | details, see Table 8.       |
   +-----------------------+-----------+--------+-----------------------------+
   | bandwidth             | Yes       | Object | Specifies the bandwidth.    |
   |                       |           |        | For details, see Table 10.  |
   +-----------------------+-----------+--------+-----------------------------+
   | enterprise_project_id | No        | String | -  Specifies the enterprise |
   |                       |           |        |    project ID. The value is |
   |                       |           |        |    **0** or a string that   |
   |                       |           |        |    contains a maximum of 36 |
   |                       |           |        |    characters in UUID       |
   |                       |           |        |    format with hyphens (-). |
   |                       |           |        | -  When assigning an EIP,   |
   |                       |           |        |    you need to bind an      |
   |                       |           |        |    enterprise project ID to |
   |                       |           |        |    the EIP.                 |
   |                       |           |        | -  If this parameter is not |
   |                       |           |        |    specified, the default   |
   |                       |           |        |    value is **0**.          |
   |                       |           |        |                             |
   |                       |           |        | NOTE:                       |
   |                       |           |        | For more information about  |
   |                       |           |        | enterprise projects and how |
   |                       |           |        | to obtain enterprise        |
   |                       |           |        | project IDs, see the        |
   |                       |           |        | *Enterprise Management User |
   |                       |           |        | Guide*.                     |
   +-----------------------+-----------+--------+-----------------------------+

.. table:: **Table 8** **publicip** parameter description

   +------------+-----------+---------+-----------------------------+
   | Parameter  | Mandatory | Type    | Description                 |
   +============+===========+=========+=============================+
   | type       | Yes       | String  | -  Specifies the EIP type.  |
   |            |           |         | -  Constraints:             |
   |            |           |         |                             |
   |            |           |         |    -  The configured value  |
   |            |           |         |       must be supported by  |
   |            |           |         |       the system.           |
   |            |           |         |    -  **publicip_id** is an |
   |            |           |         |       IPv4 port. If         |
   |            |           |         |       **publicip_type** is  |
   |            |           |         |       not specified, the    |
   |            |           |         |       default value is      |
   |            |           |         |       **5_bgp**.            |
   +------------+-----------+---------+-----------------------------+
   | ip_version | No        | Integer | -  Specifies the EIP        |
   |            |           |         |    version.                 |
   |            |           |         | -  The value can be **4**   |
   |            |           |         |    and **6**. **4**         |
   |            |           |         |    indicates an IPv4        |
   |            |           |         |    address, and **6**       |
   |            |           |         |    indicates an IPv6        |
   |            |           |         |    address.                 |
   |            |           |         | -  Constraints:             |
   |            |           |         |                             |
   |            |           |         |    -  The configured value  |
   |            |           |         |       must be supported by  |
   |            |           |         |       the system.           |
   |            |           |         |    -  If this parameter is  |
   |            |           |         |       left blank or is an   |
   |            |           |         |       empty string, an IPv4 |
   |            |           |         |       address is assigned   |
   |            |           |         |       by default.           |
   +------------+-----------+---------+-----------------------------+
   | ip_address | No        | String  | -  Specifies the EIP to be  |
   |            |           |         |    assigned. The system     |
   |            |           |         |    automatically assigns an |
   |            |           |         |    EIP if you do not        |
   |            |           |         |    specify it.              |
   |            |           |         | -  The value must be a      |
   |            |           |         |    valid IPv4 address in    |
   |            |           |         |    the available IP address |
   |            |           |         |    range.                   |
   +------------+-----------+---------+-----------------------------+


.. table:: **Table 9** **bandwidth** parameter description

   +-------------+-----------+---------+-----------------------------+
   | Parameter   | Mandatory | Type    | Description                 |
   +=============+===========+=========+=============================+
   | name        | Yes       | String  | -  Specifies the bandwidth  |
   |             |           |         |    name.                    |
   |             |           |         | -  The value is a string of |
   |             |           |         |    1 to 64 characters that  |
   |             |           |         |    can contain letters,     |
   |             |           |         |    digits, underscores (_), |
   |             |           |         |    hyphens (-), and periods |
   |             |           |         |    (.).                     |
   |             |           |         | -  This parameter is        |
   |             |           |         |    mandatory when           |
   |             |           |         |    **share_type** is set to |
   |             |           |         |    **PER**. This parameter  |
   |             |           |         |    will be ignored when     |
   |             |           |         |    **share_type** is set to |
   |             |           |         |    **WHOLE** with an ID     |
   |             |           |         |    specified.               |
   +-------------+-----------+---------+-----------------------------+
   | size        | Yes       | Integer | -  Specifies the bandwidth  |
   |             |           |         |    (Mbit/s).                |
   |             |           |         | -  The value ranges from    |
   |             |           |         |    **1** to **1000** by     |
   |             |           |         |    default. (The range may  |
   |             |           |         |    vary depending on the    |
   |             |           |         |    configuration in each    |
   |             |           |         |    region. You can see the  |
   |             |           |         |    bandwidth range of each  |
   |             |           |         |    region on the management |
   |             |           |         |    console.)                |
   |             |           |         | -  This parameter is        |
   |             |           |         |    mandatory when           |
   |             |           |         |    **share_type** is set to |
   |             |           |         |    **PER**. This parameter  |
   |             |           |         |    will be ignored when     |
   |             |           |         |    **share_type** is set to |
   |             |           |         |    **WHOLE** with an ID     |
   |             |           |         |    specified.               |
   |             |           |         | -  The minimum increment    |
   |             |           |         |    for bandwidth adjustment |
   |             |           |         |    varies depending on the  |
   |             |           |         |    bandwidth range. The     |
   |             |           |         |    details are as follows:  |
   |             |           |         |                             |
   |             |           |         |    -  The minimum increment |
   |             |           |         |       is 1 Mbit/s if the    |
   |             |           |         |       allowed bandwidth     |
   |             |           |         |       ranges from 0 Mbit/s  |
   |             |           |         |       to 300 Mbit/s (with   |
   |             |           |         |       300 Mbit/s included). |
   |             |           |         |    -  The minimum increment |
   |             |           |         |       is 50 Mbit/s if the   |
   |             |           |         |       allowed bandwidth     |
   |             |           |         |       ranges from 300       |
   |             |           |         |       Mbit/s to 1000        |
   |             |           |         |       Mbit/s.               |
   |             |           |         |    -  The minimum increment |
   |             |           |         |       is 500 Mbit/s if the  |
   |             |           |         |       allowed bandwidth is  |
   |             |           |         |       greater than 1000     |
   |             |           |         |       Mbit/s.               |
   +-------------+-----------+---------+-----------------------------+
   | id          | No        | String  | -  Specifies the bandwidth  |
   |             |           |         |    ID. You can specify an   |
   |             |           |         |    existing shared          |
   |             |           |         |    bandwidth when assigning |
   |             |           |         |    an EIP.                  |
   |             |           |         | -  The value can be the ID  |
   |             |           |         |    of the shared bandwidth  |
   |             |           |         |    whose type is set to     |
   |             |           |         |    **WHOLE**.               |
   +-------------+-----------+---------+-----------------------------+
   | share_type  | Yes       | String  | -  Specifies the bandwidth  |
   |             |           |         |    type.                    |
   |             |           |         | -  The value is **PER**,    |
   |             |           |         |    indicating that the      |
   |             |           |         |    bandwidth is dedicated.  |
   +-------------+-----------+---------+-----------------------------+
   | charge_mode | No        | String  | -  If the value is          |
   |             |           |         |    **traffic**, the         |
   |             |           |         |    bandwidth is billed by   |
   |             |           |         |    traffic.                 |
   +-------------+-----------+---------+-----------------------------+


-  Step 1: Apply for an EIP.

   .. code::

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

.. _Example EIP response:

-  Example response

   .. code::

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

-  Step 2: Bind the EIP. (Values of **public_id** and **port_id** are the same as that in the `Example EIP response`_.)

   .. code::

      PUT /v1/8b7e35ad379141fc9df3e178bd64f55c/publicips/f588ccfa-8750-4d7c-bf5d-2ede24414706

      {
          "publicip": {
              "port_id": "a7ecbdb5-5a63-41dd-a830-e16c0a7e04a7"
          }
      }

-  Example response

   .. code::

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
^^^^^^^^^^^^^^^^

-  Example response 1

   .. code::

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

   .. code::

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
^^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Querying Load Balancers
=======================

Function
^^^^^^^^

This API is used to query load balancers and display them in a list. Filter query and pagination query are supported. Unless otherwise specified, exact match is applied.

Constraints
^^^^^^^^^^^

Parameters **marker**, **limit**, and **page_reverse** are used for pagination query. Parameters **marker** and **page_reverse** take effect only when they are used together with parameter **limit**.

URI
^^^

GET /v2.0/lbaas/loadbalancers

Request
^^^^^^^

.. table:: **Table 1** Parameter description

   +---------------------+-----------+---------+-----------------------------+
   | Parameter           | Mandatory | Type    | Description                 |
   +=====================+===========+=========+=============================+
   | marker              | No        | String  | Specifies the ID of the     |
   |                     |           |         | load balancer from which    |
   |                     |           |         | pagination query starts,    |
   |                     |           |         | that is, the ID of the last |
   |                     |           |         | load balancer on the        |
   |                     |           |         | previous page.              |
   |                     |           |         |                             |
   |                     |           |         | This parameter must be used |
   |                     |           |         | together with **limit**.    |
   +---------------------+-----------+---------+-----------------------------+
   | limit               | No        | Integer | Specifies the number of     |
   |                     |           |         | load balancers on each      |
   |                     |           |         | page.                       |
   +---------------------+-----------+---------+-----------------------------+
   | page_reverse        | No        | Boolean | Specifies the page          |
   |                     |           |         | direction. The value can be |
   |                     |           |         | **true** or **false**, and  |
   |                     |           |         | the default value is        |
   |                     |           |         | **false**. The last page in |
   |                     |           |         | the list requested with     |
   |                     |           |         | **page_reverse** set to     |
   |                     |           |         | **false** will not contain  |
   |                     |           |         | the "next" link, and the    |
   |                     |           |         | last page in the list       |
   |                     |           |         | requested with              |
   |                     |           |         | **page_reverse** set to     |
   |                     |           |         | **true** will not contain   |
   |                     |           |         | the "previous" link.        |
   |                     |           |         |                             |
   |                     |           |         | This parameter must be used |
   |                     |           |         | together with **limit**.    |
   +---------------------+-----------+---------+-----------------------------+
   | tenant_id           | No        | String  | Specifies the ID of the     |
   |                     |           |         | project where the load      |
   |                     |           |         | balancer is used.           |
   +---------------------+-----------+---------+-----------------------------+
   | id                  | No        | String  | Specifies the load balancer |
   |                     |           |         | ID.                         |
   +---------------------+-----------+---------+-----------------------------+
   | description         | No        | String  | Provides supplementary      |
   |                     |           |         | information about the load  |
   |                     |           |         | balancer.                   |
   |                     |           |         |                             |
   |                     |           |         | The value contains a        |
   |                     |           |         | maximum of 255 characters.  |
   +---------------------+-----------+---------+-----------------------------+
   | name                | No        | String  | Specifies the load balancer |
   |                     |           |         | name.                       |
   |                     |           |         |                             |
   |                     |           |         | The value contains a        |
   |                     |           |         | maximum of 255 characters.  |
   +---------------------+-----------+---------+-----------------------------+
   | operating_status    | No        | String  | This parameter is reserved, |
   |                     |           |         | and its value can only be   |
   |                     |           |         | **ONLINE**.                 |
   |                     |           |         |                             |
   |                     |           |         | It specifies the operating  |
   |                     |           |         | status of the load          |
   |                     |           |         | balancer.                   |
   +---------------------+-----------+---------+-----------------------------+
   | provisioning_status | No        | String  | This parameter is reserved, |
   |                     |           |         | and its value can only be   |
   |                     |           |         | **ACTIVE**.                 |
   |                     |           |         |                             |
   |                     |           |         | It specifies the            |
   |                     |           |         | provisioning status of the  |
   |                     |           |         | load balancer.              |
   +---------------------+-----------+---------+-----------------------------+
   | admin_state_up      | No        | Boolean | This parameter is reserved, |
   |                     |           |         | and its value can only be   |
   |                     |           |         | **true**.                   |
   |                     |           |         |                             |
   |                     |           |         | It specifies the            |
   |                     |           |         | administrative status of    |
   |                     |           |         | the load balancer.          |
   +---------------------+-----------+---------+-----------------------------+
   | vip_address         | No        | String  | Specifies the private IP    |
   |                     |           |         | address of the load         |
   |                     |           |         | balancer.                   |
   |                     |           |         |                             |
   |                     |           |         | The value contains a        |
   |                     |           |         | maximum of 64 characters.   |
   +---------------------+-----------+---------+-----------------------------+
   | vip_port_id         | No        | String  | Specifies the ID of the     |
   |                     |           |         | port bound to the private   |
   |                     |           |         | IP address of the load      |
   |                     |           |         | balancer.                   |
   +---------------------+-----------+---------+-----------------------------+
   | vip_subnet_id       | No        | String  | Specifies the ID of the     |
   |                     |           |         | subnet where the load       |
   |                     |           |         | balancer works.             |
   +---------------------+-----------+---------+-----------------------------+
   | member_address      | No        | String  | Specifies the IP address of |
   |                     |           |         | the backend server          |
   |                     |           |         | associated with the load    |
   |                     |           |         | balancer.                   |
   +---------------------+-----------+---------+-----------------------------+
   | member_device_id    | No        | String  | Specifies the ID of the     |
   |                     |           |         | cloud server used as the    |
   |                     |           |         | backend server associated   |
   |                     |           |         | with the load balancer.     |
   +---------------------+-----------+---------+-----------------------------+
   | vpc_id              | No        | String  | Specifies the ID of the VPC |
   |                     |           |         | where the load balancer     |
   |                     |           |         | works.                      |
   +---------------------+-----------+---------+-----------------------------+

Response
^^^^^^^^

.. table:: **Table 2** Response parameters

   +---------------------+-------+------------------------------------------------------------------------------------+
   | Parameter           | Type  | Description                                                                        |
   +=====================+=======+====================================================================================+
   | loadbalancers       | Array | Lists the load balancers. For details, see :ref:`qlb_t3`.                          |
   +---------------------+-------+------------------------------------------------------------------------------------+
   | loadbalancers_links | Array | Provides links to the previous or next page during pagination query, respectively. |
   |                     |       | This parameter exists only in the response body of pagination query. For details,  |
   |                     |       | see :ref:`qlb_t6`.                                                                 |
   +---------------------+-------+------------------------------------------------------------------------------------+

.. _qlb_t3:
.. table:: **Table 3** **loadbalancer** parameter description

   +---------------------+---------+-------------------------------------------+
   | Parameter           | Type    | Description                               |
   +=====================+=========+===========================================+
   | id                  | String  | Specifies the load balancer ID.           |
   +---------------------+---------+-------------------------------------------+
   | tenant_id           | String  | Specifies the ID of the project where     |
   |                     |         | the load balancer is used.                |
   |                     |         |                                           |
   |                     |         | The value contains a maximum of 255       |
   |                     |         | characters.                               |
   +---------------------+---------+-------------------------------------------+
   | name                | String  | Specifies the load balancer name.         |
   |                     |         |                                           |
   |                     |         | The value contains a maximum of 255       |
   |                     |         | characters.                               |
   +---------------------+---------+-------------------------------------------+
   | description         | String  | Provides supplementary information        |
   |                     |         | about the load balancer.                  |
   |                     |         |                                           |
   |                     |         | The value contains a maximum of 255       |
   |                     |         | characters.                               |
   +---------------------+---------+-------------------------------------------+
   | vip_subnet_id       | String  | Specifies the ID of the subnet where      |
   |                     |         | the load balancer works.                  |
   +---------------------+---------+-------------------------------------------+
   | vip_port_id         | String  | Specifies the ID of the port bound to     |
   |                     |         | the private IP address of the load        |
   |                     |         | balancer.                                 |
   |                     |         |                                           |
   |                     |         | When you create a load balancer, the      |
   |                     |         | system automatically creates a port       |
   |                     |         | and associates it with a security         |
   |                     |         | group. However, the security group        |
   |                     |         | will not take effect.                     |
   +---------------------+---------+-------------------------------------------+
   | provider            | String  | Specifies the provider of the load        |
   |                     |         | balancer.                                 |
   +---------------------+---------+-------------------------------------------+
   | vip_address         | String  | Specifies the private IP address of       |
   |                     |         | the load balancer.                        |
   |                     |         |                                           |
   |                     |         | The value contains a maximum of 64        |
   |                     |         | characters.                               |
   +---------------------+---------+-------------------------------------------+
   | listeners           | Array   | Lists the IDs of listeners added to       |
   |                     |         | the load balancer. For details, see       |
   |                     |         | :ref:`qlb_t4`.                            |
   +---------------------+---------+-------------------------------------------+
   | pools               | Array   | Lists the IDs of backend server           |
   |                     |         | groups associated with the load           |
   |                     |         | balancer. For details, see :ref:`qlb_t5`. |
   +---------------------+---------+-------------------------------------------+
   | operating_status    | String  | This parameter is reserved, and its       |
   |                     |         | value can only be **ONLINE**.             |
   |                     |         |                                           |
   |                     |         | It specifies the operating status of      |
   |                     |         | the load balancer.                        |
   +---------------------+---------+-------------------------------------------+
   | provisioning_status | String  | This parameter is reserved, and its       |
   |                     |         | value can only be **ACTIVE**.             |
   |                     |         |                                           |
   |                     |         | It specifies the provisioning status      |
   |                     |         | of the load balancer.                     |
   +---------------------+---------+-------------------------------------------+
   | admin_state_up      | Boolean | Specifies the administrative status       |
   |                     |         | of the load balancer.                     |
   |                     |         |                                           |
   |                     |         | This parameter is reserved. The value     |
   |                     |         | can be **true** or **false**.             |
   |                     |         |                                           |
   |                     |         | -  **true**: Enabled                      |
   |                     |         | -  **false**: Disabled                    |
   +---------------------+---------+-------------------------------------------+
   | tags                | Array   | Lists load balancer tags.                 |
   +---------------------+---------+-------------------------------------------+
   | created_at          | String  | Specifies the time when the load          |
   |                     |         | balancer was created.                     |
   |                     |         |                                           |
   |                     |         | The UTC time is in                        |
   |                     |         | *YYYY-MM-DDTHH:MM:SS* format.             |
   |                     |         |                                           |
   |                     |         | The value contains a maximum of 19        |
   |                     |         | characters.                               |
   +---------------------+---------+-------------------------------------------+
   | updated_at          | String  | Specifies the time when the load          |
   |                     |         | balancer was updated.                     |
   |                     |         |                                           |
   |                     |         | The UTC time is in                        |
   |                     |         | *YYYY-MM-DDTHH:MM:SS* format.             |
   |                     |         |                                           |
   |                     |         | The value contains a maximum of 19        |
   |                     |         | characters.                               |
   +---------------------+---------+-------------------------------------------+

.. _qlb_t4:
.. table:: **Table 4** **listeners** parameter description

   ========= ====== ============================================
   Parameter Type   Description
   ========= ====== ============================================
   id        String Specifies the ID of the associated listener.
   ========= ====== ============================================

.. _qlb_t5:
.. table:: **Table 5** **pools** parameter description

   ========= ====== ========================================================
   Parameter Type   Description
   ========= ====== ========================================================
   id        String Specifies the ID of the associated backend server group.
   ========= ====== ========================================================

.. _qlb_t6:
.. table:: **Table 6** **loadbalancers_links** parameter description

   +-----------+--------+---------------------------------------+
   | Parameter | Type   | Description                           |
   +===========+========+=======================================+
   | href      | String | Provides links to the previous or     |
   |           |        | next page during pagination query,    |
   |           |        | respectively.                         |
   +-----------+--------+---------------------------------------+
   | rel       | String | Specifies the prompt of the previous  |
   |           |        | or next page.                         |
   |           |        |                                       |
   |           |        | The value can be **next** or          |
   |           |        | **previous**. The value **next**      |
   |           |        | indicates the Hypertext Reference     |
   |           |        | (href) containing the URL of the next |
   |           |        | page, and **previous** indicates the  |
   |           |        | href containing the URL of the        |
   |           |        | previous page.                        |
   +-----------+--------+---------------------------------------+

Example Request
^^^^^^^^^^^^^^^

-  Example request 1: Querying all load balancers

   .. code::

      GET https://{Endpoint}/v2.0/lbaas/loadbalancers

-  Example request 2: Querying load balancers by page (Each page contains one load balancer. The ID of the start load balancer is **165b6a38-5278-4569-b747-b2ee65ea84a4**. The load balancer after **165b6a38-5278-4569-b747-b2ee65ea84a4** is the queried load balancer.)

   .. code::

      GET https://{Endpoint}/v2.0/lbaas/loadbalancers?limit=1&marker=165b6a38-5278-4569-b747-b2ee65ea84a4

-  Example request 3: Querying the load balancer using the IP address of a backend server (192.168.0.191)

   .. code::

      GET https://{Endpoint}/v2.0/lbaas/loadbalancers?member_address=192.168.0.181

Example Response
^^^^^^^^^^^^^^^^

-  Example response 1

   .. code::

      {
          "loadbalancers": [
              {
                  "description": "simple lb",
                  "admin_state_up": true,
                  "tenant_id": "1a3e005cf9ce40308c900bcb08e5320c",

                  "provisioning_status": "ACTIVE",
                  "vip_subnet_id": "5328f1e6-ce29-44f1-9493-b128a5653350",
                  "listeners": [
                      {
                          "id": "45196943-2907-4369-87b1-c009b1d7ac35"
                      }
                  ],
                  "vip_address": "10.0.0.2",
                  "vip_port_id": "cbced4fe-6f6f-4fd6-9348-0c3d1219d6ca",
                  "provider": "vlb",
                  "pools": [
                      {
                          "id": "21d49cf7-4fd3-4cb6-8c48-b7fc6c259aab"
                  }
                  ],
                  "id": "a9729389-6147-41a3-ab22-a24aed8692b2",
                  "operating_status": "ONLINE",
                  "tags": [],
                  "name": "loadbalancer1",
                  "created_at": "2018-07-25T01:54:13",
                  "updated_at": "2018-07-25T01:54:14"
              }
          ]
      }

-  Example response 2

   .. code::

      {
          "loadbalancers": [
              {
                  "description": "",
                  "provisioning_status": "ACTIVE",
                  "tenant_id": "601240b9c5c94059b63d484c92cfe308",

                  "admin_state_up": true,
                  "provider": "vlb",
                  "pools": [
                      {
                          "id": "b13dba4c-a44c-4c40-8f6e-ce7a162b9f22"
                      },
                      {
                          "id": "4b9e765f-82ee-4128-911b-0a2d9ebc74c7"
                      }
                  ],
                  "listeners": [
                      {
                          "id": "21c41336-d0d3-4349-8641-6e82b4a4d097"
                      }
                  ],
                  "vip_port_id": "44ac5d9b-b0c0-4810-9a9d-c4dbf541e47e",
                  "operating_status": "ONLINE",
                  "vip_address": "192.168.0.234",
                  "vip_subnet_id": "9d60827e-0e5c-490a-8183-0b6ebf9084ca",
                  "id": "e79a7dd6-3a38-429a-95f9-c7f78b346cbe",
                  "tags": [],
                  "name": "elb-robot",
                  "created_at": "2018-07-25T01:54:13",
                  "updated_at": "2018-07-25T01:54:14"
              }
          ],
          "loadbalancers_links": [
              {
                  "href": "https://network.Region.dc1.domainname.com/v2.0/lbaas/loadbalancers?limit=10&marker=e79a7dd6-3a38-429a-95f9-c7f78b346cbe&page_reverse=True",
                    "rel": "previous"
              }
          ]
      }

-  Example response 3

   .. code::

      {
          "loadbalancers": [
              {
                  "description": "",
                  "provisioning_status": "ACTIVE",
                  "tenant_id": "601240b9c5c94059b63d484c92cfe308",

                  "created_at": "2018-11-29T13:55:20",
                  "admin_state_up": true,
                  "update_at": "2018-11-29T13:55:21",
                  "id": "c1127125-64a9-4394-a08a-ef3be8f7ef9c",
                  "pools": [
                      {
                          "id": "2f6895be-019b-4c82-9b53-c4a2ac009e20"
                      }
                  ],
                  "listeners": [
                      {
                          "id": "5c63d176-444f-4c75-9cfe-bcb8a05a845c"
                      }
                  ],
                  "vip_port_id": "434ac600-b779-4428-b7a7-830e047511f1",
                  "operating_status": "ONLINE",
                  "vip_address": "192.168.0.181",
                  "vip_subnet_id": "9a303536-417c-45dc-a6db-1234b9e1c2b2",
                  "provider": "vlb",
                  "tags": [],
                  "name": "elb-ftci"

              }
          ]
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Querying Details of a Load Balancer
===================================

Response
^^^^^^^^

.. table:: **Table 1** Parameter description

   +--------------+--------+--------------------------------------------------------------+
   | Parameter    | Type   | Description                                                  |
   +==============+========+==============================================================+
   | loadbalancer | Object | Specifies the load balancer. For details, see :ref:`slb_t2`. |
   +--------------+--------+--------------------------------------------------------------+

.. _slb_t2:
.. table:: **Table 2** **loadbalancer** parameter description

   +---------------------+---------+------------------------------------------+
   | Parameter           | Type    | Description                              |
   +=====================+=========+==========================================+
   | id                  | String  | Specifies the load balancer ID.          |
   +---------------------+---------+------------------------------------------+
   | tenant_id           | String  | Specifies the ID of the project where    |
   |                     |         | the load balancer is used.               |
   |                     |         |                                          |
   |                     |         | The value contains a maximum of 255      |
   |                     |         | characters.                              |
   +---------------------+---------+------------------------------------------+
   | name                | String  | Specifies the load balancer name.        |
   |                     |         |                                          |
   |                     |         | The value contains a maximum of 255      |
   |                     |         | characters.                              |
   +---------------------+---------+------------------------------------------+
   | description         | String  | Provides supplementary information       |
   |                     |         | about the load balancer.                 |
   |                     |         |                                          |
   |                     |         | The value contains a maximum of 255      |
   |                     |         | characters.                              |
   +---------------------+---------+------------------------------------------+
   | vip_subnet_id       | String  | Specifies the ID of the subnet where     |
   |                     |         | the load balancer works.                 |
   +---------------------+---------+------------------------------------------+
   | vip_port_id         | String  | Specifies the ID of the port bound to    |
   |                     |         | the private IP address of the load       |
   |                     |         | balancer.                                |
   +---------------------+---------+------------------------------------------+
   | provider            | String  | Specifies the provider of the load       |
   |                     |         | balancer.                                |
   +---------------------+---------+------------------------------------------+
   | vip_address         | String  | Specifies the private IP address of      |
   |                     |         | the load balancer.                       |
   |                     |         |                                          |
   |                     |         | The value contains a maximum of 64       |
   |                     |         | characters.                              |
   +---------------------+---------+------------------------------------------+
   | listeners           | Array   | Lists the IDs of listeners added to      |
   |                     |         | the load balancer. For details, see      |
   |                     |         | :ref:`slb_t3`                            |
   +---------------------+---------+------------------------------------------+
   | pools               | Array   | Lists the IDs of backend server          |
   |                     |         | groups associated with the load          |
   |                     |         | balancer. For details, see :ref:`slb_t4` |
   +---------------------+---------+------------------------------------------+
   | operating_status    | String  | Specifies the operating status of the    |
   |                     |         | load balancer.                           |
   |                     |         |                                          |
   |                     |         | The value can be **ONLINE**,             |
   |                     |         | **OFFLINE**, **DEGRADED**,               |
   |                     |         | **DISABLED**, or **NO_MONITOR**.         |
   |                     |         |                                          |
   |                     |         | This parameter is reserved. The          |
   |                     |         | default value is **ONLINE**.             |
   |                     |         |                                          |
   |                     |         | The value contains a maximum of 16       |
   |                     |         | characters.                              |
   +---------------------+---------+------------------------------------------+
   | provisioning_status | String  | Specifies the provisioning status of     |
   |                     |         | the load balancer.                       |
   |                     |         |                                          |
   |                     |         | The value can be **ACTIVE**,             |
   |                     |         | **PENDING_CREATE**, or **ERROR**.        |
   |                     |         |                                          |
   |                     |         | This parameter is reserved. The          |
   |                     |         | default value is **ACTIVE**.             |
   |                     |         |                                          |
   |                     |         | The value contains a maximum of 16       |
   |                     |         | characters.                              |
   +---------------------+---------+------------------------------------------+
   | admin_state_up      | Boolean | Specifies the administrative status      |
   |                     |         | of the load balancer.                    |
   |                     |         |                                          |
   |                     |         | This parameter is reserved. The          |
   |                     |         | default value is **true**.               |
   +---------------------+---------+------------------------------------------+
   | tags                | Array   | Lists the tags added to the load         |
   |                     |         | balancer.                                |
   +---------------------+---------+------------------------------------------+
   | created_at          | String  | Specifies the time when the load         |
   |                     |         | balancer was created.                    |
   |                     |         |                                          |
   |                     |         | The UTC time is in                       |
   |                     |         | *YYYY-MM-DDTHH:MM:SS* format.            |
   |                     |         |                                          |
   |                     |         | The value contains a maximum of 19       |
   |                     |         | characters.                              |
   +---------------------+---------+------------------------------------------+
   | updated_at          | String  | Specifies the time when the load         |
   |                     |         | balancer was updated.                    |
   |                     |         |                                          |
   |                     |         | The UTC time is in                       |
   |                     |         | *YYYY-MM-DDTHH:MM:SS* format.            |
   |                     |         |                                          |
   |                     |         | The value contains a maximum of 19       |
   |                     |         | characters.                              |
   +---------------------+---------+------------------------------------------+

.. _slb_t3:
.. table:: **Table 3** **listeners** parameter description

   ========= ====== ============================================
   Parameter Type   Description
   ========= ====== ============================================
   id        String Specifies the ID of the associated listener.
   ========= ====== ============================================

.. _slb_t4:
.. table:: **Table 4** **pools** parameter description

   ========= ====== ========================================================
   Parameter Type   Description
   ========= ====== ========================================================
   id        String Specifies the ID of the associated backend server group.
   ========= ====== ========================================================

Status Codes
^^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Querying the Status Tree of a Load Balancer
===========================================

Function
^^^^^^^^

This API is used to query the status tree of a load balancer. You can use this API to query details about the associated listeners, backend server groups, backend servers, health checks, forwarding policies, and forwarding rules, helping you understand the topology of resources associated with the load balancer.

URI
^^^

GET /v2.0/lbaas/loadbalancers/{loadbalancer_id}/statuses

.. table:: **Table 1** Parameter description

   =============== ========= ====== ===============================
   Parameter       Mandatory Type   Description
   =============== ========= ====== ===============================
   loadbalancer_id Yes       String Specifies the load balancer ID.
   =============== ========= ====== ===============================

Request
^^^^^^^

None

Response
^^^^^^^^

.. table:: **Table 2** Response parameters

   +-----------+--------+-------------------------------------------------------------------------------+
   | Parameter | Type   | Description                                                                   |
   +===========+========+===============================================================================+
   | statuses  | Object | Specifies the status tree of a load balancer. For details, see :ref:`qst_t3`. |
   +-----------+--------+-------------------------------------------------------------------------------+

.. _qst_t3:
.. table:: **Table 3** **statuses** parameter description

   +--------------+--------+--------------------------------------------------------------+
   | Parameter    | Type   | Description                                                  |
   +==============+========+==============================================================+
   | loadbalancer | Object | Specifies the load balancer. For details, see :ref:`qst_t4`. |
   +--------------+--------+--------------------------------------------------------------+

.. _qst_t4:
.. table:: **Table 4** **loadbalancer** parameter description

   +---------------------+--------+---------------------------------------+
   | Parameter           | Type   | Description                           |
   +=====================+========+=======================================+
   | id                  | String | Specifies the load balancer ID.       |
   +---------------------+--------+---------------------------------------+
   | name                | String | Specifies the load balancer name.     |
   |                     |        |                                       |
   |                     |        | The value contains a maximum of 255   |
   |                     |        | characters.                           |
   +---------------------+--------+---------------------------------------+
   | listeners           | Array  | Lists the listeners added to the load |
   |                     |        | balancer. For details of this         |
   |                     |        | parameter, see :ref:`qst_t5`.         |
   +---------------------+--------+---------------------------------------+
   | pools               | Array  | Lists the backend server groups       |
   |                     |        | associated with the load balancer.    |
   |                     |        | For details of this parameter, see    |
   |                     |        | :ref:`qst_t6`.                        |
   +---------------------+--------+---------------------------------------+
   | operating_status    | String | This field is reserved.               |
   |                     |        |                                       |
   |                     |        | It specifies the operating status of  |
   |                     |        | the load balancer. The value can be   |
   |                     |        | one of the following:                 |
   |                     |        |                                       |
   |                     |        | -  **ONLINE** (default): The load     |
   |                     |        |    balancer is running normally.      |
   |                     |        | -  **DEGRADED**: This status is       |
   |                     |        |    displayed only when                |
   |                     |        |    **provisioning_status** of a       |
   |                     |        |    forwarding policy or forwarding    |
   |                     |        |    rule added to a listener of the    |
   |                     |        |    load balancer is set to **ERROR**  |
   |                     |        |    and the API for querying the load  |
   |                     |        |    balancer status tree is called.    |
   |                     |        | -  **DISABLED**: This status is       |
   |                     |        |    displayed only when                |
   |                     |        |    **admin_state_up** of the load     |
   |                     |        |    balancer is set to **false** and   |
   |                     |        |    the API for querying the load      |
   |                     |        |    balancer status tree is called.    |
   +---------------------+--------+---------------------------------------+
   | provisioning_status | String | This parameter is reserved, and its   |
   |                     |        | value can only be **ACTIVE**.         |
   |                     |        |                                       |
   |                     |        | It specifies the provisioning status  |
   |                     |        | of the load balancer.                 |
   +---------------------+--------+---------------------------------------+

.. _qst_t5:
.. table:: **Table 5** **listeners** parameter description

   +---------------------+--------+----------------------------------------------+
   | Parameter           | Type   | Description                                  |
   +=====================+========+==============================================+
   | id                  | String | Specifies the listener ID.                   |
   +---------------------+--------+----------------------------------------------+
   | name                | String | Specifies the listener name.                 |
   +---------------------+--------+----------------------------------------------+
   | l7policies          | Array  | Lists associated forwarding policies.        |
   |                     |        | For details of this parameter, see           |
   |                     |        | :ref:`qst_t9`.                               |
   +---------------------+--------+----------------------------------------------+
   | pools               | Array  | Lists the backend server groups              |
   |                     |        | associated with the listener. For            |
   |                     |        | details of this parameter, see :ref:`qst_t6` |
   +---------------------+--------+----------------------------------------------+
   | operating_status    | String | This parameter is reserved, and its          |
   |                     |        | value can only be **ONLINE**.                |
   |                     |        |                                              |
   |                     |        | It specifies the operating status of         |
   |                     |        | the listener.                                |
   +---------------------+--------+----------------------------------------------+
   | provisioning_status | String | This parameter is reserved, and its          |
   |                     |        | value can only be **ACTIVE**.                |
   |                     |        |                                              |
   |                     |        | It specifies the provisioning status         |
   |                     |        | of the listener.                             |
   +---------------------+--------+----------------------------------------------+

.. _qst_t6:
.. table:: **Table 6** **pools** parameter description

   +---------------------+--------+---------------------------------------+
   | Parameter           | Type   | Description                           |
   +=====================+========+=======================================+
   | id                  | String | Specifies the ID of the backend       |
   |                     |        | server group.                         |
   +---------------------+--------+---------------------------------------+
   | name                | String | Specifies the name of the backend     |
   |                     |        | server group.                         |
   +---------------------+--------+---------------------------------------+
   | healthmonitor       | Object | Provides health check details of the  |
   |                     |        | backend server group. For details of  |
   |                     |        | this parameter, see :ref:`qst_t7`.    |
   +---------------------+--------+---------------------------------------+
   | members             | Array  | Lists the members contained in the    |
   |                     |        | backend server group. For details of  |
   |                     |        | this parameter, see :ref:`qst_t8`.    |
   +---------------------+--------+---------------------------------------+
   | operating_status    | String | This parameter is reserved, and its   |
   |                     |        | value can only be **ONLINE**.         |
   |                     |        |                                       |
   |                     |        | It specifies the operating status of  |
   |                     |        | the backend server group.             |
   +---------------------+--------+---------------------------------------+
   | provisioning_status | String | This parameter is reserved, and its   |
   |                     |        | value can only be **ACTIVE**.         |
   |                     |        |                                       |
   |                     |        | It specifies the provisioning status  |
   |                     |        | of the backend server group.          |
   +---------------------+--------+---------------------------------------+

.. _qst_t7:
.. table:: **Table 7** **healthmonitor** parameter description

   +---------------------+--------+--------------------------------------+
   | Parameter           | Type   | Description                          |
   +=====================+========+======================================+
   | id                  | String | Specifies the health check ID.       |
   +---------------------+--------+--------------------------------------+
   | name                | String | Specifies the health check name.     |
   +---------------------+--------+--------------------------------------+
   | type                | String | -  Specifies the health check        |
   |                     |        |    protocol.                         |
   |                     |        | -  The value can be **UDP_CONNECT**, |
   |                     |        |    **TCP**, or **HTTP**.             |
   +---------------------+--------+--------------------------------------+
   | provisioning_status | String | This parameter is reserved, and its  |
   |                     |        | value can only be **ACTIVE**.        |
   |                     |        |                                      |
   |                     |        | It specifies the provisioning status |
   |                     |        | of the health check.                 |
   +---------------------+--------+--------------------------------------+

.. _qst_t8:
.. table:: **Table 8** **members** parameter description

   +---------------------+---------+---------------------------------------+
   | Parameter           | Type    | Description                           |
   +=====================+=========+=======================================+
   | id                  | String  | Specifies the backend server ID.      |
   +---------------------+---------+---------------------------------------+
   | address             | String  | Specifies the private IP address of   |
   |                     |         | the backend server, for example,      |
   |                     |         | 192.168.3.11.                         |
   +---------------------+---------+---------------------------------------+
   | protocol_port       | Integer | Specifies the port used by the        |
   |                     |         | backend server. The port number       |
   |                     |         | ranges from 0 to 65535.               |
   +---------------------+---------+---------------------------------------+
   | operating_status    | String  | This parameter is reserved. It        |
   |                     |         | specifies the operating status of the |
   |                     |         | backend server. The value can be one  |
   |                     |         | of the following:                     |
   |                     |         |                                       |
   |                     |         | -  **ONLINE**: The backend server is  |
   |                     |         |    running normally.                  |
   |                     |         | -  **NO_MONITOR**: No health check is |
   |                     |         |    configured for the backend server  |
   |                     |         |    group that the backend server      |
   |                     |         |    belongs to.                        |
   |                     |         | -  **DISABLED**: The backend server   |
   |                     |         |    is not available. This status is   |
   |                     |         |    displayed only when                |
   |                     |         |    **admin_state_up** of the backend  |
   |                     |         |    server, or the backend server      |
   |                     |         |    group to which it belongs, or the  |
   |                     |         |    associated load balancer is set to |
   |                     |         |    **false** and the API for querying |
   |                     |         |    the load balancer status tree is   |
   |                     |         |    called.                            |
   |                     |         | -  **OFFLINE**: The cloud server used |
   |                     |         |    as the backend server is stopped   |
   |                     |         |    or does not exist.                 |
   |                     |         |                                       |
   |                     |         | NOTE:                                 |
   |                     |         | When **admin_state_up** is set to     |
   |                     |         | **false** and **operating_status** is |
   |                     |         | set to **OFFLINE** for a backend      |
   |                     |         | server, **DISABLED** is returned for  |
   |                     |         | **operating_status** of the backend   |
   |                     |         | server in the response of this API.   |
   +---------------------+---------+---------------------------------------+
   | provisioning_status | String  | This parameter is reserved, and its   |
   |                     |         | value can only be **ACTIVE**.         |
   |                     |         |                                       |
   |                     |         | It specifies the provisioning status  |
   |                     |         | of the backend server.                |
   +---------------------+---------+---------------------------------------+

.. _qst_t9:
.. table:: **Table 9** **l7policies** parameter description

   +---------------------+--------+---------------------------------------+
   | Parameter           | Type   | Description                           |
   +=====================+========+=======================================+
   | id                  | String | Specifies the forwarding policy ID.   |
   +---------------------+--------+---------------------------------------+
   | name                | String | Specifies the forwarding policy name. |
   +---------------------+--------+---------------------------------------+
   | rules               | Array  | Lists the forwarding rules of the     |
   |                     |        | forwarding policy. For details of     |
   |                     |        | this parameter, see :ref:`qst_t10`.   |
   +---------------------+--------+---------------------------------------+
   | action              | String | -  Specifies whether requests are     |
   |                     |        |    forwarded to another backend       |
   |                     |        |    server group or redirected to an   |
   |                     |        |    HTTPS listener.                    |
   |                     |        | -  The value can be                   |
   |                     |        |    **REDIRECT_TO_POOL** or            |
   |                     |        |    **REDIRECT_TO_LISTENER**.          |
   |                     |        |                                       |
   |                     |        |    -  **REDIRECT_TO_POOL**: Requests  |
   |                     |        |       are forwarded to another        |
   |                     |        |       backend server group.           |
   |                     |        |    -  **REDIRECT_TO_LISTENER**:       |
   |                     |        |       Requests are redirected to an   |
   |                     |        |       HTTPS listener.                 |
   +---------------------+--------+---------------------------------------+
   | provisioning_status | String | This parameter is reserved.           |
   |                     |        |                                       |
   |                     |        | It specifies the provisioning status  |
   |                     |        | of the forwarding policy. Value       |
   |                     |        | options:                              |
   |                     |        |                                       |
   |                     |        | -  **ACTIVE** (default): The          |
   |                     |        |    forwarding policy is normal.       |
   |                     |        | -  **ERROR**: Another forwarding      |
   |                     |        |    policy of the same listener has    |
   |                     |        |    the same forwarding rule.          |
   +---------------------+--------+---------------------------------------+

.. _qst_t10:
.. table:: **Table 10** **rules** parameter description

   +---------------------+--------+---------------------------------------+
   | Parameter           | Type   | Description                           |
   +=====================+========+=======================================+
   | id                  | String | Specifies the forwarding rule ID.     |
   +---------------------+--------+---------------------------------------+
   | type                | String | -  Specifies the match type of a      |
   |                     |        |    forwarding rule.                   |
   |                     |        | -  The value can be **PATH** or       |
   |                     |        |    **HOST_NAME**.                     |
   |                     |        |                                       |
   |                     |        |    -  **PATH**: matches the path in   |
   |                     |        |       the request.                    |
   |                     |        |    -  **HOST_NAME**: matches the      |
   |                     |        |       domain name in the request.     |
   +---------------------+--------+---------------------------------------+
   | provisioning_status | String | This parameter is reserved.           |
   |                     |        |                                       |
   |                     |        | It specifies the provisioning status  |
   |                     |        | of the forwarding rule. The value can |
   |                     |        | be one of the following:              |
   |                     |        |                                       |
   |                     |        | -  **ACTIVE** (default): The          |
   |                     |        |    forwarding rule is normal.         |
   |                     |        | -  **ERROR**: Another forwarding      |
   |                     |        |    policy of the same listener has    |
   |                     |        |    the same forwarding rule.          |
   +---------------------+--------+---------------------------------------+

Example Request
^^^^^^^^^^^^^^^

-  Example request

   .. code::

      GET https://{Endpoint}/v2.0/lbaas/loadbalancers/38278031-cfca-44be-81be-a412f618773b/statuses

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   .. code::

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
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Updating a Load Balancer
========================

Function
^^^^^^^^

This API is used to update the name or description of a load balancer.

URI
^^^

PUT /v2.0/lbaas/loadbalancers/{loadbalancer_id}

.. table:: **Table 1** Parameter description

   =============== ========= ====== ===============================
   Parameter       Mandatory Type   Description
   =============== ========= ====== ===============================
   loadbalancer_id Yes       String Specifies the load balancer ID.
   =============== ========= ====== ===============================

Request
^^^^^^^

.. table:: **Table 2** Parameter description

   +--------------+-----------+--------+--------------------------------------------------------------+
   | Parameter    | Mandatory | Type   | Description                                                  |
   +==============+===========+========+==============================================================+
   | loadbalancer | Yes       | Object | Specifies the load balancer. For details, see :ref:`ulb_t3`. |
   +--------------+-----------+--------+--------------------------------------------------------------+

.. _ulb_t3:
.. table:: **Table 3** **loadbalancer** parameter description

   +----------------+-----------+---------+-----------------------------+
   | Parameter      | Mandatory | Type    | Description                 |
   +================+===========+=========+=============================+
   | name           | No        | String  | Specifies the load balancer |
   |                |           |         | name.                       |
   |                |           |         |                             |
   |                |           |         | The value contains a        |
   |                |           |         | maximum of 255 characters.  |
   +----------------+-----------+---------+-----------------------------+
   | description    | No        | String  | Provides supplementary      |
   |                |           |         | information about the load  |
   |                |           |         | balancer.                   |
   |                |           |         |                             |
   |                |           |         | The value contains a        |
   |                |           |         | maximum of 255 characters.  |
   +----------------+-----------+---------+-----------------------------+
   | admin_state_up | No        | Boolean | Specifies the               |
   |                |           |         | administrative status of    |
   |                |           |         | the load balancer.          |
   |                |           |         |                             |
   |                |           |         | This parameter is reserved. |
   |                |           |         | The default value is        |
   |                |           |         | **true**.                   |
   +----------------+-----------+---------+-----------------------------+

Response
^^^^^^^^

.. table:: **Table 4** Response parameters

   +--------------+--------+--------------------------------------------------------------+
   | Parameter    | Type   | Description                                                  |
   +==============+========+==============================================================+
   | loadbalancer | Object | Specifies the load balancer. For details, see :ref:`ulb_t5`. |
   +--------------+--------+--------------------------------------------------------------+

.. _ulb_t5:
.. table:: **Table 5** **loadbalancer** parameter description

   +---------------------+---------+-------------------------------------------+
   | Parameter           | Type    | Description                               |
   +=====================+=========+===========================================+
   | id                  | String  | Specifies the load balancer ID.           |
   +---------------------+---------+-------------------------------------------+
   | tenant_id           | String  | Specifies the ID of the project where     |
   |                     |         | the load balancer is used.                |
   |                     |         |                                           |
   |                     |         | The value contains a maximum of 255       |
   |                     |         | characters.                               |
   +---------------------+---------+-------------------------------------------+
   | name                | String  | Specifies the load balancer name.         |
   |                     |         |                                           |
   |                     |         | The value contains a maximum of 255       |
   |                     |         | characters.                               |
   +---------------------+---------+-------------------------------------------+
   | description         | String  | Provides supplementary information        |
   |                     |         | about the load balancer.                  |
   |                     |         |                                           |
   |                     |         | The value contains a maximum of 255       |
   |                     |         | characters.                               |
   +---------------------+---------+-------------------------------------------+
   | vip_subnet_id       | String  | Specifies the ID of the subnet where      |
   |                     |         | the load balancer works.                  |
   +---------------------+---------+-------------------------------------------+
   | vip_port_id         | String  | Specifies the ID of the port bound to     |
   |                     |         | the private IP address of the load        |
   |                     |         | balancer.                                 |
   |                     |         |                                           |
   |                     |         | When you create a load balancer, the      |
   |                     |         | system automatically creates a port       |
   |                     |         | and associates it with a security         |
   |                     |         | group. However, the security group        |
   |                     |         | will not take effect.                     |
   +---------------------+---------+-------------------------------------------+
   | provider            | String  | Specifies the provider of the load        |
   |                     |         | balancer.                                 |
   +---------------------+---------+-------------------------------------------+
   | vip_address         | String  | Specifies the private IP address of       |
   |                     |         | the load balancer.                        |
   |                     |         |                                           |
   |                     |         | The value contains a maximum of 64        |
   |                     |         | characters.                               |
   +---------------------+---------+-------------------------------------------+
   | listeners           | Array   | Lists the IDs of listeners added to       |
   |                     |         | the load balancer. For details, see       |
   |                     |         | :ref:`ulb_t6`.                            |
   +---------------------+---------+-------------------------------------------+
   | pools               | Array   | Lists the IDs of backend server           |
   |                     |         | groups associated with the load           |
   |                     |         | balancer. For details, see :ref:`ulb_t7`. |
   +---------------------+---------+-------------------------------------------+
   | operating_status    | String  | This parameter is reserved, and its       |
   |                     |         | value can only be **ONLINE**.             |
   |                     |         |                                           |
   |                     |         | It specifies the operating status of      |
   |                     |         | the load balancer.                        |
   +---------------------+---------+-------------------------------------------+
   | provisioning_status | String  | This parameter is reserved, and its       |
   |                     |         | value can only be **ACTIVE**.             |
   |                     |         |                                           |
   |                     |         | It specifies the provisioning status      |
   |                     |         | of the load balancer.                     |
   +---------------------+---------+-------------------------------------------+
   | admin_state_up      | Boolean | Specifies the administrative status       |
   |                     |         | of the load balancer.                     |
   |                     |         |                                           |
   |                     |         | This parameter is reserved. The value     |
   |                     |         | can be **true** or **false**.             |
   |                     |         |                                           |
   |                     |         | -  **true**: Enabled                      |
   |                     |         | -  **false**: Disabled                    |
   +---------------------+---------+-------------------------------------------+
   | tags                | Array   | Lists load balancer tags.                 |
   +---------------------+---------+-------------------------------------------+
   | created_at          | String  | Specifies the time when the load          |
   |                     |         | balancer was created.                     |
   |                     |         |                                           |
   |                     |         | The UTC time is in                        |
   |                     |         | *YYYY-MM-DDTHH:MM:SS* format.             |
   |                     |         |                                           |
   |                     |         | The value contains a maximum of 19        |
   |                     |         | characters.                               |
   +---------------------+---------+-------------------------------------------+
   | updated_at          | String  | Specifies the time when the load          |
   |                     |         | balancer was updated.                     |
   |                     |         |                                           |
   |                     |         | The UTC time is in                        |
   |                     |         | *YYYY-MM-DDTHH:MM:SS* format.             |
   |                     |         |                                           |
   |                     |         | The value contains a maximum of 19        |
   |                     |         | characters.                               |
   +---------------------+---------+-------------------------------------------+

.. _ulb_t6:
.. table:: **Table 6** **listeners** parameter description

   ========= ====== ============================================
   Parameter Type   Description
   ========= ====== ============================================
   id        String Specifies the ID of the associated listener.
   ========= ====== ============================================

.. _ulb_t7:
.. table:: **Table 7** **pools** parameter description

   ========= ====== ========================================================
   Parameter Type   Description
   ========= ====== ========================================================
   id        String Specifies the ID of the associated backend server group.
   ========= ====== ========================================================

Example Request
^^^^^^^^^^^^^^^

-  Example request: Modifying the load balancer name and description

   .. code::

      PUT https://{Endpoint}/v2.0/lbaas/loadbalancers/1e11b74e-30b7-4b78-b09b-84aec4a04487

      {
          "loadbalancer": {
              "name": "lb_update_test",
              "description": "lb update test"
          }
      }

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   .. code::

      {
        "loadbalancer": {
          "description": "simple lb2",
          "admin_state_up": true,
          "tenant_id": "145483a5107745e9b3d80f956713e6a3",

          "provisioning_status": "ACTIVE",
          "vip_subnet_id": "823d5866-6e30-45c2-9b1a-a1ebc3757fdb",
          "listeners": [
            {
              "id": "37ffe679-08ef-436e-b6bd-cf66fb4c3de2"
            }
          ],
          "vip_address": "192.172.1.68",
          "vip_port_id": "f42e3019-67f7-4d2a-8d1c-af49e7c22fa6",
          "tags": [],
          "provider": "vlb",
          "pools": [
            {
              "id": "75c4f2d4-a213-4408-9fa8-d64708e8d1df"
            }
          ],
          "id": "c32a9f9a-0cc6-4f38-bb9c-cde79a533c19",
          "operating_status": "ONLINE",
          "name": "loadbalancer-test2",
          "created_at": "2018-07-25T01:54:13",
          "updated_at": "2018-07-25T01:54:14"
        }
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Deleting a Load Balancer
========================

Function
^^^^^^^^

This API is used to delete a specific load balancer.

Constraints
^^^^^^^^^^^

All listeners added to the load balancer must be deleted before the load balancer is deleted.

URI
^^^

DELETE /v2.0/lbaas/loadbalancers/{loadbalancer_id}

.. table:: **Table 1** Parameter description

   =============== ========= ====== ===============================
   Parameter       Mandatory Type   Description
   =============== ========= ====== ===============================
   loadbalancer_id Yes       String Specifies the load balancer ID.
   =============== ========= ====== ===============================

Request
^^^^^^^

None

Response
^^^^^^^^

None

Example Request
^^^^^^^^^^^^^^^

Example request: Deleting a load balancer

.. code::

   DELETE https://{endpoint}/v2.0/lbaas/loadbalancers/90f7c765-0bc9-47c4-8513-4cc0c264c8f8

Example Response
^^^^^^^^^^^^^^^^

Example response

None

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.
