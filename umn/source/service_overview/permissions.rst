:original_name: en-us_topic_0171274900.html

.. _en-us_topic_0171274900:

Permissions
===========

If you need to assign different permissions to personnel in your enterprise to access your ELB resources, IAM is a good choice for fine-grained permissions management. IAM provides identity authentication, permissions management, and access control, helping you securely access your cloud resources.

With IAM, you can create IAM users and assign permissions to control their access to specific resources. For example, if you want some software developers in your enterprise to use ELB resources but do not want them to delete these resources or perform any other high-risk operations, you can grant permission to use ELB resources but not permission to delete them.

Skip this section if your account does not require individual IAM users for permissions management.

IAM is a free service. You only pay for the resources in your account. For more information about IAM, see the *IAM Service Overview*.

ELB Permissions
---------------

New IAM users do not have any permissions assigned by default. You need to first add them to one or more groups and attach policies or roles to these groups. The users then inherit permissions from the groups and can perform specified operations on cloud services based on the permissions they have been assigned.

ELB is a project-level service deployed for specific regions. To assign ELB permissions to a user group, specify the scope as region-specific projects and select projects for which you want the permissions to take effect. If you select **All projects**, the permissions will take effect for the user group in all region-specific projects. When accessing ELB, users need to switch to the authorized region.

You can grant permissions by using roles and policies.

-  Roles: A coarse-grained authorization strategy provided by IAM to assign permissions based on users' job responsibilities. Only a limited number of service-level roles are available for authorization. When you grant permissions using roles, you also need to attach any existing role dependencies. Roles are not ideal for fine-grained authorization and least privilege access.
-  Policies: A fine-grained authorization strategy provided by IAM to assign permissions required to perform operations on specific cloud resources under certain conditions. This type of authorization is more flexible and is ideal for least privilege access. For example, you can grant ELB users only permissions to manage a certain type of resources. A majority of fine-grained policies contain permissions for specific APIs, and permissions are defined using API actions. For the API actions supported by ELB, see *Elastic Load Balance API Reference*.

:ref:`Table 1 <en-us_topic_0171274900__table1492612523149>` lists all the system-defined permissions for ELB.

.. _en-us_topic_0171274900__table1492612523149:

.. table:: **Table 1** System-defined permissions for ELB

   +-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
   | Role/Policy Name      | Description                                                                                                                                                                                                                               | Type                  |
   +=======================+===========================================================================================================================================================================================================================================+=======================+
   | ELB FullAccess        | Permissions: all permissions on ELB resources                                                                                                                                                                                             | System-defined policy |
   |                       |                                                                                                                                                                                                                                           |                       |
   |                       | Scope: project-level service                                                                                                                                                                                                              |                       |
   +-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
   | ELB ReadOnlyAccess    | Permissions: read-only permissions on ELB resources                                                                                                                                                                                       | System-defined policy |
   |                       |                                                                                                                                                                                                                                           |                       |
   |                       | Scope: project-level service                                                                                                                                                                                                              |                       |
   +-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
   | ELB Administrator     | Permissions: all permissions on ELB resources. To be granted this permission, users must also have the **Tenant Administrator**, **VPC Administrator**, **CES Administrator**, **Server Administrator** and **Tenant Guest** permissions. | System-defined role   |
   |                       |                                                                                                                                                                                                                                           |                       |
   |                       | Scope: project-level service                                                                                                                                                                                                              |                       |
   |                       |                                                                                                                                                                                                                                           |                       |
   |                       | .. note::                                                                                                                                                                                                                                 |                       |
   |                       |                                                                                                                                                                                                                                           |                       |
   |                       |    If your account has applied for fine-grained permissions, configure fine-grained policies for ELB system permissions, instead of RBAC policies.                                                                                        |                       |
   +-----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+

:ref:`Table 2 <en-us_topic_0171274900__table26611439131>` describes common operations supported by each system policy of ELB.

.. _en-us_topic_0171274900__table26611439131:

.. table:: **Table 2** Common operations supported by system-defined policies

   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Operation                                         | ELB FullAccess | ELB ReadOnlyAccess | ELB Administrator |
   +===================================================+================+====================+===================+
   | Creating a load balancer                          | Supported      | Not supported      | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Querying a load balancer                          | Supported      | Supported          | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Querying a load balancer and associated resources | Supported      | Supported          | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Querying load balancers                           | Supported      | Supported          | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Modifying a load balancer                         | Supported      | Not supported      | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Deleting a load balancer                          | Supported      | Not supported      | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Adding a listener                                 | Supported      | Not supported      | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Querying a listener                               | Supported      | Supported          | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Modifying a listener                              | Supported      | Not supported      | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Deleting a listener                               | Supported      | Not supported      | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Adding a backend server group                     | Supported      | Not supported      | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Querying a backend server group                   | Supported      | Supported          | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Modifying a backend server group                  | Supported      | Not supported      | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Deleting a backend server group                   | Supported      | Not supported      | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Adding a backend server                           | Supported      | Not supported      | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Querying a backend server                         | Supported      | Supported          | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Modifying a backend server                        | Supported      | Not supported      | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Deleting a backend server                         | Supported      | Not supported      | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Configuring a health check                        | Supported      | Not supported      | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Querying a health check                           | Supported      | Supported          | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Modifying a health check                          | Supported      | Not supported      | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Disabling a health check                          | Supported      | Not supported      | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Assigning an EIP                                  | Not supported  | Not supported      | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Binding an EIP to a load balancer                 | Not supported  | Not supported      | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Querying an EIP                                   | Supported      | Supported          | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Unbinding an EIP from a load balancer             | Not supported  | Not supported      | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Viewing metrics                                   | Not supported  | Not supported      | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
   | Viewing access logs                               | Not supported  | Not supported      | Supported         |
   +---------------------------------------------------+----------------+--------------------+-------------------+
