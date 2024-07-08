:original_name: en-us_topic_0000001929387249.html

.. _en-us_topic_0000001929387249:

Log
===

+---------------------------------------------------+------------------------------+---------------------+------------------------------------------------------+
| API                                               | API Function                 | Action              | Authorization Scope                                  |
+===================================================+==============================+=====================+======================================================+
| POST /v3/{project_id}/elb/logtanks                | Creating a log               | elb:logtanks:create | Both projects and enterprise projects are supported. |
+---------------------------------------------------+------------------------------+---------------------+------------------------------------------------------+
| GET /v3/{project_id}/elb/logtanks/{logtank_id}    | Viewing the details of a log | elb:logtanks:get    | Both projects and enterprise projects are supported. |
+---------------------------------------------------+------------------------------+---------------------+------------------------------------------------------+
| GET /v3/{project_id}/elb/logtanks                 | Querying logs                | elb:logtanks:list   | Both projects and enterprise projects are supported. |
+---------------------------------------------------+------------------------------+---------------------+------------------------------------------------------+
| PUT /v3/{project_id}/elb/logtanks/{logtank_id}    | Updating a log               | elb:logtanks:put    | Both projects and enterprise projects are supported. |
+---------------------------------------------------+------------------------------+---------------------+------------------------------------------------------+
| DELETE /v3/{project_id}/elb/logtanks/{logtank_id} | Deleting a log               | elb:logtanks:delete | Both projects and enterprise projects are supported. |
+---------------------------------------------------+------------------------------+---------------------+------------------------------------------------------+
