:original_name: elb_sq_lb_v3_0001.html

.. _elb_sq_lb_v3_0001:

Load Balancer
=============

+-------------------------------------------------------------------+---------------------------------------------+--------------------------+------------------------------------------------------+
| API                                                               | API Function                                | Action                   | Authorization Scope                                  |
+===================================================================+=============================================+==========================+======================================================+
| POST /v3/{project_id}/elb/loadbalancers                           | Creating a load balancer                    | elb:loadbalancers:create | Both projects and enterprise projects are supported. |
+-------------------------------------------------------------------+---------------------------------------------+--------------------------+------------------------------------------------------+
| GET /v3/{project_id}/elb/loadbalancers/{loadbalancer_id}          | Querying a load balancer                    | elb:loadbalancers:get    | Both projects and enterprise projects are supported. |
+-------------------------------------------------------------------+---------------------------------------------+--------------------------+------------------------------------------------------+
| GET /v3/{project_id}/elb/loadbalancers                            | Querying load balancers                     | elb:loadbalancers:list   | Both projects and enterprise projects are supported. |
+-------------------------------------------------------------------+---------------------------------------------+--------------------------+------------------------------------------------------+
| PUT /v3/{project_id}/elb/loadbalancers/{loadbalancer_id}          | Updating a load balancer                    | elb:loadbalancers:put    | Both projects and enterprise projects are supported. |
+-------------------------------------------------------------------+---------------------------------------------+--------------------------+------------------------------------------------------+
| DELETE /v3/{project_id}/elb/loadbalancers/{loadbalancer_id}       | Deleting a load balancer                    | elb:loadbalancers:delete | Both projects and enterprise projects are supported. |
+-------------------------------------------------------------------+---------------------------------------------+--------------------------+------------------------------------------------------+
| GET /v3/{project_id}/elb/loadbalancers/{loadbalancer_id}/statuses | Querying the status tree of a load balancer | elb:loadbalancers:get    | Both projects and enterprise projects are supported. |
+-------------------------------------------------------------------+---------------------------------------------+--------------------------+------------------------------------------------------+
