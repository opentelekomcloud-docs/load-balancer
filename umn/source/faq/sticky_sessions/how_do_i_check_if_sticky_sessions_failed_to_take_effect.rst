:original_name: elb_faq_0046.html

.. _elb_faq_0046:

How Do I Check If Sticky Sessions Failed to Take Effect?
========================================================

#. Check whether sticky sessions are enabled for the backend server group. If sticky sessions are enabled, go to the next step.
#. Check the health check result of the backend server. If the health check result is **Unhealthy**, traffic is routed to other backend servers and sticky sessions become invalid.
#. If you select the source IP hash algorithm, check whether the IP address of the request changes before the load balancer receives the request.
#. If sticky sessions are enabled for an HTTP or HTTPS listener, check whether the request carries a cookie. If they are, check whether the cookie value changed (because load balancing at Layer 7 uses cookies to maintain sessions).
