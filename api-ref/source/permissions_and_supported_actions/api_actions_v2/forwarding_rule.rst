:original_name: elb_sq_lb_0007.html

.. _elb_sq_lb_0007:

Forwarding Rule
===============

+-------------------------------------------------------------+-----------------------------+--------------------+-------------------------+
| API                                                         | API Function                | Action             | Authorization Scope     |
+=============================================================+=============================+====================+=========================+
| POST /v2.0/lbaas/l7policies/{l7policy_id}/rules             | Adding a forwarding rule    | elb:l7rules:create | Projects are supported. |
+-------------------------------------------------------------+-----------------------------+--------------------+-------------------------+
| GET /v2.0/lbaas/l7policies/{l7policy_id}/rules              | Querying forwarding rules   | elb:l7rules:list   | Projects are supported. |
+-------------------------------------------------------------+-----------------------------+--------------------+-------------------------+
| GET /v2.0/lbaas/l7policies/{l7policy_id}/rules/{rule_id}    | Querying a forwarding rule  | elb:l7rules:get    | Projects are supported. |
+-------------------------------------------------------------+-----------------------------+--------------------+-------------------------+
| PUT /v2.0/lbaas/l7policies/{l7policy_id}/rules/{rule_id}    | Modifying a forwarding rule | elb:l7rules:put    | Projects are supported. |
+-------------------------------------------------------------+-----------------------------+--------------------+-------------------------+
| DELETE /v2.0/lbaas/l7policies/{l7policy_id}/rules/{rule_id} | Deleting a forwarding rule  | elb:l7rules:delete | Projects are supported. |
+-------------------------------------------------------------+-----------------------------+--------------------+-------------------------+
