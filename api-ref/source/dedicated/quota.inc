.. -*- rst -*-

Querying Quotas
===============

.. rest_method:: GET /v3/{project_id}/elb/quotas

This API is used to query resource quotas of a specific user.

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

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - certificate: quota-certificate
   - healthmonitor: quota-healthmonitor
   - l7policy: quota-l7policy
   - listener: quota-listener
   - loadbalancer: quota-loadbalancer
   - member: quota-member
   - members_per_pool: quota-members_per_pool
   - pool: quota-pool
   - ipgroup: quota-ipgroup
   - project_id: project_id

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/quota-list-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/quota-list-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.
