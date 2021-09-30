=======
Memeber
=======

Adding a Backend Server
=======================

.. rest_method:: POST /v3/{project_id}/elb/pools/{pool_id}/members

This API is used to add a backend server.

When you add backend servers, note the following:

- Two backend servers in the same backend server group must have different IP
  addresses and ports.

- If no subnets are specified during cloud server creation, cross-VPC backend
  servers can be added. In this case, **address** must be set to an IPv4
  address, the protocol of the backend server group must be TCP, HTTP, or
  HTTPS, and cross-VPC backend must have been enabled for the load balancer.

- If a subnet is specified during cloud server creation, the subnet must be
  in the same VPC as the subnet from which the virtual IP address bound to
  the load balancer is assigned.

- If the backend server group supports IPv4/IPv6 dual stack, **address** can
  be an IPv4 or IPv6 address. The value of **address** depends on the IP
  address version of the backend server group.

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
   - pool_id: path-pool-id
   - admin_state_up: member-admin_state_up-optional
   - address: member-address
   - name: member-name-optional
   - protocol_port: member-protocol_port
   - subnet_cidr_id: member-subnet_cidr_id-optional
   - weight: member-weight-optional

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - member: member
   - id: member-id
   - project_id: project_id
   - admin_state_up: member-admin_state_up
   - address: member-address
   - name: member-name
   - protocol_port: member-protocol_port
   - subnet_cidr_id: member-subnet_cidr_id
   - weight: member-weight

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/member-create-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/member-create-response.json
   :language: javascript


Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Querying Backend Servers
========================

.. rest_method:: GET /v3/{project_id}/elb/pools/{pool_id}/members

This API is used to query all backend servers.

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
   - pool_id: path-pool-id
   - marker: marker
   - limit: limit
   - page_reverse: page-reverse
   - id: member-id-query
   - name: member-name-query
   - weight: member-weight-query
   - admin_state_up: member-admin_state_up-query
   - subnet_cidr_id: member-subnet_cidr_id-query
   - address: member-address-query
   - protocol_port: member-protocol_port-query
   - operating_status: member-operating_status-query
   - ip_version: member-ip_version-query

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - page_info: page_info
   - request_id: request_id
   - members: members
   - id: member-id
   - project_id: project_id
   - admin_state_up: member-admin_state_up
   - address: member-address
   - name: member-name
   - protocol_port: member-protocol_port
   - subnet_cidr_id: member-subnet_cidr_id
   - weight: member-weight

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/member-list-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/member-list-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Viewing Details of a Backend Server
===================================

.. rest_method:: GET /v3/{project_id}/elb/pools/{pool_id}/members/{member_id}

This API is used to view details of a backend server.

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
   - pool_id: path-pool-id
   - member_id: path-member-id

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - member: member
   - id: member-id
   - project_id: project_id
   - admin_state_up: member-admin_state_up
   - address: member-address
   - name: member-name
   - protocol_port: member-protocol_port
   - subnet_cidr_id: member-subnet_cidr_id
   - weight: member-weight

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/member-show-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/member-show-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Updating a Backend Server
=========================

.. rest_method:: PUT /v3/{project_id}/elb/pools/{pool_id}/members/{member_id}

The backend server can be updated only when the provisioning status of the
associated load balancer is **ACTIVE**.

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
   - pool_id: path-pool-id
   - member_id: path-member-id
   - admin_state_up: member-admin_state_up-optional
   - name: member-name-optional
   - weight: member-weight-optional

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - member: member
   - id: member-id
   - project_id: project_id
   - admin_state_up: member-admin_state_up
   - address: member-address
   - name: member-name
   - protocol_port: member-protocol_port
   - subnet_cidr_id: member-subnet_cidr_id
   - weight: member-weight

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/member-update-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/member-update-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Removing a Backend Server
=========================

.. rest_method:: DELETE /v3/{project_id}/elb/pools/{pool_id}/members/{member_id}

This API is used to remove a backend server.

When you remove backend servers, note the following:

- After you remove a backend server, new connections to this server will not
  be established. However, persistent connections that have been established
  will be maintained.

- The last backend server cannot be removed. If it is removed, 403 will be
  returned.

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
   - pool_id: path-pool-id
   - member_id: path-member-id

Response Parameters
^^^^^^^^^^^^^^^^^^^

None

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/hm-delete-curl
   :language: bash

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.
