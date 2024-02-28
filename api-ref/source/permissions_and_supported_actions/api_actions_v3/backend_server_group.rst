:original_name: elb_sq_lb_v3_0003.html

.. _elb_sq_lb_v3_0003:

Backend Server Group
====================

+---------------------------------------------+----------------------------------+------------------+------------------------------------------------------+
| API                                         | API Function                     | Action           | Authorization Scope                                  |
+=============================================+==================================+==================+======================================================+
| POST /v3/{project_id}/elb/pools             | Creating a backend server group  | elb:pools:create | Both projects and enterprise projects are supported. |
+---------------------------------------------+----------------------------------+------------------+------------------------------------------------------+
| GET /v3/{project_id}/elb/pools/{pool_id}    | Querying a backend server group  | elb:pools:get    | Both projects and enterprise projects are supported. |
+---------------------------------------------+----------------------------------+------------------+------------------------------------------------------+
| GET /v3/{project_id}/elb/pools              | Querying backend server groups   | elb:pools:list   | Both projects and enterprise projects are supported. |
+---------------------------------------------+----------------------------------+------------------+------------------------------------------------------+
| PUT /v3/{project_id}/elb/pools/{pool_id}    | Modifying a backend server group | elb:pools:put    | Both projects and enterprise projects are supported. |
+---------------------------------------------+----------------------------------+------------------+------------------------------------------------------+
| DELETE /v3/{project_id}/elb/pools/{pool_id} | Deleting a backend server group  | elb:pools:delete | Both projects and enterprise projects are supported. |
+---------------------------------------------+----------------------------------+------------------+------------------------------------------------------+
