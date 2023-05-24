:original_name: elb_faq_0083.html

.. _elb_faq_0083:

Will ELB Stop Distributing Traffic Immediately After a Listener Is Deleted?
===========================================================================

-  If a TCP or UDP listener is deleted, the load balancer immediately stops routing traffic because the client uses short connections to communicate with the load balancer.
-  If an HTTP or HTTPS listener is deleted, persistent connections that have been established between the client and the load balancer will be kept alive until they time out, and therefore request routing is not affected. After the connections time out, the client stops sending requests over these connections. The default timeout duration is 300s.

   .. note::

      The duration for which persistent connections are kept alive is called idle timeout, and this takes effect only for persistent connections established between the client and load balancer.
