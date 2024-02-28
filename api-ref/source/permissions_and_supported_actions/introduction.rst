:original_name: elb_sq_0001.html

.. _elb_sq_0001:

Introduction
============

This section describes fine-grained permissions management for the ELB service. If your account does not need individual IAM users, then you may skip over this chapter.

By default, new IAM users do not have permissions assigned. You need to add a user to one or more groups, and attach permissions policies or roles to these groups. Users inherit permissions from the groups to which they are added and can perform specified operations on cloud services based on the permissions.

An account has all of the permissions required to call all APIs, but IAM users must have the required permissions specifically assigned. The permissions required for calling an API are determined by the actions supported by the API. Only users who have been granted permissions allowing the actions can call the API successfully. For example, if an IAM user queries backend servers using an API, the user must have been granted permissions that allow the elb:servers:list action.

Supported Actions
-----------------

ELB provides system-defined policies that can be directly used in IAM. You can also create custom policies and use them to supplement system-defined policies, implementing more refined access control. Operations supported by policies are specific to APIs. The following are common concepts related to policies:

-  Permissions: Defined by actions in a custom policy.
-  APIs: REST APIs that can be called in a custom policy.
-  Actions: Added to a custom policy to control permissions for specific operations.
-  Dependencies: actions which a specific action depends on. When allowing an action for a user, you also need to allow any existing action dependencies for that user.

:ref:`API Actions (V3) <elb_sq_lb_v3_0000>` describes the custom policy authorization items supported by ELB.

-  :ref:`Load balancer actions <elb_sq_lb_v3_0001>`, including actions supported by all load balancer APIs, such as the APIs for creating a load balancer, querying a load balancer, querying the load balancer status tree, querying the load balancer list, updating a load balancer, and deleting a load balancer.

   .. note::

      The check mark (Y) indicates that an action takes effect. The cross mark (x) indicates that an action does not take effect.
