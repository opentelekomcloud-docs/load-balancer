:original_name: elb_faq_0079.html

.. _elb_faq_0079:

Does ELB Support Persistent Connections?
========================================

Yes.

The connections between the client and load balancer are persistent connections. After a TCP persistent connection is established, the client continuously sends HTTP requests to the load balancer until the connection times out. The reuse of TCP connections reduces the costs for a large number of short connections.
