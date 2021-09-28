=============
Load Balancer
=============

Creating a Load Balancer
========================

Function
^^^^^^^^

This API is used to create a dedicated load balancer. When you create the load
balancer, note the following:

-  Specify both **vip_subnet_cidr_id** and **vip_address** if you want to bind
   a private IPv4 address to the load balancer.

-  Specify **publicip** and either **vpc_id** or **vip_subnet_cidr_id** if you
   want to bind a new IPv4 EIP to the load balancer.

-  Specify **publicip_ids** and either **vpc_id** or **vip_subnet_cidr_id** if
   you want to bind an existing IPv4 EIP to the load balancer.

-  Specify **ipv6_vip_virsubnet_id** you want to bind a private IPv6 address to
   the load balancer.

-  Specify **ipv6_vip_virsubnet_id** and **ipv6_bandwidth** if you want to bind
   a public IPv6 address to the load balancer.

-  You cannot bind an occupied private IPv4 address, an occupied private IPv6
   address, or an occupied public IPv6 address to the load balancer.

-  Dedicated load balancers with IPv6 addresses are not supported.

Constraints
^^^^^^^^^^^

There are some constraints when you create a dedicated load balancer:

-  **vpc_id**, **vip_subnet_cidr_id**, and **ipv6_vip_virsubnet_id** cannot be
   left blank at the same time.

-  **ip_target_enable** specifies whether to enable cross-VPC backend. If you
   have a load balancer with this function enabled, you can add servers in a
   VPC connected through a VPC peering connection, in a VPC connected through a
   cloud connection, or in an on-premises data center at the other end of a
   Direct Connect or VPN connection, by using server IP addresses.

-  **admin_state_up** must be set to **true**.

-  **provider** must be set to **vlb**.

-  **elb_virsubnet_ids** indicates the subnets that support IPv4/IPv6 dual
   stack or only IPv4 subnets. If only IPv4 subnets are supported,
   **ipv6_vip_virsubnet_id** must be left blank.

-  If you bind an EIP to the load balancer during creation, you cannot unbind
   it from the load balancer by calling the API after the load balancer is
   created. Instead, you can unbind the EIP only on the ELB console. Locate the
   dedicated load balancer in the load balancer list and click **More** >
   **Unbind EIP** in the **Operation** column.

-  **publicip_ids** and **publicip** cannot be specified at the same time. Set
   either **publicip_ids** to bind an existing EIP to the load balancer, or
   **publicip** to bind a new EIP to the load balancer, or neither of them.

-  If you want to add the load balancer to a shared bandwidth, you must specify
   the ID of the shared bandwidth. If you want the load balancer to use a new
   dedicated bandwidth, **charge_mode**, **share_type**, and **size** are
   required.

-  Dedicated load balancers are supported only in the **eu-nl** region.

URI
^^^

POST /v3/{project_id}/elb/loadbalancers

.. table:: **Table 1** Path parameters

   +------------+-----------+--------+---------------------------+
   | Parameter  | Mandatory | Type   | Description               |
   +============+===========+========+===========================+
   | project_id | Yes       | String | Specifies the project ID. |
   |            |           |        |                           |
   |            |           |        | Minimum: **1**            |
   |            |           |        |                           |
   |            |           |        | Maximum: **255**          |
   +------------+-----------+--------+---------------------------+

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 2** Request header parameters

   ============ ========= ====== =================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== =================================
   X-Auth-Token No        String Shows authentication information.
   ============ ========= ====== =================================

.. table:: **Table 3** Request body parameters

   +--------------+-----------+-----------------------+------------------------------+
   | Parameter    | Mandatory | Type                  | Description                  |
   +==============+===========+=======================+==============================+
   | loadbalancer | Yes       | :ref:`dlbc_t4` object | Specifies the load balancer. |
   +--------------+-----------+-----------------------+------------------------------+

