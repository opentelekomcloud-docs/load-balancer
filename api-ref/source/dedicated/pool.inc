.. -*- rst -*-

Creating a Backend Server Group
===============================

.. rest_method:: POST /v3/{project_id}/elb/pools

This API is used to create a backend server group.

If **session-persistence** is specified, **cookie_name** is available only when
**type** is set to **APP_COOKIE**.

If **listener_id** is specified, the listener must have no backend server group
associated.

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
   - admin_state_up: admin_state_up-optional
   - description: pool-description-optional
   - lb_algorithm: pool-lb_algorithm
   - listener_id: pool-listener_id-optional
   - loadbalancer_id: pool-loadbalancer_id-optional
   - name: pool-name-optional
   - project_id: project_id
   - protocol: pool-protocol
   - session_persistence: pool-session_persistence-optional
   - session_persistence.cookie_name: pool-session_persistence-cookie_name-optional
   - session_persistence.type: pool-session_persistence-type
   - session_persistence.persistence_timeout: pool-session_persistence-timeout-optional
   - slow_start: pool-slow_start-optional
   - slow_start.enable: pool-slow_start-enable
   - slow_start.duration: pool-slow_start-duration

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - request_id: request_id
   - pool: pool
   - admin_state_up: admin_state_up
   - description: pool-description
   - healthmonitor_id: pool-healthmonitor_id
   - id: pool-id
   - lb_algorithm: pool-lb_algorithm
   - listeners: pool-listeners
   - listeners.id: listener-id
   - loadbalancers: pool-loadbalancers
   - loadbalancers.id: loadbalancer-id
   - members: pool-members
   - members.id: member-id
   - name: pool-name
   - project_id: project_id
   - protocol: pool-protocol
   - session_persistence: pool-session_persistence
   - session_persistence.cookie_name: pool-session_persistence-cookie_name
   - session_persistence.type: pool-session_persistence-type
   - session_persistence.persistence_timeout: pool-session_persistence-timeout
   - slow_start: pool-slow_start
   - slow_start.enable: pool-slow_start-enable
   - slow_start.duration: pool-slow_start-duration
   - ip_version: pool-ip_version

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/pool-create-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/pool-create-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Listing Backend Server Groups
=============================

.. rest_method:: GET /v3/{project_id}/elb/pools

This API is used to query all backend server groups.

Parameters **marker**, **limit**, and **page_reverse** are used for pagination
query.

Parameters **marker** and **page_reverse** take effect only when they are used
together with parameter **limit**.

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
   - admin_state_up: admin_state_up-unsupported-query
   - description: pool-description-query
   - healthmonitor: pool-healthmonitor_id-query
   - id: pool-id-query
   - name: pool-name-query
   - loadbalancer_id: pool-loadbalancer_id-query
   - protocol: pool-protocol-query
   - lb_algorithm: pool-lb_algorithm-query
   - ip_version: pool-ip_version-query
   - member_address: pool-member_address-query
   - member_device_id: pool-member_device_id-query

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - page_info: page_info
   - request_id: request_id
   - pools: pools
   - admin_state_up: admin_state_up
   - description: pool-description
   - healthmonitor_id: pool-healthmonitor_id
   - id: pool-id
   - lb_algorithm: pool-lb_algorithm
   - listeners: pool-listeners
   - listeners.id: listener-id
   - loadbalancers: pool-loadbalancers
   - loadbalancers.id: loadbalancer-id
   - members: pool-members
   - members.id: member-id
   - name: pool-name
   - project_id: project_id
   - protocol: pool-protocol
   - session_persistence: pool-session_persistence
   - session_persistence.cookie_name: pool-session_persistence-cookie_name
   - session_persistence.type: pool-session_persistence-type
   - session_persistence.persistence_timeout: pool-session_persistence-timeout
   - slow_start: pool-slow_start
   - slow_start.enable: pool-slow_start-enable
   - slow_start.duration: pool-slow_start-duration
   - ip_version: pool-ip_version

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/pool-list-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/pool-list-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Viewing Details of a Backend Server Group
=========================================

.. rest_method:: GET /v3/{project_id}/elb/pools/{pool_id}

This API is used to view details of a backend server group.

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


Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - request_id: request_id
   - pool: pool
   - admin_state_up: admin_state_up
   - description: pool-description
   - healthmonitor_id: pool-healthmonitor_id
   - id: pool-id
   - lb_algorithm: pool-lb_algorithm
   - listeners: pool-listeners
   - listeners.id: listener-id
   - loadbalancers: pool-loadbalancers
   - loadbalancers.id: loadbalancer-id
   - members: pool-members
   - members.id: member-id
   - name: pool-name
   - project_id: project_id
   - protocol: pool-protocol
   - session_persistence: pool-session_persistence
   - session_persistence.cookie_name: pool-session_persistence-cookie_name
   - session_persistence.type: pool-session_persistence-type
   - session_persistence.persistence_timeout: pool-session_persistence-timeout
   - slow_start: pool-slow_start
   - slow_start.enable: pool-slow_start-enable
   - slow_start.duration: pool-slow_start-duration
   - ip_version: pool-ip_version

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/pool-show-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/pool-show-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Updating a Backend Server Group
===============================

.. rest_method:: PUT /v3/{project_id}/elb/pools/{pool_id}

This API is used to update a backend server group.

The backend server group can be updated only when the provisioning status of
the associated load balancer is **ACTIVE**.

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
   - admin_state_up: admin_state_up-optional
   - description: pool-description-optional
   - lb_algorithm: pool-lb_algorithm
   - name: pool-name-optional
   - session_persistence: pool-session_persistence-optional
   - session_persistence.cookie_name: pool-session_persistence-cookie_name-optional
   - session_persistence.type: pool-session_persistence-type
   - session_persistence.persistence_timeout: pool-session_persistence-timeout-optional
   - slow_start: pool-slow_start-optional
   - slow_start.enable: pool-slow_start-enable
   - slow_start.duration: pool-slow_start-duration

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - request_id: request_id
   - pool: pool
   - admin_state_up: admin_state_up
   - description: pool-description
   - healthmonitor_id: pool-healthmonitor_id
   - id: pool-id
   - lb_algorithm: pool-lb_algorithm
   - listeners: pool-listeners
   - listeners.id: listener-id
   - loadbalancers: pool-loadbalancers
   - loadbalancers.id: loadbalancer-id
   - members: pool-members
   - members.id: member-id
   - name: pool-name
   - project_id: project_id
   - protocol: pool-protocol
   - session_persistence: pool-session_persistence
   - session_persistence.cookie_name: pool-session_persistence-cookie_name
   - session_persistence.type: pool-session_persistence-type
   - session_persistence.persistence_timeout: pool-session_persistence-timeout
   - slow_start: pool-slow_start
   - slow_start.enable: pool-slow_start-enable
   - slow_start.duration: pool-slow_start-duration
   - ip_version: pool-ip_version

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/pool-update-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/pool-update-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Deleting a Backend Server Group
===============================

.. rest_method:: DELETE /v3/{project_id}/elb/pools/{pool_id}

This API is used to delete a backend server group.

A backend server group can be deleted only after all servers are removed from
the group, the health check configured for the group is deleted, and the group
has no forwarding policies associated.

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

Response Parameters
^^^^^^^^^^^^^^^^^^^

None

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/pool-delete-curl
   :language: bash

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.
