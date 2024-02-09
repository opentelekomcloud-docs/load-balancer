:original_name: elb_faq_0110.html

.. _elb_faq_0110:

Which Protocol Should I Select for the Backend Server Group When Adding an HTTPS Listener?
==========================================================================================

To use HTTPS at both the frontend and backend, you can create a dedicated load balancer, add an HTTPS listener to the load balancer, and set the backend protocol to HTTPS.

To use HTTPS at the frontend only, you can create a dedicated load balancer, add an HTTPS listener to the load balancer, and set the backend protocol to HTTP.

.. note::

   Using HTTPS at both the frontend and backend only allows you to enable mutual authentication on the load balancer and backend servers.
