:original_name: elb_sq_lb_v3_0011.html

.. _elb_sq_lb_v3_0011:

Custom Security Policy
======================

+--------------------------------------------------------------------+------------------------------------+------------------------------+------------------------------------------------------+
| API                                                                | API Function                       | Action                       | Authorization Scope                                  |
+====================================================================+====================================+==============================+======================================================+
| POST /v3/{project_id}/elb/security-policies                        | Creating a custom security policy  | elb:security-policies:create | Both projects and enterprise projects are supported. |
+--------------------------------------------------------------------+------------------------------------+------------------------------+------------------------------------------------------+
| GET /v3/{project_id}/elb/security-policies/{security_policy_id}    | Querying a custom security policy  | elb:security-policies:get    | Both projects and enterprise projects are supported. |
+--------------------------------------------------------------------+------------------------------------+------------------------------+------------------------------------------------------+
| GET /v3/{project_id}/elb/security-policies                         | Querying custom security policies  | elb:security-policies:list   | Both projects and enterprise projects are supported. |
+--------------------------------------------------------------------+------------------------------------+------------------------------+------------------------------------------------------+
| PUT /v3/{project_id}/elb/security-policies/{security_policy_id}    | Modifying a custom security policy | elb:security-policies:put    | Both projects and enterprise projects are supported. |
+--------------------------------------------------------------------+------------------------------------+------------------------------+------------------------------------------------------+
| DELETE /v3/{project_id}/elb/security-policies/{security_policy_id} | Deleting a custom security policy  | elb:security-policies:delete | Both projects and enterprise projects are supported. |
+--------------------------------------------------------------------+------------------------------------+------------------------------+------------------------------------------------------+
| GET /v3/{project_id}/elb/system-security-policies                  | Querying system security policies  | elb:security-policies:list   | Both projects and enterprise projects are supported. |
+--------------------------------------------------------------------+------------------------------------+------------------------------+------------------------------------------------------+
