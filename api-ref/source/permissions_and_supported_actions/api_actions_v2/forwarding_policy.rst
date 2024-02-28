:original_name: elb_sq_lb_0006.html

.. _elb_sq_lb_0006:

Forwarding Policy
=================

+---------------------------------------------+-------------------------------+-----------------------+-------------------------+
| API                                         | API Function                  | Action                | Authorization Scope     |
+=============================================+===============================+=======================+=========================+
| POST /v2.0/lbaas/l7policies                 | Adding a forwarding policy    | elb:l7policies:create | Projects are supported. |
+---------------------------------------------+-------------------------------+-----------------------+-------------------------+
| GET /v2.0/lbaas/l7policies                  | Querying forwarding policies  | elb:l7policies:list   | Projects are supported. |
+---------------------------------------------+-------------------------------+-----------------------+-------------------------+
| GET /v2.0/lbaas/l7policies/{l7policy_id}    | Querying a forwarding policy  | elb:l7policies:get    | Projects are supported. |
+---------------------------------------------+-------------------------------+-----------------------+-------------------------+
| PUT /v2.0/lbaas/l7policies/{l7policy_id}    | Modifying a forwarding policy | elb:l7policies:put    | Projects are supported. |
+---------------------------------------------+-------------------------------+-----------------------+-------------------------+
| DELETE /v2.0/lbaas/l7policies/{l7policy_id} | Deleting a forwarding policy  | elb:l7policies:delete | Projects are supported. |
+---------------------------------------------+-------------------------------+-----------------------+-------------------------+
