:original_name: en-us_topic_0162009773.html

.. _en-us_topic_0162009773:

Creating a Custom Policy
========================

Custom policies can be created as a supplement to the system policies of ELB. For the actions supported for custom policies, see "Permissions Policies and Supported Actions" in the Elastic Load Balance API Reference.

You can create custom policies in either of the following ways:

-  Visual editor: Select cloud services, actions, resources, and request conditions. This does not require knowledge of policy syntax.
-  JSON: Edit JSON policies from scratch or based on an existing policy.

For details, see `Creating a Custom Policy <https://docs.otc.t-systems.com/identity-access-management/umn/user_guide/fine-grained_policy_management/creating_a_custom_policy.html>`__. The following section contains examples of common ELB custom policies.

Example Custom Policies
-----------------------

-  Example 1: Allowing users to update a load balancer

   .. code-block::

      {
           "Version": "1.1",
           "Statement": [
               {
                   "Effect": "Allow",
                   "Action": [
                       "elb:loadbalancers:put"
                   ]
               }
           ]
       }

-  Example 2: Denying load balancer deletion

   A deny policy must be used in conjunction with other policies to take effect. If the permissions assigned to a user contain both Allow and Deny actions, the Deny actions take precedence over the Allow actions.

   If you grant the system policy **ELB FullAccess** to a user but do not want the user to have the permission to delete load balancers defined in the policy, you can create a custom policy that rejects the deletion of load balancers and grant the **ELB FullAccess** and deny policies to the user, so that the user can perform all operations on ELB except deleting load balancers. The following is an example deny policy:

   .. code-block::

      {
             "Version": "1.1",
             "Statement": [
                   {
                 "Effect": "Deny",
                         "Action": [
                               "elb:loadbalancers:delete"
                         ]
                   }
             ]
       }

-  Example 3: Defining permissions for multiple services in a policy

   A custom policy can contain the actions of multiple services that are of the global or project-level type. The following is an example policy containing actions of multiple services:

   .. code-block::

      {
          "Version": "1.1",
          "Statement": [
              {
                  "Effect": "Allow",
                  "Action": [
                      "elb:loadbalancers:get",
                      "elb:loadbalancers:list",
                      "elb:loadbalancers:delete",
                      "ecs:cloudServers:delete"
                  ]
              }
          ]
      }
