:original_name: elb_faq_210304.html

.. _elb_faq_210304:

Why Can't I Delete My Load Balancer?
====================================

-  There may be resources associated with the load balancer. Delete these resources first.

   Delete the resources configured for the load balancer in the following sequence:

   #. Delete all the forwarding policies added to HTTP and HTTPS listeners of the load balancer.
   #. Delete the redirect created for each HTTP listener of the load balancer.
   #. Remove all the backend servers from the backend server groups associated with each listener of the load balancer.
   #. Delete all the listeners added to the load balancer.
   #. Delete all backend server groups associated with each listener of the load balancer.

-  Deletion protection may have been enabled for the load balancer. Disable deletion protection first.
-  Removal protection may have been enabled for the load balancer. Disable removal protection first.
