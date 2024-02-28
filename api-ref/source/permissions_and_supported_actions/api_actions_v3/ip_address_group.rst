:original_name: elb_sq_lb_v3_0012.html

.. _elb_sq_lb_v3_0012:

IP Address Group
================

+-------------------------------------------------------------------------+------------------------------------------------+---------------------+------------------------------------------------------+
| API                                                                     | API Function                                   | Action              | Authorization Scope                                  |
+=========================================================================+================================================+=====================+======================================================+
| POST /v3/{project_id}/elb/ipgroups                                      | Creating an IP address group                   | elb:ipgroups:create | Both projects and enterprise projects are supported. |
+-------------------------------------------------------------------------+------------------------------------------------+---------------------+------------------------------------------------------+
| GET /v3/{project_id}/elb/ipgroups/{ipgroup_id}                          | Querying an IP address group                   | elb:ipgroups:get    | Both projects and enterprise projects are supported. |
+-------------------------------------------------------------------------+------------------------------------------------+---------------------+------------------------------------------------------+
| GET /v3/{project_id}/elb/ipgroups                                       | Querying IP address groups                     | elb:ipgroups:list   | Both projects and enterprise projects are supported. |
+-------------------------------------------------------------------------+------------------------------------------------+---------------------+------------------------------------------------------+
| PUT /v3/{project_id}/elb/ipgroups/{ipgroup_id}                          | Updating an IP address group                   | elb:ipgroups:put    | Both projects and enterprise projects are supported. |
+-------------------------------------------------------------------------+------------------------------------------------+---------------------+------------------------------------------------------+
| DELETE /v3/{project_id}/elb/ipgroups/{ipgroup_id}                       | Deleting an IP address group                   | elb:ipgroups:delete | Both projects and enterprise projects are supported. |
+-------------------------------------------------------------------------+------------------------------------------------+---------------------+------------------------------------------------------+
| POST /v3/{project_id}/elb/ipgroups/{ipgroup_id}/iplist/create-or-update | Updating IP addresses in an IP address group   | elb:ipgroups:put    | Both projects and enterprise projects are supported. |
+-------------------------------------------------------------------------+------------------------------------------------+---------------------+------------------------------------------------------+
| POST /v3/{project_id}/elb/ipgroups/{ipgroup_id}/iplist/batch-delete     | Deleting IP addresses from an IP address group | elb:ipgroups:put    | Both projects and enterprise projects are supported. |
+-------------------------------------------------------------------------+------------------------------------------------+---------------------+------------------------------------------------------+
