=============
Load Balancer
=============

Creating a Load Balancer
========================

.. rest_method:: POST /v3/{project_id}/elb/loadbalancers

This API is used to create a dedicated load balancer. When you create the
load balancer, note the following:

-  Specify both **vip_subnet_cidr_id** and **vip_address** if you want to
   bind a private IPv4 address to the load balancer.

-  Specify **publicip** and either **vpc_id** or **vip_subnet_cidr_id** if
   you want to bind a new IPv4 EIP to the load balancer.

-  Specify **publicip_ids** and either **vpc_id** or **vip_subnet_cidr_id**
   if you want to bind an existing IPv4 EIP to the load balancer.

-  Specify **ipv6_vip_virsubnet_id** you want to bind a private IPv6 address
   to the load balancer.

-  Specify **ipv6_vip_virsubnet_id** and **ipv6_bandwidth** if you want to
   bind a public IPv6 address to the load balancer.

-  You cannot bind an occupied private IPv4 address, an occupied private IPv6
   address, or an occupied public IPv6 address to the load balancer.

-  Dedicated load balancers with IPv6 addresses are not supported.

There are some constraints when you create a dedicated load balancer:

-  **vpc_id**, **vip_subnet_cidr_id**, and **ipv6_vip_virsubnet_id** cannot
   be left blank at the same time.

-  **ip_target_enable** specifies whether to enable cross-VPC backend. If you
   have a load balancer with this function enabled, you can add servers in a
   VPC connected through a VPC peering connection, in a VPC connected through
   a cloud connection, or in an on-premises data center at the other end of a
   Direct Connect or VPN connection, by using server IP addresses.

-  **admin_state_up** must be set to **true**.

-  **provider** must be set to **vlb**.

-  **elb_virsubnet_ids** indicates the subnets that support IPv4/IPv6 dual
   stack or only IPv4 subnets. If only IPv4 subnets are supported,
   **ipv6_vip_virsubnet_id** must be left blank.

-  If you bind an EIP to the load balancer during creation, you cannot unbind
   it from the load balancer by calling the API after the load balancer is
   created. Instead, you can unbind the EIP only on the ELB console. Locate
   the dedicated load balancer in the load balancer list and click **More** >
   **Unbind EIP** in the **Operation** column.

-  **publicip_ids** and **publicip** cannot be specified at the same time.
   Set either **publicip_ids** to bind an existing EIP to the load balancer,
   or **publicip** to bind a new EIP to the load balancer, or neither of
   them.

-  If you want to add the load balancer to a shared bandwidth, you must
   specify the ID of the shared bandwidth. If you want the load balancer to
   use a new dedicated bandwidth, **charge_mode**, **share_type**, and
   **size** are required.

-  Dedicated load balancers are supported only in the **eu-nl** region.

.. rest_status_code:: success ../http-status.yaml

   - 201

.. rest_status_code:: error ../http-status.yaml

   - 400
   - 401
   - 403
   - 404

