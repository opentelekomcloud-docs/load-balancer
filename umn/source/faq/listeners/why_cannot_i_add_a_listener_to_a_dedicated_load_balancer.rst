:original_name: elb_faq_210410.html

.. _elb_faq_210410:

Why Cannot I Add a Listener to a Dedicated Load Balancer?
=========================================================

If you select either network load balancing (TCP/UDP) or application load balancing (HTTP/HTTPS) when creating the load balancer, you can only add listeners of the matched protocol.

The load balancing type cannot be changed after being selected. For example, if you have selected network load balancing during load balancer creation, you cannot change it to application load balancing and you cannot add HTTP or HTTPS listeners.

.. table:: **Table 1** Protocols and load balancing types

   ========================== ========== ========================
   Load Balancing Type        Protocol   Listener Types
   ========================== ========== ========================
   Network load balancing     TCP/UDP    TCP and UDP listeners
   Application load balancing HTTP/HTTPS HTTP and HTTPS listeners
   ========================== ========== ========================
