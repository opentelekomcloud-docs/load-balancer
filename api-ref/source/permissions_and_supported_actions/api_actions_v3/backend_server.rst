:original_name: elb_sq_lb_v3_0004.html

.. _elb_sq_lb_v3_0004:

Backend Server
==============

+-----------------------------------------------------------------+----------------------------+--------------------+------------------------------------------------------+
| API                                                             | API Function               | Action             | Authorization Scope                                  |
+=================================================================+============================+====================+======================================================+
| POST /v3/{project_id}/elb/pools/{pool_id}/members               | Adding a backend server    | elb:members:create | Both projects and enterprise projects are supported. |
+-----------------------------------------------------------------+----------------------------+--------------------+------------------------------------------------------+
| GET /v3/{project_id}/elb/pools/{pool_id}/members/{member_id}    | Querying a backend server  | elb:members:get    | Both projects and enterprise projects are supported. |
+-----------------------------------------------------------------+----------------------------+--------------------+------------------------------------------------------+
| GET /v3/{project_id}/elb/pools/{pool_id}/members                | Querying backend servers   | elb:members:list   | Both projects and enterprise projects are supported. |
+-----------------------------------------------------------------+----------------------------+--------------------+------------------------------------------------------+
| PUT /v3/{project_id}/elb/pools/{pool_id}/members/{member_id}    | Modifying a backend server | elb:members:put    | Both projects and enterprise projects are supported. |
+-----------------------------------------------------------------+----------------------------+--------------------+------------------------------------------------------+
| DELETE /v3/{project_id}/elb/pools/{pool_id}/members/{member_id} | Removing a backend server  | elb:members:delete | Both projects and enterprise projects are supported. |
+-----------------------------------------------------------------+----------------------------+--------------------+------------------------------------------------------+
