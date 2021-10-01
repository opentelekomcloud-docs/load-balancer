.. -*- rst -*-

Adding a Listener
=================

.. rest_method:: POST /v3/{project_id}/elb/listeners

This API is used to add a listener to a load balancer.

Only the administrator can specify **connection_limit**.

- The listener protocol can be TCP, HTTP, UDP, or HTTPS.
- For load balancing at Layer 4, the listener protocol can only be TCP or
  UDP.
- For load balancing at Layer 7, the listener protocol can only be HTTP or
  HTTPS.
- For load balancing both at Layer 4 and Layer 7, TCP, UDP, HTTP, and HTTPS
  are supported.

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
   - listener: listener
   - admin_state_up: admin_state_up-notsupported-optional
   - client_ca_tls_container_ref: listener-client_ca_tls_container_ref-optional
   - default_pool_id: listener-default_pool_id-optional
   - default_tls_container_ref: listener-default_tls_container_ref-optional
   - description: listener-description-optional
   - http2_enable: listener-http2_enable-optional
   - insert_headers: listener-insert_headers-optional
   - loadbalancer_id: listener-loadbalancer_id
   - name: listener-name-optional
   - project_id: project_id-optional
   - protocol: listener-protocol
   - protocol_port: listener-protocol_port
   - sni_container_refs: listener-sni_container_refs-optional
   - tags: tags-optional
   - tls_ciphers_policy: listener-tls_ciphers_policy-optional
   - enable_member_retry: listener-enable_member_retry-optional
   - keepalive_timeout: listener-keepalive_timeout-optional
   - client_timeout: listener-client_timeout-optional
   - member_timeout: listener-member_timeout-optional
   - ipgroup: listener-ipgroup-optional
   - transparent_client_ip_enable: listener-transparent_client_ip_enable-optional
   - enhance_l7policy_enable: listener-enhance_l7policy_enable-optional

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - listener: listener
   - id: listener-id
   - admin_state_up: admin_state_up-notsupported
   - client_ca_tls_container_ref: listener-client_ca_tls_container_ref
   - connection_limit: listener-connection_limit
   - created_at: created_at
   - default_pool_id: listener-default_pool_id
   - default_tls_container_ref: listener-default_tls_container_ref
   - description: listener-description
   - http2_enable: listener-http2_enable
   - insert_headers: listener-insert_headers
   - loadbalancers: listener-loadbalancers
   - name: listener-name
   - project_id: project_id
   - protocol: listener-protocol
   - protocol_port: listener-protocol_port
   - sni_container_refs: listener-sni_container_refs
   - tags: tags
   - updated_at: updated_at
   - tls_ciphers_policy: listener-tls_ciphers_policy
   - enable_member_retry: listener-enable_member_retry
   - keepalive_timeout: listener-keepalive_timeout
   - client_timeout: listener-client_timeout
   - member_timeout: listener-member_timeout
   - ipgroup: listener-ipgroup
   - transparent_client_ip_enable: listener-transparent_client_ip_enable
   - enhance_l7policy_enable: listener-enhance_l7policy_enable

Example Requests
^^^^^^^^^^^^^^^^

Creating HTTPS listener

.. literalinclude:: examples/listener-create-https-curl
   :language: bash

Creating TCP listener

.. literalinclude:: examples/listener-create-tcp-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/listener-create-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Listing Listeners
=================

.. rest_method:: GET /v3/{project_id}/elb/listeners

This API is used to query listeners.

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
   - protocol_port: listener-protocol_port-query
   - protocol: listener-protocol-query
   - description: listener-description-query
   - default_tls_container_ref: listener-default_tls_container_ref-query
   - client_ca_tls_container_ref: listener-client_ca_tls_container_ref-query
   - admin_state_up: admin_state_up-unsupported-query
   - connection_limit: listener-connection_limit-query
   - default_pool_id: listener-default_pool_id-query
   - id: listener-id-query
   - name: listener-name-query
   - http2_enable: listener-http2_enable-query
   - loadbalancer_id: listener-loadbalancer_id-query
   - tls_ciphers_policy: listener-tls_ciphers_policy-query
   - member_address: listener-member_address-query
   - member_device_id: listener-member_device_id-query
   - enable_member_retry: listener-enable_member_retry-query
   - member_timeout: listener-member_timeout-query
   - client_timeout: listener-client_timeout-query
   - keepalive_timeout: listener-keepalive_timeout-query
   - transparent_client_ip_enable: listener-transparent_client_ip_enable-query

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - page_info: page_info
   - request_id: request_id
   - listeners: listeners
   - id: listener-id
   - admin_state_up: admin_state_up-notsupported
   - client_ca_tls_container_ref: listener-client_ca_tls_container_ref
   - connection_limit: listener-connection_limit
   - created_at: created_at
   - default_pool_id: listener-default_pool_id
   - default_tls_container_ref: listener-default_tls_container_ref
   - description: listener-description
   - http2_enable: listener-http2_enable
   - insert_headers: listener-insert_headers
   - loadbalancers: listener-loadbalancers
   - name: listener-name
   - project_id: project_id
   - protocol: listener-protocol
   - protocol_port: listener-protocol_port
   - sni_container_refs: listener-sni_container_refs
   - tags: tags
   - updated_at: updated_at
   - tls_ciphers_policy: listener-tls_ciphers_policy
   - enable_member_retry: listener-enable_member_retry
   - keepalive_timeout: listener-keepalive_timeout
   - client_timeout: listener-client_timeout
   - member_timeout: listener-member_timeout
   - ipgroup: listener-ipgroup
   - transparent_client_ip_enable: listener-transparent_client_ip_enable
   - enhance_l7policy_enable: listener-enhance_l7policy_enable

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/listener-list-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/listener-list-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Viewing Details of a Listener
=============================

