:original_name: elb_sq_lb_v3_0005.html

.. _elb_sq_lb_v3_0005:

Health Check
============

+---------------------------------------------------------------+----------------------------+---------------------------+------------------------------------------------------+
| API                                                           | API Function               | Action                    | Authorization Scope                                  |
+===============================================================+============================+===========================+======================================================+
| POST /v3/{project_id}/elb/healthmonitors                      | Configuring a health check | elb:healthmonitors:create | Both projects and enterprise projects are supported. |
+---------------------------------------------------------------+----------------------------+---------------------------+------------------------------------------------------+
| GET /v3/{project_id}/elb/healthmonitors/{healthmonitor_id}    | Querying a health check    | elb:healthmonitors:get    | Both projects and enterprise projects are supported. |
+---------------------------------------------------------------+----------------------------+---------------------------+------------------------------------------------------+
| GET /v3/{project_id}/elb/healthmonitors                       | Querying health checks     | elb:healthmonitors:list   | Both projects and enterprise projects are supported. |
+---------------------------------------------------------------+----------------------------+---------------------------+------------------------------------------------------+
| PUT /v3/{project_id}/elb/healthmonitors/{healthmonitor_id}    | Modifying a health check   | elb:healthmonitors:put    | Both projects and enterprise projects are supported. |
+---------------------------------------------------------------+----------------------------+---------------------------+------------------------------------------------------+
| DELETE /v3/{project_id}/elb/healthmonitors/{healthmonitor_id} | Deleting a health check    | elb:healthmonitor:delete  | Both projects and enterprise projects are supported. |
+---------------------------------------------------------------+----------------------------+---------------------------+------------------------------------------------------+
