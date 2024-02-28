:original_name: elb_sq_lb_0002.html

.. _elb_sq_lb_0002:

Listener
========

+--------------------------------------------+----------------------+----------------------+-------------------------+
| API                                        | API Function         | Action               | Authorization Scope     |
+============================================+======================+======================+=========================+
| POST /v2.0/lbaas/listeners                 | Adding a listener    | elb:listeners:create | Projects are supported. |
+--------------------------------------------+----------------------+----------------------+-------------------------+
| GET /v2.0/lbaas/listeners                  | Querying listeners   | elb:listeners:list   | Projects are supported. |
+--------------------------------------------+----------------------+----------------------+-------------------------+
| GET /v2.0/lbaas/listeners/{listener_id}    | Querying a listener  | elb:listeners:get    | Projects are supported. |
+--------------------------------------------+----------------------+----------------------+-------------------------+
| PUT /v2.0/lbaas/listeners/{listener_id}    | Modifying a listener | elb:listeners:put    | Projects are supported. |
+--------------------------------------------+----------------------+----------------------+-------------------------+
| DELETE /v2.0/lbaas/listeners/{listener_id} | Deleting a listener  | elb:listeners:delete | Projects are supported. |
+--------------------------------------------+----------------------+----------------------+-------------------------+
