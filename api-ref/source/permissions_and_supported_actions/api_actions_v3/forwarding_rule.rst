:original_name: elb_sq_lb_v3_0007.html

.. _elb_sq_lb_v3_0007:

Forwarding Rule
===============

+------------------------------------------------------------------------+----------------------------+--------------------+------------------------------------------------------+
| API                                                                    | API Function               | Action             | Authorization Scope                                  |
+========================================================================+============================+====================+======================================================+
| POST /v3/{project_id}/elb/l7policies/{l7policy_id}/rules               | Creating a forwarding rule | elb:l7rules:create | Both projects and enterprise projects are supported. |
+------------------------------------------------------------------------+----------------------------+--------------------+------------------------------------------------------+
| GET /v3/{project_id}/elb/l7policies/{l7policy_id}/rules/{l7rule_id}    | Querying a forwarding rule | elb:l7rules:get    | Both projects and enterprise projects are supported. |
+------------------------------------------------------------------------+----------------------------+--------------------+------------------------------------------------------+
| GET /v3/{project_id}/elb/l7policies/{l7policy_id}/rules                | Querying forwarding rules  | elb:l7rules:list   | Both projects and enterprise projects are supported. |
+------------------------------------------------------------------------+----------------------------+--------------------+------------------------------------------------------+
| PUT /v3/{project_id}/elb/l7policies/{l7policy_id}/rules/{l7rule_id}    | Updating a forwarding rule | elb:l7rules:put    | Both projects and enterprise projects are supported. |
+------------------------------------------------------------------------+----------------------------+--------------------+------------------------------------------------------+
| DELETE /v3/{project_id}/elb/l7policies/{l7policy_id}/rules/{l7rule_id} | Deleting a forwarding rule | elb:l7rules:delete | Both projects and enterprise projects are supported. |
+------------------------------------------------------------------------+----------------------------+--------------------+------------------------------------------------------+