Request Parameters
^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - project_id: path-project-id
   - loadbalancer: loadbalancer
   - name: loadbalancer-name-optional
   - description: loadbalancer-description-optional
   - vip_address: loadbalancer-vip_address-optional
   - vip_subnet_cidr_id: loadbalancer-vip_subnet_cidr_id-optional
   - ipv6_vip_virsubnet_id: loadbalancer-ipv6_vip_virsubnet_id-optional
   - provider: loadbalancer-provider-optional
   - l4_flavor_id: loadbalancer-l4_flavor_id-optional
   - guaranteed: loadbalancer-guaranteed-optional
   - vpc_id: loadbalancer-vpc_id-optional
   - availability_zone_list: loadbalancer-availability_zone_list
   - tags: tags-optional
   - admin_state_up: loadbalancer-admin_state_up-optional
   - l7_flavor_id: loadbalancer-l7_flavor_id-optional
   - ipv6_bandwidth: loadbalancer-ipv6_bandwidth-optional
   - ipv6_bandwidth.id: loadbalancer-ipv6_bandwidth-id
   - publicip_ids: loadbalancer-publicip_ids-optional
   - publicip: loadbalancer-publicip-optional
   - publicip.ip_version: loadbalancer-publicip-ip_version-optional
   - publicip.network_type: loadbalancer-publicip-network_type
   - publicip.description: loadbalancer-publicip-description-optional
   - publicip.bandwidth: loadbalancer-publicip-bandwidth
   - publicip.bandwidth.name: loadbalancer-publicip-bandwidth-name-optional
   - publicip.bandwidth.id: loadbalancer-publicip-bandwidth-id-optional
   - publicip.bandwidth.charge_mode: loadbalancer-publicip-bandwidth-charge_mode-optional
   - publicip.bandwidth.size: loadbalancer-publicip-bandwidth-size-optional
   - publicip.bandwidth.share_type: loadbalancer-publicip-bandwidth-share_type-optional

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - project_id: project_id
   - loadbalancer: loadbalancer
   - id: loadbalancer-id
   - description: loadbalancer-description
   - provisioning_status: loadbalancer-provisioning_status
   - admin_state_up: loadbalancer-admin_state_up
   - provider: loadbalancer-provider
   - pools: loadbalancer-pools
   - pools.id: pool-id
   - listeners: loadbalancer-listeners
   - listeners.id: listener-id
   - operating_status: loadbalancer-operating_status
   - vip_address: loadbalancer-vip_address
   - vip_subnet_cidr_id: loadbalancer-vip_subnet_cidr_id
   - name: loadbalancer-name
   - vip_port_id: loadbalancer-port_id
   - tags: tags
   - created_at: created_at
   - updated_at: updated_at
   - guaranteed: loadbalancer-guaranteed
   - vpc_id: loadbalancer-vpc_id
   - eips: eips
   - eips.eip_id: eip-id
   - eips.eip_address: eip-address
   - eips.ip_version: eip-ip_version
   - ipv6_vip_address: loadbalancer-ipv6_vip_address
   - ipv6_vip_virsubnet_id: loadbalancer-ipv6_vip_virsubnet_id
   - ipv6_vip_port_id: loadbalancer-ipv6_vip_port_id
   - availability_zone_list: loadbalancer-availability_zone_list
   - l4_flavor_id: loadbalancer-l4_flavor_id
   - l4_scale_flavor_id: loadbalancer-l4_scale_flavor_id
   - l7_flavor_id: loadbalancer-l7_flavor_id
   - l7_scale_flavor_id: loadbalancer-l7_scale_flavor_id
   - publicips: loadbalancer-publicips
   - publicips.public_ip: loadbalancer-publicip-id
   - publicips.public_address: loadbalancer-publicip-address
   - publicips.ip_version: loadbalancer-publicip-ip_version
   - elb_virsubnet_ids: loadbalancer-elb_virsubnet_ids
   - ip_target_enable: loadbalancer-ip_target_enable
   - frozen_scene: loadbalancer-frozen_scene
   - ipv6_bandwidth: loadbalancer-ipv6_bandwidth
   - ipv6_bandwidth.id: loadbalancer-ipv6_bandwidth-id

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/lb-create-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/lb-create-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Listing Load Balancers
======================

.. rest_method:: GET /v3/{project_id}/elb/loadbalancers

This API is used to query all load balancers. Both filtered query and
pagination query are supported.

Parameters **marker**, **limit**, and **page_reverse** are used for
pagination query.

Parameters **marker** and **page_reverse** take effect only when they are
used together with parameter **limit**.

.. rest_status_code:: success ../http-status.yaml

   - 200

.. rest_status_code:: error ../http-status.yaml

   - 400
   - 401
   - 403
   - 404

