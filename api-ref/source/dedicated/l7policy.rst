=================
Forwarding Policy
=================

Adding a Forwarding Policy
==========================

.. rest_method:: POST /v3/{project_id}/elb/l7policies

This API is used to add a forwarding policy.

The protocol of the listener to which requests are redirected can only be
HTTPS.

The listener associated with the forwarding policy cannot be any listener added
to other load balancers.

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
   - action: l7policy-action
   - description: l7policy-description
   - listener_id: l7policy-listener_id
   - name: l7policy-name
   - position: l7policy-position
   - project_id: project_id
   - redirect_listener_id: l7policy-redirect_listener_id
   - redirect_pool_id: l7policy-redirect_pool_id
   - redirect_url: l7policy-redirect_url
   - priority: l7policy-priority
   - rules: l7policy-rules
   - redirect_url_config: l7policy-redirect_url_config
   - redirect_url_config.protocol: l7policy-redirect_url_config-protocol
   - redirect_url_config.host: l7policy-redirect_url_config-host
   - redirect_url_config.port: l7policy-redirect_url_config-port
   - redirect_url_config.path: l7policy-redirect_url_config-path
   - redirect_url_config.query: l7policy-redirect_url_config-query
   - redirect_url_config.status_code: l7policy-redirect_url_config-status_code
   - fixed_response_config: l7policy-fixed_response_config
   - fixed_response_config.status_code: l7policy-fixed_response_config-status_code
   - fixed_response_config.content_type: l7policy-fixed_response_config-content_type
   - fixed_response_config.message_body: l7policy-fixed_response_config-message_body

Rule Parameters
^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - admin_state_up: l7rule-admin_state_up
   - type: l7rule-type
   - compare_type: l7rule-compare_type
   - invert: l7rule-invert
   - key: l7rule-key
   - value: l7rule-value
   - conditions: l7rule-conditions
   - conditions.key: l7rule-conditions-key
   - conditions.value: l7rule-conditions-value

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - project_id: path-project-id
   - admin_state_up: admin_state_up
   - action: l7policy-action
   - description: l7policy-description
   - listener_id: l7policy-listener_id
   - name: l7policy-name
   - position: l7policy-position
   - project_id: project_id
   - redirect_listener_id: l7policy-redirect_listener_id
   - redirect_pool_id: l7policy-redirect_pool_id
   - redirect_url: l7policy-redirect_url
   - priority: l7policy-priority
   - rules: l7policy-rules
   - redirect_url_config: l7policy-redirect_url_config
   - redirect_url_config.protocol: l7policy-redirect_url_config-protocol
   - redirect_url_config.host: l7policy-redirect_url_config-host
   - redirect_url_config.port: l7policy-redirect_url_config-port
   - redirect_url_config.path: l7policy-redirect_url_config-path
   - redirect_url_config.query: l7policy-redirect_url_config-query
   - redirect_url_config.status_code: l7policy-redirect_url_config-status_code
   - fixed_response_config: l7policy-fixed_response_config
   - fixed_response_config.status_code: l7policy-fixed_response_config-status_code
   - fixed_response_config.content_type: l7policy-fixed_response_config-content_type
   - fixed_response_config.message_body: l7policy-fixed_response_config-message_body

Example Requests
^^^^^^^^^^^^^^^^

Creating a redirection for a listener

.. literalinclude:: examples/l7policy-create-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/l7policy-create-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Listing Forwarding Policies
============================

.. rest_method:: GET /v3/{project_id}/elb/l7policies

This API is used to query all forwarding policies.

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
   - id: l7policy-id-query
   - name: l7policy-name-query
   - description: l7policy-description-query
   - admin_state_up: l7policy-admin_state_up-query
   - listener_id: l7policy-listener_id-query
   - position: l7policy-position-query
   - action: l7policy-action-query
   - redirect_url: l7policy-redirect_url-query
   - redirect_pool_id: l7policy-redirect_pool_id-query
   - redirect_listener_id: l7policy-redirect_listener_id-query
   - provisioning_status: l7policy-provisioning_status-query
   - display_all_rules: l7policy-display_all_rules-query
   - priority: l7policy-priority-query

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - page_info: page_info
   - request_id: request_id
   - l7policies: l7policies
   - project_id: path-project-id
   - admin_state_up: admin_state_up
   - action: l7policy-action
   - description: l7policy-description
   - listener_id: l7policy-listener_id
   - name: l7policy-name
   - position: l7policy-position
   - project_id: project_id
   - redirect_listener_id: l7policy-redirect_listener_id
   - redirect_pool_id: l7policy-redirect_pool_id
   - redirect_url: l7policy-redirect_url
   - priority: l7policy-priority
   - rules: l7policy-rules
   - redirect_url_config: l7policy-redirect_url_config
   - redirect_url_config.protocol: l7policy-redirect_url_config-protocol
   - redirect_url_config.host: l7policy-redirect_url_config-host
   - redirect_url_config.port: l7policy-redirect_url_config-port
   - redirect_url_config.path: l7policy-redirect_url_config-path
   - redirect_url_config.query: l7policy-redirect_url_config-query
   - redirect_url_config.status_code: l7policy-redirect_url_config-status_code
   - fixed_response_config: l7policy-fixed_response_config
   - fixed_response_config.status_code: l7policy-fixed_response_config-status_code
   - fixed_response_config.content_type: l7policy-fixed_response_config-content_type
   - fixed_response_config.message_body: l7policy-fixed_response_config-message_body

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/l7policy-list-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/l7policy-list-response.json
   :language: javascript

