============
Health Check
============

Creating a Health Check
=======================

.. rest_method:: POST /v3/{project_id}/elb/healthmonitors

This API is used to configure a health check.

The security groups must have rules that allow access from 100.125.0.0/16. If
you want to use UDP for health checks, ensure that the protocol of the backend
server group is UDP.

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
   - admin_state_up: healthmonitor-admin_state_up-optional
   - delay: healthmonitor-delay
   - domain_name: healthmonitor-domain_name-optional
   - expected_codes: healthmonitor-expected_codes-optional
   - http_method: healthmonitor-http_method-optional
   - max_retries: healthmonitor-max_retries
   - max_retries_down: healthmonitor-max_retries_down-optional
   - monitor_port: healthmonitor-monitor_port-optional
   - name: healthmonitor-name-optional
   - pool_id: healthmonitor-pool_id
   - timeout: healthmonitor-timeout
   - type: healthmonitor-type
   - url_path: healthmonitor-url_path-optional

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - healthmonitor: healthmonitor
   - id: healthmonitor-id
   - admin_state_up: healthmonitor-admin_state_up
   - delay: healthmonitor-delay
   - domain_name: healthmonitor-domain_name
   - expected_codes: healthmonitor-expected_codes
   - http_method: healthmonitor-http_method
   - max_retries: healthmonitor-max_retries
   - max_retries_down: healthmonitor-max_retries_down
   - monitor_port: healthmonitor-monitor_port
   - name: healthmonitor-name
   - pools: healthmonitor-pools
   - pool.id: healthmonitor-pool_id
   - timeout: healthmonitor-timeout
   - type: healthmonitor-type
   - url_path: healthmonitor-url_path

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/hm-create-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/hm-create-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Listing Health Checks
=====================

.. rest_method:: GET /v3/{project_id}/elb/healthmonitors

This API is used to query all health checks.

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
   - id: healthmonitor-id-query
   - monitor_port: healthmonitor-monitor_port-query
   - domain_name: healthmonitor-domain_name-query
   - delay: healthmonitor-delay-query
   - max_retries: healthmonitor-max_retries-query
   - admin_state_up: healthmonitor-admin_state_up-query
   - max_retries_down: healthmonitor-max_retries_down-query
   - timeout: healthmonitor-timeout-query
   - type: healthmonitor-type-query
   - expected_codes: healthmonitor-expected_codes-query
   - url_path: healthmonitor-url_path-query
   - http_method: healthmonitor-http_method-query

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - page_info: page_info
   - request_id: request_id
   - healthmonitors: healthmonitors
   - id: healthmonitor-id
   - admin_state_up: admin_state_up
   - delay: healthmonitor-delay
   - domain_name: healthmonitor-domain_name
   - expected_codes: healthmonitor-expected_codes
   - http_method: healthmonitor-http_method
   - max_retries: healthmonitor-max_retries
   - max_retries_down: healthmonitor-max_retries_down
   - monitor_port: healthmonitor-monitor_port
   - name: healthmonitor-name
   - pools: healthmonitor-pools
   - pool.id: healthmonitor-pool_id
   - timeout: healthmonitor-timeout
   - type: healthmonitor-type
   - url_path: healthmonitor-url_path

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/hm-list-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/hm-list-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Viewing Details of a Health Check
=================================

.. rest_method:: GET /v3/{project_id}/elb/healthmonitors/{healthmonitor_id}

This API is used to view details of a health check.

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
   - healthmonitor_id: path-healthmonitor-id

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - request_id: request_id
   - healthmonitor: healthmonitor
   - id: healthmonitor-id
   - admin_state_up: healthmonitor-admin_state_up
   - delay: healthmonitor-delay
   - domain_name: healthmonitor-domain_name
   - expected_codes: healthmonitor-expected_codes
   - http_method: healthmonitor-http_method
   - max_retries: healthmonitor-max_retries
   - max_retries_down: healthmonitor-max_retries_down
   - monitor_port: healthmonitor-monitor_port
   - name: healthmonitor-name
   - pools: healthmonitor-pools
   - pool.id: healthmonitor-pool_id
   - timeout: healthmonitor-timeout
   - type: healthmonitor-type
   - url_path: healthmonitor-url_path

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/hm-show-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/hm-show-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Updating a Health Check
=======================

.. rest_method:: PUT /v3/{project_id}/elb/healthmonitors/{healthmonitor_id}

This API is used to update a health check.

The health check can be updated only when the provisioning status of the
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
   - healthmonitor_id: path-healthmonitor-id
   - admin_state_up: healthmonitor-admin_state_up-optional
   - delay: healthmonitor-delay-optional
   - domain_name: healthmonitor-domain_name-optional
   - expected_codes: healthmonitor-expected_codes-optional
   - http_method: healthmonitor-http_method-optional
   - max_retries: healthmonitor-max_retries-optional
   - max_retries_down: healthmonitor-max_retries_down-optional
   - monitor_port: healthmonitor-monitor_port-optional
   - name: healthmonitor-name-optional
   - timeout: healthmonitor-timeout-optional
   - type: healthmonitor-type-optional
   - url_path: healthmonitor-url_path-optional

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - healthmonitor: healthmonitor
   - id: healthmonitor-id
   - admin_state_up: healthmonitor-admin_state_up
   - delay: healthmonitor-delay
   - domain_name: healthmonitor-domain_name
   - expected_codes: healthmonitor-expected_codes
   - http_method: healthmonitor-http_method
   - max_retries: healthmonitor-max_retries
   - max_retries_down: healthmonitor-max_retries_down
   - monitor_port: healthmonitor-monitor_port
   - name: healthmonitor-name
   - pools: healthmonitor-pools
   - pool.id: healthmonitor-pool_id
   - timeout: healthmonitor-timeout
   - type: healthmonitor-type
   - url_path: healthmonitor-url_path

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/hm-update-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/hm-update-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Deleting a Health Check
=======================

.. rest_method:: DELETE /v3/{project_id}/elb/healthmonitors/{healthmonitor_id}

This API is used to delete a health check.

The health check can be deleted only when the provisioning status of the
associated load balancer is **ACTIVE**.

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
   - healthmonitor_id: path-healthmonitor-id

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
