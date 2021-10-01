.. -*- rst -*-

Querying AZs
============

.. rest_method:: GET /v3/{project_id}/elb/availability-zones

This API is used to query all available AZs when you create a dedicated load balancer.

One set of AZs is returned. When you create a dedicated load balancer, you can select one or more AZs only in the set.

.. rest_status_code:: success ../http-status.yaml

   - 200

.. rest_status_code:: error ../http-status.yaml

   - 400
   - 401
   - 403
   - 404

Request
^^^^^^^

.. rest_parameters:: ./parameters.yaml

   - project_id: path-project-id

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: ./parameters.yaml

   - availability_zones: availability_zones
   - request_id: request_id
   - availability_zone.state: availability_zone-state
   - availability_zone.code: availability_zone-code

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/az-list-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/az-list-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.