.. rest_method:: GET /v3/{project_id}/elb/listeners/{listener_id}

This API is used to view details of a listener.

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
   - listener_id: path-listener-id

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - page_info: page_info
   - request_id: request_id
   - listeners: listeners
   - id: listener-id
   - admin_state_up: admin_state_up-notsupported
   - client_ca_tls_container_ref: listener-client_ca_tls_container_ref
   - connection_limit: listener-connection_limit
   - created_at: created_at
   - default_pool_id: listener-default_pool_id
   - default_tls_container_ref: listener-default_tls_container_ref
   - description: listener-description
   - http2_enable: listener-http2_enable
   - insert_headers: listener-insert_headers
   - loadbalancers: listener-loadbalancers
   - name: listener-name
   - project_id: project_id
   - protocol: listener-protocol
   - protocol_port: listener-protocol_port
   - sni_container_refs: listener-sni_container_refs
   - tags: tags
   - updated_at: updated_at
   - tls_ciphers_policy: listener-tls_ciphers_policy
   - enable_member_retry: listener-enable_member_retry
   - keepalive_timeout: listener-keepalive_timeout
   - client_timeout: listener-client_timeout
   - member_timeout: listener-member_timeout
   - ipgroup: listener-ipgroup
   - transparent_client_ip_enable: listener-transparent_client_ip_enable
   - enhance_l7policy_enable: listener-enhance_l7policy_enable

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/listener-show-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/listener-show-response.json
   :language: javascript

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

Updating a Listener
===================

.. rest_method:: PUT /v3/{project_id}/elb/listeners/{listener_id}

This API is used to update a listener.

If the provisioning status of the load balancer that the listener is added to
is not **ACTIVE**, the listener cannot be updated. Only the administrator can
specify **connection_limit**.

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
   - listener_id: path-listener-id
   - admin_state_up: admin_state_up-notsupported-optional
   - client_ca_tls_container_ref: listener-client_ca_tls_container_ref-optional
   - default_pool_id: listener-default_pool_id-optional
   - default_tls_container_ref: listener-default_tls_container_ref-optional
   - description: listener-description-optional
   - http2_enable: listener-http2_enable-optional
   - insert_headers: listener-insert_headers-optional
   - name: listener-name-optional
   - sni_container_refs: listener-sni_container_refs-optional
   - tls_ciphers_policy: listener-tls_ciphers_policy-optional
   - enable_member_retry: listener-enable_member_retry-optional
   - keepalive_timeout: listener-keepalive_timeout-optional
   - client_timeout: listener-client_timeout-optional
   - member_timeout: listener-member_timeout-optional
   - ipgroup: listener-ipgroup-optional
   - transparent_client_ip_enable: listener-transparent_client_ip_enable-optional
   - enhance_l7policy_enable: listener-enhance_l7policy_enable-optional

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - request_id: request_id
   - listener: listener
   - id: listener-id
   - admin_state_up: admin_state_up-notsupported
   - client_ca_tls_container_ref: listener-client_ca_tls_container_ref
   - connection_limit: listener-connection_limit
   - created_at: created_at
   - default_pool_id: listener-default_pool_id
   - default_tls_container_ref: listener-default_tls_container_ref
   - description: listener-description
   - http2_enable: listener-http2_enable
   - insert_headers: listener-insert_headers
   - loadbalancers: listener-loadbalancers
   - name: listener-name
   - project_id: project_id
   - protocol: listener-protocol
   - protocol_port: listener-protocol_port
   - sni_container_refs: listener-sni_container_refs
   - tags: tags
   - updated_at: updated_at
   - tls_ciphers_policy: listener-tls_ciphers_policy
   - enable_member_retry: listener-enable_member_retry
   - keepalive_timeout: listener-keepalive_timeout
   - client_timeout: listener-client_timeout
   - member_timeout: listener-member_timeout
   - ipgroup: listener-ipgroup
   - transparent_client_ip_enable: listener-transparent_client_ip_enable
   - enhance_l7policy_enable: listener-enhance_l7policy_enable

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/listener-update-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/listener-update-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Deleting a Listener
===================

.. rest_method:: DELETE /v3/{project_id}/elb/listeners/{listener_id}

This API is used to delete a listener.

Before you delete a listener, delete the associated backend server group or
disassociate the backend server group from the listener, and then delete all
forwarding policies.

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
   - listener_id: path-listener-id

Response Parameters
^^^^^^^^^^^^^^^^^^^

None

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/listener-delete-curl
   :language: bash


Error Codes
^^^^^^^^^^^

See :ref:`dsc`.
