:original_name: elb_sq_lb_0005.html

.. _elb_sq_lb_0005:

Health Check
============

+----------------------------------------------------+----------------------------+---------------------------+-------------------------+
| API                                                | API Function               | Action                    | Authorization Scope     |
+====================================================+============================+===========================+=========================+
| POST /v2.0/lbaas/healthmonitors                    | Configuring a health check | elb:healthmonitors:create | Projects are supported. |
+----------------------------------------------------+----------------------------+---------------------------+-------------------------+
| GET /v2.0/lbaas/healthmonitors                     | Querying health checks     | elb:healthmonitors:list   | Projects are supported. |
+----------------------------------------------------+----------------------------+---------------------------+-------------------------+
| GET /v2.0/lbaas/healthmonitors/{healthmonitors}    | Querying a health check    | elb:healthmonitors:get    | Projects are supported. |
+----------------------------------------------------+----------------------------+---------------------------+-------------------------+
| PUT /v2.0/lbaas/healthmonitors/{healthmonitors}    | Modifying a health check   | elb:healthmonitors:put    | Projects are supported. |
+----------------------------------------------------+----------------------------+---------------------------+-------------------------+
| DELETE /v2.0/lbaas/healthmonitors/{healthmonitors} | Disabling a health check   | elb:healthmonitor:delete  | Projects are supported. |
+----------------------------------------------------+----------------------------+---------------------------+-------------------------+