.. _dlbc_t4:
.. table:: **Table 4** CreateLoadBalancerOption

   +------------------------+-----------+-------------------+-----------------------------+
   | Parameter              | Mandatory | Type              | Description                 |
   +========================+===========+===================+=============================+
   | name                   | No        | String            | Specifies the load balancer |
   |                        |           |                   | name.                       |
   |                        |           |                   |                             |
   |                        |           |                   | Minimum: **0**              |
   |                        |           |                   | Maximum: **255**            |
   +------------------------+-----------+-------------------+-----------------------------+
   | description            | No        | String            | Provides supplementary      |
   |                        |           |                   | information about the load  |
   |                        |           |                   | balancer.                   |
   |                        |           |                   |                             |
   |                        |           |                   | Minimum: **0**              |
   |                        |           |                   | Maximum: **255**            |
   +------------------------+-----------+-------------------+-----------------------------+
   | vip_address            | No        | String            | Specifies the virtual IP    |
   |                        |           |                   | address bound to the load   |
   |                        |           |                   | balancer. The IP address    |
   |                        |           |                   | must be from the IPv4       |
   |                        |           |                   | subnet of the VPC where the |
   |                        |           |                   | load balancer works and IP  |
   |                        |           |                   | address should not be       |
   |                        |           |                   | occupied by other services. |
   |                        |           |                   |                             |
   |                        |           |                   | Note:                       |
   |                        |           |                   |                             |
   |                        |           |                   | -  If both                  |
   |                        |           |                   |    **vip_subnet_cidr_id**   |
   |                        |           |                   |    and **vip_address** are  |
   |                        |           |                   |    specified, a dedicated   |
   |                        |           |                   |    load balancer with a     |
   |                        |           |                   |    private IPv4 address     |
   |                        |           |                   |    will be created, and the |
   |                        |           |                   |    virtual IP address       |
   |                        |           |                   |    specified by             |
   |                        |           |                   |    **vip_address** is the   |
   |                        |           |                   |    private IP address of    |
   |                        |           |                   |    the load balancer.       |
   |                        |           |                   | -  If only                  |
   |                        |           |                   |    **vip_subnet_cidr_id**   |
   |                        |           |                   |    is specified, a          |
   |                        |           |                   |    dedicated load balancer  |
   |                        |           |                   |    with a private IPv4      |
   |                        |           |                   |    address will be created, |
   |                        |           |                   |    and the system will      |
   |                        |           |                   |    automatically assign a   |
   |                        |           |                   |    virtual IP address to    |
   |                        |           |                   |    the load balancer.       |
   +------------------------+-----------+-------------------+-----------------------------+
   | vip_subnet_cidr_id     | No        | String            | Specifies the ID of the     |
   |                        |           |                   | IPv4 subnet where the load  |
   |                        |           |                   | balancer works. You can     |
   |                        |           |                   | query **neutron_subnet_id** |
   |                        |           |                   | in the response by calling  |
   |                        |           |                   | the API (GET                |
   |                        |           |                   | https://{VPC_Endpoint       |
   |                        |           |                   | }/v1/{project_id}/subnets). |
   |                        |           |                   |                             |
   |                        |           |                   | -  Both                     |
   |                        |           |                   |    **vip_subnet_cidr_id**   |
   |                        |           |                   |    and **vip_address** are  |
   |                        |           |                   |    required if you want to  |
   |                        |           |                   |    create a dedicated load  |
   |                        |           |                   |    balancer with a private  |
   |                        |           |                   |    IPv4 address.            |
   |                        |           |                   | -  **publicip** and either  |
   |                        |           |                   |    **vpc_id** or            |
   |                        |           |                   |    **vip_subnet_cidr_id**   |
   |                        |           |                   |    are required if you want |
   |                        |           |                   |    to create a dedicated    |
   |                        |           |                   |    load balancer with a new |
   |                        |           |                   |    IPv4 EIP.                |
   |                        |           |                   | -  **publicip_ids** and     |
   |                        |           |                   |    either **vpc_id** or     |
   |                        |           |                   |    **vip_subnet_cidr_id**   |
   |                        |           |                   |    are required if you want |
   |                        |           |                   |    to with a dedicated load |
   |                        |           |                   |    balancer with an         |
   |                        |           |                   |    existing IPv4 EIP.       |
   |                        |           |                   | -  The subnet specified by  |
   |                        |           |                   |    **vip_subnet_cidr_id**   |
   |                        |           |                   |    must be in the VPC       |
   |                        |           |                   |    specified by **vpc_id**  |
   |                        |           |                   |    if you specify both      |
   |                        |           |                   |    **vpc_id** and           |
   |                        |           |                   |    **vip_subnet_cidr_id**.  |
   +------------------------+-----------+-------------------+-----------------------------+
   | ipv6_vip_virsubnet_id  | No        | String            | Specifies the ID of the     |
   |                        |           |                   | IPv6 subnet where the load  |
   |                        |           |                   | balancer works. You can     |
   |                        |           |                   | query **id** in the         |
   |                        |           |                   | response by calling the API |
   |                        |           |                   | (GET                        |
   |                        |           |                   | https://{VPC_Endpoint       |
   |                        |           |                   | }/v1/{project_id}/subnets). |
   |                        |           |                   |                             |
   |                        |           |                   | Note:                       |
   |                        |           |                   |                             |
   |                        |           |                   | - **ipv6_vip_virsubnet_id** |
   |                        |           |                   |    is required if you want  |
   |                        |           |                   |    to create a load         |
   |                        |           |                   |    balancer with a private  |
   |                        |           |                   |    IPv6 address.            |
   |                        |           |                   | - Both                      |
   |                        |           |                   |   **ipv6_vip_virsubnet_id** |
   |                        |           |                   |   and **ipv6_bandwidth**    |
   |                        |           |                   |   are required if you want  |
   |                        |           |                   |   to create a load          |
   |                        |           |                   |   balancer with a public    |
   |                        |           |                   |   IPv6 address.             |
   |                        |           |                   | - The subnet specified by   |
   |                        |           |                   |   **ipv6_vip_virsubnet_id** |
   |                        |           |                   |   must be in the VPC        |
   |                        |           |                   |   specified by **vpc_id**   |
   |                        |           |                   |   if you specify both       |
   |                        |           |                   |   **ipv6_vip_virsubnet_id** |
   |                        |           |                   |   and **vpc_id**.           |
   |                        |           |                   | - IPv6 must be enabled for  |
   |                        |           |                   |   the subnet where the      |
   |                        |           |                   |   load balancer works.      |
   |                        |           |                   |                             |
   |                        |           |                   | This parameter is           |
   |                        |           |                   | unsupported. Please do not  |
   |                        |           |                   | use it.                     |
   +------------------------+-----------+-------------------+-----------------------------+
   | provider               | No        | String            | Specifies the provider of   |
   |                        |           |                   | the load balancer. The      |
   |                        |           |                   | value can only be **vlb**.  |
   +------------------------+-----------+-------------------+-----------------------------+
   | l4_flavor_id           | No        | String            | Specifies the ID of the     |
   |                        |           |                   | Layer-4 flavor.             |
   |                        |           |                   |                             |
   |                        |           |                   | Specify either              |
   |                        |           |                   | **l4_flavor_id** or         |
   |                        |           |                   | **l7_flavor_id** or both    |
   |                        |           |                   | **l4_flavor_id** and        |
   |                        |           |                   | **l7_flavor_id** when you   |
   |                        |           |                   | create a load balancer.     |
   +------------------------+-----------+-------------------+-----------------------------+
   | project_id             | No        | String            | Specifies the project ID.   |
   +------------------------+-----------+-------------------+-----------------------------+
   | guaranteed             | No        | Boolean           | Specifies whether the load  |
   |                        |           |                   | balancer is a dedicated     |
   |                        |           |                   | load balancer. The value    |
   |                        |           |                   | can only be **true**.       |
   |                        |           |                   |                             |
   |                        |           |                   | Default: **true**           |
   +------------------------+-----------+-------------------+-----------------------------+
   | vpc_id                 | No        | String            | Specifies the ID of the VPC |
   |                        |           |                   | where the load balancer     |
   |                        |           |                   | works. You can query **id** |
   |                        |           |                   | in the response by calling  |
   |                        |           |                   | the API (GET                |
   |                        |           |                   | https://{VPC_Endpo          |
   |                        |           |                   | int}/v1/{project_id}/vpcs). |
   |                        |           |                   |                             |
   |                        |           |                   | - The subnet specified by   |
   |                        |           |                   |   **vip_subnet_cidr_id**    |
   |                        |           |                   |   must be in the VPC        |
   |                        |           |                   |   specified by **vpc_id**   |
   |                        |           |                   |   if you specify both       |
   |                        |           |                   |   **vip_subnet_cidr_id**    |
   |                        |           |                   |   and **vpc_id**.           |
   |                        |           |                   | - The subnet specified by   |
   |                        |           |                   |   **ipv6_vip_virsubnet_id** |
   |                        |           |                   |   must be in the VPC        |
   |                        |           |                   |   specified by **vpc_id**   |
   |                        |           |                   |   if you specify both       |
   |                        |           |                   |   **ipv6_vip_virsubnet_id** |
   |                        |           |                   |   and **vpc_id**.           |
   +------------------------+-----------+-------------------+-----------------------------+
   | availability_zone_list | Yes       | Array of strings  | Specifies the list of AZs   |
   |                        |           |                   | where the load balancer can |
   |                        |           |                   | be created. You can query   |
   |                        |           |                   | the AZs by calling the API  |
   |                        |           |                   | (GET                        |
   |                        |           |                   | https://{                   |
   |                        |           |                   | ELB_Endpoint}/v3/{project_i |
   |                        |           |                   | d}/elb/availability-zones). |
   |                        |           |                   | Select one or more AZs in   |
   |                        |           |                   | the same set.               |
   +------------------------+-----------+-------------------+-----------------------------+
   | enterprise_project_id  | No        | String            | Specifies the enterprise    |
   |                        |           |                   | project ID. The value       |
   |                        |           |                   | cannot be **""**, **"0"**,  |
   |                        |           |                   | or the ID of an enterprise  |
   |                        |           |                   | project that does not       |
   |                        |           |                   | exist. If this parameter is |
   |                        |           |                   | not passed during resource  |
   |                        |           |                   | creation, the resource      |
   |                        |           |                   | belongs to the default      |
   |                        |           |                   | enterprise project.         |
   |                        |           |                   |                             |
   |                        |           |                   | This parameter is           |
   |                        |           |                   | unsupported. Please do not  |
   |                        |           |                   | use it.                     |
   +------------------------+-----------+-------------------+-----------------------------+
   | tags                   | No        | Array of          | Lists the tags added to the |
   |                        |           | :ref:`dlbc_tag`   | load balancer. Example:     |
   |                        |           | objects           | "tags":[{"key":"my_ta       |
   |                        |           |                   | g","value":"my_tag_value"}] |
   +------------------------+-----------+-------------------+-----------------------------+
   | admin_state_up         | No        | Boolean           | Specifies the               |
   |                        |           |                   | administrative status of    |
   |                        |           |                   | the load balancer. The      |
   |                        |           |                   | value can only be **true**. |
   |                        |           |                   |                             |
   |                        |           |                   | This parameter is           |
   |                        |           |                   | unsupported. Please do not  |
   |                        |           |                   | use it.                     |
   |                        |           |                   |                             |
   |                        |           |                   | Default: **true**           |
   +------------------------+-----------+-------------------+-----------------------------+
   | l7_flavor_id           | No        | String            | Specifies the ID of the     |
   |                        |           |                   | Layer-7 flavor.             |
   |                        |           |                   |                             |
   |                        |           |                   | Specify either              |
   |                        |           |                   | **l4_flavor_id** or         |
   |                        |           |                   | **l7_flavor_id** or both    |
   |                        |           |                   | **l4_flavor_id** and        |
   |                        |           |                   | **l7_flavor_id** when you   |
   |                        |           |                   | create a load balancer.     |
   |                        |           |                   |                             |
   |                        |           |                   | Minimum: **1**              |
   |                        |           |                   |                             |
   |                        |           |                   | Maximum: **255**            |
   +------------------------+-----------+-------------------+-----------------------------+
   | ipv6_bandwidth         | No        | :ref:`dlbc_bandw` | Specifies the ID of the     |
   |                        |           | object            | bandwidth. This parameter   |
   |                        |           |                   | is available only when you  |
   |                        |           |                   | create or update a          |
   |                        |           |                   | dedicated load balancer     |
   |                        |           |                   | that has an IPv6 address    |
   |                        |           |                   | bound.                      |
   |                        |           |                   |                             |
   |                        |           |                   | If you use a new IPv6       |
   |                        |           |                   | address and specify a       |
   |                        |           |                   | shared bandwidth, the IPv6  |
   |                        |           |                   | address will be added to    |
   |                        |           |                   | the shared bandwidth.       |
   |                        |           |                   |                             |
   |                        |           |                   | This parameter is           |
   |                        |           |                   | unsupported. Please do not  |
   |                        |           |                   | use it.                     |
   +------------------------+-----------+-------------------+-----------------------------+
   | publicip_ids           | No        | Array of strings  | Specifies the ID of the EIP |
   |                        |           |                   | the system will             |
   |                        |           |                   | automatically assign and    |
   |                        |           |                   | bind to the load balancer   |
   |                        |           |                   | during load balancer        |
   |                        |           |                   | creation. Currently, only   |
   |                        |           |                   | the first EIP will be bound |
   |                        |           |                   | to the load balancer        |
   |                        |           |                   | although multiple EIP IDs   |
   |                        |           |                   | can be set.                 |
   +------------------------+-----------+-------------------+-----------------------------+
   | publicip               | No        | :ref:`dlbc_pi`    | Provides information about  |
   |                        |           | object            | the new IPv4 EIP that will  |
   |                        |           |                   | be bound to the dedicated   |
   |                        |           |                   | load balancer during load   |
   |                        |           |                   | balancer creation.          |
   +------------------------+-----------+-------------------+-----------------------------+
   | elb_virsubnet_ids      | Yes       | Array of strings  | Lists the IDs of subnets on |
   |                        |           |                   | the downstream plane. You   |
   |                        |           |                   | can query parameter **id**  |
   |                        |           |                   | in the response by calling  |
   |                        |           |                   | the API (GET                |
   |                        |           |                   | https://{VPC_Endpoint       |
   |                        |           |                   | }/v1/{project_id}/subnets). |
   |                        |           |                   |                             |
   |                        |           |                   | If there is more than one   |
   |                        |           |                   | subnet, the first subnet in |
   |                        |           |                   | the list will be used.      |
   |                        |           |                   |                             |
   |                        |           |                   | The subnets must be in the  |
   |                        |           |                   | VPC where the load balancer |
   |                        |           |                   | works.                      |
   +------------------------+-----------+-------------------+-----------------------------+
   | ip_target_enable       | No        | Boolean           | Specifies whether to enable |
   |                        |           |                   | cross-VPC backend. The      |
   |                        |           |                   | value can be **true**       |
   |                        |           |                   | (enabled) or **false**      |
   |                        |           |                   | (disabled). This function   |
   |                        |           |                   | is supported only by        |
   |                        |           |                   | dedicated load balancers.   |
   |                        |           |                   |                             |
   |                        |           |                   | If you enable this          |
   |                        |           |                   | function, you can add       |
   |                        |           |                   | servers in a VPC connected  |
   |                        |           |                   | through a VPC peering       |
   |                        |           |                   | connection, in a VPC        |
   |                        |           |                   | connected through a cloud   |
   |                        |           |                   | connection, or in an        |
   |                        |           |                   | on-premises data center at  |
   |                        |           |                   | the other end of a Direct   |
   |                        |           |                   | Connect or VPN connection,  |
   |                        |           |                   | by using their IP           |
   |                        |           |                   | addresses.                  |
   |                        |           |                   |                             |
   |                        |           |                   | This parameter is           |
   |                        |           |                   | unsupported. Please do not  |
   |                        |           |                   | use it.                     |
   +------------------------+-----------+-------------------+-----------------------------+

.. _dlbc_tag:
.. table:: **Table 5** Tag

   ========= ========= ====== ========================
   Parameter Mandatory Type   Description
   ========= ========= ====== ========================
   key       No        String Specifies the tag key.
   value     No        String Specifies the tag value.
   ========= ========= ====== ========================

.. _dlbc_bandw:
.. table:: **Table 6** BandwidthRef

   ========= ========= ====== ==================================
   Parameter Mandatory Type   Description
   ========= ========= ====== ==================================
   id        Yes       String Specifies the shared bandwidth ID.
   ========= ========= ====== ==================================

.. _dlbc_pi:
.. table:: **Table 7** CreateLoadBalancerPublicIpOption

   +--------------+-----------+---------------------------+-----------------------------+
   | Parameter    | Mandatory | Type                      | Description                 |
   +==============+===========+===========================+=============================+
   | ip_version   | No        | Integer                   | Specifies the IP address    |
   |              |           |                           | version. The value can be   |
   |              |           |                           | **4** (IPv4) or **6**       |
   |              |           |                           | (IPv6).                     |
   |              |           |                           |                             |
   |              |           |                           | IPv6 is unsupported. The    |
   |              |           |                           | value cannot be **6**.      |
   |              |           |                           |                             |
   |              |           |                           | Default: **4**              |
   +--------------+-----------+---------------------------+-----------------------------+
   | network_type | Yes       | String                    | Specifies the EIP type. The |
   |              |           |                           | value can be **5_bgp**      |
   |              |           |                           | (default) and               |
   |              |           |                           | **5_mailbgp**.              |
   |              |           |                           |                             |
   |              |           |                           | NOTE:                       |
   |              |           |                           | In **eu-de**, the value of  |
   |              |           |                           | this parameter can only be  |
   |              |           |                           | **5_gray**.                 |
   |              |           |                           |                             |
   |              |           |                           | Minimum: **1**              |
   |              |           |                           |                             |
   |              |           |                           | Maximum: **36**             |
   +--------------+-----------+---------------------------+-----------------------------+
   | description  | No        | String                    | Provides supplementary      |
   |              |           |                           | information about the IPv4  |
   |              |           |                           | EIP.                        |
   |              |           |                           |                             |
   |              |           |                           | Minimum: **1**              |
   |              |           |                           |                             |
   |              |           |                           | Maximum: **255**            |
   +--------------+-----------+---------------------------+-----------------------------+
   | bandwidth    | Yes       | :ref:`dlbc_bandwo` object | Provides supplementary      |
   |              |           |                           | information about the       |
   |              |           |                           | bandwidth.                  |
   +--------------+-----------+---------------------------+-----------------------------+

.. _dlbc_bandwo:
.. table:: **Table 8** CreateLoadBalancerBandwidthOption

   +-------------+-----------+---------+-----------------------------+
   | Parameter   | Mandatory | Type    | Description                 |
   +=============+===========+=========+=============================+
   | name        | No        | String  | Specifies the bandwidth     |
   |             |           |         | name.                       |
   |             |           |         |                             |
   |             |           |         | Minimum: **1**              |
   |             |           |         |                             |
   |             |           |         | Maximum: **64**             |
   +-------------+-----------+---------+-----------------------------+
   | size        | No        | Integer | Specifies the bandwidth     |
   |             |           |         | range.                      |
   |             |           |         |                             |
   |             |           |         | The default range is 1      |
   |             |           |         | Mbit/s to 2,000 Mbit/s.     |
   |             |           |         | (The specific range may     |
   |             |           |         | vary depending on the       |
   |             |           |         | configuration in each       |
   |             |           |         | region. You can see the     |
   |             |           |         | available bandwidth range   |
   |             |           |         | on the management console.) |
   |             |           |         |                             |
   |             |           |         | Note:                       |
   |             |           |         |                             |
   |             |           |         | The minimum increment for   |
   |             |           |         | bandwidth adjustment varies |
   |             |           |         | depending on the bandwidth  |
   |             |           |         | range. The following are    |
   |             |           |         | the details:                |
   |             |           |         |                             |
   |             |           |         | -  The minimum increment is |
   |             |           |         |    1 Mbit/s if the          |
   |             |           |         |    bandwidth range is from  |
   |             |           |         |    0 Mbit/s to 300 Mbit/s.  |
   |             |           |         | -  The minimum increment is |
   |             |           |         |    50 Mbit/s if the         |
   |             |           |         |    bandwidth range is from  |
   |             |           |         |    300 Mbit/s to 1,000      |
   |             |           |         |    Mbit/s.                  |
   |             |           |         | -  The minimum increment is |
   |             |           |         |    500 Mbit/s if the        |
   |             |           |         |    bandwidth is greater     |
   |             |           |         |    than 1,000 Mbit/s.       |
   |             |           |         |                             |
   |             |           |         | This parameter is mandatory |
   |             |           |         | if **id** is set to         |
   |             |           |         | **null**.                   |
   |             |           |         |                             |
   |             |           |         | Minimum: **0**              |
   |             |           |         |                             |
   |             |           |         | Maximum: **99999**          |
   +-------------+-----------+---------+-----------------------------+
   | charge_mode | No        | String  | Specifies how the bandwidth |
   |             |           |         | used by the EIP is billed.  |
   |             |           |         |                             |
   |             |           |         | Currently, the bandwidth    |
   |             |           |         | can be billed only by       |
   |             |           |         | **traffic**.                |
   |             |           |         |                             |
   |             |           |         | This parameter is mandatory |
   |             |           |         | if **id** is set to         |
   |             |           |         | **null**.                   |
   +-------------+-----------+---------+-----------------------------+
   | share_type  | No        | String  | Specifies the bandwidth     |
   |             |           |         | type.                       |
   |             |           |         |                             |
   |             |           |         | The value options are as    |
   |             |           |         | follows:                    |
   |             |           |         |                             |
   |             |           |         | -  **PER**: indicates       |
   |             |           |         |    dedicated bandwidth.     |
   |             |           |         | -  **WHOLE**: indicates     |
   |             |           |         |    shared bandwidth.        |
   |             |           |         |                             |
   |             |           |         | This parameter is mandatory |
   |             |           |         | when **id** is set to       |
   |             |           |         | **null**. It will be        |
   |             |           |         | ignored if the value of     |
   |             |           |         | **id** is not **null**.     |
   +-------------+-----------+---------+-----------------------------+
   | id          | No        | String  | Specifies the ID of the     |
   |             |           |         | shared bandwidth. You can   |
   |             |           |         | add a load balancer to a    |
   |             |           |         | shared bandwidth by         |
   |             |           |         | specifying its ID.          |
   |             |           |         |                             |
   |             |           |         | If you have specified an    |
   |             |           |         | ID, you do not need to pass |
   |             |           |         | other parameters. Even if   |
   |             |           |         | you pass other parameters,  |
   |             |           |         | the system will             |
   |             |           |         | automatically ignore these  |
   |             |           |         | parameters.                 |
   +-------------+-----------+---------+-----------------------------+

Response Parameters
^^^^^^^^^^^^^^^^^^^

**Status code: 201**

.. table:: **Table 9** Response body parameters

   +--------------+---------------------+----------------------------------------+
   | Parameter    | Type                | Description                            |
   +==============+=====================+========================================+
   | loadbalancer | :ref:`dlbc_` object | Specifies the load balancer.           |
   +--------------+---------------------+----------------------------------------+
   | request_id   | String              | Specifies the request ID. The value is |
   |              |                     | automatically generated.               |
   +--------------+---------------------+----------------------------------------+

.. _dlbc_:
.. table:: **Table 10** LoadBalancer

   +------------------------+-----------------------------------+---------------------------------------+
   | Parameter              | Type                              | Description                           |
   +========================+===================================+=======================================+
   | id                     | String                            | Specifies the load balancer ID.       |
   |                        |                                   |                                       |
   |                        |                                   | Default: **Automatically generated**  |
   +------------------------+-----------------------------------+---------------------------------------+
   | description            | String                            | Provides supplementary information    |
   |                        |                                   | about the load balancer.              |
   |                        |                                   |                                       |
   |                        |                                   | Minimum: **1**                        |
   |                        |                                   |                                       |
   |                        |                                   | Maximum: **255**                      |
   +------------------------+-----------------------------------+---------------------------------------+
   | provisioning_status    | String                            | Specifies the provisioning status of  |
   |                        |                                   | the load balancer. The value can only |
   |                        |                                   | be **ACTIVE**.                        |
   +------------------------+-----------------------------------+---------------------------------------+
   | admin_state_up         | Boolean                           | Specifies the administrative status   |
   |                        |                                   | of the load balancer. The value can   |
   |                        |                                   | only be **true**.                     |
   |                        |                                   |                                       |
   |                        |                                   | This parameter is unsupported. Please |
   |                        |                                   | do not use it.                        |
   |                        |                                   |                                       |
   |                        |                                   | Default: **true**                     |
   +------------------------+-----------------------------------+---------------------------------------+
   | provider               | String                            | Specifies the provider of the load    |
   |                        |                                   | balancer. The value can only be       |
   |                        |                                   | **vlb**.                              |
   |                        |                                   |                                       |
   |                        |                                   | Default: **vlb**                      |
   +------------------------+-----------------------------------+---------------------------------------+
   | pools                  | Array of :ref:`dlbc_pr1` objects  | Lists the IDs of backend server       |
   |                        |                                   | groups associated with the load       |
   |                        |                                   | balancer.                             |
   +------------------------+-----------------------------------+---------------------------------------+
   | listeners              | Array of :ref:`dlbc_lr1` objects  | Lists the IDs of listeners added to   |
   |                        |                                   | the load balancer.                    |
   +------------------------+-----------------------------------+---------------------------------------+
   | operating_status       | String                            | Specifies the operating status of the |
   |                        |                                   | load balancer. The value can only be  |
   |                        |                                   | **ONLINE**.                           |
   |                        |                                   |                                       |
   |                        |                                   | Minimum: **1**                        |
   |                        |                                   |                                       |
   |                        |                                   | Maximum: **16**                       |
   +------------------------+-----------------------------------+---------------------------------------+
   | vip_address            | String                            | Specifies the private IPv4 address    |
   |                        |                                   | bound to the load balancer.           |
   |                        |                                   |                                       |
   |                        |                                   | Minimum: **1**                        |
   |                        |                                   |                                       |
   |                        |                                   | Maximum: **64**                       |
   +------------------------+-----------------------------------+---------------------------------------+
   | vip_subnet_cidr_id     | String                            | Specifies the ID of the IPv4 subnet   |
   |                        |                                   | where the load balancer works.        |
   |                        |                                   |                                       |
   |                        |                                   | Minimum: **1**                        |
   |                        |                                   |                                       |
   |                        |                                   | Maximum: **36**                       |
   +------------------------+-----------------------------------+---------------------------------------+
   | name                   | String                            | Specifies the name of the load        |
   |                        |                                   | balancer.                             |
   |                        |                                   |                                       |
   |                        |                                   | Minimum: **1**                        |
   |                        |                                   |                                       |
   |                        |                                   | Maximum: **255**                      |
   +------------------------+-----------------------------------+---------------------------------------+
   | project_id             | String                            | Specifies the project ID of the load  |
   |                        |                                   | balancer.                             |
   |                        |                                   |                                       |
   |                        |                                   | Minimum: **1**                        |
   |                        |                                   |                                       |
   |                        |                                   | Maximum: **32**                       |
   +------------------------+-----------------------------------+---------------------------------------+
   | vip_port_id            | String                            | Specifies the ID of the port bound to |
   |                        |                                   | the virtual IP address (the value of  |
   |                        |                                   | **vip_address**) of the load          |
   |                        |                                   | balancer.                             |
   |                        |                                   |                                       |
   |                        |                                   | When you create a dedicated load      |
   |                        |                                   | balancer, the system automatically    |
   |                        |                                   | creates a port for the load balancer  |
   |                        |                                   | and associates the port with a        |
   |                        |                                   | default security group. However,      |
   |                        |                                   | security group rules containing the   |
   |                        |                                   | port will not affect traffic to and   |
   |                        |                                   | from the load balancer.               |
   +------------------------+-----------------------------------+---------------------------------------+
   | tags                   | Array of :ref:`dlbc_tag1` objects | Lists the tags added to the load      |
   |                        |                                   | balancer.                             |
   +------------------------+-----------------------------------+---------------------------------------+
   | created_at             | String                            | Specifies the time when the load      |
   |                        |                                   | balancer was created.                 |
   |                        |                                   |                                       |
   |                        |                                   | Minimum: **1**                        |
   |                        |                                   |                                       |
   |                        |                                   | Maximum: **20**                       |
   +------------------------+-----------------------------------+---------------------------------------+
   | updated_at             | String                            | Specifies the time when the load      |
   |                        |                                   | balancer was updated.                 |
   |                        |                                   |                                       |
   |                        |                                   | Minimum: **1**                        |
   |                        |                                   |                                       |
   |                        |                                   | Maximum: **20**                       |
   +------------------------+-----------------------------------+---------------------------------------+
   | guaranteed             | Boolean                           | Specifies whether the load balancer   |
   |                        |                                   | is a dedicated load balancer.         |
   |                        |                                   |                                       |
   |                        |                                   | The value can be **true** or          |
   |                        |                                   | **false**. **true** indicates a       |
   |                        |                                   | dedicated load balancer, and          |
   |                        |                                   | **false** indicates a shared load     |
   |                        |                                   | balancer. When dedicated load         |
   |                        |                                   | balancers are launched in the         |
   |                        |                                   | **eu-de** region, either **true** or  |
   |                        |                                   | **false** will be returned when you   |
   |                        |                                   | use the API to query or update a load |
   |                        |                                   | balancer.                             |
   |                        |                                   |                                       |
   |                        |                                   | Default: **true**                     |
   +------------------------+-----------------------------------+---------------------------------------+
   | vpc_id                 | String                            | Specifies the ID of the VPC where the |
   |                        |                                   | load balancer works.                  |
   +------------------------+-----------------------------------+---------------------------------------+
   | eips                   | Array of :ref:`dlbc_ei1` objects  | Specifies the EIP bound to the load   |
   |                        |                                   | balancer.                             |
   +------------------------+-----------------------------------+---------------------------------------+
   | ipv6_vip_address       | String                            | Specifies the IPv6 address bound to   |
   |                        |                                   | the load balancer.                    |
   |                        |                                   |                                       |
   |                        |                                   | This parameter is unsupported. Please |
   |                        |                                   | do not use it.                        |
   |                        |                                   |                                       |
   |                        |                                   | Default: **None**                     |
   |                        |                                   |                                       |
   |                        |                                   | Minimum: **1**                        |
   |                        |                                   |                                       |
   |                        |                                   | Maximum: **64**                       |
   +------------------------+-----------------------------------+---------------------------------------+
   | ipv6_vip_virsubnet_id  | String                            | Specifies the ID of the IPv6 subnet   |
   |                        |                                   | where the load balancer works.        |
   |                        |                                   |                                       |
   |                        |                                   | This parameter is unsupported. Please |
   |                        |                                   | do not use it.                        |
   +------------------------+-----------------------------------+---------------------------------------+
   | ipv6_vip_port_id       | String                            | Specifies the ID of the port bound to |
   |                        |                                   | the IPv6 address.                     |
   |                        |                                   |                                       |
   |                        |                                   | This parameter is unsupported. Please |
   |                        |                                   | do not use it.                        |
   +------------------------+-----------------------------------+---------------------------------------+
   | availability_zone_list | Array of strings                  | Specifies the list of AZs where the   |
   |                        |                                   | load balancer is created.             |
   +------------------------+-----------------------------------+---------------------------------------+
   | enterprise_project_id  | String                            | Specifies the enterprise project ID.  |
   |                        |                                   |                                       |
   |                        |                                   | If this parameter is not passed       |
   |                        |                                   | during resource creation, the         |
   |                        |                                   | resource belongs to the default       |
   |                        |                                   | enterprise project.                   |
   |                        |                                   |                                       |
   |                        |                                   | This parameter is unsupported. Please |
   |                        |                                   | do not use it.                        |
   |                        |                                   |                                       |
   |                        |                                   | Default: **0**                        |
   +------------------------+-----------------------------------+---------------------------------------+
   | l4_flavor_id           | String                            | Specifies the Layer-4 flavor.         |
   |                        |                                   |                                       |
   |                        |                                   | Minimum: **1**                        |
   |                        |                                   |                                       |
   |                        |                                   | Maximum: **255**                      |
   +------------------------+-----------------------------------+---------------------------------------+
   | l4_scale_flavor_id     | String                            | Specifies the reserved Layer 4        |
   |                        |                                   | flavor.                               |
   |                        |                                   |                                       |
   |                        |                                   | Minimum: **1**                        |
   |                        |                                   |                                       |
   |                        |                                   | Maximum: **255**                      |
   +------------------------+-----------------------------------+---------------------------------------+
   | l7_flavor_id           | String                            | Specifies the Layer-7 flavor.         |
   |                        |                                   |                                       |
   |                        |                                   | Minimum: **1**                        |
   |                        |                                   |                                       |
   |                        |                                   | Maximum: **255**                      |
   +------------------------+-----------------------------------+---------------------------------------+
   | l7_scale_flavor_id     | String                            | Specifies the reserved Layer 7        |
   |                        |                                   | flavor.                               |
   |                        |                                   |                                       |
   |                        |                                   | Minimum: **1**                        |
   |                        |                                   |                                       |
   |                        |                                   | Maximum: **255**                      |
   +------------------------+-----------------------------------+---------------------------------------+
   | publicips              | Array of :ref:`dlbc_pi1` objects  | Specifies the EIP bound to the load   |
   |                        |                                   | balancer.                             |
   +------------------------+-----------------------------------+---------------------------------------+
   | elb_virsubnet_ids      | Array of strings                  | Specifies the ID of the subnet on the |
   |                        |                                   | downstream plane. The ports used by   |
   |                        |                                   | the load balancer dynamically occupy  |
   |                        |                                   | IP addresses in the subnet.           |
   +------------------------+-----------------------------------+---------------------------------------+
   | ip_target_enable       | Boolean                           | Specifies whether to enable cross-VPC |
   |                        |                                   | backend.                              |
   |                        |                                   |                                       |
   |                        |                                   | This parameter is unsupported. Please |
   |                        |                                   | do not use it.                        |
   |                        |                                   |                                       |
   |                        |                                   | Default: **false**                    |
   +------------------------+-----------------------------------+---------------------------------------+
   | frozen_scene           | String                            | Specifies the scenario where the load |
   |                        |                                   | balancer is frozen. Use commas to     |
   |                        |                                   | separate multiple scenarios.          |
   |                        |                                   |                                       |
   |                        |                                   | If the value is **ARREAR**, the load  |
   |                        |                                   | balancer is frozen because your       |
   |                        |                                   | account is in arrears.                |
   +------------------------+-----------------------------------+---------------------------------------+
   | ipv6_bandwidth         | :ref:`dlbc_br1` object            | Specifies the ID of the bandwidth.    |
   |                        |                                   | This parameter is available only when |
   |                        |                                   | you create or update a dedicated load |
   |                        |                                   | balancer that has an IPv6 address     |
   |                        |                                   | bound.                                |
   |                        |                                   |                                       |
   |                        |                                   | If you use a new IPv6 address and     |
   |                        |                                   | specify a shared bandwidth, the IPv6  |
   |                        |                                   | address will be added to the shared   |
   |                        |                                   | bandwidth.                            |
   |                        |                                   |                                       |
   |                        |                                   | This parameter is unsupported. Please |
   |                        |                                   | do not use it.                        |
   +------------------------+-----------------------------------+---------------------------------------+

.. _dlbc_pr1:
.. table:: **Table 11** PoolRef

   ========= ====== =============================================
   Parameter Type   Description
   ========= ====== =============================================
   id        String Specifies the ID of the backend server group.
   ========= ====== =============================================

.. _dlbc_lr1:
.. table:: **Table 12** ListenerRef

   ========= ====== ==========================
   Parameter Type   Description
   ========= ====== ==========================
   id        String Specifies the listener ID.
   ========= ====== ==========================

.. _dlbc_tag1:
.. table:: **Table 13** Tag

   ========= ====== ========================
   Parameter Type   Description
   ========= ====== ========================
   key       String Specifies the tag key.
   value     String Specifies the tag value.
   ========= ====== ========================

.. _dlbc_ei1:
.. table:: **Table 14** EipInfo

   +-------------+---------+---------------------------------------+
   | Parameter   | Type    | Description                           |
   +=============+=========+=======================================+
   | eip_id      | String  | Specifies the EIP ID.                 |
   +-------------+---------+---------------------------------------+
   | eip_address | String  | Specifies the specific IP address.    |
   +-------------+---------+---------------------------------------+
   | ip_version  | Integer | Specifies the IP version. **4**       |
   |             |         | indicates IPv4, and **6** indicates   |
   |             |         | IPv6.                                 |
   |             |         |                                       |
   |             |         | IPv6 is unsupported. The value cannot |
   |             |         | be **6**.                             |
   +-------------+---------+---------------------------------------+

.. _dlbc_pi1:
.. table:: **Table 15** PublicIpInfo

   +------------------+---------+---------------------------------------+
   | Parameter        | Type    | Description                           |
   +==================+=========+=======================================+
   | publicip_id      | String  | Specifies the EIP ID.                 |
   +------------------+---------+---------------------------------------+
   | publicip_address | String  | Specifies the IP address.             |
   +------------------+---------+---------------------------------------+
   | ip_version       | Integer | Specifies the IP version. The value   |
   |                  |         | can be **4** (IPv4) or **6** (IPv6).  |
   |                  |         |                                       |
   |                  |         | IPv6 is unsupported. The value cannot |
   |                  |         | be **6**.                             |
   +------------------+---------+---------------------------------------+

.. _dlbc_br1:
.. table:: **Table 16** BandwidthRef

   ========= ====== ==================================
   Parameter Type   Description
   ========= ====== ==================================
   id        String Specifies the shared bandwidth ID.
   ========= ====== ==================================

Example Requests
^^^^^^^^^^^^^^^^

Example 1: Creating a load balancer with an IPv4 EIP

.. code::

   POST

   https://{ELB_Endponit}/v3/060576782980d5762f9ec014dd2f1148/elb/loadbalancers

   {
     "loadbalancer" : {
       "vpc_id" : "e5a892ff-3c33-44ef-ada5-b713eb1f7a8b",
       "availability_zone_list" : [ "br-iaas-odin1a" ],
       "admin_state_up" : true,
       "vip_subnet_cidr_id" : "1800b6b8-a69f-4719-813d-24d62aaf32bd",
       "elb_virsubnet_ids" : [ "1fe8c0a8-d648-4294-8ea5-4d7f0c700e69" ],
       "name" : "elb-ipv4-public",
       "publicip" : {
         "network_type" : "5_bgp",
         "bandwidth" : {
           "size" : 2,
           "share_type" : "PER",
           "charge_mode" : "traffic",
           "name" : "elb_eip_traffic"
         }
       }
     }
   }

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 201**

Successful request.

.. code::

   {
     "request_id" : "86bb342be098113734389bffcf593607",
     "loadbalancer" : {
       "id" : "badd5a4b-14cf-4319-ac91-4182a80dee9a",
       "project_id" : "060576782980d5762f9ec014dd2f1148",
       "name" : "elb-ipv4-public",
       "description" : "",
       "vip_port_id" : "265c13fb-49a9-4f51-b848-7f0cced0aef0",
       "vip_address" : "192.168.0.151",
       "admin_state_up" : true,
       "provisioning_status" : "ACTIVE",
       "operating_status" : "ONLINE",
       "listeners" : [ ],
       "pools" : [ ],
       "tags" : [ ],
       "provider" : "vlb",
       "created_at" : "2021-03-29T02:44:47Z",
       "updated_at" : "2021-03-29T02:44:47Z",
       "vpc_id" : "e5a892ff-3c33-44ef-ada5-b713eb1f7a8b",
       "enterprise_project_id" : "0",
       "availability_zone_list" : [ "br-iaas-odin1a" ],
       "publicips" : [ {
         "publicip_id" : "448d497a-8f65-4c17-b2b2-f21279446e00",
         "publicip_address" : "10.246.170.154",
         "ip_version" : 4
       } ],
       "elb_virsubnet_ids" : [ "4df3e391-5ebf-4300-b614-cf5a4e793666" ],
       "elb_virsubnet_type" : "dualstack",
       "ip_target_enable" : false,
       "eips" : [ {
         "eip_id" : "448d497a-8f65-4c17-b2b2-f21279446e00",
         "eip_address" : "10.246.170.154",
         "ip_version" : 4
       } ],
       "guaranteed" : true,
       "l4_flavor_id" : "e5acacda-f861-404e-9871-df480c49d185",
       "l7_flavor_id" : "2f124f60-980a-42f3-b201-35461df1b936",
       "vip_subnet_cidr_id" : "1800b6b8-a69f-4719-813d-24d62aaf32bd"
     }
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

Querying Load Balancers
=======================

Function
^^^^^^^^

This API is used to query all load balancers. Both filtered query and
pagination query are supported.

Constraints
^^^^^^^^^^^

Parameters **marker**, **limit**, and **page_reverse** are used for pagination
query.

Parameters **marker** and **page_reverse** take effect only when they are used
together with parameter **limit**.

URI
^^^

GET /v3/{project_id}/elb/loadbalancers

.. table:: **Table 1** Path parameters

   +------------+-----------+--------+---------------------------+
   | Parameter  | Mandatory | Type   | Description               |
   +============+===========+========+===========================+
   | project_id | Yes       | String | Specifies the project ID. |
   |            |           |        |                           |
   |            |           |        | Minimum: **1**            |
   |            |           |        | Maximum: **255**          |
   +------------+-----------+--------+---------------------------+

.. table:: **Table 2** Query parameters

   +------------------------+-----------+---------+-----------------------------+
   | Parameter              | Mandatory | Type    | Description                 |
   +========================+===========+=========+=============================+
   | marker                 | No        | String  | Specifies the ID of the     |
   |                        |           |         | last record on the previous |
   |                        |           |         | page.                       |
   |                        |           |         |                             |
   |                        |           |         | Note:                       |
   |                        |           |         |                             |
   |                        |           |         | -  This parameter must be   |
   |                        |           |         |    used together with       |
   |                        |           |         |    **limit**.               |
   |                        |           |         | -  If this parameter is not |
   |                        |           |         |    specified, the first     |
   |                        |           |         |    page will be queried.    |
   |                        |           |         | -  This parameter cannot be |
   |                        |           |         |    left blank or set to an  |
   |                        |           |         |    invalid ID.              |
   +------------------------+-----------+---------+-----------------------------+
   | limit                  | No        | Integer | Specifies the number of     |
   |                        |           |         | records on each page.       |
   |                        |           |         |                             |
   |                        |           |         | Minimum: **0**              |
   |                        |           |         |                             |
   |                        |           |         | Maximum: **2000**           |
   +------------------------+-----------+---------+-----------------------------+
   | page_reverse           | No        | Boolean | Specifies the page          |
   |                        |           |         | direction.                  |
   |                        |           |         |                             |
   |                        |           |         | The value can be **true**   |
   |                        |           |         | or **false**, and the       |
   |                        |           |         | default value is **false**. |
   |                        |           |         |                             |
   |                        |           |         | The last page in the list   |
   |                        |           |         | requested with              |
   |                        |           |         | **page_reverse** set to     |
   |                        |           |         | **false** will not contain  |
   |                        |           |         | the "next" link, and the    |
   |                        |           |         | last page in the list       |
   |                        |           |         | requested with              |
   |                        |           |         | **page_reverse** set to     |
   |                        |           |         | **true** will not contain   |
   |                        |           |         | the "previous" link.        |
   |                        |           |         |                             |
   |                        |           |         | This parameter must be used |
   |                        |           |         | together with **limit**.    |
   +------------------------+-----------+---------+-----------------------------+
   | id                     | No        | Array   | Specifies the load balancer |
   |                        |           |         | ID.                         |
   |                        |           |         |                             |
   |                        |           |         | Multiple IDs can be queried |
   |                        |           |         | in the format of            |
   |                        |           |         | *id=xxx&id=xxx*.            |
   +------------------------+-----------+---------+-----------------------------+
   | name                   | No        | Array   | Specifies the load balancer |
   |                        |           |         | name.                       |
   |                        |           |         |                             |
   |                        |           |         | Multiple names can be       |
   |                        |           |         | queried in the format of    |
   |                        |           |         | *name=xxx&name=xxx*.        |
   +------------------------+-----------+---------+-----------------------------+
   | description            | No        | Array   | Provides supplementary      |
   |                        |           |         | information about the load  |
   |                        |           |         | balancer.                   |
   |                        |           |         |                             |
   |                        |           |         | Multiple descriptions can   |
   |                        |           |         | be queried in the format of |
   |                        |           |         | *descri                     |
   |                        |           |         | ption=xxx&description=xxx*. |
   +------------------------+-----------+---------+-----------------------------+
   | admin_state_up         | No        | Boolean | Specifies the               |
   |                        |           |         | administrative status of    |
   |                        |           |         | the load balancer.          |
   |                        |           |         |                             |
   |                        |           |         | This parameter is           |
   |                        |           |         | unsupported. Please do not  |
   |                        |           |         | use it.                     |
   +------------------------+-----------+---------+-----------------------------+
   | provisioning_status    | No        | Array   | Specifies the provisioning  |
   |                        |           |         | status of the load          |
   |                        |           |         | balancer. The value can     |
   |                        |           |         | only be **ACTIVE**,         |
   |                        |           |         | indicating that the load    |
   |                        |           |         | balancer is provisioned     |
   |                        |           |         | successfully.               |
   |                        |           |         |                             |
   |                        |           |         | Multiple provisioning       |
   |                        |           |         | statuses can be queried in  |
   |                        |           |         | the format of               |
   |                        |           |         | *provisioning_status=xx     |
   |                        |           |         | x&provisioning_status=xxx*. |
   +------------------------+-----------+---------+-----------------------------+
   | operating_status       | No        | Array   | Specifies the operating     |
   |                        |           |         | status of the load          |
   |                        |           |         | balancer. The value can     |
   |                        |           |         | only be **ONLINE**,         |
   |                        |           |         | indicating that the load    |
   |                        |           |         | balancer is working         |
   |                        |           |         | normally.                   |
   |                        |           |         |                             |
   |                        |           |         | Multiple operating statuses |
   |                        |           |         | can be queried in the       |
   |                        |           |         | format of                   |
   |                        |           |         | *operating_status           |
   |                        |           |         | =xxx&operating_status=xxx*. |
   +------------------------+-----------+---------+-----------------------------+
   | guaranteed             | No        | Boolean | Specifies whether the load  |
   |                        |           |         | balancer is a dedicated     |
   |                        |           |         | load balancer. The value    |
   |                        |           |         | can only be **true**.       |
   +------------------------+-----------+---------+-----------------------------+
   | vpc_id                 | No        | Array   | Specifies the ID of the VPC |
   |                        |           |         | where the load balancer     |
   |                        |           |         | works.                      |
   |                        |           |         |                             |
   |                        |           |         | Multiple IDs can be queried |
   |                        |           |         | in the format of            |
   |                        |           |         | *vpc_id=xxx&vpc_id=xxx*.    |
   +------------------------+-----------+---------+-----------------------------+
   | vip_port_id            | No        | Array   | Specifies the ID of the     |
   |                        |           |         | port bound to the virtual   |
   |                        |           |         | IP address of the load      |
   |                        |           |         | balancer.                   |
   |                        |           |         |                             |
   |                        |           |         | Multiple IDs can be queried |
   |                        |           |         | in the format of            |
   |                        |           |         | *vip_po                     |
   |                        |           |         | rt_id=xxx&vip_port_id=xxx*. |
   +------------------------+-----------+---------+-----------------------------+
   | vip_address            | No        | Array   | Specifies the virtual IP    |
   |                        |           |         | address bound to the load   |
   |                        |           |         | balancer.                   |
   |                        |           |         |                             |
   |                        |           |         | Multiple virtual IP         |
   |                        |           |         | addresses can be queried in |
   |                        |           |         | the format of               |
   |                        |           |         | *vip_ad                     |
   |                        |           |         | dress=xxx&vip_address=xxx*. |
   +------------------------+-----------+---------+-----------------------------+
   | vip_subnet_cidr_id     | No        | Array   | Specifies the ID of the     |
   |                        |           |         | subnet where the load       |
   |                        |           |         | balancer works.             |
   |                        |           |         |                             |
   |                        |           |         | Multiple IDs can be queried |
   |                        |           |         | in the format of            |
   |                        |           |         | *vip_subnet_cidr_id=x       |
   |                        |           |         | xx&vip_subnet_cidr_id=xxx*. |
   +------------------------+-----------+---------+-----------------------------+
   | l4_flavor_id           | No        | Array   | Specifies the ID of the     |
   |                        |           |         | flavor at Layer 4.          |
   |                        |           |         |                             |
   |                        |           |         | Multiple IDs can be queried |
   |                        |           |         | in the format of            |
   |                        |           |         | *l4_flavo                   |
   |                        |           |         | r_id=xxx&l4_flavor_id=xxx*. |
   +------------------------+-----------+---------+-----------------------------+
   | l4_scale_flavor_id     | No        | Array   | Specifies the elastic       |
   |                        |           |         | flavor that is reserved for |
   |                        |           |         | now.                        |
   |                        |           |         |                             |
   |                        |           |         | Multiple flavors can be     |
   |                        |           |         | queried in the format of    |
   |                        |           |         | *l4_scale_flavor_id=x       |
   |                        |           |         | xx&l4_scale_flavor_id=xxx*. |
   +------------------------+-----------+---------+-----------------------------+
   | ipv6_vip_address       | No        | Array   | Specifies the IPv6 address  |
   |                        |           |         | bound to the load balancer. |
   |                        |           |         |                             |
   |                        |           |         | Multiple IPv6 addresses can |
   |                        |           |         | be queried in the format of |
   |                        |           |         | *ipv6_vip_address           |
   |                        |           |         | =xxx&ipv6_vip_address=xxx*. |
   |                        |           |         |                             |
   |                        |           |         | This parameter is           |
   |                        |           |         | unsupported. Please do not  |
   |                        |           |         | use it.                     |
   +------------------------+-----------+---------+-----------------------------+
   | ipv6_vip_virsubnet_id  | No        | Array   | Specifies the ID of the     |
   |                        |           |         | IPv6 subnet where the load  |
   |                        |           |         | balancer works.             |
   |                        |           |         |                             |
   |                        |           |         | Multiple IDs can be queried |
   |                        |           |         | in the format of            |
   |                        |           |         | *ipv6_vip_virsubnet_id=xxx& |
   |                        |           |         | ipv6_vip_virsubnet_id=xxx*. |
   |                        |           |         |                             |
   |                        |           |         | This parameter is           |
   |                        |           |         | unsupported. Please do not  |
   |                        |           |         | use it.                     |
   +------------------------+-----------+---------+-----------------------------+
   | ipv6_vip_port_id       | No        | Array   | Specifies the ID of the     |
   |                        |           |         | port bound to the IPv6      |
   |                        |           |         | address of the load         |
   |                        |           |         | balancer.                   |
   |                        |           |         |                             |
   |                        |           |         | Multiple ports can be       |
   |                        |           |         | queried in the format of    |
   |                        |           |         | *ipv6_vip_port_id           |
   |                        |           |         | =xxx&ipv6_vip_port_id=xxx*. |
   |                        |           |         |                             |
   |                        |           |         | This parameter is           |
   |                        |           |         | unsupported. Please do not  |
   |                        |           |         | use it.                     |
   +------------------------+-----------+---------+-----------------------------+
   | availability_zone_list | No        | Array   | Specifies the list of AZs   |
   |                        |           |         | where the load balancer is  |
   |                        |           |         | created. You can query the  |
   |                        |           |         | AZs by calling the API      |
   |                        |           |         | (/v3/{project_i             |
   |                        |           |         | d}/elb/availability-zones). |
   |                        |           |         |                             |
   |                        |           |         | Multiple AZs can be queried |
   |                        |           |         | in the format of            |
   |                        |           |         | *a                          |
   |                        |           |         | vailability_zone_list=xxx&a |
   |                        |           |         | vailability_zone_list=xxx*. |
   +------------------------+-----------+---------+-----------------------------+
   | eips                   | No        | Array   | Specifies the EIP bound to  |
   |                        |           |         | the load balancer.          |
   |                        |           |         |                             |
   |                        |           |         | The following is an         |
   |                        |           |         | example:                    |
   |                        |           |         |                             |
   |                        |           |         | "eips": [ { "eip_id":       |
   |                        |           |         | "e9b72a9d-42                |
   |                        |           |         | 75-455e-a724-853504e4d9c6", |
   |                        |           |         | "eip_address":              |
   |                        |           |         | "88.88.14.122",             |
   |                        |           |         | "ip_version": 4 } ]         |
   |                        |           |         |                             |
   |                        |           |         | Multiple EIPs can be        |
   |                        |           |         | queried in the format of    |
   |                        |           |         | *eips=e                     |
   |                        |           |         | ip_id=xxx&eips=eip_id=xxx*. |
   +------------------------+-----------+---------+-----------------------------+
   | l7_flavor_id           | No        | Array   | Specifies the ID of the     |
   |                        |           |         | flavor at Layer 7.          |
   |                        |           |         |                             |
   |                        |           |         | Multiple flavors can be     |
   |                        |           |         | queried in the format of    |
   |                        |           |         | *l7_flavo                   |
   |                        |           |         | r_id=xxx&l7_flavor_id=xxx*. |
   +------------------------+-----------+---------+-----------------------------+
   | l7_scale_flavor_id     | No        | Array   | Specifies the elastic       |
   |                        |           |         | flavor that is reserved for |
   |                        |           |         | now.                        |
   |                        |           |         |                             |
   |                        |           |         | Multiple flavors can be     |
   |                        |           |         | queried in the format of    |
   |                        |           |         | *l7_scale_flavor_id=x       |
   |                        |           |         | xx&l7_scale_flavor_id=xxx*. |
   +------------------------+-----------+---------+-----------------------------+
   | member_device_id       | No        | Array   | Specifies the ID of the     |
   |                        |           |         | cloud server that serves as |
   |                        |           |         | a backend server. This      |
   |                        |           |         | parameter is used only as a |
   |                        |           |         | query condition and is not  |
   |                        |           |         | included in the response.   |
   |                        |           |         |                             |
   |                        |           |         | Multiple IDs can be queried |
   |                        |           |         | in the format of            |
   |                        |           |         | *member_device_id           |
   |                        |           |         | =xxx&member_device_id=xxx*. |
   +------------------------+-----------+---------+-----------------------------+
   | member_address         | No        | Array   | Specifies the private IP    |
   |                        |           |         | address of the backend      |
   |                        |           |         | server. This parameter is   |
   |                        |           |         | used only as a query        |
   |                        |           |         | condition and is not        |
   |                        |           |         | included in the response.   |
   +------------------------+-----------+---------+-----------------------------+
   | enterprise_project_id  | No        | Array   | Specifies the enterprise    |
   |                        |           |         | project ID.                 |
   |                        |           |         |                             |
   |                        |           |         | -  If this parameter is not |
   |                        |           |         |    passed, resources in the |
   |                        |           |         |    default enterprise       |
   |                        |           |         |    project are queried, and |
   |                        |           |         |    authentication is        |
   |                        |           |         |    performed based on the   |
   |                        |           |         |    default enterprise       |
   |                        |           |         |    project.                 |
   |                        |           |         | -  If this parameter is     |
   |                        |           |         |    passed, its value can be |
   |                        |           |         |    the ID of an existing    |
   |                        |           |         |    enterprise project or    |
   |                        |           |         |    **all_granted_eps**.     |
   |                        |           |         |                             |
   |                        |           |         | If the value is a specific  |
   |                        |           |         | ID, resources in the        |
   |                        |           |         | specific enterprise project |
   |                        |           |         | are required. If the value  |
   |                        |           |         | is **all_granted_eps**,     |
   |                        |           |         | resources in all enterprise |
   |                        |           |         | projects are queried.       |
   |                        |           |         |                             |
   |                        |           |         | Multiple IDs can be queried |
   |                        |           |         | in the format of            |
   |                        |           |         | *enterprise_project_id=xxx& |
   |                        |           |         | enterprise_project_id=xxx*. |
   |                        |           |         |                             |
   |                        |           |         | This parameter is           |
   |                        |           |         | unsupported. Please do not  |
   |                        |           |         | use it.                     |
   +------------------------+-----------+---------+-----------------------------+
   | publicips              | No        | Array   | Specifies the public IP     |
   |                        |           |         | address bound to the load   |
   |                        |           |         | balancer.                   |
   |                        |           |         |                             |
   |                        |           |         | The following is an         |
   |                        |           |         | example:                    |
   |                        |           |         |                             |
   |                        |           |         | "publicips": [ {            |
   |                        |           |         | "publicip_id":              |
   |                        |           |         | "e9b72a9d-42                |
   |                        |           |         | 75-455e-a724-853504e4d9c6", |
   |                        |           |         | "publicip_address":         |
   |                        |           |         | "88.88.14.122",             |
   |                        |           |         | "publicip_ip_version": 4 }  |
   |                        |           |         | ]                           |
   |                        |           |         |                             |
   |                        |           |         | Multiple EIPs can be        |
   |                        |           |         | queried in the format of    |
   |                        |           |         | *publicips=publicip_id=xxx& |
   |                        |           |         | publicips=publicip_id=xxx*. |
   +------------------------+-----------+---------+-----------------------------+
   | ip_version             | No        | Array   | Specifies the IP version.   |
   |                        |           |         | The value can be **4**      |
   |                        |           |         | (IPv4) or **6** (IPv6).     |
   |                        |           |         |                             |
   |                        |           |         | Multiple versions can be    |
   |                        |           |         | queried in the format of    |
   |                        |           |         | *ip_v                       |
   |                        |           |         | ersion=xxx&ip_version=xxx*. |
   |                        |           |         |                             |
   |                        |           |         | IPv6 is unsupported. The    |
   |                        |           |         | value cannot be **6**.      |
   +------------------------+-----------+---------+-----------------------------+

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 3** Request header parameters

   ============ ========= ====== ================================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ================================================
   X-Auth-Token No        String Specifies the token used for IAM authentication.
   ============ ========= ====== ================================================

Response Parameters
^^^^^^^^^^^^^^^^^^^

**Status code: 200**

.. table:: **Table 4** Response body parameters

   +---------------+-------------------------+------------------------------------------------+
   | Parameter     | Type                    | Description                                    |
   +===============+=========================+================================================+
   | loadbalancers | Array of                | Lists the load balancers.                      |
   |               | :ref:`dlbl_lb` objects  |                                                |
   +---------------+-------------------------+------------------------------------------------+
   | page_info     | :ref:`dlbl_page` object | Provides load balancer pagination information. |
   +---------------+-------------------------+------------------------------------------------+
   | request_id    | String                  | Specifies the request ID. The value is         |
   |               |                         | automatically generated.                       |
   +---------------+-------------------------+------------------------------------------------+

.. _dlbl_lb:
.. table:: **Table 5** LoadBalancer

   +------------------------+----------------------------------+---------------------------------------+
   | Parameter              | Type                             | Description                           |
   +========================+==================================+=======================================+
   | id                     | String                           | Specifies the load balancer ID.       |
   |                        |                                  |                                       |
   |                        |                                  | Default: **Automatically generated**  |
   +------------------------+----------------------------------+---------------------------------------+
   | description            | String                           | Provides supplementary information    |
   |                        |                                  | about the load balancer.              |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **255**                      |
   +------------------------+----------------------------------+---------------------------------------+
   | provisioning_status    | String                           | Specifies the provisioning status of  |
   |                        |                                  | the load balancer. The value can only |
   |                        |                                  | be **ACTIVE**.                        |
   +------------------------+----------------------------------+---------------------------------------+
   | admin_state_up         | Boolean                          | Specifies the administrative status   |
   |                        |                                  | of the load balancer. The value can   |
   |                        |                                  | only be **true**.                     |
   |                        |                                  |                                       |
   |                        |                                  | This parameter is unsupported. Please |
   |                        |                                  | do not use it.                        |
   |                        |                                  |                                       |
   |                        |                                  | Default: **true**                     |
   +------------------------+----------------------------------+---------------------------------------+
   | provider               | String                           | Specifies the provider of the load    |
   |                        |                                  | balancer. The value can only be       |
   |                        |                                  | **vlb**.                              |
   |                        |                                  |                                       |
   |                        |                                  | Default: **vlb**                      |
   +------------------------+----------------------------------+---------------------------------------+
   | pools                  | Array of :ref:`dlbl_pr` objects  | Lists the IDs of backend server       |
   |                        |                                  | groups associated with the load       |
   |                        |                                  | balancer.                             |
   +------------------------+----------------------------------+---------------------------------------+
   | listeners              | Array of :ref:`dlbl_lr` objects  | Lists the IDs of listeners added to   |
   |                        |                                  | the load balancer.                    |
   +------------------------+----------------------------------+---------------------------------------+
   | operating_status       | String                           | Specifies the operating status of the |
   |                        |                                  | load balancer. The value can only be  |
   |                        |                                  | **ONLINE**.                           |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **16**                       |
   +------------------------+----------------------------------+---------------------------------------+
   | vip_address            | String                           | Specifies the private IPv4 address    |
   |                        |                                  | bound to the load balancer.           |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **64**                       |
   +------------------------+----------------------------------+---------------------------------------+
   | vip_subnet_cidr_id     | String                           | Specifies the ID of the IPv4 subnet   |
   |                        |                                  | where the load balancer works.        |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **36**                       |
   +------------------------+----------------------------------+---------------------------------------+
   | name                   | String                           | Specifies the name of the load        |
   |                        |                                  | balancer.                             |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **255**                      |
   +------------------------+----------------------------------+---------------------------------------+
   | project_id             | String                           | Specifies the project ID of the load  |
   |                        |                                  | balancer.                             |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **32**                       |
   +------------------------+----------------------------------+---------------------------------------+
   | vip_port_id            | String                           | Specifies the ID of the port bound to |
   |                        |                                  | the virtual IP address (the value of  |
   |                        |                                  | **vip_address**) of the load          |
   |                        |                                  | balancer.                             |
   |                        |                                  |                                       |
   |                        |                                  | When you create a dedicated load      |
   |                        |                                  | balancer, the system automatically    |
   |                        |                                  | creates a port for the load balancer  |
   |                        |                                  | and associates the port with a        |
   |                        |                                  | default security group. However,      |
   |                        |                                  | security group rules containing the   |
   |                        |                                  | port will not affect traffic to and   |
   |                        |                                  | from the load balancer.               |
   +------------------------+----------------------------------+---------------------------------------+
   | tags                   | Array of :ref:`dlbl_tag` objects | Lists the tags added to the load      |
   |                        |                                  | balancer.                             |
   +------------------------+----------------------------------+---------------------------------------+
   | created_at             | String                           | Specifies the time when the load      |
   |                        |                                  | balancer was created.                 |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **20**                       |
   +------------------------+----------------------------------+---------------------------------------+
   | updated_at             | String                           | Specifies the time when the load      |
   |                        |                                  | balancer was updated.                 |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **20**                       |
   +------------------------+----------------------------------+---------------------------------------+
   | guaranteed             | Boolean                          | Specifies whether the load balancer   |
   |                        |                                  | is a dedicated load balancer.         |
   |                        |                                  |                                       |
   |                        |                                  | The value can be **true** or          |
   |                        |                                  | **false**. **true** indicates a       |
   |                        |                                  | dedicated load balancer, and          |
   |                        |                                  | **false** indicates a shared load     |
   |                        |                                  | balancer. When dedicated load         |
   |                        |                                  | balancers are launched in the         |
   |                        |                                  | **eu-de** region, either **true** or  |
   |                        |                                  | **false** will be returned when you   |
   |                        |                                  | use the API to query or update a load |
   |                        |                                  | balancer.                             |
   |                        |                                  |                                       |
   |                        |                                  | Default: **true**                     |
   +------------------------+----------------------------------+---------------------------------------+
   | vpc_id                 | String                           | Specifies the ID of the VPC where the |
   |                        |                                  | load balancer works.                  |
   +------------------------+----------------------------------+---------------------------------------+
   | eips                   | Array of :ref:`dlbl_ei` objects  | Specifies the EIP bound to the load   |
   |                        |                                  | balancer.                             |
   +------------------------+----------------------------------+---------------------------------------+
   | ipv6_vip_address       | String                           | Specifies the IPv6 address bound to   |
   |                        |                                  | the load balancer.                    |
   |                        |                                  |                                       |
   |                        |                                  | This parameter is unsupported. Please |
   |                        |                                  | do not use it.                        |
   |                        |                                  |                                       |
   |                        |                                  | Default: **None**                     |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **64**                       |
   +------------------------+----------------------------------+---------------------------------------+
   | ipv6_vip_virsubnet_id  | String                           | Specifies the ID of the IPv6 subnet   |
   |                        |                                  | where the load balancer works.        |
   |                        |                                  |                                       |
   |                        |                                  | This parameter is unsupported. Please |
   |                        |                                  | do not use it.                        |
   +------------------------+----------------------------------+---------------------------------------+
   | ipv6_vip_port_id       | String                           | Specifies the ID of the port bound to |
   |                        |                                  | the IPv6 address.                     |
   |                        |                                  |                                       |
   |                        |                                  | This parameter is unsupported. Please |
   |                        |                                  | do not use it.                        |
   +------------------------+----------------------------------+---------------------------------------+
   | availability_zone_list | Array of strings                 | Specifies the list of AZs where the   |
   |                        |                                  | load balancer is created.             |
   +------------------------+----------------------------------+---------------------------------------+
   | enterprise_project_id  | String                           | Specifies the enterprise project ID.  |
   |                        |                                  |                                       |
   |                        |                                  | If this parameter is not passed       |
   |                        |                                  | during resource creation, the         |
   |                        |                                  | resource belongs to the default       |
   |                        |                                  | enterprise project.                   |
   |                        |                                  |                                       |
   |                        |                                  | This parameter is unsupported. Please |
   |                        |                                  | do not use it.                        |
   |                        |                                  |                                       |
   |                        |                                  | Default: **0**                        |
   +------------------------+----------------------------------+---------------------------------------+
   | l4_flavor_id           | String                           | Specifies the Layer-4 flavor.         |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **255**                      |
   +------------------------+----------------------------------+---------------------------------------+
   | l4_scale_flavor_id     | String                           | Specifies the reserved Layer 4        |
   |                        |                                  | flavor.                               |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **255**                      |
   +------------------------+----------------------------------+---------------------------------------+
   | l7_flavor_id           | String                           | Specifies the Layer-7 flavor.         |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **255**                      |
   +------------------------+----------------------------------+---------------------------------------+
   | l7_scale_flavor_id     | String                           | Specifies the reserved Layer 7        |
   |                        |                                  | flavor.                               |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **255**                      |
   +------------------------+----------------------------------+---------------------------------------+
   | publicips              | Array of :ref:`dlbl_pi` objects  | Specifies the EIP bound to the load   |
   |                        |                                  | balancer.                             |
   +------------------------+----------------------------------+---------------------------------------+
   | elb_virsubnet_ids      | Array of strings                 | Specifies the ID of the subnet on the |
   |                        |                                  | downstream plane. The ports used by   |
   |                        |                                  | the load balancer dynamically occupy  |
   |                        |                                  | IP addresses in the subnet.           |
   +------------------------+----------------------------------+---------------------------------------+
   | ip_target_enable       | Boolean                          | Specifies whether to enable cross-VPC |
   |                        |                                  | backend.                              |
   |                        |                                  |                                       |
   |                        |                                  | This parameter is unsupported. Please |
   |                        |                                  | do not use it.                        |
   |                        |                                  |                                       |
   |                        |                                  | Default: **false**                    |
   +------------------------+----------------------------------+---------------------------------------+
   | frozen_scene           | String                           | Specifies the scenario where the load |
   |                        |                                  | balancer is frozen. Use commas to     |
   |                        |                                  | separate multiple scenarios.          |
   |                        |                                  |                                       |
   |                        |                                  | If the value is **ARREAR**, the load  |
   |                        |                                  | balancer is frozen because your       |
   |                        |                                  | account is in arrears.                |
   +------------------------+----------------------------------+---------------------------------------+
   | ipv6_bandwidth         | :ref:`dlbl_br` object            | Specifies the ID of the bandwidth.    |
   |                        |                                  | This parameter is available only when |
   |                        |                                  | you create or update a dedicated load |
   |                        |                                  | balancer that has an IPv6 address     |
   |                        |                                  | bound.                                |
   |                        |                                  |                                       |
   |                        |                                  | If you use a new IPv6 address and     |
   |                        |                                  | specify a shared bandwidth, the IPv6  |
   |                        |                                  | address will be added to the shared   |
   |                        |                                  | bandwidth.                            |
   |                        |                                  |                                       |
   |                        |                                  | This parameter is unsupported. Please |
   |                        |                                  | do not use it.                        |
   +------------------------+----------------------------------+---------------------------------------+

.. _dlbl_pr:
.. table:: **Table 6** PoolRef

   ========= ====== =============================================
   Parameter Type   Description
   ========= ====== =============================================
   id        String Specifies the ID of the backend server group.
   ========= ====== =============================================

.. _dlbl_lr:
.. table:: **Table 7** ListenerRef

   ========= ====== ==========================
   Parameter Type   Description
   ========= ====== ==========================
   id        String Specifies the listener ID.
   ========= ====== ==========================

.. _dlbl_tag:
.. table:: **Table 8** Tag

   ========= ====== ========================
   Parameter Type   Description
   ========= ====== ========================
   key       String Specifies the tag key.
   value     String Specifies the tag value.
   ========= ====== ========================

.. _dlbl_ei:
.. table:: **Table 9** EipInfo

   +-------------+---------+---------------------------------------+
   | Parameter   | Type    | Description                           |
   +=============+=========+=======================================+
   | eip_id      | String  | Specifies the EIP ID.                 |
   +-------------+---------+---------------------------------------+
   | eip_address | String  | Specifies the specific IP address.    |
   +-------------+---------+---------------------------------------+
   | ip_version  | Integer | Specifies the IP version. **4**       |
   |             |         | indicates IPv4, and **6** indicates   |
   |             |         | IPv6.                                 |
   |             |         |                                       |
   |             |         | IPv6 is unsupported. The value cannot |
   |             |         | be **6**.                             |
   +-------------+---------+---------------------------------------+

.. _dlbl_pi:
.. table:: **Table 10** PublicIpInfo

   +------------------+---------+---------------------------------------+
   | Parameter        | Type    | Description                           |
   +==================+=========+=======================================+
   | publicip_id      | String  | Specifies the EIP ID.                 |
   +------------------+---------+---------------------------------------+
   | publicip_address | String  | Specifies the IP address.             |
   +------------------+---------+---------------------------------------+
   | ip_version       | Integer | Specifies the IP version. The value   |
   |                  |         | can be **4** (IPv4) or **6** (IPv6).  |
   |                  |         |                                       |
   |                  |         | IPv6 is unsupported. The value cannot |
   |                  |         | be **6**.                             |
   +------------------+---------+---------------------------------------+

.. _dlbl_br:
.. table:: **Table 11** BandwidthRef

   ========= ====== ==================================
   Parameter Type   Description
   ========= ====== ==================================
   id        String Specifies the shared bandwidth ID.
   ========= ====== ==================================

.. _dlbl_page:
.. table:: **Table 12** PageInfo

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

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   GET

   https://{elb_endpoint}/v3/{project_id}/elb/loadbalancers?limit={num}&marker={loadbalancer_id}

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 200**

Successful request.

.. code::

   {
     "loadbalancers" : [ {
       "id" : "87627cb6-9ff1-4580-984f-cc564fa9fc34",
       "project_id" : "b2782e6708b8475c993e6064bc456bf8",
       "name" : "loadbalancer-cyf",
       "description" : "simple lb-cyf",
       "vip_port_id" : "0381c10b-4927-4fa5-a7b5-fa529c162a06",
       "vip_address" : "192.168.0.26",
       "admin_state_up" : true,
       "provisioning_status" : "ACTIVE",
       "operating_status" : "ONLINE",
       "listeners" : [ ],
       "pools" : [ ],
       "tags" : [ ],
       "provider" : "vlb",
       "created_at" : "2019-05-24T02:09:39Z",
       "updated_at" : "2019-05-24T02:09:39Z",
       "vpc_id" : "2037c5bb-e04b-4de2-9300-9051af18e417",
       "enterprise_project_id" : "0",
       "availability_zone_list" : [ "AZ1" ],
       "elb_virsubnet_ids" : [ "ad5d63bf-3b50-4e88-b4d9-e94a59aade48" ],
       "eips" : [ ],
       "guaranteed" : true,
       "l4_flavor_id" : "22365281-de68-45e4-ada4-b0920b6da3c2",
       "l7_flavor_id" : "0942eb8f-51fa-4354-87b1-bf4cfeca4823",
       "vip_subnet_cidr_id" : "1992ec06-f364-4ae3-b936-6a8cc24633b7"
     }, {
       "id" : "09e86f09-03fc-440e-8132-03f3e149e979",
       "project_id" : "b2782e6708b8475c993e6064bc456bf8",
       "name" : "loadbalancer-cyf",
       "description" : "simple lb-cyf",
       "vip_port_id" : "e0bb984a-d094-4559-9b3b-bd61b5eb3a8f",
       "vip_address" : "192.168.0.47",
       "admin_state_up" : true,
       "provisioning_status" : "ACTIVE",
       "operating_status" : "ONLINE",
       "listeners" : [ ],
       "pools" : [ ],
       "tags" : [ ],
       "provider" : "vlb",
       "created_at" : "2019-05-24T02:02:01Z",
       "updated_at" : "2019-05-24T02:02:01Z",
       "vpc_id" : "2037c5bb-e04b-4de2-9300-9051af18e417",
       "enterprise_project_id" : "0",
       "availability_zone_list" : [ "AZ1" ],
       "elb_virsubnet_ids" : [ "ad5d63bf-3b50-4e88-b4d9-e94a59aade48" ],
       "eips" : [ ],
       "guaranteed" : true,
       "vip_subnet_cidr_id" : "1992ec06-f364-4ae3-b936-6a8cc24633b7"
     } ],
     "page_info" : {
       "next_marker" : "09e86f09-03fc-440e-8132-03f3e149e979",
       "previous_marker" : "87627cb6-9ff1-4580-984f-cc564fa9fc34",
       "current_count" : 2
     },
     "request_id" : "8709f187-c879-446c-a198-8f93ede2c178"
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

Viewing Details of a Load Balancer
==================================

Function
^^^^^^^^

This API is used to view details of a load balancer.

URI
^^^

GET /v3/{project_id}/elb/loadbalancers/{loadbalancer_id}

.. table:: **Table 1** Path parameters

   =============== ========= ====== ===============================
   Parameter       Mandatory Type   Description
   =============== ========= ====== ===============================
   project_id      Yes       String Specifies the project ID.
   loadbalancer_id Yes       String Specifies the load balancer ID.
   =============== ========= ====== ===============================

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

   +--------------+--------------------------------------------------+----------------------------------------+
   | Parameter    | Type                                             | Description                            |
   +==============+==================================================+========================================+
   | request_id   | String                                           | Specifies the request ID. The value is |
   |              |                                                  | automatically generated.               |
   +--------------+--------------------------------------------------+----------------------------------------+
   | loadbalancer | :ref:`dlbs_lb` object                            | Specifies the load balancer.           |
   +--------------+--------------------------------------------------+----------------------------------------+

.. _dlbs_lb:
.. table:: **Table 4** LoadBalancer

   +------------------------+----------------------------------+---------------------------------------+
   | Parameter              | Type                             | Description                           |
   +========================+==================================+=======================================+
   | id                     | String                           | Specifies the load balancer ID.       |
   |                        |                                  |                                       |
   |                        |                                  | Default: **Automatically generated**  |
   +------------------------+----------------------------------+---------------------------------------+
   | description            | String                           | Provides supplementary information    |
   |                        |                                  | about the load balancer.              |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **255**                      |
   +------------------------+----------------------------------+---------------------------------------+
   | provisioning_status    | String                           | Specifies the provisioning status of  |
   |                        |                                  | the load balancer. The value can only |
   |                        |                                  | be **ACTIVE**.                        |
   +------------------------+----------------------------------+---------------------------------------+
   | admin_state_up         | Boolean                          | Specifies the administrative status   |
   |                        |                                  | of the load balancer. The value can   |
   |                        |                                  | only be **true**.                     |
   |                        |                                  |                                       |
   |                        |                                  | This parameter is unsupported. Please |
   |                        |                                  | do not use it.                        |
   |                        |                                  |                                       |
   |                        |                                  | Default: **true**                     |
   +------------------------+----------------------------------+---------------------------------------+
   | provider               | String                           | Specifies the provider of the load    |
   |                        |                                  | balancer. The value can only be       |
   |                        |                                  | **vlb**.                              |
   |                        |                                  |                                       |
   |                        |                                  | Default: **vlb**                      |
   +------------------------+----------------------------------+---------------------------------------+
   | pools                  | Array of :ref:`dlbs_pr` objects  | Lists the IDs of backend server       |
   |                        |                                  | groups associated with the load       |
   |                        |                                  | balancer.                             |
   |                        | objects                          |                                       |
   +------------------------+----------------------------------+---------------------------------------+
   | listeners              | Array of :ref:`dlbs_lr` objects  | Lists the IDs of listeners added to   |
   |                        |                                  | the load balancer.                    |
   +------------------------+----------------------------------+---------------------------------------+
   | operating_status       | String                           | Specifies the operating status of the |
   |                        |                                  | load balancer. The value can only be  |
   |                        |                                  | **ONLINE**.                           |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **16**                       |
   +------------------------+----------------------------------+---------------------------------------+
   | vip_address            | String                           | Specifies the private IPv4 address    |
   |                        |                                  | bound to the load balancer.           |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **64**                       |
   +------------------------+----------------------------------+---------------------------------------+
   | vip_subnet_cidr_id     | String                           | Specifies the ID of the IPv4 subnet   |
   |                        |                                  | where the load balancer works.        |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **36**                       |
   +------------------------+----------------------------------+---------------------------------------+
   | name                   | String                           | Specifies the name of the load        |
   |                        |                                  | balancer.                             |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **255**                      |
   +------------------------+----------------------------------+---------------------------------------+
   | project_id             | String                           | Specifies the project ID of the load  |
   |                        |                                  | balancer.                             |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **32**                       |
   +------------------------+----------------------------------+---------------------------------------+
   | vip_port_id            | String                           | Specifies the ID of the port bound to |
   |                        |                                  | the virtual IP address (the value of  |
   |                        |                                  | **vip_address**) of the load          |
   |                        |                                  | balancer.                             |
   |                        |                                  |                                       |
   |                        |                                  | When you create a dedicated load      |
   |                        |                                  | balancer, the system automatically    |
   |                        |                                  | creates a port for the load balancer  |
   |                        |                                  | and associates the port with a        |
   |                        |                                  | default security group. However,      |
   |                        |                                  | security group rules containing the   |
   |                        |                                  | port will not affect traffic to and   |
   |                        |                                  | from the load balancer.               |
   +------------------------+----------------------------------+---------------------------------------+
   | tags                   | Array of :ref:`dlbs_tag` objects | Lists the tags added to the load      |
   |                        |                                  | balancer.                             |
   +------------------------+----------------------------------+---------------------------------------+
   | created_at             | String                           | Specifies the time when the load      |
   |                        |                                  | balancer was created.                 |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **20**                       |
   +------------------------+----------------------------------+---------------------------------------+
   | updated_at             | String                           | Specifies the time when the load      |
   |                        |                                  | balancer was updated.                 |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **20**                       |
   +------------------------+----------------------------------+---------------------------------------+
   | guaranteed             | Boolean                          | Specifies whether the load balancer   |
   |                        |                                  | is a dedicated load balancer.         |
   |                        |                                  |                                       |
   |                        |                                  | The value can be **true** or          |
   |                        |                                  | **false**. **true** indicates a       |
   |                        |                                  | dedicated load balancer, and          |
   |                        |                                  | **false** indicates a shared load     |
   |                        |                                  | balancer. When dedicated load         |
   |                        |                                  | balancers are launched in the         |
   |                        |                                  | **eu-de** region, either **true** or  |
   |                        |                                  | **false** will be returned when you   |
   |                        |                                  | use the API to query or update a load |
   |                        |                                  | balancer.                             |
   |                        |                                  |                                       |
   |                        |                                  | Default: **true**                     |
   +------------------------+----------------------------------+---------------------------------------+
   | vpc_id                 | String                           | Specifies the ID of the VPC where the |
   |                        |                                  | load balancer works.                  |
   +------------------------+----------------------------------+---------------------------------------+
   | eips                   | Array of :ref:`dlbs_ei` objects  | Specifies the EIP bound to the load   |
   |                        |                                  | balancer.                             |
   +------------------------+----------------------------------+---------------------------------------+
   | ipv6_vip_address       | String                           | Specifies the IPv6 address bound to   |
   |                        |                                  | the load balancer.                    |
   |                        |                                  |                                       |
   |                        |                                  | This parameter is unsupported. Please |
   |                        |                                  | do not use it.                        |
   |                        |                                  |                                       |
   |                        |                                  | Default: **None**                     |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **64**                       |
   +------------------------+----------------------------------+---------------------------------------+
   | ipv6_vip_virsubnet_id  | String                           | Specifies the ID of the IPv6 subnet   |
   |                        |                                  | where the load balancer works.        |
   |                        |                                  |                                       |
   |                        |                                  | This parameter is unsupported. Please |
   |                        |                                  | do not use it.                        |
   +------------------------+----------------------------------+---------------------------------------+
   | ipv6_vip_port_id       | String                           | Specifies the ID of the port bound to |
   |                        |                                  | the IPv6 address.                     |
   |                        |                                  |                                       |
   |                        |                                  | This parameter is unsupported. Please |
   |                        |                                  | do not use it.                        |
   +------------------------+----------------------------------+---------------------------------------+
   | availability_zone_list | Array of strings                 | Specifies the list of AZs where the   |
   |                        |                                  | load balancer is created.             |
   +------------------------+----------------------------------+---------------------------------------+
   | enterprise_project_id  | String                           | Specifies the enterprise project ID.  |
   |                        |                                  |                                       |
   |                        |                                  | If this parameter is not passed       |
   |                        |                                  | during resource creation, the         |
   |                        |                                  | resource belongs to the default       |
   |                        |                                  | enterprise project.                   |
   |                        |                                  |                                       |
   |                        |                                  | This parameter is unsupported. Please |
   |                        |                                  | do not use it.                        |
   |                        |                                  |                                       |
   |                        |                                  | Default: **0**                        |
   +------------------------+----------------------------------+---------------------------------------+
   | l4_flavor_id           | String                           | Specifies the Layer-4 flavor.         |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **255**                      |
   +------------------------+----------------------------------+---------------------------------------+
   | l4_scale_flavor_id     | String                           | Specifies the reserved Layer 4        |
   |                        |                                  | flavor.                               |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **255**                      |
   +------------------------+----------------------------------+---------------------------------------+
   | l7_flavor_id           | String                           | Specifies the Layer-7 flavor.         |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **255**                      |
   +------------------------+----------------------------------+---------------------------------------+
   | l7_scale_flavor_id     | String                           | Specifies the reserved Layer 7        |
   |                        |                                  | flavor.                               |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **255**                      |
   +------------------------+----------------------------------+---------------------------------------+
   | publicips              | Array of :ref:`dlbs_pi` objects  | Specifies the EIP bound to the load   |
   |                        |                                  | balancer.                             |
   +------------------------+----------------------------------+---------------------------------------+
   | elb_virsubnet_ids      | Array of strings                 | Specifies the ID of the subnet on the |
   |                        |                                  | downstream plane. The ports used by   |
   |                        |                                  | the load balancer dynamically occupy  |
   |                        |                                  | IP addresses in the subnet.           |
   +------------------------+----------------------------------+---------------------------------------+
   | ip_target_enable       | Boolean                          | Specifies whether to enable cross-VPC |
   |                        |                                  | backend.                              |
   |                        |                                  |                                       |
   |                        |                                  | This parameter is unsupported. Please |
   |                        |                                  | do not use it.                        |
   |                        |                                  |                                       |
   |                        |                                  | Default: **false**                    |
   +------------------------+----------------------------------+---------------------------------------+
   | frozen_scene           | String                           | Specifies the scenario where the load |
   |                        |                                  | balancer is frozen. Use commas to     |
   |                        |                                  | separate multiple scenarios.          |
   |                        |                                  |                                       |
   |                        |                                  | If the value is **ARREAR**, the load  |
   |                        |                                  | balancer is frozen because your       |
   |                        |                                  | account is in arrears.                |
   +------------------------+----------------------------------+---------------------------------------+
   | ipv6_bandwidth         | :ref:`dlbs_br` object            | Specifies the ID of the bandwidth.    |
   |                        |                                  | This parameter is available only when |
   |                        |                                  | you create or update a dedicated load |
   |                        |                                  | balancer that has an IPv6 address     |
   |                        |                                  | bound.                                |
   |                        |                                  |                                       |
   |                        |                                  | If you use a new IPv6 address and     |
   |                        |                                  | specify a shared bandwidth, the IPv6  |
   |                        |                                  | address will be added to the shared   |
   |                        |                                  | bandwidth.                            |
   |                        |                                  |                                       |
   |                        |                                  | This parameter is unsupported. Please |
   |                        |                                  | do not use it.                        |
   +------------------------+----------------------------------+---------------------------------------+

.. _dlbs_pr:
.. table:: **Table 5** PoolRef

   ========= ====== =============================================
   Parameter Type   Description
   ========= ====== =============================================
   id        String Specifies the ID of the backend server group.
   ========= ====== =============================================

.. _dlbs_lr:
.. table:: **Table 6** ListenerRef

   ========= ====== ==========================
   Parameter Type   Description
   ========= ====== ==========================
   id        String Specifies the listener ID.
   ========= ====== ==========================

.. _dlbs_tag:
.. table:: **Table 7** Tag

   ========= ====== ========================
   Parameter Type   Description
   ========= ====== ========================
   key       String Specifies the tag key.
   value     String Specifies the tag value.
   ========= ====== ========================

.. _dlbs_ei:
.. table:: **Table 8** EipInfo

   +-------------+---------+---------------------------------------+
   | Parameter   | Type    | Description                           |
   +=============+=========+=======================================+
   | eip_id      | String  | Specifies the EIP ID.                 |
   +-------------+---------+---------------------------------------+
   | eip_address | String  | Specifies the specific IP address.    |
   +-------------+---------+---------------------------------------+
   | ip_version  | Integer | Specifies the IP version. **4**       |
   |             |         | indicates IPv4, and **6** indicates   |
   |             |         | IPv6.                                 |
   |             |         |                                       |
   |             |         | IPv6 is unsupported. The value cannot |
   |             |         | be **6**.                             |
   +-------------+---------+---------------------------------------+

.. _dlbs_pi:
.. table:: **Table 9** PublicIpInfo

   +------------------+---------+---------------------------------------+
   | Parameter        | Type    | Description                           |
   +==================+=========+=======================================+
   | publicip_id      | String  | Specifies the EIP ID.                 |
   +------------------+---------+---------------------------------------+
   | publicip_address | String  | Specifies the IP address.             |
   +------------------+---------+---------------------------------------+
   | ip_version       | Integer | Specifies the IP version. The value   |
   |                  |         | can be **4** (IPv4) or **6** (IPv6).  |
   |                  |         |                                       |
   |                  |         | IPv6 is unsupported. The value cannot |
   |                  |         | be **6**.                             |
   +------------------+---------+---------------------------------------+

.. _dlbs_br:
.. table:: **Table 10** BandwidthRef

   ========= ====== ==================================
   Parameter Type   Description
   ========= ====== ==================================
   id        String Specifies the shared bandwidth ID.
   ========= ====== ==================================

Example Requests
^^^^^^^^^^^^^^^^

Viewing details of a load balancer

.. code::

   GET /v3/{project_id}/elb/loadbalancers/{loadbalancer_id}

   GET

   https://{ELB_Endpoint}/v3/060576782980d5762f9ec014dd2f1148/elb/loadbalancers/3dbde7e5-c277-4ea3-a424-edd339357eff

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 200**

Successful request.

.. code::

   {
     "loadbalancer" : {
       "id" : "3dbde7e5-c277-4ea3-a424-edd339357eff",
       "project_id" : "060576782980d5762f9ec014dd2f1148",
       "name" : "elb-l4-no-delete",
       "vip_port_id" : "f079c7ee-65a9-44ef-be86-53d8927e59be",
       "vip_address" : "10.0.0.196",
       "admin_state_up" : true,
       "provisioning_status" : "ACTIVE",
       "operating_status" : "ONLINE",
       "listeners" : [ ],
       "pools" : [ {
         "id" : "1d864dc9-f6ef-4366-b59d-7034cde2328f"
       }, {
         "id" : "c0a2e4a1-c028-4a24-a62f-e721c52f5513"
       }, {
         "id" : "79308896-6169-4c28-acbc-e139eb661996"
       } ],
       "tags" : [ ],
       "created_at" : "2019-12-02T09:55:11Z",
       "updated_at" : "2019-12-02T09:55:11Z",
       "vpc_id" : "70711260-9de9-4d96-9839-0ae698e00109",
       "enterprise_project_id" : "0",
       "availability_zone_list" : [ ],
       "publicips" : [ ],
       "elb_virsubnet_ids" : [ "ad5d63bf-3b50-4e88-b4d9-e94a59aade48" ],
       "eips" : [ ],
       "guaranteed" : true,

       "l4_flavor_id" : "e5acacda-f861-404e-9871-df480c49d185",
       "vip_subnet_cidr_id" : "396d918a-756e-4163-8450-3bdc860109cf"
     },
     "request_id" : "1a47cfbf-969f-4e40-8c0e-c2e60b14bcac"
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

Updating a Load Balancer
========================

Function
^^^^^^^^

This API is used to update a load balancer.

URI
^^^

PUT /v3/{project_id}/elb/loadbalancers/{loadbalancer_id}

.. table:: **Table 1** Path parameters

   =============== ========= ====== ===============================
   Parameter       Mandatory Type   Description
   =============== ========= ====== ===============================
   loadbalancer_id Yes       String Specifies the load balancer ID.
   project_id      Yes       String Specifies the project ID.
   =============== ========= ====== ===============================

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 2** Request header parameters

   ============ ========= ====== ================================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ================================================
   X-Auth-Token Yes       String Specifies the token used for IAM authentication.
   ============ ========= ====== ================================================

.. table:: **Table 3** Request body parameters

   +--------------+-----------+-------------------------------------------+------------------------------+
   | Parameter    | Mandatory | Type                                      | Description                  |
   +==============+===========+===========================================+==============================+
   | loadbalancer | Yes       | :ref:`dlbu_o` object                      | Specifies the load balancer. |
   +--------------+-----------+-------------------------------------------+------------------------------+

.. _dlbu_o:
.. table:: **Table 4** UpdateLoadBalancerOption

   +-----------------------+-----------+-----------------------+-----------------------------+
   | Parameter             | Mandatory | Type                  | Description                 |
   +=======================+===========+=======================+=============================+
   | name                  | No        | String                | Specifies the load balancer |
   |                       |           |                       | name.                       |
   |                       |           |                       |                             |
   |                       |           |                       | Minimum: **0**              |
   |                       |           |                       |                             |
   |                       |           |                       | Maximum: **255**            |
   +-----------------------+-----------+-----------------------+-----------------------------+
   | admin_state_up        | No        | Boolean               | Specifies the               |
   |                       |           |                       | administrative status of    |
   |                       |           |                       | the load balancer. And the  |
   |                       |           |                       | value can only be **true**. |
   |                       |           |                       |                             |
   |                       |           |                       | This parameter is           |
   |                       |           |                       | unsupported. Please do not  |
   |                       |           |                       | use it.                     |
   |                       |           |                       |                             |
   |                       |           |                       | Default: **true**           |
   +-----------------------+-----------+-----------------------+-----------------------------+
   | description           | No        | String                | Provides supplementary      |
   |                       |           |                       | information about the load  |
   |                       |           |                       | balancer.                   |
   |                       |           |                       |                             |
   |                       |           |                       | Minimum: **0**              |
   |                       |           |                       |                             |
   |                       |           |                       | Maximum: **255**            |
   +-----------------------+-----------+-----------------------+-----------------------------+
   | ipv6_vip_virsubnet_id | No        | String                | Specifies the ID of the     |
   |                       |           |                       | IPv6 subnet where the load  |
   |                       |           |                       | balancer works. You can     |
   |                       |           |                       | query **id** in the         |
   |                       |           |                       | response by calling the API |
   |                       |           |                       | (GET                        |
   |                       |           |                       | https://{VPC_Endpoint       |
   |                       |           |                       | }/v1/{project_id}/subnets). |
   |                       |           |                       |                             |
   |                       |           |                       | The IPv6 subnet can be      |
   |                       |           |                       | updated using               |
   |                       |           |                       | **ipv6_vip_virsubnet_id**,  |
   |                       |           |                       | and the private IPv6        |
   |                       |           |                       | address of the load         |
   |                       |           |                       | balancer will be changed    |
   |                       |           |                       | accordingly.                |
   |                       |           |                       |                             |
   |                       |           |                       | The IPv6 subnet must be in  |
   |                       |           |                       | the VPC specified by        |
   |                       |           |                       | **vpc_id**.                 |
   |                       |           |                       |                             |
   |                       |           |                       | Note:                       |
   |                       |           |                       |                             |
   |                       |           |                       | - **ipv6_vip_virsubnet_id** |
   |                       |           |                       |   can be updated only when  |
   |                       |           |                       |   **guaranteed** is set to  |
   |                       |           |                       |   **true**.                 |
   |                       |           |                       | - Enter **null** if the     |
   |                       |           |                       |   IPv6 address is unbound   |
   |                       |           |                       |   from the load balancer.   |
   |                       |           |                       |                             |
   |                       |           |                       | This parameter is           |
   |                       |           |                       | unsupported. Please do not  |
   |                       |           |                       | use it.                     |
   +-----------------------+-----------+-----------------------+-----------------------------+
   | vip_subnet_cidr_id    | No        | String                | Specifies the ID of the     |
   |                       |           |                       | IPv4 subnet where the load  |
   |                       |           |                       | balancer works. You can     |
   |                       |           |                       | query **neutron_subnet_id** |
   |                       |           |                       | in the response by calling  |
   |                       |           |                       | the API (GET                |
   |                       |           |                       | https://{VPC_Endpoint       |
   |                       |           |                       | }/v1/{project_id}/subnets). |
   |                       |           |                       |                             |
   |                       |           |                       | -  The IPv4 subnet can be   |
   |                       |           |                       |    updated using            |
   |                       |           |                       |    **vip_subnet_cidr_id**,  |
   |                       |           |                       |    and the private IPv4     |
   |                       |           |                       |    address of the load      |
   |                       |           |                       |    balancer will be changed |
   |                       |           |                       |    accordingly.             |
   |                       |           |                       | -  If **vip_address** is    |
   |                       |           |                       |    also specified, the IP   |
   |                       |           |                       |    address specified by it  |
   |                       |           |                       |    must be in the subnet    |
   |                       |           |                       |    specified by             |
   |                       |           |                       |    **vip_subnet_cidr_id**   |
   |                       |           |                       |    and will be used as the  |
   |                       |           |                       |    private IPv4 address of  |
   |                       |           |                       |    the load balancer.       |
   |                       |           |                       | -  The IPv4 subnet must be  |
   |                       |           |                       |    in the VPC specified by  |
   |                       |           |                       |    **vpc_id**.              |
   |                       |           |                       |                             |
   |                       |           |                       | Note:                       |
   |                       |           |                       |                             |
   |                       |           |                       | -  **vip_subnet_cidr_id**   |
   |                       |           |                       |    can be updated only when |
   |                       |           |                       |    **guaranteed** is set to |
   |                       |           |                       |    **true**.                |
   |                       |           |                       | -  Enter **null** if the    |
   |                       |           |                       |    private IPv4 address is  |
   |                       |           |                       |    unbound from the load    |
   |                       |           |                       |    balancer.                |
   |                       |           |                       |                             |
   |                       |           |                       | Minimum: **1**              |
   |                       |           |                       |                             |
   |                       |           |                       | Maximum: **36**             |
   +-----------------------+-----------+-----------------------+-----------------------------+
   | vip_address           | No        | String                | Specifies the virtual IP    |
   |                       |           |                       | address bound to the load   |
   |                       |           |                       | balancer. The IP address    |
   |                       |           |                       | must be from the IPv4       |
   |                       |           |                       | subnet of the VPC where the |
   |                       |           |                       | load balancer works and IP  |
   |                       |           |                       | address should not be       |
   |                       |           |                       | occupied by other services. |
   |                       |           |                       |                             |
   |                       |           |                       | The IP address specified by |
   |                       |           |                       | this parameter must be in   |
   |                       |           |                       | the subnet specified by     |
   |                       |           |                       | **vip_subnet_cidr_id** and  |
   |                       |           |                       | will be used as the private |
   |                       |           |                       | IPv4 address of the load    |
   |                       |           |                       | balancer.                   |
   |                       |           |                       |                             |
   |                       |           |                       | **vip_address** can be      |
   |                       |           |                       | updated only when           |
   |                       |           |                       | **guaranteed** is set to    |
   |                       |           |                       | **true**.                   |
   |                       |           |                       |                             |
   |                       |           |                       | Minimum: **1**              |
   |                       |           |                       |                             |
   |                       |           |                       | Maximum: **36**             |
   +-----------------------+-----------+-----------------------+-----------------------------+
   | l4_flavor_id          | No        | String                | Specifies the ID of the     |
   |                       |           |                       | Layer-4 flavor.             |
   |                       |           |                       |                             |
   |                       |           |                       | Note:                       |
   |                       |           |                       |                             |
   |                       |           |                       | -  This parameter can be    |
   |                       |           |                       |    updated only when        |
   |                       |           |                       |    **guaranteed** is set to |
   |                       |           |                       |    **true**.                |
   |                       |           |                       | -  The value cannot be      |
   |                       |           |                       |    changed from **null** to |
   |                       |           |                       |    a specific value, or the |
   |                       |           |                       |    other way around. If you |
   |                       |           |                       |    need to change the       |
   |                       |           |                       |    flavor, you must select  |
   |                       |           |                       |    a larger one.            |
   |                       |           |                       |                             |
   |                       |           |                       | Minimum: **1**              |
   |                       |           |                       |                             |
   |                       |           |                       | Maximum: **255**            |
   +-----------------------+-----------+-----------------------+-----------------------------+
   | l7_flavor_id          | No        | String                | Specifies the ID of the     |
   |                       |           |                       | Layer-7 flavor.             |
   |                       |           |                       |                             |
   |                       |           |                       | Note:                       |
   |                       |           |                       |                             |
   |                       |           |                       | -  This parameter can be    |
   |                       |           |                       |    updated only when        |
   |                       |           |                       |    **guaranteed** is set to |
   |                       |           |                       |    **true**.                |
   |                       |           |                       | -  The value cannot be      |
   |                       |           |                       |    changed from **null** to |
   |                       |           |                       |    a specific value, or the |
   |                       |           |                       |    other way around. If you |
   |                       |           |                       |    need to change the       |
   |                       |           |                       |    flavor, you must select  |
   |                       |           |                       |    a larger one.            |
   +-----------------------+-----------+-----------------------+-----------------------------+
   | ipv6_bandwidth        | No        | :ref:`dlbu_br` object | Specifies the ID of the     |
   |                       |           |                       | bandwidth. This parameter   |
   |                       |           |                       | is available only when you  |
   |                       |           |                       | create or update a          |
   |                       |           |                       | dedicated load balancer     |
   |                       |           |                       | that has an IPv6 address    |
   |                       |           |                       | bound.                      |
   |                       |           |                       |                             |
   |                       |           |                       | If you use a new IPv6       |
   |                       |           |                       | address and specify a       |
   |                       |           |                       | shared bandwidth, the IPv6  |
   |                       |           |                       | address will be added to    |
   |                       |           |                       | the shared bandwidth.       |
   |                       |           |                       |                             |
   |                       |           |                       | This parameter is           |
   |                       |           |                       | unsupported. Please do not  |
   |                       |           |                       | use it.                     |
   +-----------------------+-----------+-----------------------+-----------------------------+
   | ip_target_enable      | No        | Boolean               | Specifies whether to enable |
   |                       |           |                       | cross-VPC backend. The      |
   |                       |           |                       | value can only be **true**. |
   |                       |           |                       |                             |
   |                       |           |                       | This parameter is           |
   |                       |           |                       | unsupported. Please do not  |
   |                       |           |                       | use it.                     |
   +-----------------------+-----------+-----------------------+-----------------------------+

.. _dlbu_br:
.. table:: **Table 5** BandwidthRef

   ========= ========= ====== ==================================
   Parameter Mandatory Type   Description
   ========= ========= ====== ==================================
   id        Yes       String Specifies the shared bandwidth ID.
   ========= ========= ====== ==================================

Response Parameters
^^^^^^^^^^^^^^^^^^^

**Status code: 200**

.. table:: **Table 6** Response body parameters

   +--------------+--------------------------------------------------+----------------------------------------+
   | Parameter    | Type                                             | Description                            |
   +==============+==================================================+========================================+
   | request_id   | String                                           | Specifies the request ID. The value is |
   |              |                                                  | automatically generated.               |
   +--------------+--------------------------------------------------+----------------------------------------+
   | loadbalancer | :ref:`dlbu_lb` object                            | Specifies the load balancer.           |
   +--------------+--------------------------------------------------+----------------------------------------+

.. _dlbu_lb:
.. table:: **Table 7** LoadBalancer

   +------------------------+----------------------------------+---------------------------------------+
   | Parameter              | Type                             | Description                           |
   +========================+==================================+=======================================+
   | id                     | String                           | Specifies the load balancer ID.       |
   |                        |                                  |                                       |
   |                        |                                  | Default: **Automatically generated**  |
   +------------------------+----------------------------------+---------------------------------------+
   | description            | String                           | Provides supplementary information    |
   |                        |                                  | about the load balancer.              |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **255**                      |
   +------------------------+----------------------------------+---------------------------------------+
   | provisioning_status    | String                           | Specifies the provisioning status of  |
   |                        |                                  | the load balancer. The value can only |
   |                        |                                  | be **ACTIVE**.                        |
   +------------------------+----------------------------------+---------------------------------------+
   | admin_state_up         | Boolean                          | Specifies the administrative status   |
   |                        |                                  | of the load balancer. The value can   |
   |                        |                                  | only be **true**.                     |
   |                        |                                  |                                       |
   |                        |                                  | This parameter is unsupported. Please |
   |                        |                                  | do not use it.                        |
   |                        |                                  |                                       |
   |                        |                                  | Default: **true**                     |
   +------------------------+----------------------------------+---------------------------------------+
   | provider               | String                           | Specifies the provider of the load    |
   |                        |                                  | balancer. The value can only be       |
   |                        |                                  | **vlb**.                              |
   |                        |                                  |                                       |
   |                        |                                  | Default: **vlb**                      |
   +------------------------+----------------------------------+---------------------------------------+
   | pools                  | Array of :ref:`dlbu_pr` objects  | Lists the IDs of backend server       |
   |                        |                                  | groups associated with the load       |
   |                        |                                  | balancer.                             |
   +------------------------+----------------------------------+---------------------------------------+
   | listeners              | Array of :ref:`dlbu_lr` objects  | Lists the IDs of listeners added to   |
   |                        |                                  | the load balancer.                    |
   +------------------------+----------------------------------+---------------------------------------+
   | operating_status       | String                           | Specifies the operating status of the |
   |                        |                                  | load balancer. The value can only be  |
   |                        |                                  | **ONLINE**.                           |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **16**                       |
   +------------------------+----------------------------------+---------------------------------------+
   | vip_address            | String                           | Specifies the private IPv4 address    |
   |                        |                                  | bound to the load balancer.           |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **64**                       |
   +------------------------+----------------------------------+---------------------------------------+
   | vip_subnet_cidr_id     | String                           | Specifies the ID of the IPv4 subnet   |
   |                        |                                  | where the load balancer works.        |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **36**                       |
   +------------------------+----------------------------------+---------------------------------------+
   | name                   | String                           | Specifies the name of the load        |
   |                        |                                  | balancer.                             |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **255**                      |
   +------------------------+----------------------------------+---------------------------------------+
   | project_id             | String                           | Specifies the project ID of the load  |
   |                        |                                  | balancer.                             |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  |                                       |
   |                        |                                  | Maximum: **32**                       |
   +------------------------+----------------------------------+---------------------------------------+
   | vip_port_id            | String                           | Specifies the ID of the port bound to |
   |                        |                                  | the virtual IP address (the value of  |
   |                        |                                  | **vip_address**) of the load          |
   |                        |                                  | balancer.                             |
   |                        |                                  |                                       |
   |                        |                                  | When you create a dedicated load      |
   |                        |                                  | balancer, the system automatically    |
   |                        |                                  | creates a port for the load balancer  |
   |                        |                                  | and associates the port with a        |
   |                        |                                  | default security group. However,      |
   |                        |                                  | security group rules containing the   |
   |                        |                                  | port will not affect traffic to and   |
   |                        |                                  | from the load balancer.               |
   +------------------------+----------------------------------+---------------------------------------+
   | tags                   | Array of :ref:`dlbu_tag` objects | Lists the tags added to the load      |
   |                        |                                  | balancer.                             |
   +------------------------+----------------------------------+---------------------------------------+
   | created_at             | String                           | Specifies the time when the load      |
   |                        |                                  | balancer was created.                 |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  | Maximum: **20**                       |
   +------------------------+----------------------------------+---------------------------------------+
   | updated_at             | String                           | Specifies the time when the load      |
   |                        |                                  | balancer was updated.                 |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  | Maximum: **20**                       |
   +------------------------+----------------------------------+---------------------------------------+
   | guaranteed             | Boolean                          | Specifies whether the load balancer   |
   |                        |                                  | is a dedicated load balancer.         |
   |                        |                                  |                                       |
   |                        |                                  | The value can be **true** or          |
   |                        |                                  | **false**. **true** indicates a       |
   |                        |                                  | dedicated load balancer, and          |
   |                        |                                  | **false** indicates a shared load     |
   |                        |                                  | balancer. When dedicated load         |
   |                        |                                  | balancers are launched in the         |
   |                        |                                  | **eu-de** region, either **true** or  |
   |                        |                                  | **false** will be returned when you   |
   |                        |                                  | use the API to query or update a load |
   |                        |                                  | balancer.                             |
   |                        |                                  |                                       |
   |                        |                                  | Default: **true**                     |
   +------------------------+----------------------------------+---------------------------------------+
   | vpc_id                 | String                           | Specifies the ID of the VPC where the |
   |                        |                                  | load balancer works.                  |
   +------------------------+----------------------------------+---------------------------------------+
   | eips                   | Array of :ref:`dlbu_ei` objects  | Specifies the EIP bound to the load   |
   |                        |                                  | balancer.                             |
   +------------------------+----------------------------------+---------------------------------------+
   | ipv6_vip_address       | String                           | Specifies the IPv6 address bound to   |
   |                        |                                  | the load balancer.                    |
   |                        |                                  |                                       |
   |                        |                                  | This parameter is unsupported. Please |
   |                        |                                  | do not use it.                        |
   |                        |                                  |                                       |
   |                        |                                  | Default: **None**                     |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  | Maximum: **64**                       |
   +------------------------+----------------------------------+---------------------------------------+
   | ipv6_vip_virsubnet_id  | String                           | Specifies the ID of the IPv6 subnet   |
   |                        |                                  | where the load balancer works.        |
   |                        |                                  |                                       |
   |                        |                                  | This parameter is unsupported. Please |
   |                        |                                  | do not use it.                        |
   +------------------------+----------------------------------+---------------------------------------+
   | ipv6_vip_port_id       | String                           | Specifies the ID of the port bound to |
   |                        |                                  | the IPv6 address.                     |
   |                        |                                  |                                       |
   |                        |                                  | This parameter is unsupported. Please |
   |                        |                                  | do not use it.                        |
   +------------------------+----------------------------------+---------------------------------------+
   | availability_zone_list | Array of strings                 | Specifies the list of AZs where the   |
   |                        |                                  | load balancer is created.             |
   +------------------------+----------------------------------+---------------------------------------+
   | enterprise_project_id  | String                           | Specifies the enterprise project ID.  |
   |                        |                                  |                                       |
   |                        |                                  | If this parameter is not passed       |
   |                        |                                  | during resource creation, the         |
   |                        |                                  | resource belongs to the default       |
   |                        |                                  | enterprise project.                   |
   |                        |                                  |                                       |
   |                        |                                  | This parameter is unsupported. Please |
   |                        |                                  | do not use it.                        |
   |                        |                                  |                                       |
   |                        |                                  | Default: **0**                        |
   +------------------------+----------------------------------+---------------------------------------+
   | l4_flavor_id           | String                           | Specifies the Layer-4 flavor.         |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  | Maximum: **255**                      |
   +------------------------+----------------------------------+---------------------------------------+
   | l4_scale_flavor_id     | String                           | Specifies the reserved Layer 4        |
   |                        |                                  | flavor.                               |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  | Maximum: **255**                      |
   +------------------------+----------------------------------+---------------------------------------+
   | l7_flavor_id           | String                           | Specifies the Layer-7 flavor.         |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  | Maximum: **255**                      |
   +------------------------+----------------------------------+---------------------------------------+
   | l7_scale_flavor_id     | String                           | Specifies the reserved Layer 7        |
   |                        |                                  | flavor.                               |
   |                        |                                  |                                       |
   |                        |                                  | Minimum: **1**                        |
   |                        |                                  | Maximum: **255**                      |
   +------------------------+----------------------------------+---------------------------------------+
   | publicips              | Array of :ref:`dlbu_pi` objects  | Specifies the EIP bound to the load   |
   |                        |                                  | balancer.                             |
   +------------------------+----------------------------------+---------------------------------------+
   | elb_virsubnet_ids      | Array of strings                 | Specifies the ID of the subnet on the |
   |                        |                                  | downstream plane. The ports used by   |
   |                        |                                  | the load balancer dynamically occupy  |
   |                        |                                  | IP addresses in the subnet.           |
   +------------------------+----------------------------------+---------------------------------------+
   | ip_target_enable       | Boolean                          | Specifies whether to enable cross-VPC |
   |                        |                                  | backend.                              |
   |                        |                                  |                                       |
   |                        |                                  | This parameter is unsupported. Please |
   |                        |                                  | do not use it.                        |
   |                        |                                  |                                       |
   |                        |                                  | Default: **false**                    |
   +------------------------+----------------------------------+---------------------------------------+
   | frozen_scene           | String                           | Specifies the scenario where the load |
   |                        |                                  | balancer is frozen. Use commas to     |
   |                        |                                  | separate multiple scenarios.          |
   |                        |                                  |                                       |
   |                        |                                  | If the value is **ARREAR**, the load  |
   |                        |                                  | balancer is frozen because your       |
   |                        |                                  | account is in arrears.                |
   +------------------------+----------------------------------+---------------------------------------+
   | ipv6_bandwidth         | :ref:`dlbu_br1` object           | Specifies the ID of the bandwidth.    |
   |                        |                                  | This parameter is available only when |
   |                        |                                  | you create or update a dedicated load |
   |                        |                                  | balancer that has an IPv6 address     |
   |                        |                                  | bound.                                |
   |                        |                                  |                                       |
   |                        |                                  | If you use a new IPv6 address and     |
   |                        |                                  | specify a shared bandwidth, the IPv6  |
   |                        |                                  | address will be added to the shared   |
   |                        |                                  | bandwidth.                            |
   |                        |                                  |                                       |
   |                        |                                  | This parameter is unsupported. Please |
   |                        |                                  | do not use it.                        |
   +------------------------+----------------------------------+---------------------------------------+

.. _dlbu_pr:
.. table:: **Table 8** PoolRef

   ========= ====== =============================================
   Parameter Type   Description
   ========= ====== =============================================
   id        String Specifies the ID of the backend server group.
   ========= ====== =============================================

.. _dlbu_lr:
.. table:: **Table 9** ListenerRef

   ========= ====== ==========================
   Parameter Type   Description
   ========= ====== ==========================
   id        String Specifies the listener ID.
   ========= ====== ==========================

.. _dlbu_tag:
.. table:: **Table 10** Tag

   ========= ====== ========================
   Parameter Type   Description
   ========= ====== ========================
   key       String Specifies the tag key.
   value     String Specifies the tag value.
   ========= ====== ========================

.. _dlbu_ei:
.. table:: **Table 11** EipInfo

   +-------------+---------+---------------------------------------+
   | Parameter   | Type    | Description                           |
   +=============+=========+=======================================+
   | eip_id      | String  | Specifies the EIP ID.                 |
   +-------------+---------+---------------------------------------+
   | eip_address | String  | Specifies the specific IP address.    |
   +-------------+---------+---------------------------------------+
   | ip_version  | Integer | Specifies the IP version. **4**       |
   |             |         | indicates IPv4, and **6** indicates   |
   |             |         | IPv6.                                 |
   |             |         |                                       |
   |             |         | IPv6 is unsupported. The value cannot |
   |             |         | be **6**.                             |
   +-------------+---------+---------------------------------------+

.. _dlbu_pi:
.. table:: **Table 12** PublicIpInfo

   +------------------+---------+---------------------------------------+
   | Parameter        | Type    | Description                           |
   +==================+=========+=======================================+
   | publicip_id      | String  | Specifies the EIP ID.                 |
   +------------------+---------+---------------------------------------+
   | publicip_address | String  | Specifies the IP address.             |
   +------------------+---------+---------------------------------------+
   | ip_version       | Integer | Specifies the IP version. The value   |
   |                  |         | can be **4** (IPv4) or **6** (IPv6).  |
   |                  |         |                                       |
   |                  |         | IPv6 is unsupported. The value cannot |
   |                  |         | be **6**.                             |
   +------------------+---------+---------------------------------------+

.. _dlbu_br1:
.. table:: **Table 13** BandwidthRef

   ========= ====== ==================================
   Parameter Type   Description
   ========= ====== ==================================
   id        String Specifies the shared bandwidth ID.
   ========= ====== ==================================

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   PUT

   https://{elb_endpoint}/v3/{project_id}/elb/loadbalancers/{loadbalancer_id}

   {
     "loadbalancer" : {
       "admin_state_up" : true,
       "description" : "loadbalancer",
       "name" : "loadbalancer-update"
     }
   }

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 200**

Successful request.

.. code::

   {
     "request_id" : "010dad1e-32a3-4405-ab83-62a1fc5f8722",
     "loadbalancer" : {
       "id" : "2e073bf8-edfe-4e51-a699-d915b0b8af89",
       "project_id" : "b2782e6708b8475c993e6064bc456bf8",
       "name" : "loadbalancer-update",
       "description" : "loadbalancer",
       "admin_state_up" : true,
       "provisioning_status" : "ACTIVE",
       "operating_status" : "ONLINE",
       "listeners" : [ {
         "id" : "41937176-bf64-4b58-8e0d-9ff2d0d32c54"
       }, {
         "id" : "abc6ac93-ad0e-4765-bd5a-eec632efde56"
       }, {
         "id" : "b9d8ba97-6d60-467d-838d-f3550b54c22a"
       }, {
         "id" : "fd797ebd-263d-4b18-96e9-e9188d36c69e"
       } ],
       "pools" : [ {
         "id" : "0aabcaa8-c35c-4ddc-a60c-9032d0ac0b80"
       }, {
         "id" : "165d9092-396e-4a8d-b398-067496a447d2"
       } ],
       "tags" : [ ],
       "provider" : "vlb",
       "created_at" : "2019-04-20T03:10:37Z",
       "updated_at" : "2019-05-24T02:11:58Z",
       "vpc_id" : "2037c5bb-e04b-4de2-9300-9051af18e417",
       "enterprise_project_id" : "0",
       "availability_zone_list" : [ "AZ1", "AZ2", "dc3" ],
       "eips" : [ ],
       "guaranteed" : true
     }
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

Deleting a Load Balancer
========================

Function
^^^^^^^^

This API is used to delete a load balancer.

Constraints
^^^^^^^^^^^

All listeners added to the load balancer must be deleted before the load balancer is deleted.

URI
^^^

DELETE /v3/{project_id}/elb/loadbalancers/{loadbalancer_id}

.. table:: **Table 1** Path parameters

   =============== ========= ====== ===============================
   Parameter       Mandatory Type   Description
   =============== ========= ====== ===============================
   project_id      Yes       String Specifies the project ID.
   loadbalancer_id Yes       String Specifies the load balancer ID.
   =============== ========= ====== ===============================

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

   https://{elb_endpoint}/v3/{project_id}/elb/loadbalancers/{loadbalancer_id}

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

Querying the Status Tree of a Load Balancer
===========================================

Function
^^^^^^^^

This API is used to query the status tree of a load balancer and show
information about all resources associated with the load balancer.

When **admin_state_up** is set to **false** and **operating_status** to
**OFFLINE** for a backend server, **DISABLED** is returned for
**operating_status** of the backend server in the response of this API.

URI
^^^

GET /v3/{project_id}/elb/loadbalancers/{loadbalancer_id}/statuses

.. table:: **Table 1** Path parameters

   =============== ========= ====== ===============================
   Parameter       Mandatory Type   Description
   =============== ========= ====== ===============================
   project_id      Yes       String Specifies the project ID.
   loadbalancer_id Yes       String Specifies the load balancer ID.
   =============== ========= ====== ===============================

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

   +------------+------------------------+----------------------------------------------+
   | Parameter  | Type                   | Description                                  |
   +============+========================+==============================================+
   | statuses   | :ref:`dlbst_lb` object | Provides information about the load balancer |
   |            |                        | status tree.                                 |
   +------------+------------------------+----------------------------------------------+
   | request_id | String                 | Specifies the request ID. The value is       |
   |            |                        | automatically generated.                     |
   +------------+------------------------+----------------------------------------------+

.. _dlbst_lb:
.. table:: **Table 4** LoadBalancerStatusResult

   +--------------+------------------------+-------------------------------------------------+
   | Parameter    | Type                   | Description                                     |
   +==============+========================+=================================================+
   | loadbalancer | :ref:`dlbst_t5` object | Specifies the statuses of the load balancer and |
   |              |                        | its associated resources.                       |
   +--------------+------------------------+-------------------------------------------------+

.. _dlbst_t5:
.. table:: **Table 5** LoadBalancerStatus

   +---------------------+------------------------------------+---------------------------------------+
   | Parameter           | Type                               | Description                           |
   +=====================+====================================+=======================================+
   | name                | String                             | Specifies the load balancer name.     |
   |                     |                                    |                                       |
   |                     |                                    | Minimum: **1**                        |
   |                     |                                    |                                       |
   |                     |                                    | Maximum: **255**                      |
   +---------------------+------------------------------------+---------------------------------------+
   | provisioning_status | String                             | Specifies the provisioning status of  |
   |                     |                                    | the load balancer.                    |
   |                     |                                    |                                       |
   |                     |                                    | The value can only be **ACTIVE**.     |
   +---------------------+------------------------------------+---------------------------------------+
   | listeners           | Array of :ref:`dlbst_li` objects   | Lists the listeners added to the load |
   |                     |                                    | balancer.                             |
   +---------------------+------------------------------------+---------------------------------------+
   | pools               | Array of :ref:`dlbst_pool` objects | Lists the backend server groups       |
   |                     |                                    | associated with the load balancer.    |
   +---------------------+------------------------------------+---------------------------------------+
   | id                  | String                             | Specifies the load balancer ID.       |
   +---------------------+------------------------------------+---------------------------------------+
   | operating_status    | String                             | Specifies the operating status of the |
   |                     |                                    | load balancer.                        |
   |                     |                                    |                                       |
   |                     |                                    | The value can only be one of the      |
   |                     |                                    | following:                            |
   |                     |                                    |                                       |
   |                     |                                    | -  **ONLINE** (default): The load     |
   |                     |                                    |    balancer is running normally.      |
   |                     |                                    |                                       |
   |                     |                                    | -  **DEGRADED**: This status is       |
   |                     |                                    |    displayed only when                |
   |                     |                                    |    **operating_status** is set to     |
   |                     |                                    |    **OFFLINE** for a backend server   |
   |                     |                                    |    associated with the load balancer  |
   |                     |                                    |    and the API for querying the load  |
   |                     |                                    |    balancer status tree is called.    |
   |                     |                                    |                                       |
   |                     |                                    | -  **DISABLED**: This status is       |
   |                     |                                    |    displayed only when                |
   |                     |                                    |    **admin_state_up** of the load     |
   |                     |                                    |    balancer is set to **false** and   |
   |                     |                                    |    the API for querying the load      |
   |                     |                                    |    balancer status tree is called.    |
   +---------------------+------------------------------------+---------------------------------------+

.. _dlbst_li:
.. table:: **Table 6** LoadBalancerStatusListener

   +---------------------+---------------------------------------+---------------------------------------+
   | Parameter           | Type                                  | Description                           |
   +=====================+=======================================+=======================================+
   | name                | String                                | Specifies the name of the listener    |
   |                     |                                       | added to the load balancer.           |
   |                     |                                       |                                       |
   |                     |                                       | Minimum: **1**                        |
   |                     |                                       |                                       |
   |                     |                                       | Maximum: **255**                      |
   +---------------------+---------------------------------------+---------------------------------------+
   | provisioning_status | String                                | Specifies the provisioning status of  |
   |                     |                                       | the listener. The value can only be   |
   |                     |                                       | **ACTIVE**.                           |
   |                     |                                       |                                       |
   |                     |                                       | Default: **ACTIVE**                   |
   +---------------------+---------------------------------------+---------------------------------------+
   | pools               | Array of :ref:`dlbst_pool` objects    | Specifies the operating status of the |
   |                     |                                       | backend server group associated with  |
   |                     |                                       | the listener.                         |
   +---------------------+---------------------------------------+---------------------------------------+
   | l7policies          | Array of :ref:`dlbst_policy` objects  | Specifies the operating status of the |
   |                     |                                       | forwarding policy added to the        |
   |                     |                                       | listener.                             |
   +---------------------+---------------------------------------+---------------------------------------+
   | id                  | String                                | Specifies the listener ID.            |
   +---------------------+---------------------------------------+---------------------------------------+
   | operating_status    | String                                | Specifies the operating status of the |
   |                     |                                       | listener.                             |
   |                     |                                       |                                       |
   |                     |                                       | The value can only be one of the      |
   |                     |                                       | following:                            |
   |                     |                                       |                                       |
   |                     |                                       | -  **ONLINE** (default): The listener |
   |                     |                                       |    is running normally.               |
   |                     |                                       |                                       |
   |                     |                                       | -  **DISABLED**: This status is       |
   |                     |                                       |    displayed only when                |
   |                     |                                       |    **admin_state_up** of the load     |
   |                     |                                       |    balancer or the listener is set to |
   |                     |                                       |    **false** and the API for querying |
   |                     |                                       |    the load balancer status tree is   |
   |                     |                                       |    called.                            |
   +---------------------+---------------------------------------+---------------------------------------+

.. _dlbst_policy:
.. table:: **Table 7** LoadBalancerStatusPolicy

   +---------------------+---------------------------------------+--------------------------------------+
   | Parameter           | Type                                  | Description                          |
   +=====================+=======================================+======================================+
   | action              | String                                | Specifies whether requests are       |
   |                     |                                       | forwarded to another backend server  |
   |                     |                                       | group or redirected to an HTTPS      |
   |                     |                                       | listener. The value can be           |
   |                     |                                       | **REDIRECT_TO_POOL** or              |
   |                     |                                       | **REDIRECT_TO_LISTENER**.            |
   +---------------------+---------------------------------------+--------------------------------------+
   | id                  | String                                | Specifies the policy ID.             |
   +---------------------+---------------------------------------+--------------------------------------+
   | provisioning_status | String                                | Specifies the provisioning status of |
   |                     |                                       | the forwarding policy.               |
   |                     |                                       |                                      |
   |                     |                                       | The value can only be **ACTIVE**.    |
   |                     |                                       |                                      |
   |                     |                                       | Default: **ACTIVE**                  |
   +---------------------+---------------------------------------+--------------------------------------+
   | name                | String                                | Specifies the policy name.           |
   |                     |                                       |                                      |
   |                     |                                       | Minimum: **1**                       |
   |                     |                                       |                                      |
   |                     |                                       | Maximum: **255**                     |
   +---------------------+---------------------------------------+--------------------------------------+
   | rules               | Array of :ref:`dlbst_l7r` objects     | Specifies the forwarding rule.       |
   +---------------------+---------------------------------------+--------------------------------------+

.. _dlbst_l7r:
.. table:: **Table 8** LoadBalancerStatusL7Rule

   +---------------------+--------+---------------------------------------+
   | Parameter           | Type   | Description                           |
   +=====================+========+=======================================+
   | id                  | String | Specifies the ID of the forwarding    |
   |                     |        | rule.                                 |
   +---------------------+--------+---------------------------------------+
   | provisioning_status | String | Specifies the provisioning status of  |
   |                     |        | the forwarding rule.                  |
   |                     |        |                                       |
   |                     |        | The value can only be **ACTIVE**.     |
   +---------------------+--------+---------------------------------------+
   | type                | String | Specifies the match content. The      |
   |                     |        | value can be **HOST_NAME** or         |
   |                     |        | **PATH**.                             |
   |                     |        |                                       |
   |                     |        | **HOST_NAME** indicates that the      |
   |                     |        | domain name will be used for          |
   |                     |        | matching, and **PATH** indicates that |
   |                     |        | the URL will be used for matching.    |
   |                     |        |                                       |
   |                     |        | The **type** value must be unique for |
   |                     |        | each forwarding rule in a forwarding  |
   |                     |        | policy.                               |
   +---------------------+--------+---------------------------------------+

.. _dlbst_pool:
.. table:: **Table 9** LoadBalancerStatusPool

   +---------------------+------------------------+---------------------------------------+
   | Parameter           | Type                   | Description                           |
   +=====================+========================+=======================================+
   | provisioning_status | String                 | Specifies the provisioning status of  |
   |                     |                        | the backend server group. The value   |
   |                     |                        | can only be **ACTIVE**.               |
   +---------------------+------------------------+---------------------------------------+
   | name                | String                 | Specifies the name of the backend     |
   |                     |                        | server group.                         |
   |                     |                        |                                       |
   |                     |                        | Minimum: **1**                        |
   |                     |                        |                                       |
   |                     |                        | Maximum: **255**                      |
   +---------------------+------------------------+---------------------------------------+
   | healthmonitor       | :ref:`dlbst_hm` object | Specifies the health check results of |
   |                     |                        | backend servers in the load balancer  |
   |                     |                        | status tree.                          |
   +---------------------+------------------------+---------------------------------------+
   | members             | :ref:`dlbst_m` objects | Specifies the backend server.         |
   +---------------------+------------------------+---------------------------------------+
   | id                  | String                 | Specifies the ID of the backend       |
   |                     |                        | server group.                         |
   +---------------------+------------------------+---------------------------------------+
   | operating_status    | String                 | Specifies the operating status of the |
   |                     |                        | backend server group.                 |
   |                     |                        |                                       |
   |                     |                        | The value can be one of the           |
   |                     |                        | following:                            |
   |                     |                        |                                       |
   |                     |                        | -  **ONLINE**: The backend server     |
   |                     |                        |    group is running normally.         |
   |                     |                        |                                       |
   |                     |                        | -  **DEGRADED**: This status is       |
   |                     |                        |    displayed only when                |
   |                     |                        |    **operating_status** of a backend  |
   |                     |                        |    server in the group is set to      |
   |                     |                        |    **OFFLINE** and the API for        |
   |                     |                        |    querying the load balancer status  |
   |                     |                        |    tree is called.                    |
   |                     |                        |                                       |
   |                     |                        | -  **DISABLED**: This status is       |
   |                     |                        |    displayed only when                |
   |                     |                        |    **admin_state_up** of the backend  |
   |                     |                        |    server group or the associated     |
   |                     |                        |    load balancer is set to **false**  |
   |                     |                        |    and the API for querying the load  |
   |                     |                        |    balancer status tree is called.    |
   +---------------------+------------------------+---------------------------------------+

.. _dlbst_hm:
.. table:: **Table 10** LoadBalancerStatusHealthMonitor

   +---------------------+--------+--------------------------------------+
   | Parameter           | Type   | Description                          |
   +=====================+========+======================================+
   | type                | String | Specifies the health check protocol. |
   |                     |        | The value can be **TCP**,            |
   |                     |        | **UDP_CONNECT**, or **HTTP**.        |
   +---------------------+--------+--------------------------------------+
   | id                  | String | Specifies the health check ID.       |
   +---------------------+--------+--------------------------------------+
   | name                | String | Specifies the health check name.     |
   |                     |        |                                      |
   |                     |        | Minimum: **1**                       |
   |                     |        |                                      |
   |                     |        | Maximum: **255**                     |
   +---------------------+--------+--------------------------------------+
   | provisioning_status | String | Specifies the provisioning status of |
   |                     |        | the health check. The value can only |
   |                     |        | be **ACTIVE**.                       |
   +---------------------+--------+--------------------------------------+

.. _dlbst_m:
.. table:: **Table 11** LoadBalancerStatusMember

   +---------------------+---------+---------------------------------------+
   | Parameter           | Type    | Description                           |
   +=====================+=========+=======================================+
   | provisioning_status | String  | Specifies the provisioning status of  |
   |                     |         | the backend server. The value can     |
   |                     |         | only be **ACTIVE**.                   |
   |                     |         |                                       |
   |                     |         | Default: **ACTIVE**                   |
   +---------------------+---------+---------------------------------------+
   | address             | String  | Specifies the IP address of the       |
   |                     |         | backend server.                       |
   +---------------------+---------+---------------------------------------+
   | protocol_port       | Integer | Specifies the port used by the        |
   |                     |         | backend server to receive requests.   |
   |                     |         | The port number ranges from 1 to      |
   |                     |         | 65535.                                |
   +---------------------+---------+---------------------------------------+
   | id                  | String  | Specifies the backend server ID.      |
   +---------------------+---------+---------------------------------------+
   | operating_status    | String  | Specifies the operating status of the |
   |                     |         | backend server.                       |
   |                     |         |                                       |
   |                     |         | The value can be one of the           |
   |                     |         | following:                            |
   |                     |         |                                       |
   |                     |         | -  **ONLINE**: The backend server is  |
   |                     |         |    running normally.                  |
   |                     |         |                                       |
   |                     |         | -  **NO_MONITOR**: No health check is |
   |                     |         |    configured for the backend server  |
   |                     |         |    group to which the backend server  |
   |                     |         |    belongs.                           |
   |                     |         |                                       |
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
   |                     |         |                                       |
   |                     |         | -  **OFFLINE**: The cloud server used |
   |                     |         |    as the backend server is stopped   |
   |                     |         |    or does not exist.                 |
   +---------------------+---------+---------------------------------------+

Example Requests
^^^^^^^^^^^^^^^^

Querying the status tree of a load balancer

.. code::

   GET

   https://{ELB_Endpoint}/v3/{project_id}/elb/loadbalancers/38278031-cfca-44be-81be-a412f618773b/statuses

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 200**

Successful request.

.. code::

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
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
200         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.