Viewing Details of a Forwarding Policy
======================================

.. rest_method:: GET /v3/{project_id}/elb/l7policies/{policy_id}

This API is used to view details of a forwarding policy.

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
   - policy_id: path-l7policy-id

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - project_id: path-project-id
   - admin_state_up: admin_state_up
   - action: l7policy-action
   - description: l7policy-description
   - listener_id: l7policy-listener_id
   - name: l7policy-name
   - position: l7policy-position
   - project_id: project_id
   - redirect_listener_id: l7policy-redirect_listener_id
   - redirect_pool_id: l7policy-redirect_pool_id
   - redirect_url: l7policy-redirect_url
   - priority: l7policy-priority
   - rules: l7policy-rules
   - redirect_url_config: l7policy-redirect_url_config
   - redirect_url_config.protocol: l7policy-redirect_url_config-protocol
   - redirect_url_config.host: l7policy-redirect_url_config-host
   - redirect_url_config.port: l7policy-redirect_url_config-port
   - redirect_url_config.path: l7policy-redirect_url_config-path
   - redirect_url_config.query: l7policy-redirect_url_config-query
   - redirect_url_config.status_code: l7policy-redirect_url_config-status_code
   - fixed_response_config: l7policy-fixed_response_config
   - fixed_response_config.status_code: l7policy-fixed_response_config-status_code
   - fixed_response_config.content_type: l7policy-fixed_response_config-content_type
   - fixed_response_config.message_body: l7policy-fixed_response_config-message_body

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/l7policy-show-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/l7policy-show-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Updating a Forwarding Policy
============================

.. rest_method:: PUT /v3/{project_id}/elb/l7policies/{policy_id}

This API is used to update a forwarding policy.

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
   - policy_id: path-l7policy-id
   - admin_state_up: admin_state_up
   - action: l7policy-action
   - description: l7policy-description
   - listener_id: l7policy-listener_id
   - name: l7policy-name
   - position: l7policy-position
   - project_id: project_id
   - redirect_listener_id: l7policy-redirect_listener_id
   - redirect_pool_id: l7policy-redirect_pool_id
   - redirect_url: l7policy-redirect_url
   - priority: l7policy-priority
   - rules: l7policy-rules
   - redirect_url_config: l7policy-redirect_url_config
   - redirect_url_config.protocol: l7policy-redirect_url_config-protocol
   - redirect_url_config.host: l7policy-redirect_url_config-host
   - redirect_url_config.port: l7policy-redirect_url_config-port
   - redirect_url_config.path: l7policy-redirect_url_config-path
   - redirect_url_config.query: l7policy-redirect_url_config-query
   - redirect_url_config.status_code: l7policy-redirect_url_config-status_code
   - fixed_response_config: l7policy-fixed_response_config
   - fixed_response_config.status_code: l7policy-fixed_response_config-status_code
   - fixed_response_config.content_type: l7policy-fixed_response_config-content_type
   - fixed_response_config.message_body: l7policy-fixed_response_config-message_body

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - project_id: path-project-id
   - admin_state_up: admin_state_up
   - action: l7policy-action
   - description: l7policy-description
   - listener_id: l7policy-listener_id
   - name: l7policy-name
   - position: l7policy-position
   - project_id: project_id
   - redirect_listener_id: l7policy-redirect_listener_id
   - redirect_pool_id: l7policy-redirect_pool_id
   - redirect_url: l7policy-redirect_url
   - priority: l7policy-priority
   - rules: l7policy-rules
   - redirect_url_config: l7policy-redirect_url_config
   - redirect_url_config.protocol: l7policy-redirect_url_config-protocol
   - redirect_url_config.host: l7policy-redirect_url_config-host
   - redirect_url_config.port: l7policy-redirect_url_config-port
   - redirect_url_config.path: l7policy-redirect_url_config-path
   - redirect_url_config.query: l7policy-redirect_url_config-query
   - redirect_url_config.status_code: l7policy-redirect_url_config-status_code
   - fixed_response_config: l7policy-fixed_response_config
   - fixed_response_config.status_code: l7policy-fixed_response_config-status_code
   - fixed_response_config.content_type: l7policy-fixed_response_config-content_type
   - fixed_response_config.message_body: l7policy-fixed_response_config-message_body

Rule Parameters
^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - admin_state_up: l7rule-admin_state_up
   - type: l7rule-type
   - compare_type: l7rule-compare_type
   - invert: l7rule-invert
   - key: l7rule-key
   - value: l7rule-value
   - conditions: l7rule-conditions
   - conditions.key: l7rule-conditions-key
   - conditions.value: l7rule-conditions-value

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/l7policy-update-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/l7policy-update-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Deleting a Forwarding Policy
============================

.. rest_method:: DELETE /v3/{project_id}/elb/l7policies/{policy_id}

This API is used to delete a forwarding policy.

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
   - policy_id: path-l7policy-id

Response Parameters
^^^^^^^^^^^^^^^^^^^

None

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/l7policy-delete-curl
   :language: bash

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.