Request Parameters
^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - project_id: path-project-id
   - marker: marker
   - limit: limit
   - page_reverse: page-reverse
   - id: loadbalancer-id-query
   - name: loadbalancer-name-query
   - description: loadbalancer-description-query
   - admin_state_up: admin_state_up-unsupported-query
   - provisioning_status: loadbalancer-provisioning_status-query
   - operating_status: loadbalancer-operating_status-query
   - guaranteed: loadbalancer-guaranteed-query
   - vpc_id: loadbalancer-vpc_id-query
   - vip_port_id: loadbalancer-vip_port_id-query
   - vip_address: loadbalancer-vip_address-query
   - vip_subnet_cidr_id: loadbalancer-vip_subnet_cidr_id-query
   - l4_flavor_id: loadbalancer-l4_flavor_id-query
   - l4_scale_flavor_id: loadbalancer-l4_scale_flavor_id-query
   - ipv6_vip_address: loadbalancer-ipv6_vip_address-query
   - ipv6_vip_virsubnet_id: loadbalancer-ipv6_vip_virsubnet_id-query
   - ipv6_vip_port_id: loadbalancer-ipv6_vip_port_id-query
   - availability_zone_list: loadbalancer-availability_zone_list-query
   - eips: loadbalancer-eips-query
   - l7_flavor_id: loadbalancer-l7_flavor_id-query
   - l7_scale_flavor_id: loadbalancer-l7_scale_flavor_id-query
   - member_device_id: loadbalancer-member_device_id-query
   - member_address: loadbalancer-member_address-query
   - publicips: loadbalancer-publicips-query
   - ip_version: loadbalancer-ip_version-query

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - page_info: page_info
   - request_id: request_id
   - loadbalancers: loadbalancers
   - id: loadbalancer-id
   - description: loadbalancer-description
   - provisioning_status: loadbalancer-provisioning_status
   - admin_state_up: loadbalancer-admin_state_up
   - provider: loadbalancer-provider
   - pools: loadbalancer-pools
   - pools.id: pool-id
   - listeners: loadbalancer-listeners
   - listeners.id: listener-id
   - operating_status: loadbalancer-operating_status
   - vip_address: loadbalancer-vip_address
   - vip_subnet_cidr_id: loadbalancer-vip_subnet_cidr_id
   - name: loadbalancer-name
   - vip_port_id: loadbalancer-port_id
   - tags: tags
   - created_at: created_at
   - updated_at: updated_at
   - guaranteed: loadbalancer-guaranteed
   - vpc_id: loadbalancer-vpc_id
   - eips: eips
   - eips.eip_id: eip-id
   - eips.eip_address: eip-address
   - eips.ip_version: eip-ip_version
   - ipv6_vip_address: loadbalancer-ipv6_vip_address
   - ipv6_vip_virsubnet_id: loadbalancer-ipv6_vip_virsubnet_id
   - ipv6_vip_port_id: loadbalancer-ipv6_vip_port_id
   - availability_zone_list: loadbalancer-availability_zone_list
   - l4_flavor_id: loadbalancer-l4_flavor_id
   - l4_scale_flavor_id: loadbalancer-l4_scale_flavor_id
   - l7_flavor_id: loadbalancer-l7_flavor_id
   - l7_scale_flavor_id: loadbalancer-l7_scale_flavor_id
   - publicips: loadbalancer-publicips
   - publicips.public_ip: loadbalancer-publicip-id
   - publicips.public_address: loadbalancer-publicip-address
   - publicips.ip_version: loadbalancer-publicip-ip_version
   - elb_virsubnet_ids: loadbalancer-elb_virsubnet_ids
   - ip_target_enable: loadbalancer-ip_target_enable
   - frozen_scene: loadbalancer-frozen_scene
   - ipv6_bandwidth: loadbalancer-ipv6_bandwidth
   - ipv6_bandwidth.id: loadbalancer-ipv6_bandwidth-id

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/lb-list-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/lb-list-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Viewing Details of a Load Balancer
==================================

.. rest_method:: GET /v3/{project_id}/elb/loadbalancers/{loadbalancer_id}

This API is used to view details of a load balancer.

Request Parameters
^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - project_id: path-project-id
   - loadbalancer_id: path-loadbalancer-id

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - project_id: project_id
   - loadbalancer: loadbalancer
   - id: loadbalancer-id
   - description: loadbalancer-description
   - provisioning_status: loadbalancer-provisioning_status
   - admin_state_up: loadbalancer-admin_state_up
   - provider: loadbalancer-provider
   - pools: loadbalancer-pools
   - pools.id: pool-id
   - listeners: loadbalancer-listeners
   - listeners.id: listener-id
   - operating_status: loadbalancer-operating_status
   - vip_address: loadbalancer-vip_address
   - vip_subnet_cidr_id: loadbalancer-vip_subnet_cidr_id
   - name: loadbalancer-name
   - vip_port_id: loadbalancer-port_id
   - tags: tags
   - created_at: created_at
   - updated_at: updated_at
   - guaranteed: loadbalancer-guaranteed
   - vpc_id: loadbalancer-vpc_id
   - eips: eips
   - eips.eip_id: eip-id
   - eips.eip_address: eip-address
   - eips.ip_version: eip-ip_version
   - ipv6_vip_address: loadbalancer-ipv6_vip_address
   - ipv6_vip_virsubnet_id: loadbalancer-ipv6_vip_virsubnet_id
   - ipv6_vip_port_id: loadbalancer-ipv6_vip_port_id
   - availability_zone_list: loadbalancer-availability_zone_list
   - l4_flavor_id: loadbalancer-l4_flavor_id
   - l4_scale_flavor_id: loadbalancer-l4_scale_flavor_id
   - l7_flavor_id: loadbalancer-l7_flavor_id
   - l7_scale_flavor_id: loadbalancer-l7_scale_flavor_id
   - publicips: loadbalancer-publicips
   - publicips.public_ip: loadbalancer-publicip-id
   - publicips.public_address: loadbalancer-publicip-address
   - publicips.ip_version: loadbalancer-publicip-ip_version
   - elb_virsubnet_ids: loadbalancer-elb_virsubnet_ids
   - ip_target_enable: loadbalancer-ip_target_enable
   - frozen_scene: loadbalancer-frozen_scene
   - ipv6_bandwidth: loadbalancer-ipv6_bandwidth
   - ipv6_bandwidth.id: loadbalancer-ipv6_bandwidth-id

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/lb-show-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/lb-show-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Updating a Load Balancer
========================

