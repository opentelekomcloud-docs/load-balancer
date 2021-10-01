.. -*- rst -*-

Creating a Certificate
======================

.. rest_method:: POST /v3/{project_id}/elb/certificates

This API is used to create an SSL certificate.

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
   - admin_state_up: admin_state_up-notsupported
   - certificate: certificate-certificate
   - description: certificate-description-optional
   - domain: certificate-domain-optional
   - name: certificate-name-optional
   - private_key: certificate-private_key-optional
   - type: certificate-type-optional

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - project_id: project_id
   - admin_state_up: admin_state_up-notsupported
   - certificate: certificate-certificate
   - description: certificate-description
   - domain: certificate-domain
   - id: id
   - name: certificate-name
   - private_key: certificate-private_key
   - type: certificate-type
   - created_at: created_at
   - updated_at: updated_at
   - expire_time: certificate-expire_time

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/cert-create-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/cert-create-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Listing Certificates
====================

.. rest_method:: GET /v3/{project_id}/elb/certificates

This API is used to query all SSL certificates.

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
   - id: id-query
   - name: name-query
   - description: description-query
   - admin_state_up: admin_state_up-unsupported-query
   - domain: certificate-domain-query
   - type: certificate-type-query

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - page_info: page_info
   - request_id: request_id
   - certificates: certificates
   - project_id: project_id
   - admin_state_up: admin_state_up-notsupported
   - certificate: certificate-certificate
   - description: certificate-description
   - domain: certificate-domain
   - id: id
   - name: certificate-name
   - private_key: certificate-private_key
   - type: certificate-type
   - created_at: created_at
   - updated_at: updated_at
   - expire_time: certificate-expire_time

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/cert-list-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/cert-list-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Viewing Details of a Certificate
================================

.. rest_method:: GET /v3/{project_id}/elb/certificates/{certificate_id}

This API is used to view details of an SSL certificate.

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
   - certificate_id: path-certificate-id

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - project_id: project_id
   - admin_state_up: admin_state_up-notsupported
   - certificate: certificate-certificate
   - description: certificate-description
   - domain: certificate-domain
   - id: id
   - name: certificate-name
   - private_key: certificate-private_key
   - type: certificate-type
   - created_at: created_at
   - updated_at: updated_at
   - expire_time: certificate-expire_time

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/cert-show-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/cert-show-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Updating a Certificate
======================

.. rest_method:: PUT /v3/{project_id}/elb/certificates/{certificate_id}

This API is used to update an SSL certificate.

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
   - certificate_id: path-certificate-id
   - certificate: certificate-certificate
   - description: certificate-description-optional
   - name: certificate-name-optional
   - private_key: certificate-private_key-optional
   - domain: certificate-domain-optional

Response Parameters
^^^^^^^^^^^^^^^^^^^

.. rest_parameters:: parameters.yaml

   - project_id: project_id
   - admin_state_up: admin_state_up-notsupported
   - certificate: certificate-certificate
   - description: certificate-description
   - domain: certificate-domain
   - id: id
   - name: certificate-name
   - private_key: certificate-private_key
   - type: certificate-type
   - created_at: created_at
   - updated_at: updated_at
   - expire_time: certificate-expire_time

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/cert-create-curl
   :language: bash

Example Responses
^^^^^^^^^^^^^^^^^

.. literalinclude:: examples/cert-create-response.json
   :language: javascript

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Deleting a Certificate
======================

.. rest_method:: DELETE /v3/{project_id}/elb/certificates/{certificate_id}

This API is used to delete an SSL certificate.

If the certificate is used by a listener, the certificate cannot be deleted,
and the 409 Conflict error code will be displayed.

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
   - certificate_id: path-certificate-id

Example Requests
^^^^^^^^^^^^^^^^

.. literalinclude:: examples/cert-delete-curl
   :language: bash

Response Parameters
^^^^^^^^^^^^^^^^^^^

None

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.
