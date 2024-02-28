:original_name: elb_sq_lb_0010.html

.. _elb_sq_lb_0010:

Tag
===

+----------------------------------------------------------------------+-----------------------------------------------------------------+-----------------------------+-------------------------+
| API                                                                  | API Function                                                    | Action                      | Authorization Scope     |
+======================================================================+=================================================================+=============================+=========================+
| GET /v2.0/{project_id}/loadbalancers/{loadbalancer_id}/tags          | Querying all tags of a load balancer                            | elb:loadbalancerTags:get    | Projects are supported. |
+----------------------------------------------------------------------+-----------------------------------------------------------------+-----------------------------+-------------------------+
| POST /v2.0/{project_id}/loadbalancers/{loadbalancer_id}/tags/action  | Adding tags to or deleting tags from a load balancer in batches | elb:loadbalancerTags:create | Projects are supported. |
+----------------------------------------------------------------------+-----------------------------------------------------------------+-----------------------------+-------------------------+
| GET /v2.0/{project_id}/loadbalancers/tags                            | Querying tags of all load balancers in a specific project       | elb:loadbalancerTags:get    | Projects are supported. |
+----------------------------------------------------------------------+-----------------------------------------------------------------+-----------------------------+-------------------------+
| POST /v2.0/{project_id}/loadbalancers/resource_instances/action      | Querying load balancers by tag                                  | elb:loadbalancerTags:get    | Projects are supported. |
+----------------------------------------------------------------------+-----------------------------------------------------------------+-----------------------------+-------------------------+
| POST /v2.0/{project_id}/loadbalancers/{loadbalancer_id}/tags         | Adding a tag to a specific load balancer                        | elb:loadbalancerTags:create | Projects are supported. |
+----------------------------------------------------------------------+-----------------------------------------------------------------+-----------------------------+-------------------------+
| DELETE /v2.0/{project_id}/loadbalancers/{loadbalancer_id}/tags/{key} | Deleting a tag with a specific key from a load balancer         | elb:loadbalancerTags:delete | Projects are supported. |
+----------------------------------------------------------------------+-----------------------------------------------------------------+-----------------------------+-------------------------+
| GET /v2.0/{project_id}/listeners/{listener_id}/tags                  | Querying all tags of a listener                                 | elb:listenerTags:get        | Projects are supported. |
+----------------------------------------------------------------------+-----------------------------------------------------------------+-----------------------------+-------------------------+
| POST /v2.0/{project_id}/listeners/{listener_id}/tags/action          | Adding or deleting listener tags in batches                     | elb:listenerTags:create     | Projects are supported. |
+----------------------------------------------------------------------+-----------------------------------------------------------------+-----------------------------+-------------------------+
| GET /v2.0/{project_id}/listeners/tags                                | Querying the tags of all listeners                              | elb:listenerTags:get        | Projects are supported. |
+----------------------------------------------------------------------+-----------------------------------------------------------------+-----------------------------+-------------------------+
| POST /v2.0/{project_id}/listeners/resource_instances/action          | Querying listeners by tag                                       | elb:listenerTags:get        | Projects are supported. |
+----------------------------------------------------------------------+-----------------------------------------------------------------+-----------------------------+-------------------------+
| POST /v2.0/{project_id}/listeners/{listener_id}/tags                 | Adding a tag to a specific listener                             | elb:listenerTags:create     | Projects are supported. |
+----------------------------------------------------------------------+-----------------------------------------------------------------+-----------------------------+-------------------------+
| DELETE /v2.0/{project_id}/listeners/{listener_id}/tags/{key}         | Deleting a tag with a specific key from a listener              | elb:listenerTags:delete     | Projects are supported. |
+----------------------------------------------------------------------+-----------------------------------------------------------------+-----------------------------+-------------------------+
