:original_name: elb_sq_lb_0001.html

.. _elb_sq_lb_0001:

Load Balancer
=============

+----------------------------------------------------------+---------------------------------------------+--------------------------+-------------------------+
| API                                                      | API Function                                | Action                   | Authorization Scope     |
+==========================================================+=============================================+==========================+=========================+
| POST /v2.0/lbaas/loadbalancers                           | Creating a load balancer                    | elb:loadbalancers:create | Projects are supported. |
+----------------------------------------------------------+---------------------------------------------+--------------------------+-------------------------+
| GET /v2.0/lbaas/loadbalancers                            | Querying load balancers                     | elb:loadbalancers:list   | Projects are supported. |
+----------------------------------------------------------+---------------------------------------------+--------------------------+-------------------------+
| GET /v2.0/lbaas/loadbalancers/{loadbalancer_id}          | Querying a load balancer                    | elb:loadbalancers:get    | Projects are supported. |
+----------------------------------------------------------+---------------------------------------------+--------------------------+-------------------------+
| PUT /v2.0/lbaas/loadbalancers/{loadbalancer_id}          | Updating a load balancer                    | elb:loadbalancers:put    | Projects are supported. |
+----------------------------------------------------------+---------------------------------------------+--------------------------+-------------------------+
| DELETE /v2.0/lbaas/loadbalancers/{loadbalancer_id}       | Deleting a load balancer                    | elb:loadbalancers:delete | Projects are supported. |
+----------------------------------------------------------+---------------------------------------------+--------------------------+-------------------------+
| GET /v2.0/lbaas/loadbalancers/{loadbalancer_id}/statuses | Querying the status tree of a load balancer | elb:loadbalancers:get    | Projects are supported. |
+----------------------------------------------------------+---------------------------------------------+--------------------------+-------------------------+
