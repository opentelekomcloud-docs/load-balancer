:original_name: elb_sq_lb_0004.html

.. _elb_sq_lb_0004:

Backend Server
==============

+--------------------------------------------------------+--------------------------------------+--------------------+-------------------------+
| API                                                    | API Function                         | Action             | Authorization Scope     |
+========================================================+======================================+====================+=========================+
| POST /v2.0/lbaas/pools/{pool_id}/members               | Adding a backend server              | elb:members:create | Projects are supported. |
+--------------------------------------------------------+--------------------------------------+--------------------+-------------------------+
| GET /v2.0/lbaas/pools/{pool_id}/members                | Querying backend servers             | elb:members:list   | Projects are supported. |
+--------------------------------------------------------+--------------------------------------+--------------------+-------------------------+
| GET /v2.0/lbaas/pools/{pool_id}/members/{member_id}    | Querying a backend server            | elb:members:get    | Projects are supported. |
+--------------------------------------------------------+--------------------------------------+--------------------+-------------------------+
| PUT /v2.0/lbaas/pools/{pool_id}/members/{member_id}    | Modifying a backend server           | elb:members:put    | Projects are supported. |
+--------------------------------------------------------+--------------------------------------+--------------------+-------------------------+
| DELETE /v2.0/lbaas/pools/{pool_id}/members/{member_id} | Removing a backend server            | elb:members:delete | Projects are supported. |
+--------------------------------------------------------+--------------------------------------+--------------------+-------------------------+
| GET /v2.0/lbaas/members                                | Querying backend servers             | elb:members:list   | Projects are supported. |
+--------------------------------------------------------+--------------------------------------+--------------------+-------------------------+
| PUT /v2.0/lbaas/pools/{pool_id}/members                | Modifying backend servers in batches | elb:members:put    | Projects are supported. |
+--------------------------------------------------------+--------------------------------------+--------------------+-------------------------+
