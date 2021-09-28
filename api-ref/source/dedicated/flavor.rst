=======
Flavors
=======

Querying Flavors
================

.. rest_method:: GET /v3/{project_id}/elb/flavors

This API is used to query all load balancer flavors that are available to a
specific user in a specific region.

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

Request
^^^^^^^

.. rest_parameters:: ./parameters.yaml

   - project_id: path-project-id
   - id: flavor-id-query
   - limit: limit
   - marker: marker
   - name: flavor-name-query
   - page_reverse: page-reverse
   - shared: flavor-shared-query

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: ./parameters.yaml

   - page_info: page_info
   - request_id: request_id
   - flavors: flavors
   - id: flavor-id
   - info: flavor-info
   - info.connection: flavor-info-connection
   - info.bandwidth: flavor-info-bandwidth
   - info.cps: flavor-info-cps
   - info.qps: flavor-info-qps
   - name: flavor-name
   - project_id: project_id
   - shared: flavor-shared
   - type: flavor-type

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/flavor-list-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^


.. literalinclude:: examples/flavors-list-response.json
   :language: javascript


Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Viewing Details of a Flavor
===========================

.. rest_method:: GET /v3/{project_id}/elb/flavors/{flavor_id}

This API is used to view details of a flavor.

This API can only be used to view the details of a flavor.

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
   - flavor_id: path-flavor-id

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: ./parameters.yaml

   - flavor: flavor
   - id: flavor-id
   - info: flavor-info
   - info.connection: flavor-info-connection
   - info.bandwidth: flavor-info-bandwidth
   - info.cps: flavor-info-cps
   - info.qps: flavor-info-qps
   - name: flavor-name
   - project_id: project_id
   - request_id: request_id
   - shared: flavor-shared
   - type: flavor-type


Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/flavor-show-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^


.. literalinclude:: examples/flavor-show-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.
