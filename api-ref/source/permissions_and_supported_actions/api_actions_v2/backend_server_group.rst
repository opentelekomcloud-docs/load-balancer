:original_name: elb_sq_lb_0003.html

.. _elb_sq_lb_0003:

Backend Server Group
====================

+------------------------------------+----------------------------------+------------------+-------------------------+
| API                                | API Function                     | Action           | Authorization Scope     |
+====================================+==================================+==================+=========================+
| POST /v2.0/lbaas/pools             | Creating a backend server group  | elb:pools:create | Projects are supported. |
+------------------------------------+----------------------------------+------------------+-------------------------+
| GET /v2.0/lbaas/pools              | Querying backend server groups   | elb:pools:list   | Projects are supported. |
+------------------------------------+----------------------------------+------------------+-------------------------+
| GET /v2.0/lbaas/pools/{pool_id}    | Querying a backend server group  | elb:pools:get    | Projects are supported. |
+------------------------------------+----------------------------------+------------------+-------------------------+
| PUT /v2.0/lbaas/pools/{pool_id}    | Modifying a backend server group | elb:pools:put    | Projects are supported. |
+------------------------------------+----------------------------------+------------------+-------------------------+
| DELETE /v2.0/lbaas/pools/{pool_id} | Deleting a backend server group  | elb:pools:delete | Projects are supported. |
+------------------------------------+----------------------------------+------------------+-------------------------+
