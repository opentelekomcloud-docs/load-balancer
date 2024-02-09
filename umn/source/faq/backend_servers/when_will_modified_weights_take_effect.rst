:original_name: elb_faq_0125.html

.. _elb_faq_0125:

When Will Modified Weights Take Effect?
=======================================

The new weights for backend servers take effect immediately after the weights are configured. Connections that have been established with backend servers will not be affected.

.. note::

   If the weight of a backend server is changed to 0, the new weight does not take effect immediately, and requests are still routed to this backend server. This is because a persistent connection is established between the load balancer and the backend server and requests are routed to this server until the connection times out.

   -  TCP and UDP listeners: Persistent connections are disconnected after the idle timeout duration expires.
   -  HTTP and HTTPS listeners: Persistent connections are disconnected after the response timeout duration expires.
