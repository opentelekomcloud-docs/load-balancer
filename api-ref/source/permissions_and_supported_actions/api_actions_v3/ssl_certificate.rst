:original_name: elb_sq_lb_v3_0009.html

.. _elb_sq_lb_v3_0009:

SSL Certificate
===============

+-----------------------------------------------------------+-------------------------+-------------------------+------------------------------------------------------+
| API                                                       | API Function            | Action                  | Authorization Scope                                  |
+===========================================================+=========================+=========================+======================================================+
| POST /v3/{project_id}/elb/certificates                    | Adding a certificate    | elb:certificates:create | Both projects and enterprise projects are supported. |
+-----------------------------------------------------------+-------------------------+-------------------------+------------------------------------------------------+
| GET /v3/{project_id}/elb/certificates/{certificate_id}    | Querying a certificate  | elb:certificates:get    | Both projects and enterprise projects are supported. |
+-----------------------------------------------------------+-------------------------+-------------------------+------------------------------------------------------+
| GET /v3/{project_id}/elb/certificates                     | Querying certificates   | elb:certificates:list   | Both projects and enterprise projects are supported. |
+-----------------------------------------------------------+-------------------------+-------------------------+------------------------------------------------------+
| PUT /v3/{project_id}/elb/certificates/{certificate_id}    | Modifying a certificate | elb:certificates:put    | Both projects and enterprise projects are supported. |
+-----------------------------------------------------------+-------------------------+-------------------------+------------------------------------------------------+
| DELETE /v3/{project_id}/elb/certificates/{certificate_id} | Deleting a certificate  | elb:certificates:delete | Both projects and enterprise projects are supported. |
+-----------------------------------------------------------+-------------------------+-------------------------+------------------------------------------------------+