.. rest_method:: PUT /v3/{project_id}/elb/loadbalancers/{loadbalancer_id}

This API is used to update a load balancer.

Request Parameters
^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - project_id: path-project-id
   - loadbalancer_id: path-loadbalancer-id
   - loadbalancer: loadbalancer
   - name: loadbalancer-name-optional
   - admin_state_up: loadbalancer-admin_state_up-optional
   - description: loadbalancer-description-optional
   - ipv6_vip_virsubnet_id: loadbalancer-ipv6_vip_virsubnet_id-optional
   - vip_subnet_cidr_id: loadbalancer-vip_subnet_cidr_id-optional
   - vip_address: loadbalancer-vip_address-optional
   - l4_flavor_id: loadbalancer-l4_flavor_id-optional
   - l7_flavor_id: loadbalancer-l7_flavor_id-optional
   - ipv6_bandwidth: loadbalancer-ipv6_bandwidth-optional
   - ipv6_bandwidth.id: loadbalancer-ipv6_bandwidth-id
   - ip_target_enable: loadbalancer-ip_target_enable

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - project_id: project_id
   - loadbalancer: loadbalancer
   - id: loadbalancer-id
   - description: loadbalancer-description
   - provisioning_status: loadbalancer-provisioning_status
   - admin_state_up: loadbalancer-admin_state_up
   - provider: loadbalancer-provider
   - pools: loadbalancer-pools
   - pools.id: pool-id
   - listeners: loadbalancer-listeners
   - listeners.id: listener-id
   - operating_status: loadbalancer-operating_status
   - vip_address: loadbalancer-vip_address
   - vip_subnet_cidr_id: loadbalancer-vip_subnet_cidr_id
   - name: loadbalancer-name
   - vip_port_id: loadbalancer-port_id
   - tags: tags
   - created_at: created_at
   - updated_at: updated_at
   - guaranteed: loadbalancer-guaranteed
   - vpc_id: loadbalancer-vpc_id
   - eips: eips
   - eips.eip_id: eip-id
   - eips.eip_address: eip-address
   - eips.ip_version: eip-ip_version
   - ipv6_vip_address: loadbalancer-ipv6_vip_address
   - ipv6_vip_virsubnet_id: loadbalancer-ipv6_vip_virsubnet_id
   - ipv6_vip_port_id: loadbalancer-ipv6_vip_port_id
   - availability_zone_list: loadbalancer-availability_zone_list
   - l4_flavor_id: loadbalancer-l4_flavor_id
   - l4_scale_flavor_id: loadbalancer-l4_scale_flavor_id
   - l7_flavor_id: loadbalancer-l7_flavor_id
   - l7_scale_flavor_id: loadbalancer-l7_scale_flavor_id
   - publicips: loadbalancer-publicips
   - publicips.public_ip: loadbalancer-publicip-id
   - publicips.public_address: loadbalancer-publicip-address
   - publicips.ip_version: loadbalancer-publicip-ip_version
   - elb_virsubnet_ids: loadbalancer-elb_virsubnet_ids
   - ip_target_enable: loadbalancer-ip_target_enable
   - frozen_scene: loadbalancer-frozen_scene
   - ipv6_bandwidth: loadbalancer-ipv6_bandwidth
   - ipv6_bandwidth.id: loadbalancer-ipv6_bandwidth-id

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/lb-update-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/lb-update-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Deleting a Load Balancer
========================

.. rest_method:: DELETE /v3/{project_id}/elb/loadbalancers/{loadbalancer_id}

This API is used to delete a load balancer.

All listeners added to the load balancer must be deleted before the load balancer is deleted.

.. rest_status_code:: success ../http-status.yaml

   - 204

.. rest_status_code:: error ../http-status.yaml

   - 400
   - 401
   - 403
   - 404

Request Parameters
^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - project_id: path-project-id
   - loadbalancer_id: path-loadbalancer-id

Response Parameters
^^^^^^^^^^^^^^^^^^^

None

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/lb-delete-curl
   :language: bash


Error Codes
^^^^^^^^^^^

See :ref:`dsc`.
