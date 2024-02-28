:original_name: elb_sq_lb_v3_0002.html

.. _elb_sq_lb_v3_0002:

Listener
========

+-----------------------------------------------------+----------------------+----------------------+------------------------------------------------------+
| API                                                 | API Function         | Action               | Authorization Scope                                  |
+=====================================================+======================+======================+======================================================+
| POST /v3/{project_id}/elb/listeners                 | Adding a listener    | elb:listeners:create | Both projects and enterprise projects are supported. |
+-----------------------------------------------------+----------------------+----------------------+------------------------------------------------------+
| GET /v3/{project_id}/elb/listeners/{listener_id}    | Querying a listener  | elb:listeners:get    | Both projects and enterprise projects are supported. |
+-----------------------------------------------------+----------------------+----------------------+------------------------------------------------------+
| GET /v3/{project_id}/elb/listeners                  | Querying listeners   | elb:listeners:list   | Both projects and enterprise projects are supported. |
+-----------------------------------------------------+----------------------+----------------------+------------------------------------------------------+
| PUT /v3/{project_id}/elb/listeners/{listener_id}    | Modifying a listener | elb:listeners:put    | Both projects and enterprise projects are supported. |
+-----------------------------------------------------+----------------------+----------------------+------------------------------------------------------+
| DELETE /v3/{project_id}/elb/listeners/{listener_id} | Deleting a listener  | elb:listeners:delete | Both projects and enterprise projects are supported. |
+-----------------------------------------------------+----------------------+----------------------+------------------------------------------------------+
