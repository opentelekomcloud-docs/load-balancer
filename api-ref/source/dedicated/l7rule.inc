.. -*- rst -*-

Adding a Forwarding Rule
========================

.. rest_method:: POST /v3/{project_id}/elb/l7policies/{l7policy_id}/rules

This API is used to add a forwarding rule.

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
   - l7policy_id: path-l7policy-id
   - rule: l7rule
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

   - project_id: project_id
   - rule: l7rule
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

.. literalinclude:: examples/l7rule-create-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/l7rule-create-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Listing Forwarding Rules
=========================

.. rest_method:: GET /v3/{project_id}/elb/l7policies/{l7policy_id}/rules

This API is used to query all forwarding rules.

Parameters **marker**, **limit**, and **page_reverse** are used for pagination
query.

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
   - l7policy_id: path-l7policy-id
   - marker: marker
   - limit: limit
   - page_reverse: page-reverse
   - id: l7rule-id-query
   - compare_type: l7rule-compare_type-query
   - provisioning_status: l7rule-provisioning_status-query
   - invert: l7rule-invert-query
   - admin_state_up: l7rule-admin_state_up-query
   - key: l7rule-key-query
   - value: l7rule-value-query
   - type: l7rule-type-query

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - page_info: page_info
   - request_id: request_id
   - rules: l7rules
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

.. literalinclude:: examples/l7rule-list-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/l7rule-list-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Viewing Details of a Forwarding Rule
====================================

.. rest_method:: GET /v3/{project_id}/elb/l7policies/{l7policy_id}/rules/{l7rule_id}

This API is used to view details of a forwarding rule.

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
   - l7policy_id: path-l7policy-id
   - l7rule_id: path-l7rule-id

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - project_id: project_id
   - rule: l7rule
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

.. literalinclude:: examples/l7rule-show-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/l7rule-show-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Updating a Forwarding Rule
==========================

.. rest_method:: PUT /v3/{project_id}/elb/l7policies/{l7policy_id}/rules/{l7rule_id}

This API is used to update a forwarding rule.

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
   - l7rule_id: path-l7rule-id
   - l7policy_id: path-l7policy-id
   - rule: l7rule
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

   - project_id: project_id
   - rule: l7rule
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

.. literalinclude:: examples/l7rule-update-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/l7rule-update-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Deleting a Forwarding Rule
==========================

.. rest_method:: DELETE /v3/{project_id}/elb/l7policies/{l7policy_id}/rules/{l7rule_id}

This API is used to delete a forwarding rule.

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
   - l7policy_id: path-l7policy-id
   - l7rule_id: path-l7rule-id

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/l7rule-delete-curl
   :language: bash

Response Parameters
^^^^^^^^^^^^^^^^^^^

None

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.
