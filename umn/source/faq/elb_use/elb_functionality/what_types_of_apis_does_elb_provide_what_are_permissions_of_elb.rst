:original_name: elb_faq_0088.html

.. _elb_faq_0088:

What Types of APIs Does ELB Provide? What Are Permissions of ELB?
=================================================================

ELB supports the following policies:

.. table:: **Table 1** ELB policies

   +-----------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Policy Type           | Policy Name           | Description                                                                                                                                                                      |
   +=======================+=======================+==================================================================================================================================================================================+
   | RBAC policy           | ELB Administrator     | Has all permissions on ELB.                                                                                                                                                      |
   |                       |                       |                                                                                                                                                                                  |
   |                       |                       | Before assigning the RBAC policy to a user group, check whether the user group has a dependent policy. If yes, set the dependent permission to make the RBAC policy take effect. |
   +-----------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Fine-grained policy   | ELB FullAccess        | Has all permissions on ELB.                                                                                                                                                      |
   |                       |                       |                                                                                                                                                                                  |
   |                       |                       | If this function is not enabled, you cannot assign a fine-grained policy to a user group.                                                                                        |
   +-----------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   |                       | ELB ReadOnlyAccess    | Has the read-only permission on ELB.                                                                                                                                             |
   +-----------------------+-----------------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

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

For details about fine-grained permissions, see the *Elastic Load Balance API Reference*.
