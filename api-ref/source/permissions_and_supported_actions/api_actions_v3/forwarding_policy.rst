:original_name: elb_sq_lb_v3_0006.html

.. _elb_sq_lb_v3_0006:

Forwarding Policy
=================

+------------------------------------------------------------+------------------------------------------------------------+-----------------------+------------------------------------------------------+
| API                                                        | API Function                                               | Action                | Authorization Scope                                  |
+============================================================+============================================================+=======================+======================================================+
| POST /v3/{project_id}/elb/l7policies                       | Adding a forwarding policy                                 | elb:l7policies:create | Both projects and enterprise projects are supported. |
+------------------------------------------------------------+------------------------------------------------------------+-----------------------+------------------------------------------------------+
| GET /v3/{project_id}/elb/l7policies/{l7policy_id}          | Querying a forwarding policy                               | elb:l7policies:get    | Both projects and enterprise projects are supported. |
+------------------------------------------------------------+------------------------------------------------------------+-----------------------+------------------------------------------------------+
| GET /v3/{project_id}/elb/l7policies                        | Querying forwarding policies                               | elb:l7policies:list   | Both projects and enterprise projects are supported. |
+------------------------------------------------------------+------------------------------------------------------------+-----------------------+------------------------------------------------------+
| PUT /v3/{project_id}/elb/l7policies/{l7policy_id}          | Modifying a forwarding policy                              | elb:l7policies:put    | Both projects and enterprise projects are supported. |
+------------------------------------------------------------+------------------------------------------------------------+-----------------------+------------------------------------------------------+
| DELETE /v3/{project_id}/elb/l7policies/{l7policy_id}       | Deleting a forwarding policy                               | elb:l7policies:delete | Both projects and enterprise projects are supported. |
+------------------------------------------------------------+------------------------------------------------------------+-----------------------+------------------------------------------------------+
| POST /v3/{project_id}/elb/l7policies/batch-update-priority | Modifying the priorities of forwarding policies in batches | elb:l7policies:put    | Both projects and enterprise projects are supported. |
+------------------------------------------------------------+------------------------------------------------------------+-----------------------+------------------------------------------------------+
