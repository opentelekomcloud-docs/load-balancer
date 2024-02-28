:original_name: elb_sq_lb_0008.html

.. _elb_sq_lb_0008:

Whitelist
=========

+----------------------------------------------+----------------------+-----------------------+-------------------------+
| API                                          | API Function         | Action                | Authorization Scope     |
+==============================================+======================+=======================+=========================+
| POST /v2.0/lbaas/whitelists                  | Adding a whitelist   | elb:whitelists:create | Projects are supported. |
+----------------------------------------------+----------------------+-----------------------+-------------------------+
| GET /v2.0/lbaas/whitelists                   | Querying whitelists  | elb:whitelists:list   | Projects are supported. |
+----------------------------------------------+----------------------+-----------------------+-------------------------+
| GET /v2.0/lbaas/whitelists/{whitelist_id}    | Querying a whitelist | elb:whitelists:get    | Projects are supported. |
+----------------------------------------------+----------------------+-----------------------+-------------------------+
| PUT /v2.0/lbaas/whitelists/{whitelist_id}    | Updating a whitelist | elb:whitelists:put    | Projects are supported. |
+----------------------------------------------+----------------------+-----------------------+-------------------------+
| DELETE /v2.0/lbaas/whitelists/{whitelist_id} | Deleting a whitelist | elb:whitelists:delete | Projects are supported. |
+----------------------------------------------+----------------------+-----------------------+-------------------------+
