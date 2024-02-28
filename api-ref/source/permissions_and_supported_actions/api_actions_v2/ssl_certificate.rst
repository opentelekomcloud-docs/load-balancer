:original_name: elb_sq_lb_0009.html

.. _elb_sq_lb_0009:

SSL Certificate
===============

+--------------------------------------------------+-------------------------+-------------------------+-------------------------+
| API                                              | API Function            | Action                  | Authorization Scope     |
+==================================================+=========================+=========================+=========================+
| POST /v2.0/lbaas/certificates                    | Adding a certificate    | elb:certificates:create | Projects are supported. |
+--------------------------------------------------+-------------------------+-------------------------+-------------------------+
| GET /v2.0/lbaas/certificates                     | Querying certificates   | elb:certificates:list   | Projects are supported. |
+--------------------------------------------------+-------------------------+-------------------------+-------------------------+
| GET /v2.0/lbaas/certificates/{certificate_id}    | Querying a certificate  | elb:certificates:get    | Projects are supported. |
+--------------------------------------------------+-------------------------+-------------------------+-------------------------+
| PUT /v2.0/lbaas/certificates/{certificate_id}    | Modifying a certificate | elb:certificates:put    | Projects are supported. |
+--------------------------------------------------+-------------------------+-------------------------+-------------------------+
| DELETE /v2.0/lbaas/certificates/{certificate_id} | Deleting a certificate  | elb:certificates:delete | Projects are supported. |
+--------------------------------------------------+-------------------------+-------------------------+-------------------------+
